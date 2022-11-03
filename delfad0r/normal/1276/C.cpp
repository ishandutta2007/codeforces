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
#define QW bool
#define Wr Finv
#define Qy vs_ptr
#define QQ internal_range_query
#define Qt container_carrying_iterator
#define Qx struct
#define QF jv_ptr
#define z __arg1__
#define We to_nested_vector_impl
#define H other
#define Ww std::ostream
#define Wq iterable_wrapper
#define QC std::vector
#define Qr tuple_tail
#define W0 is_end
#define W9 std::decay_t
#define Qe tuple_head
#define Qw __arg3__
#define k std::end
#define QD static
#define Qu nested_vector_size
#define Qq nested_vector_at
#define QG implicit_lambda_unary_operator
#define o operator
#define w inline
#define L decltype
#define W8 finv_
#define QS std::move
#define QM is_composable_v
#define Qv j_end
#define W7 std::tuple_element_t
#define O return
#define QA std::invoke_result_t
#define Q6 std::forward
#define Qk else
#define Qb implicit_lambda_binary_operator
#define W2 push_back
#define QO apply
#define W6 nested_vector_impl
#define W5 range
#define R std::tuple
#define q Iterator
#define Q8 std::enable_if_t
#define Q7 std::is_rvalue_reference_v
#define Qg def_iterable_ostream
#define M size_t
#define W3 iterator_macro
#define Qz __arg2__
#define Ql implicit_lambda
#define Qm for
#define Qi cartesian_product
#define QI using
#define QH false
#define Q0 this
#define Q_ std::declval
#define W4 std::apply
#define QP std::remove_reference_t
#define Qj std::index_sequence
#define X int
#define QU to_vector
#define QN range_query
#define Qh has_updated
#define QB begin
#define QY def_iterator_manip_iter
#define Q4 internal_build
#define QV advance
#define Q5 iter
#define Qf combinations_with_replacement_impl
#define Q1 size
#define QX __tuple__
#define QT k_ptr
#define Z const
#define QZ true
#define Qc prefix_table_nd
#define E typename
#define Q9 public
#define W template
#define QL make_nested_vector
#define P std::begin
#define QK is_composable_
#define QJ constexpr
#define QR __expr1__
#define Qn GET_5TH_ARG
#define Q3 mutable
#define Qd has_advanced
#define Q2 is_iterable_v
#define QE tuple_many_of_t
#define Qs std::conditional_t
#define Y auto
#define Qa ostream_tuple_helper_
#define Qp std::shared_ptr
#define Qo cartesian_product_incr_
#define Q void
#define W1 std::get

