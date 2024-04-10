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
#include<tuple>
#define Qz iterable_wrapper
#define Ql jv_ptr
#define Ey std::declval
#define QL lazy_range_tree_iterator
#define z operator
#define Q_ persistent_binary_tree
#define QM ostream_tuple_helper_
#define WO __tuple__
#define WZ internal_build
#define QP std::enable_if_t
#define QN Args
#define Qh vertex
#define WN has_children
#define Qg mutable
#define d iterator
#define QA val
#define Q7 apply
#define Qf query_id
#define Qy class
#define QY it_end
#define QJ total
#define Et k_ptr
#define E6 find_first_after
#define Eu private
#define QC std::index_sequence
#define WY container_carrying_iterator
#define Qb max_pow2
#define WP using
#define Wv nested_vector_at
#define E8 std::begin
#define Qq iterator_macro
#define WR __arg1__
#define QX interval
#define Qa std::end
#define L Pred
#define Q8 std::make_index_sequence
#define WE step
#define Wh template_for_iterable
#define Qu find_last_before
#define q query_f
#define M QueryF
#define Q3 range_tree_find_last_before_impl
#define WQ j_end
#define Wm internal_point_update
#define Er contains
#define Ee full_merge
#define Qm advance
#define Wn implicit_lambda_unary_operator
#define Ew left_index
#define Eq push_back
#define W4 to_nested_vector_impl
#define Qp std::index_sequence_for
#define Y Idx
#define E9 QueryMerge
#define Qj nested_vector_impl
#define QV modify
#define Wc is_end
#define Wz new_vertex
#define E7 constexpr
#define Wl tuple_tail
#define Qc range_tree_range_query
#define R query_merge
#define Q Iterator
#define Wk range
#define E2 tuple_many_of_t
#define A size_t
#define Wj tree
#define WW std::make_signed_t
#define WM right_child
#define Wa base_range_tree
#define Qi std::invoke_result_t
#define Wg cartesian_product
#define W1 ::iterator
#define WJ args
#define E4 tuple_head
#define Qo std::forward
#define Wf range_update
#define Wd sparse_binary_tree
#define Q1 right_half
#define WC get_interval
#define Qe std::ostream
#define E3 else
#define Ws pending_operation
#define H inline
#define WU std::shared_ptr
#define Q6 fast_range_tree
#define Wo has_updated
#define Wu tuple_many_of
#define Wi internal_range_update
#define QF _range_tree_full_merge_impl
#define QS contiguous_binary_tree
#define w this
#define E1 not
#define W8 is_leaf
#define Qd std::remove_reference_t
#define W_ get_operation
#define a other
#define E5 disjoint
#define QI all_different_
#define QW is_composable_v
#define B auto
#define Q9 go_left
#define QZ BinaryTree
#define Qr go_right
#define P typename
#define Wt correct_iterator_t
#define WB std::apply
#define WV public
#define QD left_half
#define We implicit_lambda_binary_operator
#define W3 set_right_child
#define Qn lazy_range_tree_vertex
#define QE accum_unordered_map_by_
#define WX bool
#define Ei true
#define Ww Operation::identity
#define QB propagate
#define Wq full_query
#define Q2 get_val
#define QU merge
#define E return
#define W void
#define Qw has_advanced
#define WL std::get
#define QH range_tree_find_first_after_impl
#define WD struct
#define W0 false
#define QR nested_vector_size
#define X const
#define W9 size
#define QG get_root
#define o pred
#define WK set_left_child
#define Wy point_update
#define W7 cartesian_product_range
#define Qs std::decay_t
#define WH template_for_iterable_3
#define Q5 static
#define Qk std::tuple
#define WI range_tree_find_first_after
#define W6 apply_operation
#define O decltype
#define W5 __arg3__
#define Wr range_tree_find_last_before
#define QQ implicit_lambda
#define Wb tree_ptr
#define QT Operation::merge
#define QK zipped_range_tree_iterator
#define Wx def_iterable_ostream
#define W2 left_child
#define Qt is_composable
#define Wp to_vector
#define WG def_iterator_manip_iter
#define N Operation
#define WF is_iterable_v
#define Q4 build
#define Q0 is_composable_
#define E0 right_index
#define WS identity
#define QO strict_range_tree_iterator
#define Qv std::vector
#define WA __arg2__
#define Z template
#define WT range_query
#define Qx __expr1__
Z<P T,A>WP ignore_second=T;Z<A...Ix,P T>B tuple_many_of_impl(QC<Ix...>,X T&x){E Qk(ignore_second<T,Ix>(x)...);}Z<A n,P T>B Wu(X T&x){E tuple_many_of_impl(Q8<n>{},x);}Z<A n,P T>WP E2=O(Wu<n,T>(Ey<T>()));Z<P...QN>B E4(X Qk<QN...>&t){E WL<0>(t);}Z<A...Ix,P...QN>B tuple_tail_impl(QC<Ix...>,X Qk<QN...>&t){E Qk(WL<Ix+1>(t)...);}Z<P...QN>B Wl(X Qk<QN...>&t){E tuple_tail_impl(Q8<sizeof...(QN)-1>{},t);}Z<P T1,P T2>std::common_type_t<T1,T2>maxx(X T1&x,X T2&y){if(x<y){E y;}E3{E x;}} Z<P T1,P T2,P...Ts>H B maxx(X T1&x,X T2&y,X Ts&...xs){E maxx(maxx(x,y),xs...);}Z<P T1,P T2>B minn(X T1&x,X T2&y){if(x<=y){E x;}E3{E y;}} Z<P T1,P T2,P...Ts>H B minn(X T1&x,X T2&y,X Ts&...xs){E minn(minn(x,y),xs...);}E7 int _log2(int x){if(x==0){E 0;}E 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&]()->O(B){E(f);}
#define FF_1(WR,f)[&](B&&WR)->O(B){(W)WR;E(f);}
#define FF_2(WR,WA,f)[&](B&&WR,B&&WA)->O(B){(W)WR;(W)WA;E(f);}
#define FF_macro_chooser(...)GET_4TH_ARG(__VA_ARGS__,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c]()->O(B){E(f);}
#define FC_1(WR,f,c)[&,c](B&&WR)->O(B){(W)WR;E(f);}
#define FC_2(WR,WA,f,c)[&,c](B&&WR,B&&WA)->O(B){(W)WR;(W)WA;E(f);}
#define FC_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2]()->O(B){E(f);}
#define FC2_1(WR,f,c1,c2)[&,c1,c2](B&&_)->O(B){(W)WR;E(f);}
#define FC2_2(WR,WA,f,c1,c2)[&,c1,c2](B&&WR,B&&WA)->O(B){(W)WR;(W)WA;E(f);}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(WR,f)[&](B&&WO)->O(B){B&[WR]=WO;(W)WR;E(f);}
#define FT_2(WR,WA,f)[&](B&&WO)->O(B){B&[WR,WA]=WO;(W)WR;(W)WA;E(f);}
#define FT_3(WR,WA,W5,f)[&](B&&WO)->O(B){B&[WR,WA,W5]=WO;(W)WR;(W)WA;(W)W5;E(f);}
#define FT_4(WR,WA,W5,__arg4__,f)[&](B&&WO)->O(B){B&[WR,WA,W5,__arg4__]=WO;(W)WR;(W)WA;(W)W5;(W)__arg4__;E(f);}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Qx,f)[&](){B&&Qx;E f;}()
#define LET_2(Qx,__expr2__,f)[&](){B&&Qx;B&&__expr2__;E f;}()
#define LET_3(Qx,__expr2__,__expr3__,f)[&](){B&&Qx;B&&__expr2__;B&&__expr3__;E f;}()
#define LET_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
Z<P F>Qy QQ{Eu:F f;WV:QQ(F f_):f(f_){} Z<P...Ts>E7 O(B)z()(Ts&&...xs)X{E f(Qo<Ts>(xs)...);}};QQ _(FF(x,x));QQ _1(FF(x,y,x));QQ _2(FF(x,y,y));
#define implicit_lambda_unary_operator(op)Z<P F>E7 O(B)z op(QQ<F>f){E QQ([=](B&&...xs){E op f(Qo<O(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)Z<P F,P T>E7 O(B)z op(QQ<F>f,X T&y){E QQ([=](B&&...xs){E f(Qo<O(xs)>(xs)...)op y;});}Z<P F,P T>E7 O(B)z op(X T&y,QQ<F>f){E QQ([=](B&&...xs){E y op f(Qo<O(xs)>(xs)...);});}Z<P F,P G>E7 O(B)z op(QQ<F>f,QQ<G>g){E QQ([=](B&&...xs){E f(Qo<O(xs)>(xs)...)op g(Qo<O(xs)>(xs)...);});}
Wn(+)Wn(-)Wn(!)Wn(~)Wn(*)Wn(&)We(+)We(-)We(*)We(/)We(%)We(<)We(>)We(<=)We(>=)We(==)We(!=)We(<<)We(>>)We(&)We(|)We(^)We(&&)
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define template_for_iterable_3(T,I,V)Z<P T,P I=Wt<T>,P V=P Qs<T>::value_type>
#define template_for_iterable_2(T,I)WH(T,I,)
#define template_for_iterable_1(T)template_for_iterable_2(T,I)
#define template_for_iterable_macro_chooser(...)GET_4TH_ARG(__VA_ARGS__,WH,template_for_iterable_2,template_for_iterable_1)
#define template_for_iterable(...)template_for_iterable_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define iterator_macro(extra,neq,incr,QA)WD Q{extra WX z!=(X Q&a)X{(W)a;E neq;}W z++()incr O(B)z*()X{E QA;}};
#define def_iterator_manip_iter(name,templ,WJ,args_,extra,it_begin,QY,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,WJ,args_,extra,{Qq(extra extra_it Qg I it;,neq_it,incr_it,val_it);E Qz(it_begin,QY);})
#define def_iterator_manip_2(name,code)E7 WD{WP Q0=W;Wh(T,I,V)O(B)z()(X T&v)X code Wh(T,I,V)O(B)z()(T&v)X code}name;
#define def_iterator_manip_6(name,templ,WJ,args_,extra,code)templ WD name##_impl{WP Q0=W;extra Wh(T,I,V)O(B)z()(X T&v)X code Wh(T,I,V)O(B)z()(T&v)X code};templ H O(B)name WJ{E name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,WJ,code)E7 WD{WP Q0=W;templ O(B)z()WJ X code}name;
Z<P T,P=W>WD is_iterable:WV std::false_type{};Z<P T>WD is_iterable<T,std::void_t<O(E8(Ey<T>())),O(Qa(Ey<T>()))>>:WV std::true_type{};Z<P T>E7 WX WF=is_iterable<T>::value;Z<P T,P=W>WD Qt:WV std::false_type{};Z<P T>WD Qt<T,std::void_t<P T::is_composable_>>:WV std::true_type{};Z<P T>E7 WX QW=Qt<T>::value;Z<P T,P=QP<WF<T>>>WD correct_iterator{WP type=std::conditional_t<std::is_const_v<Qd<T>>,P Qd<T>::const_iterator,P Qd<T>W1>;};Z<P T>WP Wt=P correct_iterator<T>::type;Z<P I>H B Qz(X I&b,X I&e){WD Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
WP is_iterable_wrapper=W;WP d=I;WP const_iterator=I;WP value_type=Qs<O(*Ey<I>())>;
#pragma GCC diagnostic pop
I b,e;B begin()X{E b;}B end()X{E e;}};E Wrapper{b,e};}Wh(T)H B iter(T&&iterable){E Qz(E8(iterable),Qa(iterable));}Z<P C>WD WY:WV C::iterator{WU<C>p;WY(WU<C>p_,P C::iterator it):C::iterator(it),p(p_){}};Z<P C>H B iterc(C&&v){WP D=Qs<C>;WU<D>p(new D(Qo<C>(v)));E Qz(WY<D>{p,E8(*p)},WY<D>{p,Qa(*p)});}Z<P T>H B iter(std::initializer_list<T>l){E iterc(Qv<T>(l));}Z<P T,P F,P=Qi<F,T>>O(B)z>(T&&v,X F&f){E f(Qo<T>(v));}Z<P M1,P M2>WD composed{WP Q0=W;X M1 m1;X M2 m2;Z<P T>O(B)z()(T&&v)X{E m1(m2(Qo<T>(v)));}};Z<P M1,P M2,P=QP<QW<M1>or QW<M2>>>H B z<(X M1&m1,X M2&m2){E composed<M1,M2>{m1,m2};} 
#define to_container_macro(T,ins)def_iterator_manip(to_##T,{std::T<V>s;for(B&&x:v){s.ins(Qo<O(x)>(x));}E s;})
to_container_macro(vector,Eq)to_container_macro(set,insert)to_container_macro(unordered_set,insert)Z<A n>WD W4{Wh(T)H Q5 B make(T&&v){E Qo<T>(v)>Q7(FF(u,W4<n-1>::make(u)))>Wp;}Wh(T)H Q5 B make(X T&v){E Qo<T>(v)>Q7(FF(u,W4<n-1>::make(u)))>Wp;}};Z<>WD W4<1>{Wh(T)H Q5 B make(T&&v){E Qo<T>(v)>Wp;}Wh(T)H Q5 B make(X T&v){E Qo<T>(v)>Wp;}};Z<A n>WD to_nested_vector_{WP Q0=W;Wh(T)H O(B)z()(T&&v)X{E W4<n>::make(Qo<T>(v));}};Z<A n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(A l,A r),({l,r}),A l;A r;,{E Qz(E8(v)+l,E8(v)+r);})def_iterator_manip(is_nil,{E E1(E8(v)!=Qa(v));});def_iterator_manip(length,{A l=0;for(B&i:v){++l;}E l;});
#pragma GCC diagnostic ignored "-Wnarrowing"
Z<P T1,P T2,P T3,P T=WW<O(T1()+T2()+T3())>>H B Wk(X T1&b,X T2&e,X T3&WE){Qq(T x;T e;T WE;WX Wc()X{E(WE>=T(0)and x>=e)or(WE<T(0)and x<=e);},Wc()xor a.Wc(),{x+=WE;},T(x))E Qz(Q{b,e,WE},Q{e,e,WE});}Z<P T1,P T2>H B Wk(X T1&b,X T2&e){E Wk(b,e,1);}Z<P T>H B Wk(X T&e){E Wk(T(),e,1);} 
#pragma GCC diagnostic pop
Z<P T>H B to_infinity(X T&b=T(),X T&WE=1){Qq(T x;T WE;,Ei,{x+=WE;},T(x))E Qz(Q{b,WE},Q{b,WE});}WG(Q7,Z<P F>,(F f),<F>{f},F f;,(Q{f,E8(v)}),(Q{f,Qa(v)}),,it!=a.it,{++it;},f(*it))WG(take,,(A n),{n},A n;,(Q{n,E8(v)}),(Q{0,Qa(v)}),,n!=a.n,{--n;if(n>0){++it;}},*it)WG(take_while,Z<P F>,(F f),<F>{f},F f;,(Q{f,E1(E8(v)!=Qa(v)and f(*E8(v))),E8(v)}),(Q{f,Ei,Qa(v)}),WX Wc;,Wc xor a.Wc,{++it;if(E1 f(*it)){Wc=Ei;}},*it)WG(drop,,(A n),{n},Qg A n;,(Q{n,Qa(v),E8(v)}),(Q{0,Qa(v),Qa(v)}),X I end_it;H W Qm()X{while(n>0){if(E1(it!=end_it)){n=0;break;}--n;++it;}},(Qm(),a.Qm(),it!=a.it),{Qm();++it;},(Qm(),*it))WG(drop_while,Z<P F>,(F f),<F>{f},F f;,(Q{f,Qa(v),W0,E8(v)}),(Q{f,Qa(v),Ei,Qa(v)}),X I end_it;Qg WX Qw;H W Qm()X{if(E1 Qw){while(it!=end_it and f(*it)){++it;}Qw=Ei;}},(Qm(),a.Qm(),it!=a.it),{Qm();++it;},(Qm(),*it))def_iterator_manip(head,{E*E8(v);})H B tail=drop(1);H B at(A n){E head<drop(n);}WG(cons,Z<P S>,(S s),<S>{s},S s;,(Q{s,Ei,E8(v)}),(Q{s,W0,Qa(v)}),WX is_s;,is_s!=a.is_s or it!=a.it,{if(is_s){is_s=W0;}E3{++it;}},(is_s)?(s):(*it))def_iterator_manip(snoc,{B it=E8(v);B h=*it;++it;E Qk(h,Qz(it,Qa(v)));})def_iterator_manip(split_at,,(A n),{n},A n;,{B it=E8(v);Qv<T>u;for(B i:Wk(n)){u.Eq(*it);++it;}E Qk(iterc(std::move(u)),Qz(it,Qa(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
WG(chunks_of,,(A n),{n},A n;,(Q{n,{},W0,Qa(v),E8(v)}),(Q{n,{},W0,Qa(v),Qa(v)}),Qg Qv<V>u;Qg WX Wo;I QY;W update()X{u.clear();Wo=Ei;for(B i:Wk(n)){if(it!=QY){u.Eq(*it);++it;}E3{break;}}},it!=a.it,{if(Wo){Wo=W0;}E3{for(B i:Wk(n)){if(it!=QY){++it;}E3{break;}}}},(Wo)?(iterc(u)):(update(),iterc(u))) 
#pragma GCC diagnostic pop
Z<P F,P S>WD fold_impl{WP Q0=W;F f;S s;Wh(T)O(B)z()(X T&v)X{B x=s;for(B y:v){x=f(x,y);}E x;}};Z<P F,P S>H B fold(F f,X S&s){E fold_impl<F,S>{f,s};}def_iterator_manip(fold1,Z<P F>,(F f),<F>{f},F f;,{B u=v>snoc;E WL<1>(u)>fold(f,WL<0>(u));})def_iterator_manip(sum,{E v>fold(std::plus<V>(),V());})def_iterator_manip(product,{E v>fold(std::multiplies<V>(),V(1));})def_iterator_manip(maximum_by,Z<P F>,(F f),<F>{f},F f;,{E v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{E v>maximum_by(std::less<V>());})def_iterator_manip(maximum_on,Z<P F>,(F f),<F>{f},F f;,{E v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,Z<P F>,(F f),<F>{f},F f;,{E v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{E v>minimum_by(std::less<V>());})def_iterator_manip(minimum_on,Z<P F>,(F f),<F>{f},F f;,{E v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})Z<P F,P S>WD scan_impl{WP Q0=W;F f;S s;Wh(T,I)O(B)z()(X T&v)X{Qq(F f;Qg S s;Qg WX Wo;WX Qw;Qg I it;,it!=a.it,{if(E1 Wo){s=f(s,*it);};Wo=W0;if(Qw){++it;}E3{Qw=Ei;}},(Wo)?(s):(Wo=Ei,s=f(s,*it)))E Qz(Q{f,s,Ei,W0,E8(v)},Q{f,s,Ei,Ei,Qa(v)});}Wh(T,I)O(B)z()(T&v)X{Qq(F f;Qg S s;Qg WX Wo;WX Qw;Qg I it;,it!=a.it,{if(E1 Wo){s=f(s,*it);};Wo=W0;if(Qw){++it;}E3{Qw=Ei;}},(Wo)?(s):(Wo=Ei,s=f(s,*it)))E Qz(Q{f,s,Ei,W0,E8(v)},Q{f,s,Ei,Ei,Qa(v)});}};Z<P F,P S>H B scan(F f,X S&s){E scan_impl<F,S>{f,s};}WG(scan1,Z<P F>,(F f),<F>{f},F f;,(Q{f,*E8(v),Ei,E8(v)}),(Q{f,*E8(v),Ei,Qa(v)}),Qg V s;Qg WX Wo;,it!=a.it,{if(E1 Wo){s=f(s,*it);};Wo=W0;++it;},(Wo)?(s):(Wo=Ei,s=f(s,*it)))Z<P T,P S,P I=Wt<T>,P J=Wt<S>>H B z+(T&&v,S&&u){Qq(I i;I i_end;J j;WX in_i;,i!=a.i or j!=a.j,{if(in_i){++i;if(E1(i!=i_end)){in_i=W0;}}E3{++j;}},(in_i)?(*i):(*j))I bv=E8(v);I ev=Qa(v);J bu=E8(u);J eu=Qa(u);E Qz(Q{bv,ev,bu,bv!=ev},Q{ev,ev,eu,W0});}E7 WD{WP Q0=W;Wh(T)B z()(T&&v)X{B u=Qo<T>(v)>filter(FF(i,E1 is_nil(i)));B b=E8(u);B e=Qa(u);WP J=O(b);WP V=Qs<O(*b)>;WP K=O(E8(*b));WD Q{J j;J WQ;WU<V>Ql;K*Et;WX Wc;Q(J j,J WQ,X V&jv,WX Wc):j(j),WQ(WQ),Ql(new V(jv)),Et(new K(E8(*Ql))),Wc(Wc){} Q(J j,J WQ,WX Wc):j(j),WQ(WQ),Ql(nullptr),Et(nullptr),Wc(Wc){} Q(X Q&a):j(a.j),WQ(a.WQ),Ql(a.Ql),Et((a.Et)?(new K(*a.Et)):nullptr),Wc(a.Wc){} Q(Q&&a):j(a.j),WQ(a.WQ),Ql(a.Ql),Et((a.Et)?(new K(*a.Et)):nullptr),Wc(a.Wc){}~Q(){delete Et;}WX z!=(X Q&a)X{E Wc xor a.Wc;}W z++(){++*Et;if(E1(*Et!=Qa(*Ql))){++j;if(j!=WQ){delete Et;Ql=std::make_shared<V>(*j);Et=new K(E8(*Ql));}E3{Wc=Ei;}}}O(B)z*()X{E**Et;}};if(u>is_nil){E Qz(Q(b,e,Ei),Q(b,e,Ei));}E3{E Qz(Q(b,e,*b,W0),Q(e,e,Ei));}}}flatten;Z<P T,P F,P=QP<WF<T>>>B z>=(X T&v,F f){E v>Q7(f)>flatten;}Z<P U,A i,A s>WX QI(X U&x,X U&y){if E7(i<s){E WL<i>(x)!=WL<i>(y)and QI<U,i+1,s>(x,y);}E3{E Ei;}} Z<P U,A i,A s>W incr_all_(U&u){if E7(i<s){++WL<i>(u);incr_all_<U,i+1,s>(u);}} Z<P F,P...QN,A...Seq>O(B)call_f_(F f,X Qk<QN...>&u,QC<Seq...>){E f(*WL<Seq>(u)...);}Z<P F,P...Ts>H B zip_with(F f,Ts&&...vs){Qq(F f;Qk<Wt<Ts>...>its;,(QI<O(its),0,sizeof...(Ts)>(its,a.its)),{(incr_all_<O(its),0,sizeof...(Ts)>(its));},call_f_(f,its,Qp<Ts...>{}))E Qz(Q{f,Qk<Wt<Ts>...>(E8(vs)...)},Q{f,Qk<Wt<Ts>...>(Qa(vs)...)});}WD zip_default_function_{Z<P...Ts>O(B)z()(Ts&&...xs)X{E Qk<Ts...>(xs...);}};Z<P...Ts>H B zip(Ts&&...vs){E zip_with(zip_default_function_{},Qo<Ts>(vs)...);}WG(filter,Z<P F>,(F f),<F>{f},F f;,(Q{f,Qa(v),E8(v)}),(Q{f,Qa(v),Qa(v)}),X I end_it;H W Qm()X{while(it!=end_it and E1 f(*it)){++it;}},(Qm(),a.Qm(),it!=a.it),{Qm();++it;},(Qm(),*it))def_template_lambda(Z<P T>,repeat,(T&&v),{WD Q{X Qs<T>v;WX z!=(X Q&)X{E Ei;}W z++(){} X B&z*()X{E v;}};E Qz(Q{v},Q{v});})H B replicate(A n){E take(n)<repeat;}H B cycle=flatten<repeat;def_iterator_manip(enumerate,{E zip(to_infinity(A(0)),v);})def_iterator_manip(reversed,{B s=v>Wp;std::reverse(s.begin(),s.end());E iterc(std::move(s));})def_iterator_manip(sorted_by,Z<P F>,(F f),<F>{f},F f;,{B s=v>Wp;std::sort(E8(s),Qa(s),f);E iterc(std::move(s));})def_iterator_manip(sorted,{E v>sorted_by(std::less<V>());})def_iterator_manip(sorted_on,Z<P F>,(F f),<F>{f},F f;,{E v>Q7(FF(i,Qk(i,f(i))))>sorted_by(FF(x,y,WL<1>(x)<WL<1>(y)))>Q7(FF(i,WL<0>(i)));})def_iterator_manip(nub,{Qq(I QY;I it;,it!=a.it,{O(*it)pr;do{pr=*it;++it;}while(it!=QY and pr==*it);},*it)B b=E8(v);B e=Qa(v);E Qz(Q{e,b},Q{e,e});})Z<P F,P S>WD accum_vector_by_{WP Q0=W;A n;F f;S s;Wh(T,I,V)O(B)z()(X T&v)X{Qv<Qs<Qi<F,S,O(WL<1>(Ey<V>()))>>>u(n,s);for(B&&[i,x]:v){u[i]=f(u[i],x);}E u;}};Z<P F,P S>H B accum_vector_by(A n,F f,X S&s){E accum_vector_by_<F,S>{n,f,s};}Z<P S>H B accum_vector(A n,X S&s=S()){E accum_vector_by(n,_2,s);}Z<P F,P S>WD accum_map_by_{WP Q0=W;F f;S s;Wh(T,I,V)O(B)z()(X T&v)X{std::map<Qs<O(WL<0>(Ey<V>()))>,Qs<Qi<F,S,O(WL<1>(Ey<V>()))>>>u;for(B&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}E3{u[i]=f(s,x);}} E u;}};Z<P F,P S>H B accum_map_by(F f,X S&s){E accum_map_by_<F,S>{f,s};}Z<P S>H B accum_map(X S&s=S()){E accum_map_by(_2,s);}Z<P F,P S>WD QE{WP Q0=W;F f;S s;Wh(T,I,V)O(B)z()(X T&v)X{std::unordered_map<Qs<O(WL<0>(Ey<V>()))>,Qs<Qi<F,S,O(WL<1>(Ey<V>()))>>>u;for(B&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}E3{u[i]=f(s,x);}} E u;}};Z<P F,P S>H B accum_unordered_map_by(F f,X S&s){E QE<F,S>{f,s};}Z<P S>H B accum_unordered_map(X S&s=S()){E accum_unordered_map_by(_2,s);}Z<P I>B Wg(X I&v){E v>Q7(FF(x,Qk(x)));}Z<P I,P...Is>B Wg(X I&v,X Is&...vs){B p=Wg(vs...);E v>=FC(x,p>Q7(FC(t,std::tuple_cat(Qk(x),t),x)),p);}Z<P...Ts>B W7(X Ts&...n){E Wg(Wk(n)...);}Z<A n,P I>B cartesian_power(X I&v){E WB([](X B&...vs){E Wg(vs...);},Wu<n>(v));}Z<P T>H B istream_iterable(std::istream&in){Qq(std::istream&in;Qg T QA;WX Wc;Qg WX has_read;,Wc xor a.Wc,{if(E1(in>>QA)){Wc=Ei;}},(has_read)?(QA):(has_read=Ei,in>>QA,QA))E Qz(Q{in,T{},W0,W0},Q{in,T{},Ei,Ei});}Z<P T>H B input=istream_iterable<T>(std::cin);Z<P T>Qe&print_iterable(Qe&out,X T&v,X std::string&sep= " "){for(B it=E8(v);it!=Qa(v);){ out<<*it;++it;if(it!=Qa(v)){out<<sep;}E3{E out;}} E out;}Z<P T,P=P T::is_iterable_wrapper>H Qe&z<<(Qe&out,X T&v){out<< "[";for(B it=E8(v);it!=Qa(v);){ out<<*it;++it;if(it!=Qa(v)){out<< ", ";}} E out<< "]";} 
#define def_iterable_ostream(I)Z<P...Ts>Qe&z<<(Qe&out,X I<Ts...>&v){E out<<iter(v);}
Wx(Qv)Wx(std::map)Wx(std::unordered_map)Wx(std::set)Wx(std::unordered_set)Z<A n,P T>WD Qj{WP type=Qv<P Qj<n-1,T>::type>;Q5 B make(X E2<n,A>&sz,X T&QA=T()){E Qv(E4(sz),Qj<n-1,T>::make(Wl(sz),QA));}};Z<P T>WD Qj<1,T>{WP type=Qv<T>;Q5 B make(X Qk<A>&sz,X T&QA=T()){E Qv(E4(sz),QA);}};Z<A n,P T>WP nested_vector=P Qj<n,T>::type;Z<A n,P T>B make_nested_vector(X E2<n,A>&sz,X T&QA=T()){E Qj<n,T>::make(sz,QA);}Z<A n,P T>H B QR(X T&v){if E7(n==1){E Qk(v.W9());}E3{E std::tuple_cat(Qk(v.W9()),QR<n-1>(v[0]));}} Z<A n,P T>H B nested_vector_indices(X T&v){E WB([&](B...x){E W7(x...);},QR<n>(v));}Z<A n,P T>H O(B)Wv(X Qv<T>&v,X E2<n,A>&i){if E7(n==1){E v[E4(i)];}E3{E Wv<n-1>(v[E4(i)],Wl(i));}} Z<A n,P T>H O(B)Wv(Qv<T>&v,X E2<n,A>&i){if E7(n==1){E v[E4(i)];}E3{E Wv<n-1>(v[E4(i)],Wl(i));}} Z<P U,A i,A s>Qe&QM(Qe&out,X U&u){if E7(i==0){out<< "{ ";}out<<WL<i>(u);if E7(i+1<s){out<< ", ";E QM<U,i+1,s>(out,u);}E3{E out<< " }";}} Z<P...Ts>Qe&z<<(Qe&out,X Qk<Ts...>&u){E QM<O(u),0,sizeof...(Ts)>(out,u);}Z<P T,P S>Qe&z<<(Qe&out,X std::pair<T,S>&p){E out<<Qk(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(W0);std::cin.tie(0);std::cout.tie(0);
#define END }
WP namespace std;WP LL=long long;Z<P T,P Merge>Qy Q6{Eu:A n,Qb;X T id;Qv<Qv<T>>rt;Merge QU;WV:Q6(X T&id_,Merge merge_):id(id_),QU(merge_){} W Q4(A n_,X T&QA){Q4(QA>replicate(n_));}Z<P I,P=QP<WF<I>>>W Q4(X I&v){rt.emplace_back(v>Wp);n=rt[0].W9();Qb=_log2(n-1)+1;for(B i:Wk(1,Qb+1)){rt.Eq(Wk(0,rt[i-1].W9()/2)>Q7(FF(j,QU(rt[i-1][2*j],rt[i-1][2*j+1])))>Wp);if(rt[i-1].W9()&1){rt[i].Eq(rt[i-1].back());}}}W Wy(A p,X T&v){rt[0][p]=v;for(B i:Wk(Qb)){p/=2;if(p*2+1<rt[i].W9()){rt[i+1][p]=QU(rt[i][p*2],rt[i][p*2+1]);}E3{rt[i+1][p]=rt[i][p*2];}}}Z<P M>H B point_query(A p,M q)X{E q(rt[0][p]);}H T point_query(A p)X{E rt[0][p];}Z<P M>H B Wq(M q)X{E q(rt.back().back());}H T Wq()X{E rt.back().back();}Z<P M,P S,P E9>B WT(A l,A r,X S&Qf,M q,E9 R)X{if(l>=r){E Qf;}S ans=Qf;for(int i=0;r-l>=(1<<i);++i){A j=1<<i;if(l&j){ans=R(q(rt[i][l>>i]),ans);l+=j;if(l>=r){E ans;}} if(r&j){r-=j;ans=R(ans,q(rt[i][r>>i]));}} E ans;}H B WT(A l,A r)X{E WT(l,r,id,_,QU);}Z<P L,P M,P S,P E9>long long E6(A l,L o,X S&Qf,M q,E9 R)X{if(o(Qf)){E l;}if(l==0){if(o(point_query(0,q))){E 1;}E3{l=1;}} B QJ=Qf;for(B i:Wk(Qb)){if(l>=W9()){break;}A j=1<<i;if(l&j){B y=R(QJ,q(rt[i][l>>i]));if(o(y)){for(int k=i-1;k>=0;--k){y=R(QJ,q(rt[k][l>>k]));if(E1 o(y)){l+=1<<k;QJ=y;}} E l+1;}E3{l+=j;QJ=y;}}}E-1;}Z<P L>H long long E6(A l,L o)X{E E6(l,o,id,_,QU);}Z<P L,P M,P S,P E9>long long Qu(A r,L o,X S&Qf,M q,E9 R)X{if(o(Qf)){E r;}B QJ=Qf;for(B i:Wk(Qb+1)){A j=1<<i;if(r&j){B y=R(q(rt[i][(r>>i)-1]),QJ);if(o(y)){for(int k=i-1;k>=0;--k){y=R(q(rt[k][(r>>k)-1]),QJ);if(E1 o(y)){r-=1<<k;QJ=y;}} E r-1;}E3{r-=j;QJ=y;}}}E-1;}Z<P L>H long long Qu(A r,L o)X{E Qu(r,o,id,_,QU);}H A W9()X{E n;}};Z<P T,P Merge>B make_fast_range_tree(X T&id,Merge QU=Merge()){E Q6<T,Merge>(id,QU);}Z<P Y>WD QX{Y l,r;WX Er(X QX&a)X{E l<=a.l and a.r<=r;}WX Er(X Y&p)X{E l<=p and p<r;}WX E5(X QX&a)X{E r<=a.l or a.r<=l;}W QD(){r=(l+r)/2;}W Q1(){l=(l+r)/2;}Y W9()X{E r-l;}};Z<P Y,P T>Qy QS{Eu:A sz;Qv<T>Wj;WV:Qy d{Eu:QS<Y,T>*Wb;A j;QX<Y>i;WV:explicit d(QS<Y,T>*t):Wb(t),j(1),i{0,Y(t->sz)}{} H d QV(){E*w;}H W WK(X d&){} H W W3(X d&){} H W Q9(){i.QD();j=j*2;}H W Qr(){i.Q1();j=j*2+1;}H d W2()X{d it(*w);it.Q9();E it;}H d WM()X{d it(*w);it.Qr();E it;}H WX W8()X{E i.W9()==1;}H WX WN()X{E i.W9()>1;}T&z*()X{E Wb->Wj[j];}T*z->()X{E&(Wb->Wj[j]);}H B WC()X{E i;}H Y Ew()X{E i.l;}H Y E0()X{E i.r;}};W Q4(Y n,X T&QA){Wj.assign(1<<(_log2(n-1)+2),QA);sz=n;}H Y W9()X{E sz;}d QG(){E d(w);}};Z<P Y,P T>Qy Wd{Eu:WD Qh{T QA;A l=0,r=0;};T id;Y sz;Qv<Qh>Wj;A Wz(){Wj.Eq(Qh{id,0,0});E Wj.W9()-1;}H W QB(A j){if(Wj[j].l==Wj[j].r){Wj[j].l=Wz();Wj[j].r=Wz();}} WV:Qy d{Eu:Wd<Y,T>*Wb;A j;QX<Y>i;WV:explicit d(Wd<Y,T>*t):Wb(t),j(0),i{0,Y(t->W9())}{} H W QB(){Wb->QB(j);}H d&QV(){E*w;}H W WK(X d&){} H W W3(X d&){} H W Q9(){QB();i.QD();j=Wb->Wj[j].l;}H W Qr(){QB();i.Q1();j=Wb->Wj[j].r;}H d W2()X{d it(*w);it.Q9();E it;}H d WM()X{d it(*w);it.Qr();E it;}H WX W8()X{E i.W9()==1;}H WX WN()X{E Wb->Wj[j].l;}T&z*()X{E Wb->Wj[j].QA;}T*z->()X{E&(Wb->Wj[j].QA);}H B WC()X{E i;}H Y Ew()X{E i.l;}H Y E0()X{E i.r;}};W Q4(Y n,X T&QA){id=QA;Wz();sz=n;}H Y W9()X{E sz;}d QG(){E d(w);}};Z<P Y,P T>Qy Q_{Eu:WD Qh{T QA;A l=0,r=0;};T id;Y sz;Qv<Qh>Wj;A Wz(){Wj.Eq(Qh{id,0,0});E Wj.W9()-1;}A Wz(X Qh&v){Wj.Eq(v);E Wj.W9()-1;}H W QB(A j){if(Wj[j].l==Wj[j].r){Wj[j].l=Wz();Wj[j].r=Wz();}} WV:Qy d{Eu:Q_<Y,T>*Wb;A j;QX<Y>i;WV:explicit d(Q_<Y,T>*t):Wb(t),j(0),i{0,Y(t->W9())}{} H W QB(){Wb->QB(j);}H d&QV(){j=Wb->Wz(Wb->Wj[j]);E*w;}H W WK(X d&it){Wb->Wj[j].l=it.j;}H W W3(X d&it){Wb->Wj[j].r=it.j;}H W Q9(){QB();i.QD();j=Wb->Wj[j].l;}H W Qr(){QB();i.Q1();j=Wb->Wj[j].r;}H d W2()X{d it(*w);it.Q9();E it;}H d WM()X{d it(*w);it.Qr();E it;}H WX W8()X{E i.W9()==1;}H WX WN()X{E Wb->Wj[j].l;}T&z*()X{E Wb->Wj[j].QA;}T*z->()X{E&(Wb->Wj[j].QA);}H B WC()X{E i;}H Y Ew()X{E i.l;}H Y E0()X{E i.r;}};W Q4(Y n,X T&QA){id=QA;Wz();sz=n;}H Y W9()X{E sz;}d QG(){E d(w);}};Z<P Y,P Q,P M,P E9>B Qc(Q it,X QX<Y>&i,M q,E9 R){if(i.Er(it.WC())){E q(it.Q2());}it.QB();if(i.E5(it.W2().WC())){E Qc(Q(it.WM()),i,q,R);}if(i.E5(it.WM().WC())){E Qc(Q(it.W2()),i,q,R);}E R(Qc(Q(it.W2()),i,q,R),Qc(Q(it.WM()),i,q,R));}Z<P Y,P Q,P S,P L,P M,P E9>Qk<S,WW<Y>>QH(Q it,Y l,S QJ,L o,M q,E9 R){if(l<=it.Ew()){if(o(QJ)){E{QJ,l};}B y=R(QJ,q(it.Q2()));if(E1 o(y)){E{y,-1};}while(E1 it.W8()){it.QB();y=R(QJ,q(it.W2().Q2()));if(o(y)){it.Q9();}E3{it.Qr();QJ=y;}} E{QJ,it.E0()};}it.QB();if(l>=it.W2().E0()){E QH(Q(it.WM()),l,QJ,o,q,R);}B[tot_l,ans]=QH(Q(it.W2()),l,QJ,o,q,R);if(ans==-1){E QH(Q(it.WM()),l,tot_l,o,q,R);}E3{E{tot_l,ans};}} Z<P Y,P Q,P S,P L,P M,P E9>WW<Y>WI(Q it,Y l,X S&Qf,L o,M q,E9 R){if(l>=it.E0()){E(o(Qf))?(it.E0()):(-1);}E WL<1>(QH(it,l,Qf,o,q,R));}Z<P Y,P Q,P S,P L,P M,P E9>Qk<S,WW<Y>>Q3(Q it,Y r,S QJ,L o,M q,E9 R){if(r>=it.E0()){if(o(QJ)){E{QJ,r};}B y=R(q(it.Q2()),QJ);if(E1 o(y)){E{y,-1};}while(E1 it.W8()){it.QB();y=R(q(it.WM().Q2()),QJ);if(o(y)){it.Qr();}E3{it.Q9();QJ=y;}} E{QJ,it.Ew()};}it.QB();if(r<=it.WM().Ew()){E Q3(Q(it.W2()),r,QJ,o,q,R);}B[tot_r,ans]=Q3(Q(it.WM()),r,QJ,o,q,R);if(ans==-1){E Q3(Q(it.W2()),r,tot_r,o,q,R);}E3{E{tot_r,ans};}} Z<P Y,P Q,P S,P L,P M,P E9>WW<Y>Wr(Q it,Y r,X S&Qf,L o,M q,E9 R){if(r<=0){E(o(Qf))?(0):(-1);}E WL<1>(Q3(it,r,Qf,o,q,R));}Z<P N,P T,P=W>WD QF{H Q5 W f(T&x,X T&lc,X T&rc,X N&){x=QT(lc,rc);}};Z<P N,P T>WD QF<N,T,O(QT(Ey<T&>(),Ey<T>(),Ey<T>(),Ey<N>()))>{H Q5 W f(T&x,X T&lc,X T&rc,X N&op){QT(x,lc,rc,op);}};Z<P Y,P T,P QZ,P Q>Qy Wa{protected:Qg QZ bt;Z<P S>W WZ(Q it,X Qv<S>&v){if(it.WC().E5(QX<Y>{0,Y(v.W9())})){E;}if(it.W8()){it.Q2()=v[it.Ew()];E;}WZ(it.W2(),v);WZ(it.WM(),v);it.Q2()=Iterator::merge(it.W2().Q2(),it.WM().Q2());}WV:Q5 T QU(X T&,X T&);H Q Q4(Y n,X T&v){bt.Q4(n,v);E QG();}Z<P I,P=QP<WF<I>>>H Q Q4(X I&v){Q4(v>Wp);E QG();}Z<P S>Q Q4(X Qv<S>&v){bt.Q4(v.W9(),T{});WZ(QG(),v);E QG();}H Q QG()X{E bt.QG();}Z<P M>H B Wq(M q)X{E q(QG().Q2());}H B Wq()X{E QG().Q2();}Z<P...QN>H B WT(QN&&...WJ)X{E QG().WT(Qo<QN>(WJ)...);}Z<P...QN>H B E6(QN&&...WJ)X{E QG().E6(Qo<QN>(WJ)...);}Z<P...QN>H B Qu(QN&&...WJ)X{E QG().Qu(Qo<QN>(WJ)...);}H A W9()X{E bt.W9();}};Z<P Y,P T,P Q,P N>Qy QO:WV Q{Eu:H Q5 W Ee(T&x,X T&lc,X T&rc,X N&op){QF<N,T>::f(x,lc,rc,op);}W Wm(Y p,X N&op){if(w->W8()){op.apply_to(Q2(),p);E;}if(W2().WC().Er(p)){w->WK(W2().QV());W2().Wm(p,op);}E3{w->W3(WM().QV());WM().Wm(p,op);}Ee(Q2(),W2().Q2(),WM().Q2(),op);}WV:H Q5 B QU(X T&x,X T&y){E QT(x,y);}Q5 X T WS;QO(X Q&a):Q(a){} W QB(){} H QO W2()X{QO it(*w);it.Q9();E it;}H QO WM()X{QO it(*w);it.Qr();E it;}H T&Q2(){E**w;}H X T&Q2()X{E**w;}Z<P M>H B Wq(M q)X{E q(Q2());}H B Wq()X{E Q2();}Z<P S,P M,P E9>H B WT(Y l,Y r,X S&Qf,M q,E9 R)X{QX<Y>i{l,r};if(l<r and E1 i.E5(w->WC())){E Qc(*w,i,q,R);}E3{E Qf;}} H B WT(Y l,Y r)X{E WT(l,r,Ww,_,QU);}Z<P L,P S,P M,P E9>H B E6(Y l,L o,X S&Qf,M q,E9 R)X{E WI(*w,l,Qf,o,q,R);}Z<P L>H B E6(Y l,L o)X{E WI(*w,l,Ww,o,_,QU);}Z<P L,P S,P M,P E9>H B Qu(Y r,L o,X S&Qf,M q,E9 R)X{E Wr(*w,r,Qf,o,q,R);}Z<P L>H B Qu(Y r,L o)X{E Wr(*w,r,Ww,o,_,QU);}H B Wy(Y p,X N&op){QO it(*w);it.QV();it.Wm(p,op);E it;}};Z<P Y,P T,P Q,P N>X T QO<Y,T,Q,N>::identity=Ww;Z<P Y,P T,Z<P,P>P QZ,P N>Qy strict_range_tree:WV Wa<Y,T,QZ<Y,T>,QO<Y,T,P QZ<Y,T>W1,N>>{WV:WP d=P QO<Y,T,P QZ<Y,T>W1,N>W1;H d Wy(Y p,X N&op){E w->QG().Wy(p,op);}};Z<P Y,P T,Z<P,P>P QZ,P N>B make_strict_range_tree(){E strict_range_tree<Y,T,QZ,N>();}Z<P Y,P T,P Q,P N>Qy QL:WV Q{Eu:H Q5 W Ee(T&x,X T&lc,X T&rc,X N&op){QF<N,T>::f(x,lc,rc,op);}W Wm(Y p,X N&op){if(w->W8()){op.apply_to(Q2(),p,p+1);E;}if((*w)->no_op()and w->WN()){if(W2().WC().Er(p)){w->WK(W2().QV());W2().Wm(p,op);}E3{w->W3(WM().QV());WM().Wm(p,op);}} E3{QB();if(W2().WC().Er(p)){W2().Wm(p,op);}E3{WM().Wm(p,op);}} Ee(Q2(),W2().Q2(),WM().Q2(),op);}W Wi(QX<Y>i,X N&op){if(i.Er(w->WC())){(*w)->W6(op.restrict(w->Ew(),w->E0(),i.l,i.r),w->Ew(),w->E0());E;}if((*w)->no_op()and w->WN()){if(E1 i.E5(W2().WC())){w->WK(W2().QV());W2().Wi(i,op);}if(E1 i.E5(WM().WC())){w->W3(WM().QV());WM().Wi(i,op);}} E3{QB();if(E1 i.E5(W2().WC())){W2().Wi(i,op);}if(E1 i.E5(WM().WC())){WM().Wi(i,op);}} w->Ee(Q2(),W2().Q2(),WM().Q2(),op);}WV:H Q5 B QU(X T&x,X T&y){E QT(x,y);}Q5 X T WS;QL(X Q&a):Q(a){} W QB(){if((*w)->no_op()){E;}Y l=w->Ew(),r=w->E0();Y m=(l+r)/2;w->WK(W2().QV());w->W3(WM().QV());W2()->W6((*w)->W_().restrict(l,m,l,r),l,m);WM()->W6((*w)->W_().restrict(m,r,l,r),m,r);(*w)->delete_operation();}H QL W2()X{QL it(*w);it.Q9();E it;}H QL WM()X{QL it(*w);it.Qr();E it;}H T&Q2(){E(*w)->QA;}H X T&Q2()X{E(*w)->QA;}Z<P M>H B Wq(M q)X{E q(Q2());}H B Wq()X{E Q2();}Z<P S,P M,P E9>H B WT(Y l,Y r,X S&Qf,M q,E9 R)X{QX<Y>i{l,r};if(l<r and E1 i.E5(w->WC())){E Qc(*w,i,q,R);}E3{E Qf;}} H B WT(Y l,Y r)X{E WT(l,r,Ww,_,QU);}Z<P L,P S,P M,P E9>H B E6(Y l,L o,X S&Qf,M q,E9 R)X{E WI(*w,l,Qf,o,q,R);}Z<P L>H B E6(Y l,L o)X{E WI(*w,l,Ww,o,_,QU);}Z<P L,P S,P M,P E9>H B Qu(Y r,L o,X S&Qf,M q,E9 R)X{E Wr(*w,r,Qf,o,q,R);}Z<P L>H B Qu(Y r,L o)X{E Wr(*w,r,Ww,o,_,QU);}H B Wy(Y p,X N&op){QL it(*w);it.QV();it.Wm(p,op);E it;}H B Wf(Y l,Y r,X N&op){QL it(*w);QX<Y>i{l,r};if(l<r and E1 i.E5(w->WC())){it.QV();it.Wi(i,op);}E it;}};Z<P Y,P T,P Q,P N>X T QL<Y,T,Q,N>::identity=Ww;Z<P Y,P T,P N>Qy Qn{Eu:WX Ws;N op;WV:T QA;explicit Qn(X T&val_=T()):Ws(W0),QA(val_){} H WX no_op()X{E E1 Ws;}W W6(X N&new_op,Y l,Y r){if(no_op()){op=new_op;Ws=Ei;}E3{op.append(new_op);}new_op.apply_to(QA,l,r);}H X N&W_()X{E op;}W delete_operation(){Ws=W0;}};Z<P Y,P T,Z<P,P>P QZ,P N>Qy lazy_range_tree:WV Wa<Y,T,QZ<Y,Qn<Y,T,N>>,QL<Y,T,P QZ<Y,Qn<Y,T,N>>W1,N>>{WV:WP Qh=Qn<Y,T,N>;WP d=QL<Y,T,P QZ<Y,Qh>W1,N>;H d Q4(Y n,X T&v){w->bt.Q4(n,Qh(v));E w->QG();}Z<P I,P=QP<WF<I>>>H d Q4(X I&v){E Q4(v>Wp);}Z<P S>d Q4(X Qv<S>&v){w->bt.Q4(v.W9(),Qh(T{}));w->WZ(w->QG(),v);E w->QG();}H d Wy(Y p,X N&op){E w->QG().Wy(p,op);}H d Wf(Y l,Y r,X N&op){E w->QG().Wf(l,r,op);}};Z<P Y,P T,Z<P,P>P QZ,P N,P...QN>B make_lazy_range_tree(){E lazy_range_tree<Y,T,QZ,N>();}Z<P...Is>Qy QK{Eu:Qk<Is...>its;WV:QK(X Is&...its_):its(its_...){} H B QV(){WB([&](B&&...xs){(xs.QV(),...);},its);E*w;}H W QB(){WB([&](B&&...xs){(xs.QB(),...);},its);}H W WK(X QK&it){WB([&](B&&...xs){(WL<xs>(its).WK(WL<xs>(it)),...);},Qp<Is...>{});}H W W3(X QK&it){WB([&](B&&...xs){(WL<xs>(its).WK(WL<xs>(it)),...);},Qp<Is...>{});}H W Q9(){WB([&](B&&...xs){(xs.Q9(),...);},its);}H W Qr(){WB([&](B&&...xs){(xs.Qr(),...);},its);}H QK W2()X{B it=*w;it.Q9();E it;}H QK WM()X{B it=*w;it.Qr();E it;}H WX W8()X{E WL<0>(its).W8();}H O(B)z*()X{E WB([&](B&&...xs){E std::forward_as_tuple(xs.Q2()...);},its);}H O(B)Q2()X{E**w;}H B WC()X{E WL<0>(its).WC();}H B Ew()X{E WL<0>(its).Ew();}H B E0()X{E WL<0>(its).E0();}WP T=Qk<Qs<O(*Ey<Is>())>...>;WP Y=Qs<O(WL<0>(its).Ew())>;H Q5 B QU(X T&x,X T&y){E WB([&](B&&...xs){E Qk(Is::merge(WL<xs>(x),WL<xs>(y))...);},Qp<Is...>{});}Q5 X T WS;Z<P M>H B Wq(M q)X{E q(Q2());}H B Wq()X{E Q2();}Z<P S,P M,P E9>H B WT(Y l,Y r,X S&Qf,M q,E9 R)X{QX<Y>i{l,r};if(l<r and E1 i.E5(w->WC())){E Qc(*w,i,q,R);}E3{E Qf;}} H B WT(Y l,Y r)X{E WT(l,r,WS,_,QU);}Z<P L,P S,P M,P E9>H B E6(Y l,L o,X S&Qf,M q,E9 R)X{E WI(*w,l,Qf,o,q,R);}Z<P L>H B E6(Y l,L o)X{E WI(*w,l,WS,o,_,QU);}Z<P L,P S,P M,P E9>H B Qu(Y r,L o,X S&Qf,M q,E9 R)X{E Wr(*w,r,Qf,o,q,R);}Z<P L>H B Qu(Y r,L o)X{E Wr(*w,r,WS,o,_,QU);}};Z<P...Is>X P QK<Is...>::T QK<Is...>::identity=Qk(Is::identity...);Z<P...Is>B zip_range_trees(X Is&...iterators){E QK<Is...>(iterators...);}WD Val{int fours,sevens,lis,lds;};WD N{WX flip;E7 Q5 Val WS={0,0,0,0};Q5 Val QU(Val x,Val y){E{x.fours+y.fours,x.sevens+y.sevens,max(x.fours+y.lis,x.lis+y.sevens),max(x.sevens+y.lds,x.lds+y.fours)};}N restrict(int,int,int,int)X{E*w;}W apply_to(Val&x,int,int)X{if(flip){swap(x.fours,x.sevens);swap(x.lis,x.lds);}} W append(X N&a){flip^=a.flip;}};BEGIN int n,m;cin>>n>>m;B rt=make_lazy_range_tree<int,Val,QS,N>();rt.Q4(input<char>>take(n)>Q7(FF(c,(c== '4')?(Val{1,0,1,1}):(Val{0,1,1,1}))));while(m--){string s;cin>>s;if(s[0]== 'c'){cout<<rt.Wq().lis<< "\n";}E3{int l,r;cin>>l>>r;rt.Wf(l-1,r,{Ei});}} END