#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/function.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file19_name = "syntax-tree/function.3.mr";
#endif
#define MR_FILE_NAME _mr_file19_name

/* MR4 compiler - Syntax tree function */

/* Function node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeFunction SyntaxTreeFunction;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeFunction {
  SyntaxTreeBlock _base;
  List* aux_variables;
  TypeData* parent_type;
  String* name;
  FunctionArguments* arguments;
  SyntaxTreeMockFunction* mocker_function;
  SyntaxTreeFunction* dynamic_base_method;
  Int dynamic_base_count;
  Bool is_dynamic;
/* write function body */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse_new(SyntaxTreeFunction* self, TypeData* parent_type, Char* end, SyntaxTreeFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_new = "SyntaxTreeFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse_new
Returncode SyntaxTreeFunction_parse_new(SyntaxTreeFunction* self, TypeData* parent_type, Char* end, SyntaxTreeFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeFunction));
  if ((*new_node) == NULL) RAISE(16)
  *(*new_node) = (SyntaxTreeFunction){SyntaxTreeFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._dtl = SyntaxTreeFunction__dtl;
  CHECK(17, SyntaxTreeFunction_parse((*new_node), parent_type, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse(SyntaxTreeFunction* self, TypeData* parent_type, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse = "SyntaxTreeFunction.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse
Returncode SyntaxTreeFunction_parse(SyntaxTreeFunction* self, TypeData* parent_type, Char* end) {
  CHECK(20, SyntaxTreeFunction_init(self) )
  self->parent_type = parent_type;
  if (NULL != self->parent_type) {
    self->_base._base.indentation_spaces = 2;
    if (self->parent_type->is_dynamic) {
      String* meth_type = NULL;
      Int _Int79;
      CHECK(26, read_until(&(String){2, 1, " "}, false, &(meth_type), &((*end)), &(_Int79)) )
      Bool _Bool80;
      CHECK(27, String_equal(meth_type, &(String){8, 7, "dynamic"}, &(_Bool80)) )
      if (_Bool80) {
        self->is_dynamic = true;
      }
      else {
        Bool _Bool81;
        CHECK(29, String_equal(meth_type, &(String){5, 4, "inst"}, &(_Bool81)) )
        if (!_Bool81) {
          CHECK(30, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){46, 45, "expected \"dynamic\" or \"inst\" method type, got"}, meth_type) )
        }
      }
    }
  }
  CHECK(33, SyntaxTreeFunction_parse_header(self, false, &((*end))) )
  CHECK(34, SyntaxTreeFunction_parse_body(self, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_init(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_init = "SyntaxTreeFunction.init";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_init
Returncode SyntaxTreeFunction_init(SyntaxTreeFunction* self) {
  CHECK(37, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  self->aux_variables = malloc(sizeof(List));
  if (self->aux_variables == NULL) RAISE(38)
  *self->aux_variables = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse_body(SyntaxTreeFunction* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_body = "SyntaxTreeFunction.parse-body";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse_body
Returncode SyntaxTreeFunction_parse_body(SyntaxTreeFunction* self, Char* end) {
  self->_base._base.indentation_spaces += 2;
  CHECK(42, SyntaxTreeBlock_parse_block(&(self->_base), &((*end))) )
  self->_base._base.indentation_spaces = 2;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse_header(SyntaxTreeFunction* self, Bool is_native, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_header = "SyntaxTreeFunction.parse-header";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse_header
Returncode SyntaxTreeFunction_parse_header(SyntaxTreeFunction* self, Bool is_native, Char* end) {
  CHECK(46, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  CHECK(47, (self)->_base._base._base._dtl[7](self) )
  if ((*end) != '(') {
    CHECK(49, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){38, 37, "expected \"(\" after function name, got"}, (*end)) )
  }
  CHECK(51, SyntaxTreeFunction_parse_arguments(self, is_native, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_parse_arguments(SyntaxTreeFunction* self, Bool is_native, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_parse_arguments = "SyntaxTreeFunction.parse-arguments";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_parse_arguments
Returncode SyntaxTreeFunction_parse_arguments(SyntaxTreeFunction* self, Bool is_native, Char* end) {
  self->arguments = malloc(sizeof(FunctionArguments));
  if (self->arguments == NULL) RAISE(54)
  *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->arguments->_base._dtl = FunctionArguments__dtl;
  DeclarationArgumentFactory* argument_factory = &(DeclarationArgumentFactory){DeclarationArgumentFactory__dtl};
  argument_factory->_base._dtl = DeclarationArgumentFactory__dtl;
  SyntaxTreeCode* dummy_node = &(SyntaxTreeCode){SyntaxTreeCode__dtl, NULL, 0, NULL};
  dummy_node->_base._dtl = SyntaxTreeCode__dtl;
  CHECK(57, SyntaxTreeNode_set_location(&(dummy_node->_base)) )
  dummy_node->parent = &(self->_base);
  CHECK(59, FunctionArguments_parse(self->arguments, &(argument_factory->_base), is_native, dummy_node, &((*end))) )
  if (NULL != self->parent_type) {
    TypeInstance* _TypeInstance82;
    CHECK(62, TypeData_m_new_type_instance(self->parent_type, &(_TypeInstance82)) )
    CHECK(62, FunctionArguments_add_self_parameter(self->arguments, _TypeInstance82) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_check_name(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_check_name = "SyntaxTreeFunction.check-name";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_check_name
Returncode SyntaxTreeFunction_check_name(SyntaxTreeFunction* self) {
  Bool _Bool83;
  CHECK(66, f_is_legal_name(self->name, false, &(_Bool83)) )
  if (!_Bool83) {
    CHECK(67, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){22, 21, "illegal function name"}, self->name) )
  }
  if (NULL != self->parent_type) {
    SyntaxTreeFunction* meth = NULL;
    Int _Int84;
    CHECK(70, TypeData_find_meth(self->parent_type, self->name, &(meth), &(_Int84)) )
    if (NULL != meth) {
      CHECK(72, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){23, 22, "redefinition of method"}, self->name) )
    }
    SyntaxTreeVariable* field = NULL;
    Int _Int85;
    CHECK(74, TypeData_find_field(self->parent_type, self->name, &(field), &(_Int85)) )
    if (NULL != field) {
      CHECK(76, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){28, 27, "method name overrides field"}, self->name) )
    }
  }
  else {
    SyntaxTreeFunction* _SyntaxTreeFunction86;
    CHECK(79, SyntaxTreeNamespace_find_function(&(glob->root->_base), self->name, &(_SyntaxTreeFunction86)) )
    if (NULL != _SyntaxTreeFunction86) {
      CHECK(80, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){25, 24, "redefinition of function"}, self->name) )
    }
    SyntaxTreeVariable* _SyntaxTreeVariable87;
    CHECK(81, (glob->root)->_base._base._base._dtl[5](glob->root, self->name, &(_SyntaxTreeVariable87)) )
    if (NULL != _SyntaxTreeVariable87) {
      CHECK(82, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){40, 39, "function name overrides global variable"}, self->name) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_get_function(SyntaxTreeFunction* self, SyntaxTreeFunction** function);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_get_function = "SyntaxTreeFunction.get-function";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_get_function
Returncode SyntaxTreeFunction_get_function(SyntaxTreeFunction* self, SyntaxTreeFunction** function) {
  (*function) = self;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_get_parent_type(SyntaxTreeFunction* self, TypeData** parent_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_get_parent_type = "SyntaxTreeFunction.get-parent-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_get_parent_type
Returncode SyntaxTreeFunction_get_parent_type(SyntaxTreeFunction* self, TypeData** parent_type) {
  (*parent_type) = self->parent_type;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_add_aux_variable(SyntaxTreeFunction* self, Int access, Bool is_create, TypeInstance* type_instance, SyntaxTreeVariable** new_variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_add_aux_variable = "SyntaxTreeFunction.add-aux-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_add_aux_variable
Returncode SyntaxTreeFunction_add_aux_variable(SyntaxTreeFunction* self, Int access, Bool is_create, TypeInstance* type_instance, SyntaxTreeVariable** new_variable) {
  Int index = 0;
  ListNode* node = self->aux_variables->first;
  while (true) {
    if (!(NULL != node)) break;
    if (!(((TypeCount*)(node->item))->type_data != type_instance->type_data)) break;
    node = node->next;
  }
  if (NULL != node) {
    ((TypeCount*)(node->item))->count += 1;
    index = ((TypeCount*)(node->item))->count;
  }
  else {
    TypeCount* type_count = malloc(sizeof(TypeCount));
    if (type_count == NULL) RAISE(104)
    *type_count = (TypeCount){NULL, 0};
    type_count->type_data = type_instance->type_data;
    CHECK(106, List_add(self->aux_variables, type_count) )
  }
  SyntaxTreeVariable* variable = malloc(sizeof(SyntaxTreeVariable));
  if (variable == NULL) RAISE(107)
  *variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false, false, false};
  variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  variable->name = _new_string(type_instance->type_data->name->length + 21);
  if (variable->name == NULL) RAISE(108)
  CHECK(110, String_copy(variable->name, &(String){5, 4, "aux_"}) )
  CHECK(111, String_concat(variable->name, type_instance->type_data->name) )
  CHECK(112, String_append(variable->name, '_') )
  String* index_str = &(String){16, 0, (char[16]){0}};
  CHECK(114, Int_str(index, index_str) )
  CHECK(115, String_concat(variable->name, index_str) )
  variable->_base.parent = &(self->_base);
  variable->access = access;
  variable->is_create = is_create;
  CHECK(119, TypeInstance_copy_new(type_instance, &(variable->type_instance)) )
  (*new_variable) = variable;
  CHECK(121, List_add(self->_base._base.variables, variable) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_find_variable(SyntaxTreeFunction* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_find_variable = "SyntaxTreeFunction.find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_find_variable
Returncode SyntaxTreeFunction_find_variable(SyntaxTreeFunction* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(125, SyntaxTreeBlock_find_variable(&(self->_base), name, &((*variable))) )
  if (!(NULL != (*variable))) {
    CHECK(127, FunctionArguments_find_variable(self->arguments, name, &((*variable))) )
  }
  if (!(NULL != (*variable))) {
    CHECK(129, (glob->root)->_base._base._base._dtl[5](glob->root, name, &((*variable))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_link_types(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_link_types = "SyntaxTreeFunction.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_link_types
Returncode SyntaxTreeFunction_link_types(SyntaxTreeFunction* self) {
  CHECK(132, (self->arguments)->_base._dtl[1](self->arguments) )
  CHECK(133, SyntaxTreeBlock_link_types(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_analyze(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_analyze = "SyntaxTreeFunction.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_analyze
Returncode SyntaxTreeFunction_analyze(SyntaxTreeFunction* self) {
  CHECK(136, (self->arguments)->_base._dtl[2](self->arguments) )
  CHECK(137, SyntaxTreeBlock_analyze(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_m_compare(SyntaxTreeFunction* self, SyntaxTreeFunction* other);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_m_compare = "SyntaxTreeFunction.m-compare";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_m_compare
Returncode SyntaxTreeFunction_m_compare(SyntaxTreeFunction* self, SyntaxTreeFunction* other) {
  if (self->is_dynamic != other->is_dynamic) {
    CHECK(141, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){28, 27, "illegal dynamic in function"}, self->name) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* write function body */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write = "SyntaxTreeFunction.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write
Returncode SyntaxTreeFunction_write(SyntaxTreeFunction* self) {
  /* #define MR_FILE_NAME "`file-name`" */
  /* #define MR_FUNC_NAME "`parent-type`.`function-name`" */
  /* Returncode `Type`_`name`(`args`) { */
  /*   `block...` */
  /* } */
  /* #undef MR_FILE_NAME */
  /* #undef MR_FUNC_NAME */
  CHECK(152, write_pre_func(self) )
  CHECK(153, SyntaxTreeFunction_write_header(self) )
  CHECK(154, SyntaxTreeFunction_write_block(self) )
  CHECK(155, write_post_func() )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_header(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_header = "SyntaxTreeFunction.write-header";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_header
Returncode SyntaxTreeFunction_write_header(SyntaxTreeFunction* self) {
  CHECK(158, write(&(String){13, 12, "\nReturncode "}) )
  CHECK(159, SyntaxTreeFunction_write_cname(self) )
  CHECK(160, (self->arguments)->_base._dtl[3](self->arguments) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_block(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_block = "SyntaxTreeFunction.write-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_block
Returncode SyntaxTreeFunction_write_block(SyntaxTreeFunction* self) {
  /* `previous-text` { */
  /*   Returncode MR_err = OK; */
  /*   `block...` */
  /* MR_cleanup: */
  /*   return MR_err; */
  /* } */
  CHECK(169, SyntaxTreeBlock_write_block_start(&(self->_base)) )
  CHECK(170, write(&(String){27, 26, "  Returncode MR_err = OK;\n"}) )
  CHECK(171, SyntaxTreeBranch_write(&(self->_base._base)) )
  CHECK(172, SyntaxTreeFunction_write_setup(self) )
  CHECK(173, SyntaxTreeNode_write_children(&(self->_base._base._base), self->_base.code_nodes) )
  CHECK(174, write(&(String){13, 12, "MR_cleanup:\n"}) )
  CHECK(175, SyntaxTreeFunction_write_cleanup(self) )
  CHECK(176, write(&(String){18, 17, "  return MR_err;\n"}) )
  CHECK(177, SyntaxTreeBlock_write_block_end(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_setup(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_setup = "SyntaxTreeFunction.write-setup";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_setup
Returncode SyntaxTreeFunction_write_setup(SyntaxTreeFunction* self) {
  ListNode* node = self->arguments->parameters->first;
  while (true) {
    if (!(NULL != node)) break;
    if (((Argument*)(node->item))->access == ACCESS_USER || ((Argument*)(node->item))->access == ACCESS_OWNER) {
      CHECK(184, write(&(String){14, 13, "  MR_inc_ref("}) )
      SyntaxTreeVariable* _SyntaxTreeVariable88;
      CHECK(185, (((Argument*)(node->item)))->_base._dtl[8](((Argument*)(node->item)), &(_SyntaxTreeVariable88)) )
      CHECK(185, write_cname(_SyntaxTreeVariable88->name) )
      CHECK(186, write(&(String){11, 10, "_Refman);\n"}) )
    }
    node = node->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_cleanup(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_cleanup = "SyntaxTreeFunction.write-cleanup";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_cleanup
Returncode SyntaxTreeFunction_write_cleanup(SyntaxTreeFunction* self) {
  ListNode* var_node = self->_base._base.variables->last;
  while (true) {
    if (!(NULL != var_node)) break;
    if (!((SyntaxTreeVariable*)(var_node->item))->type_instance->type_data->is_primitive) {
      CHECK(194, write(&(String){6, 5, "  MR_"}) )
      if (((SyntaxTreeVariable*)(var_node->item))->access == ACCESS_OWNER) {
        CHECK(196, write(&(String){7, 6, "owner_"}) )
      }
      CHECK(197, write(&(String){9, 8, "dec_ref("}) )
      CHECK(198, write_cname(((SyntaxTreeVariable*)(var_node->item))->name) )
      CHECK(199, write(&(String){11, 10, "_Refman);\n"}) )
    }
    var_node = var_node->prev;
  }
  
  ListNode* param_node = self->arguments->parameters->last;
  while (true) {
    if (!(NULL != param_node)) break;
    if (((Argument*)(param_node->item))->access == ACCESS_USER || ((Argument*)(param_node->item))->access == ACCESS_OWNER) {
      CHECK(207, write(&(String){6, 5, "  MR_"}) )
      if (((Argument*)(param_node->item))->access == ACCESS_OWNER) {
        CHECK(209, write(&(String){7, 6, "owner_"}) )
      }
      CHECK(210, write(&(String){9, 8, "dec_ref("}) )
      SyntaxTreeVariable* _SyntaxTreeVariable89;
      CHECK(211, (((Argument*)(param_node->item)))->_base._dtl[8](((Argument*)(param_node->item)), &(_SyntaxTreeVariable89)) )
      CHECK(211, write_cname(_SyntaxTreeVariable89->name) )
      CHECK(212, write(&(String){11, 10, "_Refman);\n"}) )
    }
    param_node = param_node->prev;
  }
  
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_cname(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_cname = "SyntaxTreeFunction.write-cname";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_cname
Returncode SyntaxTreeFunction_write_cname(SyntaxTreeFunction* self) {
  if (NULL != self->parent_type) {
    CHECK(218, write_cname(self->parent_type->name) )
    CHECK(219, write(&(String){2, 1, "_"}) )
  }
  CHECK(220, write_cname(self->name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_pointer(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_pointer = "SyntaxTreeFunction.write-pointer";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_pointer
Returncode SyntaxTreeFunction_write_pointer(SyntaxTreeFunction* self) {
  CHECK(223, FunctionArguments_write_pointer(self->arguments, self->name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFunction_write_declaration(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFunction_write_declaration = "SyntaxTreeFunction.write-declaration";
#define MR_FUNC_NAME _func_name_SyntaxTreeFunction_write_declaration
Returncode SyntaxTreeFunction_write_declaration(SyntaxTreeFunction* self) {
  /* Returncode `Type`_`name`(`args`); */
  CHECK(227, SyntaxTreeFunction_write_header(self) )
  CHECK(228, write(&(String){3, 2, ";\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Count occurrences of a specific type */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeCount TypeCount;
#elif MR_STAGE == MR_TYPES(0)
struct TypeCount {
  TypeData* type_data;
  Int count;
};
#endif


/* Constructor declaration in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeConstructor SyntaxTreeConstructor;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeConstructor {
  SyntaxTreeFunction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstructor_parse_new(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end, SyntaxTreeConstructor** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstructor_parse_new = "SyntaxTreeConstructor.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstructor_parse_new
Returncode SyntaxTreeConstructor_parse_new(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end, SyntaxTreeConstructor** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeConstructor));
  if ((*new_node) == NULL) RAISE(241)
  *(*new_node) = (SyntaxTreeConstructor){SyntaxTreeConstructor__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeConstructor__dtl;
  CHECK(242, SyntaxTreeConstructor_parse((*new_node), parent_type, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstructor_parse(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstructor_parse = "SyntaxTreeConstructor.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstructor_parse
Returncode SyntaxTreeConstructor_parse(SyntaxTreeConstructor* self, TypeData* parent_type, Char* end) {
  CHECK(245, SyntaxTreeFunction_init(&(self->_base)) )
  self->_base.parent_type = parent_type;
  self->_base._base._base.indentation_spaces = 2;
  CHECK(248, string_new_copy(&(String){4, 3, "new"}, &(self->_base.name)) )
  CHECK(249, SyntaxTreeFunction_parse_arguments(&(self->_base), false, &((*end))) )
  CHECK(250, SyntaxTreeFunction_parse_body(&(self->_base), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstructor_analyze(SyntaxTreeConstructor* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstructor_analyze = "SyntaxTreeConstructor.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstructor_analyze
Returncode SyntaxTreeConstructor_analyze(SyntaxTreeConstructor* self) {
  if (NULL != self->_base.arguments->outputs->first) {
    CHECK(254, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){25, 24, "constructor with outputs"}) )
  }
  CHECK(255, SyntaxTreeFunction_analyze(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeConstructor__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeConstructor__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeConstructor_analyze, (void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Main function node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeMainFunction SyntaxTreeMainFunction;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeMainFunction {
  SyntaxTreeFunction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMainFunction_parse_new(SyntaxTreeMainFunction* self, Char* end, SyntaxTreeMainFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_parse_new = "SyntaxTreeMainFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeMainFunction_parse_new
Returncode SyntaxTreeMainFunction_parse_new(SyntaxTreeMainFunction* self, Char* end, SyntaxTreeMainFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeMainFunction));
  if ((*new_node) == NULL) RAISE(261)
  *(*new_node) = (SyntaxTreeMainFunction){SyntaxTreeMainFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMainFunction__dtl;
  CHECK(262, SyntaxTreeMainFunction_parse((*new_node), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMainFunction_parse(SyntaxTreeMainFunction* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_parse = "SyntaxTreeMainFunction.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeMainFunction_parse
Returncode SyntaxTreeMainFunction_parse(SyntaxTreeMainFunction* self, Char* end) {
  CHECK(265, SyntaxTreeFunction_init(&(self->_base)) )
  CHECK(266, string_new_copy(&(String){5, 4, "main"}, &(self->_base.name)) )
  self->_base.arguments = malloc(sizeof(FunctionArguments));
  if (self->_base.arguments == NULL) RAISE(267)
  *self->_base.arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->_base.arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(268, FunctionArguments_init(self->_base.arguments) )
  CHECK(269, SyntaxTreeFunction_parse_body(&(self->_base), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMainFunction_write(SyntaxTreeMainFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_write = "SyntaxTreeMainFunction.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeMainFunction_write
Returncode SyntaxTreeMainFunction_write(SyntaxTreeMainFunction* self) {
  /* USER_MAIN_HEADER { */
  /*   `block...` */
  /* } */
  /* MAIN_FUNC */
  CHECK(276, write_pre_func(&(self->_base)) )
  CHECK(277, write(&(String){18, 17, "\nUSER_MAIN_HEADER"}) )
  CHECK(278, SyntaxTreeFunction_write_block(&(self->_base)) )
  CHECK(279, write_post_func() )
  CHECK(280, write(&(String){12, 11, "\nMAIN_FUNC\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeMainFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeMainFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeMainFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


/* Function declaration argument */
#if MR_STAGE == MR_TYPEDEFS
typedef struct DeclarationArgument DeclarationArgument;
#elif MR_STAGE == MR_TYPES(2)
struct DeclarationArgument {
  Argument _base;
  SyntaxTreeVariable* variable;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_copy_new(DeclarationArgument* self, DeclarationArgument** new_argument);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_copy_new = "DeclarationArgument.copy-new";
#define MR_FUNC_NAME _func_name_DeclarationArgument_copy_new
Returncode DeclarationArgument_copy_new(DeclarationArgument* self, DeclarationArgument** new_argument) {
  (*new_argument) = malloc(sizeof(DeclarationArgument));
  if ((*new_argument) == NULL) RAISE(288)
  *(*new_argument) = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, false, NULL};
  (*new_argument)->_base._base._dtl = DeclarationArgument__dtl;
  (*new_argument)->_base._base.input_file_name = self->_base._base.input_file_name;
  (*new_argument)->_base._base.line_number = self->_base._base.line_number;
  (*new_argument)->_base.access = self->_base.access;
  (*new_argument)->_base.is_output = self->_base.is_output;
  (*new_argument)->_base.is_native = self->_base.is_native;
  (*new_argument)->variable = malloc(sizeof(SyntaxTreeVariable));
  if ((*new_argument)->variable == NULL) RAISE(294)
  *(*new_argument)->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false, false, false};
  (*new_argument)->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  (*new_argument)->variable->access = self->variable->access;
  (*new_argument)->variable->parent_type = self->variable->parent_type;
  CHECK(297, TypeInstance_copy_new(self->variable->type_instance, &((*new_argument)->variable->type_instance)) )
  CHECK(299, string_new_copy(self->variable->name, &((*new_argument)->variable->name)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_parse_value(DeclarationArgument* self, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_parse_value = "DeclarationArgument.parse-value";
#define MR_FUNC_NAME _func_name_DeclarationArgument_parse_value
Returncode DeclarationArgument_parse_value(DeclarationArgument* self, SyntaxTreeCode* code_node, Char* end) {
  self->variable = malloc(sizeof(SyntaxTreeVariable));
  if (self->variable == NULL) RAISE(302)
  *self->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false, false, false};
  self->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  self->variable->access = self->_base.access;
  self->variable->is_output = self->_base.is_output;
  if (NULL != code_node) {
    CHECK(306, (code_node)->_base._dtl[0](code_node, &(self->variable->parent_type)) )
  }
  self->variable->type_instance = malloc(sizeof(TypeInstance));
  if (self->variable->type_instance == NULL) RAISE(307)
  *self->variable->type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
  CHECK(308, TypeInstance_parse(self->variable->type_instance, &(String){2, 1, " "}, &(self->_base._base), NULL, &((*end))) )
  if ((*end) != ' ') {
    CHECK(310, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  CHECK(311, read_new(&(String){3, 2, ",)"}, &(self->variable->name), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_get_parent_type(DeclarationArgument* self, TypeData** parent_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_get_parent_type = "DeclarationArgument.get-parent-type";
#define MR_FUNC_NAME _func_name_DeclarationArgument_get_parent_type
Returncode DeclarationArgument_get_parent_type(DeclarationArgument* self, TypeData** parent_type) {
  (*parent_type) = self->variable->parent_type;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_link_types(DeclarationArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_link_types = "DeclarationArgument.link-types";
#define MR_FUNC_NAME _func_name_DeclarationArgument_link_types
Returncode DeclarationArgument_link_types(DeclarationArgument* self) {
  CHECK(317, TypeInstance_link_types(self->variable->type_instance, &(self->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_analyze(DeclarationArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_analyze = "DeclarationArgument.analyze";
#define MR_FUNC_NAME _func_name_DeclarationArgument_analyze
Returncode DeclarationArgument_analyze(DeclarationArgument* self) {
  if (self->variable->type_instance->type_data->is_primitive) {
    if (self->_base.is_output && self->_base.access != ACCESS_VAR) {
      if ((self->_base.access) < 0 || (self->_base.access) >= (glob->access_names)->length) RAISE(322)
      CHECK(322, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){7, 6, "output"}, self->variable->name, &(String){48, 47, "access should be \"var\" for primitive types, got"}, (&(((String*)((glob->access_names)->values))[self->_base.access]))) )
    }
    else {
      if (!self->_base.is_output && self->_base.access != ACCESS_COPY) {
        if ((self->_base.access) < 0 || (self->_base.access) >= (glob->access_names)->length) RAISE(328)
        CHECK(328, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){10, 9, "parameter"}, self->variable->name, &(String){49, 48, "access should be \"copy\" for primitive types, got"}, (&(((String*)((glob->access_names)->values))[self->_base.access]))) )
      }
    }
  }
  else {
    if (self->_base.access == ACCESS_COPY) {
      CHECK(334, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){9, 8, "argument"}, self->variable->name, &(String){51, 50, "access should not be \"copy\" for non-primitive type"}, self->variable->type_instance->type_data->name) )
    }
  }
  CHECK(339, TypeInstance_analyze_lengths(self->variable->type_instance, &(self->_base._base)) )
  if (self->_base.is_native) {
    if (self->_base.access == ACCESS_OWNER) {
      CHECK(342, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "owner argument to native function"}) )
    }
    if (self->_base.is_output && self->_base.access == ACCESS_USER) {
      CHECK(344, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "user output to native function"}) )
    }
    
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_get_type_instance(DeclarationArgument* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_get_type_instance = "DeclarationArgument.get-type-instance";
#define MR_FUNC_NAME _func_name_DeclarationArgument_get_type_instance
Returncode DeclarationArgument_get_type_instance(DeclarationArgument* self, TypeInstance** type_instance) {
  (*type_instance) = self->variable->type_instance;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_get_variable(DeclarationArgument* self, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_get_variable = "DeclarationArgument.get-variable";
#define MR_FUNC_NAME _func_name_DeclarationArgument_get_variable
Returncode DeclarationArgument_get_variable(DeclarationArgument* self, SyntaxTreeVariable** variable) {
  (*variable) = self->variable;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgument_write(DeclarationArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgument_write = "DeclarationArgument.write";
#define MR_FUNC_NAME _func_name_DeclarationArgument_write
Returncode DeclarationArgument_write(DeclarationArgument* self) {
  if (self->variable->type_instance->type_data == &(glob->type_func->_base)) {
    CHECK(355, write(&(String){14, 13, "Returncode (*"}) )
    if (self->_base.is_output) {
      CHECK(357, write(&(String){2, 1, "*"}) )
    }
    CHECK(358, write_cname(self->variable->name) )
    CHECK(359, write(&(String){2, 1, ")"}) )
    CHECK(360, (self->variable->type_instance->arguments)->_base._dtl[3](self->variable->type_instance->arguments) )
    return OK;
  }
  /* `type`[*][*] `name` */
  /* [, RefManager*[*] `name`_Refman] */
  /* [, `type`_Dynamic*[*] `name`_Dynamic] */
  CHECK(365, write_cname(self->variable->type_instance->type_data->name) )
  if (!self->variable->type_instance->type_data->is_primitive) {
    CHECK(367, write(&(String){2, 1, "*"}) )
  }
  if (self->_base.is_output) {
    CHECK(369, write(&(String){2, 1, "*"}) )
  }
  CHECK(370, write(&(String){2, 1, " "}) )
  CHECK(371, write_cname(self->variable->name) )
  
  if (!self->variable->type_instance->type_data->is_primitive &&  ! self->_base.is_native) {
    CHECK(375, write(&(String){14, 13, ", RefManager*"}) )
    if (self->_base.is_output) {
      CHECK(377, write(&(String){2, 1, "*"}) )
    }
    CHECK(378, write(&(String){2, 1, " "}) )
    CHECK(379, write_cname(self->variable->name) )
    CHECK(380, write(&(String){8, 7, "_Refman"}) )
  }
  
  if (self->variable->type_instance->type_data->is_dynamic &&  ! self->_base.is_native) {
    CHECK(383, write(&(String){3, 2, ", "}) )
    CHECK(384, write_cname(self->variable->type_instance->type_data->name) )
    CHECK(385, write(&(String){10, 9, "_Dynamic*"}) )
    if (self->_base.is_output) {
      CHECK(387, write(&(String){2, 1, "*"}) )
    }
    CHECK(388, write(&(String){2, 1, " "}) )
    CHECK(389, write_cname(self->variable->name) )
    CHECK(390, write(&(String){9, 8, "_Dynamic"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func DeclarationArgument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func DeclarationArgument__dtl[] = {(void*)DeclarationArgument_get_parent_type, (void*)DeclarationArgument_link_types, (void*)DeclarationArgument_analyze, (void*)DeclarationArgument_write, (void*)DeclarationArgument_copy_new, (void*)DeclarationArgument_parse_value, (void*)DeclarationArgument_get_type_instance, (void*)Argument_check_same_type_as, (void*)DeclarationArgument_get_variable, (void*)Argument_get_output, (void*)Argument_write_preactions, (void*)Argument_write_postactions};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct DeclarationArgumentFactory DeclarationArgumentFactory;
#elif MR_STAGE == MR_TYPES(1)
struct DeclarationArgumentFactory {
  ArgumentFactory _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode DeclarationArgumentFactory_m_new_argument(DeclarationArgumentFactory* self, Argument** new_argument);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_DeclarationArgumentFactory_m_new_argument = "DeclarationArgumentFactory.m-new-argument";
#define MR_FUNC_NAME _func_name_DeclarationArgumentFactory_m_new_argument
Returncode DeclarationArgumentFactory_m_new_argument(DeclarationArgumentFactory* self, Argument** new_argument) {
  DeclarationArgument* _DeclarationArgument90 = malloc(sizeof(DeclarationArgument));
  if (_DeclarationArgument90 == NULL) RAISE(395)
  *_DeclarationArgument90 = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, false, NULL};
  _DeclarationArgument90->_base._base._dtl = DeclarationArgument__dtl;
  (*new_argument) = &(_DeclarationArgument90->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func DeclarationArgumentFactory__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func DeclarationArgumentFactory__dtl[] = {(void*)DeclarationArgumentFactory_m_new_argument};
#endif


/* to be mocked in unit-tests */
#if MR_STAGE == MR_DECLARATIONS
Returncode write_pre_func(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_pre_func = "write-pre-func";
#define MR_FUNC_NAME _func_name_write_pre_func
Returncode write_pre_func(SyntaxTreeFunction* self) {
  CHECK(400, write(&(String){24, 23, "\n#define MR_FILE_NAME \""}) )
  CHECK(401, write(self->_base._base._base.input_file_name) )
  CHECK(402, write(&(String){25, 24, "\"\n#define MR_FUNC_NAME \""}) )
  if (NULL != self->parent_type) {
    CHECK(404, write(self->parent_type->name) )
    CHECK(405, write(&(String){2, 1, "."}) )
  }
  CHECK(406, write(self->name) )
  CHECK(407, write(&(String){2, 1, "\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

/* to be mocked in unit-tests */
#if MR_STAGE == MR_DECLARATIONS
Returncode write_post_func();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_post_func = "write-post-func";
#define MR_FUNC_NAME _func_name_write_post_func
Returncode write_post_func() {
  CHECK(411, write(&(String){21, 20, "#undef MR_FILE_NAME\n"}) )
  CHECK(412, write(&(String){21, 20, "#undef MR_FUNC_NAME\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/argument.c"
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "expression/base-type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/native.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "syntax-tree/test.c"
#include "syntax-tree/type.c"
#include "syntax-tree/type-instance.c"
#include "syntax-tree/variable.c"
#include "mr4-compiler.c"
#if MR_STAGE == MR_TYPES(1)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(2)
#elif MR_STAGE == MR_TYPES(2)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(3)
#elif MR_STAGE == MR_TYPES(3)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(4)
#elif MR_STAGE == MR_TYPES(4)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(5)
#endif
#undef MR_INCLUDES
#endif

#endif
