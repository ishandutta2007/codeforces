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
#define QW has_updated
#define QO implicit_lambda
#define QX def_iterator_manip_iter
#define QZ std::remove_reference_t
#define Qd std::index_sequence
#define Qz nested_vector_at
#define Q7 combinations_with_replacement_impl
#define Qt ostream_tuple_helper_
#define Ql cartesian_product_incr_
#define Z size_t
#define w Iterator
#define QM this
#define O typename
#define A template
#define QQ tuple_many_of_t
#define Qk std::is_rvalue_reference_v
#define Q6 using
#define Q5 k_ptr
#define QF __arg2__
#define QU std::vector
#define QN implicit_lambda_binary_operator
#define Qu jv_ptr
#define QB std::conditional_t
#define Qj j_end
#define q return
#define Qh range
#define QP iter
#define Qg std::decay_t
#define QV to_vector
#define QC true
#define o decltype
#define Q9 size
#define QA false
#define QT __arg3__
#define QL std::invoke_result_t
#define Qf std::forward
#define Y __arg1__
#define Qw GET_5TH_ARG
#define Qc push_back
#define QI int
#define Qp std::shared_ptr
#define a std::end
#define QD to_nested_vector_impl
#define Qy is_composable_
#define Qm std::ostream
#define Qs iterable_wrapper
#define Qq tuple_head
#define z operator
#define Qv std::declval
#define Q4 vs_ptr
#define Qn std::tuple
#define P std::begin
#define QK bool
#define QS std::tuple_element_t
#define Qr std::apply
#define Qi else
#define QJ def_iterable_ostream
#define QH __expr1__
#define Qa constexpr
#define Qb mutable
#define Q8 nested_vector_size
#define Q3 container_carrying_iterator
#define QY std::move
#define H const
#define E auto
#define k void
#define Qo implicit_lambda_unary_operator
#define B other
#define Qe nested_vector_impl
#define Q inline
#define Q0 has_advanced
#define QG advance
#define Q1 struct
#define W is_end
#define Q2 iterator_macro
#define Qx cartesian_product
#define QR std::get
#define QE __tuple__

