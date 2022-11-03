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
#define Q3 __arg3__
#define Qv range
#define E is_end
#define Qa __tuple__
#define QG is_composable_v
#define Qh __arg2__
#define Qg implicit_lambda_binary_operator
#define QO to_nested_vector_impl
#define QZ std::shared_ptr
#define QM tuple_many_of_t
#define QA std::tuple_element_t
#define QX std::apply
#define z std::end
#define QL std::vector
#define Qd iter
#define Qn std::declval
#define QK vs_ptr
#define B Iterator
#define QS advance
#define Qb mutable
#define Q8 iterator_macro
#define Q7 bool
#define QB nested_vector_at
#define H const
#define M struct
#define QI std::forward
#define Qu cartesian_product_incr_
#define Qy jv_ptr
#define Qt j_end
#define Qq tuple_many_of
#define Qm push_back
#define QV std::is_rvalue_reference_v
#define P decltype
#define QU nested_vector_impl
#define a size_t
#define Qc __expr1__
#define W std::tuple
#define QC is_composable_
#define k operator
#define QY iterable_wrapper
#define QT ostream_tuple_helper_
#define o other
#define QJ to_vector
#define q void
#define Qx def_iterable_ostream
#define d true
#define Q6 std::invoke_result_t
#define O return
#define X using
#define Qf step
#define QE std::move
#define Y inline
#define QF container_carrying_iterator
#define QR my_v
#define QQ false
#define Q0 it_end
#define Q1 apply
#define QN implicit_lambda_unary_operator
#define Q9 def_iterator_manip_iter
#define Q2 cartesian_product
#define Qe std::get
#define R typename
#define Qp has_advanced
#define Qo std::decay_t
#define Qz constexpr
#define Qi this
#define Z auto
#define QP tuple_tail
#define L template
#define Qr combinations_with_replacement_impl
#define Qj std::ostream
#define Q4 has_updated
#define QW std::conditional_t
#define w __arg1__
#define Qk else
#define Qw tuple_head
#define QD implicit_lambda
#define Ql std::remove_reference_t
#define Qs k_ptr
#define Q std::begin
#define QH std::index_sequence
#define Q5 nested_vector_size

