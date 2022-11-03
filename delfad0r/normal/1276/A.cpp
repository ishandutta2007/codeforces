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
#define QC __expr1__
#define QX implicit_lambda_unary_operator
#define z size_t
#define QA nested_vector_size
#define L std::tuple
#define QP std::conditional_t
#define QV std::vector
#define H operator
#define QR __arg3__
#define P template
#define QE else
#define q std::begin
#define QL std::index_sequence
#define M return
#define Ql tuple_many_of_t
#define Qz GET_5TH_ARG
#define Qu iterable_wrapper
#define Qg std::shared_ptr
#define Q5 to_vector
#define QM k_ptr
#define Qi std::ostream
#define k inline
#define QW has_advanced
#define O other
#define Qx implicit_lambda
#define Q9 apply
#define Q1 std::forward
#define Q8 is_composable_v
#define QJ bool
#define Q3 std::move
#define d typename
#define QN range
#define o __arg1__
#define Y void
#define Qk using
#define Qp is_composable_
#define QH tuple_head
#define Qj iterator_macro
#define Qb def_iterator_manip_iter
#define QB advance
#define Qh container_carrying_iterator
#define QI it_end
#define QU def_iterable_ostream
#define Qa tuple_tail
#define Qr nested_vector_at
#define QF has_updated
#define Qt cartesian_product
#define R decltype
#define QD constexpr
#define Qv to_nested_vector_impl
#define QQ std::get
#define X struct
#define Qq jv_ptr
#define Qo combinations_with_replacement_impl
#define QK ostream_tuple_helper_
#define Qw this
#define E is_end
#define Qm std::declval
#define Qn push_back
#define QO std::remove_reference_t
#define Qy cartesian_product_incr_
#define W std::end
#define a true
#define Qf __tuple__
#define Qe std::invoke_result_t
#define QG __arg2__
#define Q2 false
#define Q7 std::apply
#define QY vs_ptr
#define Q6 j_end
#define Q auto
#define Z Iterator
#define QZ std::tuple_element_t
#define QT std::decay_t
#define Q4 iter
#define Q0 std::is_rvalue_reference_v
#define w const
#define Qd my_v
#define Qs implicit_lambda_binary_operator
#define Qc mutable
#define QS nested_vector_impl

