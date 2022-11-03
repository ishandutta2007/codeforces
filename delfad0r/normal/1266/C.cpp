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
#define Qy my_v
#define Qr advance
#define Q3 has_updated
#define Qh __arg2__
#define QH std::apply
#define Qu std::move
#define Qj tuple_tail
#define L template
#define H auto
#define Q0 nested_vector_size
#define Q1 __expr1__
#define Qd def_iterable_ostream
#define q std::tuple
#define Qg std::index_sequence
#define d std::begin
#define QB std::conditional_t
#define Z std::end
#define QR to_nested_vector_impl
#define Qb std::forward
#define Qs std::invoke_result_t
#define Qc to_vector
#define Q5 is_composable_v
#define QV has_advanced
#define A using
#define Qw constexpr
#define P inline
#define X Iterator
#define Qt __tuple__
#define QC std::vector
#define Qx implicit_lambda_binary_operator
#define QL vs_ptr
#define QX std::tuple_element_t
#define Qf iterator_macro
#define Q8 std::is_rvalue_reference_v
#define Qn jv_ptr
#define Q4 GET_5TH_ARG
#define Qe std::remove_reference_t
#define Qz else
#define Qk tuple_head
#define QG false
#define Q7 iter
#define Q6 bool
#define QO implicit_lambda_unary_operator
#define Qi __arg3__
#define Qm combinations_with_replacement_impl
#define w typename
#define Q size_t
#define Qo std::get
#define E other
#define QP it_end
#define QW cartesian_product_incr_
#define QE implicit_lambda
#define a is_end
#define QF nested_vector_impl
#define QQ mutable
#define Qa tuple_many_of_t
#define O operator
#define Q9 iterable_wrapper
#define QD container_carrying_iterator
#define QI this
#define M return
#define QJ apply
#define QS std::ostream
#define B void
#define QZ is_composable_
#define QU std::declval
#define QY j_end
#define Qq ostream_tuple_helper_
#define z true
#define W decltype
#define QK cartesian_product
#define Q2 std::decay_t
#define Qp nested_vector_at
#define o const
#define QT def_iterator_manip_iter
#define Y __arg1__
#define QA k_ptr
#define Qv range
#define k struct
#define Ql std::shared_ptr

