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
#define B operator
#define d auto
#define Q7 combinations_with_replacement_impl
#define Y other
#define QM k_ptr
#define QU std::remove_reference_t
#define E size_t
#define Q inline
#define Qx iter
#define QK container_carrying_iterator
#define Qz std::index_sequence
#define QY nested_vector_at
#define o const
#define Q5 implicit_lambda_binary_operator
#define Q4 std::ostream
#define Qi range
#define Qa is_composable
#define Qt std::invoke_result_t
#define Q9 using
#define Qm has_updated
#define W std::end
#define QI cartesian_product
#define QZ iterator_macro
#define z std::tuple
#define QJ std::forward
#define P struct
#define Q6 __expr1__
#define QG it_end
#define QH std::decay_t
#define w template
#define H return
#define Qe bool
#define Qn nested_vector_size
#define Qj std::is_rvalue_reference_v
#define Qk cartesian_product_incr_
#define q true
#define QL std::vector
#define Qf tuple_many_of_t
#define Qo iterable_wrapper
#define QR vs_ptr
#define Qr advance
#define X __arg1__
#define QF this
#define Qy is_composable_
#define Qw mutable
#define QN to_nested_vector_impl
#define QV std::tuple_element_t
#define QS false
#define Qp __arg3__
#define Q0 tuple_tail
#define QC implicit_lambda
#define QD std::declval
#define Qc std::move
#define L std::begin
#define Qs push_back
#define QB is_composable_v
#define QT else
#define Qg nested_vector_impl
#define k Iterator
#define Q2 def_iterable_ostream
#define Qb ostream_tuple_helper_
#define Qh j_end
#define O void
#define Q3 __arg2__
#define Z typename
#define Q1 std::apply
#define QA jv_ptr
#define Qq std::conditional_t
#define QP __tuple__
#define Qd std::shared_ptr
#define QO constexpr
#define Qu def_iterator_manip_iter
#define QQ std::get
#define QE my_v
#define QX implicit_lambda_unary_operator
#define Qv has_advanced
#define M decltype
#define R is_end
#define Ql apply
#define Q8 tuple_head
#define QW to_vector

