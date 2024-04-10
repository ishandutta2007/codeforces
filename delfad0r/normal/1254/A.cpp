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
#define Q3 nested_vector_at
#define Qv std::conditional_t
#define QK else
#define H decltype
#define o operator
#define QO k_ptr
#define QH def_iterator_manip_iter
#define Qa std::ostream
#define QB std::move
#define QI cartesian_product_incr_
#define Qq bool
#define Q void
#define Qc implicit_lambda_unary_operator
#define Qr std::decay_t
#define O template
#define z __arg1__
#define QG std::forward
#define Q6 nested_vector_impl
#define X struct
#define Qe vs_ptr
#define Qg constexpr
#define L inline
#define QV __tuple__
#define Qp std::get
#define Qz __expr1__
#define Qs my_v
#define Qk advance
#define Qi tuple_head
#define Q7 is_composable_
#define QC range
#define Ql has_advanced
#define QA __arg3__
#define QU has_updated
#define QR std::vector
#define QY to_vector
#define QD implicit_lambda
#define Qj to_nested_vector_impl
#define QX std::shared_ptr
#define a auto
#define Qu std::tuple_element_t
#define P true
#define QS std::is_rvalue_reference_v
#define k std::tuple
#define Qh std::index_sequence
#define QF implicit_lambda_binary_operator
#define Qw it_end
#define q other
#define Q4 combinations_with_replacement_impl
#define QZ mutable
#define QE tuple_many_of_t
#define Z return
#define d std::begin
#define Qb is_composable
#define QL tuple_tail
#define QW std::apply
#define M typename
#define QJ cartesian_product
#define Y size_t
#define QQ iterator_macro
#define Q9 std::declval
#define Qm container_carrying_iterator
#define Q5 iterable_wrapper
#define Qn false
#define Q2 ostream_tuple_helper_
#define Qf std::invoke_result_t
#define Q8 def_iterable_ostream
#define W Iterator
#define Q0 j_end
#define Qy apply
#define E is_end
#define w const
#define B using
#define Qx is_composable_v
#define QP __arg2__
#define A std::end
#define Qo std::remove_reference_t
#define Q1 jv_ptr
#define QT this
#define Qd iter
#define Qt nested_vector_size

