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
#define w auto
#define W1 std::declval
#define QP j_end
#define Qp has_updated
#define QV cartesian_product_incr_
#define Qu iterable_wrapper
#define Qk implicit_lambda
#define Qe false
#define QU std::apply
#define Qy has_advanced
#define QB constexpr
#define z template
#define QE tuple_many_of_t
#define QG std::move
#define Q2 range
#define QF is_composable_
#define Q7 def_iterator_manip_iter
#define Qs push_back
#define P is_end
#define Q_ jv_ptr
#define QM std::forward
#define L other
#define QT std::vector
#define Qn this
#define Ql std::decay_t
#define Qg my_v
#define QS implicit_lambda_unary_operator
#define Qi std::remove_reference_t
#define H struct
#define Qf ostream_tuple_helper_
#define Q4 std::index_sequence
#define d typename
#define Q8 combinations_with_replacement_impl
#define Qo std::conditional_t
#define Z operator
#define Qt __arg2__
#define QY __tuple__
#define QH it_end
#define O void
#define Qq iter
#define W return
#define Q0 iterator_macro
#define Y size_t
#define QR std::tuple_element_t
#define QI tuple_many_of
#define Qh k_ptr
#define QA std::is_rvalue_reference_v
#define Qm apply
#define QX __arg3__
#define Q std::tuple
#define QC nested_vector_at
#define Qc using
#define Qa def_iterable_ostream
#define A inline
#define Q1 advance
#define M std::begin
#define Qj nested_vector_impl
#define Q5 container_carrying_iterator
#define QZ std::invoke_result_t
#define Qz implicit_lambda_binary_operator
#define q __arg1__
#define Qb make_query
#define E decltype
#define QL mutable
#define QO vs_ptr
#define QW std::get
#define o std::end
#define QK else
#define QQ int
#define QJ std::ostream
#define X const
#define Q3 tuple_tail
#define Qd is_composable_v
#define QN nested_vector_size
#define Qr to_nested_vector_impl
#define R Iterator
#define QD to_vector
#define Qv bool
#define Q6 std::shared_ptr
#define B true
#define Qx cartesian_product
#define Q9 tuple_head
#define Qw __expr1__

