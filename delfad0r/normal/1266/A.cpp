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
#define Qw nested_vector_size
#define QH constexpr
#define QB def_iterator_manip_iter
#define Qv ostream_tuple_helper_
#define QV has_advanced
#define w operator
#define P std::end
#define Qc else
#define QG __arg2__
#define QI std::conditional_t
#define Q8 has_updated
#define M Iterator
#define k size_t
#define o void
#define Q7 iter
#define A return
#define QE is_composable_
#define Qr GET_5TH_ARG
#define QW this
#define E auto
#define Q0 j_end
#define Qq my_v
#define QC std::tuple_element_t
#define QF implicit_lambda
#define QD tuple_many_of_t
#define QX nested_vector_impl
#define Qi iterator_macro
#define Qz bool
#define O __arg1__
#define X std::begin
#define QP it_end
#define Q5 implicit_lambda_unary_operator
#define QS tuple_head
#define Qh jv_ptr
#define Q3 is_composable_v
#define Qx std::declval
#define QZ std::forward
#define Q4 cartesian_product_incr_
#define Y is_end
#define Q9 std::vector
#define Qa nested_vector_at
#define QL vs_ptr
#define q template
#define Q1 tuple_tail
#define Qe advance
#define Q2 std::decay_t
#define QQ std::shared_ptr
#define QA def_iterable_ostream
#define Qk implicit_lambda_binary_operator
#define QU to_vector
#define Qj std::is_rvalue_reference_v
#define Qu std::remove_reference_t
#define z typename
#define Z decltype
#define R const
#define QO std::ostream
#define Qg std::invoke_result_t
#define Qm combinations_with_replacement_impl
#define Qn apply
#define B struct
#define Ql __expr1__
#define Qy mutable
#define QK to_nested_vector_impl
#define W other
#define L std::tuple
#define QR __tuple__
#define QJ std::get
#define Qo cartesian_product
#define Qp iterable_wrapper
#define Qt range
#define Qf std::apply
#define H inline
#define Qd k_ptr
#define d using
#define Qs false
#define QY std::move
#define Q true
#define QT std::index_sequence
#define Qb container_carrying_iterator
#define Q6 __arg3__