O<M T,Y>B ignore_second=T;O<Y...Ix,M T>a tuple_many_of_impl(Qh<Ix...>,w T&x){Z k(ignore_second<T,Ix>(x)...);}O<Y n,M T>a tuple_many_of(w T&x){Z tuple_many_of_impl(std::make_index_sequence<n>{},x);}O<Y n,M T>B QE=H(tuple_many_of<n,T>(Q9<T>()));O<M...Args>a Qi(w k<Args...>&t){Z Qp<0>(t);}O<Y...Ix,M...Args>a tuple_tail_impl(Qh<Ix...>,w k<Args...>&t){Z k(Qp<Ix+1>(t)...);}O<M...Args>a QL(w k<Args...>&t){Z tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}X empty_t{};Qg empty_t empty_v;O<M T1,M T2>std::common_type_t<T1,T2>maxx(w T1&x,w T2&y){if(x<y){Z y;}QK{Z x;}} O<M T1,M T2,M...Ts>L a maxx(w T1&x,w T2&y,w Ts&...xs){Z maxx(maxx(x,y),xs...);}O<M T1,M T2>a minn(w T1&x,w T2&y){if(x<=y){Z x;}QK{Z y;}} O<M T1,M T2,M...Ts>L a minn(w T1&x,w T2&y,w Ts&...xs){Z minn(minn(x,y),xs...);}Qg int _log2(int x){if(x==0){Z 0;}Z 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&]()->H(a){Z f;}
#define FF_1(z,f)[&](a&&z)->H(a){(Q)z;Z f;}
#define FF_2(z,QP,f)[&](a&&z,a&&QP)->H(a){(Q)z;(Q)QP;Z f;}
#define FF_3(z,QP,QA,f)[&](a&&z,a&&QP,a&&QA)->H(a){(Q)z;(Q)QP;(Q)QA;Z f;}
#define FF_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c]()->H(a){Z f;}
#define FC_1(z,f,c)[&,c](a&&z)->H(a){(Q)z;Z f;}
#define FC_2(z,QP,f,c)[&,c](a&&z,a&&QP)->H(a){(Q)z;(Q)QP;Z f;}
#define FC_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2]()->H(a){Z f;}
#define FC2_1(z,f,c1,c2)[&,c1,c2](a&&z)->H(a){(Q)z;Z f;}
#define FC2_2(z,QP,f,c1,c2)[&,c1,c2](a&&z,a&&QP)->H(a){(Q)z;(Q)QP;Z f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(z,f)[&](a&&QV)->H(a){a&[z]=QV;(Q)z;Z f;}
#define FT_2(z,QP,f)[&](a&&QV)->H(a){a&[z,QP]=QV;(Q)z;(Q)QP;Z f;}
#define FT_3(z,QP,QA,f)[&](a&&QV)->H(a){a&[z,QP,QA]=QV;(Q)z;(Q)QP;(Q)QA;Z f;}
#define FT_4(z,QP,QA,__arg4__,f)[&](a&&QV)->H(a){a&[z,QP,QA,__arg4__]=QV;(Q)z;(Q)QP;(Q)QA;(Q)__arg4__;Z f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Qz,f)[&](){a&&Qz;Z f;}()
#define LET_2(Qz,__expr2__,f)[&](){a&&Qz;a&&__expr2__;Z f;}()
#define LET_3(Qz,__expr2__,__expr3__,f)[&](){a&&Qz;a&&__expr2__;a&&__expr3__;Z f;}()
#define LET_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)Qg X{B Q7=Q;templ L H(a)o()args w code}name;
O<M F>class QD{private:F f;public:QD(F f_):f(f_){} O<M...Ts>Qg a o()(Ts&&...xs)w{Z f(QG<Ts>(xs)...);}};QD _([](a&&x)->Qv<QS<H(x)>,Qo<H(x)>,H(x)>{Z x;});QD _1([](a&&x,a&&)->Qv<QS<H(x)>,Qo<H(x)>,H(x)>{Z x;});QD _2([](a&&,a&&y)->Qv<QS<H(y)>,Qo<H(y)>,H(y)>{Z y;});
#define implicit_lambda_unary_operator(op)O<M F>Qg H(a)o op(QD<F>f){Z QD([=](a&&...xs){Z op f(QG<H(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)O<M F,M T>Qg H(a)o op(QD<F>f,w T&y){Z QD([=](a&&...xs){Z f(QG<H(xs)>(xs)...)op y;});}O<M F,M T>Qg H(a)o op(w T&y,QD<F>f){Z QD([=](a&&...xs){Z y op f(QG<H(xs)>(xs)...);});}O<M F,M G>Qg H(a)o op(QD<F>f,QD<G>g){Z QD([=](a&&...xs){Z f(QG<H(xs)>(xs)...)op g(QG<H(xs)>(xs)...);});}
Qc(+)Qc(-)Qc(!)Qc(~)Qc(*)Qc(&)QF(+)QF(-)QF(*)QF(/)QF(%)QF(<)QF(>)QF(<=)QF(>=)QF(==)QF(!=)QF(<<)QF(>>)QF(&)QF(|)QF(^)QF(&&)O<M T,M=Q>X Qb:public std::false_type{};O<M T>X Qb<T,std::void_t<M T::is_composable_>>:public std::true_type{};O<M T>Qg Qq Qx=Qb<T>::value;O<M T,M F,M=Qf<F,T>>H(a)o>(T&&v,w F&f){Z f(QG<T>(v));}O<M M1,M M2>X composed{B Q7=Q;w M1 m1;w M2 m2;O<M T>H(a)o()(T&&v)w{Z m1(m2(QG<T>(v)));}};O<M M1,M M2,M=std::enable_if_t<Qx<M1>or Qx<M2>>>L a o<(w M1&m1,w M2&m2){Z composed<M1,M2>{m1,m2};}O<Y n>X nth_impl{B Q7=Q;O<M...Ts>Qg Qu<n,k<Ts...>>&o()(k<Ts...>&u)w{Z Qp<n>(u);}O<M...Ts>Qg Qu<n,k<Ts...>>o()(k<Ts...>&&u)w{Z Qp<n>(u);}O<M...Ts>Qg w Qu<n,k<Ts...>>&o()(w k<Ts...>&u)w{Z Qp<n>(u);}O<M...Ts>Qg w Qu<n,k<Ts...>>o()(w k<Ts...>&&u)w{Z Qp<n>(u);}};O<Y n>Qg nth_impl<n>nth;Qg nth_impl<0>fst;Qg nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)X W{extra Qq o!=(w W&q)w neq W&o++()incr H(a)o*()w val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,Qw,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{QQ(extra extra_it QZ I it;,neq_it,incr_it,val_it);Z Q5(it_begin,Qw);})
#define def_iterator_manip_2(name,code)Qg X{B Q7=Q;O<M T,M I=H(d(Q9<T>())),M V=Qr<H(*Q9<I>())>>H(a)o()(T&&v)w code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ X name##_impl{B Q7=Q;extra O<M T,M I=H(d(Q9<T>())),M V=Qr<H(*Q9<I>())>>H(a)o()(T&&v)w code};templ L H(a)name args{Z name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
O<M T,M=Q>X is_iterable:public std::false_type{};O<M T>X is_iterable<T,std::void_t<H(d(Q9<T>())),H(A(Q9<T>()))>>:public std::true_type{};O<M T>Qg Qq is_iterable_v=is_iterable<T>::value;O<M I>L a Q5(w I&b,w I&e){X Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
B is_iterable_wrapper=Q;B iterator=I;B value_type=Qr<H(*Q9<I>())>;
#pragma GCC diagnostic pop
I b,e;a begin()w{Z b;}a end()w{Z e;}};Z Wrapper{b,e};}O<M T>L a Qd(T&&iterable){Z Q5(d(QG<T>(iterable)),A(QG<T>(iterable)));}O<M I>L a Qd(w I&b,w I&e){Z Q5(b,e);}O<M C>X Qm:public C::iterator{QX<C>p;Qm(QX<C>p_,M C::iterator it):C::iterator(it),p(p_){}};O<M C>L a iterc(C&&v){B D=Qr<C>;QX<D>p(new D(QG<C>(v)));Z Q5(Qm<D>{p,d(*p)},Qm<D>{p,A(*p)});}O<M T>L a Qd(std::initializer_list<T>l){Z iterc(QR<T>(l));}def_template_lambda(O<M T>,QY,(T&&v),{QR<M Qr<T>::value_type>s;for(a&&x:v){s.push_back(x);}Z s;})O<Y n>X Qj{O<M T>L static a make(T&&v){Z QG<T>(v)>Qy(FF(u,Qj<n-1>::make(u)))>QY;}};O<>X Qj<1>{O<M T>L static a make(T&&v){Z QG<T>(v)>QY;}};O<Y n>X to_nested_vector_{B Q7=Q;O<M T>L H(a)o()(T&&v)w{Z Qj<n>::make(QG<T>(v));}};O<Y n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(Y l,Y r),({l,r}),Y l;Y r;,{Z Qd(d(v)+l,d(v)+r);})def_iterator_manip(is_nil,{Z not(d(v)!=A(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{Y l=0;for(a i=d(v);i!=A(v);++i){++l;}Z l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
O<M T1,M T2,M T3,M T=std::make_signed_t<H(T1()+T2()+T3())>>L a QC(w T1&b,w T2&e,w T3&step){QQ(T x;T e;T step;L Qq E()w{Z(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{Z E()xor q.E();},{x+=step;Z*QT;},{Z T(x);}) Z Qd(W{b,e,step},W{e,e,step});}O<M T1,M T2>L a QC(w T1&b,w T2&e){Z QC(b,e,H(T1()+T2())(1));}O<M T>L a QC(w T&e){Z QC(T(),e,T(1));} 
#pragma GCC diagnostic pop
O<M T>L a to_infinity(w T&b=0,w T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
QQ(T x;T step;,{(Q)q;Z P;},{x+=step;Z*QT;},{Z T(x);}) Z Qd(W{b,step},W{b,step});
#pragma GCC diagnostic pop
}QH(Qy,O<M F>,(F f),<F>{f},F f;,(W{f,d(v)}),(W{f,A(v)}),,{ Z it!=q.it;},{++it;Z*QT;},{Z f(*it);}) QH(take,,(Y n),{n},Y n;,(W{n,d(v)}),(W{0,A(v)}),,{ Z n!=q.n;},{--n;if(n>0){++it;}Z*QT;},{Z*it;}) QH(take_while,O<M F>,(F f),<F>{f},F f;,(W{f,not(d(v)!=A(v)and f(*d(v))),d(v)}),(W{f,P,A(v)}),Qq E;,{Z E xor q.E;},{++it;if(not f(*it)){E=P;}Z*QT;},{Z*it;}) QH(drop,,(Y n),{n},QZ Y n;,(W{n,A(v),d(v)}),(W{0,A(v),A(v)}),w I end_it;L Q Qk()w{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{Qk();q.Qk();Z it!=q.it;},{Qk();++it;Z*QT;},{Qk();Z*it;}) QH(drop_while,O<M F>,(F f),<F>{f},F f;,(W{f,A(v),Qn,d(v)}),(W{f,A(v),P,A(v)}),w I end_it;QZ Qq Ql;L Q Qk()w{if(not Ql){while(it!=end_it and f(*it)){++it;}Ql=P;}},{Qk();q.Qk();Z it!=q.it;},{Qk();++it;Z*QT;},{Qk();Z*it;}) def_iterator_manip(head,{Z*d(v);})L a tail=drop(1);L a at(Y n){Z head<drop(n);}QH(cons,O<M S>,(S s),<S>{s},S s;,(W{s,P,d(v)}),(W{s,Qn,A(v)}),Qq is_s;,{Z is_s!=q.is_s or it!=q.it;},{if(is_s){is_s=Qn;}QK{++it;}Z*QT;},{Z(is_s)?(s):(*it);}) def_iterator_manip(snoc,{a it=d(v);a h=*it;++it;Z k(h,Qd(it,A(v)));})def_iterator_manip(split_at,,(Y n),{n},Y n;,{a it=d(v);QR<T>u;for(a i:QC(n)){u.push_back(*it);++it;}Z k(iterc(QB(u)),Qd(it,A(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
QH(chunks_of,,(Y n),{n},Y n;,(W{n,{},Qn,A(v),d(v)}),(W{n,{},Qn,A(v),A(v)}),QZ QR<V>u;QZ Qq QU;I Qw;Q update()w{u.clear();QU=P;for(a i:QC(n)){if(it!=Qw){u.push_back(*it);++it;}QK{break;}}},{Z it!=q.it;},{if(QU){QU=Qn;}QK{for(a i:QC(n)){if(it!=Qw){++it;}QK{break;}}}Z*QT;},{if(not QU){update();}Z iterc(u);})
#pragma GCC diagnostic pop
O<M F,M S>X fold_impl{B Q7=Q;F f;S s;O<M T>a o()(w T&v)w{a x=s;for(a y:v){x=f(x,y);}Z x;}};O<M F,M S>L a fold(F f,w S&s){Z fold_impl<F,S>{f,s};}def_iterator_manip(fold1,O<M F>,(F f),<F>{f},F f;,{a u=v>snoc;Z u>snd>fold(f,u>fst);})def_iterator_manip(sum,{Z v>fold(_1+_2,V(0));})def_iterator_manip(product,{Z v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,O<M F>,(F f),<F>{f},F f;,{Z v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{Z v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,O<M F>,(F f),<F>{f},F f;,{Z v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,O<M F>,(F f),<F>{f},F f;,{Z v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{Z v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,O<M F>,(F f),<F>{f},F f;,{Z v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})O<M F,M S>X scan_impl{B Q7=Q;F f;S s;O<M T,M I=H(d(Q9<T>()))>H(a)o()(T&&v)w{QQ(F f;QZ S s;QZ Qq QU;Qq Ql;QZ I it;,{Z it!=q.it;},{if(not QU){s=f(s,*it);};QU=Qn;if(Ql){++it;}QK{Ql=P;}Z*QT;},{if(not QU){QU=P;s=f(s,*it);}Z s;}) Z Qd(W{f,s,P,Qn,d(QG<T>(v))},W{f,s,P,P,A(QG<T>(v))});}};O<M F,M S>L a scan(F f,w S&s){Z scan_impl<F,S>{f,s};}QH(scan1,O<M F>,(F f),<F>{f},F f;,(W{f,*d(v),P,d(v)}),(W{f,*d(v),P,A(v)}),QZ V s;QZ Qq QU;,{Z it!=q.it;},{if(not QU){s=f(s,*it);};QU=Qn;++it;Z*QT;},{if(not QU){QU=P;s=f(s,*it);}Z s;}) O<M T,M S,M I=H(d(Q9<T>())),M J=H(d(Q9<S>()))>L a o+(T&&v,S&&u){QQ(I i;I i_end;J j;Qq in_i;,{Z i!=q.i or j!=q.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=Qn;}}QK{++j;}Z*QT;},{Z(in_i)?(*i):(*j);}) I bv=d(v);I ev=A(v);J bu=d(u);J eu=A(u);Z Qd(W{bv,ev,bu,bv!=ev},W{ev,ev,eu,Qn});}Qg X{B Q7=Q;O<M T>a o()(T&&v)w{a u=QG<T>(v)>filter(FF(i,not is_nil(i)));a b=d(u);a e=A(u);B J=H(b);B V=Qr<H(*b)>;B K=H(d(*b));X W{J j;J Q0;QX<V>Q1;K*QO;Qq E;W(J j,J Q0,w V&jv,Qq E):j(j),Q0(Q0),Q1(new V(jv)),QO(new K(d(*Q1))),E(E){} W(J j,J Q0,Qq E):j(j),Q0(Q0),Q1(nullptr),QO(nullptr),E(E){} W(w W&q):j(q.j),Q0(q.Q0),Q1(q.Q1),QO((q.QO)?(new K(*q.QO)):nullptr),E(q.E){} W(W&&q):j(q.j),Q0(q.Q0),Q1(q.Q1),QO((q.QO)?(new K(*q.QO)):nullptr),E(q.E){}~W(){delete QO;}Qq o!=(w W&q)w{Z E xor q.E;}W&o++(){++*QO;if(not(*QO!=A(*Q1))){++j;if(j!=Q0){delete QO;Q1=std::make_shared<V>(*j);QO=new K(d(*Q1));}QK{E=P;}} Z*QT;}H(a)o*()w{Z**QO;}};if(u>is_nil){Z Q5(W(b,e,P),W(b,e,P));}QK{Z Q5(W(b,e,*b,Qn),W(e,e,P));}}}flatten;O<M T,M F,M=std::enable_if_t<is_iterable_v<T>>>a o>=(T&&v,F f){Z v>Qy(f)>flatten;}O<M U,Y...Is>L Qq all_different_(w U&x,w U&y,Qh<Is...>){Z((Qp<Is>(x)!=Qp<Is>(y))&&...);}O<M F,M...Ts>L a zip_with(F f,Ts&&...vs){QQ(F f;k<H(d(Q9<Ts>()))...>its;,{Z all_different_(its,q.its,std::index_sequence_for<Ts...>{});},{QW([&](a&&...xs){(++xs,...);},its);Z*QT;},{Z QW([&](a&&...xs){Z f(*xs...);},its);}) Z Qd(W{f,k(d(vs)...)},W{f,k(A(vs)...)});};X zip_default_function_{O<M...Ts>H(a)o()(Ts&&...xs)w{Z k<Ts...>(QG<Ts>(xs)...);}};O<M...Ts>L a zip(Ts&&...vs){Z zip_with(zip_default_function_{},QG<Ts>(vs)...);}QH(filter,O<M F>,(F f),<F>{f},F f;,(W{f,A(v),d(v)}),(W{f,A(v),A(v)}),w I end_it;L Q Qk()w{while(it!=end_it and not f(*it)){++it;}},{Qk();q.Qk();Z it!=q.it;},{Qk();++it;Z*QT;},{Qk();Z*it;}) def_template_lambda(O<M T>,repeat,(T&&v),{X W{w Qr<T>v;Qq o!=(w W&)w{Z P;}W&o++(){Z*QT;}w a&o*()w{Z v;}};Z Qd(W{v},W{v});})L a replicate(Y n){Z take(n)<repeat;}L a cycle=flatten<repeat;def_iterator_manip(enumerate,{Z zip(to_infinity(Y(0)),v);})def_iterator_manip(reversed,{a s=v>QY;std::reverse(s.begin(),s.end());Z iterc(QB(s));})def_iterator_manip(sorted_by,O<M F>,(F f),<F>{f},F f;,{a s=v>QY;std::sort(d(s),A(s),f);Z iterc(QB(s));})def_iterator_manip(sorted,{Z v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,O<M F>,(F f),<F>{f},F f;,{Z v>Qy(FF(i,k(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>Qy(fst);})def_iterator_manip(nub,{QQ(I Qw;I it;,{Z it!=q.it;},{H(*it)pr;do{pr=*it;++it;}while(it!=Qw and pr==*it);Z*QT;},{Z*it;}) a b=d(v);a e=A(v);Z Qd(W{e,b},W{e,e});})O<M F,M S>X accum_vector_by_{B Q7=Q;Y n;F f;S s;O<M T,M I=H(d(Q9<T>())),M V=Qr<H(*Q9<I>())>>H(a)o()(w T&v)w{QR<Qr<Qf<F,S,H(Qp<1>(Q9<V>()))>>>u(n,s);for(a&&[i,x]:v){u[i]=f(u[i],x);}Z u;}};O<M F,M S>L a accum_vector_by(Y n,F f,w S&s){Z accum_vector_by_<F,S>{n,f,s};}O<M S>L a accum_vector(Y n,w S&s=S()){Z accum_vector_by(n,_2,s);}O<M F,M S>X accum_map_by_{B Q7=Q;F f;S s;O<M T,M I=H(d(Q9<T>())),M V=Qr<H(*Q9<I>())>>H(a)o()(w T&v)w{std::map<Qr<H(Qp<0>(Q9<V>()))>,Qr<Qf<F,S,H(Qp<1>(Q9<V>()))>>>u;for(a&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QK{u[i]=f(s,x);}} Z u;}};O<M F,M S>L a accum_map_by(F f,w S&s){Z accum_map_by_<F,S>{f,s};}O<M S>L a accum_map(w S&s=S()){Z accum_map_by(_2,s);}O<M F,M S>X accum_unordered_map_by_{B Q7=Q;F f;S s;O<M T,M I=H(d(Q9<T>())),M V=Qr<H(*Q9<I>())>>H(a)o()(w T&v)w{std::unordered_map<Qr<H(Qp<0>(Q9<V>()))>,Qr<Qf<F,S,H(Qp<1>(Q9<V>()))>>>u;for(a&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QK{u[i]=f(s,x);}} Z u;}};O<M F,M S>L a accum_unordered_map_by(F f,w S&s){Z accum_unordered_map_by_<F,S>{f,s};}O<M S>L a accum_unordered_map(w S&s=S()){Z accum_unordered_map_by(_2,s);}O<M U,Y...Is>L Qq any_different_(w U&x,w U&y,Qh<Is...>){Z((Qp<Is>(x)!=Qp<Is>(y))||...);}O<Y N,M W>L Q QI(W&it){if Qg(N>=1){++Qp<N-1>(it.its);if(not(Qp<N-1>(it.its)!=A(Qp<N-1>(*it.my_vs_ptr)))){Qp<N-1>(it.its)=d(Qp<N-1>(*it.my_vs_ptr));QI<N-1>(it);}} QK{it.its=QW([](a&&...xs){Z k(A(xs)...);},*it.my_vs_ptr);}} O<M...Ts>a QJ(Ts&&...vs){a Qe=std::make_shared<k<Qv<QS<Ts>,Qo<Ts>,Ts>...>>(vs...);QQ(k<H(d(Q9<Qv<QS<Ts>,Qo<Ts>,Ts>>()))...>its;H(Qe)my_vs_ptr;,{Z any_different_(its,q.its,std::index_sequence_for<Ts...>{});},{QI<sizeof...(Ts)>(*QT);Z*QT;},{Z QW([](a&&...xs){Z k<H(*xs)...>(*xs...);},its);}) if(QW([](a&&...xs){Z((xs>is_nil)||...);},*Qe)){Z Qd(W{QW([](a&&...xs){Z k(A(xs)...);},*Qe),Qe},W{QW([](a&&...xs){Z k(A(xs)...);},*Qe),Qe});}QK{Z Qd(W{QW([](a&&...xs){Z k(d(xs)...);},*Qe),Qe},W{QW([](a&&...xs){Z k(A(xs)...);},*Qe),Qe});}};O<M...Ts>L a cartesian_product_range(w Ts&...n){Z QJ(QC(n)...);}O<Y n,M I>L a cartesian_power(w I&v){Z QW([](w a&...vs){Z QJ(vs...);},tuple_many_of<n>(v));}X{B Q7=Q;int n=-1;O<M T>a o()(T&&v)w{if Qg(std::is_convertible_v<T,int>){a x=*QT;x.n=v;Z x;}QK{a vec=v>QY;int m=vec.size();X W{int n;H(vec)Qs;QR<Y>cycles;Qq E;Qq o!=(w W&q)w{Z E xor q.E;}W&o++(){for(a i:QC(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=Qs.size()-i;std::rotate(Qs.begin()+i,Qs.begin()+i+1,Qs.end());}QK{std::swap(Qs[i],Qs[Qs.size()-cycles[i]]);Z*QT;}} E=P;Z*QT;}a o*()w{Z Qs>array_slice(0,n);}};int n1=(n<0)?(m):(n);Z Qd(W{n1,QB(vec),QC(m,m-n1,-1)>Qy(FF(x,Y(x)))>QY,Qn},W{n1,{},{},P});}}}permutations;X combinations_impl{B Q7=Q;int n;O<M T>a o()(T&&v)w{a vec=v>QY;int m=vec.size();QQ(int n;H(vec)Qs;QR<Y>idx;Qq E;,{Z E xor q.E;},{for(a i:QC(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(a j:QC(i+1,n)){idx[j]=idx[j-1]+1;}Z*QT;}} E=P;Z*QT;},{Z idx>array_slice(0,n)>Qy(FF(i,Qs[i]));}) Z Qd(W{n,QB(vec),QC(0,m)>Qy(FF(x,Y(x)))>QY,Qn},W{n,{},{},P});}};L a combinations(int n){Z combinations_impl{n};}X Q4{B Q7=Q;int n;O<M T>a o()(T&&v)w{a vec=v>QY;int m=vec.size();QQ(int n;H(vec)Qs;QR<Y>idx;Qq E;,{Z E xor q.E;},{for(a i:QC(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(a j:QC(i+1,n)){idx[j]=idx[i];}Z*QT;}} E=P;Z*QT;},{Z idx>array_slice(0,n)>Qy(FF(i,Qs[i]));}) Z Qd(W{n,QB(vec),Y(0)>replicate(m)>QY,Qn},W{n,{},{},P});}};L a combinations_with_replacement(int n){Z Q4{n};}O<M T>L a istream_iterable(std::istream&in){QQ(std::istream&in;QZ T val;Qq E;QZ Qq has_read;,{Z E xor q.E;},{if(not(in>>val)){E=P;}Z*QT;},{if(not has_read){has_read=P;in>>val;}Z val;}) Z Qd(W{in,T{},Qn,Qn},W{in,T{},P,P});}O<M T>L a input=istream_iterable<T>(std::cin);O<M T>Qa&print_iterable(Qa&out,w T&v,w std::string&sep= " "){for(a it=d(v);it!=A(v);){ out<<*it;++it;if(it!=A(v)){out<<sep;}QK{Z out;}} Z out;}O<M T,M=M T::is_iterable_wrapper>L Qa&o<<(Qa&out,w T&v){out<< "[";Z print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)O<M...Ts>Qa&o<<(Qa&out,w I<Ts...>&v){Z out<<Qd(v);}
Q8(QR)Q8(std::map)Q8(std::unordered_map)Q8(std::set)Q8(std::unordered_set)O<Y n,M T>X Q6{B type=QR<M Q6<n-1,T>::type>;static a make(w QE<n,Y>&sz,w T&val=T()){Z QR(Qi(sz),Q6<n-1,T>::make(QL(sz),val));}};O<M T>X Q6<1,T>{B type=QR<T>;static a make(w k<Y>&sz,w T&val=T()){Z QR(Qi(sz),val);}};O<Y n,M T>B nested_vector=M Q6<n,T>::type;O<Y n,M T>a make_nested_vector(w QE<n,Y>&sz,w T&val=T()){Z Q6<n,T>::make(sz,val);}O<Y n,M T>L a Qt(w T&v){if Qg(n==1){Z k(v.size());}QK{Z std::tuple_cat(k(v.size()),Qt<n-1>(v[0]));}} O<Y n,M T>L a nested_vector_indices(w T&v){Z QW([&](a...x){Z cartesian_product_range(x...);},Qt<n>(v));}O<Y n,M T>L H(a)Q3(w QR<T>&v,w QE<n,Y>&i){if Qg(n==1){Z v[Qi(i)];}QK{Z Q3<n-1>(v[Qi(i)],QL(i));}} O<Y n,M T>L H(a)Q3(QR<T>&v,w QE<n,Y>&i){if Qg(n==1){Z v[Qi(i)];}QK{Z Q3<n-1>(v[Qi(i)],QL(i));}} O<M U,Y i,Y s>Qa&Q2(Qa&out,w U&u){if Qg(i==0){out<< "{ ";}out<<Qp<i>(u);if Qg(i+1<s){out<< ", ";Z Q2<U,i+1,s>(out,u);}QK{Z out<< " }";}} O<M...Ts>Qa&o<<(Qa&out,w k<Ts...>&u){Z Q2<H(u),0,sizeof...(Ts)>(out,u);}O<M T,M S>Qa&o<<(Qa&out,w std::pair<T,S>&p){Z out<<k(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(Qn);std::cin.tie(0);std::cout.tie(0);
#define END }
B namespace std;B LL=long long;w string chars= "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";Q solve(){int R,C,K;cin>>R>>C>>K;vector<string>G(R);for(a&g:G){cin>>g;}vector<string>ans(R,string(C, ' '));int i=0,c=0;int rice=G>Qy(FF(s,s>filter(_== 'R')>length))>sum;for(a y:QC(R)){a xs=QC(C)>QY;if(y%2){reverse(xs.begin(),xs.end());}for(a x:xs){ans[y][x]=chars[i];if(K==0){continue;}if(G[y][x]== 'R'){++c;}if(c==rice/K){rice-=c;K--;if(K){i++;}c=0;}}}for(a&g:ans){cout<<g<< "\n";}} BEGIN int T;cin>>T;while(T--){solve();}END