L<R T,a>X ignore_second=T;L<a...Ix,R T>Z tuple_many_of_impl(QH<Ix...>,H T&x){O W(ignore_second<T,Ix>(x)...);}L<a n,R T>Z Qq(H T&x){O tuple_many_of_impl(std::make_index_sequence<n>{},x);}L<a n,R T>X QM=P(Qq<n,T>(Qn<T>()));L<R...Args>Z Qw(H W<Args...>&t){O Qe<0>(t);}L<a...Ix,R...Args>Z tuple_tail_impl(QH<Ix...>,H W<Args...>&t){O W(Qe<Ix+1>(t)...);}L<R...Args>Z QP(H W<Args...>&t){O tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}M empty_t{};Qz empty_t empty_v;L<R T1,R T2>std::common_type_t<T1,T2>maxx(H T1&x,H T2&y){if(x<y){O y;}Qk{O x;}} L<R T1,R T2,R...Ts>Y Z maxx(H T1&x,H T2&y,H Ts&...xs){O maxx(maxx(x,y),xs...);}L<R T1,R T2>Z minn(H T1&x,H T2&y){if(x<=y){O x;}Qk{O y;}} L<R T1,R T2,R...Ts>Y Z minn(H T1&x,H T2&y,H Ts&...xs){O minn(minn(x,y),xs...);}Qz int _log2(int x){if(x==0){O 0;}O 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&]()->P(Z){O f;}
#define FF_1(w,f)[&](Z&&w)->P(Z){(q)w;O f;}
#define FF_2(w,Qh,f)[&](Z&&w,Z&&Qh)->P(Z){(q)w;(q)Qh;O f;}
#define FF_3(w,Qh,Q3,f)[&](Z&&w,Z&&Qh,Z&&Q3)->P(Z){(q)w;(q)Qh;(q)Q3;O f;}
#define FF_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c]()->P(Z){O f;}
#define FC_1(w,f,c)[&,c](Z&&w)->P(Z){(q)w;O f;}
#define FC_2(w,Qh,f,c)[&,c](Z&&w,Z&&Qh)->P(Z){(q)w;(q)Qh;O f;}
#define FC_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2]()->P(Z){O f;}
#define FC2_1(w,f,c1,c2)[&,c1,c2](Z&&w)->P(Z){(q)w;O f;}
#define FC2_2(w,Qh,f,c1,c2)[&,c1,c2](Z&&w,Z&&Qh)->P(Z){(q)w;(q)Qh;O f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(w,f)[&](Z&&Qa)->P(Z){Z&[w]=Qa;(q)w;O f;}
#define FT_2(w,Qh,f)[&](Z&&Qa)->P(Z){Z&[w,Qh]=Qa;(q)w;(q)Qh;O f;}
#define FT_3(w,Qh,Q3,f)[&](Z&&Qa)->P(Z){Z&[w,Qh,Q3]=Qa;(q)w;(q)Qh;(q)Q3;O f;}
#define FT_4(w,Qh,Q3,__arg4__,f)[&](Z&&Qa)->P(Z){Z&[w,Qh,Q3,__arg4__]=Qa;(q)w;(q)Qh;(q)Q3;(q)__arg4__;O f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Qc,f)[&](){Z&&Qc;O f;}()
#define LET_2(Qc,__expr2__,f)[&](){Z&&Qc;Z&&__expr2__;O f;}()
#define LET_3(Qc,__expr2__,__expr3__,f)[&](){Z&&Qc;Z&&__expr2__;Z&&__expr3__;O f;}()
#define LET_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)Qz M{X QC=q;templ Y P(Z)k()args H code}name;
L<R F>class QD{private:F f;public:QD(F f_):f(f_){} L<R...Ts>Qz Z k()(Ts&&...xs)H{O f(QI<Ts>(xs)...);}};QD _([](Z&&x)->QW<QV<P(x)>,Ql<P(x)>,P(x)>{O x;});QD _1([](Z&&x,Z&&)->QW<QV<P(x)>,Ql<P(x)>,P(x)>{O x;});QD _2([](Z&&,Z&&y)->QW<QV<P(y)>,Ql<P(y)>,P(y)>{O y;});
#define implicit_lambda_unary_operator(op)L<R F>Qz P(Z)k op(QD<F>f){O QD([=](Z&&...xs){O op f(QI<P(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)L<R F,R T>Qz P(Z)k op(QD<F>f,H T&y){O QD([=](Z&&...xs){O f(QI<P(xs)>(xs)...)op y;});}L<R F,R T>Qz P(Z)k op(H T&y,QD<F>f){O QD([=](Z&&...xs){O y op f(QI<P(xs)>(xs)...);});}L<R F,R G>Qz P(Z)k op(QD<F>f,QD<G>g){O QD([=](Z&&...xs){O f(QI<P(xs)>(xs)...)op g(QI<P(xs)>(xs)...);});}
QN(+)QN(-)QN(!)QN(~)QN(*)QN(&)Qg(+)Qg(-)Qg(*)Qg(/)Qg(%)Qg(<)Qg(>)Qg(<=)Qg(>=)Qg(==)Qg(!=)Qg(<<)Qg(>>)Qg(&)Qg(|)Qg(^)Qg(&&)L<R T,R=q>M is_composable:public std::false_type{};L<R T>M is_composable<T,std::void_t<R T::is_composable_>>:public std::true_type{};L<R T>Qz Q7 QG=is_composable<T>::value;L<R T,R F,R=Q6<F,T>>P(Z)k>(T&&v,H F&f){O f(QI<T>(v));}L<R M1,R M2>M composed{X QC=q;H M1 m1;H M2 m2;L<R T>P(Z)k()(T&&v)H{O m1(m2(QI<T>(v)));}};L<R M1,R M2,R=std::enable_if_t<QG<M1>or QG<M2>>>Y Z k<(H M1&m1,H M2&m2){O composed<M1,M2>{m1,m2};}L<a n>M nth_impl{X QC=q;L<R...Ts>Qz QA<n,W<Ts...>>&k()(W<Ts...>&u)H{O Qe<n>(u);}L<R...Ts>Qz QA<n,W<Ts...>>k()(W<Ts...>&&u)H{O Qe<n>(u);}L<R...Ts>Qz H QA<n,W<Ts...>>&k()(H W<Ts...>&u)H{O Qe<n>(u);}L<R...Ts>Qz H QA<n,W<Ts...>>k()(H W<Ts...>&&u)H{O Qe<n>(u);}};L<a n>Qz nth_impl<n>nth;Qz nth_impl<0>fst;Qz nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)M B{extra Q7 k!=(H B&o)H neq B&k++()incr P(Z)k*()H val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,Q0,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{Q8(extra extra_it Qb I it;,neq_it,incr_it,val_it);O QY(it_begin,Q0);})
#define def_iterator_manip_2(name,code)Qz M{X QC=q;L<R T,R I=P(Q(Qn<T>())),R V=Qo<P(*Qn<I>())>>P(Z)k()(T&&v)H code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ M name##_impl{X QC=q;extra L<R T,R I=P(Q(Qn<T>())),R V=Qo<P(*Qn<I>())>>P(Z)k()(T&&v)H code};templ Y P(Z)name args{O name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
L<R T,R=q>M is_iterable:public std::false_type{};L<R T>M is_iterable<T,std::void_t<P(Q(Qn<T>())),P(z(Qn<T>()))>>:public std::true_type{};L<R T>Qz Q7 is_iterable_v=is_iterable<T>::value;L<R I>Y Z QY(H I&b,H I&e){M Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
X is_iterable_wrapper=q;X iterator=I;X value_type=Qo<P(*Qn<I>())>;
#pragma GCC diagnostic pop
I b,e;Z begin()H{O b;}Z end()H{O e;}};O Wrapper{b,e};}L<R T>Y Z Qd(T&&iterable){O QY(Q(QI<T>(iterable)),z(QI<T>(iterable)));}L<R I>Y Z Qd(H I&b,H I&e){O QY(b,e);}L<R C>M QF:public C::iterator{QZ<C>p;QF(QZ<C>p_,R C::iterator it):C::iterator(it),p(p_){}};L<R C>Y Z iterc(C&&v){X D=Qo<C>;QZ<D>p(new D(QI<C>(v)));O QY(QF<D>{p,Q(*p)},QF<D>{p,z(*p)});}L<R T>Y Z Qd(std::initializer_list<T>l){O iterc(QL<T>(l));}def_template_lambda(L<R T>,QJ,(T&&v),{QL<R Qo<T>::value_type>s;for(Z&&x:v){s.Qm(x);}O s;})L<a n>M QO{L<R T>Y static Z make(T&&v){O QI<T>(v)>Q1(FF(u,QO<n-1>::make(u)))>QJ;}};L<>M QO<1>{L<R T>Y static Z make(T&&v){O QI<T>(v)>QJ;}};L<a n>M to_nested_vector_{X QC=q;L<R T>Y P(Z)k()(T&&v)H{O QO<n>::make(QI<T>(v));}};L<a n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(a l,a r),({l,r}),a l;a r;,{O Qd(Q(v)+l,Q(v)+r);})def_iterator_manip(is_nil,{O not(Q(v)!=z(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{a l=0;for(Z i=Q(v);i!=z(v);++i){++l;}O l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
L<R T1,R T2,R T3,R T=std::make_signed_t<P(T1()+T2()+T3())>>Y Z Qv(H T1&b,H T2&e,H T3&Qf){Q8(T x;T e;T Qf;Y Q7 E()H{O(Qf>=T(0)and x>=e)or(Qf<T(0)and x<=e);},{O E()xor o.E();},{x+=Qf;O*Qi;},{O T(x);}) O Qd(B{b,e,Qf},B{e,e,Qf});}L<R T1,R T2>Y Z Qv(H T1&b,H T2&e){O Qv(b,e,P(T1()+T2())(1));}L<R T>Y Z Qv(H T&e){O Qv(T(),e,T(1));} 
#pragma GCC diagnostic pop
L<R T>Y Z to_infinity(H T&b=0,H T&Qf=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
Q8(T x;T Qf;,{(q)o;O d;},{x+=Qf;O*Qi;},{O T(x);}) O Qd(B{b,Qf},B{b,Qf});
#pragma GCC diagnostic pop
}Q9(Q1,L<R F>,(F f),<F>{f},F f;,(B{f,Q(v)}),(B{f,z(v)}),,{ O it!=o.it;},{++it;O*Qi;},{O f(*it);}) Q9(take,,(a n),{n},a n;,(B{n,Q(v)}),(B{0,z(v)}),,{ O n!=o.n;},{--n;if(n>0){++it;}O*Qi;},{O*it;}) Q9(take_while,L<R F>,(F f),<F>{f},F f;,(B{f,not(Q(v)!=z(v)and f(*Q(v))),Q(v)}),(B{f,d,z(v)}),Q7 E;,{O E xor o.E;},{++it;if(not f(*it)){E=d;}O*Qi;},{O*it;}) Q9(drop,,(a n),{n},Qb a n;,(B{n,z(v),Q(v)}),(B{0,z(v),z(v)}),H I end_it;Y q QS()H{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{QS();o.QS();O it!=o.it;},{QS();++it;O*Qi;},{QS();O*it;}) Q9(drop_while,L<R F>,(F f),<F>{f},F f;,(B{f,z(v),QQ,Q(v)}),(B{f,z(v),d,z(v)}),H I end_it;Qb Q7 Qp;Y q QS()H{if(not Qp){while(it!=end_it and f(*it)){++it;}Qp=d;}},{QS();o.QS();O it!=o.it;},{QS();++it;O*Qi;},{QS();O*it;}) def_iterator_manip(head,{O*Q(v);})Y Z tail=drop(1);Y Z at(a n){O head<drop(n);}Q9(cons,L<R S>,(S s),<S>{s},S s;,(B{s,d,Q(v)}),(B{s,QQ,z(v)}),Q7 is_s;,{O is_s!=o.is_s or it!=o.it;},{if(is_s){is_s=QQ;}Qk{++it;}O*Qi;},{O(is_s)?(s):(*it);}) def_iterator_manip(snoc,{Z it=Q(v);Z h=*it;++it;O W(h,Qd(it,z(v)));})def_iterator_manip(split_at,,(a n),{n},a n;,{Z it=Q(v);QL<T>u;for(Z i:Qv(n)){u.Qm(*it);++it;}O W(iterc(QE(u)),Qd(it,z(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
Q9(chunks_of,,(a n),{n},a n;,(B{n,{},QQ,z(v),Q(v)}),(B{n,{},QQ,z(v),z(v)}),Qb QL<V>u;Qb Q7 Q4;I Q0;q update()H{u.clear();Q4=d;for(Z i:Qv(n)){if(it!=Q0){u.Qm(*it);++it;}Qk{break;}}},{O it!=o.it;},{if(Q4){Q4=QQ;}Qk{for(Z i:Qv(n)){if(it!=Q0){++it;}Qk{break;}}}O*Qi;},{if(not Q4){update();}O iterc(u);})
#pragma GCC diagnostic pop
L<R F,R S>M fold_impl{X QC=q;F f;S s;L<R T>Z k()(H T&v)H{Z x=s;for(Z y:v){x=f(x,y);}O x;}};L<R F,R S>Y Z fold(F f,H S&s){O fold_impl<F,S>{f,s};}def_iterator_manip(fold1,L<R F>,(F f),<F>{f},F f;,{Z u=v>snoc;O u>snd>fold(f,u>fst);})def_iterator_manip(sum,{O v>fold(_1+_2,V(0));})def_iterator_manip(product,{O v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,L<R F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{O v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,L<R F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,L<R F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{O v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,L<R F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})L<R F,R S>M scan_impl{X QC=q;F f;S s;L<R T,R I=P(Q(Qn<T>()))>P(Z)k()(T&&v)H{Q8(F f;Qb S s;Qb Q7 Q4;Q7 Qp;Qb I it;,{O it!=o.it;},{if(not Q4){s=f(s,*it);};Q4=QQ;if(Qp){++it;}Qk{Qp=d;}O*Qi;},{if(not Q4){Q4=d;s=f(s,*it);}O s;}) O Qd(B{f,s,d,QQ,Q(QI<T>(v))},B{f,s,d,d,z(QI<T>(v))});}};L<R F,R S>Y Z scan(F f,H S&s){O scan_impl<F,S>{f,s};}Q9(scan1,L<R F>,(F f),<F>{f},F f;,(B{f,*Q(v),d,Q(v)}),(B{f,*Q(v),d,z(v)}),Qb V s;Qb Q7 Q4;,{O it!=o.it;},{if(not Q4){s=f(s,*it);};Q4=QQ;++it;O*Qi;},{if(not Q4){Q4=d;s=f(s,*it);}O s;}) L<R T,R S,R I=P(Q(Qn<T>())),R J=P(Q(Qn<S>()))>Y Z k+(T&&v,S&&u){Q8(I i;I i_end;J j;Q7 in_i;,{O i!=o.i or j!=o.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=QQ;}}Qk{++j;}O*Qi;},{O(in_i)?(*i):(*j);}) I bv=Q(v);I ev=z(v);J bu=Q(u);J eu=z(u);O Qd(B{bv,ev,bu,bv!=ev},B{ev,ev,eu,QQ});}Qz M{X QC=q;L<R T>Z k()(T&&v)H{Z u=QI<T>(v)>filter(FF(i,not is_nil(i)));Z b=Q(u);Z e=z(u);X J=P(b);X V=Qo<P(*b)>;X K=P(Q(*b));M B{J j;J Qt;QZ<V>Qy;K*Qs;Q7 E;B(J j,J Qt,H V&jv,Q7 E):j(j),Qt(Qt),Qy(new V(jv)),Qs(new K(Q(*Qy))),E(E){} B(J j,J Qt,Q7 E):j(j),Qt(Qt),Qy(nullptr),Qs(nullptr),E(E){} B(H B&o):j(o.j),Qt(o.Qt),Qy(o.Qy),Qs((o.Qs)?(new K(*o.Qs)):nullptr),E(o.E){} B(B&&o):j(o.j),Qt(o.Qt),Qy(o.Qy),Qs((o.Qs)?(new K(*o.Qs)):nullptr),E(o.E){}~B(){delete Qs;}Q7 k!=(H B&o)H{O E xor o.E;}B&k++(){++*Qs;if(not(*Qs!=z(*Qy))){++j;if(j!=Qt){delete Qs;Qy=std::make_shared<V>(*j);Qs=new K(Q(*Qy));}Qk{E=d;}} O*Qi;}P(Z)k*()H{O**Qs;}};if(u>is_nil){O QY(B(b,e,d),B(b,e,d));}Qk{O QY(B(b,e,*b,QQ),B(e,e,d));}}}flatten;L<R T,R F,R=std::enable_if_t<is_iterable_v<T>>>Z k>=(T&&v,F f){O v>Q1(f)>flatten;}L<R U,a...Is>Y Q7 all_different_(H U&x,H U&y,QH<Is...>){O((Qe<Is>(x)!=Qe<Is>(y))&&...);}L<R F,R...Ts>Y Z zip_with(F f,Ts&&...vs){Q8(F f;W<P(Q(Qn<Ts>()))...>its;,{O all_different_(its,o.its,std::index_sequence_for<Ts...>{});},{QX([&](Z&&...xs){(++xs,...);},its);O*Qi;},{O QX([&](Z&&...xs){O f(*xs...);},its);}) O Qd(B{f,W(Q(vs)...)},B{f,W(z(vs)...)});};M zip_default_function_{L<R...Ts>P(Z)k()(Ts&&...xs)H{O W<Ts...>(QI<Ts>(xs)...);}};L<R...Ts>Y Z zip(Ts&&...vs){O zip_with(zip_default_function_{},QI<Ts>(vs)...);}Q9(filter,L<R F>,(F f),<F>{f},F f;,(B{f,z(v),Q(v)}),(B{f,z(v),z(v)}),H I end_it;Y q QS()H{while(it!=end_it and not f(*it)){++it;}},{QS();o.QS();O it!=o.it;},{QS();++it;O*Qi;},{QS();O*it;}) def_template_lambda(L<R T>,repeat,(T&&v),{M B{H Qo<T>v;Q7 k!=(H B&)H{O d;}B&k++(){O*Qi;}H Z&k*()H{O v;}};O Qd(B{v},B{v});})Y Z replicate(a n){O take(n)<repeat;}Y Z cycle=flatten<repeat;def_iterator_manip(enumerate,{O zip(to_infinity(a(0)),v);})def_iterator_manip(reversed,{Z s=v>QJ;std::reverse(s.begin(),s.end());O iterc(QE(s));})def_iterator_manip(sorted_by,L<R F>,(F f),<F>{f},F f;,{Z s=v>QJ;std::sort(Q(s),z(s),f);O iterc(QE(s));})def_iterator_manip(sorted,{O v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,L<R F>,(F f),<F>{f},F f;,{O v>Q1(FF(i,W(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>Q1(fst);})def_iterator_manip(nub,{Q8(I Q0;I it;,{O it!=o.it;},{P(*it)pr;do{pr=*it;++it;}while(it!=Q0 and pr==*it);O*Qi;},{O*it;}) Z b=Q(v);Z e=z(v);O Qd(B{e,b},B{e,e});})L<R F,R S>M accum_vector_by_{X QC=q;a n;F f;S s;L<R T,R I=P(Q(Qn<T>())),R V=Qo<P(*Qn<I>())>>P(Z)k()(H T&v)H{QL<Qo<Q6<F,S,P(Qe<1>(Qn<V>()))>>>u(n,s);for(Z&&[i,x]:v){u[i]=f(u[i],x);}O u;}};L<R F,R S>Y Z accum_vector_by(a n,F f,H S&s){O accum_vector_by_<F,S>{n,f,s};}L<R S>Y Z accum_vector(a n,H S&s=S()){O accum_vector_by(n,_2,s);}L<R F,R S>M accum_map_by_{X QC=q;F f;S s;L<R T,R I=P(Q(Qn<T>())),R V=Qo<P(*Qn<I>())>>P(Z)k()(H T&v)H{std::map<Qo<P(Qe<0>(Qn<V>()))>,Qo<Q6<F,S,P(Qe<1>(Qn<V>()))>>>u;for(Z&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qk{u[i]=f(s,x);}} O u;}};L<R F,R S>Y Z accum_map_by(F f,H S&s){O accum_map_by_<F,S>{f,s};}L<R S>Y Z accum_map(H S&s=S()){O accum_map_by(_2,s);}L<R F,R S>M accum_unordered_map_by_{X QC=q;F f;S s;L<R T,R I=P(Q(Qn<T>())),R V=Qo<P(*Qn<I>())>>P(Z)k()(H T&v)H{std::unordered_map<Qo<P(Qe<0>(Qn<V>()))>,Qo<Q6<F,S,P(Qe<1>(Qn<V>()))>>>u;for(Z&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qk{u[i]=f(s,x);}} O u;}};L<R F,R S>Y Z accum_unordered_map_by(F f,H S&s){O accum_unordered_map_by_<F,S>{f,s};}L<R S>Y Z accum_unordered_map(H S&s=S()){O accum_unordered_map_by(_2,s);}L<R U,a...Is>Y Q7 any_different_(H U&x,H U&y,QH<Is...>){O((Qe<Is>(x)!=Qe<Is>(y))||...);}L<a N,R B>Y q Qu(B&it){if Qz(N>=1){++Qe<N-1>(it.its);if(not(Qe<N-1>(it.its)!=z(Qe<N-1>(*it.my_vs_ptr)))){Qe<N-1>(it.its)=Q(Qe<N-1>(*it.my_vs_ptr));Qu<N-1>(it);}} Qk{it.its=QX([](Z&&...xs){O W(z(xs)...);},*it.my_vs_ptr);}} L<R...Ts>Z Q2(Ts&&...vs){Z QK=std::make_shared<W<QW<QV<Ts>,Ql<Ts>,Ts>...>>(vs...);Q8(W<P(Q(Qn<QW<QV<Ts>,Ql<Ts>,Ts>>()))...>its;P(QK)my_vs_ptr;,{O any_different_(its,o.its,std::index_sequence_for<Ts...>{});},{Qu<sizeof...(Ts)>(*Qi);O*Qi;},{O QX([](Z&&...xs){O W<P(*xs)...>(*xs...);},its);}) if(QX([](Z&&...xs){O((xs>is_nil)||...);},*QK)){O Qd(B{QX([](Z&&...xs){O W(z(xs)...);},*QK),QK},B{QX([](Z&&...xs){O W(z(xs)...);},*QK),QK});}Qk{O Qd(B{QX([](Z&&...xs){O W(Q(xs)...);},*QK),QK},B{QX([](Z&&...xs){O W(z(xs)...);},*QK),QK});}};L<R...Ts>Y Z cartesian_product_range(H Ts&...n){O Q2(Qv(n)...);}L<a n,R I>Y Z cartesian_power(H I&v){O QX([](H Z&...vs){O Q2(vs...);},Qq<n>(v));}M{X QC=q;int n=-1;L<R T>Z k()(T&&v)H{if Qz(std::is_convertible_v<T,int>){Z x=*Qi;x.n=v;O x;}Qk{Z vec=v>QJ;int m=vec.size();M B{int n;P(vec)QR;QL<a>cycles;Q7 E;Q7 k!=(H B&o)H{O E xor o.E;}B&k++(){for(Z i:Qv(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=QR.size()-i;std::rotate(QR.begin()+i,QR.begin()+i+1,QR.end());}Qk{std::swap(QR[i],QR[QR.size()-cycles[i]]);O*Qi;}} E=d;O*Qi;}Z k*()H{O QR>array_slice(0,n);}};int n1=(n<0)?(m):(n);O Qd(B{n1,QE(vec),Qv(m,m-n1,-1)>Q1(FF(x,a(x)))>QJ,QQ},B{n1,{},{},d});}}}permutations;M combinations_impl{X QC=q;int n;L<R T>Z k()(T&&v)H{Z vec=v>QJ;int m=vec.size();Q8(int n;P(vec)QR;QL<a>idx;Q7 E;,{O E xor o.E;},{for(Z i:Qv(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(Z j:Qv(i+1,n)){idx[j]=idx[j-1]+1;}O*Qi;}} E=d;O*Qi;},{O idx>array_slice(0,n)>Q1(FF(i,QR[i]));}) O Qd(B{n,QE(vec),Qv(0,m)>Q1(FF(x,a(x)))>QJ,QQ},B{n,{},{},d});}};Y Z combinations(int n){O combinations_impl{n};}M Qr{X QC=q;int n;L<R T>Z k()(T&&v)H{Z vec=v>QJ;int m=vec.size();Q8(int n;P(vec)QR;QL<a>idx;Q7 E;,{O E xor o.E;},{for(Z i:Qv(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(Z j:Qv(i+1,n)){idx[j]=idx[i];}O*Qi;}} E=d;O*Qi;},{O idx>array_slice(0,n)>Q1(FF(i,QR[i]));}) O Qd(B{n,QE(vec),a(0)>replicate(m)>QJ,QQ},B{n,{},{},d});}};Y Z combinations_with_replacement(int n){O Qr{n};}L<R T>Y Z istream_iterable(std::istream&in){Q8(std::istream&in;Qb T val;Q7 E;Qb Q7 has_read;,{O E xor o.E;},{if(not(in>>val)){E=d;}O*Qi;},{if(not has_read){has_read=d;in>>val;}O val;}) O Qd(B{in,T{},QQ,QQ},B{in,T{},d,d});}L<R T>Y Z input=istream_iterable<T>(std::cin);L<R T>Qj&print_iterable(Qj&out,H T&v,H std::string&sep= " "){for(Z it=Q(v);it!=z(v);){ out<<*it;++it;if(it!=z(v)){out<<sep;}Qk{O out;}} O out;}L<R T,R=R T::is_iterable_wrapper>Y Qj&k<<(Qj&out,H T&v){out<< "[";O print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)L<R...Ts>Qj&k<<(Qj&out,H I<Ts...>&v){O out<<Qd(v);}
Qx(QL)Qx(std::map)Qx(std::unordered_map)Qx(std::set)Qx(std::unordered_set)L<a n,R T>M QU{X type=QL<R QU<n-1,T>::type>;static Z make(H QM<n,a>&sz,H T&val=T()){O QL(Qw(sz),QU<n-1,T>::make(QP(sz),val));}};L<R T>M QU<1,T>{X type=QL<T>;static Z make(H W<a>&sz,H T&val=T()){O QL(Qw(sz),val);}};L<a n,R T>X nested_vector=R QU<n,T>::type;L<a n,R T>Z make_nested_vector(H QM<n,a>&sz,H T&val=T()){O QU<n,T>::make(sz,val);}L<a n,R T>Y Z Q5(H T&v){if Qz(n==1){O W(v.size());}Qk{O std::tuple_cat(W(v.size()),Q5<n-1>(v[0]));}} L<a n,R T>Y Z nested_vector_indices(H T&v){O QX([&](Z...x){O cartesian_product_range(x...);},Q5<n>(v));}L<a n,R T>Y P(Z)QB(H QL<T>&v,H QM<n,a>&i){if Qz(n==1){O v[Qw(i)];}Qk{O QB<n-1>(v[Qw(i)],QP(i));}} L<a n,R T>Y P(Z)QB(QL<T>&v,H QM<n,a>&i){if Qz(n==1){O v[Qw(i)];}Qk{O QB<n-1>(v[Qw(i)],QP(i));}} L<R U,a i,a s>Qj&QT(Qj&out,H U&u){if Qz(i==0){out<< "{ ";}out<<Qe<i>(u);if Qz(i+1<s){out<< ", ";O QT<U,i+1,s>(out,u);}Qk{O out<< " }";}} L<R...Ts>Qj&k<<(Qj&out,H W<Ts...>&u){O QT<P(u),0,sizeof...(Ts)>(out,u);}L<R T,R S>Qj&k<<(Qj&out,H std::pair<T,S>&p){O out<<W(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(QQ);std::cin.tie(0);std::cout.tie(0);
#define END }
X namespace std;X LL=long long;BEGIN int N;cin>>N;Z A=input<LL>>take(N)>QJ;Z s=A>sum;vector<LL>primes;for(LL p=2;p*p<=s;++p){if((s%p)==0){primes.Qm(p);while((s%p)==0){s/=p;}}}if(s>1){primes.Qm(s);}if(primes>is_nil){cout<<-1<< "\n";O 0;}Z ans=primes>Q1(FF(p,A>scan((_1+_2)%p,0LL)>Q1(FF(x,minn(x,p-x)))>sum))>minimum;cout<<ans<< "\n";END