//This code was not purposefully obfuscated; the #define's were needed to comply with this plaform's source size constraints
#include<algorithm>
#include<array>
#include<bitset>
#include<cassert>
#include<cstring>
#include<cmath>
#include<complex>
#include<cstdio>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<limits>
#include<map>
#include<memory>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<valarray>
#include<vector>
#include<type_traits>
#include<typeinfo>
#include<tuple>
#define Ej std::index_sequence_for
#define Wu internal_build
#define O decltype
#define Wy apply
#define Ed __arg2__
#define Wt is_leaf
#define d this
#define We point_update
#define Ww def_iterable_ostream
#define a query_merge
#define W0 int
#define E9 get_val
#define W5 std::decay_t
#define W8 not
#define W7 to_nested_vector_impl
#define o typename
#define W6 struct
#define w size_t
#define Eg std::index_sequence
#define E8 range_query
#define W_ query_id
#define W4 BinaryTree
#define W3 static
#define Ef std::forward
#define W2 Args
#define Wf strict_range_tree_iterator
#define Eh ostream_tuple_helper_
#define Es std::is_convertible_v
#define Ea step
#define Wg Operation
#define Wh has_children
#define WB push_back
#define QM left_child
#define QN tuple_tail
#define QB is_composable
#define QV std::tuple
#define QC j_end
#define Eu apply_operation
#define Ey find_first_after
#define QA interval
#define Wr std::remove_reference_t
#define Et std::tuple_element_t
#define Eo val
#define Er else
#define E7 persistent_binary_tree
#define Ee std::apply
#define Ew iterable_wrapper
#define QX std::get
#define Qs full_query
#define QZ __arg1__
#define QL modify
#define Qa internal_range_update
#define Eq is_composable_v
#define Y auto
#define E0 std::vector
#define QK right_half
#define E5 right_index
#define QJ std::ostream
#define Wv go_left
#define Qo contains
#define M template
#define Ep get_interval
#define QF for
#define QD std::move
#define E6 range_tree_find_last_before_impl
#define QS find_last_before
#define WO get_root
#define E4 range
#define E3 bool
#define B inline
#define R return
#define WV __tuple__
#define WC constexpr
#define E2 tuple_many_of_t
#define WF lazy_range_tree_vertex
#define W pred
#define QP std::declval
#define WN advance
#define QO iterator_macro
#define QI cartesian_product
#define WW implicit_lambda
#define QU build
#define z operator
#define X Idx
#define W9 class
#define QY tuple_head
#define QT to_vector
#define QW QueryMerge
#define Ws __expr1__
#define QR left_index
#define WA it_end
#define Wp range_tree_find_first_after
#define QE def_iterator_manip_iter
#define Wi get_operation
#define WJ is_iterable_v
#define WH std::make_signed_t
#define WG fast_range_tree
#define QH go_right
#define Q6 has_updated
#define Qn set_right_child
#define WD _range_tree_full_merge_impl
#define QQ private
#define Z Iterator
#define Qm set_left_child
#define WS mutable
#define Wk k_ptr
#define WK contiguous_binary_tree
#define WP sparse_binary_tree
#define WI new_vertex
#define WU total
#define WM size
#define WY false
#define Qb iter
#define WT zipped_range_tree_iterator
#define Qg ::iterator
#define E1 args
#define Q const
#define Qx base_range_tree
#define WR nested_vector_impl
#define WE public
#define Qz no_op
#define Qu container_carrying_iterator
#define Ql __arg3__
#define WQ right_child
#define Qj lazy_range_tree_iterator
#define Ei Operation::identity
#define Wn std::invoke_result_t
#define Wj range_tree_find_last_before
#define Wb tree
#define Qf std::conditional_t
#define Qd std::make_index_sequence
#define Wc true
#define Wx implicit_lambda_binary_operator
#define Wz tree_ptr
#define L query_f
#define Qp jv_ptr
#define Wm internal_point_update
#define Wl std::end
#define Qi propagate
#define Qy std::shared_ptr
#define Q2 vertex
#define A other
#define Qr is_composable_
#define WX std::enable_if_t
#define Qe disjoint
#define Wq pending_operation
#define Qw merge
#define W1 GET_5TH_ARG
#define Qt is_end
#define Q0 vs_ptr
#define Q9 tuple_many_of
#define Q8 std::is_rvalue_reference_v
#define WZ iterator
#define Q7 cartesian_product_incr_
#define QG Pred
#define E QueryF
#define Q_ max_pow2
#define H std::begin
#define Wd implicit_lambda_unary_operator
#define WL identity
#define Wo using
#define Qv has_advanced
#define Qc Operation::merge
#define P void
#define Qk nested_vector_at
#define Qh its
#define Wa nested_vector_size
#define Q4 combinations_with_replacement_impl
#define Q3 range_tree_range_query
#define Qq range_tree_find_first_after_impl
#define Q5 full_merge
#define Q1 my_v

