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
#define Z std::end
#define QB tuple_many_of_t
#define Ql std::ostream
#define P Iterator
#define Qk iter
#define QJ else
#define Qm std::move
#define Qx tuple_tail
#define QG is_composable_
#define Q3 implicit_lambda_binary_operator
#define Q9 combinations_with_replacement_impl
#define QU cartesian_product
#define Qn def_iterator_manip_iter
#define QF implicit_lambda_unary_operator
#define O decltype
#define QP vs_ptr
#define A return
#define Qj this
#define QA nested_vector_size
#define QT advance
#define E other
#define Q6 ostream_tuple_helper_
#define Qh bool
#define QO j_end
#define Qo has_updated
#define Q0 std::remove_reference_t
#define QH __arg3__
#define Qb std::get
#define QR std::vector
#define QI tuple_many_of
#define z template
#define q inline
#define M std::begin
#define Q2 to_vector
#define QE iterable_wrapper
#define Qf std::decay_t
#define QQ it_end
#define Qw jv_ptr
#define QC std::tuple_element_t
#define QX def_iterable_ostream
#define Qy __arg2__
#define QD range
#define R auto
#define QW to_nested_vector_impl
#define Qz std::make_index_sequence
#define X std::tuple
#define Qi is_composable_v
#define QZ std::invoke_result_t
#define Qg std::declval
#define Qv tuple_head
#define Y is_end
#define Q7 cartesian_product_incr_
#define Q1 my_v
#define Qs std::index_sequence
#define QS std::forward
#define k typename
#define QV nested_vector_at
#define Qp container_carrying_iterator
#define d void
#define Qt std::conditional_t
#define Qc has_advanced
#define Q8 false
#define L constexpr
#define Qd __tuple__
#define QY k_ptr
#define H operator
#define Qr std::apply
#define a const
#define B using
#define Q4 nested_vector_impl
#define QL std::shared_ptr
#define Q5 apply
#define Qe __expr1__
#define QK iterator_macro
#define Q struct
#define Qu std::is_rvalue_reference_v
#define Qa implicit_lambda
#define W true
#define w size_t
#define o __arg1__
#define Qq mutable