z<d T,Y>Qc ignore_second=T;z<Y...Ix,d T>w tuple_many_of_impl(Q4<Ix...>,X T&x){W Q(ignore_second<T,Ix>(x)...);}z<Y n,d T>w QI(X T&x){W tuple_many_of_impl(std::make_index_sequence<n>{},x);}z<Y n,d T>Qc QE=E(QI<n,T>(W1<T>()));z<d...Args>w Q9(X Q<Args...>&t){W QW<0>(t);}z<Y...Ix,d...Args>w tuple_tail_impl(Q4<Ix...>,X Q<Args...>&t){W Q(QW<Ix+1>(t)...);}z<d...Args>w Q3(X Q<Args...>&t){W tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}H empty_t{};QB empty_t empty_v;z<d T1,d T2>std::common_type_t<T1,T2>maxx(X T1&x,X T2&y){if(x<y){W y;}QK{W x;}} z<d T1,d T2,d...Ts>A w maxx(X T1&x,X T2&y,X Ts&...xs){W maxx(maxx(x,y),xs...);}z<d T1,d T2>w minn(X T1&x,X T2&y){if(x<=y){W x;}QK{W y;}} z<d T1,d T2,d...Ts>A w minn(X T1&x,X T2&y,X Ts&...xs){W minn(minn(x,y),xs...);}QB QQ _log2(QQ x){if(x==0){W 0;}W 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&]()->E(w){W f;}
#define FF_1(q,f)[&](w&&q)->E(w){(O)q;W f;}
#define FF_2(q,Qt,f)[&](w&&q,w&&Qt)->E(w){(O)q;(O)Qt;W f;}
#define FF_3(q,Qt,QX,f)[&](w&&q,w&&Qt,w&&QX)->E(w){(O)q;(O)Qt;(O)QX;W f;}
#define FF_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c]()->E(w){W f;}
#define FC_1(q,f,c)[&,c](w&&q)->E(w){(O)q;W f;}
#define FC_2(q,Qt,f,c)[&,c](w&&q,w&&Qt)->E(w){(O)q;(O)Qt;W f;}
#define FC_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2]()->E(w){W f;}
#define FC2_1(q,f,c1,c2)[&,c1,c2](w&&q)->E(w){(O)q;W f;}
#define FC2_2(q,Qt,f,c1,c2)[&,c1,c2](w&&q,w&&Qt)->E(w){(O)q;(O)Qt;W f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(q,f)[&](w&&QY)->E(w){w&[q]=QY;(O)q;W f;}
#define FT_2(q,Qt,f)[&](w&&QY)->E(w){w&[q,Qt]=QY;(O)q;(O)Qt;W f;}
#define FT_3(q,Qt,QX,f)[&](w&&QY)->E(w){w&[q,Qt,QX]=QY;(O)q;(O)Qt;(O)QX;W f;}
#define FT_4(q,Qt,QX,__arg4__,f)[&](w&&QY)->E(w){w&[q,Qt,QX,__arg4__]=QY;(O)q;(O)Qt;(O)QX;(O)__arg4__;W f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Qw,f)[&](){w&&Qw;W f;}()
#define LET_2(Qw,__expr2__,f)[&](){w&&Qw;w&&__expr2__;W f;}()
#define LET_3(Qw,__expr2__,__expr3__,f)[&](){w&&Qw;w&&__expr2__;w&&__expr3__;W f;}()
#define LET_macro_chooser(...)GET_5TH_ARG(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)QB H{Qc QF=O;templ A E(w)Z()args X code}name;
z<d F>class Qk{private:F f;public:Qk(F f_):f(f_){} z<d...Ts>QB w Z()(Ts&&...xs)X{W f(QM<Ts>(xs)...);}};Qk _([](w&&x)->Qo<QA<E(x)>,Qi<E(x)>,E(x)>{W x;});Qk _1([](w&&x,w&&)->Qo<QA<E(x)>,Qi<E(x)>,E(x)>{W x;});Qk _2([](w&&,w&&y)->Qo<QA<E(y)>,Qi<E(y)>,E(y)>{W y;});
#define implicit_lambda_unary_operator(op)z<d F>QB E(w)Z op(Qk<F>f){W Qk([=](w&&...xs){W op f(QM<E(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)z<d F,d T>QB E(w)Z op(Qk<F>f,X T&y){W Qk([=](w&&...xs){W f(QM<E(xs)>(xs)...)op y;});}z<d F,d T>QB E(w)Z op(X T&y,Qk<F>f){W Qk([=](w&&...xs){W y op f(QM<E(xs)>(xs)...);});}z<d F,d G>QB E(w)Z op(Qk<F>f,Qk<G>g){W Qk([=](w&&...xs){W f(QM<E(xs)>(xs)...)op g(QM<E(xs)>(xs)...);});}
QS(+)QS(-)QS(!)QS(~)QS(*)QS(&)Qz(+)Qz(-)Qz(*)Qz(/)Qz(%)Qz(<)Qz(>)Qz(<=)Qz(>=)Qz(==)Qz(!=)Qz(<<)Qz(>>)Qz(&)Qz(|)Qz(^)Qz(&&)z<d T,d=O>H is_composable:public std::false_type{};z<d T>H is_composable<T,std::void_t<d T::is_composable_>>:public std::true_type{};z<d T>QB Qv Qd=is_composable<T>::value;z<d T,d F,d=QZ<F,T>>E(w)Z>(T&&v,X F&f){W f(QM<T>(v));}z<d M1,d M2>H composed{Qc QF=O;X M1 m1;X M2 m2;z<d T>E(w)Z()(T&&v)X{W m1(m2(QM<T>(v)));}};z<d M1,d M2,d=std::enable_if_t<Qd<M1>or Qd<M2>>>A w Z<(X M1&m1,X M2&m2){W composed<M1,M2>{m1,m2};}z<Y n>H nth_impl{Qc QF=O;z<d...Ts>QB QR<n,Q<Ts...>>&Z()(Q<Ts...>&u)X{W QW<n>(u);}z<d...Ts>QB QR<n,Q<Ts...>>Z()(Q<Ts...>&&u)X{W QW<n>(u);}z<d...Ts>QB X QR<n,Q<Ts...>>&Z()(X Q<Ts...>&u)X{W QW<n>(u);}z<d...Ts>QB X QR<n,Q<Ts...>>Z()(X Q<Ts...>&&u)X{W QW<n>(u);}};z<Y n>QB nth_impl<n>nth;QB nth_impl<0>fst;QB nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)H R{extra Qv Z!=(X R&L)X neq R&Z++()incr E(w)Z*()X val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,QH,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{Q0(extra extra_it QL I it;,neq_it,incr_it,val_it);W Qu(it_begin,QH);})
#define def_iterator_manip_2(name,code)QB H{Qc QF=O;z<d T,d I=E(M(W1<T>())),d V=Ql<E(*W1<I>())>>E(w)Z()(T&&v)X code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ H name##_impl{Qc QF=O;extra z<d T,d I=E(M(W1<T>())),d V=Ql<E(*W1<I>())>>E(w)Z()(T&&v)X code};templ A E(w)name args{W name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
z<d T,d=O>H is_iterable:public std::false_type{};z<d T>H is_iterable<T,std::void_t<E(M(W1<T>())),E(o(W1<T>()))>>:public std::true_type{};z<d T>QB Qv is_iterable_v=is_iterable<T>::value;z<d I>A w Qu(X I&b,X I&e){H Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
Qc is_iterable_wrapper=O;Qc iterator=I;Qc value_type=Ql<E(*W1<I>())>;
#pragma GCC diagnostic pop
I b,e;w begin()X{W b;}w end()X{W e;}};W Wrapper{b,e};}z<d T>A w Qq(T&&iterable){W Qu(M(QM<T>(iterable)),o(QM<T>(iterable)));}z<d I>A w Qq(X I&b,X I&e){W Qu(b,e);}z<d C>H Q5:public C::iterator{Q6<C>p;Q5(Q6<C>p_,d C::iterator it):C::iterator(it),p(p_){}};z<d C>A w iterc(C&&v){Qc D=Ql<C>;Q6<D>p(new D(QM<C>(v)));W Qu(Q5<D>{p,M(*p)},Q5<D>{p,o(*p)});}z<d T>A w Qq(std::initializer_list<T>l){W iterc(QT<T>(l));}def_template_lambda(z<d T>,QD,(T&&v),{QT<d Ql<T>::value_type>s;for(w&&x:v){s.Qs(x);}W s;})z<Y n>H Qr{z<d T>A static w make(T&&v){W QM<T>(v)>Qm(FF(u,Qr<n-1>::make(u)))>QD;}};z<>H Qr<1>{z<d T>A static w make(T&&v){W QM<T>(v)>QD;}};z<Y n>H to_nested_vector_{Qc QF=O;z<d T>A E(w)Z()(T&&v)X{W Qr<n>::make(QM<T>(v));}};z<Y n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(Y l,Y r),({l,r}),Y l;Y r;,{W Qq(M(v)+l,M(v)+r);})def_iterator_manip(is_nil,{W not(M(v)!=o(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{Y l=0;for(w i=M(v);i!=o(v);++i){++l;}W l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
z<d T1,d T2,d T3,d T=std::make_signed_t<E(T1()+T2()+T3())>>A w Q2(X T1&b,X T2&e,X T3&step){Q0(T x;T e;T step;A Qv P()X{W(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{W P()xor L.P();},{x+=step;W*Qn;},{W T(x);}) W Qq(R{b,e,step},R{e,e,step});}z<d T1,d T2>A w Q2(X T1&b,X T2&e){W Q2(b,e,E(T1()+T2())(1));}z<d T>A w Q2(X T&e){W Q2(T(),e,T(1));} 
#pragma GCC diagnostic pop
z<d T>A w to_infinity(X T&b=0,X T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
Q0(T x;T step;,{(O)L;W B;},{x+=step;W*Qn;},{W T(x);}) W Qq(R{b,step},R{b,step});
#pragma GCC diagnostic pop
}Q7(Qm,z<d F>,(F f),<F>{f},F f;,(R{f,M(v)}),(R{f,o(v)}),,{ W it!=L.it;},{++it;W*Qn;},{W f(*it);}) Q7(take,,(Y n),{n},Y n;,(R{n,M(v)}),(R{0,o(v)}),,{ W n!=L.n;},{--n;if(n>0){++it;}W*Qn;},{W*it;}) Q7(take_while,z<d F>,(F f),<F>{f},F f;,(R{f,not(M(v)!=o(v)and f(*M(v))),M(v)}),(R{f,B,o(v)}),Qv P;,{W P xor L.P;},{++it;if(not f(*it)){P=B;}W*Qn;},{W*it;}) Q7(drop,,(Y n),{n},QL Y n;,(R{n,o(v),M(v)}),(R{0,o(v),o(v)}),X I end_it;A O Q1()X{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{Q1();L.Q1();W it!=L.it;},{Q1();++it;W*Qn;},{Q1();W*it;}) Q7(drop_while,z<d F>,(F f),<F>{f},F f;,(R{f,o(v),Qe,M(v)}),(R{f,o(v),B,o(v)}),X I end_it;QL Qv Qy;A O Q1()X{if(not Qy){while(it!=end_it and f(*it)){++it;}Qy=B;}},{Q1();L.Q1();W it!=L.it;},{Q1();++it;W*Qn;},{Q1();W*it;}) def_iterator_manip(head,{W*M(v);})A w tail=drop(1);A w at(Y n){W head<drop(n);}Q7(cons,z<d S>,(S s),<S>{s},S s;,(R{s,B,M(v)}),(R{s,Qe,o(v)}),Qv is_s;,{W is_s!=L.is_s or it!=L.it;},{if(is_s){is_s=Qe;}QK{++it;}W*Qn;},{W(is_s)?(s):(*it);}) def_iterator_manip(snoc,{w it=M(v);w h=*it;++it;W Q(h,Qq(it,o(v)));})def_iterator_manip(split_at,,(Y n),{n},Y n;,{w it=M(v);QT<T>u;for(w i:Q2(n)){u.Qs(*it);++it;}W Q(iterc(QG(u)),Qq(it,o(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
Q7(chunks_of,,(Y n),{n},Y n;,(R{n,{},Qe,o(v),M(v)}),(R{n,{},Qe,o(v),o(v)}),QL QT<V>u;QL Qv Qp;I QH;O update()X{u.clear();Qp=B;for(w i:Q2(n)){if(it!=QH){u.Qs(*it);++it;}QK{break;}}},{W it!=L.it;},{if(Qp){Qp=Qe;}QK{for(w i:Q2(n)){if(it!=QH){++it;}QK{break;}}}W*Qn;},{if(not Qp){update();}W iterc(u);})
#pragma GCC diagnostic pop
z<d F,d S>H fold_impl{Qc QF=O;F f;S s;z<d T>w Z()(X T&v)X{w x=s;for(w y:v){x=f(x,y);}W x;}};z<d F,d S>A w fold(F f,X S&s){W fold_impl<F,S>{f,s};}def_iterator_manip(fold1,z<d F>,(F f),<F>{f},F f;,{w u=v>snoc;W u>snd>fold(f,u>fst);})def_iterator_manip(sum,{W v>fold(_1+_2,V(0));})def_iterator_manip(product,{W v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,z<d F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{W v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,z<d F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,z<d F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{W v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,z<d F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})z<d F,d S>H scan_impl{Qc QF=O;F f;S s;z<d T,d I=E(M(W1<T>()))>E(w)Z()(T&&v)X{Q0(F f;QL S s;QL Qv Qp;Qv Qy;QL I it;,{W it!=L.it;},{if(not Qp){s=f(s,*it);};Qp=Qe;if(Qy){++it;}QK{Qy=B;}W*Qn;},{if(not Qp){Qp=B;s=f(s,*it);}W s;}) W Qq(R{f,s,B,Qe,M(QM<T>(v))},R{f,s,B,B,o(QM<T>(v))});}};z<d F,d S>A w scan(F f,X S&s){W scan_impl<F,S>{f,s};}Q7(scan1,z<d F>,(F f),<F>{f},F f;,(R{f,*M(v),B,M(v)}),(R{f,*M(v),B,o(v)}),QL V s;QL Qv Qp;,{W it!=L.it;},{if(not Qp){s=f(s,*it);};Qp=Qe;++it;W*Qn;},{if(not Qp){Qp=B;s=f(s,*it);}W s;}) z<d T,d S,d I=E(M(W1<T>())),d J=E(M(W1<S>()))>A w Z+(T&&v,S&&u){Q0(I i;I i_end;J j;Qv in_i;,{W i!=L.i or j!=L.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=Qe;}}QK{++j;}W*Qn;},{W(in_i)?(*i):(*j);}) I bv=M(v);I ev=o(v);J bu=M(u);J eu=o(u);W Qq(R{bv,ev,bu,bv!=ev},R{ev,ev,eu,Qe});}QB H{Qc QF=O;z<d T>w Z()(T&&v)X{w u=QM<T>(v)>filter(FF(i,not is_nil(i)));w b=M(u);w e=o(u);Qc J=E(b);Qc V=Ql<E(*b)>;Qc K=E(M(*b));H R{J j;J QP;Q6<V>Q_;K*Qh;Qv P;R(J j,J QP,X V&jv,Qv P):j(j),QP(QP),Q_(new V(jv)),Qh(new K(M(*Q_))),P(P){} R(J j,J QP,Qv P):j(j),QP(QP),Q_(nullptr),Qh(nullptr),P(P){} R(X R&L):j(L.j),QP(L.QP),Q_(L.Q_),Qh((L.Qh)?(new K(*L.Qh)):nullptr),P(L.P){} R(R&&L):j(L.j),QP(L.QP),Q_(L.Q_),Qh((L.Qh)?(new K(*L.Qh)):nullptr),P(L.P){}~R(){delete Qh;}Qv Z!=(X R&L)X{W P xor L.P;}R&Z++(){++*Qh;if(not(*Qh!=o(*Q_))){++j;if(j!=QP){delete Qh;Q_=std::make_shared<V>(*j);Qh=new K(M(*Q_));}QK{P=B;}} W*Qn;}E(w)Z*()X{W**Qh;}};if(u>is_nil){W Qu(R(b,e,B),R(b,e,B));}QK{W Qu(R(b,e,*b,Qe),R(e,e,B));}}}flatten;z<d T,d F,d=std::enable_if_t<is_iterable_v<T>>>w Z>=(T&&v,F f){W v>Qm(f)>flatten;}z<d U,Y...Is>A Qv all_different_(X U&x,X U&y,Q4<Is...>){W((QW<Is>(x)!=QW<Is>(y))&&...);}z<d F,d...Ts>A w zip_with(F f,Ts&&...vs){Q0(F f;Q<E(M(W1<Ts>()))...>its;,{W all_different_(its,L.its,std::index_sequence_for<Ts...>{});},{QU([&](w&&...xs){(++xs,...);},its);W*Qn;},{W QU([&](w&&...xs){W f(*xs...);},its);}) W Qq(R{f,Q(M(vs)...)},R{f,Q(o(vs)...)});};H zip_default_function_{z<d...Ts>E(w)Z()(Ts&&...xs)X{W Q<Ts...>(QM<Ts>(xs)...);}};z<d...Ts>A w zip(Ts&&...vs){W zip_with(zip_default_function_{},QM<Ts>(vs)...);}Q7(filter,z<d F>,(F f),<F>{f},F f;,(R{f,o(v),M(v)}),(R{f,o(v),o(v)}),X I end_it;A O Q1()X{while(it!=end_it and not f(*it)){++it;}},{Q1();L.Q1();W it!=L.it;},{Q1();++it;W*Qn;},{Q1();W*it;}) def_template_lambda(z<d T>,repeat,(T&&v),{H R{X Ql<T>v;Qv Z!=(X R&)X{W B;}R&Z++(){W*Qn;}X w&Z*()X{W v;}};W Qq(R{v},R{v});})A w replicate(Y n){W take(n)<repeat;}A w cycle=flatten<repeat;def_iterator_manip(enumerate,{W zip(to_infinity(Y(0)),v);})def_iterator_manip(reversed,{w s=v>QD;std::reverse(s.begin(),s.end());W iterc(QG(s));})def_iterator_manip(sorted_by,z<d F>,(F f),<F>{f},F f;,{w s=v>QD;std::sort(M(s),o(s),f);W iterc(QG(s));})def_iterator_manip(sorted,{W v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,z<d F>,(F f),<F>{f},F f;,{W v>Qm(FF(i,Q(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>Qm(fst);})def_iterator_manip(nub,{Q0(I QH;I it;,{W it!=L.it;},{E(*it)pr;do{pr=*it;++it;}while(it!=QH and pr==*it);W*Qn;},{W*it;}) w b=M(v);w e=o(v);W Qq(R{e,b},R{e,e});})z<d F,d S>H accum_vector_by_{Qc QF=O;Y n;F f;S s;z<d T,d I=E(M(W1<T>())),d V=Ql<E(*W1<I>())>>E(w)Z()(X T&v)X{QT<Ql<QZ<F,S,E(QW<1>(W1<V>()))>>>u(n,s);for(w&&[i,x]:v){u[i]=f(u[i],x);}W u;}};z<d F,d S>A w accum_vector_by(Y n,F f,X S&s){W accum_vector_by_<F,S>{n,f,s};}z<d S>A w accum_vector(Y n,X S&s=S()){W accum_vector_by(n,_2,s);}z<d F,d S>H accum_map_by_{Qc QF=O;F f;S s;z<d T,d I=E(M(W1<T>())),d V=Ql<E(*W1<I>())>>E(w)Z()(X T&v)X{std::map<Ql<E(QW<0>(W1<V>()))>,Ql<QZ<F,S,E(QW<1>(W1<V>()))>>>u;for(w&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QK{u[i]=f(s,x);}} W u;}};z<d F,d S>A w accum_map_by(F f,X S&s){W accum_map_by_<F,S>{f,s};}z<d S>A w accum_map(X S&s=S()){W accum_map_by(_2,s);}z<d F,d S>H accum_unordered_map_by_{Qc QF=O;F f;S s;z<d T,d I=E(M(W1<T>())),d V=Ql<E(*W1<I>())>>E(w)Z()(X T&v)X{std::unordered_map<Ql<E(QW<0>(W1<V>()))>,Ql<QZ<F,S,E(QW<1>(W1<V>()))>>>u;for(w&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QK{u[i]=f(s,x);}} W u;}};z<d F,d S>A w accum_unordered_map_by(F f,X S&s){W accum_unordered_map_by_<F,S>{f,s};}z<d S>A w accum_unordered_map(X S&s=S()){W accum_unordered_map_by(_2,s);}z<d U,Y...Is>A Qv any_different_(X U&x,X U&y,Q4<Is...>){W((QW<Is>(x)!=QW<Is>(y))||...);}z<Y N,d R>A O QV(R&it){if QB(N>=1){++QW<N-1>(it.its);if(not(QW<N-1>(it.its)!=o(QW<N-1>(*it.my_vs_ptr)))){QW<N-1>(it.its)=M(QW<N-1>(*it.my_vs_ptr));QV<N-1>(it);}} QK{it.its=QU([](w&&...xs){W Q(o(xs)...);},*it.my_vs_ptr);}} z<d...Ts>w Qx(Ts&&...vs){w QO=std::make_shared<Q<Qo<QA<Ts>,Qi<Ts>,Ts>...>>(vs...);Q0(Q<E(M(W1<Qo<QA<Ts>,Qi<Ts>,Ts>>()))...>its;E(QO)my_vs_ptr;,{W any_different_(its,L.its,std::index_sequence_for<Ts...>{});},{QV<sizeof...(Ts)>(*Qn);W*Qn;},{W QU([](w&&...xs){W Q<E(*xs)...>(*xs...);},its);}) if(QU([](w&&...xs){W((xs>is_nil)||...);},*QO)){W Qq(R{QU([](w&&...xs){W Q(o(xs)...);},*QO),QO},R{QU([](w&&...xs){W Q(o(xs)...);},*QO),QO});}QK{W Qq(R{QU([](w&&...xs){W Q(M(xs)...);},*QO),QO},R{QU([](w&&...xs){W Q(o(xs)...);},*QO),QO});}};z<d...Ts>A w cartesian_product_range(X Ts&...n){W Qx(Q2(n)...);}z<Y n,d I>A w cartesian_power(X I&v){W QU([](X w&...vs){W Qx(vs...);},QI<n>(v));}H{Qc QF=O;QQ n=-1;z<d T>w Z()(T&&v)X{if QB(std::is_convertible_v<T,QQ>){w x=*Qn;x.n=v;W x;}QK{w vec=v>QD;QQ m=vec.size();H R{QQ n;E(vec)Qg;QT<Y>cycles;Qv P;Qv Z!=(X R&L)X{W P xor L.P;}R&Z++(){for(w i:Q2(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=Qg.size()-i;std::rotate(Qg.begin()+i,Qg.begin()+i+1,Qg.end());}QK{std::swap(Qg[i],Qg[Qg.size()-cycles[i]]);W*Qn;}} P=B;W*Qn;}w Z*()X{W Qg>array_slice(0,n);}};QQ n1=(n<0)?(m):(n);W Qq(R{n1,QG(vec),Q2(m,m-n1,-1)>Qm(FF(x,Y(x)))>QD,Qe},R{n1,{},{},B});}}}permutations;H combinations_impl{Qc QF=O;QQ n;z<d T>w Z()(T&&v)X{w vec=v>QD;QQ m=vec.size();Q0(QQ n;E(vec)Qg;QT<Y>idx;Qv P;,{W P xor L.P;},{for(w i:Q2(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(w j:Q2(i+1,n)){idx[j]=idx[j-1]+1;}W*Qn;}} P=B;W*Qn;},{W idx>array_slice(0,n)>Qm(FF(i,Qg[i]));}) W Qq(R{n,QG(vec),Q2(0,m)>Qm(FF(x,Y(x)))>QD,Qe},R{n,{},{},B});}};A w combinations(QQ n){W combinations_impl{n};}H Q8{Qc QF=O;QQ n;z<d T>w Z()(T&&v)X{w vec=v>QD;QQ m=vec.size();Q0(QQ n;E(vec)Qg;QT<Y>idx;Qv P;,{W P xor L.P;},{for(w i:Q2(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(w j:Q2(i+1,n)){idx[j]=idx[i];}W*Qn;}} P=B;W*Qn;},{W idx>array_slice(0,n)>Qm(FF(i,Qg[i]));}) W Qq(R{n,QG(vec),Y(0)>replicate(m)>QD,Qe},R{n,{},{},B});}};A w combinations_with_replacement(QQ n){W Q8{n};}z<d T>A w istream_iterable(std::istream&in){Q0(std::istream&in;QL T val;Qv P;QL Qv has_read;,{W P xor L.P;},{if(not(in>>val)){P=B;}W*Qn;},{if(not has_read){has_read=B;in>>val;}W val;}) W Qq(R{in,T{},Qe,Qe},R{in,T{},B,B});}z<d T>A w input=istream_iterable<T>(std::cin);z<d T>QJ&print_iterable(QJ&out,X T&v,X std::string&sep= " "){for(w it=M(v);it!=o(v);){ out<<*it;++it;if(it!=o(v)){out<<sep;}QK{W out;}} W out;}z<d T,d=d T::is_iterable_wrapper>A QJ&Z<<(QJ&out,X T&v){out<< "[";W print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)z<d...Ts>QJ&Z<<(QJ&out,X I<Ts...>&v){W out<<Qq(v);}
Qa(QT)Qa(std::map)Qa(std::unordered_map)Qa(std::set)Qa(std::unordered_set)z<Y n,d T>H Qj{Qc type=QT<d Qj<n-1,T>::type>;static w make(X QE<n,Y>&sz,X T&val=T()){W QT(Q9(sz),Qj<n-1,T>::make(Q3(sz),val));}};z<d T>H Qj<1,T>{Qc type=QT<T>;static w make(X Q<Y>&sz,X T&val=T()){W QT(Q9(sz),val);}};z<Y n,d T>Qc nested_vector=d Qj<n,T>::type;z<Y n,d T>w make_nested_vector(X QE<n,Y>&sz,X T&val=T()){W Qj<n,T>::make(sz,val);}z<Y n,d T>A w QN(X T&v){if QB(n==1){W Q(v.size());}QK{W std::tuple_cat(Q(v.size()),QN<n-1>(v[0]));}} z<Y n,d T>A w nested_vector_indices(X T&v){W QU([&](w...x){W cartesian_product_range(x...);},QN<n>(v));}z<Y n,d T>A E(w)QC(X QT<T>&v,X QE<n,Y>&i){if QB(n==1){W v[Q9(i)];}QK{W QC<n-1>(v[Q9(i)],Q3(i));}} z<Y n,d T>A E(w)QC(QT<T>&v,X QE<n,Y>&i){if QB(n==1){W v[Q9(i)];}QK{W QC<n-1>(v[Q9(i)],Q3(i));}} z<d U,Y i,Y s>QJ&Qf(QJ&out,X U&u){if QB(i==0){out<< "{ ";}out<<QW<i>(u);if QB(i+1<s){out<< ", ";W Qf<U,i+1,s>(out,u);}QK{W out<< " }";}} z<d...Ts>QJ&Z<<(QJ&out,X Q<Ts...>&u){W Qf<E(u),0,sizeof...(Ts)>(out,u);}z<d T,d S>QJ&Z<<(QJ&out,X std::pair<T,S>&p){W out<<Q(p.first,p.second);} 
#define BEGIN  QQ main(){std::ios_base::sync_with_stdio(Qe);std::cin.tie(0);std::cout.tie(0);
#define END }
Qc namespace std;Qc LL=long long;w Qb(QQ t,QQ i,QQ j,QQ k){cout<<t<< " " <<i<< " " <<j<< " " <<k<<endl;LL ans;cin>>ans;W ans;}w solve_half(QQ i,QQ j,vector<QQ>v){if(v.empty()){W vector<QQ>{};}w areas=v>Qm(FF(x,tuple(x,Qb(1,i,j,x))))>QD;w maxi=areas>maximum_on(snd)>fst;E(areas)bef,aft;for(w[k,a]:areas){if(maxi==k){continue;}if(Qb(2,i,maxi,k)==1){aft.emplace_back(k,a);}QK{bef.emplace_back(k,a);}} W((bef>sorted_on(snd)>Qm(fst))+Qq({maxi})+(aft>sorted_on(snd)>Qm(fst)>reversed))>QD;}QQ main(){QQ N;cin>>N;vector<QQ>up,down;for(QQ n=3;n<=N;++n){if(Qb(2,1,2,n)==1){up.Qs(n);}QK{down.Qs(n);}} vector<QQ>ans={1};w x=solve_half(1,2,down);ans.insert(ans.end(),x.begin(),x.end());ans.Qs(2);x=solve_half(2,1,up);ans.insert(ans.end(),x.begin(),x.end());cout<<0<< " ";for(w i:ans){cout<<i<< " ";}cout<<endl;}