A<O T,Z>Q6 ignore_second=T;A<Z...Ix,O T>E tuple_many_of_impl(Qd<Ix...>,H T&x){q Qn(ignore_second<T,Ix>(x)...);}A<Z n,O T>E tuple_many_of(H T&x){q tuple_many_of_impl(std::make_index_sequence<n>{},x);}A<Z n,O T>Q6 QQ=o(tuple_many_of<n,T>(Qv<T>()));A<O...Args>E Qq(H Qn<Args...>&t){q QR<0>(t);}A<Z...Ix,O...Args>E tuple_tail_impl(Qd<Ix...>,H Qn<Args...>&t){q Qn(QR<Ix+1>(t)...);}A<O...Args>E tuple_tail(H Qn<Args...>&t){q tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}Q1 empty_t{};Qa empty_t empty_v;A<O T1,O T2>std::common_type_t<T1,T2>maxx(H T1&x,H T2&y){if(x<y){q y;}Qi{q x;}} A<O T1,O T2,O...Ts>Q E maxx(H T1&x,H T2&y,H Ts&...xs){q maxx(maxx(x,y),xs...);}A<O T1,O T2>E minn(H T1&x,H T2&y){if(x<=y){q x;}Qi{q y;}} A<O T1,O T2,O...Ts>Q E minn(H T1&x,H T2&y,H Ts&...xs){q minn(minn(x,y),xs...);}Qa QI _log2(QI x){if(x==0){q 0;}q 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){q f;}
#define FF_1(Y,f)[&](E&&Y){(k)Y;q f;}
#define FF_2(Y,QF,f)[&](E&&Y,E&&QF){(k)Y;(k)QF;q f;}
#define FF_3(Y,QF,QT,f)[&](E&&Y,E&&QF,E&&QT){(k)Y;(k)QF;(k)QT;q f;}
#define FF_macro_chooser(...)Qw(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->E&{q f;}
#define FREF_1(Y,f)[&](E&&Y)->E&{(k)Y;q f;}
#define FREF_2(Y,QF,f)[&](E&&Y,E&&QF)->E&{(k)Y;(k)QF;q f;}
#define FREF_3(Y,QF,QT,f)[&](E&&Y,E&&QF,E&&QT)->E&{(k)Y;(k)QF;(k)QT;q f;}
#define FREF_macro_chooser(...)Qw(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){q f;}
#define FC_1(Y,f,c)[&,c](E&&Y){(k)Y;q f;}
#define FC_2(Y,QF,f,c)[&,c](E&&Y,E&&QF){(k)Y;(k)QF;q f;}
#define FC_macro_chooser(...)Qw(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){q f;}
#define FC2_1(Y,f,c1,c2)[&,c1,c2](E&&Y){(k)Y;q f;}
#define FC2_2(Y,QF,f,c1,c2)[&,c1,c2](E&&Y,E&&QF){(k)Y;(k)QF;q f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(Y,f)[&](E&&QE){E&[Y]=QE;(k)Y;q f;}
#define FT_2(Y,QF,f)[&](E&&QE){E&[Y,QF]=QE;(k)Y;(k)QF;q f;}
#define FT_3(Y,QF,QT,f)[&](E&&QE){E&[Y,QF,QT]=QE;(k)Y;(k)QF;(k)QT;q f;}
#define FT_4(Y,QF,QT,__arg4__,f)[&](E&&QE){E&[Y,QF,QT,__arg4__]=QE;(k)Y;(k)QF;(k)QT;(k)__arg4__;q f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(QH,f)[&](){E&&QH;q f;}()
#define LET_2(QH,__expr2__,f)[&](){E&&QH;E&&__expr2__;q f;}()
#define LET_3(QH,__expr2__,__expr3__,f)[&](){E&&QH;E&&__expr2__;E&&__expr3__;q f;}()
#define LET_macro_chooser(...)Qw(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)Qa Q1{Q6 Qy=k;templ Q o(E)z()args H code}name;
A<O F>class QO{private:F f;public:QO(F f_):f(f_){} A<O...Ts>Qa E z()(Ts&&...xs)H{q f(Qf<Ts>(xs)...);}};QO _([](E&&x)->QB<Qk<o(x)>,QZ<o(x)>,o(x)>{q x;});QO _1([](E&&x,E&&)->QB<Qk<o(x)>,QZ<o(x)>,o(x)>{q x;});QO _2([](E&&,E&&y)->QB<Qk<o(y)>,QZ<o(y)>,o(y)>{q y;});
#define implicit_lambda_unary_operator(op)A<O F>Qa o(E)z op(QO<F>f){q QO([=](E&&...xs){q op f(Qf<o(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)A<O F,O T>Qa o(E)z op(QO<F>f,H T&y){q QO([=](E&&...xs){q f(Qf<o(xs)>(xs)...)op y;});}A<O F,O T>Qa o(E)z op(H T&y,QO<F>f){q QO([=](E&&...xs){q y op f(Qf<o(xs)>(xs)...);});}A<O F,O G>Qa o(E)z op(QO<F>f,QO<G>g){q QO([=](E&&...xs){q f(Qf<o(xs)>(xs)...)op g(Qf<o(xs)>(xs)...);});}
Qo(+)Qo(-)Qo(!)Qo(~)Qo(*)Qo(&)QN(+)QN(-)QN(*)QN(/)QN(%)QN(<)QN(>)QN(<=)QN(>=)QN(==)QN(!=)QN(<<)QN(>>)QN(&)QN(|)QN(^)QN(&&)A<O T,O=k>Q1 is_composable:public std::false_type{};A<O T>Q1 is_composable<T,std::void_t<O T::is_composable_>>:public std::true_type{};A<O T>Qa QK is_composable_v=is_composable<T>::value;A<O T,O F,O=QL<F,T>>o(E)z>(T&&v,H F&f){q f(Qf<T>(v));}A<O M1,O M2>Q1 composed{Q6 Qy=k;H M1 m1;H M2 m2;A<O T>o(E)z()(T&&v)H{q m1(m2(Qf<T>(v)));}};A<O M1,O M2,O=std::enable_if_t<is_composable_v<M1>or is_composable_v<M2>>>Q E z<(H M1&m1,H M2&m2){q composed<M1,M2>{m1,m2};}A<Z n>Q1 nth_impl{Q6 Qy=k;A<O...Ts>Qa QS<n,Qn<Ts...>>&z()(Qn<Ts...>&u)H{q QR<n>(u);}A<O...Ts>Qa QS<n,Qn<Ts...>>z()(Qn<Ts...>&&u)H{q QR<n>(u);}A<O...Ts>Qa H QS<n,Qn<Ts...>>&z()(H Qn<Ts...>&u)H{q QR<n>(u);}A<O...Ts>Qa H QS<n,Qn<Ts...>>z()(H Qn<Ts...>&&u)H{q QR<n>(u);}};A<Z n>Qa nth_impl<n>nth;Qa nth_impl<0>fst;Qa nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)Q1 w{extra QK z!=(H w&B)H neq w&z++()incr o(E)z*()H val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,it_end,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{Q2(extra extra_it Qb I it;,neq_it,incr_it,val_it);q Qs(it_begin,it_end);})
#define def_iterator_manip_2(name,code)Qa Q1{Q6 Qy=k;A<O T,O I=o(P(Qv<T>())),O V=Qg<o(*Qv<I>())>>o(E)z()(T&&v)H code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ Q1 name##_impl{Q6 Qy=k;extra A<O T,O I=o(P(Qv<T>())),O V=Qg<o(*Qv<I>())>>o(E)z()(T&&v)H code};templ Q o(E)name args{q name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
A<O T,O=k>Q1 is_iterable:public std::false_type{};A<O T>Q1 is_iterable<T,std::void_t<o(P(Qv<T>())),o(a(Qv<T>()))>>:public std::true_type{};A<O T>Qa QK is_iterable_v=is_iterable<T>::value;A<O I>Q E Qs(H I&b,H I&e){Q1 Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
Q6 is_iterable_wrapper=k;Q6 iterator=I;Q6 value_type=Qg<o(*Qv<I>())>;
#pragma GCC diagnostic pop
I b,e;E begin()H{q b;}E end()H{q e;}};q Wrapper{b,e};}A<O T>Q E QP(T&&iterable){q Qs(P(Qf<T>(iterable)),a(Qf<T>(iterable)));}A<O I>Q E QP(H I&b,H I&e){q Qs(b,e);}A<O C>Q1 Q3:public C::iterator{Qp<C>p;Q3(Qp<C>p_,O C::iterator it):C::iterator(it),p(p_){}};A<O C>Q E iterc(C&&v){Q6 D=Qg<C>;Qp<D>p(new D(Qf<C>(v)));q Qs(Q3<D>{p,P(*p)},Q3<D>{p,a(*p)});}A<O T>Q E QP(std::initializer_list<T>l){q iterc(QU<T>(l));}def_template_lambda(A<O T>,QV,(T&&v),{QU<O Qg<T>::value_type>s;for(E&&x:v){s.Qc(x);}q s;})A<Z n>Q1 QD{A<O T>Q static E make(T&&v){q Qf<T>(v)>apply(FF(u,QD<n-1>::make(u)))>QV;}};A<>Q1 QD<1>{A<O T>Q static E make(T&&v){q Qf<T>(v)>QV;}};A<Z n>Q1 to_nested_vector_{Q6 Qy=k;A<O T>Q o(E)z()(T&&v)H{q QD<n>::make(Qf<T>(v));}};A<Z n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(Z l,Z r),({l,r}),Z l;Z r;,{q QP(P(v)+l,P(v)+r);})def_iterator_manip(is_nil,{q not(P(v)!=a(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{Z l=0;for(E i=P(v);i!=a(v);++i){++l;}q l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
A<O T1,O T2,O T3,O T=std::make_signed_t<o(T1()+T2()+T3())>>Q E Qh(H T1&b,H T2&e,H T3&step){Q2(T x;T e;T step;Q QK W()H{q(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{q W()xor B.W();},{x+=step;q*QM;},{q T(x);}) q QP(w{b,e,step},w{e,e,step});}A<O T1,O T2>Q E Qh(H T1&b,H T2&e){q Qh(b,e,o(T1()+T2())(1));}A<O T>Q E Qh(H T&e){q Qh(T(),e,T(1));} 
#pragma GCC diagnostic pop
A<O T>Q E to_infinity(H T&b=0,H T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
Q2(T x;T step;,{(k)B;q QC;},{x+=step;q*QM;},{q T(x);}) q QP(w{b,step},w{b,step});
#pragma GCC diagnostic pop
}QX(apply,A<O F>,(F f),<F>{f},F f;,(w{f,P(v)}),(w{f,a(v)}),,{ q it!=B.it;},{++it;q*QM;},{q f(*it);}) QX(take,,(Z n),{n},Z n;,(w{n,P(v)}),(w{0,a(v)}),,{ q n!=B.n;},{--n;if(n>0){++it;}q*QM;},{q*it;}) QX(take_while,A<O F>,(F f),<F>{f},F f;,(w{f,not(P(v)!=a(v)and f(*P(v))),P(v)}),(w{f,QC,a(v)}),QK W;,{q W xor B.W;},{++it;if(not f(*it)){W=QC;}q*QM;},{q*it;}) QX(drop,,(Z n),{n},Qb Z n;,(w{n,a(v),P(v)}),(w{0,a(v),a(v)}),H I end_it;Q k QG()H{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{QG();B.QG();q it!=B.it;},{QG();++it;q*QM;},{QG();q*it;}) QX(drop_while,A<O F>,(F f),<F>{f},F f;,(w{f,a(v),QA,P(v)}),(w{f,a(v),QC,a(v)}),H I end_it;Qb QK Q0;Q k QG()H{if(not Q0){while(it!=end_it and f(*it)){++it;}Q0=QC;}},{QG();B.QG();q it!=B.it;},{QG();++it;q*QM;},{QG();q*it;}) def_iterator_manip(head,{q*P(v);})Q E tail=drop(1);Q E at(Z n){q head<drop(n);}QX(cons,A<O S>,(S s),<S>{s},S s;,(w{s,QC,P(v)}),(w{s,QA,a(v)}),QK is_s;,{q is_s!=B.is_s or it!=B.it;},{if(is_s){is_s=QA;}Qi{++it;}q*QM;},{q(is_s)?(s):(*it);}) def_iterator_manip(snoc,{E it=P(v);E h=*it;++it;q Qn(h,QP(it,a(v)));})def_iterator_manip(split_at,,(Z n),{n},Z n;,{E it=P(v);QU<T>u;for(E i:Qh(n)){u.Qc(*it);++it;}q Qn(iterc(QY(u)),QP(it,a(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
QX(chunks_of,,(Z n),{n},Z n;,(w{n,{},QA,a(v),P(v)}),(w{n,{},QA,a(v),a(v)}),Qb QU<V>u;Qb QK QW;I it_end;k update()H{u.clear();QW=QC;for(E i:Qh(n)){if(it!=it_end){u.Qc(*it);++it;}Qi{break;}}},{q it!=B.it;},{if(QW){QW=QA;}Qi{for(E i:Qh(n)){if(it!=it_end){++it;}Qi{break;}}}q*QM;},{if(not QW){update();}q iterc(u);})
#pragma GCC diagnostic pop
A<O F,O S>Q1 fold_impl{Q6 Qy=k;F f;S s;A<O T>E z()(H T&v)H{E x=s;for(E y:v){x=f(x,y);}q x;}};A<O F,O S>Q E fold(F f,H S&s){q fold_impl<F,S>{f,s};}def_iterator_manip(fold1,A<O F>,(F f),<F>{f},F f;,{E u=v>snoc;q u>snd>fold(f,u>fst);})def_iterator_manip(sum,{q v>fold(_1+_2,V(0));})def_iterator_manip(product,{q v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,A<O F>,(F f),<F>{f},F f;,{q v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{q v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,A<O F>,(F f),<F>{f},F f;,{q v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,A<O F>,(F f),<F>{f},F f;,{q v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{q v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,A<O F>,(F f),<F>{f},F f;,{q v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})A<O F,O S>Q1 scan_impl{Q6 Qy=k;F f;S s;A<O T,O I=o(P(Qv<T>()))>o(E)z()(T&&v)H{Q2(F f;Qb S s;Qb QK QW;QK Q0;Qb I it;,{q it!=B.it;},{if(not QW){s=f(s,*it);};QW=QA;if(Q0){++it;}Qi{Q0=QC;}q*QM;},{if(not QW){QW=QC;s=f(s,*it);}q s;}) q QP(w{f,s,QC,QA,P(Qf<T>(v))},w{f,s,QC,QC,a(Qf<T>(v))});}};A<O F,O S>Q E scan(F f,H S&s){q scan_impl<F,S>{f,s};}QX(scan1,A<O F>,(F f),<F>{f},F f;,(w{f,*P(v),QC,P(v)}),(w{f,*P(v),QC,a(v)}),Qb V s;Qb QK QW;,{q it!=B.it;},{if(not QW){s=f(s,*it);};QW=QA;++it;q*QM;},{if(not QW){QW=QC;s=f(s,*it);}q s;}) A<O T,O S,O I=o(P(Qv<T>())),O J=o(P(Qv<S>()))>Q E z+(T&&v,S&&u){Q2(I i;I i_end;J j;QK in_i;,{q i!=B.i or j!=B.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=QA;}}Qi{++j;}q*QM;},{q(in_i)?(*i):(*j);}) I bv=P(v);I ev=a(v);J bu=P(u);J eu=a(u);q QP(w{bv,ev,bu,bv!=ev},w{ev,ev,eu,QA});}Qa Q1{Q6 Qy=k;A<O T>E z()(T&&v)H{E u=Qf<T>(v)>filter(FF(i,not is_nil(i)));E b=P(u);E e=a(u);Q6 J=o(b);Q6 V=Qg<o(*b)>;Q6 K=o(P(*b));Q1 w{J j;J Qj;Qp<V>Qu;K*Q5;QK W;w(J j,J Qj,H V&jv,QK W):j(j),Qj(Qj),Qu(new V(jv)),Q5(new K(P(*Qu))),W(W){} w(J j,J Qj,QK W):j(j),Qj(Qj),Qu(nullptr),Q5(nullptr),W(W){} w(H w&B):j(B.j),Qj(B.Qj),Qu(B.Qu),Q5((B.Q5)?(new K(*B.Q5)):nullptr),W(B.W){} w(w&&B):j(B.j),Qj(B.Qj),Qu(B.Qu),Q5((B.Q5)?(new K(*B.Q5)):nullptr),W(B.W){}~w(){delete Q5;}QK z!=(H w&B)H{q W xor B.W;}w&z++(){++*Q5;if(not(*Q5!=a(*Qu))){++j;if(j!=Qj){delete Q5;Qu=std::make_shared<V>(*j);Q5=new K(P(*Qu));}Qi{W=QC;}} q*QM;}o(E)z*()H{q**Q5;}};if(u>is_nil){q Qs(w(b,e,QC),w(b,e,QC));}Qi{q Qs(w(b,e,*b,QA),w(e,e,QC));}}}flatten;A<O T,O F,O=std::enable_if_t<is_iterable_v<T>>>E z>=(T&&v,F f){q v>apply(f)>flatten;}A<O U,Z...Is>Q QK all_different_(H U&x,H U&y,Qd<Is...>){q((QR<Is>(x)!=QR<Is>(y))&&...);}A<O F,O...Ts>Q E zip_with(F f,Ts&&...vs){Q2(F f;Qn<o(P(Qv<Ts>()))...>its;,{q all_different_(its,B.its,std::index_sequence_for<Ts...>{});},{Qr([&](E&&...xs){(++xs,...);},its);q*QM;},{q Qr([&](E&&...xs){q f(*xs...);},its);}) q QP(w{f,Qn(P(vs)...)},w{f,Qn(a(vs)...)});};Q1 zip_default_function_{A<O...Ts>o(E)z()(Ts&&...xs)H{q Qn<Ts...>(Qf<Ts>(xs)...);}};A<O...Ts>Q E zip(Ts&&...vs){q zip_with(zip_default_function_{},Qf<Ts>(vs)...);}QX(filter,A<O F>,(F f),<F>{f},F f;,(w{f,a(v),P(v)}),(w{f,a(v),a(v)}),H I end_it;Q k QG()H{while(it!=end_it and not f(*it)){++it;}},{QG();B.QG();q it!=B.it;},{QG();++it;q*QM;},{QG();q*it;}) def_template_lambda(A<O T>,repeat,(T&&v),{Q1 w{H Qg<T>v;QK z!=(H w&)H{q QC;}w&z++(){q*QM;}H E&z*()H{q v;}};q QP(w{v},w{v});})Q E replicate(Z n){q take(n)<repeat;}Q E cycle=flatten<repeat;def_iterator_manip(enumerate,{q zip(to_infinity(Z(0)),v);})def_iterator_manip(reversed,{E s=v>QV;std::reverse(s.begin(),s.end());q iterc(QY(s));})def_iterator_manip(sorted_by,A<O F>,(F f),<F>{f},F f;,{E s=v>QV;std::sort(P(s),a(s),f);q iterc(QY(s));})def_iterator_manip(sorted,{q v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,A<O F>,(F f),<F>{f},F f;,{q v>apply(FF(i,Qn(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>apply(fst);})def_iterator_manip(nub,{Q2(I it_end;I it;,{q it!=B.it;},{o(*it)pr;do{pr=*it;++it;}while(it!=it_end and pr==*it);q*QM;},{q*it;}) E b=P(v);E e=a(v);q QP(w{e,b},w{e,e});})A<O F,O S>Q1 accum_vector_by_{Q6 Qy=k;Z n;F f;S s;A<O T,O I=o(P(Qv<T>())),O V=Qg<o(*Qv<I>())>>o(E)z()(H T&v)H{QU<Qg<QL<F,S,o(QR<1>(Qv<V>()))>>>u(n,s);for(E&&[i,x]:v){u[i]=f(u[i],x);}q u;}};A<O F,O S>Q E accum_vector_by(Z n,F f,H S&s){q accum_vector_by_<F,S>{n,f,s};}A<O S>Q E accum_vector(Z n,H S&s=S()){q accum_vector_by(n,_2,s);}A<O F,O S>Q1 accum_map_by_{Q6 Qy=k;F f;S s;A<O T,O I=o(P(Qv<T>())),O V=Qg<o(*Qv<I>())>>o(E)z()(H T&v)H{std::map<Qg<o(QR<0>(Qv<V>()))>,Qg<QL<F,S,o(QR<1>(Qv<V>()))>>>u;for(E&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qi{u[i]=f(s,x);}} q u;}};A<O F,O S>Q E accum_map_by(F f,H S&s){q accum_map_by_<F,S>{f,s};}A<O S>Q E accum_map(H S&s=S()){q accum_map_by(_2,s);}A<O F,O S>Q1 accum_unordered_map_by_{Q6 Qy=k;F f;S s;A<O T,O I=o(P(Qv<T>())),O V=Qg<o(*Qv<I>())>>o(E)z()(H T&v)H{std::unordered_map<Qg<o(QR<0>(Qv<V>()))>,Qg<QL<F,S,o(QR<1>(Qv<V>()))>>>u;for(E&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qi{u[i]=f(s,x);}} q u;}};A<O F,O S>Q E accum_unordered_map_by(F f,H S&s){q accum_unordered_map_by_<F,S>{f,s};}A<O S>Q E accum_unordered_map(H S&s=S()){q accum_unordered_map_by(_2,s);}A<O U,Z...Is>Q QK any_different_(H U&x,H U&y,Qd<Is...>){q((QR<Is>(x)!=QR<Is>(y))||...);}A<Z N,O w>Q k Ql(w&it){if Qa(N>=1){++QR<N-1>(it.its);if(not(QR<N-1>(it.its)!=a(QR<N-1>(*it.my_vs_ptr)))){QR<N-1>(it.its)=P(QR<N-1>(*it.my_vs_ptr));Ql<N-1>(it);}} Qi{it.its=Qr([](E&&...xs){q Qn(a(xs)...);},*it.my_vs_ptr);}} A<O...Ts>E Qx(Ts&&...vs){E Q4=std::make_shared<Qn<QB<Qk<Ts>,QZ<Ts>,Ts>...>>(vs...);Q2(Qn<o(P(Qv<QB<Qk<Ts>,QZ<Ts>,Ts>>()))...>its;o(Q4)my_vs_ptr;,{q any_different_(its,B.its,std::index_sequence_for<Ts...>{});},{Ql<sizeof...(Ts)>(*QM);q*QM;},{q Qr([](E&&...xs){q Qn<o(*xs)...>(*xs...);},its);}) if(Qr([](E&&...xs){q((xs>is_nil)||...);},*Q4)){q QP(w{Qr([](E&&...xs){q Qn(a(xs)...);},*Q4),Q4},w{Qr([](E&&...xs){q Qn(a(xs)...);},*Q4),Q4});}Qi{q QP(w{Qr([](E&&...xs){q Qn(P(xs)...);},*Q4),Q4},w{Qr([](E&&...xs){q Qn(a(xs)...);},*Q4),Q4});}};A<O...Ts>Q E cartesian_product_range(H Ts&...n){q Qx(Qh(n)...);}A<Z n,O I>Q E cartesian_power(H I&v){q Qr([](H E&...vs){q Qx(vs...);},tuple_many_of<n>(v));}Q1{Q6 Qy=k;QI n=-1;A<O T>E z()(T&&v)H{if Qa(std::is_convertible_v<T,QI>){E x=*QM;x.n=v;q x;}Qi{E vec=v>QV;QI m=vec.Q9();Q1 w{QI n;o(vec)my_v;QU<Z>cycles;QK W;QK z!=(H w&B)H{q W xor B.W;}w&z++(){for(E i:Qh(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=my_v.Q9()-i;std::rotate(my_v.begin()+i,my_v.begin()+i+1,my_v.end());}Qi{std::swap(my_v[i],my_v[my_v.Q9()-cycles[i]]);q*QM;}} W=QC;q*QM;}E z*()H{q my_v>array_slice(0,n);}};QI n1=(n<0)?(m):(n);q QP(w{n1,QY(vec),Qh(m,m-n1,-1)>apply(FF(x,Z(x)))>QV,QA},w{n1,{},{},QC});}}}permutations;Q1 combinations_impl{Q6 Qy=k;QI n;A<O T>E z()(T&&v)H{E vec=v>QV;QI m=vec.Q9();Q2(QI n;o(vec)my_v;QU<Z>idx;QK W;,{q W xor B.W;},{for(E i:Qh(n-1,-1,-1)){if(idx[i]!=idx.Q9()-n+i){idx[i]++;for(E j:Qh(i+1,n)){idx[j]=idx[j-1]+1;}q*QM;}} W=QC;q*QM;},{q idx>array_slice(0,n)>apply(FF(i,my_v[i]));}) q QP(w{n,QY(vec),Qh(0,m)>apply(FF(x,Z(x)))>QV,QA},w{n,{},{},QC});}};Q E combinations(QI n){q combinations_impl{n};}Q1 Q7{Q6 Qy=k;QI n;A<O T>E z()(T&&v)H{E vec=v>QV;QI m=vec.Q9();Q2(QI n;o(vec)my_v;QU<Z>idx;QK W;,{q W xor B.W;},{for(E i:Qh(n-1,-1,-1)){if(idx[i]!=idx.Q9()-1){idx[i]++;for(E j:Qh(i+1,n)){idx[j]=idx[i];}q*QM;}} W=QC;q*QM;},{q idx>array_slice(0,n)>apply(FF(i,my_v[i]));}) q QP(w{n,QY(vec),Z(0)>replicate(m)>QV,QA},w{n,{},{},QC});}};Q E combinations_with_replacement(QI n){q Q7{n};}A<O T>Q E istream_iterable(std::istream&in){Q2(std::istream&in;Qb T val;QK W;Qb QK has_read;,{q W xor B.W;},{if(not(in>>val)){W=QC;}q*QM;},{if(not has_read){has_read=QC;in>>val;}q val;}) q QP(w{in,T{},QA,QA},w{in,T{},QC,QC});}A<O T>Q E input=istream_iterable<T>(std::cin);A<O T>Qm&print_iterable(Qm&out,H T&v,H std::string&sep= " "){for(E it=P(v);it!=a(v);){ out<<*it;++it;if(it!=a(v)){out<<sep;}Qi{q out;}} q out;}A<O T,O=O T::is_iterable_wrapper>Q Qm&z<<(Qm&out,H T&v){out<< "[";q print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)A<O...Ts>Qm&z<<(Qm&out,H I<Ts...>&v){q out<<QP(v);}
QJ(QU)QJ(std::map)QJ(std::unordered_map)QJ(std::set)QJ(std::unordered_set)A<Z n,O T>Q1 Qe{Q6 type=QU<O Qe<n-1,T>::type>;static E make(H QQ<n,Z>&sz,H T&val=T()){q QU(Qq(sz),Qe<n-1,T>::make(tuple_tail(sz),val));}};A<O T>Q1 Qe<1,T>{Q6 type=QU<T>;static E make(H Qn<Z>&sz,H T&val=T()){q QU(Qq(sz),val);}};A<Z n,O T>Q6 nested_vector=O Qe<n,T>::type;A<Z n,O T>E make_nested_vector(H QQ<n,Z>&sz,H T&val=T()){q Qe<n,T>::make(sz,val);}A<Z n,O T>Q E Q8(H T&v){if Qa(n==1){q Qn(v.Q9());}Qi{q std::tuple_cat(Qn(v.Q9()),Q8<n-1>(v[0]));}} A<Z n,O T>Q E nested_vector_indices(H T&v){q Qr([&](E...x){q cartesian_product_range(x...);},Q8<n>(v));}A<Z n,O T>Q o(E)Qz(H QU<T>&v,H QQ<n,Z>&i){if Qa(n==1){q v[Qq(i)];}Qi{q Qz<n-1>(v[Qq(i)],tuple_tail(i));}} A<Z n,O T>Q o(E)Qz(QU<T>&v,H QQ<n,Z>&i){if Qa(n==1){q v[Qq(i)];}Qi{q Qz<n-1>(v[Qq(i)],tuple_tail(i));}} A<O U,Z i,Z s>Qm&Qt(Qm&out,H U&u){if Qa(i==0){out<< "{ ";}out<<QR<i>(u);if Qa(i+1<s){out<< ", ";q Qt<U,i+1,s>(out,u);}Qi{q out<< " }";}} A<O...Ts>Qm&z<<(Qm&out,H Qn<Ts...>&u){q Qt<o(u),0,sizeof...(Ts)>(out,u);}A<O T,O S>Qm&z<<(Qm&out,H std::pair<T,S>&p){q out<<Qn(p.first,p.second);} 
#define BEGIN  QI main(){std::ios_base::sync_with_stdio(QA);std::cin.tie(0);std::cout.tie(0);
#define END }
Q6 namespace std;Q6 LL=long long;BEGIN QI N,M;cin>>N>>M;vector<LL>X(N);while(M--){QI u,v,d;cin>>u>>v>>d;--u;--v;X[u]-=d;X[v]+=d;}vector<QI>L,R;for(QI n=0;n<N;++n){if(X[n]<0){L.Qc(n);}Qi{R.Qc(n);}} vector<tuple<QI,QI,LL>>ans;for(QI i=0,j=0;i<QI(L.Q9())and j<QI(R.Q9());){ LL m=min(-X[L[i]],X[R[j]]);X[L[i]]+=m;X[R[j]]-=m;if(m>0){ans.emplace_back(L[i],R[j],m);}while(i<QI(L.Q9())and X[L[i]]==0){++i;}while(j<QI(R.Q9())and X[R[j]]==0){++j;}} cout<<ans.Q9()<< "\n";for(E[u,v,d]:ans){cout<<u+1<< " " <<v+1<< " " <<d<< "\n";}END