z<k T,w>B ignore_second=T;z<w...Ix,k T>R tuple_many_of_impl(Qs<Ix...>,a T&x){A X(ignore_second<T,Ix>(x)...);}z<w n,k T>R QI(a T&x){A tuple_many_of_impl(Qz<n>{},x);}z<w n,k T>B QB=O(QI<n,T>(Qg<T>()));z<k...Args>R Qv(a X<Args...>&t){A Qb<0>(t);}z<w...Ix,k...Args>R tuple_tail_impl(Qs<Ix...>,a X<Args...>&t){A X(Qb<Ix+1>(t)...);}z<k...Args>R Qx(a X<Args...>&t){A tuple_tail_impl(Qz<sizeof...(Args)-1>{},t);}Q empty_t{};L empty_t empty_v;z<k T1,k T2>std::common_type_t<T1,T2>maxx(a T1&x,a T2&y){if(x<y){A y;}QJ{A x;}} z<k T1,k T2,k...Ts>q R maxx(a T1&x,a T2&y,a Ts&...xs){A maxx(maxx(x,y),xs...);}z<k T1,k T2>R minn(a T1&x,a T2&y){if(x<=y){A x;}QJ{A y;}} z<k T1,k T2,k...Ts>q R minn(a T1&x,a T2&y,a Ts&...xs){A minn(minn(x,y),xs...);}L int _log2(int x){if(x==0){A 0;}A 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&]()->O(R){A f;}
#define FF_1(o,f)[&](R&&o)->O(R){(d)o;A f;}
#define FF_2(o,Qy,f)[&](R&&o,R&&Qy)->O(R){(d)o;(d)Qy;A f;}
#define FF_3(o,Qy,QH,f)[&](R&&o,R&&Qy,R&&QH)->O(R){(d)o;(d)Qy;(d)QH;A f;}
#define FF_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c]()->O(R){A f;}
#define FC_1(o,f,c)[&,c](R&&o)->O(R){(d)o;A f;}
#define FC_2(o,Qy,f,c)[&,c](R&&o,R&&Qy)->O(R){(d)o;(d)Qy;A f;}
#define FC_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2]()->O(R){A f;}
#define FC2_1(o,f,c1,c2)[&,c1,c2](R&&o)->O(R){(d)o;A f;}
#define FC2_2(o,Qy,f,c1,c2)[&,c1,c2](R&&o,R&&Qy)->O(R){(d)o;(d)Qy;A f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(o,f)[&](R&&Qd)->O(R){R&[o]=Qd;(d)o;A f;}
#define FT_2(o,Qy,f)[&](R&&Qd)->O(R){R&[o,Qy]=Qd;(d)o;(d)Qy;A f;}
#define FT_3(o,Qy,QH,f)[&](R&&Qd)->O(R){R&[o,Qy,QH]=Qd;(d)o;(d)Qy;(d)QH;A f;}
#define FT_4(o,Qy,QH,__arg4__,f)[&](R&&Qd)->O(R){R&[o,Qy,QH,__arg4__]=Qd;(d)o;(d)Qy;(d)QH;(d)__arg4__;A f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Qe,f)[&](){R&&Qe;A f;}()
#define LET_2(Qe,__expr2__,f)[&](){R&&Qe;R&&__expr2__;A f;}()
#define LET_3(Qe,__expr2__,__expr3__,f)[&](){R&&Qe;R&&__expr2__;R&&__expr3__;A f;}()
#define LET_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)L Q{B QG=d;templ q O(R)H()args a code}name;
z<k F>class Qa{private:F f;public:Qa(F f_):f(f_){} z<k...Ts>L R H()(Ts&&...xs)a{A f(QS<Ts>(xs)...);}};Qa _([](R&&x)->Qt<Qu<O(x)>,Q0<O(x)>,O(x)>{A x;});Qa _1([](R&&x,R&&)->Qt<Qu<O(x)>,Q0<O(x)>,O(x)>{A x;});Qa _2([](R&&,R&&y)->Qt<Qu<O(y)>,Q0<O(y)>,O(y)>{A y;});
#define implicit_lambda_unary_operator(op)z<k F>L O(R)H op(Qa<F>f){A Qa([=](R&&...xs){A op f(QS<O(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)z<k F,k T>L O(R)H op(Qa<F>f,a T&y){A Qa([=](R&&...xs){A f(QS<O(xs)>(xs)...)op y;});}z<k F,k T>L O(R)H op(a T&y,Qa<F>f){A Qa([=](R&&...xs){A y op f(QS<O(xs)>(xs)...);});}z<k F,k G>L O(R)H op(Qa<F>f,Qa<G>g){A Qa([=](R&&...xs){A f(QS<O(xs)>(xs)...)op g(QS<O(xs)>(xs)...);});}
QF(+)QF(-)QF(!)QF(~)QF(*)QF(&)Q3(+)Q3(-)Q3(*)Q3(/)Q3(%)Q3(<)Q3(>)Q3(<=)Q3(>=)Q3(==)Q3(!=)Q3(<<)Q3(>>)Q3(&)Q3(|)Q3(^)Q3(&&)z<k T,k=d>Q is_composable:public std::false_type{};z<k T>Q is_composable<T,std::void_t<k T::is_composable_>>:public std::true_type{};z<k T>L Qh Qi=is_composable<T>::value;z<k T,k F,k=QZ<F,T>>O(R)H>(T&&v,a F&f){A f(QS<T>(v));}z<k M1,k M2>Q composed{B QG=d;a M1 m1;a M2 m2;z<k T>O(R)H()(T&&v)a{A m1(m2(QS<T>(v)));}};z<k M1,k M2,k=std::enable_if_t<Qi<M1>or Qi<M2>>>q R H<(a M1&m1,a M2&m2){A composed<M1,M2>{m1,m2};}z<w n>Q nth_impl{B QG=d;z<k...Ts>L QC<n,X<Ts...>>&H()(X<Ts...>&u)a{A Qb<n>(u);}z<k...Ts>L QC<n,X<Ts...>>H()(X<Ts...>&&u)a{A Qb<n>(u);}z<k...Ts>L a QC<n,X<Ts...>>&H()(a X<Ts...>&u)a{A Qb<n>(u);}z<k...Ts>L a QC<n,X<Ts...>>H()(a X<Ts...>&&u)a{A Qb<n>(u);}};z<w n>L nth_impl<n>nth;L nth_impl<0>fst;L nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)Q P{extra Qh H!=(a P&E)a neq P&H++()incr O(R)H*()a val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,QQ,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{QK(extra extra_it Qq I it;,neq_it,incr_it,val_it);A QE(it_begin,QQ);})
#define def_iterator_manip_2(name,code)L Q{B QG=d;z<k T,k I=O(M(Qg<T>())),k V=Qf<O(*Qg<I>())>>O(R)H()(T&&v)a code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ Q name##_impl{B QG=d;extra z<k T,k I=O(M(Qg<T>())),k V=Qf<O(*Qg<I>())>>O(R)H()(T&&v)a code};templ q O(R)name args{A name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
z<k T,k=d>Q is_iterable:public std::false_type{};z<k T>Q is_iterable<T,std::void_t<O(M(Qg<T>())),O(Z(Qg<T>()))>>:public std::true_type{};z<k T>L Qh is_iterable_v=is_iterable<T>::value;z<k I>q R QE(a I&b,a I&e){Q Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
B is_iterable_wrapper=d;B iterator=I;B value_type=Qf<O(*Qg<I>())>;
#pragma GCC diagnostic pop
I b,e;R begin()a{A b;}R end()a{A e;}};A Wrapper{b,e};}z<k T>q R Qk(T&&iterable){A QE(M(QS<T>(iterable)),Z(QS<T>(iterable)));}z<k I>q R Qk(a I&b,a I&e){A QE(b,e);}z<k C>Q Qp:public C::iterator{QL<C>p;Qp(QL<C>p_,k C::iterator it):C::iterator(it),p(p_){}};z<k C>q R iterc(C&&v){B D=Qf<C>;QL<D>p(new D(QS<C>(v)));A QE(Qp<D>{p,M(*p)},Qp<D>{p,Z(*p)});}z<k T>q R Qk(std::initializer_list<T>l){A iterc(QR<T>(l));}def_template_lambda(z<k T>,Q2,(T&&v),{QR<k Qf<T>::value_type>s;for(R&&x:v){s.push_back(x);}A s;})z<w n>Q QW{z<k T>q static R make(T&&v){A QS<T>(v)>Q5(FF(u,QW<n-1>::make(u)))>Q2;}};z<>Q QW<1>{z<k T>q static R make(T&&v){A QS<T>(v)>Q2;}};z<w n>Q to_nested_vector_{B QG=d;z<k T>q O(R)H()(T&&v)a{A QW<n>::make(QS<T>(v));}};z<w n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(w l,w r),({l,r}),w l;w r;,{A Qk(M(v)+l,M(v)+r);})def_iterator_manip(is_nil,{A not(M(v)!=Z(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{w l=0;for(R i=M(v);i!=Z(v);++i){++l;}A l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
z<k T1,k T2,k T3,k T=std::make_signed_t<O(T1()+T2()+T3())>>q R QD(a T1&b,a T2&e,a T3&step){QK(T x;T e;T step;q Qh Y()a{A(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{A Y()xor E.Y();},{x+=step;A*Qj;},{A T(x);}) A Qk(P{b,e,step},P{e,e,step});}z<k T1,k T2>q R QD(a T1&b,a T2&e){A QD(b,e,O(T1()+T2())(1));}z<k T>q R QD(a T&e){A QD(T(),e,T(1));} 
#pragma GCC diagnostic pop
z<k T>q R to_infinity(a T&b=0,a T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
QK(T x;T step;,{(d)E;A W;},{x+=step;A*Qj;},{A T(x);}) A Qk(P{b,step},P{b,step});
#pragma GCC diagnostic pop
}Qn(Q5,z<k F>,(F f),<F>{f},F f;,(P{f,M(v)}),(P{f,Z(v)}),,{ A it!=E.it;},{++it;A*Qj;},{A f(*it);}) Qn(take,,(w n),{n},w n;,(P{n,M(v)}),(P{0,Z(v)}),,{ A n!=E.n;},{--n;if(n>0){++it;}A*Qj;},{A*it;}) Qn(take_while,z<k F>,(F f),<F>{f},F f;,(P{f,not(M(v)!=Z(v)and f(*M(v))),M(v)}),(P{f,W,Z(v)}),Qh Y;,{A Y xor E.Y;},{++it;if(not f(*it)){Y=W;}A*Qj;},{A*it;}) Qn(drop,,(w n),{n},Qq w n;,(P{n,Z(v),M(v)}),(P{0,Z(v),Z(v)}),a I end_it;q d QT()a{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{QT();E.QT();A it!=E.it;},{QT();++it;A*Qj;},{QT();A*it;}) Qn(drop_while,z<k F>,(F f),<F>{f},F f;,(P{f,Z(v),Q8,M(v)}),(P{f,Z(v),W,Z(v)}),a I end_it;Qq Qh Qc;q d QT()a{if(not Qc){while(it!=end_it and f(*it)){++it;}Qc=W;}},{QT();E.QT();A it!=E.it;},{QT();++it;A*Qj;},{QT();A*it;}) def_iterator_manip(head,{A*M(v);})q R tail=drop(1);q R at(w n){A head<drop(n);}Qn(cons,z<k S>,(S s),<S>{s},S s;,(P{s,W,M(v)}),(P{s,Q8,Z(v)}),Qh is_s;,{A is_s!=E.is_s or it!=E.it;},{if(is_s){is_s=Q8;}QJ{++it;}A*Qj;},{A(is_s)?(s):(*it);}) def_iterator_manip(snoc,{R it=M(v);R h=*it;++it;A X(h,Qk(it,Z(v)));})def_iterator_manip(split_at,,(w n),{n},w n;,{R it=M(v);QR<T>u;for(R i:QD(n)){u.push_back(*it);++it;}A X(iterc(Qm(u)),Qk(it,Z(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
Qn(chunks_of,,(w n),{n},w n;,(P{n,{},Q8,Z(v),M(v)}),(P{n,{},Q8,Z(v),Z(v)}),Qq QR<V>u;Qq Qh Qo;I QQ;d update()a{u.clear();Qo=W;for(R i:QD(n)){if(it!=QQ){u.push_back(*it);++it;}QJ{break;}}},{A it!=E.it;},{if(Qo){Qo=Q8;}QJ{for(R i:QD(n)){if(it!=QQ){++it;}QJ{break;}}}A*Qj;},{if(not Qo){update();}A iterc(u);})
#pragma GCC diagnostic pop
z<k F,k S>Q fold_impl{B QG=d;F f;S s;z<k T>R H()(a T&v)a{R x=s;for(R y:v){x=f(x,y);}A x;}};z<k F,k S>q R fold(F f,a S&s){A fold_impl<F,S>{f,s};}def_iterator_manip(fold1,z<k F>,(F f),<F>{f},F f;,{R u=v>snoc;A u>snd>fold(f,u>fst);})def_iterator_manip(sum,{A v>fold(_1+_2,V(0));})def_iterator_manip(product,{A v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,z<k F>,(F f),<F>{f},F f;,{A v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{A v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,z<k F>,(F f),<F>{f},F f;,{A v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,z<k F>,(F f),<F>{f},F f;,{A v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{A v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,z<k F>,(F f),<F>{f},F f;,{A v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})z<k F,k S>Q scan_impl{B QG=d;F f;S s;z<k T,k I=O(M(Qg<T>()))>O(R)H()(T&&v)a{QK(F f;Qq S s;Qq Qh Qo;Qh Qc;Qq I it;,{A it!=E.it;},{if(not Qo){s=f(s,*it);};Qo=Q8;if(Qc){++it;}QJ{Qc=W;}A*Qj;},{if(not Qo){Qo=W;s=f(s,*it);}A s;}) A Qk(P{f,s,W,Q8,M(QS<T>(v))},P{f,s,W,W,Z(QS<T>(v))});}};z<k F,k S>q R scan(F f,a S&s){A scan_impl<F,S>{f,s};}Qn(scan1,z<k F>,(F f),<F>{f},F f;,(P{f,*M(v),W,M(v)}),(P{f,*M(v),W,Z(v)}),Qq V s;Qq Qh Qo;,{A it!=E.it;},{if(not Qo){s=f(s,*it);};Qo=Q8;++it;A*Qj;},{if(not Qo){Qo=W;s=f(s,*it);}A s;}) z<k T,k S,k I=O(M(Qg<T>())),k J=O(M(Qg<S>()))>q R H+(T&&v,S&&u){QK(I i;I i_end;J j;Qh in_i;,{A i!=E.i or j!=E.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=Q8;}}QJ{++j;}A*Qj;},{A(in_i)?(*i):(*j);}) I bv=M(v);I ev=Z(v);J bu=M(u);J eu=Z(u);A Qk(P{bv,ev,bu,bv!=ev},P{ev,ev,eu,Q8});}L Q{B QG=d;z<k T>R H()(T&&v)a{R u=QS<T>(v)>filter(FF(i,not is_nil(i)));R b=M(u);R e=Z(u);B J=O(b);B V=Qf<O(*b)>;B K=O(M(*b));Q P{J j;J QO;QL<V>Qw;K*QY;Qh Y;P(J j,J QO,a V&jv,Qh Y):j(j),QO(QO),Qw(new V(jv)),QY(new K(M(*Qw))),Y(Y){} P(J j,J QO,Qh Y):j(j),QO(QO),Qw(nullptr),QY(nullptr),Y(Y){} P(a P&E):j(E.j),QO(E.QO),Qw(E.Qw),QY((E.QY)?(new K(*E.QY)):nullptr),Y(E.Y){} P(P&&E):j(E.j),QO(E.QO),Qw(E.Qw),QY((E.QY)?(new K(*E.QY)):nullptr),Y(E.Y){}~P(){delete QY;}Qh H!=(a P&E)a{A Y xor E.Y;}P&H++(){++*QY;if(not(*QY!=Z(*Qw))){++j;if(j!=QO){delete QY;Qw=std::make_shared<V>(*j);QY=new K(M(*Qw));}QJ{Y=W;}} A*Qj;}O(R)H*()a{A**QY;}};if(u>is_nil){A QE(P(b,e,W),P(b,e,W));}QJ{A QE(P(b,e,*b,Q8),P(e,e,W));}}}flatten;z<k T,k F,k=std::enable_if_t<is_iterable_v<T>>>R H>=(T&&v,F f){A v>Q5(f)>flatten;}z<k U,w...Is>q Qh all_different_(a U&x,a U&y,Qs<Is...>){A((Qb<Is>(x)!=Qb<Is>(y))&&...);}z<k F,k...Ts>q R zip_with(F f,Ts&&...vs){QK(F f;X<O(M(Qg<Ts>()))...>its;,{A all_different_(its,E.its,std::index_sequence_for<Ts...>{});},{Qr([&](R&&...xs){(++xs,...);},its);A*Qj;},{A Qr([&](R&&...xs){A f(*xs...);},its);}) A Qk(P{f,X(M(vs)...)},P{f,X(Z(vs)...)});};Q zip_default_function_{z<k...Ts>O(R)H()(Ts&&...xs)a{A X<Ts...>(QS<Ts>(xs)...);}};z<k...Ts>q R zip(Ts&&...vs){A zip_with(zip_default_function_{},QS<Ts>(vs)...);}Qn(filter,z<k F>,(F f),<F>{f},F f;,(P{f,Z(v),M(v)}),(P{f,Z(v),Z(v)}),a I end_it;q d QT()a{while(it!=end_it and not f(*it)){++it;}},{QT();E.QT();A it!=E.it;},{QT();++it;A*Qj;},{QT();A*it;}) def_template_lambda(z<k T>,repeat,(T&&v),{Q P{a Qf<T>v;Qh H!=(a P&)a{A W;}P&H++(){A*Qj;}a R&H*()a{A v;}};A Qk(P{v},P{v});})q R replicate(w n){A take(n)<repeat;}q R cycle=flatten<repeat;def_iterator_manip(enumerate,{A zip(to_infinity(w(0)),v);})def_iterator_manip(reversed,{R s=v>Q2;std::reverse(s.begin(),s.end());A iterc(Qm(s));})def_iterator_manip(sorted_by,z<k F>,(F f),<F>{f},F f;,{R s=v>Q2;std::sort(M(s),Z(s),f);A iterc(Qm(s));})def_iterator_manip(sorted,{A v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,z<k F>,(F f),<F>{f},F f;,{A v>Q5(FF(i,X(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>Q5(fst);})def_iterator_manip(nub,{QK(I QQ;I it;,{A it!=E.it;},{O(*it)pr;do{pr=*it;++it;}while(it!=QQ and pr==*it);A*Qj;},{A*it;}) R b=M(v);R e=Z(v);A Qk(P{e,b},P{e,e});})z<k F,k S>Q accum_vector_by_{B QG=d;w n;F f;S s;z<k T,k I=O(M(Qg<T>())),k V=Qf<O(*Qg<I>())>>O(R)H()(a T&v)a{QR<Qf<QZ<F,S,O(Qb<1>(Qg<V>()))>>>u(n,s);for(R&&[i,x]:v){u[i]=f(u[i],x);}A u;}};z<k F,k S>q R accum_vector_by(w n,F f,a S&s){A accum_vector_by_<F,S>{n,f,s};}z<k S>q R accum_vector(w n,a S&s=S()){A accum_vector_by(n,_2,s);}z<k F,k S>Q accum_map_by_{B QG=d;F f;S s;z<k T,k I=O(M(Qg<T>())),k V=Qf<O(*Qg<I>())>>O(R)H()(a T&v)a{std::map<Qf<O(Qb<0>(Qg<V>()))>,Qf<QZ<F,S,O(Qb<1>(Qg<V>()))>>>u;for(R&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QJ{u[i]=f(s,x);}} A u;}};z<k F,k S>q R accum_map_by(F f,a S&s){A accum_map_by_<F,S>{f,s};}z<k S>q R accum_map(a S&s=S()){A accum_map_by(_2,s);}z<k F,k S>Q accum_unordered_map_by_{B QG=d;F f;S s;z<k T,k I=O(M(Qg<T>())),k V=Qf<O(*Qg<I>())>>O(R)H()(a T&v)a{std::unordered_map<Qf<O(Qb<0>(Qg<V>()))>,Qf<QZ<F,S,O(Qb<1>(Qg<V>()))>>>u;for(R&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QJ{u[i]=f(s,x);}} A u;}};z<k F,k S>q R accum_unordered_map_by(F f,a S&s){A accum_unordered_map_by_<F,S>{f,s};}z<k S>q R accum_unordered_map(a S&s=S()){A accum_unordered_map_by(_2,s);}z<k U,w...Is>q Qh any_different_(a U&x,a U&y,Qs<Is...>){A((Qb<Is>(x)!=Qb<Is>(y))||...);}z<w N,k P>q d Q7(P&it){if L(N>=1){++Qb<N-1>(it.its);if(not(Qb<N-1>(it.its)!=Z(Qb<N-1>(*it.my_vs_ptr)))){Qb<N-1>(it.its)=M(Qb<N-1>(*it.my_vs_ptr));Q7<N-1>(it);}} QJ{it.its=Qr([](R&&...xs){A X(Z(xs)...);},*it.my_vs_ptr);}} z<k...Ts>R QU(Ts&&...vs){R QP=std::make_shared<X<Qt<Qu<Ts>,Q0<Ts>,Ts>...>>(vs...);QK(X<O(M(Qg<Qt<Qu<Ts>,Q0<Ts>,Ts>>()))...>its;O(QP)my_vs_ptr;,{A any_different_(its,E.its,std::index_sequence_for<Ts...>{});},{Q7<sizeof...(Ts)>(*Qj);A*Qj;},{A Qr([](R&&...xs){A X<O(*xs)...>(*xs...);},its);}) if(Qr([](R&&...xs){A((xs>is_nil)||...);},*QP)){A Qk(P{Qr([](R&&...xs){A X(Z(xs)...);},*QP),QP},P{Qr([](R&&...xs){A X(Z(xs)...);},*QP),QP});}QJ{A Qk(P{Qr([](R&&...xs){A X(M(xs)...);},*QP),QP},P{Qr([](R&&...xs){A X(Z(xs)...);},*QP),QP});}};z<k...Ts>q R cartesian_product_range(a Ts&...n){A QU(QD(n)...);}z<w n,k I>q R cartesian_power(a I&v){A Qr([](a R&...vs){A QU(vs...);},QI<n>(v));}Q{B QG=d;int n=-1;z<k T>R H()(T&&v)a{if L(std::is_convertible_v<T,int>){R x=*Qj;x.n=v;A x;}QJ{R vec=v>Q2;int m=vec.size();Q P{int n;O(vec)Q1;QR<w>cycles;Qh Y;Qh H!=(a P&E)a{A Y xor E.Y;}P&H++(){for(R i:QD(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=Q1.size()-i;std::rotate(Q1.begin()+i,Q1.begin()+i+1,Q1.end());}QJ{std::swap(Q1[i],Q1[Q1.size()-cycles[i]]);A*Qj;}} Y=W;A*Qj;}R H*()a{A Q1>array_slice(0,n);}};int n1=(n<0)?(m):(n);A Qk(P{n1,Qm(vec),QD(m,m-n1,-1)>Q5(FF(x,w(x)))>Q2,Q8},P{n1,{},{},W});}}}permutations;Q combinations_impl{B QG=d;int n;z<k T>R H()(T&&v)a{R vec=v>Q2;int m=vec.size();QK(int n;O(vec)Q1;QR<w>idx;Qh Y;,{A Y xor E.Y;},{for(R i:QD(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(R j:QD(i+1,n)){idx[j]=idx[j-1]+1;}A*Qj;}} Y=W;A*Qj;},{A idx>array_slice(0,n)>Q5(FF(i,Q1[i]));}) A Qk(P{n,Qm(vec),QD(0,m)>Q5(FF(x,w(x)))>Q2,Q8},P{n,{},{},W});}};q R combinations(int n){A combinations_impl{n};}Q Q9{B QG=d;int n;z<k T>R H()(T&&v)a{R vec=v>Q2;int m=vec.size();QK(int n;O(vec)Q1;QR<w>idx;Qh Y;,{A Y xor E.Y;},{for(R i:QD(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(R j:QD(i+1,n)){idx[j]=idx[i];}A*Qj;}} Y=W;A*Qj;},{A idx>array_slice(0,n)>Q5(FF(i,Q1[i]));}) A Qk(P{n,Qm(vec),w(0)>replicate(m)>Q2,Q8},P{n,{},{},W});}};q R combinations_with_replacement(int n){A Q9{n};}z<k T>q R istream_iterable(std::istream&in){QK(std::istream&in;Qq T val;Qh Y;Qq Qh has_read;,{A Y xor E.Y;},{if(not(in>>val)){Y=W;}A*Qj;},{if(not has_read){has_read=W;in>>val;}A val;}) A Qk(P{in,T{},Q8,Q8},P{in,T{},W,W});}z<k T>q R input=istream_iterable<T>(std::cin);z<k T>Ql&print_iterable(Ql&out,a T&v,a std::string&sep= " "){for(R it=M(v);it!=Z(v);){ out<<*it;++it;if(it!=Z(v)){out<<sep;}QJ{A out;}} A out;}z<k T,k=k T::is_iterable_wrapper>q Ql&H<<(Ql&out,a T&v){out<< "[";A print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)z<k...Ts>Ql&H<<(Ql&out,a I<Ts...>&v){A out<<Qk(v);}
QX(QR)QX(std::map)QX(std::unordered_map)QX(std::set)QX(std::unordered_set)z<w n,k T>Q Q4{B type=QR<k Q4<n-1,T>::type>;static R make(a QB<n,w>&sz,a T&val=T()){A QR(Qv(sz),Q4<n-1,T>::make(Qx(sz),val));}};z<k T>Q Q4<1,T>{B type=QR<T>;static R make(a X<w>&sz,a T&val=T()){A QR(Qv(sz),val);}};z<w n,k T>B nested_vector=k Q4<n,T>::type;z<w n,k T>R make_nested_vector(a QB<n,w>&sz,a T&val=T()){A Q4<n,T>::make(sz,val);}z<w n,k T>q R QA(a T&v){if L(n==1){A X(v.size());}QJ{A std::tuple_cat(X(v.size()),QA<n-1>(v[0]));}} z<w n,k T>q R nested_vector_indices(a T&v){A Qr([&](R...x){A cartesian_product_range(x...);},QA<n>(v));}z<w n,k T>q O(R)QV(a QR<T>&v,a QB<n,w>&i){if L(n==1){A v[Qv(i)];}QJ{A QV<n-1>(v[Qv(i)],Qx(i));}} z<w n,k T>q O(R)QV(QR<T>&v,a QB<n,w>&i){if L(n==1){A v[Qv(i)];}QJ{A QV<n-1>(v[Qv(i)],Qx(i));}} z<k U,w i,w s>Ql&Q6(Ql&out,a U&u){if L(i==0){out<< "{ ";}out<<Qb<i>(u);if L(i+1<s){out<< ", ";A Q6<U,i+1,s>(out,u);}QJ{A out<< " }";}} z<k...Ts>Ql&H<<(Ql&out,a X<Ts...>&u){A Q6<O(u),0,sizeof...(Ts)>(out,u);}z<k T,k S>Ql&H<<(Ql&out,a std::pair<T,S>&p){A out<<X(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(Q8);std::cin.tie(0);std::cout.tie(0);
#define END }
B namespace std;B LL=long long;L int MOD=1000000007;BEGIN int n,m;cin>>n>>m;if(n>m){swap(n,m);}vector<LL>fib(m+10,0);fib[1]=1;for(R i:QD(2,m+2)){fib[i]=(fib[i-1]+fib[i-2])%MOD;}cout<<((2*(fib[m+1]+fib[n+1]-1))%MOD)<< "\n";END