L<w T,Q>A ignore_second=T;L<Q...Ix,w T>H tuple_many_of_impl(Qg<Ix...>,o T&x){M q(ignore_second<T,Ix>(x)...);}L<Q n,w T>H tuple_many_of(o T&x){M tuple_many_of_impl(std::make_index_sequence<n>{},x);}L<Q n,w T>A Qa=W(tuple_many_of<n,T>(QU<T>()));L<w...Args>H Qk(o q<Args...>&t){M Qo<0>(t);}L<Q...Ix,w...Args>H tuple_tail_impl(Qg<Ix...>,o q<Args...>&t){M q(Qo<Ix+1>(t)...);}L<w...Args>H Qj(o q<Args...>&t){M tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}k empty_t{};Qw empty_t empty_v;L<w T1,w T2>std::common_type_t<T1,T2>maxx(o T1&x,o T2&y){if(x<y){M y;}Qz{M x;}} L<w T1,w T2,w...Ts>P H maxx(o T1&x,o T2&y,o Ts&...xs){M maxx(maxx(x,y),xs...);}L<w T1,w T2>H minn(o T1&x,o T2&y){if(x<=y){M x;}Qz{M y;}} L<w T1,w T2,w...Ts>P H minn(o T1&x,o T2&y,o Ts&...xs){M minn(minn(x,y),xs...);}Qw int _log2(int x){if(x==0){M 0;}M 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){M f;}
#define FF_1(Y,f)[&](H&&Y){(B)Y;M f;}
#define FF_2(Y,Qh,f)[&](H&&Y,H&&Qh){(B)Y;(B)Qh;M f;}
#define FF_3(Y,Qh,Qi,f)[&](H&&Y,H&&Qh,H&&Qi){(B)Y;(B)Qh;(B)Qi;M f;}
#define FF_macro_chooser(...)Q4(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->H&{M f;}
#define FREF_1(Y,f)[&](H&&Y)->H&{(B)Y;M f;}
#define FREF_2(Y,Qh,f)[&](H&&Y,H&&Qh)->H&{(B)Y;(B)Qh;M f;}
#define FREF_3(Y,Qh,Qi,f)[&](H&&Y,H&&Qh,H&&Qi)->H&{(B)Y;(B)Qh;(B)Qi;M f;}
#define FREF_macro_chooser(...)Q4(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){M f;}
#define FC_1(Y,f,c)[&,c](H&&Y){(B)Y;M f;}
#define FC_2(Y,Qh,f,c)[&,c](H&&Y,H&&Qh){(B)Y;(B)Qh;M f;}
#define FC_macro_chooser(...)Q4(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){M f;}
#define FC2_1(Y,f,c1,c2)[&,c1,c2](H&&Y){(B)Y;M f;}
#define FC2_2(Y,Qh,f,c1,c2)[&,c1,c2](H&&Y,H&&Qh){(B)Y;(B)Qh;M f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(Y,f)[&](H&&Qt){H&[Y]=Qt;(B)Y;M f;}
#define FT_2(Y,Qh,f)[&](H&&Qt){H&[Y,Qh]=Qt;(B)Y;(B)Qh;M f;}
#define FT_3(Y,Qh,Qi,f)[&](H&&Qt){H&[Y,Qh,Qi]=Qt;(B)Y;(B)Qh;(B)Qi;M f;}
#define FT_4(Y,Qh,Qi,__arg4__,f)[&](H&&Qt){H&[Y,Qh,Qi,__arg4__]=Qt;(B)Y;(B)Qh;(B)Qi;(B)__arg4__;M f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Q1,f)[&](){H&&Q1;M f;}()
#define LET_2(Q1,__expr2__,f)[&](){H&&Q1;H&&__expr2__;M f;}()
#define LET_3(Q1,__expr2__,__expr3__,f)[&](){H&&Q1;H&&__expr2__;H&&__expr3__;M f;}()
#define LET_macro_chooser(...)Q4(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)Qw k{A QZ=B;templ P W(H)O()args o code}name;
L<w F>class QE{private:F f;public:QE(F f_):f(f_){} L<w...Ts>Qw H O()(Ts&&...xs)o{M f(Qb<Ts>(xs)...);}};QE _([](H&&x)->QB<Q8<W(x)>,Qe<W(x)>,W(x)>{M x;});QE _1([](H&&x,H&&)->QB<Q8<W(x)>,Qe<W(x)>,W(x)>{M x;});QE _2([](H&&,H&&y)->QB<Q8<W(y)>,Qe<W(y)>,W(y)>{M y;});
#define implicit_lambda_unary_operator(op)L<w F>Qw W(H)O op(QE<F>f){M QE([=](H&&...xs){M op f(Qb<W(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)L<w F,w T>Qw W(H)O op(QE<F>f,o T&y){M QE([=](H&&...xs){M f(Qb<W(xs)>(xs)...)op y;});}L<w F,w T>Qw W(H)O op(o T&y,QE<F>f){M QE([=](H&&...xs){M y op f(Qb<W(xs)>(xs)...);});}L<w F,w G>Qw W(H)O op(QE<F>f,QE<G>g){M QE([=](H&&...xs){M f(Qb<W(xs)>(xs)...)op g(Qb<W(xs)>(xs)...);});}
QO(+)QO(-)QO(!)QO(~)QO(*)QO(&)Qx(+)Qx(-)Qx(*)Qx(/)Qx(%)Qx(<)Qx(>)Qx(<=)Qx(>=)Qx(==)Qx(!=)Qx(<<)Qx(>>)Qx(&)Qx(|)Qx(^)Qx(&&)L<w T,w=B>k is_composable:public std::false_type{};L<w T>k is_composable<T,std::void_t<w T::is_composable_>>:public std::true_type{};L<w T>Qw Q6 Q5=is_composable<T>::value;L<w T,w F,w=Qs<F,T>>W(H)O>(T&&v,o F&f){M f(Qb<T>(v));}L<w M1,w M2>k composed{A QZ=B;o M1 m1;o M2 m2;L<w T>W(H)O()(T&&v)o{M m1(m2(Qb<T>(v)));}};L<w M1,w M2,w=std::enable_if_t<Q5<M1>or Q5<M2>>>P H O<(o M1&m1,o M2&m2){M composed<M1,M2>{m1,m2};}L<Q n>k nth_impl{A QZ=B;L<w...Ts>Qw QX<n,q<Ts...>>&O()(q<Ts...>&u)o{M Qo<n>(u);}L<w...Ts>Qw QX<n,q<Ts...>>O()(q<Ts...>&&u)o{M Qo<n>(u);}L<w...Ts>Qw o QX<n,q<Ts...>>&O()(o q<Ts...>&u)o{M Qo<n>(u);}L<w...Ts>Qw o QX<n,q<Ts...>>O()(o q<Ts...>&&u)o{M Qo<n>(u);}};L<Q n>Qw nth_impl<n>nth;Qw nth_impl<0>fst;Qw nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)k X{extra Q6 O!=(o X&E)o neq X&O++()incr W(H)O*()o val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,QP,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{Qf(extra extra_it QQ I it;,neq_it,incr_it,val_it);M Q9(it_begin,QP);})
#define def_iterator_manip_2(name,code)Qw k{A QZ=B;L<w T,w I=W(d(QU<T>())),w V=Q2<W(*QU<I>())>>W(H)O()(T&&v)o code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ k name##_impl{A QZ=B;extra L<w T,w I=W(d(QU<T>())),w V=Q2<W(*QU<I>())>>W(H)O()(T&&v)o code};templ P W(H)name args{M name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
L<w T,w=B>k is_iterable:public std::false_type{};L<w T>k is_iterable<T,std::void_t<W(d(QU<T>())),W(Z(QU<T>()))>>:public std::true_type{};L<w T>Qw Q6 is_iterable_v=is_iterable<T>::value;L<w I>P H Q9(o I&b,o I&e){k Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
A is_iterable_wrapper=B;A iterator=I;A value_type=Q2<W(*QU<I>())>;
#pragma GCC diagnostic pop
I b,e;H begin()o{M b;}H end()o{M e;}};M Wrapper{b,e};}L<w T>P H Q7(T&&iterable){M Q9(d(Qb<T>(iterable)),Z(Qb<T>(iterable)));}L<w I>P H Q7(o I&b,o I&e){M Q9(b,e);}L<w C>k QD:public C::iterator{Ql<C>p;QD(Ql<C>p_,w C::iterator it):C::iterator(it),p(p_){}};L<w C>P H iterc(C&&v){A D=Q2<C>;Ql<D>p(new D(Qb<C>(v)));M Q9(QD<D>{p,d(*p)},QD<D>{p,Z(*p)});}L<w T>P H Q7(std::initializer_list<T>l){M iterc(QC<T>(l));}def_template_lambda(L<w T>,Qc,(T&&v),{QC<w Q2<T>::value_type>s;for(H&&x:v){s.push_back(x);}M s;})L<Q n>k QR{L<w T>P static H make(T&&v){M Qb<T>(v)>QJ(FF(u,QR<n-1>::make(u)))>Qc;}};L<>k QR<1>{L<w T>P static H make(T&&v){M Qb<T>(v)>Qc;}};L<Q n>k to_nested_vector_{A QZ=B;L<w T>P W(H)O()(T&&v)o{M QR<n>::make(Qb<T>(v));}};L<Q n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(Q l,Q r),({l,r}),Q l;Q r;,{M Q7(d(v)+l,d(v)+r);})def_iterator_manip(is_nil,{M not(d(v)!=Z(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{Q l=0;for(H i=d(v);i!=Z(v);++i){++l;}M l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
L<w T1,w T2,w T3,w T=std::make_signed_t<W(T1()+T2()+T3())>>P H Qv(o T1&b,o T2&e,o T3&step){Qf(T x;T e;T step;P Q6 a()o{M(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{M a()xor E.a();},{x+=step;M*QI;},{M T(x);}) M Q7(X{b,e,step},X{e,e,step});}L<w T1,w T2>P H Qv(o T1&b,o T2&e){M Qv(b,e,W(T1()+T2())(1));}L<w T>P H Qv(o T&e){M Qv(T(),e,T(1));} 
#pragma GCC diagnostic pop
L<w T>P H to_infinity(o T&b=0,o T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
Qf(T x;T step;,{(B)E;M z;},{x+=step;M*QI;},{M T(x);}) M Q7(X{b,step},X{b,step});
#pragma GCC diagnostic pop
}QT(QJ,L<w F>,(F f),<F>{f},F f;,(X{f,d(v)}),(X{f,Z(v)}),,{ M it!=E.it;},{++it;M*QI;},{M f(*it);}) QT(take,,(Q n),{n},Q n;,(X{n,d(v)}),(X{0,Z(v)}),,{ M n!=E.n;},{--n;if(n>0){++it;}M*QI;},{M*it;}) QT(take_while,L<w F>,(F f),<F>{f},F f;,(X{f,not(d(v)!=Z(v)and f(*d(v))),d(v)}),(X{f,z,Z(v)}),Q6 a;,{M a xor E.a;},{++it;if(not f(*it)){a=z;}M*QI;},{M*it;}) QT(drop,,(Q n),{n},QQ Q n;,(X{n,Z(v),d(v)}),(X{0,Z(v),Z(v)}),o I end_it;P B Qr()o{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{Qr();E.Qr();M it!=E.it;},{Qr();++it;M*QI;},{Qr();M*it;}) QT(drop_while,L<w F>,(F f),<F>{f},F f;,(X{f,Z(v),QG,d(v)}),(X{f,Z(v),z,Z(v)}),o I end_it;QQ Q6 QV;P B Qr()o{if(not QV){while(it!=end_it and f(*it)){++it;}QV=z;}},{Qr();E.Qr();M it!=E.it;},{Qr();++it;M*QI;},{Qr();M*it;}) def_iterator_manip(head,{M*d(v);})P H tail=drop(1);P H at(Q n){M head<drop(n);}QT(cons,L<w S>,(S s),<S>{s},S s;,(X{s,z,d(v)}),(X{s,QG,Z(v)}),Q6 is_s;,{M is_s!=E.is_s or it!=E.it;},{if(is_s){is_s=QG;}Qz{++it;}M*QI;},{M(is_s)?(s):(*it);}) def_iterator_manip(snoc,{H it=d(v);H h=*it;++it;M q(h,Q7(it,Z(v)));})def_iterator_manip(split_at,,(Q n),{n},Q n;,{H it=d(v);QC<T>u;for(H i:Qv(n)){u.push_back(*it);++it;}M q(iterc(Qu(u)),Q7(it,Z(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
QT(chunks_of,,(Q n),{n},Q n;,(X{n,{},QG,Z(v),d(v)}),(X{n,{},QG,Z(v),Z(v)}),QQ QC<V>u;QQ Q6 Q3;I QP;B update()o{u.clear();Q3=z;for(H i:Qv(n)){if(it!=QP){u.push_back(*it);++it;}Qz{break;}}},{M it!=E.it;},{if(Q3){Q3=QG;}Qz{for(H i:Qv(n)){if(it!=QP){++it;}Qz{break;}}}M*QI;},{if(not Q3){update();}M iterc(u);})
#pragma GCC diagnostic pop
L<w F,w S>k fold_impl{A QZ=B;F f;S s;L<w T>H O()(o T&v)o{H x=s;for(H y:v){x=f(x,y);}M x;}};L<w F,w S>P H fold(F f,o S&s){M fold_impl<F,S>{f,s};}def_iterator_manip(fold1,L<w F>,(F f),<F>{f},F f;,{H u=v>snoc;M u>snd>fold(f,u>fst);})def_iterator_manip(sum,{M v>fold(_1+_2,V(0));})def_iterator_manip(product,{M v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,L<w F>,(F f),<F>{f},F f;,{M v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{M v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,L<w F>,(F f),<F>{f},F f;,{M v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,L<w F>,(F f),<F>{f},F f;,{M v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{M v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,L<w F>,(F f),<F>{f},F f;,{M v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})L<w F,w S>k scan_impl{A QZ=B;F f;S s;L<w T,w I=W(d(QU<T>()))>W(H)O()(T&&v)o{Qf(F f;QQ S s;QQ Q6 Q3;Q6 QV;QQ I it;,{M it!=E.it;},{if(not Q3){s=f(s,*it);};Q3=QG;if(QV){++it;}Qz{QV=z;}M*QI;},{if(not Q3){Q3=z;s=f(s,*it);}M s;}) M Q7(X{f,s,z,QG,d(Qb<T>(v))},X{f,s,z,z,Z(Qb<T>(v))});}};L<w F,w S>P H scan(F f,o S&s){M scan_impl<F,S>{f,s};}QT(scan1,L<w F>,(F f),<F>{f},F f;,(X{f,*d(v),z,d(v)}),(X{f,*d(v),z,Z(v)}),QQ V s;QQ Q6 Q3;,{M it!=E.it;},{if(not Q3){s=f(s,*it);};Q3=QG;++it;M*QI;},{if(not Q3){Q3=z;s=f(s,*it);}M s;}) L<w T,w S,w I=W(d(QU<T>())),w J=W(d(QU<S>()))>P H O+(T&&v,S&&u){Qf(I i;I i_end;J j;Q6 in_i;,{M i!=E.i or j!=E.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=QG;}}Qz{++j;}M*QI;},{M(in_i)?(*i):(*j);}) I bv=d(v);I ev=Z(v);J bu=d(u);J eu=Z(u);M Q7(X{bv,ev,bu,bv!=ev},X{ev,ev,eu,QG});}Qw k{A QZ=B;L<w T>H O()(T&&v)o{H u=Qb<T>(v)>filter(FF(i,not is_nil(i)));H b=d(u);H e=Z(u);A J=W(b);A V=Q2<W(*b)>;A K=W(d(*b));k X{J j;J QY;Ql<V>Qn;K*QA;Q6 a;X(J j,J QY,o V&jv,Q6 a):j(j),QY(QY),Qn(new V(jv)),QA(new K(d(*Qn))),a(a){} X(J j,J QY,Q6 a):j(j),QY(QY),Qn(nullptr),QA(nullptr),a(a){} X(o X&E):j(E.j),QY(E.QY),Qn(E.Qn),QA((E.QA)?(new K(*E.QA)):nullptr),a(E.a){} X(X&&E):j(E.j),QY(E.QY),Qn(E.Qn),QA((E.QA)?(new K(*E.QA)):nullptr),a(E.a){}~X(){delete QA;}Q6 O!=(o X&E)o{M a xor E.a;}X&O++(){++*QA;if(not(*QA!=Z(*Qn))){++j;if(j!=QY){delete QA;Qn=std::make_shared<V>(*j);QA=new K(d(*Qn));}Qz{a=z;}} M*QI;}W(H)O*()o{M**QA;}};if(u>is_nil){M Q9(X(b,e,z),X(b,e,z));}Qz{M Q9(X(b,e,*b,QG),X(e,e,z));}}}flatten;L<w T,w F,w=std::enable_if_t<is_iterable_v<T>>>H O>=(T&&v,F f){M v>QJ(f)>flatten;}L<w U,Q...Is>P Q6 all_different_(o U&x,o U&y,Qg<Is...>){M((Qo<Is>(x)!=Qo<Is>(y))&&...);}L<w F,w...Ts>P H zip_with(F f,Ts&&...vs){Qf(F f;q<W(d(QU<Ts>()))...>its;,{M all_different_(its,E.its,std::index_sequence_for<Ts...>{});},{QH([&](H&&...xs){(++xs,...);},its);M*QI;},{M QH([&](H&&...xs){M f(*xs...);},its);}) M Q7(X{f,q(d(vs)...)},X{f,q(Z(vs)...)});};k zip_default_function_{L<w...Ts>W(H)O()(Ts&&...xs)o{M q<Ts...>(Qb<Ts>(xs)...);}};L<w...Ts>P H zip(Ts&&...vs){M zip_with(zip_default_function_{},Qb<Ts>(vs)...);}QT(filter,L<w F>,(F f),<F>{f},F f;,(X{f,Z(v),d(v)}),(X{f,Z(v),Z(v)}),o I end_it;P B Qr()o{while(it!=end_it and not f(*it)){++it;}},{Qr();E.Qr();M it!=E.it;},{Qr();++it;M*QI;},{Qr();M*it;}) def_template_lambda(L<w T>,repeat,(T&&v),{k X{o Q2<T>v;Q6 O!=(o X&)o{M z;}X&O++(){M*QI;}o H&O*()o{M v;}};M Q7(X{v},X{v});})P H replicate(Q n){M take(n)<repeat;}P H cycle=flatten<repeat;def_iterator_manip(enumerate,{M zip(to_infinity(Q(0)),v);})def_iterator_manip(reversed,{H s=v>Qc;std::reverse(s.begin(),s.end());M iterc(Qu(s));})def_iterator_manip(sorted_by,L<w F>,(F f),<F>{f},F f;,{H s=v>Qc;std::sort(d(s),Z(s),f);M iterc(Qu(s));})def_iterator_manip(sorted,{M v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,L<w F>,(F f),<F>{f},F f;,{M v>QJ(FF(i,q(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>QJ(fst);})def_iterator_manip(nub,{Qf(I QP;I it;,{M it!=E.it;},{W(*it)pr;do{pr=*it;++it;}while(it!=QP and pr==*it);M*QI;},{M*it;}) H b=d(v);H e=Z(v);M Q7(X{e,b},X{e,e});})L<w F,w S>k accum_vector_by_{A QZ=B;Q n;F f;S s;L<w T,w I=W(d(QU<T>())),w V=Q2<W(*QU<I>())>>W(H)O()(o T&v)o{QC<Q2<Qs<F,S,W(Qo<1>(QU<V>()))>>>u(n,s);for(H&&[i,x]:v){u[i]=f(u[i],x);}M u;}};L<w F,w S>P H accum_vector_by(Q n,F f,o S&s){M accum_vector_by_<F,S>{n,f,s};}L<w S>P H accum_vector(Q n,o S&s=S()){M accum_vector_by(n,_2,s);}L<w F,w S>k accum_map_by_{A QZ=B;F f;S s;L<w T,w I=W(d(QU<T>())),w V=Q2<W(*QU<I>())>>W(H)O()(o T&v)o{std::map<Q2<W(Qo<0>(QU<V>()))>,Q2<Qs<F,S,W(Qo<1>(QU<V>()))>>>u;for(H&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qz{u[i]=f(s,x);}} M u;}};L<w F,w S>P H accum_map_by(F f,o S&s){M accum_map_by_<F,S>{f,s};}L<w S>P H accum_map(o S&s=S()){M accum_map_by(_2,s);}L<w F,w S>k accum_unordered_map_by_{A QZ=B;F f;S s;L<w T,w I=W(d(QU<T>())),w V=Q2<W(*QU<I>())>>W(H)O()(o T&v)o{std::unordered_map<Q2<W(Qo<0>(QU<V>()))>,Q2<Qs<F,S,W(Qo<1>(QU<V>()))>>>u;for(H&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qz{u[i]=f(s,x);}} M u;}};L<w F,w S>P H accum_unordered_map_by(F f,o S&s){M accum_unordered_map_by_<F,S>{f,s};}L<w S>P H accum_unordered_map(o S&s=S()){M accum_unordered_map_by(_2,s);}L<w U,Q...Is>P Q6 any_different_(o U&x,o U&y,Qg<Is...>){M((Qo<Is>(x)!=Qo<Is>(y))||...);}L<Q N,w X>P B QW(X&it){if Qw(N>=1){++Qo<N-1>(it.its);if(not(Qo<N-1>(it.its)!=Z(Qo<N-1>(*it.my_vs_ptr)))){Qo<N-1>(it.its)=d(Qo<N-1>(*it.my_vs_ptr));QW<N-1>(it);}} Qz{it.its=QH([](H&&...xs){M q(Z(xs)...);},*it.my_vs_ptr);}} L<w...Ts>H QK(Ts&&...vs){H QL=std::make_shared<q<QB<Q8<Ts>,Qe<Ts>,Ts>...>>(vs...);Qf(q<W(d(QU<QB<Q8<Ts>,Qe<Ts>,Ts>>()))...>its;W(QL)my_vs_ptr;,{M any_different_(its,E.its,std::index_sequence_for<Ts...>{});},{QW<sizeof...(Ts)>(*QI);M*QI;},{M QH([](H&&...xs){M q<W(*xs)...>(*xs...);},its);}) if(QH([](H&&...xs){M((xs>is_nil)||...);},*QL)){M Q7(X{QH([](H&&...xs){M q(Z(xs)...);},*QL),QL},X{QH([](H&&...xs){M q(Z(xs)...);},*QL),QL});}Qz{M Q7(X{QH([](H&&...xs){M q(d(xs)...);},*QL),QL},X{QH([](H&&...xs){M q(Z(xs)...);},*QL),QL});}};L<w...Ts>P H cartesian_product_range(o Ts&...n){M QK(Qv(n)...);}L<Q n,w I>P H cartesian_power(o I&v){M QH([](o H&...vs){M QK(vs...);},tuple_many_of<n>(v));}k{A QZ=B;int n=-1;L<w T>H O()(T&&v)o{if Qw(std::is_convertible_v<T,int>){H x=*QI;x.n=v;M x;}Qz{H vec=v>Qc;int m=vec.size();k X{int n;W(vec)Qy;QC<Q>cycles;Q6 a;Q6 O!=(o X&E)o{M a xor E.a;}X&O++(){for(H i:Qv(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=Qy.size()-i;std::rotate(Qy.begin()+i,Qy.begin()+i+1,Qy.end());}Qz{std::swap(Qy[i],Qy[Qy.size()-cycles[i]]);M*QI;}} a=z;M*QI;}H O*()o{M Qy>array_slice(0,n);}};int n1=(n<0)?(m):(n);M Q7(X{n1,Qu(vec),Qv(m,m-n1,-1)>QJ(FF(x,Q(x)))>Qc,QG},X{n1,{},{},z});}}}permutations;k combinations_impl{A QZ=B;int n;L<w T>H O()(T&&v)o{H vec=v>Qc;int m=vec.size();Qf(int n;W(vec)Qy;QC<Q>idx;Q6 a;,{M a xor E.a;},{for(H i:Qv(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(H j:Qv(i+1,n)){idx[j]=idx[j-1]+1;}M*QI;}} a=z;M*QI;},{M idx>array_slice(0,n)>QJ(FF(i,Qy[i]));}) M Q7(X{n,Qu(vec),Qv(0,m)>QJ(FF(x,Q(x)))>Qc,QG},X{n,{},{},z});}};P H combinations(int n){M combinations_impl{n};}k Qm{A QZ=B;int n;L<w T>H O()(T&&v)o{H vec=v>Qc;int m=vec.size();Qf(int n;W(vec)Qy;QC<Q>idx;Q6 a;,{M a xor E.a;},{for(H i:Qv(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(H j:Qv(i+1,n)){idx[j]=idx[i];}M*QI;}} a=z;M*QI;},{M idx>array_slice(0,n)>QJ(FF(i,Qy[i]));}) M Q7(X{n,Qu(vec),Q(0)>replicate(m)>Qc,QG},X{n,{},{},z});}};P H combinations_with_replacement(int n){M Qm{n};}L<w T>P H istream_iterable(std::istream&in){Qf(std::istream&in;QQ T val;Q6 a;QQ Q6 has_read;,{M a xor E.a;},{if(not(in>>val)){a=z;}M*QI;},{if(not has_read){has_read=z;in>>val;}M val;}) M Q7(X{in,T{},QG,QG},X{in,T{},z,z});}L<w T>P H input=istream_iterable<T>(std::cin);L<w T>QS&print_iterable(QS&out,o T&v,o std::string&sep= " "){for(H it=d(v);it!=Z(v);){ out<<*it;++it;if(it!=Z(v)){out<<sep;}Qz{M out;}} M out;}L<w T,w=w T::is_iterable_wrapper>P QS&O<<(QS&out,o T&v){out<< "[";M print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)L<w...Ts>QS&O<<(QS&out,o I<Ts...>&v){M out<<Q7(v);}
Qd(QC)Qd(std::map)Qd(std::unordered_map)Qd(std::set)Qd(std::unordered_set)L<Q n,w T>k QF{A type=QC<w QF<n-1,T>::type>;static H make(o Qa<n,Q>&sz,o T&val=T()){M QC(Qk(sz),QF<n-1,T>::make(Qj(sz),val));}};L<w T>k QF<1,T>{A type=QC<T>;static H make(o q<Q>&sz,o T&val=T()){M QC(Qk(sz),val);}};L<Q n,w T>A nested_vector=w QF<n,T>::type;L<Q n,w T>H make_nested_vector(o Qa<n,Q>&sz,o T&val=T()){M QF<n,T>::make(sz,val);}L<Q n,w T>P H Q0(o T&v){if Qw(n==1){M q(v.size());}Qz{M std::tuple_cat(q(v.size()),Q0<n-1>(v[0]));}} L<Q n,w T>P H nested_vector_indices(o T&v){M QH([&](H...x){M cartesian_product_range(x...);},Q0<n>(v));}L<Q n,w T>P W(H)Qp(o QC<T>&v,o Qa<n,Q>&i){if Qw(n==1){M v[Qk(i)];}Qz{M Qp<n-1>(v[Qk(i)],Qj(i));}} L<Q n,w T>P W(H)Qp(QC<T>&v,o Qa<n,Q>&i){if Qw(n==1){M v[Qk(i)];}Qz{M Qp<n-1>(v[Qk(i)],Qj(i));}} L<w U,Q i,Q s>QS&Qq(QS&out,o U&u){if Qw(i==0){out<< "{ ";}out<<Qo<i>(u);if Qw(i+1<s){out<< ", ";M Qq<U,i+1,s>(out,u);}Qz{M out<< " }";}} L<w...Ts>QS&O<<(QS&out,o q<Ts...>&u){M Qq<W(u),0,sizeof...(Ts)>(out,u);}L<w T,w S>QS&O<<(QS&out,o std::pair<T,S>&p){M out<<q(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(QG);std::cin.tie(0);std::cout.tie(0);
#define END }
A namespace std;A LL=long long;BEGIN int R,C;cin>>R>>C;if(C==1){if(R==1){cout<<0<< "\n";M 0;}for(int r=0;r<R;++r){cout<<(r+2)<< "\n";}} Qz{for(int c=0;c<C;++c){cout<<(c+2)<< " ";}cout<< "\n";for(int r=1;r<R;++r){for(int c=0;c<C;++c){cout<<((r+C+1)*(c+2))<< " ";}cout<< "\n";}} END