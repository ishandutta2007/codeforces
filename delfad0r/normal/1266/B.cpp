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
#define Qz __expr1__
#define QX cartesian_product_incr_
#define QV std::remove_reference_t
#define QW implicit_lambda_unary_operator
#define Qg range
#define Qv std::apply
#define Qc to_nested_vector_impl
#define Qj std::forward
#define Qk has_advanced
#define E decltype
#define QS my_v
#define Q6 std::index_sequence
#define QE iterable_wrapper
#define Qp nested_vector_at
#define Qt std::is_rvalue_reference_v
#define B true
#define QG else
#define d std::tuple
#define Qi std::shared_ptr
#define Q8 advance
#define Qb vs_ptr
#define Qo this
#define Q2 j_end
#define Qd std::declval
#define QC std::conditional_t
#define a const
#define O Iterator
#define QO bool
#define QF std::move
#define Y struct
#define Qm std::get
#define H void
#define Q4 is_composable_v
#define Qw implicit_lambda
#define Qq iter
#define Ql apply
#define R operator
#define Qa it_end
#define z return
#define Q0 container_carrying_iterator
#define o std::end
#define Qy nested_vector_impl
#define Qr ostream_tuple_helper_
#define QD def_iterator_manip_iter
#define Qx GET_5TH_ARG
#define k size_t
#define Q1 combinations_with_replacement_impl
#define X __arg1__
#define Qf def_iterable_ostream
#define Qh cartesian_product
#define QI has_updated
#define QZ iterator_macro
#define Q3 tuple_many_of_t
#define w typename
#define QL jv_ptr
#define Q7 __tuple__
#define Z std::begin
#define QK std::ostream
#define QU implicit_lambda_binary_operator
#define Qn mutable
#define Qs std::tuple_element_t
#define Q5 std::decay_t
#define QJ to_vector
#define Qe tuple_tail
#define QY constexpr
#define QP false
#define Q9 is_composable_
#define QH nested_vector_size
#define q using
#define W inline
#define QA tuple_head
#define P is_end
#define QT k_ptr
#define M __arg2__
#define QR std::invoke_result_t
#define Q template
#define Qu __arg3__
#define QQ std::vector
#define L auto
#define A other