W<E T,M>QI ignore_second=T;W<M...Ix,E T>Y tuple_many_of_impl(Qj<Ix...>,Z T&x){O R(ignore_second<T,Ix>(x)...);}W<M n,E T>Y tuple_many_of(Z T&x){O tuple_many_of_impl(std::make_index_sequence<n>{},x);}W<M n,E T>QI QE=L(tuple_many_of<n,T>(Q_<T>()));W<E...Args>Y Qe(Z R<Args...>&t){O W1<0>(t);}W<M...Ix,E...Args>Y tuple_tail_impl(Qj<Ix...>,Z R<Args...>&t){O R(W1<Ix+1>(t)...);}W<E...Args>Y Qr(Z R<Args...>&t){O tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}Qx empty_t{};QJ empty_t empty_v;W<E T1,E T2>std::common_type_t<T1,T2>maxx(Z T1&x,Z T2&y){if(x<y){O y;}Qk{O x;}} W<E T1,E T2,E...Ts>w Y maxx(Z T1&x,Z T2&y,Z Ts&...xs){O maxx(maxx(x,y),xs...);}W<E T1,E T2>Y minn(Z T1&x,Z T2&y){if(x<=y){O x;}Qk{O y;}} W<E T1,E T2,E...Ts>w Y minn(Z T1&x,Z T2&y,Z Ts&...xs){O minn(minn(x,y),xs...);}QJ X _log2(X x){if(x==0){O 0;}O 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){O f;}
#define FF_1(z,f)[&](Y&&z){(Q)z;O f;}
#define FF_2(z,Qz,f)[&](Y&&z,Y&&Qz){(Q)z;(Q)Qz;O f;}
#define FF_3(z,Qz,Qw,f)[&](Y&&z,Y&&Qz,Y&&Qw){(Q)z;(Q)Qz;(Q)Qw;O f;}
#define FF_macro_chooser(...)Qn(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->Y&{O f;}
#define FREF_1(z,f)[&](Y&&z)->Y&{(Q)z;O f;}
#define FREF_2(z,Qz,f)[&](Y&&z,Y&&Qz)->Y&{(Q)z;(Q)Qz;O f;}
#define FREF_3(z,Qz,Qw,f)[&](Y&&z,Y&&Qz,Y&&Qw)->Y&{(Q)z;(Q)Qz;(Q)Qw;O f;}
#define FREF_macro_chooser(...)Qn(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){O f;}
#define FC_1(z,f,c)[&,c](Y&&z){(Q)z;O f;}
#define FC_2(z,Qz,f,c)[&,c](Y&&z,Y&&Qz){(Q)z;(Q)Qz;O f;}
#define FC_macro_chooser(...)Qn(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){O f;}
#define FC2_1(z,f,c1,c2)[&,c1,c2](Y&&z){(Q)z;O f;}
#define FC2_2(z,Qz,f,c1,c2)[&,c1,c2](Y&&z,Y&&Qz){(Q)z;(Q)Qz;O f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(z,f)[&](Y&&QX){Y&[z]=QX;(Q)z;O f;}
#define FT_2(z,Qz,f)[&](Y&&QX){Y&[z,Qz]=QX;(Q)z;(Q)Qz;O f;}
#define FT_3(z,Qz,Qw,f)[&](Y&&QX){Y&[z,Qz,Qw]=QX;(Q)z;(Q)Qz;(Q)Qw;O f;}
#define FT_4(z,Qz,Qw,__arg4__,f)[&](Y&&QX){Y&[z,Qz,Qw,__arg4__]=QX;(Q)z;(Q)Qz;(Q)Qw;(Q)__arg4__;O f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(QR,f)[&](){Y&&QR;O f;}()
#define LET_2(QR,__expr2__,f)[&](){Y&&QR;Y&&__expr2__;O f;}()
#define LET_3(QR,__expr2__,__expr3__,f)[&](){Y&&QR;Y&&__expr2__;Y&&__expr3__;O f;}()
#define LET_macro_chooser(...)Qn(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)QJ Qx{QI QK=Q;templ w L(Y)o()args Z code}name;
W<E F>class Ql{private:F f;Q9:Ql(F f_):f(f_){} W<E...Ts>QJ Y o()(Ts&&...xs)Z{O f(Q6<Ts>(xs)...);}};Ql _([](Y&&x)->Qs<Q7<L(x)>,QP<L(x)>,L(x)>{O x;});Ql _1([](Y&&x,Y&&)->Qs<Q7<L(x)>,QP<L(x)>,L(x)>{O x;});Ql _2([](Y&&,Y&&y)->Qs<Q7<L(y)>,QP<L(y)>,L(y)>{O y;});
#define implicit_lambda_unary_operator(op)W<E F>QJ L(Y)o op(Ql<F>f){O Ql([=](Y&&...xs){O op f(Q6<L(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)W<E F,E T>QJ L(Y)o op(Ql<F>f,Z T&y){O Ql([=](Y&&...xs){O f(Q6<L(xs)>(xs)...)op y;});}W<E F,E T>QJ L(Y)o op(Z T&y,Ql<F>f){O Ql([=](Y&&...xs){O y op f(Q6<L(xs)>(xs)...);});}W<E F,E G>QJ L(Y)o op(Ql<F>f,Ql<G>g){O Ql([=](Y&&...xs){O f(Q6<L(xs)>(xs)...)op g(Q6<L(xs)>(xs)...);});}
QG(+)QG(-)QG(!)QG(~)QG(*)QG(&)Qb(+)Qb(-)Qb(*)Qb(/)Qb(%)Qb(<)Qb(>)Qb(<=)Qb(>=)Qb(==)Qb(!=)Qb(<<)Qb(>>)Qb(&)Qb(|)Qb(^)Qb(&&)W<E T,E=Q>Qx is_composable:Q9 std::false_type{};W<E T>Qx is_composable<T,std::void_t<E T::is_composable_>>:Q9 std::true_type{};W<E T>QJ QW QM=is_composable<T>::value;W<E T,E F,E=QA<F,T>>L(Y)o>(T&&v,Z F&f){O f(Q6<T>(v));}W<E M1,E M2>Qx composed{QI QK=Q;Z M1 m1;Z M2 m2;W<E T>L(Y)o()(T&&v)Z{O m1(m2(Q6<T>(v)));}};W<E M1,E M2,E=Q8<QM<M1>or QM<M2>>>w Y o<(Z M1&m1,Z M2&m2){O composed<M1,M2>{m1,m2};}W<M n>Qx nth_impl{QI QK=Q;W<E...Ts>QJ W7<n,R<Ts...>>&o()(R<Ts...>&u)Z{O W1<n>(u);}W<E...Ts>QJ W7<n,R<Ts...>>o()(R<Ts...>&&u)Z{O W1<n>(u);}W<E...Ts>QJ Z W7<n,R<Ts...>>&o()(Z R<Ts...>&u)Z{O W1<n>(u);}W<E...Ts>QJ Z W7<n,R<Ts...>>o()(Z R<Ts...>&&u)Z{O W1<n>(u);}};W<M n>QJ nth_impl<n>nth;QJ nth_impl<0>fst;QJ nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)Qx q{extra QW o!=(Z q&H)Z neq q&o++()incr L(Y)o*()Z val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,it_end,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{W3(extra extra_it Q3 I it;,neq_it,incr_it,val_it);O Wq(it_begin,it_end);})
#define def_iterator_manip_2(name,code)QJ Qx{QI QK=Q;W<E T,E I=L(P(Q_<T>())),E V=W9<L(*Q_<I>())>>L(Y)o()(T&&v)Z code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ Qx name##_impl{QI QK=Q;extra W<E T,E I=L(P(Q_<T>())),E V=W9<L(*Q_<I>())>>L(Y)o()(T&&v)Z code};templ w L(Y)name args{O name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
W<E T,E=Q>Qx is_iterable:Q9 std::false_type{};W<E T>Qx is_iterable<T,std::void_t<L(P(Q_<T>())),L(k(Q_<T>()))>>:Q9 std::true_type{};W<E T>QJ QW Q2=is_iterable<T>::value;W<E I>w Y Wq(Z I&b,Z I&e){Qx Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
QI is_iterable_wrapper=Q;QI iterator=I;QI value_type=W9<L(*Q_<I>())>;
#pragma GCC diagnostic pop
I b,e;Y QB()Z{O b;}Y end()Z{O e;}};O Wrapper{b,e};}W<E T>w Y Q5(T&&iterable){O Wq(P(Q6<T>(iterable)),k(Q6<T>(iterable)));}W<E I>w Y Q5(Z I&b,Z I&e){O Wq(b,e);}W<E C>Qx Qt:Q9 C::iterator{Qp<C>p;Qt(Qp<C>p_,E C::iterator it):C::iterator(it),p(p_){}};W<E C>w Y iterc(C&&v){QI D=W9<C>;Qp<D>p(new D(Q6<C>(v)));O Wq(Qt<D>{p,P(*p)},Qt<D>{p,k(*p)});}W<E T>w Y Q5(std::initializer_list<T>l){O iterc(QC<T>(l));}def_template_lambda(W<E T>,QU,(T&&v),{QC<E W9<T>::value_type>s;Qm(Y&&x:v){s.W2(x);}O s;})W<M n>Qx We{W<E T>w QD Y make(T&&v){O Q6<T>(v)>QO(FF(u,We<n-1>::make(u)))>QU;}};W<>Qx We<1>{W<E T>w QD Y make(T&&v){O Q6<T>(v)>QU;}};W<M n>Qx to_nested_vector_{QI QK=Q;W<E T>w L(Y)o()(T&&v)Z{O We<n>::make(Q6<T>(v));}};W<M n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(M l,M r),({l,r}),M l;M r;,{O Q5(P(v)+l,P(v)+r);})def_iterator_manip(is_nil,{O not(P(v)!=k(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{M l=0;Qm(Y i=P(v);i!=k(v);++i){++l;}O l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
W<E T1,E T2,E T3,E T=std::make_signed_t<L(T1()+T2()+T3())>>w Y W5(Z T1&b,Z T2&e,Z T3&step){W3(T x;T e;T step;w QW W0()Z{O(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{O W0()xor H.W0();},{x+=step;O*Q0;},{O T(x);}) O Q5(q{b,e,step},q{e,e,step});}W<E T1,E T2>w Y W5(Z T1&b,Z T2&e){O W5(b,e,L(T1()+T2())(1));}W<E T>w Y W5(Z T&e){O W5(T(),e,T(1));} 
#pragma GCC diagnostic pop
W<E T>w Y to_infinity(Z T&b=0,Z T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
W3(T x;T step;,{(Q)H;O QZ;},{x+=step;O*Q0;},{O T(x);}) O Q5(q{b,step},q{b,step});
#pragma GCC diagnostic pop
}QY(QO,W<E F>,(F f),<F>{f},F f;,(q{f,P(v)}),(q{f,k(v)}),,{ O it!=H.it;},{++it;O*Q0;},{O f(*it);}) QY(take,,(M n),{n},M n;,(q{n,P(v)}),(q{0,k(v)}),,{ O n!=H.n;},{--n;if(n>0){++it;}O*Q0;},{O*it;}) QY(take_while,W<E F>,(F f),<F>{f},F f;,(q{f,not(P(v)!=k(v)and f(*P(v))),P(v)}),(q{f,QZ,k(v)}),QW W0;,{O W0 xor H.W0;},{++it;if(not f(*it)){W0=QZ;}O*Q0;},{O*it;}) QY(drop,,(M n),{n},Q3 M n;,(q{n,k(v),P(v)}),(q{0,k(v),k(v)}),Z I end_it;w Q QV()Z{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{QV();H.QV();O it!=H.it;},{QV();++it;O*Q0;},{QV();O*it;}) QY(drop_while,W<E F>,(F f),<F>{f},F f;,(q{f,k(v),QH,P(v)}),(q{f,k(v),QZ,k(v)}),Z I end_it;Q3 QW Qd;w Q QV()Z{if(not Qd){while(it!=end_it and f(*it)){++it;}Qd=QZ;}},{QV();H.QV();O it!=H.it;},{QV();++it;O*Q0;},{QV();O*it;}) def_iterator_manip(head,{O*P(v);})w Y tail=drop(1);w Y at(M n){O head<drop(n);}QY(cons,W<E S>,(S s),<S>{s},S s;,(q{s,QZ,P(v)}),(q{s,QH,k(v)}),QW is_s;,{O is_s!=H.is_s or it!=H.it;},{if(is_s){is_s=QH;}Qk{++it;}O*Q0;},{O(is_s)?(s):(*it);}) def_iterator_manip(snoc,{Y it=P(v);Y h=*it;++it;O R(h,Q5(it,k(v)));})def_iterator_manip(split_at,,(M n),{n},M n;,{Y it=P(v);QC<T>u;Qm(Y i:W5(n)){u.W2(*it);++it;}O R(iterc(QS(u)),Q5(it,k(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
QY(chunks_of,,(M n),{n},M n;,(q{n,{},QH,k(v),P(v)}),(q{n,{},QH,k(v),k(v)}),Q3 QC<V>u;Q3 QW Qh;I it_end;Q update()Z{u.clear();Qh=QZ;Qm(Y i:W5(n)){if(it!=it_end){u.W2(*it);++it;}Qk{break;}}},{O it!=H.it;},{if(Qh){Qh=QH;}Qk{Qm(Y i:W5(n)){if(it!=it_end){++it;}Qk{break;}}}O*Q0;},{if(not Qh){update();}O iterc(u);})
#pragma GCC diagnostic pop
W<E F,E S>Qx fold_impl{QI QK=Q;F f;S s;W<E T>Y o()(Z T&v)Z{Y x=s;Qm(Y y:v){x=f(x,y);}O x;}};W<E F,E S>w Y fold(F f,Z S&s){O fold_impl<F,S>{f,s};}def_iterator_manip(fold1,W<E F>,(F f),<F>{f},F f;,{Y u=v>snoc;O u>snd>fold(f,u>fst);})def_iterator_manip(sum,{O v>fold(_1+_2,V(0));})def_iterator_manip(product,{O v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,W<E F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{O v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,W<E F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,W<E F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{O v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,W<E F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})W<E F,E S>Qx scan_impl{QI QK=Q;F f;S s;W<E T,E I=L(P(Q_<T>()))>L(Y)o()(T&&v)Z{W3(F f;Q3 S s;Q3 QW Qh;QW Qd;Q3 I it;,{O it!=H.it;},{if(not Qh){s=f(s,*it);};Qh=QH;if(Qd){++it;}Qk{Qd=QZ;}O*Q0;},{if(not Qh){Qh=QZ;s=f(s,*it);}O s;}) O Q5(q{f,s,QZ,QH,P(Q6<T>(v))},q{f,s,QZ,QZ,k(Q6<T>(v))});}};W<E F,E S>w Y scan(F f,Z S&s){O scan_impl<F,S>{f,s};}QY(scan1,W<E F>,(F f),<F>{f},F f;,(q{f,*P(v),QZ,P(v)}),(q{f,*P(v),QZ,k(v)}),Q3 V s;Q3 QW Qh;,{O it!=H.it;},{if(not Qh){s=f(s,*it);};Qh=QH;++it;O*Q0;},{if(not Qh){Qh=QZ;s=f(s,*it);}O s;}) W<E T,E S,E I=L(P(Q_<T>())),E J=L(P(Q_<S>()))>w Y o+(T&&v,S&&u){W3(I i;I i_end;J j;QW in_i;,{O i!=H.i or j!=H.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=QH;}}Qk{++j;}O*Q0;},{O(in_i)?(*i):(*j);}) I bv=P(v);I ev=k(v);J bu=P(u);J eu=k(u);O Q5(q{bv,ev,bu,bv!=ev},q{ev,ev,eu,QH});}QJ Qx{QI QK=Q;W<E T>Y o()(T&&v)Z{Y u=Q6<T>(v)>filter(FF(i,not is_nil(i)));Y b=P(u);Y e=k(u);QI J=L(b);QI V=W9<L(*b)>;QI K=L(P(*b));Qx q{J j;J Qv;Qp<V>QF;K*QT;QW W0;q(J j,J Qv,Z V&jv,QW W0):j(j),Qv(Qv),QF(new V(jv)),QT(new K(P(*QF))),W0(W0){} q(J j,J Qv,QW W0):j(j),Qv(Qv),QF(nullptr),QT(nullptr),W0(W0){} q(Z q&H):j(H.j),Qv(H.Qv),QF(H.QF),QT((H.QT)?(new K(*H.QT)):nullptr),W0(H.W0){} q(q&&H):j(H.j),Qv(H.Qv),QF(H.QF),QT((H.QT)?(new K(*H.QT)):nullptr),W0(H.W0){}~q(){delete QT;}QW o!=(Z q&H)Z{O W0 xor H.W0;}q&o++(){++*QT;if(not(*QT!=k(*QF))){++j;if(j!=Qv){delete QT;QF=std::make_shared<V>(*j);QT=new K(P(*QF));}Qk{W0=QZ;}} O*Q0;}L(Y)o*()Z{O**QT;}};if(u>is_nil){O Wq(q(b,e,QZ),q(b,e,QZ));}Qk{O Wq(q(b,e,*b,QH),q(e,e,QZ));}}}flatten;W<E T,E F,E=Q8<Q2<T>>>Y o>=(T&&v,F f){O v>QO(f)>flatten;}W<E U,M...Is>w QW all_different_(Z U&x,Z U&y,Qj<Is...>){O((W1<Is>(x)!=W1<Is>(y))&&...);}W<E F,E...Ts>w Y zip_with(F f,Ts&&...vs){W3(F f;R<L(P(Q_<Ts>()))...>its;,{O all_different_(its,H.its,std::index_sequence_for<Ts...>{});},{W4([&](Y&&...xs){(++xs,...);},its);O*Q0;},{O W4([&](Y&&...xs){O f(*xs...);},its);}) O Q5(q{f,R(P(vs)...)},q{f,R(k(vs)...)});};Qx zip_default_function_{W<E...Ts>L(Y)o()(Ts&&...xs)Z{O R<Ts...>(Q6<Ts>(xs)...);}};W<E...Ts>w Y zip(Ts&&...vs){O zip_with(zip_default_function_{},Q6<Ts>(vs)...);}QY(filter,W<E F>,(F f),<F>{f},F f;,(q{f,k(v),P(v)}),(q{f,k(v),k(v)}),Z I end_it;w Q QV()Z{while(it!=end_it and not f(*it)){++it;}},{QV();H.QV();O it!=H.it;},{QV();++it;O*Q0;},{QV();O*it;}) def_template_lambda(W<E T>,repeat,(T&&v),{Qx q{Z W9<T>v;QW o!=(Z q&)Z{O QZ;}q&o++(){O*Q0;}Z Y&o*()Z{O v;}};O Q5(q{v},q{v});})w Y replicate(M n){O take(n)<repeat;}w Y cycle=flatten<repeat;def_iterator_manip(enumerate,{O zip(to_infinity(M(0)),v);})def_iterator_manip(reversed,{Y s=v>QU;std::reverse(s.QB(),s.end());O iterc(QS(s));})def_iterator_manip(sorted_by,W<E F>,(F f),<F>{f},F f;,{Y s=v>QU;std::sort(P(s),k(s),f);O iterc(QS(s));})def_iterator_manip(sorted,{O v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,W<E F>,(F f),<F>{f},F f;,{O v>QO(FF(i,R(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>QO(fst);})def_iterator_manip(nub,{W3(I it_end;I it;,{O it!=H.it;},{L(*it)pr;do{pr=*it;++it;}while(it!=it_end and pr==*it);O*Q0;},{O*it;}) Y b=P(v);Y e=k(v);O Q5(q{e,b},q{e,e});})W<E F,E S>Qx accum_vector_by_{QI QK=Q;M n;F f;S s;W<E T,E I=L(P(Q_<T>())),E V=W9<L(*Q_<I>())>>L(Y)o()(Z T&v)Z{QC<W9<QA<F,S,L(W1<1>(Q_<V>()))>>>u(n,s);Qm(Y&&[i,x]:v){u[i]=f(u[i],x);}O u;}};W<E F,E S>w Y accum_vector_by(M n,F f,Z S&s){O accum_vector_by_<F,S>{n,f,s};}W<E S>w Y accum_vector(M n,Z S&s=S()){O accum_vector_by(n,_2,s);}W<E F,E S>Qx accum_map_by_{QI QK=Q;F f;S s;W<E T,E I=L(P(Q_<T>())),E V=W9<L(*Q_<I>())>>L(Y)o()(Z T&v)Z{std::map<W9<L(W1<0>(Q_<V>()))>,W9<QA<F,S,L(W1<1>(Q_<V>()))>>>u;Qm(Y&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qk{u[i]=f(s,x);}} O u;}};W<E F,E S>w Y accum_map_by(F f,Z S&s){O accum_map_by_<F,S>{f,s};}W<E S>w Y accum_map(Z S&s=S()){O accum_map_by(_2,s);}W<E F,E S>Qx accum_unordered_map_by_{QI QK=Q;F f;S s;W<E T,E I=L(P(Q_<T>())),E V=W9<L(*Q_<I>())>>L(Y)o()(Z T&v)Z{std::unordered_map<W9<L(W1<0>(Q_<V>()))>,W9<QA<F,S,L(W1<1>(Q_<V>()))>>>u;Qm(Y&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qk{u[i]=f(s,x);}} O u;}};W<E F,E S>w Y accum_unordered_map_by(F f,Z S&s){O accum_unordered_map_by_<F,S>{f,s};}W<E S>w Y accum_unordered_map(Z S&s=S()){O accum_unordered_map_by(_2,s);}W<E U,M...Is>w QW any_different_(Z U&x,Z U&y,Qj<Is...>){O((W1<Is>(x)!=W1<Is>(y))||...);}W<M N,E q>w Q Qo(q&it){if QJ(N>=1){++W1<N-1>(it.its);if(not(W1<N-1>(it.its)!=k(W1<N-1>(*it.my_vs_ptr)))){W1<N-1>(it.its)=P(W1<N-1>(*it.my_vs_ptr));Qo<N-1>(it);}} Qk{it.its=W4([](Y&&...xs){O R(k(xs)...);},*it.my_vs_ptr);}} W<E...Ts>Y Qi(Ts&&...vs){Y Qy=std::make_shared<R<Qs<Q7<Ts>,QP<Ts>,Ts>...>>(vs...);W3(R<L(P(Q_<Qs<Q7<Ts>,QP<Ts>,Ts>>()))...>its;L(Qy)my_vs_ptr;,{O any_different_(its,H.its,std::index_sequence_for<Ts...>{});},{Qo<sizeof...(Ts)>(*Q0);O*Q0;},{O W4([](Y&&...xs){O R<L(*xs)...>(*xs...);},its);}) if(W4([](Y&&...xs){O((xs>is_nil)||...);},*Qy)){O Q5(q{W4([](Y&&...xs){O R(k(xs)...);},*Qy),Qy},q{W4([](Y&&...xs){O R(k(xs)...);},*Qy),Qy});}Qk{O Q5(q{W4([](Y&&...xs){O R(P(xs)...);},*Qy),Qy},q{W4([](Y&&...xs){O R(k(xs)...);},*Qy),Qy});}};W<E...Ts>w Y cartesian_product_range(Z Ts&...n){O Qi(W5(n)...);}W<M n,E I>w Y cartesian_power(Z I&v){O W4([](Z Y&...vs){O Qi(vs...);},tuple_many_of<n>(v));}Qx{QI QK=Q;X n=-1;W<E T>Y o()(T&&v)Z{if QJ(std::is_convertible_v<T,X>){Y x=*Q0;x.n=v;O x;}Qk{Y vec=v>QU;X m=vec.Q1();Qx q{X n;L(vec)my_v;QC<M>cycles;QW W0;QW o!=(Z q&H)Z{O W0 xor H.W0;}q&o++(){Qm(Y i:W5(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=my_v.Q1()-i;std::rotate(my_v.QB()+i,my_v.QB()+i+1,my_v.end());}Qk{std::swap(my_v[i],my_v[my_v.Q1()-cycles[i]]);O*Q0;}} W0=QZ;O*Q0;}Y o*()Z{O my_v>array_slice(0,n);}};X n1=(n<0)?(m):(n);O Q5(q{n1,QS(vec),W5(m,m-n1,-1)>QO(FF(x,M(x)))>QU,QH},q{n1,{},{},QZ});}}}permutations;Qx combinations_impl{QI QK=Q;X n;W<E T>Y o()(T&&v)Z{Y vec=v>QU;X m=vec.Q1();W3(X n;L(vec)my_v;QC<M>idx;QW W0;,{O W0 xor H.W0;},{Qm(Y i:W5(n-1,-1,-1)){if(idx[i]!=idx.Q1()-n+i){idx[i]++;Qm(Y j:W5(i+1,n)){idx[j]=idx[j-1]+1;}O*Q0;}} W0=QZ;O*Q0;},{O idx>array_slice(0,n)>QO(FF(i,my_v[i]));}) O Q5(q{n,QS(vec),W5(0,m)>QO(FF(x,M(x)))>QU,QH},q{n,{},{},QZ});}};w Y combinations(X n){O combinations_impl{n};}Qx Qf{QI QK=Q;X n;W<E T>Y o()(T&&v)Z{Y vec=v>QU;X m=vec.Q1();W3(X n;L(vec)my_v;QC<M>idx;QW W0;,{O W0 xor H.W0;},{Qm(Y i:W5(n-1,-1,-1)){if(idx[i]!=idx.Q1()-1){idx[i]++;Qm(Y j:W5(i+1,n)){idx[j]=idx[i];}O*Q0;}} W0=QZ;O*Q0;},{O idx>array_slice(0,n)>QO(FF(i,my_v[i]));}) O Q5(q{n,QS(vec),M(0)>replicate(m)>QU,QH},q{n,{},{},QZ});}};w Y combinations_with_replacement(X n){O Qf{n};}W<E T>w Y istream_iterable(std::istream&in){W3(std::istream&in;Q3 T val;QW W0;Q3 QW has_read;,{O W0 xor H.W0;},{if(not(in>>val)){W0=QZ;}O*Q0;},{if(not has_read){has_read=QZ;in>>val;}O val;}) O Q5(q{in,T{},QH,QH},q{in,T{},QZ,QZ});}W<E T>w Y input=istream_iterable<T>(std::cin);W<E T>Ww&print_iterable(Ww&out,Z T&v,Z std::string&sep= " "){Qm(Y it=P(v);it!=k(v);){ out<<*it;++it;if(it!=k(v)){out<<sep;}Qk{O out;}} O out;}W<E T,E=E T::is_iterable_wrapper>w Ww&o<<(Ww&out,Z T&v){out<< "[";O print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)W<E...Ts>Ww&o<<(Ww&out,Z I<Ts...>&v){O out<<Q5(v);}
Qg(QC)Qg(std::map)Qg(std::unordered_map)Qg(std::set)Qg(std::unordered_set)W<M n,E T>Qx W6{QI type=QC<E W6<n-1,T>::type>;QD Y make(Z QE<n,M>&sz,Z T&val=T()){O QC(Qe(sz),W6<n-1,T>::make(Qr(sz),val));}};W<E T>Qx W6<1,T>{QI type=QC<T>;QD Y make(Z R<M>&sz,Z T&val=T()){O QC(Qe(sz),val);}};W<M n,E T>QI nested_vector=E W6<n,T>::type;W<M n,E T>Y QL(Z QE<n,M>&sz,Z T&val=T()){O W6<n,T>::make(sz,val);}W<M n,E T>w Y Qu(Z T&v){if QJ(n==1){O R(v.Q1());}Qk{O std::tuple_cat(R(v.Q1()),Qu<n-1>(v[0]));}} W<M n,E T>w Y nested_vector_indices(Z T&v){O W4([&](Y...x){O cartesian_product_range(x...);},Qu<n>(v));}W<M n,E T>w L(Y)Qq(Z QC<T>&v,Z QE<n,M>&i){if QJ(n==1){O v[Qe(i)];}Qk{O Qq<n-1>(v[Qe(i)],Qr(i));}} W<M n,E T>w L(Y)Qq(QC<T>&v,Z QE<n,M>&i){if QJ(n==1){O v[Qe(i)];}Qk{O Qq<n-1>(v[Qe(i)],Qr(i));}} W<E U,M i,M s>Ww&Qa(Ww&out,Z U&u){if QJ(i==0){out<< "{ ";}out<<W1<i>(u);if QJ(i+1<s){out<< ", ";O Qa<U,i+1,s>(out,u);}Qk{O out<< " }";}} W<E...Ts>Ww&o<<(Ww&out,Z R<Ts...>&u){O Qa<L(u),0,sizeof...(Ts)>(out,u);}W<E T,E S>Ww&o<<(Ww&out,Z std::pair<T,S>&p){O out<<R(p.first,p.second);} 
#define BEGIN  X main(){std::ios_base::sync_with_stdio(QH);std::cin.tie(0);std::cout.tie(0);
#define END }
QI namespace std;QI LL=long long;W<M d,E T,E F,E Wr>class Qc{friend class Qc<d+1,T,F,Wr>;private:F f;Wr finv;T id;QE<d,M>n;nested_vector<d,T>pt;W<E I>w QD Q Q4(nested_vector<d,T>&p,Z I&v,F f_){Qm(Y[i,j]:zip(p>tail,v)){Qc<d-1,T,F,Wr>::internal_build(i,j,f_);}Qm(Y i:nested_vector_indices<d-1>(p[0])){Qm(Y j:W5(1,p.Q1())){Qq<d-1>(p[j],i)=f_(Qq<d-1>(p[j-1],i),Qq<d-1>(p[j],i));}}}W<E I>w QD T QQ(Z QE<d,M>&l,Z QE<d,M>&r,Z I&v,Wr W8){O W8(Qc<d-1,T,F,Wr>::internal_range_query(Qr(l),Qr(r),v[Qe(r)],W8),Qc<d-1,T,F,Wr>::internal_range_query(Qr(l),Qr(r),v[Qe(l)],W8));}Q9:Qc(F f_,Wr W8,Z T&id_):f(f_),finv(W8),id(id_){} Qc(Z QE<d,M>&n_,F f_,Wr W8,Z T&id_):f(f_),finv(W8),id(id_),n(n_),pt(QL<d,T>(W4([](Y...x){O R((x+1)...);},n),id)){} W<E J,E=Q8<Q2<J>>>Qc(Z QE<d,M>&n_,Z J&v,F f_,Wr W8,Z T&id_):f(f_),finv(W8),id(id_){build(n_,v);}W<E I>Q build(Z QE<d,M>&n_,Z I&v){n=n_;pt=QL<d,T>(W4([](Y...x){O R((x+1)...);},n),id);Q4(pt,v,f);}w T QN(Z QE<d,M>&l,Z QE<d,M>&r)Z{O QQ(l,r,pt,finv);}w Y Q1()Z{O n;}};W<E T,E F,E Wr>class Qc<1,T,F,Wr>{friend class Qc<2,T,F,Wr>;private:F f;Wr finv;T id;M n;QC<T>pt;W<E I>w QD Q Q4(QC<T>&p,Z I&v,F f_){Qm(Y[i,j]:zip(p>tail,v)){i=j;}Qm(Y i:W5(1,p.Q1())){p[i]=f_(p[i-1],p[i]);}} W<E I>w QD T QQ(Z R<M>&l,Z R<M>&r,Z I&v,Wr W8){O W8(v[Qe(r)],v[Qe(l)]);}Q9:Qc(F f_,Wr W8,Z T&id_):f(f_),finv(W8),id(id_){} Qc(Z R<M>&n_,F f_,Wr W8,Z T&id_):f(f_),finv(W8),id(id_),n(Qe(n_)),pt(n,id){} W<E J,E=Q8<Q2<J>>>Qc(Z R<M>&n_,Z J&v,F f_,Wr W8,Z T&id_):f(f_),finv(W8),id(id_){build(n_,v);}W<E I>Q build(Z R<M>&n_,Z I&v){n=Qe(n_);pt=QC(n+1,id);Q4(pt,v,f);}w T QN(Z R<M>&l,Z R<M>&r)Z{O QQ(l,r,pt,finv);}w T QN(M l,M r)Z{O QN(R(l),R(r));}w Y Q1()Z{O n;}};W<M d,E T,E F=std::plus<T>,E Wr=std::minus<T>>Y make_prefix_table_nd(F f=F(),Wr finv=Wr(),Z T&id=T{}){O Qc<d,T,F,Wr>(f,finv,id);}W<E T,E F=std::plus<T>,E Wr=std::minus<T>>Y make_prefix_table(F f=F(),Wr finv=Wr(),Z T&id=T{}){O Qc<1,T,F,Wr>(f,finv,id);}BEGIN X N;cin>>N;vector<X>A(N);Qm(X&a:A){cin>>a;}sort(A.QB(),A.end());vector<tuple<X,X>>S;Qm(Y a:A){if(S.empty()or fst(S.back())!=a){S.emplace_back(a,1);}Qk{snd(S.back())++;}} sort(S.QB(),S.end(),FF(x,y,snd(x)<snd(y)));Y B=S>QO(fst)>QU;Y C=S>QO(snd)>QU;Y pt=make_prefix_table<X>();pt.build(N,C);X best_r=1;X best_cnt=1;Qm(X r=1;r*r<=N;++r){Y x=lower_bound(C.QB(),C.end(),r)-C.QB();X c=(pt.QN(0,x)+r*(C.Q1()-x))/r;if(c<r){continue;}X cnt=c*r;if(cnt>best_cnt){best_cnt=cnt;best_r=r;}} X r=best_r;X x=lower_bound(C.QB(),C.end(),best_r)-C.QB();X c=(pt.QN(0,x)+r*(C.Q1()-x))/r;vector<X>u;Qm(X i=0;i<x;++i){Qm(X t:W5(C[i])){u.W2(B[i]);}} Qm(X i=x;i<X(C.Q1());++i){Qm(X t:W5(r)){u.W2(B[i]);}} Y ans=QL<2,X>({r,c});X s=0,t=0;Qm(X i=0;i<r*c;++i){ans[s][t]=u.back();u.pop_back();s=(s+1)%r;t=(t+1)%c;if(ans[s][t]!=0){s+=1;assert(i==(r*c-1)or ans[s][t]==0);}} cout<<(r*c)<< "\n";cout<<r<< " " <<c<< "\n";Qm(Y&y:ans){Qm(Y i:y){cout<<i<< " ";}cout<< "\n";}END