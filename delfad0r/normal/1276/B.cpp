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
#define QD std::index_sequence
#define o typename
#define Qf else
#define QX std::conditional_t
#define z other
#define W1 has_advanced
#define Q8 nested_vector_impl
#define Qv __tuple__
#define Qd visited
#define Qs std::ostream
#define Q9 ostream_tuple_helper_
#define Z size_t
#define QW nested_vector_at
#define Qx mutable
#define QO vs_ptr
#define Qa this
#define QJ cartesian_product_incr_
#define Q_ to_nested_vector_impl
#define QH vector
#define Qy std::get
#define Qw is_composable_
#define Qh has_updated
#define QB __arg3__
#define Qo tuple_many_of_t
#define w void
#define QU jv_ptr
#define QE false
#define Qm std::invoke_result_t
#define Qq implicit_lambda_binary_operator
#define Qk advance
#define Q0 __arg2__
#define Ql def_iterator_manip_iter
#define QN std::shared_ptr
#define QY using
#define QQ k_ptr
#define Qn is_end
#define QG std::is_rvalue_reference_v
#define QF std::apply
#define QV std::declval
#define QZ iter
#define QR bool
#define L const
#define Qb implicit_lambda
#define W template
#define Qu GET_5TH_ARG
#define Q4 std::remove_reference_t
#define Qi cartesian_product
#define QM to_vector
#define QL __expr1__
#define k __arg1__
#define QC std::tuple
#define Qj true
#define QS constexpr
#define Q7 iterable_wrapper
#define QT iterator_macro
#define QA combinations_with_replacement_impl
#define E std::end
#define Q3 tuple_head
#define O return
#define a operator
#define QK std::forward
#define Qp std::decay_t
#define Qt struct
#define Q1 int
#define Q6 j_end
#define Y Iterator
#define H std::begin
#define Qg container_carrying_iterator
#define Qc def_iterable_ostream
#define P decltype
#define Qr std::move
#define d inline
#define QP std::vector
#define Qz nested_vector_size
#define Qe push_back
#define Q5 implicit_lambda_unary_operator
#define X auto
#define QI std::tuple_element_t
#define Q2 range