P<d T,z>Qk ignore_second=T;P<z...Ix,d T>Q tuple_many_of_impl(QL<Ix...>,w T&x){M L(ignore_second<T,Ix>(x)...);}P<z n,d T>Q tuple_many_of(w T&x){M tuple_many_of_impl(std::make_index_sequence<n>{},x);}P<z n,d T>Qk Ql=R(tuple_many_of<n,T>(Qm<T>()));P<d...Args>Q QH(w L<Args...>&t){M QQ<0>(t);}P<z...Ix,d...Args>Q tuple_tail_impl(QL<Ix...>,w L<Args...>&t){M L(QQ<Ix+1>(t)...);}P<d...Args>Q Qa(w L<Args...>&t){M tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}X empty_t{};QD empty_t empty_v;P<d T1,d T2>std::common_type_t<T1,T2>maxx(w T1&x,w T2&y){if(x<y){M y;}QE{M x;}} P<d T1,d T2,d...Ts>k Q maxx(w T1&x,w T2&y,w Ts&...xs){M maxx(maxx(x,y),xs...);}P<d T1,d T2>Q minn(w T1&x,w T2&y){if(x<=y){M x;}QE{M y;}} P<d T1,d T2,d...Ts>k Q minn(w T1&x,w T2&y,w Ts&...xs){M minn(minn(x,y),xs...);}QD int _log2(int x){if(x==0){M 0;}M 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){M f;}
#define FF_1(o,f)[&](Q&&o){(Y)o;M f;}
#define FF_2(o,QG,f)[&](Q&&o,Q&&QG){(Y)o;(Y)QG;M f;}
#define FF_3(o,QG,QR,f)[&](Q&&o,Q&&QG,Q&&QR){(Y)o;(Y)QG;(Y)QR;M f;}
#define FF_macro_chooser(...)Qz(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->Q&{M f;}
#define FREF_1(o,f)[&](Q&&o)->Q&{(Y)o;M f;}
#define FREF_2(o,QG,f)[&](Q&&o,Q&&QG)->Q&{(Y)o;(Y)QG;M f;}
#define FREF_3(o,QG,QR,f)[&](Q&&o,Q&&QG,Q&&QR)->Q&{(Y)o;(Y)QG;(Y)QR;M f;}
#define FREF_macro_chooser(...)Qz(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){M f;}
#define FC_1(o,f,c)[&,c](Q&&o){(Y)o;M f;}
#define FC_2(o,QG,f,c)[&,c](Q&&o,Q&&QG){(Y)o;(Y)QG;M f;}
#define FC_macro_chooser(...)Qz(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){M f;}
#define FC2_1(o,f,c1,c2)[&,c1,c2](Q&&o){(Y)o;M f;}
#define FC2_2(o,QG,f,c1,c2)[&,c1,c2](Q&&o,Q&&QG){(Y)o;(Y)QG;M f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(o,f)[&](Q&&Qf){Q&[o]=Qf;(Y)o;M f;}
#define FT_2(o,QG,f)[&](Q&&Qf){Q&[o,QG]=Qf;(Y)o;(Y)QG;M f;}
#define FT_3(o,QG,QR,f)[&](Q&&Qf){Q&[o,QG,QR]=Qf;(Y)o;(Y)QG;(Y)QR;M f;}
#define FT_4(o,QG,QR,__arg4__,f)[&](Q&&Qf){Q&[o,QG,QR,__arg4__]=Qf;(Y)o;(Y)QG;(Y)QR;(Y)__arg4__;M f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(QC,f)[&](){Q&&QC;M f;}()
#define LET_2(QC,__expr2__,f)[&](){Q&&QC;Q&&__expr2__;M f;}()
#define LET_3(QC,__expr2__,__expr3__,f)[&](){Q&&QC;Q&&__expr2__;Q&&__expr3__;M f;}()
#define LET_macro_chooser(...)Qz(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)QD X{Qk Qp=Y;templ k R(Q)H()args w code}name;
P<d F>class Qx{private:F f;public:Qx(F f_):f(f_){} P<d...Ts>QD Q H()(Ts&&...xs)w{M f(Q1<Ts>(xs)...);}};Qx _([](Q&&x)->QP<Q0<R(x)>,QO<R(x)>,R(x)>{M x;});Qx _1([](Q&&x,Q&&)->QP<Q0<R(x)>,QO<R(x)>,R(x)>{M x;});Qx _2([](Q&&,Q&&y)->QP<Q0<R(y)>,QO<R(y)>,R(y)>{M y;});
#define implicit_lambda_unary_operator(op)P<d F>QD R(Q)H op(Qx<F>f){M Qx([=](Q&&...xs){M op f(Q1<R(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)P<d F,d T>QD R(Q)H op(Qx<F>f,w T&y){M Qx([=](Q&&...xs){M f(Q1<R(xs)>(xs)...)op y;});}P<d F,d T>QD R(Q)H op(w T&y,Qx<F>f){M Qx([=](Q&&...xs){M y op f(Q1<R(xs)>(xs)...);});}P<d F,d G>QD R(Q)H op(Qx<F>f,Qx<G>g){M Qx([=](Q&&...xs){M f(Q1<R(xs)>(xs)...)op g(Q1<R(xs)>(xs)...);});}
QX(+)QX(-)QX(!)QX(~)QX(*)QX(&)Qs(+)Qs(-)Qs(*)Qs(/)Qs(%)Qs(<)Qs(>)Qs(<=)Qs(>=)Qs(==)Qs(!=)Qs(<<)Qs(>>)Qs(&)Qs(|)Qs(^)Qs(&&)P<d T,d=Y>X is_composable:public std::false_type{};P<d T>X is_composable<T,std::void_t<d T::is_composable_>>:public std::true_type{};P<d T>QD QJ Q8=is_composable<T>::value;P<d T,d F,d=Qe<F,T>>R(Q)H>(T&&v,w F&f){M f(Q1<T>(v));}P<d M1,d M2>X composed{Qk Qp=Y;w M1 m1;w M2 m2;P<d T>R(Q)H()(T&&v)w{M m1(m2(Q1<T>(v)));}};P<d M1,d M2,d=std::enable_if_t<Q8<M1>or Q8<M2>>>k Q H<(w M1&m1,w M2&m2){M composed<M1,M2>{m1,m2};}P<z n>X nth_impl{Qk Qp=Y;P<d...Ts>QD QZ<n,L<Ts...>>&H()(L<Ts...>&u)w{M QQ<n>(u);}P<d...Ts>QD QZ<n,L<Ts...>>H()(L<Ts...>&&u)w{M QQ<n>(u);}P<d...Ts>QD w QZ<n,L<Ts...>>&H()(w L<Ts...>&u)w{M QQ<n>(u);}P<d...Ts>QD w QZ<n,L<Ts...>>H()(w L<Ts...>&&u)w{M QQ<n>(u);}};P<z n>QD nth_impl<n>nth;QD nth_impl<0>fst;QD nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)X Z{extra QJ H!=(w Z&O)w neq Z&H++()incr R(Q)H*()w val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,QI,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{Qj(extra extra_it Qc I it;,neq_it,incr_it,val_it);M Qu(it_begin,QI);})
#define def_iterator_manip_2(name,code)QD X{Qk Qp=Y;P<d T,d I=R(q(Qm<T>())),d V=QT<R(*Qm<I>())>>R(Q)H()(T&&v)w code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ X name##_impl{Qk Qp=Y;extra P<d T,d I=R(q(Qm<T>())),d V=QT<R(*Qm<I>())>>R(Q)H()(T&&v)w code};templ k R(Q)name args{M name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
P<d T,d=Y>X is_iterable:public std::false_type{};P<d T>X is_iterable<T,std::void_t<R(q(Qm<T>())),R(W(Qm<T>()))>>:public std::true_type{};P<d T>QD QJ is_iterable_v=is_iterable<T>::value;P<d I>k Q Qu(w I&b,w I&e){X Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
Qk is_iterable_wrapper=Y;Qk iterator=I;Qk value_type=QT<R(*Qm<I>())>;
#pragma GCC diagnostic pop
I b,e;Q begin()w{M b;}Q end()w{M e;}};M Wrapper{b,e};}P<d T>k Q Q4(T&&iterable){M Qu(q(Q1<T>(iterable)),W(Q1<T>(iterable)));}P<d I>k Q Q4(w I&b,w I&e){M Qu(b,e);}P<d C>X Qh:public C::iterator{Qg<C>p;Qh(Qg<C>p_,d C::iterator it):C::iterator(it),p(p_){}};P<d C>k Q iterc(C&&v){Qk D=QT<C>;Qg<D>p(new D(Q1<C>(v)));M Qu(Qh<D>{p,q(*p)},Qh<D>{p,W(*p)});}P<d T>k Q Q4(std::initializer_list<T>l){M iterc(QV<T>(l));}def_template_lambda(P<d T>,Q5,(T&&v),{QV<d QT<T>::value_type>s;for(Q&&x:v){s.Qn(x);}M s;})P<z n>X Qv{P<d T>k static Q make(T&&v){M Q1<T>(v)>Q9(FF(u,Qv<n-1>::make(u)))>Q5;}};P<>X Qv<1>{P<d T>k static Q make(T&&v){M Q1<T>(v)>Q5;}};P<z n>X to_nested_vector_{Qk Qp=Y;P<d T>k R(Q)H()(T&&v)w{M Qv<n>::make(Q1<T>(v));}};P<z n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(z l,z r),({l,r}),z l;z r;,{M Q4(q(v)+l,q(v)+r);})def_iterator_manip(is_nil,{M not(q(v)!=W(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{z l=0;for(Q i=q(v);i!=W(v);++i){++l;}M l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
P<d T1,d T2,d T3,d T=std::make_signed_t<R(T1()+T2()+T3())>>k Q QN(w T1&b,w T2&e,w T3&step){Qj(T x;T e;T step;k QJ E()w{M(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{M E()xor O.E();},{x+=step;M*Qw;},{M T(x);}) M Q4(Z{b,e,step},Z{e,e,step});}P<d T1,d T2>k Q QN(w T1&b,w T2&e){M QN(b,e,R(T1()+T2())(1));}P<d T>k Q QN(w T&e){M QN(T(),e,T(1));} 
#pragma GCC diagnostic pop
P<d T>k Q to_infinity(w T&b=0,w T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
Qj(T x;T step;,{(Y)O;M a;},{x+=step;M*Qw;},{M T(x);}) M Q4(Z{b,step},Z{b,step});
#pragma GCC diagnostic pop
}Qb(Q9,P<d F>,(F f),<F>{f},F f;,(Z{f,q(v)}),(Z{f,W(v)}),,{ M it!=O.it;},{++it;M*Qw;},{M f(*it);}) Qb(take,,(z n),{n},z n;,(Z{n,q(v)}),(Z{0,W(v)}),,{ M n!=O.n;},{--n;if(n>0){++it;}M*Qw;},{M*it;}) Qb(take_while,P<d F>,(F f),<F>{f},F f;,(Z{f,not(q(v)!=W(v)and f(*q(v))),q(v)}),(Z{f,a,W(v)}),QJ E;,{M E xor O.E;},{++it;if(not f(*it)){E=a;}M*Qw;},{M*it;}) Qb(drop,,(z n),{n},Qc z n;,(Z{n,W(v),q(v)}),(Z{0,W(v),W(v)}),w I end_it;k Y QB()w{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{QB();O.QB();M it!=O.it;},{QB();++it;M*Qw;},{QB();M*it;}) Qb(drop_while,P<d F>,(F f),<F>{f},F f;,(Z{f,W(v),Q2,q(v)}),(Z{f,W(v),a,W(v)}),w I end_it;Qc QJ QW;k Y QB()w{if(not QW){while(it!=end_it and f(*it)){++it;}QW=a;}},{QB();O.QB();M it!=O.it;},{QB();++it;M*Qw;},{QB();M*it;}) def_iterator_manip(head,{M*q(v);})k Q tail=drop(1);k Q at(z n){M head<drop(n);}Qb(cons,P<d S>,(S s),<S>{s},S s;,(Z{s,a,q(v)}),(Z{s,Q2,W(v)}),QJ is_s;,{M is_s!=O.is_s or it!=O.it;},{if(is_s){is_s=Q2;}QE{++it;}M*Qw;},{M(is_s)?(s):(*it);}) def_iterator_manip(snoc,{Q it=q(v);Q h=*it;++it;M L(h,Q4(it,W(v)));})def_iterator_manip(split_at,,(z n),{n},z n;,{Q it=q(v);QV<T>u;for(Q i:QN(n)){u.Qn(*it);++it;}M L(iterc(Q3(u)),Q4(it,W(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
Qb(chunks_of,,(z n),{n},z n;,(Z{n,{},Q2,W(v),q(v)}),(Z{n,{},Q2,W(v),W(v)}),Qc QV<V>u;Qc QJ QF;I QI;Y update()w{u.clear();QF=a;for(Q i:QN(n)){if(it!=QI){u.Qn(*it);++it;}QE{break;}}},{M it!=O.it;},{if(QF){QF=Q2;}QE{for(Q i:QN(n)){if(it!=QI){++it;}QE{break;}}}M*Qw;},{if(not QF){update();}M iterc(u);})
#pragma GCC diagnostic pop
P<d F,d S>X fold_impl{Qk Qp=Y;F f;S s;P<d T>Q H()(w T&v)w{Q x=s;for(Q y:v){x=f(x,y);}M x;}};P<d F,d S>k Q fold(F f,w S&s){M fold_impl<F,S>{f,s};}def_iterator_manip(fold1,P<d F>,(F f),<F>{f},F f;,{Q u=v>snoc;M u>snd>fold(f,u>fst);})def_iterator_manip(sum,{M v>fold(_1+_2,V(0));})def_iterator_manip(product,{M v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,P<d F>,(F f),<F>{f},F f;,{M v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{M v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,P<d F>,(F f),<F>{f},F f;,{M v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,P<d F>,(F f),<F>{f},F f;,{M v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{M v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,P<d F>,(F f),<F>{f},F f;,{M v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})P<d F,d S>X scan_impl{Qk Qp=Y;F f;S s;P<d T,d I=R(q(Qm<T>()))>R(Q)H()(T&&v)w{Qj(F f;Qc S s;Qc QJ QF;QJ QW;Qc I it;,{M it!=O.it;},{if(not QF){s=f(s,*it);};QF=Q2;if(QW){++it;}QE{QW=a;}M*Qw;},{if(not QF){QF=a;s=f(s,*it);}M s;}) M Q4(Z{f,s,a,Q2,q(Q1<T>(v))},Z{f,s,a,a,W(Q1<T>(v))});}};P<d F,d S>k Q scan(F f,w S&s){M scan_impl<F,S>{f,s};}Qb(scan1,P<d F>,(F f),<F>{f},F f;,(Z{f,*q(v),a,q(v)}),(Z{f,*q(v),a,W(v)}),Qc V s;Qc QJ QF;,{M it!=O.it;},{if(not QF){s=f(s,*it);};QF=Q2;++it;M*Qw;},{if(not QF){QF=a;s=f(s,*it);}M s;}) P<d T,d S,d I=R(q(Qm<T>())),d J=R(q(Qm<S>()))>k Q H+(T&&v,S&&u){Qj(I i;I i_end;J j;QJ in_i;,{M i!=O.i or j!=O.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=Q2;}}QE{++j;}M*Qw;},{M(in_i)?(*i):(*j);}) I bv=q(v);I ev=W(v);J bu=q(u);J eu=W(u);M Q4(Z{bv,ev,bu,bv!=ev},Z{ev,ev,eu,Q2});}QD X{Qk Qp=Y;P<d T>Q H()(T&&v)w{Q u=Q1<T>(v)>filter(FF(i,not is_nil(i)));Q b=q(u);Q e=W(u);Qk J=R(b);Qk V=QT<R(*b)>;Qk K=R(q(*b));X Z{J j;J Q6;Qg<V>Qq;K*QM;QJ E;Z(J j,J Q6,w V&jv,QJ E):j(j),Q6(Q6),Qq(new V(jv)),QM(new K(q(*Qq))),E(E){} Z(J j,J Q6,QJ E):j(j),Q6(Q6),Qq(nullptr),QM(nullptr),E(E){} Z(w Z&O):j(O.j),Q6(O.Q6),Qq(O.Qq),QM((O.QM)?(new K(*O.QM)):nullptr),E(O.E){} Z(Z&&O):j(O.j),Q6(O.Q6),Qq(O.Qq),QM((O.QM)?(new K(*O.QM)):nullptr),E(O.E){}~Z(){delete QM;}QJ H!=(w Z&O)w{M E xor O.E;}Z&H++(){++*QM;if(not(*QM!=W(*Qq))){++j;if(j!=Q6){delete QM;Qq=std::make_shared<V>(*j);QM=new K(q(*Qq));}QE{E=a;}} M*Qw;}R(Q)H*()w{M**QM;}};if(u>is_nil){M Qu(Z(b,e,a),Z(b,e,a));}QE{M Qu(Z(b,e,*b,Q2),Z(e,e,a));}}}flatten;P<d T,d F,d=std::enable_if_t<is_iterable_v<T>>>Q H>=(T&&v,F f){M v>Q9(f)>flatten;}P<d U,z...Is>k QJ all_different_(w U&x,w U&y,QL<Is...>){M((QQ<Is>(x)!=QQ<Is>(y))&&...);}P<d F,d...Ts>k Q zip_with(F f,Ts&&...vs){Qj(F f;L<R(q(Qm<Ts>()))...>its;,{M all_different_(its,O.its,std::index_sequence_for<Ts...>{});},{Q7([&](Q&&...xs){(++xs,...);},its);M*Qw;},{M Q7([&](Q&&...xs){M f(*xs...);},its);}) M Q4(Z{f,L(q(vs)...)},Z{f,L(W(vs)...)});};X zip_default_function_{P<d...Ts>R(Q)H()(Ts&&...xs)w{M L<Ts...>(Q1<Ts>(xs)...);}};P<d...Ts>k Q zip(Ts&&...vs){M zip_with(zip_default_function_{},Q1<Ts>(vs)...);}Qb(filter,P<d F>,(F f),<F>{f},F f;,(Z{f,W(v),q(v)}),(Z{f,W(v),W(v)}),w I end_it;k Y QB()w{while(it!=end_it and not f(*it)){++it;}},{QB();O.QB();M it!=O.it;},{QB();++it;M*Qw;},{QB();M*it;}) def_template_lambda(P<d T>,repeat,(T&&v),{X Z{w QT<T>v;QJ H!=(w Z&)w{M a;}Z&H++(){M*Qw;}w Q&H*()w{M v;}};M Q4(Z{v},Z{v});})k Q replicate(z n){M take(n)<repeat;}k Q cycle=flatten<repeat;def_iterator_manip(enumerate,{M zip(to_infinity(z(0)),v);})def_iterator_manip(reversed,{Q s=v>Q5;std::reverse(s.begin(),s.end());M iterc(Q3(s));})def_iterator_manip(sorted_by,P<d F>,(F f),<F>{f},F f;,{Q s=v>Q5;std::sort(q(s),W(s),f);M iterc(Q3(s));})def_iterator_manip(sorted,{M v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,P<d F>,(F f),<F>{f},F f;,{M v>Q9(FF(i,L(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>Q9(fst);})def_iterator_manip(nub,{Qj(I QI;I it;,{M it!=O.it;},{R(*it)pr;do{pr=*it;++it;}while(it!=QI and pr==*it);M*Qw;},{M*it;}) Q b=q(v);Q e=W(v);M Q4(Z{e,b},Z{e,e});})P<d F,d S>X accum_vector_by_{Qk Qp=Y;z n;F f;S s;P<d T,d I=R(q(Qm<T>())),d V=QT<R(*Qm<I>())>>R(Q)H()(w T&v)w{QV<QT<Qe<F,S,R(QQ<1>(Qm<V>()))>>>u(n,s);for(Q&&[i,x]:v){u[i]=f(u[i],x);}M u;}};P<d F,d S>k Q accum_vector_by(z n,F f,w S&s){M accum_vector_by_<F,S>{n,f,s};}P<d S>k Q accum_vector(z n,w S&s=S()){M accum_vector_by(n,_2,s);}P<d F,d S>X accum_map_by_{Qk Qp=Y;F f;S s;P<d T,d I=R(q(Qm<T>())),d V=QT<R(*Qm<I>())>>R(Q)H()(w T&v)w{std::map<QT<R(QQ<0>(Qm<V>()))>,QT<Qe<F,S,R(QQ<1>(Qm<V>()))>>>u;for(Q&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QE{u[i]=f(s,x);}} M u;}};P<d F,d S>k Q accum_map_by(F f,w S&s){M accum_map_by_<F,S>{f,s};}P<d S>k Q accum_map(w S&s=S()){M accum_map_by(_2,s);}P<d F,d S>X accum_unordered_map_by_{Qk Qp=Y;F f;S s;P<d T,d I=R(q(Qm<T>())),d V=QT<R(*Qm<I>())>>R(Q)H()(w T&v)w{std::unordered_map<QT<R(QQ<0>(Qm<V>()))>,QT<Qe<F,S,R(QQ<1>(Qm<V>()))>>>u;for(Q&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QE{u[i]=f(s,x);}} M u;}};P<d F,d S>k Q accum_unordered_map_by(F f,w S&s){M accum_unordered_map_by_<F,S>{f,s};}P<d S>k Q accum_unordered_map(w S&s=S()){M accum_unordered_map_by(_2,s);}P<d U,z...Is>k QJ any_different_(w U&x,w U&y,QL<Is...>){M((QQ<Is>(x)!=QQ<Is>(y))||...);}P<z N,d Z>k Y Qy(Z&it){if QD(N>=1){++QQ<N-1>(it.its);if(not(QQ<N-1>(it.its)!=W(QQ<N-1>(*it.my_vs_ptr)))){QQ<N-1>(it.its)=q(QQ<N-1>(*it.my_vs_ptr));Qy<N-1>(it);}} QE{it.its=Q7([](Q&&...xs){M L(W(xs)...);},*it.my_vs_ptr);}} P<d...Ts>Q Qt(Ts&&...vs){Q QY=std::make_shared<L<QP<Q0<Ts>,QO<Ts>,Ts>...>>(vs...);Qj(L<R(q(Qm<QP<Q0<Ts>,QO<Ts>,Ts>>()))...>its;R(QY)my_vs_ptr;,{M any_different_(its,O.its,std::index_sequence_for<Ts...>{});},{Qy<sizeof...(Ts)>(*Qw);M*Qw;},{M Q7([](Q&&...xs){M L<R(*xs)...>(*xs...);},its);}) if(Q7([](Q&&...xs){M((xs>is_nil)||...);},*QY)){M Q4(Z{Q7([](Q&&...xs){M L(W(xs)...);},*QY),QY},Z{Q7([](Q&&...xs){M L(W(xs)...);},*QY),QY});}QE{M Q4(Z{Q7([](Q&&...xs){M L(q(xs)...);},*QY),QY},Z{Q7([](Q&&...xs){M L(W(xs)...);},*QY),QY});}};P<d...Ts>k Q cartesian_product_range(w Ts&...n){M Qt(QN(n)...);}P<z n,d I>k Q cartesian_power(w I&v){M Q7([](w Q&...vs){M Qt(vs...);},tuple_many_of<n>(v));}X{Qk Qp=Y;int n=-1;P<d T>Q H()(T&&v)w{if QD(std::is_convertible_v<T,int>){Q x=*Qw;x.n=v;M x;}QE{Q vec=v>Q5;int m=vec.size();X Z{int n;R(vec)Qd;QV<z>cycles;QJ E;QJ H!=(w Z&O)w{M E xor O.E;}Z&H++(){for(Q i:QN(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=Qd.size()-i;std::rotate(Qd.begin()+i,Qd.begin()+i+1,Qd.end());}QE{std::swap(Qd[i],Qd[Qd.size()-cycles[i]]);M*Qw;}} E=a;M*Qw;}Q H*()w{M Qd>array_slice(0,n);}};int n1=(n<0)?(m):(n);M Q4(Z{n1,Q3(vec),QN(m,m-n1,-1)>Q9(FF(x,z(x)))>Q5,Q2},Z{n1,{},{},a});}}}permutations;X combinations_impl{Qk Qp=Y;int n;P<d T>Q H()(T&&v)w{Q vec=v>Q5;int m=vec.size();Qj(int n;R(vec)Qd;QV<z>idx;QJ E;,{M E xor O.E;},{for(Q i:QN(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(Q j:QN(i+1,n)){idx[j]=idx[j-1]+1;}M*Qw;}} E=a;M*Qw;},{M idx>array_slice(0,n)>Q9(FF(i,Qd[i]));}) M Q4(Z{n,Q3(vec),QN(0,m)>Q9(FF(x,z(x)))>Q5,Q2},Z{n,{},{},a});}};k Q combinations(int n){M combinations_impl{n};}X Qo{Qk Qp=Y;int n;P<d T>Q H()(T&&v)w{Q vec=v>Q5;int m=vec.size();Qj(int n;R(vec)Qd;QV<z>idx;QJ E;,{M E xor O.E;},{for(Q i:QN(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(Q j:QN(i+1,n)){idx[j]=idx[i];}M*Qw;}} E=a;M*Qw;},{M idx>array_slice(0,n)>Q9(FF(i,Qd[i]));}) M Q4(Z{n,Q3(vec),z(0)>replicate(m)>Q5,Q2},Z{n,{},{},a});}};k Q combinations_with_replacement(int n){M Qo{n};}P<d T>k Q istream_iterable(std::istream&in){Qj(std::istream&in;Qc T val;QJ E;Qc QJ has_read;,{M E xor O.E;},{if(not(in>>val)){E=a;}M*Qw;},{if(not has_read){has_read=a;in>>val;}M val;}) M Q4(Z{in,T{},Q2,Q2},Z{in,T{},a,a});}P<d T>k Q input=istream_iterable<T>(std::cin);P<d T>Qi&print_iterable(Qi&out,w T&v,w std::string&sep= " "){for(Q it=q(v);it!=W(v);){ out<<*it;++it;if(it!=W(v)){out<<sep;}QE{M out;}} M out;}P<d T,d=d T::is_iterable_wrapper>k Qi&H<<(Qi&out,w T&v){out<< "[";M print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)P<d...Ts>Qi&H<<(Qi&out,w I<Ts...>&v){M out<<Q4(v);}
QU(QV)QU(std::map)QU(std::unordered_map)QU(std::set)QU(std::unordered_set)P<z n,d T>X QS{Qk type=QV<d QS<n-1,T>::type>;static Q make(w Ql<n,z>&sz,w T&val=T()){M QV(QH(sz),QS<n-1,T>::make(Qa(sz),val));}};P<d T>X QS<1,T>{Qk type=QV<T>;static Q make(w L<z>&sz,w T&val=T()){M QV(QH(sz),val);}};P<z n,d T>Qk nested_vector=d QS<n,T>::type;P<z n,d T>Q make_nested_vector(w Ql<n,z>&sz,w T&val=T()){M QS<n,T>::make(sz,val);}P<z n,d T>k Q QA(w T&v){if QD(n==1){M L(v.size());}QE{M std::tuple_cat(L(v.size()),QA<n-1>(v[0]));}} P<z n,d T>k Q nested_vector_indices(w T&v){M Q7([&](Q...x){M cartesian_product_range(x...);},QA<n>(v));}P<z n,d T>k R(Q)Qr(w QV<T>&v,w Ql<n,z>&i){if QD(n==1){M v[QH(i)];}QE{M Qr<n-1>(v[QH(i)],Qa(i));}} P<z n,d T>k R(Q)Qr(QV<T>&v,w Ql<n,z>&i){if QD(n==1){M v[QH(i)];}QE{M Qr<n-1>(v[QH(i)],Qa(i));}} P<d U,z i,z s>Qi&QK(Qi&out,w U&u){if QD(i==0){out<< "{ ";}out<<QQ<i>(u);if QD(i+1<s){out<< ", ";M QK<U,i+1,s>(out,u);}QE{M out<< " }";}} P<d...Ts>Qi&H<<(Qi&out,w L<Ts...>&u){M QK<R(u),0,sizeof...(Ts)>(out,u);}P<d T,d S>Qi&H<<(Qi&out,w std::pair<T,S>&p){M out<<L(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(Q2);std::cin.tie(0);std::cout.tie(0);
#define END }
Qk namespace std;Qk LL=long long;Y solve(){string S;cin>>S;vector<int>ans;string A;vector<int>B;vector<vector<int>>C;for(int n:QN(S.length())){if(A.empty()or S[n]!=A.back()){A.Qn(S[n]);B.Qn(1);C.Qn({n});}QE{B.back()++;C.back().Qn(n);}} for(int i=0;i<int(A.length());++i){if(A.substr(i,5)== "twone" and B[i+1]==1 and B[i+2]==1 and B[i+3]==1){ans.insert(ans.end(),C[i+2].begin(),C[i+2].end());i+=5-1;}QE if((A.substr(i,3)== "two" or A.substr(i,3)== "one")and B[i+1]==1){int m=i+1;ans.insert(ans.end(),C[m].begin(),C[m].end());i+=1;}} cout<<ans.size()<< "\n";for(Q i:ans){cout<<i+1<< " ";}cout<< "\n";}BEGIN int T;cin>>T;while(T--){solve();}END