M<o T,w>Wo ignore_second=T;M<w...Ix,o T>Y tuple_many_of_impl(Eg<Ix...>,Q T&x){R QV(ignore_second<T,Ix>(x)...);}M<w n,o T>Y Q9(Q T&x){R tuple_many_of_impl(Qd<n>{},x);}M<w n,o T>Wo E2=O(Q9<n,T>(QP<T>()));M<o...W2>Y QY(Q QV<W2...>&t){R QX<0>(t);}M<w...Ix,o...W2>Y tuple_tail_impl(Eg<Ix...>,Q QV<W2...>&t){R QV(QX<Ix+1>(t)...);}M<o...W2>Y QN(Q QV<W2...>&t){R tuple_tail_impl(Qd<sizeof...(W2)-1>{},t);}W6 empty_t{};WC empty_t empty_v;M<o T1,o T2>std::common_type_t<T1,T2>maxx(Q T1&x,Q T2&y){if(x<y){R y;}Er{R x;}} M<o T1,o T2,o...Ts>B Y maxx(Q T1&x,Q T2&y,Q Ts&...xs){R maxx(maxx(x,y),xs...);}M<o T1,o T2>Y minn(Q T1&x,Q T2&y){if(x<=y){R x;}Er{R y;}} M<o T1,o T2,o...Ts>B Y minn(Q T1&x,Q T2&y,Q Ts&...xs){R minn(minn(x,y),xs...);}WC W0 _log2(W0 x){if(x==0){R 0;}R 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){R f;}
#define FF_1(QZ,f)[&](Y&&QZ){(P)QZ;R f;}
#define FF_2(QZ,Ed,f)[&](Y&&QZ,Y&&Ed){(P)QZ;(P)Ed;R f;}
#define FF_3(QZ,Ed,Ql,f)[&](Y&&QZ,Y&&Ed,Y&&Ql){(P)QZ;(P)Ed;(P)Ql;R f;}
#define FF_macro_chooser(...)W1(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->Y&{R f;}
#define FREF_1(QZ,f)[&](Y&&QZ)->Y&{(P)QZ;R f;}
#define FREF_2(QZ,Ed,f)[&](Y&&QZ,Y&&Ed)->Y&{(P)QZ;(P)Ed;R f;}
#define FREF_3(QZ,Ed,Ql,f)[&](Y&&QZ,Y&&Ed,Y&&Ql)->Y&{(P)QZ;(P)Ed;(P)Ql;R f;}
#define FREF_macro_chooser(...)W1(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){R f;}
#define FC_1(QZ,f,c)[&,c](Y&&QZ){(P)QZ;R f;}
#define FC_2(QZ,Ed,f,c)[&,c](Y&&QZ,Y&&Ed){(P)QZ;(P)Ed;R f;}
#define FC_macro_chooser(...)W1(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){R f;}
#define FC2_1(QZ,f,c1,c2)[&,c1,c2](Y&&QZ){(P)QZ;R f;}
#define FC2_2(QZ,Ed,f,c1,c2)[&,c1,c2](Y&&QZ,Y&&Ed){(P)QZ;(P)Ed;R f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(QZ,f)[&](Y&&WV){Y&[QZ]=WV;(P)QZ;R f;}
#define FT_2(QZ,Ed,f)[&](Y&&WV){Y&[QZ,Ed]=WV;(P)QZ;(P)Ed;R f;}
#define FT_3(QZ,Ed,Ql,f)[&](Y&&WV){Y&[QZ,Ed,Ql]=WV;(P)QZ;(P)Ed;(P)Ql;R f;}
#define FT_4(QZ,Ed,Ql,__arg4__,f)[&](Y&&WV){Y&[QZ,Ed,Ql,__arg4__]=WV;(P)QZ;(P)Ed;(P)Ql;(P)__arg4__;R f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Ws,f)[&](){Y&&Ws;R f;}()
#define LET_2(Ws,__expr2__,f)[&](){Y&&Ws;Y&&__expr2__;R f;}()
#define LET_3(Ws,__expr2__,__expr3__,f)[&](){Y&&Ws;Y&&__expr2__;Y&&__expr3__;R f;}()
#define LET_macro_chooser(...)W1(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,E1,code)WC W6{Wo Qr=P;templ B O(Y)z()E1 Q code}name;
M<o F>W9 WW{QQ:F f;WE:WW(F f_):f(f_){} M<o...Ts>WC Y z()(Ts&&...xs)Q{R f(Ef<Ts>(xs)...);}};WW _([](Y&&x)->Qf<Q8<O(x)>,Wr<O(x)>,O(x)>{R x;});WW _1([](Y&&x,Y&&)->Qf<Q8<O(x)>,Wr<O(x)>,O(x)>{R x;});WW _2([](Y&&,Y&&y)->Qf<Q8<O(y)>,Wr<O(y)>,O(y)>{R y;});
#define implicit_lambda_unary_operator(op)M<o F>WC O(Y)z op(WW<F>f){R WW([=](Y&&...xs){R op f(Ef<O(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)M<o F,o T>WC O(Y)z op(WW<F>f,Q T&y){R WW([=](Y&&...xs){R f(Ef<O(xs)>(xs)...)op y;});}M<o F,o T>WC O(Y)z op(Q T&y,WW<F>f){R WW([=](Y&&...xs){R y op f(Ef<O(xs)>(xs)...);});}M<o F,o G>WC O(Y)z op(WW<F>f,WW<G>g){R WW([=](Y&&...xs){R f(Ef<O(xs)>(xs)...)op g(Ef<O(xs)>(xs)...);});}
Wd(+)Wd(-)Wd(!)Wd(~)Wd(*)Wd(&)Wx(+)Wx(-)Wx(*)Wx(/)Wx(%)Wx(<)Wx(>)Wx(<=)Wx(>=)Wx(==)Wx(!=)Wx(<<)Wx(>>)Wx(&)Wx(|)Wx(^)Wx(&&)M<o T,o=P>W6 QB:WE std::false_type{};M<o T>W6 QB<T,std::void_t<o T::is_composable_>>:WE std::true_type{};M<o T>WC E3 Eq=QB<T>::value;M<o T,o F,o=Wn<F,T>>O(Y)z>(T&&v,Q F&f){R f(Ef<T>(v));}M<o M1,o M2>W6 composed{Wo Qr=P;Q M1 m1;Q M2 m2;M<o T>O(Y)z()(T&&v)Q{R m1(m2(Ef<T>(v)));}};M<o M1,o M2,o=WX<Eq<M1>or Eq<M2>>>B Y z<(Q M1&m1,Q M2&m2){R composed<M1,M2>{m1,m2};}M<w n>W6 nth_impl{Wo Qr=P;M<o...Ts>WC Et<n,QV<Ts...>>&z()(QV<Ts...>&u)Q{R QX<n>(u);}M<o...Ts>WC Et<n,QV<Ts...>>z()(QV<Ts...>&&u)Q{R QX<n>(u);}M<o...Ts>WC Q Et<n,QV<Ts...>>&z()(Q QV<Ts...>&u)Q{R QX<n>(u);}M<o...Ts>WC Q Et<n,QV<Ts...>>z()(Q QV<Ts...>&&u)Q{R QX<n>(u);}};M<w n>WC nth_impl<n>nth;WC nth_impl<0>fst;WC nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,Eo)W6 Z{extra E3 z!=(Q Z&A)Q neq Z&z++()incr O(Y)z*()Q Eo};
#define def_iterator_manip_iter(name,templ,E1,args_,extra,it_begin,WA,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,E1,args_,extra,{QO(extra extra_it WS I it;,neq_it,incr_it,val_it);R Ew(it_begin,WA);})
#define def_iterator_manip_2(name,code)WC W6{Wo Qr=P;M<o T,o I=O(H(QP<T>())),o V=W5<O(*QP<I>())>>O(Y)z()(T&&v)Q code}name;
#define def_iterator_manip_6(name,templ,E1,args_,extra,code)templ W6 name##_impl{Wo Qr=P;extra M<o T,o I=O(H(QP<T>())),o V=W5<O(*QP<I>())>>O(Y)z()(T&&v)Q code};templ B O(Y)name E1{R name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
M<o T,o=P>W6 is_iterable:WE std::false_type{};M<o T>W6 is_iterable<T,std::void_t<O(H(QP<T>())),O(Wl(QP<T>()))>>:WE std::true_type{};M<o T>WC E3 WJ=is_iterable<T>::value;M<o I>B Y Ew(Q I&b,Q I&e){W6 Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
Wo is_iterable_wrapper=P;Wo WZ=I;Wo value_type=W5<O(*QP<I>())>;
#pragma GCC diagnostic pop
I b,e;Y begin()Q{R b;}Y end()Q{R e;}};R Wrapper{b,e};}M<o T>B Y Qb(T&&iterable){R Ew(H(Ef<T>(iterable)),Wl(Ef<T>(iterable)));}M<o I>B Y Qb(Q I&b,Q I&e){R Ew(b,e);}M<o C>W6 Qu:WE C::iterator{Qy<C>p;Qu(Qy<C>p_,o C::iterator it):C::iterator(it),p(p_){}};M<o C>B Y iterc(C&&v){Wo D=W5<C>;Qy<D>p(new D(Ef<C>(v)));R Ew(Qu<D>{p,H(*p)},Qu<D>{p,Wl(*p)});}M<o T>B Y Qb(std::initializer_list<T>l){R iterc(E0<T>(l));}def_template_lambda(M<o T>,QT,(T&&v),{E0<o W5<T>::value_type>s;QF(Y&&x:v){s.WB(x);}R s;})M<w n>W6 W7{M<o T>B W3 Y make(T&&v){R Ef<T>(v)>Wy(FF(u,W7<n-1>::make(u)))>QT;}};M<>W6 W7<1>{M<o T>B W3 Y make(T&&v){R Ef<T>(v)>QT;}};M<w n>W6 to_nested_vector_{Wo Qr=P;M<o T>B O(Y)z()(T&&v)Q{R W7<n>::make(Ef<T>(v));}};M<w n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(w l,w r),({l,r}),w l;w r;,{R Qb(H(v)+l,H(v)+r);})def_iterator_manip(is_nil,{R W8(H(v)!=Wl(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{w l=0;QF(Y i=H(v);i!=Wl(v);++i){++l;}R l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
M<o T1,o T2,o T3,o T=WH<O(T1()+T2()+T3())>>B Y E4(Q T1&b,Q T2&e,Q T3&Ea){QO(T x;T e;T Ea;B E3 Qt()Q{R(Ea>=T(0)and x>=e)or(Ea<T(0)and x<=e);},{R Qt()xor A.Qt();},{x+=Ea;R*d;},{R T(x);}) R Qb(Z{b,e,Ea},Z{e,e,Ea});}M<o T1,o T2>B Y E4(Q T1&b,Q T2&e){R E4(b,e,O(T1()+T2())(1));}M<o T>B Y E4(Q T&e){R E4(T(),e,T(1));} 
#pragma GCC diagnostic pop
M<o T>B Y to_infinity(Q T&b=0,Q T&Ea=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
QO(T x;T Ea;,{(P)A;R Wc;},{x+=Ea;R*d;},{R T(x);}) R Qb(Z{b,Ea},Z{b,Ea});
#pragma GCC diagnostic pop
}QE(Wy,M<o F>,(F f),<F>{f},F f;,(Z{f,H(v)}),(Z{f,Wl(v)}),,{ R it!=A.it;},{++it;R*d;},{R f(*it);}) QE(take,,(w n),{n},w n;,(Z{n,H(v)}),(Z{0,Wl(v)}),,{ R n!=A.n;},{--n;if(n>0){++it;}R*d;},{R*it;}) QE(take_while,M<o F>,(F f),<F>{f},F f;,(Z{f,W8(H(v)!=Wl(v)and f(*H(v))),H(v)}),(Z{f,Wc,Wl(v)}),E3 Qt;,{R Qt xor A.Qt;},{++it;if(W8 f(*it)){Qt=Wc;}R*d;},{R*it;}) QE(drop,,(w n),{n},WS w n;,(Z{n,Wl(v),H(v)}),(Z{0,Wl(v),Wl(v)}),Q I end_it;B P WN()Q{while(n>0){if(W8(it!=end_it)){n=0;break;}--n;++it;}},{WN();A.WN();R it!=A.it;},{WN();++it;R*d;},{WN();R*it;}) QE(drop_while,M<o F>,(F f),<F>{f},F f;,(Z{f,Wl(v),WY,H(v)}),(Z{f,Wl(v),Wc,Wl(v)}),Q I end_it;WS E3 Qv;B P WN()Q{if(W8 Qv){while(it!=end_it and f(*it)){++it;}Qv=Wc;}},{WN();A.WN();R it!=A.it;},{WN();++it;R*d;},{WN();R*it;}) def_iterator_manip(head,{R*H(v);})B Y tail=drop(1);B Y at(w n){R head<drop(n);}QE(cons,M<o S>,(S s),<S>{s},S s;,(Z{s,Wc,H(v)}),(Z{s,WY,Wl(v)}),E3 is_s;,{R is_s!=A.is_s or it!=A.it;},{if(is_s){is_s=WY;}Er{++it;}R*d;},{R(is_s)?(s):(*it);}) def_iterator_manip(snoc,{Y it=H(v);Y h=*it;++it;R QV(h,Qb(it,Wl(v)));})def_iterator_manip(split_at,,(w n),{n},w n;,{Y it=H(v);E0<T>u;QF(Y i:E4(n)){u.WB(*it);++it;}R QV(iterc(QD(u)),Qb(it,Wl(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
QE(chunks_of,,(w n),{n},w n;,(Z{n,{},WY,Wl(v),H(v)}),(Z{n,{},WY,Wl(v),Wl(v)}),WS E0<V>u;WS E3 Q6;I WA;P update()Q{u.clear();Q6=Wc;QF(Y i:E4(n)){if(it!=WA){u.WB(*it);++it;}Er{break;}}},{R it!=A.it;},{if(Q6){Q6=WY;}Er{QF(Y i:E4(n)){if(it!=WA){++it;}Er{break;}}}R*d;},{if(W8 Q6){update();}R iterc(u);})
#pragma GCC diagnostic pop
M<o F,o S>W6 fold_impl{Wo Qr=P;F f;S s;M<o T>Y z()(Q T&v)Q{Y x=s;QF(Y y:v){x=f(x,y);}R x;}};M<o F,o S>B Y fold(F f,Q S&s){R fold_impl<F,S>{f,s};}def_iterator_manip(fold1,M<o F>,(F f),<F>{f},F f;,{Y u=v>snoc;R u>snd>fold(f,u>fst);})def_iterator_manip(sum,{R v>fold(_1+_2,V(0));})def_iterator_manip(product,{R v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,M<o F>,(F f),<F>{f},F f;,{R v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{R v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,M<o F>,(F f),<F>{f},F f;,{R v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,M<o F>,(F f),<F>{f},F f;,{R v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{R v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,M<o F>,(F f),<F>{f},F f;,{R v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})M<o F,o S>W6 scan_impl{Wo Qr=P;F f;S s;M<o T,o I=O(H(QP<T>()))>O(Y)z()(T&&v)Q{QO(F f;WS S s;WS E3 Q6;E3 Qv;WS I it;,{R it!=A.it;},{if(W8 Q6){s=f(s,*it);};Q6=WY;if(Qv){++it;}Er{Qv=Wc;}R*d;},{if(W8 Q6){Q6=Wc;s=f(s,*it);}R s;}) R Qb(Z{f,s,Wc,WY,H(Ef<T>(v))},Z{f,s,Wc,Wc,Wl(Ef<T>(v))});}};M<o F,o S>B Y scan(F f,Q S&s){R scan_impl<F,S>{f,s};}QE(scan1,M<o F>,(F f),<F>{f},F f;,(Z{f,*H(v),Wc,H(v)}),(Z{f,*H(v),Wc,Wl(v)}),WS V s;WS E3 Q6;,{R it!=A.it;},{if(W8 Q6){s=f(s,*it);};Q6=WY;++it;R*d;},{if(W8 Q6){Q6=Wc;s=f(s,*it);}R s;}) M<o T,o S,o I=O(H(QP<T>())),o J=O(H(QP<S>()))>B Y z+(T&&v,S&&u){QO(I i;I i_end;J j;E3 in_i;,{R i!=A.i or j!=A.j;},{if(in_i){++i;if(W8(i!=i_end)){in_i=WY;}}Er{++j;}R*d;},{R(in_i)?(*i):(*j);}) I bv=H(v);I ev=Wl(v);J bu=H(u);J eu=Wl(u);R Qb(Z{bv,ev,bu,bv!=ev},Z{ev,ev,eu,WY});}WC W6{Wo Qr=P;M<o T>Y z()(T&&v)Q{Y u=Ef<T>(v)>filter(FF(i,W8 is_nil(i)));Y b=H(u);Y e=Wl(u);Wo J=O(b);Wo V=W5<O(*b)>;Wo K=O(H(*b));W6 Z{J j;J QC;Qy<V>Qp;K*Wk;E3 Qt;Z(J j,J QC,Q V&jv,E3 Qt):j(j),QC(QC),Qp(new V(jv)),Wk(new K(H(*Qp))),Qt(Qt){} Z(J j,J QC,E3 Qt):j(j),QC(QC),Qp(nullptr),Wk(nullptr),Qt(Qt){} Z(Q Z&A):j(A.j),QC(A.QC),Qp(A.Qp),Wk((A.Wk)?(new K(*A.Wk)):nullptr),Qt(A.Qt){} Z(Z&&A):j(A.j),QC(A.QC),Qp(A.Qp),Wk((A.Wk)?(new K(*A.Wk)):nullptr),Qt(A.Qt){}~Z(){delete Wk;}E3 z!=(Q Z&A)Q{R Qt xor A.Qt;}Z&z++(){++*Wk;if(W8(*Wk!=Wl(*Qp))){++j;if(j!=QC){delete Wk;Qp=std::make_shared<V>(*j);Wk=new K(H(*Qp));}Er{Qt=Wc;}} R*d;}O(Y)z*()Q{R**Wk;}};if(u>is_nil){R Ew(Z(b,e,Wc),Z(b,e,Wc));}Er{R Ew(Z(b,e,*b,WY),Z(e,e,Wc));}}}flatten;M<o T,o F,o=WX<WJ<T>>>Y z>=(T&&v,F f){R v>Wy(f)>flatten;}M<o U,w...Is>B E3 all_different_(Q U&x,Q U&y,Eg<Is...>){R((QX<Is>(x)!=QX<Is>(y))&&...);}M<o F,o...Ts>B Y zip_with(F f,Ts&&...vs){QO(F f;QV<O(H(QP<Ts>()))...>Qh;,{R all_different_(Qh,A.Qh,Ej<Ts...>{});},{Ee([&](Y&&...xs){(++xs,...);},Qh);R*d;},{R Ee([&](Y&&...xs){R f(*xs...);},Qh);}) R Qb(Z{f,QV(H(vs)...)},Z{f,QV(Wl(vs)...)});};W6 zip_default_function_{M<o...Ts>O(Y)z()(Ts&&...xs)Q{R QV<Ts...>(Ef<Ts>(xs)...);}};M<o...Ts>B Y zip(Ts&&...vs){R zip_with(zip_default_function_{},Ef<Ts>(vs)...);}QE(filter,M<o F>,(F f),<F>{f},F f;,(Z{f,Wl(v),H(v)}),(Z{f,Wl(v),Wl(v)}),Q I end_it;B P WN()Q{while(it!=end_it and W8 f(*it)){++it;}},{WN();A.WN();R it!=A.it;},{WN();++it;R*d;},{WN();R*it;}) def_template_lambda(M<o T>,repeat,(T&&v),{W6 Z{Q W5<T>v;E3 z!=(Q Z&)Q{R Wc;}Z&z++(){R*d;}Q Y&z*()Q{R v;}};R Qb(Z{v},Z{v});})B Y replicate(w n){R take(n)<repeat;}B Y cycle=flatten<repeat;def_iterator_manip(enumerate,{R zip(to_infinity(w(0)),v);})def_iterator_manip(reversed,{Y s=v>QT;std::reverse(s.begin(),s.end());R iterc(QD(s));})def_iterator_manip(sorted_by,M<o F>,(F f),<F>{f},F f;,{Y s=v>QT;std::sort(H(s),Wl(s),f);R iterc(QD(s));})def_iterator_manip(sorted,{R v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,M<o F>,(F f),<F>{f},F f;,{R v>Wy(FF(i,QV(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>Wy(fst);})def_iterator_manip(nub,{QO(I WA;I it;,{R it!=A.it;},{O(*it)pr;do{pr=*it;++it;}while(it!=WA and pr==*it);R*d;},{R*it;}) Y b=H(v);Y e=Wl(v);R Qb(Z{e,b},Z{e,e});})M<o F,o S>W6 accum_vector_by_{Wo Qr=P;w n;F f;S s;M<o T,o I=O(H(QP<T>())),o V=W5<O(*QP<I>())>>O(Y)z()(Q T&v)Q{E0<W5<Wn<F,S,O(QX<1>(QP<V>()))>>>u(n,s);QF(Y&&[i,x]:v){u[i]=f(u[i],x);}R u;}};M<o F,o S>B Y accum_vector_by(w n,F f,Q S&s){R accum_vector_by_<F,S>{n,f,s};}M<o S>B Y accum_vector(w n,Q S&s=S()){R accum_vector_by(n,_2,s);}M<o F,o S>W6 accum_map_by_{Wo Qr=P;F f;S s;M<o T,o I=O(H(QP<T>())),o V=W5<O(*QP<I>())>>O(Y)z()(Q T&v)Q{std::map<W5<O(QX<0>(QP<V>()))>,W5<Wn<F,S,O(QX<1>(QP<V>()))>>>u;QF(Y&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Er{u[i]=f(s,x);}} R u;}};M<o F,o S>B Y accum_map_by(F f,Q S&s){R accum_map_by_<F,S>{f,s};}M<o S>B Y accum_map(Q S&s=S()){R accum_map_by(_2,s);}M<o F,o S>W6 accum_unordered_map_by_{Wo Qr=P;F f;S s;M<o T,o I=O(H(QP<T>())),o V=W5<O(*QP<I>())>>O(Y)z()(Q T&v)Q{std::unordered_map<W5<O(QX<0>(QP<V>()))>,W5<Wn<F,S,O(QX<1>(QP<V>()))>>>u;QF(Y&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Er{u[i]=f(s,x);}} R u;}};M<o F,o S>B Y accum_unordered_map_by(F f,Q S&s){R accum_unordered_map_by_<F,S>{f,s};}M<o S>B Y accum_unordered_map(Q S&s=S()){R accum_unordered_map_by(_2,s);}M<o U,w...Is>B E3 any_different_(Q U&x,Q U&y,Eg<Is...>){R((QX<Is>(x)!=QX<Is>(y))||...);}M<w N,o Z>B P Q7(Z&it){if WC(N>=1){++QX<N-1>(it.Qh);if(W8(QX<N-1>(it.Qh)!=Wl(QX<N-1>(*it.my_vs_ptr)))){QX<N-1>(it.Qh)=H(QX<N-1>(*it.my_vs_ptr));Q7<N-1>(it);}} Er{it.Qh=Ee([](Y&&...xs){R QV(Wl(xs)...);},*it.my_vs_ptr);}} M<o...Ts>Y QI(Ts&&...vs){Y Q0=std::make_shared<QV<Qf<Q8<Ts>,Wr<Ts>,Ts>...>>(vs...);QO(QV<O(H(QP<Qf<Q8<Ts>,Wr<Ts>,Ts>>()))...>Qh;O(Q0)my_vs_ptr;,{R any_different_(Qh,A.Qh,Ej<Ts...>{});},{Q7<sizeof...(Ts)>(*d);R*d;},{R Ee([](Y&&...xs){R QV<O(*xs)...>(*xs...);},Qh);}) if(Ee([](Y&&...xs){R((xs>is_nil)||...);},*Q0)){R Qb(Z{Ee([](Y&&...xs){R QV(Wl(xs)...);},*Q0),Q0},Z{Ee([](Y&&...xs){R QV(Wl(xs)...);},*Q0),Q0});}Er{R Qb(Z{Ee([](Y&&...xs){R QV(H(xs)...);},*Q0),Q0},Z{Ee([](Y&&...xs){R QV(Wl(xs)...);},*Q0),Q0});}};M<o...Ts>B Y cartesian_product_range(Q Ts&...n){R QI(E4(n)...);}M<w n,o I>B Y cartesian_power(Q I&v){R Ee([](Q Y&...vs){R QI(vs...);},Q9<n>(v));}W6{Wo Qr=P;W0 n=-1;M<o T>Y z()(T&&v)Q{if WC(Es<T,W0>){Y x=*d;x.n=v;R x;}Er{Y vec=v>QT;W0 m=vec.WM();W6 Z{W0 n;O(vec)Q1;E0<w>cycles;E3 Qt;E3 z!=(Q Z&A)Q{R Qt xor A.Qt;}Z&z++(){QF(Y i:E4(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=Q1.WM()-i;std::rotate(Q1.begin()+i,Q1.begin()+i+1,Q1.end());}Er{std::swap(Q1[i],Q1[Q1.WM()-cycles[i]]);R*d;}} Qt=Wc;R*d;}Y z*()Q{R Q1>array_slice(0,n);}};W0 n1=(n<0)?(m):(n);R Qb(Z{n1,QD(vec),E4(m,m-n1,-1)>Wy(FF(x,w(x)))>QT,WY},Z{n1,{},{},Wc});}}}permutations;W6 combinations_impl{Wo Qr=P;W0 n;M<o T>Y z()(T&&v)Q{Y vec=v>QT;W0 m=vec.WM();QO(W0 n;O(vec)Q1;E0<w>idx;E3 Qt;,{R Qt xor A.Qt;},{QF(Y i:E4(n-1,-1,-1)){if(idx[i]!=idx.WM()-n+i){idx[i]++;QF(Y j:E4(i+1,n)){idx[j]=idx[j-1]+1;}R*d;}} Qt=Wc;R*d;},{R idx>array_slice(0,n)>Wy(FF(i,Q1[i]));}) R Qb(Z{n,QD(vec),E4(0,m)>Wy(FF(x,w(x)))>QT,WY},Z{n,{},{},Wc});}};B Y combinations(W0 n){R combinations_impl{n};}W6 Q4{Wo Qr=P;W0 n;M<o T>Y z()(T&&v)Q{Y vec=v>QT;W0 m=vec.WM();QO(W0 n;O(vec)Q1;E0<w>idx;E3 Qt;,{R Qt xor A.Qt;},{QF(Y i:E4(n-1,-1,-1)){if(idx[i]!=idx.WM()-1){idx[i]++;QF(Y j:E4(i+1,n)){idx[j]=idx[i];}R*d;}} Qt=Wc;R*d;},{R idx>array_slice(0,n)>Wy(FF(i,Q1[i]));}) R Qb(Z{n,QD(vec),w(0)>replicate(m)>QT,WY},Z{n,{},{},Wc});}};B Y combinations_with_replacement(W0 n){R Q4{n};}M<o T>B Y istream_iterable(std::istream&in){QO(std::istream&in;WS T Eo;E3 Qt;WS E3 has_read;,{R Qt xor A.Qt;},{if(W8(in>>Eo)){Qt=Wc;}R*d;},{if(W8 has_read){has_read=Wc;in>>Eo;}R Eo;}) R Qb(Z{in,T{},WY,WY},Z{in,T{},Wc,Wc});}M<o T>B Y input=istream_iterable<T>(std::cin);M<o T>QJ&print_iterable(QJ&out,Q T&v,Q std::string&sep= " "){QF(Y it=H(v);it!=Wl(v);){ out<<*it;++it;if(it!=Wl(v)){out<<sep;}Er{R out;}} R out;}M<o T,o=o T::is_iterable_wrapper>B QJ&z<<(QJ&out,Q T&v){out<< "[";R print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)M<o...Ts>QJ&z<<(QJ&out,Q I<Ts...>&v){R out<<Qb(v);}
Ww(E0)Ww(std::map)Ww(std::unordered_map)Ww(std::set)Ww(std::unordered_set)M<w n,o T>W6 WR{Wo type=E0<o WR<n-1,T>::type>;W3 Y make(Q E2<n,w>&sz,Q T&Eo=T()){R E0(QY(sz),WR<n-1,T>::make(QN(sz),Eo));}};M<o T>W6 WR<1,T>{Wo type=E0<T>;W3 Y make(Q QV<w>&sz,Q T&Eo=T()){R E0(QY(sz),Eo);}};M<w n,o T>Wo nested_vector=o WR<n,T>::type;M<w n,o T>Y make_nested_vector(Q E2<n,w>&sz,Q T&Eo=T()){R WR<n,T>::make(sz,Eo);}M<w n,o T>B Y Wa(Q T&v){if WC(n==1){R QV(v.WM());}Er{R std::tuple_cat(QV(v.WM()),Wa<n-1>(v[0]));}} M<w n,o T>B Y nested_vector_indices(Q T&v){R Ee([&](Y...x){R cartesian_product_range(x...);},Wa<n>(v));}M<w n,o T>B O(Y)Qk(Q E0<T>&v,Q E2<n,w>&i){if WC(n==1){R v[QY(i)];}Er{R Qk<n-1>(v[QY(i)],QN(i));}} M<w n,o T>B O(Y)Qk(E0<T>&v,Q E2<n,w>&i){if WC(n==1){R v[QY(i)];}Er{R Qk<n-1>(v[QY(i)],QN(i));}} M<o U,w i,w s>QJ&Eh(QJ&out,Q U&u){if WC(i==0){out<< "{ ";}out<<QX<i>(u);if WC(i+1<s){out<< ", ";R Eh<U,i+1,s>(out,u);}Er{R out<< " }";}} M<o...Ts>QJ&z<<(QJ&out,Q QV<Ts...>&u){R Eh<O(u),0,sizeof...(Ts)>(out,u);}M<o T,o S>QJ&z<<(QJ&out,Q std::pair<T,S>&p){R out<<QV(p.first,p.second);} 
#define BEGIN  W0 main(){std::ios_base::sync_with_stdio(WY);std::cin.tie(0);std::cout.tie(0);
#define END }
Wo namespace std;Wo LL=long long;M<o T,o Merge>W9 WG{QQ:w n,Q_;Q T id;E0<E0<T>>rt;Merge Qw;WE:WG(Q T&id_,Merge merge_):id(id_),Qw(merge_){} P QU(w n_,Q T&Eo){QU(Eo>replicate(n_));}M<o I,o=WX<WJ<I>>>P QU(Q I&v){rt.emplace_back(v>QT);n=rt[0].WM();Q_=_log2(n-1)+1;QF(Y i:E4(1,Q_+1)){rt.WB(E4(0,rt[i-1].WM()/2)>Wy(FF(j,Qw(rt[i-1][2*j],rt[i-1][2*j+1])))>QT);if(rt[i-1].WM()&1){rt[i].WB(rt[i-1].back());}}}P We(w p,Q T&v){rt[0][p]=v;QF(Y i:E4(Q_)){p/=2;if(p*2+1<rt[i].WM()){rt[i+1][p]=Qw(rt[i][p*2],rt[i][p*2+1]);}Er{rt[i+1][p]=rt[i][p*2];}}}M<o E>B Y point_query(w p,E L)Q{R L(rt[0][p]);}B T point_query(w p)Q{R rt[0][p];}M<o E>B Y Qs(E L)Q{R L(rt.back().back());}B T Qs()Q{R rt.back().back();}M<o E,o S,o QW>Y E8(w l,w r,Q S&W_,E L,QW a)Q{if(l>=r){R W_;}S ans=W_;QF(W0 i=0;r-l>=(1<<i);++i){w j=1<<i;if(l&j){ans=a(L(rt[i][l>>i]),ans);l+=j;if(l>=r){R ans;}} if(r&j){r-=j;ans=a(ans,L(rt[i][r>>i]));}} R ans;}B Y E8(w l,w r)Q{R E8(l,r,id,_,Qw);}M<o QG,o E,o S,o QW>long long Ey(w l,QG W,Q S&W_,E L,QW a)Q{if(W(W_)){R l;}if(l==0){if(W(point_query(0,L))){R 1;}Er{l=1;}} Y WU=W_;QF(Y i:E4(Q_)){if(l>=WM()){break;}w j=1<<i;if(l&j){Y y=a(WU,L(rt[i][l>>i]));if(W(y)){QF(W0 k=i-1;k>=0;--k){y=a(WU,L(rt[k][l>>k]));if(W8 W(y)){l+=1<<k;WU=y;}} R l+1;}Er{l+=j;WU=y;}}}R-1;}M<o QG>B long long Ey(w l,QG W)Q{R Ey(l,W,id,_,Qw);}M<o QG,o E,o S,o QW>long long QS(w r,QG W,Q S&W_,E L,QW a)Q{if(W(W_)){R r;}Y WU=W_;QF(Y i:E4(Q_+1)){w j=1<<i;if(r&j){Y y=a(L(rt[i][(r>>i)-1]),WU);if(W(y)){QF(W0 k=i-1;k>=0;--k){y=a(L(rt[k][(r>>k)-1]),WU);if(W8 W(y)){r-=1<<k;WU=y;}} R r-1;}Er{r-=j;WU=y;}}}R-1;}M<o QG>B long long QS(w r,QG W)Q{R QS(r,W,id,_,Qw);}B w WM()Q{R n;}};M<o T,o Merge>Y make_fast_range_tree(Q T&id,Merge Qw=Merge()){R WG<T,Merge>(id,Qw);}M<o X>W6 QA{X l,r;E3 Qo(Q QA&A)Q{R l<=A.l and A.r<=r;}E3 Qo(Q X&p)Q{R l<=p and p<r;}E3 Qe(Q QA&A)Q{R r<=A.l or A.r<=l;}P left_half(){r=(l+r)/2;}P QK(){l=(l+r)/2;}X WM()Q{R r-l;}};M<o X,o T>W9 WK{QQ:w sz;E0<T>Wb;WE:W9 WZ{QQ:WK<X,T>*Wz;w j;QA<X>i;WE:explicit WZ(WK<X,T>*t):Wz(t),j(1),i{0,X(t->sz)}{} B WZ QL(){R*d;}B P Qm(Q WZ&){} B P Qn(Q WZ&){} B P Wv(){i.left_half();j=j*2;}B P QH(){i.QK();j=j*2+1;}B WZ QM()Q{WZ it(*d);it.Wv();R it;}B WZ WQ()Q{WZ it(*d);it.QH();R it;}B E3 Wt()Q{R i.WM()==1;}B E3 Wh()Q{R i.WM()>1;}T&z*()Q{R Wz->Wb[j];}T*z->()Q{R&(Wz->Wb[j]);}B Y Ep()Q{R i;}B X QR()Q{R i.l;}B X E5()Q{R i.r;}};M<o Gen>P QU(X n,Gen gen){Wb.resize(1<<(_log2(n-1)+2));QF(Y&x:Wb){x=gen();}sz=n;}B X WM()Q{R sz;}WZ WO(){R WZ(d);}};M<o X,o T>W9 WP{QQ:W6 Q2{T Eo;w l=0,r=0;};X sz;E0<Q2>Wb;std::function<T()>gen;B w WI(){Wb.WB(Q2{gen(),0,0});R Wb.WM()-1;}B P Qi(w j){if(Wb[j].l==Wb[j].r){Wb[j].l=WI();Wb[j].r=WI();}} WE:W9 WZ{QQ:WP<X,T>*Wz;w j;QA<X>i;WE:explicit WZ(WP<X,T>*t):Wz(t),j(0),i{0,X(t->WM())}{} B P Qi(){Wz->Qi(j);}B WZ&QL(){R*d;}B P Qm(Q WZ&){} B P Qn(Q WZ&){} B P Wv(){Qi();i.left_half();j=Wz->Wb[j].l;}B P QH(){Qi();i.QK();j=Wz->Wb[j].r;}B WZ QM()Q{WZ it(*d);it.Wv();R it;}B WZ WQ()Q{WZ it(*d);it.QH();R it;}B E3 Wt()Q{R i.WM()==1;}B E3 Wh()Q{R Wz->Wb[j].l;}T&z*()Q{R Wz->Wb[j].Eo;}T*z->()Q{R&(Wz->Wb[j].Eo);}B Y Ep()Q{R i;}B X QR()Q{R i.l;}B X E5()Q{R i.r;}};M<o Gen>P QU(X n,Gen gen_){gen=gen_;WI();sz=n;}B X WM()Q{R sz;}WZ WO(){R WZ(d);}};M<o X,o T>W9 E7{QQ:W6 Q2{T Eo;w l=0,r=0;};X sz;E0<Q2>Wb;std::function<T()>gen;B w WI(){Wb.WB(Q2{gen(),0,0});R Wb.WM()-1;}B w WI(Q Q2&v){Wb.WB(v);R Wb.WM()-1;}B P Qi(w j){if(Wb[j].l==Wb[j].r){Wb[j].l=WI();Wb[j].r=WI();}} WE:W9 WZ{QQ:E7<X,T>*Wz;w j;QA<X>i;WE:explicit WZ(E7<X,T>*t):Wz(t),j(0),i{0,X(t->WM())}{} B P Qi(){Wz->Qi(j);}B WZ&QL(){j=Wz->WI(Wz->Wb[j]);R*d;}B P Qm(Q WZ&it){Wz->Wb[j].l=it.j;}B P Qn(Q WZ&it){Wz->Wb[j].r=it.j;}B P Wv(){Qi();i.left_half();j=Wz->Wb[j].l;}B P QH(){Qi();i.QK();j=Wz->Wb[j].r;}B WZ QM()Q{WZ it(*d);it.Wv();R it;}B WZ WQ()Q{WZ it(*d);it.QH();R it;}B E3 Wt()Q{R i.WM()==1;}B E3 Wh()Q{R Wz->Wb[j].l;}T&z*()Q{R Wz->Wb[j].Eo;}T*z->()Q{R&(Wz->Wb[j].Eo);}B Y Ep()Q{R i;}B X QR()Q{R i.l;}B X E5()Q{R i.r;}};M<o Gen>P QU(X n,Gen gen_){gen=gen_;WI();sz=n;}B X WM()Q{R sz;}WZ WO(){R WZ(d);}};M<o X,o Z,o E,o QW>Y Q3(Z it,Q QA<X>&i,E L,QW a){if(i.Qo(it.Ep())or(it.Qz()and W8 it.Wh())){R L(it.E9());}it.Qi();if(i.Qe(it.QM().Ep())){R Q3(Z(it.WQ()),i,L,a);}if(i.Qe(it.WQ().Ep())){R Q3(Z(it.QM()),i,L,a);}R a(Q3(Z(it.QM()),i,L,a),Q3(Z(it.WQ()),i,L,a));}M<o X,o Z,o S,o QG,o E,o QW>QV<S,WH<X>>Qq(Z it,X l,S WU,QG W,E L,QW a){if(l<=it.QR()){if(W(WU)){R{WU,l};}Y y=a(WU,L(it.E9()));if(W8 W(y)){R{y,-1};}while(W8 it.Wt()){it.Qi();y=a(WU,L(it.QM().E9()));if(W(y)){it.Wv();}Er{it.QH();WU=y;}} R{WU,it.E5()};}it.Qi();Z rc=it.WQ();if(l>=rc.QR()){R Qq(rc,l,WU,W,L,a);}Z lc=it.QM();Y[tot_l,ans]=Qq(lc,l,WU,W,L,a);if(ans==-1){R Qq(rc,l,tot_l,W,L,a);}Er{R{tot_l,ans};}} M<o X,o Z,o S,o QG,o E,o QW>WH<X>Wp(Z it,X l,Q S&W_,QG W,E L,QW a){if(l>=it.E5()){R(W(W_))?(it.E5()):(-1);}R QX<1>(Qq(it,l,W_,W,L,a));}M<o X,o Z,o S,o QG,o E,o QW>QV<S,WH<X>>E6(Z it,X r,S WU,QG W,E L,QW a){if(r>=it.E5()){if(W(WU)){R{WU,r};}Y y=a(L(it.E9()),WU);if(W8 W(y)){R{y,-1};}while(W8 it.Wt()){it.Qi();y=a(L(it.WQ().E9()),WU);if(W(y)){it.QH();}Er{it.Wv();WU=y;}} R{WU,it.QR()};}it.Qi();Z lc=it.QM();if(r<=lc.E5()){R E6(lc,r,WU,W,L,a);}Z rc=it.WQ();Y[tot_r,ans]=E6(rc,r,WU,W,L,a);if(ans==-1){R E6(lc,r,tot_r,W,L,a);}Er{R{tot_r,ans};}} M<o X,o Z,o S,o QG,o E,o QW>WH<X>Wj(Z it,X r,Q S&W_,QG W,E L,QW a){if(r<=0){R(W(W_))?(0):(-1);}R QX<1>(E6(it,r,W_,W,L,a));}M<o Wg,o T,o=P>W6 WD{B W3 P f(T&x,Q T&lc,Q T&rc,Q Wg&){x=Qc(lc,rc);}};M<o Wg,o T>W6 WD<Wg,T,O(Qc(QP<T&>(),QP<T>(),QP<T>(),QP<Wg>()))>{B W3 P f(T&x,Q T&lc,Q T&rc,Q Wg&op){Qc(x,lc,rc,op);}};M<o X,o T,o W4,o Z>W9 Qx{protected:WS W4 bt;M<o S>P Wu(Z it,Q E0<S>&v){if(it.Ep().Qe(QA<X>{0,X(v.WM())})){R;}if(it.Wt()){it.E9()=v[it.QR()];R;}Wu(it.QM(),v);Wu(it.WQ(),v);it.E9()=Iterator::merge(it.QM().E9(),it.WQ().E9());}WE:M<o Gen>B Z QU(X n,Gen gen){if WC(Es<Gen,T>){d->bt.QU(n,FC(gen,gen));}Er{d->bt.QU(n,gen);}R WO();}M<o I,o=WX<WJ<I>>>B Z QU(Q I&v){QU(v>QT);R WO();}M<o S>Z QU(Q E0<S>&v){bt.QU(v.WM(),FF(T{}));Wu(WO(),v);R WO();}B Z WO()Q{R bt.WO();}M<o E>B Y Qs(E L)Q{R L(WO().E9());}B Y Qs()Q{R WO().E9();}M<o...W2>B Y E8(W2&&...E1)Q{R WO().E8(Ef<W2>(E1)...);}M<o...W2>B Y Ey(W2&&...E1)Q{R WO().Ey(Ef<W2>(E1)...);}M<o...W2>B Y QS(W2&&...E1)Q{R WO().QS(Ef<W2>(E1)...);}B w WM()Q{R bt.WM();}};M<o X,o T,o Z,o Wg>W9 Wf:WE Z{QQ:B W3 P Q5(T&x,Q T&lc,Q T&rc,Q Wg&op){WD<Wg,T>::f(x,lc,rc,op);}P Wm(X p,Q Wg&op){if(d->Wt()){op.apply_to(E9(),p);R;}if(QM().Ep().Qo(p)){d->Qm(QM().QL());QM().Wm(p,op);}Er{d->Qn(WQ().QL());WQ().Wm(p,op);}Q5(E9(),QM().E9(),WQ().E9(),op);}WE:B W3 Y Qw(Q T&x,Q T&y){R Qc(x,y);}B W3 Y WL(){R Ei;}Wf(Q Z&A):Z(A){} P Qi(){} WC E3 Qz()Q{R Wc;}B Wf QM()Q{Wf it(*d);it.Wv();R it;}B Wf WQ()Q{Wf it(*d);it.QH();R it;}B T&E9(){R**d;}B Q T&E9()Q{R**d;}M<o E>B Y Qs(E L)Q{R L(E9());}B Y Qs()Q{R E9();}M<o S,o E,o QW>B Y E8(X l,X r,Q S&W_,E L,QW a)Q{QA<X>i{l,r};if(l<r and W8 i.Qe(d->Ep())){R Q3(*d,i,L,a);}Er{R W_;}} B Y E8(X l,X r)Q{R E8(l,r,Ei,_,Qw);}M<o QG,o S,o E,o QW>B Y Ey(X l,QG W,Q S&W_,E L,QW a)Q{R Wp(*d,l,W_,W,L,a);}M<o QG>B Y Ey(X l,QG W)Q{R Wp(*d,l,Ei,W,_,Qw);}M<o QG,o S,o E,o QW>B Y QS(X r,QG W,Q S&W_,E L,QW a)Q{R Wj(*d,r,W_,W,L,a);}M<o QG>B Y QS(X r,QG W)Q{R Wj(*d,r,Ei,W,_,Qw);}B Y We(X p,Q Wg&op){Wf it(*d);it.QL();it.Wm(p,op);R it;}};M<o X,o T,M<o,o>o W4,o Wg>W9 strict_range_tree:WE Qx<X,T,W4<X,T>,Wf<X,T,o W4<X,T>Qg,Wg>>{WE:Wo WZ=Wf<X,T,o W4<X,T>Qg,Wg>;B WZ We(X p,Q Wg&op){R d->WO().We(p,op);}};M<o X,o T,M<o,o>o W4,o Wg>Y make_strict_range_tree(){R strict_range_tree<X,T,W4,Wg>();}M<o X,o T,o Z,o Wg>W9 Qj:WE Z{QQ:B W3 P Q5(T&x,Q T&lc,Q T&rc,Q Wg&op){WD<Wg,T>::f(x,lc,rc,op);}P Wm(X p,Q Wg&op){if(d->Wt()){op.apply_to(E9(),p,p+1);R;}if((*d)->Qz()and d->Wh()){if(QM().Ep().Qo(p)){d->Qm(QM().QL());QM().Wm(p,op);}Er{d->Qn(WQ().QL());WQ().Wm(p,op);}} Er{Qi();if(QM().Ep().Qo(p)){QM().Wm(p,op);}Er{WQ().Wm(p,op);}} Q5(E9(),QM().E9(),WQ().E9(),op);}P Qa(QA<X>i,Q Wg&op){if(i.Qo(d->Ep())){(*d)->Eu(op.restrict(d->QR(),d->E5(),i.l,i.r),d->QR(),d->E5());R;}if(Qz()and d->Wh()){if(W8 i.Qe(QM().Ep())){d->Qm(QM().QL());QM().Qa(i,op);}if(W8 i.Qe(WQ().Ep())){d->Qn(WQ().QL());WQ().Qa(i,op);}} Er{Qi();if(W8 i.Qe(QM().Ep())){QM().Qa(i,op);}if(W8 i.Qe(WQ().Ep())){WQ().Qa(i,op);}} d->Q5(E9(),QM().E9(),WQ().E9(),op);}WE:B W3 Y Qw(Q T&x,Q T&y){R Qc(x,y);}B W3 Y WL(){R Ei;}Qj(Q Z&A):Z(A){} P Qi(){if(Qz()){R;}X l=d->QR(),r=d->E5();X m=(l+r)/2;d->Qm(QM().QL());d->Qn(WQ().QL());QM()->Eu((*d)->Wi().restrict(l,m,l,r),l,m);WQ()->Eu((*d)->Wi().restrict(m,r,l,r),m,r);(*d)->delete_operation();}B E3 Qz()Q{R(*d)->Qz();}B Qj QM()Q{Qj it(*d);it.Wv();R it;}B Qj WQ()Q{Qj it(*d);it.QH();R it;}B T&E9(){R(*d)->Eo;}B Q T&E9()Q{R(*d)->Eo;}M<o E>B Y Qs(E L)Q{R L(E9());}B Y Qs()Q{R E9();}M<o S,o E,o QW>B Y E8(X l,X r,Q S&W_,E L,QW a)Q{QA<X>i{l,r};if(l<r and W8 i.Qe(d->Ep())){R Q3(*d,i,L,a);}Er{R W_;}} B Y E8(X l,X r)Q{R E8(l,r,Ei,_,Qw);}M<o QG,o S,o E,o QW>B Y Ey(X l,QG W,Q S&W_,E L,QW a)Q{R Wp(*d,l,W_,W,L,a);}M<o QG>B Y Ey(X l,QG W)Q{R Wp(*d,l,Ei,W,_,Qw);}M<o QG,o S,o E,o QW>B Y QS(X r,QG W,Q S&W_,E L,QW a)Q{R Wj(*d,r,W_,W,L,a);}M<o QG>B Y QS(X r,QG W)Q{R Wj(*d,r,Ei,W,_,Qw);}B Y We(X p,Q Wg&op){Qj it(*d);it.QL();it.Wm(p,op);R it;}B Y range_update(X l,X r,Q Wg&op){Qj it(*d);QA<X>i{l,r};if(l<r and W8 i.Qe(d->Ep())){it.QL();it.Qa(i,op);}R it;}};M<o X,o T,o Wg>W9 WF{QQ:E3 Wq;Wg op;WE:T Eo;explicit WF(Q T&val_=T()):Wq(WY),Eo(val_){} B E3 Qz()Q{R W8 Wq;}P Eu(Q Wg&new_op,X l,X r){if(Qz()){op=new_op;Wq=Wc;}Er{op.append(new_op);}new_op.apply_to(Eo,l,r);}B Q Wg&Wi()Q{R op;}P delete_operation(){Wq=WY;}};M<o X,o T,M<o,o>o W4,o Wg>W9 lazy_range_tree:WE Qx<X,T,W4<X,WF<X,T,Wg>>,Qj<X,T,o W4<X,WF<X,T,Wg>>Qg,Wg>>{WE:Wo Q2=WF<X,T,Wg>;Wo WZ=Qj<X,T,o W4<X,Q2>Qg,Wg>;M<o Gen>B WZ QU(X n,Gen gen){if WC(Es<Gen,T>){d->bt.QU(n,FC(Q2(gen),gen));}Er{d->bt.QU(n,FC(Q2(gen()),gen));}R d->WO();}M<o I,o Operation0=Wg,o=WX<WJ<I>>>B WZ QU(Q I&v){R QU(v>QT);}M<o S>WZ QU(Q E0<S>&v){d->bt.QU(v.WM(),FF(Q2(T{})));d->Wu(d->WO(),v);R d->WO();}B WZ We(X p,Q Wg&op){R d->WO().We(p,op);}B WZ range_update(X l,X r,Q Wg&op){R d->WO().range_update(l,r,op);}};M<o X,o T,M<o,o>o W4,o Wg,o...W2>Y make_lazy_range_tree(){R lazy_range_tree<X,T,W4,Wg>();}M<o...Is>W9 WT{QQ:QV<Is...>Qh;WE:WT(Q Is&...its_):Qh(its_...){} B Y QL(){Ee([&](Y&&...xs){(xs.QL(),...);},Qh);R*d;}B P Qi(){Ee([&](Y&&...xs){(xs.Qi(),...);},Qh);}B E3 Qz()Q{R Ee([&](Y&&...xs){R(xs.Qz()&&...);},Qh);}B E3 Wh()Q{R Ee([&](Y&&...xs){R(xs.Qz()||...);},Qh);}B P Qm(Q WT&it){Ee([&](Y&&...xs){(QX<xs>(Qh).Qm(QX<xs>(it)),...);},Ej<Is...>{});}B P Qn(Q WT&it){Ee([&](Y&&...xs){(QX<xs>(Qh).Qm(QX<xs>(it)),...);},Ej<Is...>{});}B P Wv(){Ee([&](Y&&...xs){(xs.Wv(),...);},Qh);}B P QH(){Ee([&](Y&&...xs){(xs.QH(),...);},Qh);}B WT QM()Q{Y it=*d;it.Wv();R it;}B WT WQ()Q{Y it=*d;it.QH();R it;}B E3 Wt()Q{R QX<0>(Qh).Wt();}B O(Y)z*()Q{R Ee([&](Y&&...xs){R std::forward_as_tuple(xs.E9()...);},Qh);}B O(Y)E9()Q{R**d;}B Y Ep()Q{R QX<0>(Qh).Ep();}B Y QR()Q{R QX<0>(Qh).QR();}B Y E5()Q{R QX<0>(Qh).E5();}Wo T=QV<W5<O(*QP<Is>())>...>;Wo X=W5<O(QX<0>(Qh).QR())>;B W3 Y Qw(Q T&x,Q T&y){R Ee([&](Y&&...xs){R QV(Is::merge(QX<xs>(x),QX<xs>(y))...);},Ej<Is...>{});}B W3 Y WL(){R QV(Is::identity()...);}M<o E>B Y Qs(E L)Q{R L(E9());}B Y Qs()Q{R E9();}M<o S,o E,o QW>B Y E8(X l,X r,Q S&W_,E L,QW a)Q{QA<X>i{l,r};if(l<r and W8 i.Qe(d->Ep())){R Q3(*d,i,L,a);}Er{R W_;}} B Y E8(X l,X r)Q{R E8(l,r,WL,_,Qw);}M<o QG,o S,o E,o QW>B Y Ey(X l,QG W,Q S&W_,E L,QW a)Q{R Wp(*d,l,W_,W,L,a);}M<o QG>B Y Ey(X l,QG W)Q{R Wp(*d,l,WL,W,_,Qw);}M<o QG,o S,o E,o QW>B Y QS(X r,QG W,Q S&W_,E L,QW a)Q{R Wj(*d,r,W_,W,L,a);}M<o QG>B Y QS(X r,QG W)Q{R Wj(*d,r,WL,W,_,Qw);}};M<o...Is>Y zip_range_trees(Q Is&...iterators){R WT<Is...>(iterators...);}W6 Val{W0 sm,mn,mx;};BEGIN W0 N;string S;cin>>N>>S;W0 cursor=0;Y rt=make_fast_range_tree<Val>(Val{0,0,0},FF(x,y,(Val{x.sm+y.sm,min(x.mn,x.sm+y.mn),max(x.mx,x.sm+y.mx)})));rt.QU(N,Val{0,0,0});QF(char c:S){if(c== 'L'){cursor=max(0,cursor-1);}Er if(c== 'R'){cursor++;}Er{W0 v=(c== '(')-(c== ')');rt.We(cursor,Val{v,v,v});}Y q=rt.Qs();if(q.sm!=0 or q.mn<0){cout<< "-1 ";}Er{cout<<q.mx<< " ";}} cout<< "\n";END