W<o T,Z>QY ignore_second=T;W<Z...Ix,o T>X tuple_many_of_impl(QD<Ix...>,L T&x){O QC(ignore_second<T,Ix>(x)...);}W<Z n,o T>X tuple_many_of(L T&x){O tuple_many_of_impl(std::make_index_sequence<n>{},x);}W<Z n,o T>QY Qo=P(tuple_many_of<n,T>(QV<T>()));W<o...Args>X Q3(L QC<Args...>&t){O Qy<0>(t);}W<Z...Ix,o...Args>X tuple_tail_impl(QD<Ix...>,L QC<Args...>&t){O QC(Qy<Ix+1>(t)...);}W<o...Args>X tuple_tail(L QC<Args...>&t){O tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}Qt empty_t{};QS empty_t empty_v;W<o T1,o T2>std::common_type_t<T1,T2>maxx(L T1&x,L T2&y){if(x<y){O y;}Qf{O x;}} W<o T1,o T2,o...Ts>d X maxx(L T1&x,L T2&y,L Ts&...xs){O maxx(maxx(x,y),xs...);}W<o T1,o T2>X minn(L T1&x,L T2&y){if(x<=y){O x;}Qf{O y;}} W<o T1,o T2,o...Ts>d X minn(L T1&x,L T2&y,L Ts&...xs){O minn(minn(x,y),xs...);}QS Q1 _log2(Q1 x){if(x==0){O 0;}O 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){O f;}
#define FF_1(k,f)[&](X&&k){(w)k;O f;}
#define FF_2(k,Q0,f)[&](X&&k,X&&Q0){(w)k;(w)Q0;O f;}
#define FF_3(k,Q0,QB,f)[&](X&&k,X&&Q0,X&&QB){(w)k;(w)Q0;(w)QB;O f;}
#define FF_macro_chooser(...)Qu(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->X&{O f;}
#define FREF_1(k,f)[&](X&&k)->X&{(w)k;O f;}
#define FREF_2(k,Q0,f)[&](X&&k,X&&Q0)->X&{(w)k;(w)Q0;O f;}
#define FREF_3(k,Q0,QB,f)[&](X&&k,X&&Q0,X&&QB)->X&{(w)k;(w)Q0;(w)QB;O f;}
#define FREF_macro_chooser(...)Qu(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){O f;}
#define FC_1(k,f,c)[&,c](X&&k){(w)k;O f;}
#define FC_2(k,Q0,f,c)[&,c](X&&k,X&&Q0){(w)k;(w)Q0;O f;}
#define FC_macro_chooser(...)Qu(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){O f;}
#define FC2_1(k,f,c1,c2)[&,c1,c2](X&&k){(w)k;O f;}
#define FC2_2(k,Q0,f,c1,c2)[&,c1,c2](X&&k,X&&Q0){(w)k;(w)Q0;O f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(k,f)[&](X&&Qv){X&[k]=Qv;(w)k;O f;}
#define FT_2(k,Q0,f)[&](X&&Qv){X&[k,Q0]=Qv;(w)k;(w)Q0;O f;}
#define FT_3(k,Q0,QB,f)[&](X&&Qv){X&[k,Q0,QB]=Qv;(w)k;(w)Q0;(w)QB;O f;}
#define FT_4(k,Q0,QB,__arg4__,f)[&](X&&Qv){X&[k,Q0,QB,__arg4__]=Qv;(w)k;(w)Q0;(w)QB;(w)__arg4__;O f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(QL,f)[&](){X&&QL;O f;}()
#define LET_2(QL,__expr2__,f)[&](){X&&QL;X&&__expr2__;O f;}()
#define LET_3(QL,__expr2__,__expr3__,f)[&](){X&&QL;X&&__expr2__;X&&__expr3__;O f;}()
#define LET_macro_chooser(...)Qu(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)QS Qt{QY Qw=w;templ d P(X)a()args L code}name;
W<o F>class Qb{private:F f;public:Qb(F f_):f(f_){} W<o...Ts>QS X a()(Ts&&...xs)L{O f(QK<Ts>(xs)...);}};Qb _([](X&&x)->QX<QG<P(x)>,Q4<P(x)>,P(x)>{O x;});Qb _1([](X&&x,X&&)->QX<QG<P(x)>,Q4<P(x)>,P(x)>{O x;});Qb _2([](X&&,X&&y)->QX<QG<P(y)>,Q4<P(y)>,P(y)>{O y;});
#define implicit_lambda_unary_operator(op)W<o F>QS P(X)a op(Qb<F>f){O Qb([=](X&&...xs){O op f(QK<P(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)W<o F,o T>QS P(X)a op(Qb<F>f,L T&y){O Qb([=](X&&...xs){O f(QK<P(xs)>(xs)...)op y;});}W<o F,o T>QS P(X)a op(L T&y,Qb<F>f){O Qb([=](X&&...xs){O y op f(QK<P(xs)>(xs)...);});}W<o F,o G>QS P(X)a op(Qb<F>f,Qb<G>g){O Qb([=](X&&...xs){O f(QK<P(xs)>(xs)...)op g(QK<P(xs)>(xs)...);});}
Q5(+)Q5(-)Q5(!)Q5(~)Q5(*)Q5(&)Qq(+)Qq(-)Qq(*)Qq(/)Qq(%)Qq(<)Qq(>)Qq(<=)Qq(>=)Qq(==)Qq(!=)Qq(<<)Qq(>>)Qq(&)Qq(|)Qq(^)Qq(&&)W<o T,o=w>Qt is_composable:public std::false_type{};W<o T>Qt is_composable<T,std::void_t<o T::is_composable_>>:public std::true_type{};W<o T>QS QR is_composable_v=is_composable<T>::value;W<o T,o F,o=Qm<F,T>>P(X)a>(T&&v,L F&f){O f(QK<T>(v));}W<o M1,o M2>Qt composed{QY Qw=w;L M1 m1;L M2 m2;W<o T>P(X)a()(T&&v)L{O m1(m2(QK<T>(v)));}};W<o M1,o M2,o=std::enable_if_t<is_composable_v<M1>or is_composable_v<M2>>>d X a<(L M1&m1,L M2&m2){O composed<M1,M2>{m1,m2};}W<Z n>Qt nth_impl{QY Qw=w;W<o...Ts>QS QI<n,QC<Ts...>>&a()(QC<Ts...>&u)L{O Qy<n>(u);}W<o...Ts>QS QI<n,QC<Ts...>>a()(QC<Ts...>&&u)L{O Qy<n>(u);}W<o...Ts>QS L QI<n,QC<Ts...>>&a()(L QC<Ts...>&u)L{O Qy<n>(u);}W<o...Ts>QS L QI<n,QC<Ts...>>a()(L QC<Ts...>&&u)L{O Qy<n>(u);}};W<Z n>QS nth_impl<n>nth;QS nth_impl<0>fst;QS nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)Qt Y{extra QR a!=(L Y&z)L neq Y&a++()incr P(X)a*()L val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,it_end,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{QT(extra extra_it Qx I it;,neq_it,incr_it,val_it);O Q7(it_begin,it_end);})
#define def_iterator_manip_2(name,code)QS Qt{QY Qw=w;W<o T,o I=P(H(QV<T>())),o V=Qp<P(*QV<I>())>>P(X)a()(T&&v)L code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ Qt name##_impl{QY Qw=w;extra W<o T,o I=P(H(QV<T>())),o V=Qp<P(*QV<I>())>>P(X)a()(T&&v)L code};templ d P(X)name args{O name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
W<o T,o=w>Qt is_iterable:public std::false_type{};W<o T>Qt is_iterable<T,std::void_t<P(H(QV<T>())),P(E(QV<T>()))>>:public std::true_type{};W<o T>QS QR is_iterable_v=is_iterable<T>::value;W<o I>d X Q7(L I&b,L I&e){Qt Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
QY is_iterable_wrapper=w;QY iterator=I;QY value_type=Qp<P(*QV<I>())>;
#pragma GCC diagnostic pop
I b,e;X begin()L{O b;}X end()L{O e;}};O Wrapper{b,e};}W<o T>d X QZ(T&&iterable){O Q7(H(QK<T>(iterable)),E(QK<T>(iterable)));}W<o I>d X QZ(L I&b,L I&e){O Q7(b,e);}W<o C>Qt Qg:public C::iterator{QN<C>p;Qg(QN<C>p_,o C::iterator it):C::iterator(it),p(p_){}};W<o C>d X iterc(C&&v){QY D=Qp<C>;QN<D>p(new D(QK<C>(v)));O Q7(Qg<D>{p,H(*p)},Qg<D>{p,E(*p)});}W<o T>d X QZ(std::initializer_list<T>l){O iterc(QP<T>(l));}def_template_lambda(W<o T>,QM,(T&&v),{QP<o Qp<T>::value_type>s;for(X&&x:v){s.Qe(x);}O s;})W<Z n>Qt Q_{W<o T>d static X make(T&&v){O QK<T>(v)>apply(FF(u,Q_<n-1>::make(u)))>QM;}};W<>Qt Q_<1>{W<o T>d static X make(T&&v){O QK<T>(v)>QM;}};W<Z n>Qt to_nested_vector_{QY Qw=w;W<o T>d P(X)a()(T&&v)L{O Q_<n>::make(QK<T>(v));}};W<Z n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(Z l,Z r),({l,r}),Z l;Z r;,{O QZ(H(v)+l,H(v)+r);})def_iterator_manip(is_nil,{O not(H(v)!=E(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{Z l=0;for(X i=H(v);i!=E(v);++i){++l;}O l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
W<o T1,o T2,o T3,o T=std::make_signed_t<P(T1()+T2()+T3())>>d X Q2(L T1&b,L T2&e,L T3&step){QT(T x;T e;T step;d QR Qn()L{O(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{O Qn()xor z.Qn();},{x+=step;O*Qa;},{O T(x);}) O QZ(Y{b,e,step},Y{e,e,step});}W<o T1,o T2>d X Q2(L T1&b,L T2&e){O Q2(b,e,P(T1()+T2())(1));}W<o T>d X Q2(L T&e){O Q2(T(),e,T(1));} 
#pragma GCC diagnostic pop
W<o T>d X to_infinity(L T&b=0,L T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
QT(T x;T step;,{(w)z;O Qj;},{x+=step;O*Qa;},{O T(x);}) O QZ(Y{b,step},Y{b,step});
#pragma GCC diagnostic pop
}Ql(apply,W<o F>,(F f),<F>{f},F f;,(Y{f,H(v)}),(Y{f,E(v)}),,{ O it!=z.it;},{++it;O*Qa;},{O f(*it);}) Ql(take,,(Z n),{n},Z n;,(Y{n,H(v)}),(Y{0,E(v)}),,{ O n!=z.n;},{--n;if(n>0){++it;}O*Qa;},{O*it;}) Ql(take_while,W<o F>,(F f),<F>{f},F f;,(Y{f,not(H(v)!=E(v)and f(*H(v))),H(v)}),(Y{f,Qj,E(v)}),QR Qn;,{O Qn xor z.Qn;},{++it;if(not f(*it)){Qn=Qj;}O*Qa;},{O*it;}) Ql(drop,,(Z n),{n},Qx Z n;,(Y{n,E(v),H(v)}),(Y{0,E(v),E(v)}),L I end_it;d w Qk()L{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{Qk();z.Qk();O it!=z.it;},{Qk();++it;O*Qa;},{Qk();O*it;}) Ql(drop_while,W<o F>,(F f),<F>{f},F f;,(Y{f,E(v),QE,H(v)}),(Y{f,E(v),Qj,E(v)}),L I end_it;Qx QR W1;d w Qk()L{if(not W1){while(it!=end_it and f(*it)){++it;}W1=Qj;}},{Qk();z.Qk();O it!=z.it;},{Qk();++it;O*Qa;},{Qk();O*it;}) def_iterator_manip(head,{O*H(v);})d X tail=drop(1);d X at(Z n){O head<drop(n);}Ql(cons,W<o S>,(S s),<S>{s},S s;,(Y{s,Qj,H(v)}),(Y{s,QE,E(v)}),QR is_s;,{O is_s!=z.is_s or it!=z.it;},{if(is_s){is_s=QE;}Qf{++it;}O*Qa;},{O(is_s)?(s):(*it);}) def_iterator_manip(snoc,{X it=H(v);X h=*it;++it;O QC(h,QZ(it,E(v)));})def_iterator_manip(split_at,,(Z n),{n},Z n;,{X it=H(v);QP<T>u;for(X i:Q2(n)){u.Qe(*it);++it;}O QC(iterc(Qr(u)),QZ(it,E(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
Ql(chunks_of,,(Z n),{n},Z n;,(Y{n,{},QE,E(v),H(v)}),(Y{n,{},QE,E(v),E(v)}),Qx QP<V>u;Qx QR Qh;I it_end;w update()L{u.clear();Qh=Qj;for(X i:Q2(n)){if(it!=it_end){u.Qe(*it);++it;}Qf{break;}}},{O it!=z.it;},{if(Qh){Qh=QE;}Qf{for(X i:Q2(n)){if(it!=it_end){++it;}Qf{break;}}}O*Qa;},{if(not Qh){update();}O iterc(u);})
#pragma GCC diagnostic pop
W<o F,o S>Qt fold_impl{QY Qw=w;F f;S s;W<o T>X a()(L T&v)L{X x=s;for(X y:v){x=f(x,y);}O x;}};W<o F,o S>d X fold(F f,L S&s){O fold_impl<F,S>{f,s};}def_iterator_manip(fold1,W<o F>,(F f),<F>{f},F f;,{X u=v>snoc;O u>snd>fold(f,u>fst);})def_iterator_manip(sum,{O v>fold(_1+_2,V(0));})def_iterator_manip(product,{O v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,W<o F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{O v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,W<o F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,W<o F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{O v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,W<o F>,(F f),<F>{f},F f;,{O v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})W<o F,o S>Qt scan_impl{QY Qw=w;F f;S s;W<o T,o I=P(H(QV<T>()))>P(X)a()(T&&v)L{QT(F f;Qx S s;Qx QR Qh;QR W1;Qx I it;,{O it!=z.it;},{if(not Qh){s=f(s,*it);};Qh=QE;if(W1){++it;}Qf{W1=Qj;}O*Qa;},{if(not Qh){Qh=Qj;s=f(s,*it);}O s;}) O QZ(Y{f,s,Qj,QE,H(QK<T>(v))},Y{f,s,Qj,Qj,E(QK<T>(v))});}};W<o F,o S>d X scan(F f,L S&s){O scan_impl<F,S>{f,s};}Ql(scan1,W<o F>,(F f),<F>{f},F f;,(Y{f,*H(v),Qj,H(v)}),(Y{f,*H(v),Qj,E(v)}),Qx V s;Qx QR Qh;,{O it!=z.it;},{if(not Qh){s=f(s,*it);};Qh=QE;++it;O*Qa;},{if(not Qh){Qh=Qj;s=f(s,*it);}O s;}) W<o T,o S,o I=P(H(QV<T>())),o J=P(H(QV<S>()))>d X a+(T&&v,S&&u){QT(I i;I i_end;J j;QR in_i;,{O i!=z.i or j!=z.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=QE;}}Qf{++j;}O*Qa;},{O(in_i)?(*i):(*j);}) I bv=H(v);I ev=E(v);J bu=H(u);J eu=E(u);O QZ(Y{bv,ev,bu,bv!=ev},Y{ev,ev,eu,QE});}QS Qt{QY Qw=w;W<o T>X a()(T&&v)L{X u=QK<T>(v)>filter(FF(i,not is_nil(i)));X b=H(u);X e=E(u);QY J=P(b);QY V=Qp<P(*b)>;QY K=P(H(*b));Qt Y{J j;J Q6;QN<V>QU;K*QQ;QR Qn;Y(J j,J Q6,L V&jv,QR Qn):j(j),Q6(Q6),QU(new V(jv)),QQ(new K(H(*QU))),Qn(Qn){} Y(J j,J Q6,QR Qn):j(j),Q6(Q6),QU(nullptr),QQ(nullptr),Qn(Qn){} Y(L Y&z):j(z.j),Q6(z.Q6),QU(z.QU),QQ((z.QQ)?(new K(*z.QQ)):nullptr),Qn(z.Qn){} Y(Y&&z):j(z.j),Q6(z.Q6),QU(z.QU),QQ((z.QQ)?(new K(*z.QQ)):nullptr),Qn(z.Qn){}~Y(){delete QQ;}QR a!=(L Y&z)L{O Qn xor z.Qn;}Y&a++(){++*QQ;if(not(*QQ!=E(*QU))){++j;if(j!=Q6){delete QQ;QU=std::make_shared<V>(*j);QQ=new K(H(*QU));}Qf{Qn=Qj;}} O*Qa;}P(X)a*()L{O**QQ;}};if(u>is_nil){O Q7(Y(b,e,Qj),Y(b,e,Qj));}Qf{O Q7(Y(b,e,*b,QE),Y(e,e,Qj));}}}flatten;W<o T,o F,o=std::enable_if_t<is_iterable_v<T>>>X a>=(T&&v,F f){O v>apply(f)>flatten;}W<o U,Z...Is>d QR all_different_(L U&x,L U&y,QD<Is...>){O((Qy<Is>(x)!=Qy<Is>(y))&&...);}W<o F,o...Ts>d X zip_with(F f,Ts&&...vs){QT(F f;QC<P(H(QV<Ts>()))...>its;,{O all_different_(its,z.its,std::index_sequence_for<Ts...>{});},{QF([&](X&&...xs){(++xs,...);},its);O*Qa;},{O QF([&](X&&...xs){O f(*xs...);},its);}) O QZ(Y{f,QC(H(vs)...)},Y{f,QC(E(vs)...)});};Qt zip_default_function_{W<o...Ts>P(X)a()(Ts&&...xs)L{O QC<Ts...>(QK<Ts>(xs)...);}};W<o...Ts>d X zip(Ts&&...vs){O zip_with(zip_default_function_{},QK<Ts>(vs)...);}Ql(filter,W<o F>,(F f),<F>{f},F f;,(Y{f,E(v),H(v)}),(Y{f,E(v),E(v)}),L I end_it;d w Qk()L{while(it!=end_it and not f(*it)){++it;}},{Qk();z.Qk();O it!=z.it;},{Qk();++it;O*Qa;},{Qk();O*it;}) def_template_lambda(W<o T>,repeat,(T&&v),{Qt Y{L Qp<T>v;QR a!=(L Y&)L{O Qj;}Y&a++(){O*Qa;}L X&a*()L{O v;}};O QZ(Y{v},Y{v});})d X replicate(Z n){O take(n)<repeat;}d X cycle=flatten<repeat;def_iterator_manip(enumerate,{O zip(to_infinity(Z(0)),v);})def_iterator_manip(reversed,{X s=v>QM;std::reverse(s.begin(),s.end());O iterc(Qr(s));})def_iterator_manip(sorted_by,W<o F>,(F f),<F>{f},F f;,{X s=v>QM;std::sort(H(s),E(s),f);O iterc(Qr(s));})def_iterator_manip(sorted,{O v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,W<o F>,(F f),<F>{f},F f;,{O v>apply(FF(i,QC(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>apply(fst);})def_iterator_manip(nub,{QT(I it_end;I it;,{O it!=z.it;},{P(*it)pr;do{pr=*it;++it;}while(it!=it_end and pr==*it);O*Qa;},{O*it;}) X b=H(v);X e=E(v);O QZ(Y{e,b},Y{e,e});})W<o F,o S>Qt accum_vector_by_{QY Qw=w;Z n;F f;S s;W<o T,o I=P(H(QV<T>())),o V=Qp<P(*QV<I>())>>P(X)a()(L T&v)L{QP<Qp<Qm<F,S,P(Qy<1>(QV<V>()))>>>u(n,s);for(X&&[i,x]:v){u[i]=f(u[i],x);}O u;}};W<o F,o S>d X accum_vector_by(Z n,F f,L S&s){O accum_vector_by_<F,S>{n,f,s};}W<o S>d X accum_vector(Z n,L S&s=S()){O accum_vector_by(n,_2,s);}W<o F,o S>Qt accum_map_by_{QY Qw=w;F f;S s;W<o T,o I=P(H(QV<T>())),o V=Qp<P(*QV<I>())>>P(X)a()(L T&v)L{std::map<Qp<P(Qy<0>(QV<V>()))>,Qp<Qm<F,S,P(Qy<1>(QV<V>()))>>>u;for(X&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qf{u[i]=f(s,x);}} O u;}};W<o F,o S>d X accum_map_by(F f,L S&s){O accum_map_by_<F,S>{f,s};}W<o S>d X accum_map(L S&s=S()){O accum_map_by(_2,s);}W<o F,o S>Qt accum_unordered_map_by_{QY Qw=w;F f;S s;W<o T,o I=P(H(QV<T>())),o V=Qp<P(*QV<I>())>>P(X)a()(L T&v)L{std::unordered_map<Qp<P(Qy<0>(QV<V>()))>,Qp<Qm<F,S,P(Qy<1>(QV<V>()))>>>u;for(X&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qf{u[i]=f(s,x);}} O u;}};W<o F,o S>d X accum_unordered_map_by(F f,L S&s){O accum_unordered_map_by_<F,S>{f,s};}W<o S>d X accum_unordered_map(L S&s=S()){O accum_unordered_map_by(_2,s);}W<o U,Z...Is>d QR any_different_(L U&x,L U&y,QD<Is...>){O((Qy<Is>(x)!=Qy<Is>(y))||...);}W<Z N,o Y>d w QJ(Y&it){if QS(N>=1){++Qy<N-1>(it.its);if(not(Qy<N-1>(it.its)!=E(Qy<N-1>(*it.my_vs_ptr)))){Qy<N-1>(it.its)=H(Qy<N-1>(*it.my_vs_ptr));QJ<N-1>(it);}} Qf{it.its=QF([](X&&...xs){O QC(E(xs)...);},*it.my_vs_ptr);}} W<o...Ts>X Qi(Ts&&...vs){X QO=std::make_shared<QC<QX<QG<Ts>,Q4<Ts>,Ts>...>>(vs...);QT(QC<P(H(QV<QX<QG<Ts>,Q4<Ts>,Ts>>()))...>its;P(QO)my_vs_ptr;,{O any_different_(its,z.its,std::index_sequence_for<Ts...>{});},{QJ<sizeof...(Ts)>(*Qa);O*Qa;},{O QF([](X&&...xs){O QC<P(*xs)...>(*xs...);},its);}) if(QF([](X&&...xs){O((xs>is_nil)||...);},*QO)){O QZ(Y{QF([](X&&...xs){O QC(E(xs)...);},*QO),QO},Y{QF([](X&&...xs){O QC(E(xs)...);},*QO),QO});}Qf{O QZ(Y{QF([](X&&...xs){O QC(H(xs)...);},*QO),QO},Y{QF([](X&&...xs){O QC(E(xs)...);},*QO),QO});}};W<o...Ts>d X cartesian_product_range(L Ts&...n){O Qi(Q2(n)...);}W<Z n,o I>d X cartesian_power(L I&v){O QF([](L X&...vs){O Qi(vs...);},tuple_many_of<n>(v));}Qt{QY Qw=w;Q1 n=-1;W<o T>X a()(T&&v)L{if QS(std::is_convertible_v<T,Q1>){X x=*Qa;x.n=v;O x;}Qf{X vec=v>QM;Q1 m=vec.size();Qt Y{Q1 n;P(vec)my_v;QP<Z>cycles;QR Qn;QR a!=(L Y&z)L{O Qn xor z.Qn;}Y&a++(){for(X i:Q2(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=my_v.size()-i;std::rotate(my_v.begin()+i,my_v.begin()+i+1,my_v.end());}Qf{std::swap(my_v[i],my_v[my_v.size()-cycles[i]]);O*Qa;}} Qn=Qj;O*Qa;}X a*()L{O my_v>array_slice(0,n);}};Q1 n1=(n<0)?(m):(n);O QZ(Y{n1,Qr(vec),Q2(m,m-n1,-1)>apply(FF(x,Z(x)))>QM,QE},Y{n1,{},{},Qj});}}}permutations;Qt combinations_impl{QY Qw=w;Q1 n;W<o T>X a()(T&&v)L{X vec=v>QM;Q1 m=vec.size();QT(Q1 n;P(vec)my_v;QP<Z>idx;QR Qn;,{O Qn xor z.Qn;},{for(X i:Q2(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(X j:Q2(i+1,n)){idx[j]=idx[j-1]+1;}O*Qa;}} Qn=Qj;O*Qa;},{O idx>array_slice(0,n)>apply(FF(i,my_v[i]));}) O QZ(Y{n,Qr(vec),Q2(0,m)>apply(FF(x,Z(x)))>QM,QE},Y{n,{},{},Qj});}};d X combinations(Q1 n){O combinations_impl{n};}Qt QA{QY Qw=w;Q1 n;W<o T>X a()(T&&v)L{X vec=v>QM;Q1 m=vec.size();QT(Q1 n;P(vec)my_v;QP<Z>idx;QR Qn;,{O Qn xor z.Qn;},{for(X i:Q2(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(X j:Q2(i+1,n)){idx[j]=idx[i];}O*Qa;}} Qn=Qj;O*Qa;},{O idx>array_slice(0,n)>apply(FF(i,my_v[i]));}) O QZ(Y{n,Qr(vec),Z(0)>replicate(m)>QM,QE},Y{n,{},{},Qj});}};d X combinations_with_replacement(Q1 n){O QA{n};}W<o T>d X istream_iterable(std::istream&in){QT(std::istream&in;Qx T val;QR Qn;Qx QR has_read;,{O Qn xor z.Qn;},{if(not(in>>val)){Qn=Qj;}O*Qa;},{if(not has_read){has_read=Qj;in>>val;}O val;}) O QZ(Y{in,T{},QE,QE},Y{in,T{},Qj,Qj});}W<o T>d X input=istream_iterable<T>(std::cin);W<o T>Qs&print_iterable(Qs&out,L T&v,L std::string&sep= " "){for(X it=H(v);it!=E(v);){ out<<*it;++it;if(it!=E(v)){out<<sep;}Qf{O out;}} O out;}W<o T,o=o T::is_iterable_wrapper>d Qs&a<<(Qs&out,L T&v){out<< "[";O print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)W<o...Ts>Qs&a<<(Qs&out,L I<Ts...>&v){O out<<QZ(v);}
Qc(QP)Qc(std::map)Qc(std::unordered_map)Qc(std::set)Qc(std::unordered_set)W<Z n,o T>Qt Q8{QY type=QP<o Q8<n-1,T>::type>;static X make(L Qo<n,Z>&sz,L T&val=T()){O QP(Q3(sz),Q8<n-1,T>::make(tuple_tail(sz),val));}};W<o T>Qt Q8<1,T>{QY type=QP<T>;static X make(L QC<Z>&sz,L T&val=T()){O QP(Q3(sz),val);}};W<Z n,o T>QY nested_vector=o Q8<n,T>::type;W<Z n,o T>X make_nested_vector(L Qo<n,Z>&sz,L T&val=T()){O Q8<n,T>::make(sz,val);}W<Z n,o T>d X Qz(L T&v){if QS(n==1){O QC(v.size());}Qf{O std::tuple_cat(QC(v.size()),Qz<n-1>(v[0]));}} W<Z n,o T>d X nested_vector_indices(L T&v){O QF([&](X...x){O cartesian_product_range(x...);},Qz<n>(v));}W<Z n,o T>d P(X)QW(L QP<T>&v,L Qo<n,Z>&i){if QS(n==1){O v[Q3(i)];}Qf{O QW<n-1>(v[Q3(i)],tuple_tail(i));}} W<Z n,o T>d P(X)QW(QP<T>&v,L Qo<n,Z>&i){if QS(n==1){O v[Q3(i)];}Qf{O QW<n-1>(v[Q3(i)],tuple_tail(i));}} W<o U,Z i,Z s>Qs&Q9(Qs&out,L U&u){if QS(i==0){out<< "{ ";}out<<Qy<i>(u);if QS(i+1<s){out<< ", ";O Q9<U,i+1,s>(out,u);}Qf{O out<< " }";}} W<o...Ts>Qs&a<<(Qs&out,L QC<Ts...>&u){O Q9<P(u),0,sizeof...(Ts)>(out,u);}W<o T,o S>Qs&a<<(Qs&out,L std::pair<T,S>&p){O out<<QC(p.first,p.second);} 
#define BEGIN  Q1 main(){std::ios_base::sync_with_stdio(QE);std::cin.tie(0);std::cout.tie(0);
#define END }
QY namespace std;QY LL=long long;w dfs(Q1 n,Q1 c,L QH<QH<Q1>>&G,QH<QR>&Qd,QH<Q1>&ans){Qd[n]=Qj;ans[n]=c;for(Q1 x:G[n]){if(not Qd[x]){dfs(x,c,G,Qd,ans);}}}X get_ccs(L QH<QH<Q1>>&G,Q1 A){QH<Q1>ans(G.size());QH<QR>Qd(G.size(),QE);Qd[A]=Qj;Q1 c=1;for(Q1 n:Q2(G.size())){if(not Qd[n]){dfs(n,c,G,Qd,ans);++c;}} O ans;}w solve(){Q1 N,M;Q1 A,B;cin>>N>>M>>A>>B;--A;--B;QH<QH<Q1>>G(N);while(M--){Q1 x,y;cin>>x>>y;--x;--y;G[x].Qe(y);G[y].Qe(x);}X u=get_ccs(G,A);X v=get_ccs(G,B);map<Q1,LL>R,S;map<tuple<Q1,Q1>,LL>Q;for(Q1 n:Q2(N)){R[u[n]]++;S[v[n]]++;Q[{u[n],v[n]}]++;}LL ans=LL(N)*LL(N-1)/2-2*(N-1)+1;for(Q1 n:Q2(N)){if(n!=B and n!=A and v[A]==v[n]){++ans;}if(n!=A and n!=B and u[B]==u[n]){++ans;}} for(L X&[p,q]:R){ans-=q*(q-1)/2;}for(L X&[p,q]:S){ans-=q*(q-1)/2;}for(L X&[p,q]:Q){ans+=q*(q-1)/2;}cout<<ans<< "\n";}BEGIN Q1 T;cin>>T;while(T--){solve();}END