w<Z T,E>Q9 ignore_second=T;w<E...Ix,Z T>d tuple_many_of_impl(Qz<Ix...>,o T&x){H z(ignore_second<T,Ix>(x)...);}w<E n,Z T>d tuple_many_of(o T&x){H tuple_many_of_impl(std::make_index_sequence<n>{},x);}w<E n,Z T>Q9 Qf=M(tuple_many_of<n,T>(QD<T>()));w<Z...Args>d Q8(o z<Args...>&t){H QQ<0>(t);}w<E...Ix,Z...Args>d tuple_tail_impl(Qz<Ix...>,o z<Args...>&t){H z(QQ<Ix+1>(t)...);}w<Z...Args>d Q0(o z<Args...>&t){H tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}P empty_t{};QO empty_t empty_v;w<Z T1,Z T2>std::common_type_t<T1,T2>maxx(o T1&x,o T2&y){if(x<y){H y;}QT{H x;}} w<Z T1,Z T2,Z...Ts>Q d maxx(o T1&x,o T2&y,o Ts&...xs){H maxx(maxx(x,y),xs...);}w<Z T1,Z T2>d minn(o T1&x,o T2&y){if(x<=y){H x;}QT{H y;}} w<Z T1,Z T2,Z...Ts>Q d minn(o T1&x,o T2&y,o Ts&...xs){H minn(minn(x,y),xs...);}QO int _log2(int x){if(x==0){H 0;}H 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&]()->M(d){H f;}
#define FF_1(X,f)[&](d&&X)->M(d){(O)X;H f;}
#define FF_2(X,Q3,f)[&](d&&X,d&&Q3)->M(d){(O)X;(O)Q3;H f;}
#define FF_3(X,Q3,Qp,f)[&](d&&X,d&&Q3,d&&Qp)->M(d){(O)X;(O)Q3;(O)Qp;H f;}
#define FF_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c]()->M(d){H f;}
#define FC_1(X,f,c)[&,c](d&&X)->M(d){(O)X;H f;}
#define FC_2(X,Q3,f,c)[&,c](d&&X,d&&Q3)->M(d){(O)X;(O)Q3;H f;}
#define FC_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2]()->M(d){H f;}
#define FC2_1(X,f,c1,c2)[&,c1,c2](d&&X)->M(d){(O)X;H f;}
#define FC2_2(X,Q3,f,c1,c2)[&,c1,c2](d&&X,d&&Q3)->M(d){(O)X;(O)Q3;H f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(X,f)[&](d&&QP)->M(d){d&[X]=QP;(O)X;H f;}
#define FT_2(X,Q3,f)[&](d&&QP)->M(d){d&[X,Q3]=QP;(O)X;(O)Q3;H f;}
#define FT_3(X,Q3,Qp,f)[&](d&&QP)->M(d){d&[X,Q3,Qp]=QP;(O)X;(O)Q3;(O)Qp;H f;}
#define FT_4(X,Q3,Qp,__arg4__,f)[&](d&&QP)->M(d){d&[X,Q3,Qp,__arg4__]=QP;(O)X;(O)Q3;(O)Qp;(O)__arg4__;H f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Q6,f)[&](){d&&Q6;H f;}()
#define LET_2(Q6,__expr2__,f)[&](){d&&Q6;d&&__expr2__;H f;}()
#define LET_3(Q6,__expr2__,__expr3__,f)[&](){d&&Q6;d&&__expr2__;d&&__expr3__;H f;}()
#define LET_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)QO P{Q9 Qy=O;templ Q M(d)B()args o code}name;
w<Z F>class QC{private:F f;public:QC(F f_):f(f_){} w<Z...Ts>QO d B()(Ts&&...xs)o{H f(QJ<Ts>(xs)...);}};QC _([](d&&x)->Qq<Qj<M(x)>,QU<M(x)>,M(x)>{H x;});QC _1([](d&&x,d&&)->Qq<Qj<M(x)>,QU<M(x)>,M(x)>{H x;});QC _2([](d&&,d&&y)->Qq<Qj<M(y)>,QU<M(y)>,M(y)>{H y;});
#define implicit_lambda_unary_operator(op)w<Z F>QO M(d)B op(QC<F>f){H QC([=](d&&...xs){H op f(QJ<M(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)w<Z F,Z T>QO M(d)B op(QC<F>f,o T&y){H QC([=](d&&...xs){H f(QJ<M(xs)>(xs)...)op y;});}w<Z F,Z T>QO M(d)B op(o T&y,QC<F>f){H QC([=](d&&...xs){H y op f(QJ<M(xs)>(xs)...);});}w<Z F,Z G>QO M(d)B op(QC<F>f,QC<G>g){H QC([=](d&&...xs){H f(QJ<M(xs)>(xs)...)op g(QJ<M(xs)>(xs)...);});}
QX(+)QX(-)QX(!)QX(~)QX(*)QX(&)Q5(+)Q5(-)Q5(*)Q5(/)Q5(%)Q5(<)Q5(>)Q5(<=)Q5(>=)Q5(==)Q5(!=)Q5(<<)Q5(>>)Q5(&)Q5(|)Q5(^)Q5(&&)w<Z T,Z=O>P Qa:public std::false_type{};w<Z T>P Qa<T,std::void_t<Z T::is_composable_>>:public std::true_type{};w<Z T>QO Qe QB=Qa<T>::value;w<Z T,Z F,Z=Qt<F,T>>M(d)B>(T&&v,o F&f){H f(QJ<T>(v));}w<Z M1,Z M2>P composed{Q9 Qy=O;o M1 m1;o M2 m2;w<Z T>M(d)B()(T&&v)o{H m1(m2(QJ<T>(v)));}};w<Z M1,Z M2,Z=std::enable_if_t<QB<M1>or QB<M2>>>Q d B<(o M1&m1,o M2&m2){H composed<M1,M2>{m1,m2};}w<E n>P nth_impl{Q9 Qy=O;w<Z...Ts>QO QV<n,z<Ts...>>&B()(z<Ts...>&u)o{H QQ<n>(u);}w<Z...Ts>QO QV<n,z<Ts...>>B()(z<Ts...>&&u)o{H QQ<n>(u);}w<Z...Ts>QO o QV<n,z<Ts...>>&B()(o z<Ts...>&u)o{H QQ<n>(u);}w<Z...Ts>QO o QV<n,z<Ts...>>B()(o z<Ts...>&&u)o{H QQ<n>(u);}};w<E n>QO nth_impl<n>nth;QO nth_impl<0>fst;QO nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)P k{extra Qe B!=(o k&Y)o neq k&B++()incr M(d)B*()o val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,QG,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{QZ(extra extra_it Qw I it;,neq_it,incr_it,val_it);H Qo(it_begin,QG);})
#define def_iterator_manip_2(name,code)QO P{Q9 Qy=O;w<Z T,Z I=M(L(QD<T>())),Z V=QH<M(*QD<I>())>>M(d)B()(T&&v)o code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ P name##_impl{Q9 Qy=O;extra w<Z T,Z I=M(L(QD<T>())),Z V=QH<M(*QD<I>())>>M(d)B()(T&&v)o code};templ Q M(d)name args{H name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
w<Z T,Z=O>P is_iterable:public std::false_type{};w<Z T>P is_iterable<T,std::void_t<M(L(QD<T>())),M(W(QD<T>()))>>:public std::true_type{};w<Z T>QO Qe is_iterable_v=is_iterable<T>::value;w<Z I>Q d Qo(o I&b,o I&e){P Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
Q9 is_iterable_wrapper=O;Q9 iterator=I;Q9 value_type=QH<M(*QD<I>())>;
#pragma GCC diagnostic pop
I b,e;d begin()o{H b;}d end()o{H e;}};H Wrapper{b,e};}w<Z T>Q d Qx(T&&iterable){H Qo(L(QJ<T>(iterable)),W(QJ<T>(iterable)));}w<Z I>Q d Qx(o I&b,o I&e){H Qo(b,e);}w<Z C>P QK:public C::iterator{Qd<C>p;QK(Qd<C>p_,Z C::iterator it):C::iterator(it),p(p_){}};w<Z C>Q d iterc(C&&v){Q9 D=QH<C>;Qd<D>p(new D(QJ<C>(v)));H Qo(QK<D>{p,L(*p)},QK<D>{p,W(*p)});}w<Z T>Q d Qx(std::initializer_list<T>l){H iterc(QL<T>(l));}def_template_lambda(w<Z T>,QW,(T&&v),{QL<Z QH<T>::value_type>s;for(d&&x:v){s.Qs(x);}H s;})w<E n>P QN{w<Z T>Q static d make(T&&v){H QJ<T>(v)>Ql(FF(u,QN<n-1>::make(u)))>QW;}};w<>P QN<1>{w<Z T>Q static d make(T&&v){H QJ<T>(v)>QW;}};w<E n>P to_nested_vector_{Q9 Qy=O;w<Z T>Q M(d)B()(T&&v)o{H QN<n>::make(QJ<T>(v));}};w<E n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(E l,E r),({l,r}),E l;E r;,{H Qx(L(v)+l,L(v)+r);})def_iterator_manip(is_nil,{H not(L(v)!=W(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{E l=0;for(d i=L(v);i!=W(v);++i){++l;}H l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
w<Z T1,Z T2,Z T3,Z T=std::make_signed_t<M(T1()+T2()+T3())>>Q d Qi(o T1&b,o T2&e,o T3&step){QZ(T x;T e;T step;Q Qe R()o{H(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{H R()xor Y.R();},{x+=step;H*QF;},{H T(x);}) H Qx(k{b,e,step},k{e,e,step});}w<Z T1,Z T2>Q d Qi(o T1&b,o T2&e){H Qi(b,e,M(T1()+T2())(1));}w<Z T>Q d Qi(o T&e){H Qi(T(),e,T(1));} 
#pragma GCC diagnostic pop
w<Z T>Q d to_infinity(o T&b=0,o T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
QZ(T x;T step;,{(O)Y;H q;},{x+=step;H*QF;},{H T(x);}) H Qx(k{b,step},k{b,step});
#pragma GCC diagnostic pop
}Qu(Ql,w<Z F>,(F f),<F>{f},F f;,(k{f,L(v)}),(k{f,W(v)}),,{ H it!=Y.it;},{++it;H*QF;},{H f(*it);}) Qu(take,,(E n),{n},E n;,(k{n,L(v)}),(k{0,W(v)}),,{ H n!=Y.n;},{--n;if(n>0){++it;}H*QF;},{H*it;}) Qu(take_while,w<Z F>,(F f),<F>{f},F f;,(k{f,not(L(v)!=W(v)and f(*L(v))),L(v)}),(k{f,q,W(v)}),Qe R;,{H R xor Y.R;},{++it;if(not f(*it)){R=q;}H*QF;},{H*it;}) Qu(drop,,(E n),{n},Qw E n;,(k{n,W(v),L(v)}),(k{0,W(v),W(v)}),o I end_it;Q O Qr()o{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{Qr();Y.Qr();H it!=Y.it;},{Qr();++it;H*QF;},{Qr();H*it;}) Qu(drop_while,w<Z F>,(F f),<F>{f},F f;,(k{f,W(v),QS,L(v)}),(k{f,W(v),q,W(v)}),o I end_it;Qw Qe Qv;Q O Qr()o{if(not Qv){while(it!=end_it and f(*it)){++it;}Qv=q;}},{Qr();Y.Qr();H it!=Y.it;},{Qr();++it;H*QF;},{Qr();H*it;}) def_iterator_manip(head,{H*L(v);})Q d tail=drop(1);Q d at(E n){H head<drop(n);}Qu(cons,w<Z S>,(S s),<S>{s},S s;,(k{s,q,L(v)}),(k{s,QS,W(v)}),Qe is_s;,{H is_s!=Y.is_s or it!=Y.it;},{if(is_s){is_s=QS;}QT{++it;}H*QF;},{H(is_s)?(s):(*it);}) def_iterator_manip(snoc,{d it=L(v);d h=*it;++it;H z(h,Qx(it,W(v)));})def_iterator_manip(split_at,,(E n),{n},E n;,{d it=L(v);QL<T>u;for(d i:Qi(n)){u.Qs(*it);++it;}H z(iterc(Qc(u)),Qx(it,W(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
Qu(chunks_of,,(E n),{n},E n;,(k{n,{},QS,W(v),L(v)}),(k{n,{},QS,W(v),W(v)}),Qw QL<V>u;Qw Qe Qm;I QG;O update()o{u.clear();Qm=q;for(d i:Qi(n)){if(it!=QG){u.Qs(*it);++it;}QT{break;}}},{H it!=Y.it;},{if(Qm){Qm=QS;}QT{for(d i:Qi(n)){if(it!=QG){++it;}QT{break;}}}H*QF;},{if(not Qm){update();}H iterc(u);})
#pragma GCC diagnostic pop
w<Z F,Z S>P fold_impl{Q9 Qy=O;F f;S s;w<Z T>d B()(o T&v)o{d x=s;for(d y:v){x=f(x,y);}H x;}};w<Z F,Z S>Q d fold(F f,o S&s){H fold_impl<F,S>{f,s};}def_iterator_manip(fold1,w<Z F>,(F f),<F>{f},F f;,{d u=v>snoc;H u>snd>fold(f,u>fst);})def_iterator_manip(sum,{H v>fold(_1+_2,V(0));})def_iterator_manip(product,{H v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,w<Z F>,(F f),<F>{f},F f;,{H v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{H v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,w<Z F>,(F f),<F>{f},F f;,{H v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,w<Z F>,(F f),<F>{f},F f;,{H v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{H v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,w<Z F>,(F f),<F>{f},F f;,{H v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})w<Z F,Z S>P scan_impl{Q9 Qy=O;F f;S s;w<Z T,Z I=M(L(QD<T>()))>M(d)B()(T&&v)o{QZ(F f;Qw S s;Qw Qe Qm;Qe Qv;Qw I it;,{H it!=Y.it;},{if(not Qm){s=f(s,*it);};Qm=QS;if(Qv){++it;}QT{Qv=q;}H*QF;},{if(not Qm){Qm=q;s=f(s,*it);}H s;}) H Qx(k{f,s,q,QS,L(QJ<T>(v))},k{f,s,q,q,W(QJ<T>(v))});}};w<Z F,Z S>Q d scan(F f,o S&s){H scan_impl<F,S>{f,s};}Qu(scan1,w<Z F>,(F f),<F>{f},F f;,(k{f,*L(v),q,L(v)}),(k{f,*L(v),q,W(v)}),Qw V s;Qw Qe Qm;,{H it!=Y.it;},{if(not Qm){s=f(s,*it);};Qm=QS;++it;H*QF;},{if(not Qm){Qm=q;s=f(s,*it);}H s;}) w<Z T,Z S,Z I=M(L(QD<T>())),Z J=M(L(QD<S>()))>Q d B+(T&&v,S&&u){QZ(I i;I i_end;J j;Qe in_i;,{H i!=Y.i or j!=Y.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=QS;}}QT{++j;}H*QF;},{H(in_i)?(*i):(*j);}) I bv=L(v);I ev=W(v);J bu=L(u);J eu=W(u);H Qx(k{bv,ev,bu,bv!=ev},k{ev,ev,eu,QS});}QO P{Q9 Qy=O;w<Z T>d B()(T&&v)o{d u=QJ<T>(v)>filter(FF(i,not is_nil(i)));d b=L(u);d e=W(u);Q9 J=M(b);Q9 V=QH<M(*b)>;Q9 K=M(L(*b));P k{J j;J Qh;Qd<V>QA;K*QM;Qe R;k(J j,J Qh,o V&jv,Qe R):j(j),Qh(Qh),QA(new V(jv)),QM(new K(L(*QA))),R(R){} k(J j,J Qh,Qe R):j(j),Qh(Qh),QA(nullptr),QM(nullptr),R(R){} k(o k&Y):j(Y.j),Qh(Y.Qh),QA(Y.QA),QM((Y.QM)?(new K(*Y.QM)):nullptr),R(Y.R){} k(k&&Y):j(Y.j),Qh(Y.Qh),QA(Y.QA),QM((Y.QM)?(new K(*Y.QM)):nullptr),R(Y.R){}~k(){delete QM;}Qe B!=(o k&Y)o{H R xor Y.R;}k&B++(){++*QM;if(not(*QM!=W(*QA))){++j;if(j!=Qh){delete QM;QA=std::make_shared<V>(*j);QM=new K(L(*QA));}QT{R=q;}} H*QF;}M(d)B*()o{H**QM;}};if(u>is_nil){H Qo(k(b,e,q),k(b,e,q));}QT{H Qo(k(b,e,*b,QS),k(e,e,q));}}}flatten;w<Z T,Z F,Z=std::enable_if_t<is_iterable_v<T>>>d B>=(T&&v,F f){H v>Ql(f)>flatten;}w<Z U,E...Is>Q Qe all_different_(o U&x,o U&y,Qz<Is...>){H((QQ<Is>(x)!=QQ<Is>(y))&&...);}w<Z F,Z...Ts>Q d zip_with(F f,Ts&&...vs){QZ(F f;z<M(L(QD<Ts>()))...>its;,{H all_different_(its,Y.its,std::index_sequence_for<Ts...>{});},{Q1([&](d&&...xs){(++xs,...);},its);H*QF;},{H Q1([&](d&&...xs){H f(*xs...);},its);}) H Qx(k{f,z(L(vs)...)},k{f,z(W(vs)...)});};P zip_default_function_{w<Z...Ts>M(d)B()(Ts&&...xs)o{H z<Ts...>(QJ<Ts>(xs)...);}};w<Z...Ts>Q d zip(Ts&&...vs){H zip_with(zip_default_function_{},QJ<Ts>(vs)...);}Qu(filter,w<Z F>,(F f),<F>{f},F f;,(k{f,W(v),L(v)}),(k{f,W(v),W(v)}),o I end_it;Q O Qr()o{while(it!=end_it and not f(*it)){++it;}},{Qr();Y.Qr();H it!=Y.it;},{Qr();++it;H*QF;},{Qr();H*it;}) def_template_lambda(w<Z T>,repeat,(T&&v),{P k{o QH<T>v;Qe B!=(o k&)o{H q;}k&B++(){H*QF;}o d&B*()o{H v;}};H Qx(k{v},k{v});})Q d replicate(E n){H take(n)<repeat;}Q d cycle=flatten<repeat;def_iterator_manip(enumerate,{H zip(to_infinity(E(0)),v);})def_iterator_manip(reversed,{d s=v>QW;std::reverse(s.begin(),s.end());H iterc(Qc(s));})def_iterator_manip(sorted_by,w<Z F>,(F f),<F>{f},F f;,{d s=v>QW;std::sort(L(s),W(s),f);H iterc(Qc(s));})def_iterator_manip(sorted,{H v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,w<Z F>,(F f),<F>{f},F f;,{H v>Ql(FF(i,z(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>Ql(fst);})def_iterator_manip(nub,{QZ(I QG;I it;,{H it!=Y.it;},{M(*it)pr;do{pr=*it;++it;}while(it!=QG and pr==*it);H*QF;},{H*it;}) d b=L(v);d e=W(v);H Qx(k{e,b},k{e,e});})w<Z F,Z S>P accum_vector_by_{Q9 Qy=O;E n;F f;S s;w<Z T,Z I=M(L(QD<T>())),Z V=QH<M(*QD<I>())>>M(d)B()(o T&v)o{QL<QH<Qt<F,S,M(QQ<1>(QD<V>()))>>>u(n,s);for(d&&[i,x]:v){u[i]=f(u[i],x);}H u;}};w<Z F,Z S>Q d accum_vector_by(E n,F f,o S&s){H accum_vector_by_<F,S>{n,f,s};}w<Z S>Q d accum_vector(E n,o S&s=S()){H accum_vector_by(n,_2,s);}w<Z F,Z S>P accum_map_by_{Q9 Qy=O;F f;S s;w<Z T,Z I=M(L(QD<T>())),Z V=QH<M(*QD<I>())>>M(d)B()(o T&v)o{std::map<QH<M(QQ<0>(QD<V>()))>,QH<Qt<F,S,M(QQ<1>(QD<V>()))>>>u;for(d&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QT{u[i]=f(s,x);}} H u;}};w<Z F,Z S>Q d accum_map_by(F f,o S&s){H accum_map_by_<F,S>{f,s};}w<Z S>Q d accum_map(o S&s=S()){H accum_map_by(_2,s);}w<Z F,Z S>P accum_unordered_map_by_{Q9 Qy=O;F f;S s;w<Z T,Z I=M(L(QD<T>())),Z V=QH<M(*QD<I>())>>M(d)B()(o T&v)o{std::unordered_map<QH<M(QQ<0>(QD<V>()))>,QH<Qt<F,S,M(QQ<1>(QD<V>()))>>>u;for(d&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QT{u[i]=f(s,x);}} H u;}};w<Z F,Z S>Q d accum_unordered_map_by(F f,o S&s){H accum_unordered_map_by_<F,S>{f,s};}w<Z S>Q d accum_unordered_map(o S&s=S()){H accum_unordered_map_by(_2,s);}w<Z U,E...Is>Q Qe any_different_(o U&x,o U&y,Qz<Is...>){H((QQ<Is>(x)!=QQ<Is>(y))||...);}w<E N,Z k>Q O Qk(k&it){if QO(N>=1){++QQ<N-1>(it.its);if(not(QQ<N-1>(it.its)!=W(QQ<N-1>(*it.my_vs_ptr)))){QQ<N-1>(it.its)=L(QQ<N-1>(*it.my_vs_ptr));Qk<N-1>(it);}} QT{it.its=Q1([](d&&...xs){H z(W(xs)...);},*it.my_vs_ptr);}} w<Z...Ts>d QI(Ts&&...vs){d QR=std::make_shared<z<Qq<Qj<Ts>,QU<Ts>,Ts>...>>(vs...);QZ(z<M(L(QD<Qq<Qj<Ts>,QU<Ts>,Ts>>()))...>its;M(QR)my_vs_ptr;,{H any_different_(its,Y.its,std::index_sequence_for<Ts...>{});},{Qk<sizeof...(Ts)>(*QF);H*QF;},{H Q1([](d&&...xs){H z<M(*xs)...>(*xs...);},its);}) if(Q1([](d&&...xs){H((xs>is_nil)||...);},*QR)){H Qx(k{Q1([](d&&...xs){H z(W(xs)...);},*QR),QR},k{Q1([](d&&...xs){H z(W(xs)...);},*QR),QR});}QT{H Qx(k{Q1([](d&&...xs){H z(L(xs)...);},*QR),QR},k{Q1([](d&&...xs){H z(W(xs)...);},*QR),QR});}};w<Z...Ts>Q d cartesian_product_range(o Ts&...n){H QI(Qi(n)...);}w<E n,Z I>Q d cartesian_power(o I&v){H Q1([](o d&...vs){H QI(vs...);},tuple_many_of<n>(v));}P{Q9 Qy=O;int n=-1;w<Z T>d B()(T&&v)o{if QO(std::is_convertible_v<T,int>){d x=*QF;x.n=v;H x;}QT{d vec=v>QW;int m=vec.size();P k{int n;M(vec)QE;QL<E>cycles;Qe R;Qe B!=(o k&Y)o{H R xor Y.R;}k&B++(){for(d i:Qi(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=QE.size()-i;std::rotate(QE.begin()+i,QE.begin()+i+1,QE.end());}QT{std::swap(QE[i],QE[QE.size()-cycles[i]]);H*QF;}} R=q;H*QF;}d B*()o{H QE>array_slice(0,n);}};int n1=(n<0)?(m):(n);H Qx(k{n1,Qc(vec),Qi(m,m-n1,-1)>Ql(FF(x,E(x)))>QW,QS},k{n1,{},{},q});}}}permutations;P combinations_impl{Q9 Qy=O;int n;w<Z T>d B()(T&&v)o{d vec=v>QW;int m=vec.size();QZ(int n;M(vec)QE;QL<E>idx;Qe R;,{H R xor Y.R;},{for(d i:Qi(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(d j:Qi(i+1,n)){idx[j]=idx[j-1]+1;}H*QF;}} R=q;H*QF;},{H idx>array_slice(0,n)>Ql(FF(i,QE[i]));}) H Qx(k{n,Qc(vec),Qi(0,m)>Ql(FF(x,E(x)))>QW,QS},k{n,{},{},q});}};Q d combinations(int n){H combinations_impl{n};}P Q7{Q9 Qy=O;int n;w<Z T>d B()(T&&v)o{d vec=v>QW;int m=vec.size();QZ(int n;M(vec)QE;QL<E>idx;Qe R;,{H R xor Y.R;},{for(d i:Qi(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(d j:Qi(i+1,n)){idx[j]=idx[i];}H*QF;}} R=q;H*QF;},{H idx>array_slice(0,n)>Ql(FF(i,QE[i]));}) H Qx(k{n,Qc(vec),E(0)>replicate(m)>QW,QS},k{n,{},{},q});}};Q d combinations_with_replacement(int n){H Q7{n};}w<Z T>Q d istream_iterable(std::istream&in){QZ(std::istream&in;Qw T val;Qe R;Qw Qe has_read;,{H R xor Y.R;},{if(not(in>>val)){R=q;}H*QF;},{if(not has_read){has_read=q;in>>val;}H val;}) H Qx(k{in,T{},QS,QS},k{in,T{},q,q});}w<Z T>Q d input=istream_iterable<T>(std::cin);w<Z T>Q4&print_iterable(Q4&out,o T&v,o std::string&sep= " "){for(d it=L(v);it!=W(v);){ out<<*it;++it;if(it!=W(v)){out<<sep;}QT{H out;}} H out;}w<Z T,Z=Z T::is_iterable_wrapper>Q Q4&B<<(Q4&out,o T&v){out<< "[";H print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)w<Z...Ts>Q4&B<<(Q4&out,o I<Ts...>&v){H out<<Qx(v);}
Q2(QL)Q2(std::map)Q2(std::unordered_map)Q2(std::set)Q2(std::unordered_set)w<E n,Z T>P Qg{Q9 type=QL<Z Qg<n-1,T>::type>;static d make(o Qf<n,E>&sz,o T&val=T()){H QL(Q8(sz),Qg<n-1,T>::make(Q0(sz),val));}};w<Z T>P Qg<1,T>{Q9 type=QL<T>;static d make(o z<E>&sz,o T&val=T()){H QL(Q8(sz),val);}};w<E n,Z T>Q9 nested_vector=Z Qg<n,T>::type;w<E n,Z T>d make_nested_vector(o Qf<n,E>&sz,o T&val=T()){H Qg<n,T>::make(sz,val);}w<E n,Z T>Q d Qn(o T&v){if QO(n==1){H z(v.size());}QT{H std::tuple_cat(z(v.size()),Qn<n-1>(v[0]));}} w<E n,Z T>Q d nested_vector_indices(o T&v){H Q1([&](d...x){H cartesian_product_range(x...);},Qn<n>(v));}w<E n,Z T>Q M(d)QY(o QL<T>&v,o Qf<n,E>&i){if QO(n==1){H v[Q8(i)];}QT{H QY<n-1>(v[Q8(i)],Q0(i));}} w<E n,Z T>Q M(d)QY(QL<T>&v,o Qf<n,E>&i){if QO(n==1){H v[Q8(i)];}QT{H QY<n-1>(v[Q8(i)],Q0(i));}} w<Z U,E i,E s>Q4&Qb(Q4&out,o U&u){if QO(i==0){out<< "{ ";}out<<QQ<i>(u);if QO(i+1<s){out<< ", ";H Qb<U,i+1,s>(out,u);}QT{H out<< " }";}} w<Z...Ts>Q4&B<<(Q4&out,o z<Ts...>&u){H Qb<M(u),0,sizeof...(Ts)>(out,u);}w<Z T,Z S>Q4&B<<(Q4&out,o std::pair<T,S>&p){H out<<z(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(QS);std::cin.tie(0);std::cout.tie(0);
#define END }
Q9 namespace std;Q9 LL=long long;BEGIN int N;cin>>N;vector<int>A(N);LL s=0;for(d&x:A){cin>>x;s+=x;}vector<LL>primes;for(LL p=2;p*p<=s;++p){if((s%p)==0){primes.Qs(p);while((s%p)==0){s/=p;}}}if(s>1){primes.Qs(s);}if(primes.size()==0){cout<<-1<< "\n";H 0;}LL ans=1LL<<60;for(d p:primes){LL curr_ans=0;LL pre=0;for(d a:A){pre=(pre+a)%p;curr_ans+=min(pre,p-pre);}ans=min(ans,curr_ans);}cout<<ans<< "\n";END