q<z T,k>d ignore_second=T;q<k...Ix,z T>E tuple_many_of_impl(QT<Ix...>,R T&x){A L(ignore_second<T,Ix>(x)...);}q<k n,z T>E tuple_many_of(R T&x){A tuple_many_of_impl(std::make_index_sequence<n>{},x);}q<k n,z T>d QD=Z(tuple_many_of<n,T>(Qx<T>()));q<z...Args>E QS(R L<Args...>&t){A QJ<0>(t);}q<k...Ix,z...Args>E tuple_tail_impl(QT<Ix...>,R L<Args...>&t){A L(QJ<Ix+1>(t)...);}q<z...Args>E Q1(R L<Args...>&t){A tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}B empty_t{};QH empty_t empty_v;q<z T1,z T2>std::common_type_t<T1,T2>maxx(R T1&x,R T2&y){if(x<y){A y;}Qc{A x;}} q<z T1,z T2,z...Ts>H E maxx(R T1&x,R T2&y,R Ts&...xs){A maxx(maxx(x,y),xs...);}q<z T1,z T2>E minn(R T1&x,R T2&y){if(x<=y){A x;}Qc{A y;}} q<z T1,z T2,z...Ts>H E minn(R T1&x,R T2&y,R Ts&...xs){A minn(minn(x,y),xs...);}QH int _log2(int x){if(x==0){A 0;}A 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){A f;}
#define FF_1(O,f)[&](E&&O){(o)O;A f;}
#define FF_2(O,QG,f)[&](E&&O,E&&QG){(o)O;(o)QG;A f;}
#define FF_3(O,QG,Q6,f)[&](E&&O,E&&QG,E&&Q6){(o)O;(o)QG;(o)Q6;A f;}
#define FF_macro_chooser(...)Qr(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->E&{A f;}
#define FREF_1(O,f)[&](E&&O)->E&{(o)O;A f;}
#define FREF_2(O,QG,f)[&](E&&O,E&&QG)->E&{(o)O;(o)QG;A f;}
#define FREF_3(O,QG,Q6,f)[&](E&&O,E&&QG,E&&Q6)->E&{(o)O;(o)QG;(o)Q6;A f;}
#define FREF_macro_chooser(...)Qr(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){A f;}
#define FC_1(O,f,c)[&,c](E&&O){(o)O;A f;}
#define FC_2(O,QG,f,c)[&,c](E&&O,E&&QG){(o)O;(o)QG;A f;}
#define FC_macro_chooser(...)Qr(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){A f;}
#define FC2_1(O,f,c1,c2)[&,c1,c2](E&&O){(o)O;A f;}
#define FC2_2(O,QG,f,c1,c2)[&,c1,c2](E&&O,E&&QG){(o)O;(o)QG;A f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(O,f)[&](E&&QR){E&[O]=QR;(o)O;A f;}
#define FT_2(O,QG,f)[&](E&&QR){E&[O,QG]=QR;(o)O;(o)QG;A f;}
#define FT_3(O,QG,Q6,f)[&](E&&QR){E&[O,QG,Q6]=QR;(o)O;(o)QG;(o)Q6;A f;}
#define FT_4(O,QG,Q6,__arg4__,f)[&](E&&QR){E&[O,QG,Q6,__arg4__]=QR;(o)O;(o)QG;(o)Q6;(o)__arg4__;A f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Ql,f)[&](){E&&Ql;A f;}()
#define LET_2(Ql,__expr2__,f)[&](){E&&Ql;E&&__expr2__;A f;}()
#define LET_3(Ql,__expr2__,__expr3__,f)[&](){E&&Ql;E&&__expr2__;E&&__expr3__;A f;}()
#define LET_macro_chooser(...)Qr(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)QH B{d QE=o;templ H Z(E)w()args R code}name;
q<z F>class QF{private:F f;public:QF(F f_):f(f_){} q<z...Ts>QH E w()(Ts&&...xs)R{A f(QZ<Ts>(xs)...);}};QF _([](E&&x)->QI<Qj<Z(x)>,Qu<Z(x)>,Z(x)>{A x;});QF _1([](E&&x,E&&)->QI<Qj<Z(x)>,Qu<Z(x)>,Z(x)>{A x;});QF _2([](E&&,E&&y)->QI<Qj<Z(y)>,Qu<Z(y)>,Z(y)>{A y;});
#define implicit_lambda_unary_operator(op)q<z F>QH Z(E)w op(QF<F>f){A QF([=](E&&...xs){A op f(QZ<Z(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)q<z F,z T>QH Z(E)w op(QF<F>f,R T&y){A QF([=](E&&...xs){A f(QZ<Z(xs)>(xs)...)op y;});}q<z F,z T>QH Z(E)w op(R T&y,QF<F>f){A QF([=](E&&...xs){A y op f(QZ<Z(xs)>(xs)...);});}q<z F,z G>QH Z(E)w op(QF<F>f,QF<G>g){A QF([=](E&&...xs){A f(QZ<Z(xs)>(xs)...)op g(QZ<Z(xs)>(xs)...);});}
Q5(+)Q5(-)Q5(!)Q5(~)Q5(*)Q5(&)Qk(+)Qk(-)Qk(*)Qk(/)Qk(%)Qk(<)Qk(>)Qk(<=)Qk(>=)Qk(==)Qk(!=)Qk(<<)Qk(>>)Qk(&)Qk(|)Qk(^)Qk(&&)q<z T,z=o>B is_composable:public std::false_type{};q<z T>B is_composable<T,std::void_t<z T::is_composable_>>:public std::true_type{};q<z T>QH Qz Q3=is_composable<T>::value;q<z T,z F,z=Qg<F,T>>Z(E)w>(T&&v,R F&f){A f(QZ<T>(v));}q<z M1,z M2>B composed{d QE=o;R M1 m1;R M2 m2;q<z T>Z(E)w()(T&&v)R{A m1(m2(QZ<T>(v)));}};q<z M1,z M2,z=std::enable_if_t<Q3<M1>or Q3<M2>>>H E w<(R M1&m1,R M2&m2){A composed<M1,M2>{m1,m2};}q<k n>B nth_impl{d QE=o;q<z...Ts>QH QC<n,L<Ts...>>&w()(L<Ts...>&u)R{A QJ<n>(u);}q<z...Ts>QH QC<n,L<Ts...>>w()(L<Ts...>&&u)R{A QJ<n>(u);}q<z...Ts>QH R QC<n,L<Ts...>>&w()(R L<Ts...>&u)R{A QJ<n>(u);}q<z...Ts>QH R QC<n,L<Ts...>>w()(R L<Ts...>&&u)R{A QJ<n>(u);}};q<k n>QH nth_impl<n>nth;QH nth_impl<0>fst;QH nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)B M{extra Qz w!=(R M&W)R neq M&w++()incr Z(E)w*()R val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,QP,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{Qi(extra extra_it Qy I it;,neq_it,incr_it,val_it);A Qp(it_begin,QP);})
#define def_iterator_manip_2(name,code)QH B{d QE=o;q<z T,z I=Z(X(Qx<T>())),z V=Q2<Z(*Qx<I>())>>Z(E)w()(T&&v)R code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ B name##_impl{d QE=o;extra q<z T,z I=Z(X(Qx<T>())),z V=Q2<Z(*Qx<I>())>>Z(E)w()(T&&v)R code};templ H Z(E)name args{A name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
q<z T,z=o>B is_iterable:public std::false_type{};q<z T>B is_iterable<T,std::void_t<Z(X(Qx<T>())),Z(P(Qx<T>()))>>:public std::true_type{};q<z T>QH Qz is_iterable_v=is_iterable<T>::value;q<z I>H E Qp(R I&b,R I&e){B Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
d is_iterable_wrapper=o;d iterator=I;d value_type=Q2<Z(*Qx<I>())>;
#pragma GCC diagnostic pop
I b,e;E begin()R{A b;}E end()R{A e;}};A Wrapper{b,e};}q<z T>H E Q7(T&&iterable){A Qp(X(QZ<T>(iterable)),P(QZ<T>(iterable)));}q<z I>H E Q7(R I&b,R I&e){A Qp(b,e);}q<z C>B Qb:public C::iterator{QQ<C>p;Qb(QQ<C>p_,z C::iterator it):C::iterator(it),p(p_){}};q<z C>H E iterc(C&&v){d D=Q2<C>;QQ<D>p(new D(QZ<C>(v)));A Qp(Qb<D>{p,X(*p)},Qb<D>{p,P(*p)});}q<z T>H E Q7(std::initializer_list<T>l){A iterc(Q9<T>(l));}def_template_lambda(q<z T>,QU,(T&&v),{Q9<z Q2<T>::value_type>s;for(E&&x:v){s.push_back(x);}A s;})q<k n>B QK{q<z T>H static E make(T&&v){A QZ<T>(v)>Qn(FF(u,QK<n-1>::make(u)))>QU;}};q<>B QK<1>{q<z T>H static E make(T&&v){A QZ<T>(v)>QU;}};q<k n>B to_nested_vector_{d QE=o;q<z T>H Z(E)w()(T&&v)R{A QK<n>::make(QZ<T>(v));}};q<k n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(k l,k r),({l,r}),k l;k r;,{A Q7(X(v)+l,X(v)+r);})def_iterator_manip(is_nil,{A not(X(v)!=P(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{k l=0;for(E i=X(v);i!=P(v);++i){++l;}A l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
q<z T1,z T2,z T3,z T=std::make_signed_t<Z(T1()+T2()+T3())>>H E Qt(R T1&b,R T2&e,R T3&step){Qi(T x;T e;T step;H Qz Y()R{A(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{A Y()xor W.Y();},{x+=step;A*QW;},{A T(x);}) A Q7(M{b,e,step},M{e,e,step});}q<z T1,z T2>H E Qt(R T1&b,R T2&e){A Qt(b,e,Z(T1()+T2())(1));}q<z T>H E Qt(R T&e){A Qt(T(),e,T(1));} 
#pragma GCC diagnostic pop
q<z T>H E to_infinity(R T&b=0,R T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
Qi(T x;T step;,{(o)W;A Q;},{x+=step;A*QW;},{A T(x);}) A Q7(M{b,step},M{b,step});
#pragma GCC diagnostic pop
}QB(Qn,q<z F>,(F f),<F>{f},F f;,(M{f,X(v)}),(M{f,P(v)}),,{ A it!=W.it;},{++it;A*QW;},{A f(*it);}) QB(take,,(k n),{n},k n;,(M{n,X(v)}),(M{0,P(v)}),,{ A n!=W.n;},{--n;if(n>0){++it;}A*QW;},{A*it;}) QB(take_while,q<z F>,(F f),<F>{f},F f;,(M{f,not(X(v)!=P(v)and f(*X(v))),X(v)}),(M{f,Q,P(v)}),Qz Y;,{A Y xor W.Y;},{++it;if(not f(*it)){Y=Q;}A*QW;},{A*it;}) QB(drop,,(k n),{n},Qy k n;,(M{n,P(v),X(v)}),(M{0,P(v),P(v)}),R I end_it;H o Qe()R{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{Qe();W.Qe();A it!=W.it;},{Qe();++it;A*QW;},{Qe();A*it;}) QB(drop_while,q<z F>,(F f),<F>{f},F f;,(M{f,P(v),Qs,X(v)}),(M{f,P(v),Q,P(v)}),R I end_it;Qy Qz QV;H o Qe()R{if(not QV){while(it!=end_it and f(*it)){++it;}QV=Q;}},{Qe();W.Qe();A it!=W.it;},{Qe();++it;A*QW;},{Qe();A*it;}) def_iterator_manip(head,{A*X(v);})H E tail=drop(1);H E at(k n){A head<drop(n);}QB(cons,q<z S>,(S s),<S>{s},S s;,(M{s,Q,X(v)}),(M{s,Qs,P(v)}),Qz is_s;,{A is_s!=W.is_s or it!=W.it;},{if(is_s){is_s=Qs;}Qc{++it;}A*QW;},{A(is_s)?(s):(*it);}) def_iterator_manip(snoc,{E it=X(v);E h=*it;++it;A L(h,Q7(it,P(v)));})def_iterator_manip(split_at,,(k n),{n},k n;,{E it=X(v);Q9<T>u;for(E i:Qt(n)){u.push_back(*it);++it;}A L(iterc(QY(u)),Q7(it,P(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
QB(chunks_of,,(k n),{n},k n;,(M{n,{},Qs,P(v),X(v)}),(M{n,{},Qs,P(v),P(v)}),Qy Q9<V>u;Qy Qz Q8;I QP;o update()R{u.clear();Q8=Q;for(E i:Qt(n)){if(it!=QP){u.push_back(*it);++it;}Qc{break;}}},{A it!=W.it;},{if(Q8){Q8=Qs;}Qc{for(E i:Qt(n)){if(it!=QP){++it;}Qc{break;}}}A*QW;},{if(not Q8){update();}A iterc(u);})
#pragma GCC diagnostic pop
q<z F,z S>B fold_impl{d QE=o;F f;S s;q<z T>E w()(R T&v)R{E x=s;for(E y:v){x=f(x,y);}A x;}};q<z F,z S>H E fold(F f,R S&s){A fold_impl<F,S>{f,s};}def_iterator_manip(fold1,q<z F>,(F f),<F>{f},F f;,{E u=v>snoc;A u>snd>fold(f,u>fst);})def_iterator_manip(sum,{A v>fold(_1+_2,V(0));})def_iterator_manip(product,{A v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,q<z F>,(F f),<F>{f},F f;,{A v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{A v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,q<z F>,(F f),<F>{f},F f;,{A v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,q<z F>,(F f),<F>{f},F f;,{A v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{A v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,q<z F>,(F f),<F>{f},F f;,{A v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})q<z F,z S>B scan_impl{d QE=o;F f;S s;q<z T,z I=Z(X(Qx<T>()))>Z(E)w()(T&&v)R{Qi(F f;Qy S s;Qy Qz Q8;Qz QV;Qy I it;,{A it!=W.it;},{if(not Q8){s=f(s,*it);};Q8=Qs;if(QV){++it;}Qc{QV=Q;}A*QW;},{if(not Q8){Q8=Q;s=f(s,*it);}A s;}) A Q7(M{f,s,Q,Qs,X(QZ<T>(v))},M{f,s,Q,Q,P(QZ<T>(v))});}};q<z F,z S>H E scan(F f,R S&s){A scan_impl<F,S>{f,s};}QB(scan1,q<z F>,(F f),<F>{f},F f;,(M{f,*X(v),Q,X(v)}),(M{f,*X(v),Q,P(v)}),Qy V s;Qy Qz Q8;,{A it!=W.it;},{if(not Q8){s=f(s,*it);};Q8=Qs;++it;A*QW;},{if(not Q8){Q8=Q;s=f(s,*it);}A s;}) q<z T,z S,z I=Z(X(Qx<T>())),z J=Z(X(Qx<S>()))>H E w+(T&&v,S&&u){Qi(I i;I i_end;J j;Qz in_i;,{A i!=W.i or j!=W.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=Qs;}}Qc{++j;}A*QW;},{A(in_i)?(*i):(*j);}) I bv=X(v);I ev=P(v);J bu=X(u);J eu=P(u);A Q7(M{bv,ev,bu,bv!=ev},M{ev,ev,eu,Qs});}QH B{d QE=o;q<z T>E w()(T&&v)R{E u=QZ<T>(v)>filter(FF(i,not is_nil(i)));E b=X(u);E e=P(u);d J=Z(b);d V=Q2<Z(*b)>;d K=Z(X(*b));B M{J j;J Q0;QQ<V>Qh;K*Qd;Qz Y;M(J j,J Q0,R V&jv,Qz Y):j(j),Q0(Q0),Qh(new V(jv)),Qd(new K(X(*Qh))),Y(Y){} M(J j,J Q0,Qz Y):j(j),Q0(Q0),Qh(nullptr),Qd(nullptr),Y(Y){} M(R M&W):j(W.j),Q0(W.Q0),Qh(W.Qh),Qd((W.Qd)?(new K(*W.Qd)):nullptr),Y(W.Y){} M(M&&W):j(W.j),Q0(W.Q0),Qh(W.Qh),Qd((W.Qd)?(new K(*W.Qd)):nullptr),Y(W.Y){}~M(){delete Qd;}Qz w!=(R M&W)R{A Y xor W.Y;}M&w++(){++*Qd;if(not(*Qd!=P(*Qh))){++j;if(j!=Q0){delete Qd;Qh=std::make_shared<V>(*j);Qd=new K(X(*Qh));}Qc{Y=Q;}} A*QW;}Z(E)w*()R{A**Qd;}};if(u>is_nil){A Qp(M(b,e,Q),M(b,e,Q));}Qc{A Qp(M(b,e,*b,Qs),M(e,e,Q));}}}flatten;q<z T,z F,z=std::enable_if_t<is_iterable_v<T>>>E w>=(T&&v,F f){A v>Qn(f)>flatten;}q<z U,k...Is>H Qz all_different_(R U&x,R U&y,QT<Is...>){A((QJ<Is>(x)!=QJ<Is>(y))&&...);}q<z F,z...Ts>H E zip_with(F f,Ts&&...vs){Qi(F f;L<Z(X(Qx<Ts>()))...>its;,{A all_different_(its,W.its,std::index_sequence_for<Ts...>{});},{Qf([&](E&&...xs){(++xs,...);},its);A*QW;},{A Qf([&](E&&...xs){A f(*xs...);},its);}) A Q7(M{f,L(X(vs)...)},M{f,L(P(vs)...)});};B zip_default_function_{q<z...Ts>Z(E)w()(Ts&&...xs)R{A L<Ts...>(QZ<Ts>(xs)...);}};q<z...Ts>H E zip(Ts&&...vs){A zip_with(zip_default_function_{},QZ<Ts>(vs)...);}QB(filter,q<z F>,(F f),<F>{f},F f;,(M{f,P(v),X(v)}),(M{f,P(v),P(v)}),R I end_it;H o Qe()R{while(it!=end_it and not f(*it)){++it;}},{Qe();W.Qe();A it!=W.it;},{Qe();++it;A*QW;},{Qe();A*it;}) def_template_lambda(q<z T>,repeat,(T&&v),{B M{R Q2<T>v;Qz w!=(R M&)R{A Q;}M&w++(){A*QW;}R E&w*()R{A v;}};A Q7(M{v},M{v});})H E replicate(k n){A take(n)<repeat;}H E cycle=flatten<repeat;def_iterator_manip(enumerate,{A zip(to_infinity(k(0)),v);})def_iterator_manip(reversed,{E s=v>QU;std::reverse(s.begin(),s.end());A iterc(QY(s));})def_iterator_manip(sorted_by,q<z F>,(F f),<F>{f},F f;,{E s=v>QU;std::sort(X(s),P(s),f);A iterc(QY(s));})def_iterator_manip(sorted,{A v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,q<z F>,(F f),<F>{f},F f;,{A v>Qn(FF(i,L(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>Qn(fst);})def_iterator_manip(nub,{Qi(I QP;I it;,{A it!=W.it;},{Z(*it)pr;do{pr=*it;++it;}while(it!=QP and pr==*it);A*QW;},{A*it;}) E b=X(v);E e=P(v);A Q7(M{e,b},M{e,e});})q<z F,z S>B accum_vector_by_{d QE=o;k n;F f;S s;q<z T,z I=Z(X(Qx<T>())),z V=Q2<Z(*Qx<I>())>>Z(E)w()(R T&v)R{Q9<Q2<Qg<F,S,Z(QJ<1>(Qx<V>()))>>>u(n,s);for(E&&[i,x]:v){u[i]=f(u[i],x);}A u;}};q<z F,z S>H E accum_vector_by(k n,F f,R S&s){A accum_vector_by_<F,S>{n,f,s};}q<z S>H E accum_vector(k n,R S&s=S()){A accum_vector_by(n,_2,s);}q<z F,z S>B accum_map_by_{d QE=o;F f;S s;q<z T,z I=Z(X(Qx<T>())),z V=Q2<Z(*Qx<I>())>>Z(E)w()(R T&v)R{std::map<Q2<Z(QJ<0>(Qx<V>()))>,Q2<Qg<F,S,Z(QJ<1>(Qx<V>()))>>>u;for(E&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qc{u[i]=f(s,x);}} A u;}};q<z F,z S>H E accum_map_by(F f,R S&s){A accum_map_by_<F,S>{f,s};}q<z S>H E accum_map(R S&s=S()){A accum_map_by(_2,s);}q<z F,z S>B accum_unordered_map_by_{d QE=o;F f;S s;q<z T,z I=Z(X(Qx<T>())),z V=Q2<Z(*Qx<I>())>>Z(E)w()(R T&v)R{std::unordered_map<Q2<Z(QJ<0>(Qx<V>()))>,Q2<Qg<F,S,Z(QJ<1>(Qx<V>()))>>>u;for(E&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qc{u[i]=f(s,x);}} A u;}};q<z F,z S>H E accum_unordered_map_by(F f,R S&s){A accum_unordered_map_by_<F,S>{f,s};}q<z S>H E accum_unordered_map(R S&s=S()){A accum_unordered_map_by(_2,s);}q<z U,k...Is>H Qz any_different_(R U&x,R U&y,QT<Is...>){A((QJ<Is>(x)!=QJ<Is>(y))||...);}q<k N,z M>H o Q4(M&it){if QH(N>=1){++QJ<N-1>(it.its);if(not(QJ<N-1>(it.its)!=P(QJ<N-1>(*it.my_vs_ptr)))){QJ<N-1>(it.its)=X(QJ<N-1>(*it.my_vs_ptr));Q4<N-1>(it);}} Qc{it.its=Qf([](E&&...xs){A L(P(xs)...);},*it.my_vs_ptr);}} q<z...Ts>E Qo(Ts&&...vs){E QL=std::make_shared<L<QI<Qj<Ts>,Qu<Ts>,Ts>...>>(vs...);Qi(L<Z(X(Qx<QI<Qj<Ts>,Qu<Ts>,Ts>>()))...>its;Z(QL)my_vs_ptr;,{A any_different_(its,W.its,std::index_sequence_for<Ts...>{});},{Q4<sizeof...(Ts)>(*QW);A*QW;},{A Qf([](E&&...xs){A L<Z(*xs)...>(*xs...);},its);}) if(Qf([](E&&...xs){A((xs>is_nil)||...);},*QL)){A Q7(M{Qf([](E&&...xs){A L(P(xs)...);},*QL),QL},M{Qf([](E&&...xs){A L(P(xs)...);},*QL),QL});}Qc{A Q7(M{Qf([](E&&...xs){A L(X(xs)...);},*QL),QL},M{Qf([](E&&...xs){A L(P(xs)...);},*QL),QL});}};q<z...Ts>H E cartesian_product_range(R Ts&...n){A Qo(Qt(n)...);}q<k n,z I>H E cartesian_power(R I&v){A Qf([](R E&...vs){A Qo(vs...);},tuple_many_of<n>(v));}B{d QE=o;int n=-1;q<z T>E w()(T&&v)R{if QH(std::is_convertible_v<T,int>){E x=*QW;x.n=v;A x;}Qc{E vec=v>QU;int m=vec.size();B M{int n;Z(vec)Qq;Q9<k>cycles;Qz Y;Qz w!=(R M&W)R{A Y xor W.Y;}M&w++(){for(E i:Qt(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=Qq.size()-i;std::rotate(Qq.begin()+i,Qq.begin()+i+1,Qq.end());}Qc{std::swap(Qq[i],Qq[Qq.size()-cycles[i]]);A*QW;}} Y=Q;A*QW;}E w*()R{A Qq>array_slice(0,n);}};int n1=(n<0)?(m):(n);A Q7(M{n1,QY(vec),Qt(m,m-n1,-1)>Qn(FF(x,k(x)))>QU,Qs},M{n1,{},{},Q});}}}permutations;B combinations_impl{d QE=o;int n;q<z T>E w()(T&&v)R{E vec=v>QU;int m=vec.size();Qi(int n;Z(vec)Qq;Q9<k>idx;Qz Y;,{A Y xor W.Y;},{for(E i:Qt(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(E j:Qt(i+1,n)){idx[j]=idx[j-1]+1;}A*QW;}} Y=Q;A*QW;},{A idx>array_slice(0,n)>Qn(FF(i,Qq[i]));}) A Q7(M{n,QY(vec),Qt(0,m)>Qn(FF(x,k(x)))>QU,Qs},M{n,{},{},Q});}};H E combinations(int n){A combinations_impl{n};}B Qm{d QE=o;int n;q<z T>E w()(T&&v)R{E vec=v>QU;int m=vec.size();Qi(int n;Z(vec)Qq;Q9<k>idx;Qz Y;,{A Y xor W.Y;},{for(E i:Qt(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(E j:Qt(i+1,n)){idx[j]=idx[i];}A*QW;}} Y=Q;A*QW;},{A idx>array_slice(0,n)>Qn(FF(i,Qq[i]));}) A Q7(M{n,QY(vec),k(0)>replicate(m)>QU,Qs},M{n,{},{},Q});}};H E combinations_with_replacement(int n){A Qm{n};}q<z T>H E istream_iterable(std::istream&in){Qi(std::istream&in;Qy T val;Qz Y;Qy Qz has_read;,{A Y xor W.Y;},{if(not(in>>val)){Y=Q;}A*QW;},{if(not has_read){has_read=Q;in>>val;}A val;}) A Q7(M{in,T{},Qs,Qs},M{in,T{},Q,Q});}q<z T>H E input=istream_iterable<T>(std::cin);q<z T>QO&print_iterable(QO&out,R T&v,R std::string&sep= " "){for(E it=X(v);it!=P(v);){ out<<*it;++it;if(it!=P(v)){out<<sep;}Qc{A out;}} A out;}q<z T,z=z T::is_iterable_wrapper>H QO&w<<(QO&out,R T&v){out<< "[";A print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)q<z...Ts>QO&w<<(QO&out,R I<Ts...>&v){A out<<Q7(v);}
QA(Q9)QA(std::map)QA(std::unordered_map)QA(std::set)QA(std::unordered_set)q<k n,z T>B QX{d type=Q9<z QX<n-1,T>::type>;static E make(R QD<n,k>&sz,R T&val=T()){A Q9(QS(sz),QX<n-1,T>::make(Q1(sz),val));}};q<z T>B QX<1,T>{d type=Q9<T>;static E make(R L<k>&sz,R T&val=T()){A Q9(QS(sz),val);}};q<k n,z T>d nested_vector=z QX<n,T>::type;q<k n,z T>E make_nested_vector(R QD<n,k>&sz,R T&val=T()){A QX<n,T>::make(sz,val);}q<k n,z T>H E Qw(R T&v){if QH(n==1){A L(v.size());}Qc{A std::tuple_cat(L(v.size()),Qw<n-1>(v[0]));}} q<k n,z T>H E nested_vector_indices(R T&v){A Qf([&](E...x){A cartesian_product_range(x...);},Qw<n>(v));}q<k n,z T>H Z(E)Qa(R Q9<T>&v,R QD<n,k>&i){if QH(n==1){A v[QS(i)];}Qc{A Qa<n-1>(v[QS(i)],Q1(i));}} q<k n,z T>H Z(E)Qa(Q9<T>&v,R QD<n,k>&i){if QH(n==1){A v[QS(i)];}Qc{A Qa<n-1>(v[QS(i)],Q1(i));}} q<z U,k i,k s>QO&Qv(QO&out,R U&u){if QH(i==0){out<< "{ ";}out<<QJ<i>(u);if QH(i+1<s){out<< ", ";A Qv<U,i+1,s>(out,u);}Qc{A out<< " }";}} q<z...Ts>QO&w<<(QO&out,R L<Ts...>&u){A Qv<Z(u),0,sizeof...(Ts)>(out,u);}q<z T,z S>QO&w<<(QO&out,R std::pair<T,S>&p){A out<<L(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(Qs);std::cin.tie(0);std::cout.tie(0);
#define END }
d namespace std;d LL=long long;o solve(){string S;cin>>S;int a=0,b=0,c=0;for(E x:S){a+=x- '0';b+=(x== '0');c+=((x- '0')%2==0);}cout<<(((a%3)==0 and b and c>=2)?("red"):("cyan"))<< "\n";}BEGIN int T;cin>>T;while(T--){solve();}END