Q<w T,k>q ignore_second=T;Q<k...Ix,w T>L tuple_many_of_impl(Q6<Ix...>,a T&x){z d(ignore_second<T,Ix>(x)...);}Q<k n,w T>L tuple_many_of(a T&x){z tuple_many_of_impl(std::make_index_sequence<n>{},x);}Q<k n,w T>q Q3=E(tuple_many_of<n,T>(Qd<T>()));Q<w...Args>L QA(a d<Args...>&t){z Qm<0>(t);}Q<k...Ix,w...Args>L tuple_tail_impl(Q6<Ix...>,a d<Args...>&t){z d(Qm<Ix+1>(t)...);}Q<w...Args>L Qe(a d<Args...>&t){z tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}Y empty_t{};QY empty_t empty_v;Q<w T1,w T2>std::common_type_t<T1,T2>maxx(a T1&x,a T2&y){if(x<y){z y;}QG{z x;}} Q<w T1,w T2,w...Ts>W L maxx(a T1&x,a T2&y,a Ts&...xs){z maxx(maxx(x,y),xs...);}Q<w T1,w T2>L minn(a T1&x,a T2&y){if(x<=y){z x;}QG{z y;}} Q<w T1,w T2,w...Ts>W L minn(a T1&x,a T2&y,a Ts&...xs){z minn(minn(x,y),xs...);}QY int _log2(int x){if(x==0){z 0;}z 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){z f;}
#define FF_1(X,f)[&](L&&X){(H)X;z f;}
#define FF_2(X,M,f)[&](L&&X,L&&M){(H)X;(H)M;z f;}
#define FF_3(X,M,Qu,f)[&](L&&X,L&&M,L&&Qu){(H)X;(H)M;(H)Qu;z f;}
#define FF_macro_chooser(...)Qx(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->L&{z f;}
#define FREF_1(X,f)[&](L&&X)->L&{(H)X;z f;}
#define FREF_2(X,M,f)[&](L&&X,L&&M)->L&{(H)X;(H)M;z f;}
#define FREF_3(X,M,Qu,f)[&](L&&X,L&&M,L&&Qu)->L&{(H)X;(H)M;(H)Qu;z f;}
#define FREF_macro_chooser(...)Qx(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){z f;}
#define FC_1(X,f,c)[&,c](L&&X){(H)X;z f;}
#define FC_2(X,M,f,c)[&,c](L&&X,L&&M){(H)X;(H)M;z f;}
#define FC_macro_chooser(...)Qx(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){z f;}
#define FC2_1(X,f,c1,c2)[&,c1,c2](L&&X){(H)X;z f;}
#define FC2_2(X,M,f,c1,c2)[&,c1,c2](L&&X,L&&M){(H)X;(H)M;z f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(X,f)[&](L&&Q7){L&[X]=Q7;(H)X;z f;}
#define FT_2(X,M,f)[&](L&&Q7){L&[X,M]=Q7;(H)X;(H)M;z f;}
#define FT_3(X,M,Qu,f)[&](L&&Q7){L&[X,M,Qu]=Q7;(H)X;(H)M;(H)Qu;z f;}
#define FT_4(X,M,Qu,__arg4__,f)[&](L&&Q7){L&[X,M,Qu,__arg4__]=Q7;(H)X;(H)M;(H)Qu;(H)__arg4__;z f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Qz,f)[&](){L&&Qz;z f;}()
#define LET_2(Qz,__expr2__,f)[&](){L&&Qz;L&&__expr2__;z f;}()
#define LET_3(Qz,__expr2__,__expr3__,f)[&](){L&&Qz;L&&__expr2__;L&&__expr3__;z f;}()
#define LET_macro_chooser(...)Qx(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)QY Y{q Q9=H;templ W E(L)R()args a code}name;
Q<w F>class Qw{private:F f;public:Qw(F f_):f(f_){} Q<w...Ts>QY L R()(Ts&&...xs)a{z f(Qj<Ts>(xs)...);}};Qw _([](L&&x)->QC<Qt<E(x)>,QV<E(x)>,E(x)>{z x;});Qw _1([](L&&x,L&&)->QC<Qt<E(x)>,QV<E(x)>,E(x)>{z x;});Qw _2([](L&&,L&&y)->QC<Qt<E(y)>,QV<E(y)>,E(y)>{z y;});
#define implicit_lambda_unary_operator(op)Q<w F>QY E(L)R op(Qw<F>f){z Qw([=](L&&...xs){z op f(Qj<E(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)Q<w F,w T>QY E(L)R op(Qw<F>f,a T&y){z Qw([=](L&&...xs){z f(Qj<E(xs)>(xs)...)op y;});}Q<w F,w T>QY E(L)R op(a T&y,Qw<F>f){z Qw([=](L&&...xs){z y op f(Qj<E(xs)>(xs)...);});}Q<w F,w G>QY E(L)R op(Qw<F>f,Qw<G>g){z Qw([=](L&&...xs){z f(Qj<E(xs)>(xs)...)op g(Qj<E(xs)>(xs)...);});}
QW(+)QW(-)QW(!)QW(~)QW(*)QW(&)QU(+)QU(-)QU(*)QU(/)QU(%)QU(<)QU(>)QU(<=)QU(>=)QU(==)QU(!=)QU(<<)QU(>>)QU(&)QU(|)QU(^)QU(&&)Q<w T,w=H>Y is_composable:public std::false_type{};Q<w T>Y is_composable<T,std::void_t<w T::is_composable_>>:public std::true_type{};Q<w T>QY QO Q4=is_composable<T>::value;Q<w T,w F,w=QR<F,T>>E(L)R>(T&&v,a F&f){z f(Qj<T>(v));}Q<w M1,w M2>Y composed{q Q9=H;a M1 m1;a M2 m2;Q<w T>E(L)R()(T&&v)a{z m1(m2(Qj<T>(v)));}};Q<w M1,w M2,w=std::enable_if_t<Q4<M1>or Q4<M2>>>W L R<(a M1&m1,a M2&m2){z composed<M1,M2>{m1,m2};}Q<k n>Y nth_impl{q Q9=H;Q<w...Ts>QY Qs<n,d<Ts...>>&R()(d<Ts...>&u)a{z Qm<n>(u);}Q<w...Ts>QY Qs<n,d<Ts...>>R()(d<Ts...>&&u)a{z Qm<n>(u);}Q<w...Ts>QY a Qs<n,d<Ts...>>&R()(a d<Ts...>&u)a{z Qm<n>(u);}Q<w...Ts>QY a Qs<n,d<Ts...>>R()(a d<Ts...>&&u)a{z Qm<n>(u);}};Q<k n>QY nth_impl<n>nth;QY nth_impl<0>fst;QY nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)Y O{extra QO R!=(a O&A)a neq O&R++()incr E(L)R*()a val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,Qa,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{QZ(extra extra_it Qn I it;,neq_it,incr_it,val_it);z QE(it_begin,Qa);})
#define def_iterator_manip_2(name,code)QY Y{q Q9=H;Q<w T,w I=E(Z(Qd<T>())),w V=Q5<E(*Qd<I>())>>E(L)R()(T&&v)a code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ Y name##_impl{q Q9=H;extra Q<w T,w I=E(Z(Qd<T>())),w V=Q5<E(*Qd<I>())>>E(L)R()(T&&v)a code};templ W E(L)name args{z name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
Q<w T,w=H>Y is_iterable:public std::false_type{};Q<w T>Y is_iterable<T,std::void_t<E(Z(Qd<T>())),E(o(Qd<T>()))>>:public std::true_type{};Q<w T>QY QO is_iterable_v=is_iterable<T>::value;Q<w I>W L QE(a I&b,a I&e){Y Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
q is_iterable_wrapper=H;q iterator=I;q value_type=Q5<E(*Qd<I>())>;
#pragma GCC diagnostic pop
I b,e;L begin()a{z b;}L end()a{z e;}};z Wrapper{b,e};}Q<w T>W L Qq(T&&iterable){z QE(Z(Qj<T>(iterable)),o(Qj<T>(iterable)));}Q<w I>W L Qq(a I&b,a I&e){z QE(b,e);}Q<w C>Y Q0:public C::iterator{Qi<C>p;Q0(Qi<C>p_,w C::iterator it):C::iterator(it),p(p_){}};Q<w C>W L iterc(C&&v){q D=Q5<C>;Qi<D>p(new D(Qj<C>(v)));z QE(Q0<D>{p,Z(*p)},Q0<D>{p,o(*p)});}Q<w T>W L Qq(std::initializer_list<T>l){z iterc(QQ<T>(l));}def_template_lambda(Q<w T>,QJ,(T&&v),{QQ<w Q5<T>::value_type>s;for(L&&x:v){s.push_back(x);}z s;})Q<k n>Y Qc{Q<w T>W static L make(T&&v){z Qj<T>(v)>Ql(FF(u,Qc<n-1>::make(u)))>QJ;}};Q<>Y Qc<1>{Q<w T>W static L make(T&&v){z Qj<T>(v)>QJ;}};Q<k n>Y to_nested_vector_{q Q9=H;Q<w T>W E(L)R()(T&&v)a{z Qc<n>::make(Qj<T>(v));}};Q<k n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(k l,k r),({l,r}),k l;k r;,{z Qq(Z(v)+l,Z(v)+r);})def_iterator_manip(is_nil,{z not(Z(v)!=o(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{k l=0;for(L i=Z(v);i!=o(v);++i){++l;}z l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
Q<w T1,w T2,w T3,w T=std::make_signed_t<E(T1()+T2()+T3())>>W L Qg(a T1&b,a T2&e,a T3&step){QZ(T x;T e;T step;W QO P()a{z(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{z P()xor A.P();},{x+=step;z*Qo;},{z T(x);}) z Qq(O{b,e,step},O{e,e,step});}Q<w T1,w T2>W L Qg(a T1&b,a T2&e){z Qg(b,e,E(T1()+T2())(1));}Q<w T>W L Qg(a T&e){z Qg(T(),e,T(1));} 
#pragma GCC diagnostic pop
Q<w T>W L to_infinity(a T&b=0,a T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
QZ(T x;T step;,{(H)A;z B;},{x+=step;z*Qo;},{z T(x);}) z Qq(O{b,step},O{b,step});
#pragma GCC diagnostic pop
}QD(Ql,Q<w F>,(F f),<F>{f},F f;,(O{f,Z(v)}),(O{f,o(v)}),,{ z it!=A.it;},{++it;z*Qo;},{z f(*it);}) QD(take,,(k n),{n},k n;,(O{n,Z(v)}),(O{0,o(v)}),,{ z n!=A.n;},{--n;if(n>0){++it;}z*Qo;},{z*it;}) QD(take_while,Q<w F>,(F f),<F>{f},F f;,(O{f,not(Z(v)!=o(v)and f(*Z(v))),Z(v)}),(O{f,B,o(v)}),QO P;,{z P xor A.P;},{++it;if(not f(*it)){P=B;}z*Qo;},{z*it;}) QD(drop,,(k n),{n},Qn k n;,(O{n,o(v),Z(v)}),(O{0,o(v),o(v)}),a I end_it;W H Q8()a{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{Q8();A.Q8();z it!=A.it;},{Q8();++it;z*Qo;},{Q8();z*it;}) QD(drop_while,Q<w F>,(F f),<F>{f},F f;,(O{f,o(v),QP,Z(v)}),(O{f,o(v),B,o(v)}),a I end_it;Qn QO Qk;W H Q8()a{if(not Qk){while(it!=end_it and f(*it)){++it;}Qk=B;}},{Q8();A.Q8();z it!=A.it;},{Q8();++it;z*Qo;},{Q8();z*it;}) def_iterator_manip(head,{z*Z(v);})W L tail=drop(1);W L at(k n){z head<drop(n);}QD(cons,Q<w S>,(S s),<S>{s},S s;,(O{s,B,Z(v)}),(O{s,QP,o(v)}),QO is_s;,{z is_s!=A.is_s or it!=A.it;},{if(is_s){is_s=QP;}QG{++it;}z*Qo;},{z(is_s)?(s):(*it);}) def_iterator_manip(snoc,{L it=Z(v);L h=*it;++it;z d(h,Qq(it,o(v)));})def_iterator_manip(split_at,,(k n),{n},k n;,{L it=Z(v);QQ<T>u;for(L i:Qg(n)){u.push_back(*it);++it;}z d(iterc(QF(u)),Qq(it,o(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
QD(chunks_of,,(k n),{n},k n;,(O{n,{},QP,o(v),Z(v)}),(O{n,{},QP,o(v),o(v)}),Qn QQ<V>u;Qn QO QI;I Qa;H update()a{u.clear();QI=B;for(L i:Qg(n)){if(it!=Qa){u.push_back(*it);++it;}QG{break;}}},{z it!=A.it;},{if(QI){QI=QP;}QG{for(L i:Qg(n)){if(it!=Qa){++it;}QG{break;}}}z*Qo;},{if(not QI){update();}z iterc(u);})
#pragma GCC diagnostic pop
Q<w F,w S>Y fold_impl{q Q9=H;F f;S s;Q<w T>L R()(a T&v)a{L x=s;for(L y:v){x=f(x,y);}z x;}};Q<w F,w S>W L fold(F f,a S&s){z fold_impl<F,S>{f,s};}def_iterator_manip(fold1,Q<w F>,(F f),<F>{f},F f;,{L u=v>snoc;z u>snd>fold(f,u>fst);})def_iterator_manip(sum,{z v>fold(_1+_2,V(0));})def_iterator_manip(product,{z v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,Q<w F>,(F f),<F>{f},F f;,{z v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{z v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,Q<w F>,(F f),<F>{f},F f;,{z v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,Q<w F>,(F f),<F>{f},F f;,{z v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{z v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,Q<w F>,(F f),<F>{f},F f;,{z v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})Q<w F,w S>Y scan_impl{q Q9=H;F f;S s;Q<w T,w I=E(Z(Qd<T>()))>E(L)R()(T&&v)a{QZ(F f;Qn S s;Qn QO QI;QO Qk;Qn I it;,{z it!=A.it;},{if(not QI){s=f(s,*it);};QI=QP;if(Qk){++it;}QG{Qk=B;}z*Qo;},{if(not QI){QI=B;s=f(s,*it);}z s;}) z Qq(O{f,s,B,QP,Z(Qj<T>(v))},O{f,s,B,B,o(Qj<T>(v))});}};Q<w F,w S>W L scan(F f,a S&s){z scan_impl<F,S>{f,s};}QD(scan1,Q<w F>,(F f),<F>{f},F f;,(O{f,*Z(v),B,Z(v)}),(O{f,*Z(v),B,o(v)}),Qn V s;Qn QO QI;,{z it!=A.it;},{if(not QI){s=f(s,*it);};QI=QP;++it;z*Qo;},{if(not QI){QI=B;s=f(s,*it);}z s;}) Q<w T,w S,w I=E(Z(Qd<T>())),w J=E(Z(Qd<S>()))>W L R+(T&&v,S&&u){QZ(I i;I i_end;J j;QO in_i;,{z i!=A.i or j!=A.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=QP;}}QG{++j;}z*Qo;},{z(in_i)?(*i):(*j);}) I bv=Z(v);I ev=o(v);J bu=Z(u);J eu=o(u);z Qq(O{bv,ev,bu,bv!=ev},O{ev,ev,eu,QP});}QY Y{q Q9=H;Q<w T>L R()(T&&v)a{L u=Qj<T>(v)>filter(FF(i,not is_nil(i)));L b=Z(u);L e=o(u);q J=E(b);q V=Q5<E(*b)>;q K=E(Z(*b));Y O{J j;J Q2;Qi<V>QL;K*QT;QO P;O(J j,J Q2,a V&jv,QO P):j(j),Q2(Q2),QL(new V(jv)),QT(new K(Z(*QL))),P(P){} O(J j,J Q2,QO P):j(j),Q2(Q2),QL(nullptr),QT(nullptr),P(P){} O(a O&A):j(A.j),Q2(A.Q2),QL(A.QL),QT((A.QT)?(new K(*A.QT)):nullptr),P(A.P){} O(O&&A):j(A.j),Q2(A.Q2),QL(A.QL),QT((A.QT)?(new K(*A.QT)):nullptr),P(A.P){}~O(){delete QT;}QO R!=(a O&A)a{z P xor A.P;}O&R++(){++*QT;if(not(*QT!=o(*QL))){++j;if(j!=Q2){delete QT;QL=std::make_shared<V>(*j);QT=new K(Z(*QL));}QG{P=B;}} z*Qo;}E(L)R*()a{z**QT;}};if(u>is_nil){z QE(O(b,e,B),O(b,e,B));}QG{z QE(O(b,e,*b,QP),O(e,e,B));}}}flatten;Q<w T,w F,w=std::enable_if_t<is_iterable_v<T>>>L R>=(T&&v,F f){z v>Ql(f)>flatten;}Q<w U,k...Is>W QO all_different_(a U&x,a U&y,Q6<Is...>){z((Qm<Is>(x)!=Qm<Is>(y))&&...);}Q<w F,w...Ts>W L zip_with(F f,Ts&&...vs){QZ(F f;d<E(Z(Qd<Ts>()))...>its;,{z all_different_(its,A.its,std::index_sequence_for<Ts...>{});},{Qv([&](L&&...xs){(++xs,...);},its);z*Qo;},{z Qv([&](L&&...xs){z f(*xs...);},its);}) z Qq(O{f,d(Z(vs)...)},O{f,d(o(vs)...)});};Y zip_default_function_{Q<w...Ts>E(L)R()(Ts&&...xs)a{z d<Ts...>(Qj<Ts>(xs)...);}};Q<w...Ts>W L zip(Ts&&...vs){z zip_with(zip_default_function_{},Qj<Ts>(vs)...);}QD(filter,Q<w F>,(F f),<F>{f},F f;,(O{f,o(v),Z(v)}),(O{f,o(v),o(v)}),a I end_it;W H Q8()a{while(it!=end_it and not f(*it)){++it;}},{Q8();A.Q8();z it!=A.it;},{Q8();++it;z*Qo;},{Q8();z*it;}) def_template_lambda(Q<w T>,repeat,(T&&v),{Y O{a Q5<T>v;QO R!=(a O&)a{z B;}O&R++(){z*Qo;}a L&R*()a{z v;}};z Qq(O{v},O{v});})W L replicate(k n){z take(n)<repeat;}W L cycle=flatten<repeat;def_iterator_manip(enumerate,{z zip(to_infinity(k(0)),v);})def_iterator_manip(reversed,{L s=v>QJ;std::reverse(s.begin(),s.end());z iterc(QF(s));})def_iterator_manip(sorted_by,Q<w F>,(F f),<F>{f},F f;,{L s=v>QJ;std::sort(Z(s),o(s),f);z iterc(QF(s));})def_iterator_manip(sorted,{z v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,Q<w F>,(F f),<F>{f},F f;,{z v>Ql(FF(i,d(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>Ql(fst);})def_iterator_manip(nub,{QZ(I Qa;I it;,{z it!=A.it;},{E(*it)pr;do{pr=*it;++it;}while(it!=Qa and pr==*it);z*Qo;},{z*it;}) L b=Z(v);L e=o(v);z Qq(O{e,b},O{e,e});})Q<w F,w S>Y accum_vector_by_{q Q9=H;k n;F f;S s;Q<w T,w I=E(Z(Qd<T>())),w V=Q5<E(*Qd<I>())>>E(L)R()(a T&v)a{QQ<Q5<QR<F,S,E(Qm<1>(Qd<V>()))>>>u(n,s);for(L&&[i,x]:v){u[i]=f(u[i],x);}z u;}};Q<w F,w S>W L accum_vector_by(k n,F f,a S&s){z accum_vector_by_<F,S>{n,f,s};}Q<w S>W L accum_vector(k n,a S&s=S()){z accum_vector_by(n,_2,s);}Q<w F,w S>Y accum_map_by_{q Q9=H;F f;S s;Q<w T,w I=E(Z(Qd<T>())),w V=Q5<E(*Qd<I>())>>E(L)R()(a T&v)a{std::map<Q5<E(Qm<0>(Qd<V>()))>,Q5<QR<F,S,E(Qm<1>(Qd<V>()))>>>u;for(L&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QG{u[i]=f(s,x);}} z u;}};Q<w F,w S>W L accum_map_by(F f,a S&s){z accum_map_by_<F,S>{f,s};}Q<w S>W L accum_map(a S&s=S()){z accum_map_by(_2,s);}Q<w F,w S>Y accum_unordered_map_by_{q Q9=H;F f;S s;Q<w T,w I=E(Z(Qd<T>())),w V=Q5<E(*Qd<I>())>>E(L)R()(a T&v)a{std::unordered_map<Q5<E(Qm<0>(Qd<V>()))>,Q5<QR<F,S,E(Qm<1>(Qd<V>()))>>>u;for(L&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QG{u[i]=f(s,x);}} z u;}};Q<w F,w S>W L accum_unordered_map_by(F f,a S&s){z accum_unordered_map_by_<F,S>{f,s};}Q<w S>W L accum_unordered_map(a S&s=S()){z accum_unordered_map_by(_2,s);}Q<w U,k...Is>W QO any_different_(a U&x,a U&y,Q6<Is...>){z((Qm<Is>(x)!=Qm<Is>(y))||...);}Q<k N,w O>W H QX(O&it){if QY(N>=1){++Qm<N-1>(it.its);if(not(Qm<N-1>(it.its)!=o(Qm<N-1>(*it.my_vs_ptr)))){Qm<N-1>(it.its)=Z(Qm<N-1>(*it.my_vs_ptr));QX<N-1>(it);}} QG{it.its=Qv([](L&&...xs){z d(o(xs)...);},*it.my_vs_ptr);}} Q<w...Ts>L Qh(Ts&&...vs){L Qb=std::make_shared<d<QC<Qt<Ts>,QV<Ts>,Ts>...>>(vs...);QZ(d<E(Z(Qd<QC<Qt<Ts>,QV<Ts>,Ts>>()))...>its;E(Qb)my_vs_ptr;,{z any_different_(its,A.its,std::index_sequence_for<Ts...>{});},{QX<sizeof...(Ts)>(*Qo);z*Qo;},{z Qv([](L&&...xs){z d<E(*xs)...>(*xs...);},its);}) if(Qv([](L&&...xs){z((xs>is_nil)||...);},*Qb)){z Qq(O{Qv([](L&&...xs){z d(o(xs)...);},*Qb),Qb},O{Qv([](L&&...xs){z d(o(xs)...);},*Qb),Qb});}QG{z Qq(O{Qv([](L&&...xs){z d(Z(xs)...);},*Qb),Qb},O{Qv([](L&&...xs){z d(o(xs)...);},*Qb),Qb});}};Q<w...Ts>W L cartesian_product_range(a Ts&...n){z Qh(Qg(n)...);}Q<k n,w I>W L cartesian_power(a I&v){z Qv([](a L&...vs){z Qh(vs...);},tuple_many_of<n>(v));}Y{q Q9=H;int n=-1;Q<w T>L R()(T&&v)a{if QY(std::is_convertible_v<T,int>){L x=*Qo;x.n=v;z x;}QG{L vec=v>QJ;int m=vec.size();Y O{int n;E(vec)QS;QQ<k>cycles;QO P;QO R!=(a O&A)a{z P xor A.P;}O&R++(){for(L i:Qg(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=QS.size()-i;std::rotate(QS.begin()+i,QS.begin()+i+1,QS.end());}QG{std::swap(QS[i],QS[QS.size()-cycles[i]]);z*Qo;}} P=B;z*Qo;}L R*()a{z QS>array_slice(0,n);}};int n1=(n<0)?(m):(n);z Qq(O{n1,QF(vec),Qg(m,m-n1,-1)>Ql(FF(x,k(x)))>QJ,QP},O{n1,{},{},B});}}}permutations;Y combinations_impl{q Q9=H;int n;Q<w T>L R()(T&&v)a{L vec=v>QJ;int m=vec.size();QZ(int n;E(vec)QS;QQ<k>idx;QO P;,{z P xor A.P;},{for(L i:Qg(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(L j:Qg(i+1,n)){idx[j]=idx[j-1]+1;}z*Qo;}} P=B;z*Qo;},{z idx>array_slice(0,n)>Ql(FF(i,QS[i]));}) z Qq(O{n,QF(vec),Qg(0,m)>Ql(FF(x,k(x)))>QJ,QP},O{n,{},{},B});}};W L combinations(int n){z combinations_impl{n};}Y Q1{q Q9=H;int n;Q<w T>L R()(T&&v)a{L vec=v>QJ;int m=vec.size();QZ(int n;E(vec)QS;QQ<k>idx;QO P;,{z P xor A.P;},{for(L i:Qg(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(L j:Qg(i+1,n)){idx[j]=idx[i];}z*Qo;}} P=B;z*Qo;},{z idx>array_slice(0,n)>Ql(FF(i,QS[i]));}) z Qq(O{n,QF(vec),k(0)>replicate(m)>QJ,QP},O{n,{},{},B});}};W L combinations_with_replacement(int n){z Q1{n};}Q<w T>W L istream_iterable(std::istream&in){QZ(std::istream&in;Qn T val;QO P;Qn QO has_read;,{z P xor A.P;},{if(not(in>>val)){P=B;}z*Qo;},{if(not has_read){has_read=B;in>>val;}z val;}) z Qq(O{in,T{},QP,QP},O{in,T{},B,B});}Q<w T>W L input=istream_iterable<T>(std::cin);Q<w T>QK&print_iterable(QK&out,a T&v,a std::string&sep= " "){for(L it=Z(v);it!=o(v);){ out<<*it;++it;if(it!=o(v)){out<<sep;}QG{z out;}} z out;}Q<w T,w=w T::is_iterable_wrapper>W QK&R<<(QK&out,a T&v){out<< "[";z print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)Q<w...Ts>QK&R<<(QK&out,a I<Ts...>&v){z out<<Qq(v);}
Qf(QQ)Qf(std::map)Qf(std::unordered_map)Qf(std::set)Qf(std::unordered_set)Q<k n,w T>Y Qy{q type=QQ<w Qy<n-1,T>::type>;static L make(a Q3<n,k>&sz,a T&val=T()){z QQ(QA(sz),Qy<n-1,T>::make(Qe(sz),val));}};Q<w T>Y Qy<1,T>{q type=QQ<T>;static L make(a d<k>&sz,a T&val=T()){z QQ(QA(sz),val);}};Q<k n,w T>q nested_vector=w Qy<n,T>::type;Q<k n,w T>L make_nested_vector(a Q3<n,k>&sz,a T&val=T()){z Qy<n,T>::make(sz,val);}Q<k n,w T>W L QH(a T&v){if QY(n==1){z d(v.size());}QG{z std::tuple_cat(d(v.size()),QH<n-1>(v[0]));}} Q<k n,w T>W L nested_vector_indices(a T&v){z Qv([&](L...x){z cartesian_product_range(x...);},QH<n>(v));}Q<k n,w T>W E(L)Qp(a QQ<T>&v,a Q3<n,k>&i){if QY(n==1){z v[QA(i)];}QG{z Qp<n-1>(v[QA(i)],Qe(i));}} Q<k n,w T>W E(L)Qp(QQ<T>&v,a Q3<n,k>&i){if QY(n==1){z v[QA(i)];}QG{z Qp<n-1>(v[QA(i)],Qe(i));}} Q<w U,k i,k s>QK&Qr(QK&out,a U&u){if QY(i==0){out<< "{ ";}out<<Qm<i>(u);if QY(i+1<s){out<< ", ";z Qr<U,i+1,s>(out,u);}QG{z out<< " }";}} Q<w...Ts>QK&R<<(QK&out,a d<Ts...>&u){z Qr<E(u),0,sizeof...(Ts)>(out,u);}Q<w T,w S>QK&R<<(QK&out,a std::pair<T,S>&p){z out<<d(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(QP);std::cin.tie(0);std::cout.tie(0);
#define END }
q namespace std;q LL=long long;H solve(){LL x;cin>>x;cout<<(x>=15 and(1<=(x%14)and(x%14)<=6)?("YES"):("NO"))<< "\n";}BEGIN int T;cin>>T;while(T--){solve();}END