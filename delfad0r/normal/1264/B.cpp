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
#define QZ nested_vector_impl
#define Qp advance
#define Q9 else
#define Qo to_nested_vector_impl
#define QO false
#define Qv is_composable
#define QU bool
#define Y using
#define Qx implicit_lambda_unary_operator
#define Qg to_vector
#define Qt std::remove_reference_t
#define QL apply
#define k __arg1__
#define A __arg2__
#define QT GET_5TH_ARG
#define QD std::move
#define Q6 std::apply
#define Qs std::vector
#define Ql nested_vector_at
#define QK tuple_many_of_t
#define H size_t
#define QH std::index_sequence
#define Qk std::tuple_element_t
#define Qc std::invoke_result_t
#define Qh it_end
#define X inline
#define Qj __arg3__
#define M is_end
#define Qr while
#define QM iterable_wrapper
#define QE def_iterator_manip_iter
#define R void
#define B struct
#define Qm std::forward
#define Z decltype
#define Q4 this
#define Qi has_updated
#define O auto
#define Q5 jv_ptr
#define QF implicit_lambda
#define Q1 implicit_lambda_binary_operator
#define QP tuple_tail
#define a Iterator
#define Qb constexpr
#define L true
#define Qw std::ostream
#define QN cartesian_product_incr_
#define d const
#define QW combinations_with_replacement_impl
#define Q_ vs_ptr
#define QA iter
#define QI cartesian_product
#define Qe __tuple__
#define QS is_composable_v
#define Qu mutable
#define QB std::decay_t
#define QV __expr1__
#define o other
#define P operator
#define Q3 nested_vector_size
#define z std::begin
#define Qz std::make_index_sequence
#define w template
#define W return
#define QG ostream_tuple_helper_
#define Qq def_iterable_ostream
#define Q2 my_v
#define Q7 std::declval
#define Q0 iterator_macro
#define E typename
#define QC tuple_head
#define Qd k_ptr
#define Q std::end
#define Qn j_end
#define q std::tuple
#define QY std::get
#define QJ container_carrying_iterator
#define QR std::is_rvalue_reference_v
#define Q8 tuple_many_of
#define QX is_composable_
#define Qa range
#define Qy std::conditional_t
#define QQ std::shared_ptr
#define Qf has_advanced

w<E T,H>Y ignore_second=T;w<H...Ix,E T>O tuple_many_of_impl(QH<Ix...>,d T&x){W q(ignore_second<T,Ix>(x)...);}w<H n,E T>O Q8(d T&x){W tuple_many_of_impl(Qz<n>{},x);}w<H n,E T>Y QK=Z(Q8<n,T>(Q7<T>()));w<E...Args>O QC(d q<Args...>&t){W QY<0>(t);}w<H...Ix,E...Args>O tuple_tail_impl(QH<Ix...>,d q<Args...>&t){W q(QY<Ix+1>(t)...);}w<E...Args>O QP(d q<Args...>&t){W tuple_tail_impl(Qz<sizeof...(Args)-1>{},t);}B empty_t{};Qb empty_t empty_v;w<E T1,E T2>std::common_type_t<T1,T2>maxx(d T1&x,d T2&y){if(x<y){W y;}Q9{W x;}} w<E T1,E T2,E...Ts>X O maxx(d T1&x,d T2&y,d Ts&...xs){W maxx(maxx(x,y),xs...);}w<E T1,E T2>O minn(d T1&x,d T2&y){if(x<=y){W x;}Q9{W y;}} w<E T1,E T2,E...Ts>X O minn(d T1&x,d T2&y,d Ts&...xs){W minn(minn(x,y),xs...);}Qb int _log2(int x){if(x==0){W 0;}W 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){W f;}
#define FF_1(k,f)[&](O&&k){(R)k;W f;}
#define FF_2(k,A,f)[&](O&&k,O&&A){(R)k;(R)A;W f;}
#define FF_3(k,A,Qj,f)[&](O&&k,O&&A,O&&Qj){(R)k;(R)A;(R)Qj;W f;}
#define FF_macro_chooser(...)QT(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->O&{W f;}
#define FREF_1(k,f)[&](O&&k)->O&{(R)k;W f;}
#define FREF_2(k,A,f)[&](O&&k,O&&A)->O&{(R)k;(R)A;W f;}
#define FREF_3(k,A,Qj,f)[&](O&&k,O&&A,O&&Qj)->O&{(R)k;(R)A;(R)Qj;W f;}
#define FREF_macro_chooser(...)QT(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){W f;}
#define FC_1(k,f,c)[&,c](O&&k){(R)k;W f;}
#define FC_2(k,A,f,c)[&,c](O&&k,O&&A){(R)k;(R)A;W f;}
#define FC_macro_chooser(...)QT(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){W f;}
#define FC2_1(k,f,c1,c2)[&,c1,c2](O&&k){(R)k;W f;}
#define FC2_2(k,A,f,c1,c2)[&,c1,c2](O&&k,O&&A){(R)k;(R)A;W f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(k,f)[&](O&&Qe){O&[k]=Qe;(R)k;W f;}
#define FT_2(k,A,f)[&](O&&Qe){O&[k,A]=Qe;(R)k;(R)A;W f;}
#define FT_3(k,A,Qj,f)[&](O&&Qe){O&[k,A,Qj]=Qe;(R)k;(R)A;(R)Qj;W f;}
#define FT_4(k,A,Qj,__arg4__,f)[&](O&&Qe){O&[k,A,Qj,__arg4__]=Qe;(R)k;(R)A;(R)Qj;(R)__arg4__;W f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(QV,f)[&](){O&&QV;W f;}()
#define LET_2(QV,__expr2__,f)[&](){O&&QV;O&&__expr2__;W f;}()
#define LET_3(QV,__expr2__,__expr3__,f)[&](){O&&QV;O&&__expr2__;O&&__expr3__;W f;}()
#define LET_macro_chooser(...)QT(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)Qb B{Y QX=R;templ X Z(O)P()args d code}name;
w<E F>class QF{private:F f;public:QF(F f_):f(f_){} w<E...Ts>Qb O P()(Ts&&...xs)d{W f(Qm<Ts>(xs)...);}};QF _([](O&&x)->Qy<QR<Z(x)>,Qt<Z(x)>,Z(x)>{W x;});QF _1([](O&&x,O&&)->Qy<QR<Z(x)>,Qt<Z(x)>,Z(x)>{W x;});QF _2([](O&&,O&&y)->Qy<QR<Z(y)>,Qt<Z(y)>,Z(y)>{W y;});
#define implicit_lambda_unary_operator(op)w<E F>Qb Z(O)P op(QF<F>f){W QF([=](O&&...xs){W op f(Qm<Z(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)w<E F,E T>Qb Z(O)P op(QF<F>f,d T&y){W QF([=](O&&...xs){W f(Qm<Z(xs)>(xs)...)op y;});}w<E F,E T>Qb Z(O)P op(d T&y,QF<F>f){W QF([=](O&&...xs){W y op f(Qm<Z(xs)>(xs)...);});}w<E F,E G>Qb Z(O)P op(QF<F>f,QF<G>g){W QF([=](O&&...xs){W f(Qm<Z(xs)>(xs)...)op g(Qm<Z(xs)>(xs)...);});}
Qx(+)Qx(-)Qx(!)Qx(~)Qx(*)Qx(&)Q1(+)Q1(-)Q1(*)Q1(/)Q1(%)Q1(<)Q1(>)Q1(<=)Q1(>=)Q1(==)Q1(!=)Q1(<<)Q1(>>)Q1(&)Q1(|)Q1(^)Q1(&&)w<E T,E=R>B Qv:public std::false_type{};w<E T>B Qv<T,std::void_t<E T::is_composable_>>:public std::true_type{};w<E T>Qb QU QS=Qv<T>::value;w<E T,E F,E=Qc<F,T>>Z(O)P>(T&&v,d F&f){W f(Qm<T>(v));}w<E M1,E M2>B composed{Y QX=R;d M1 m1;d M2 m2;w<E T>Z(O)P()(T&&v)d{W m1(m2(Qm<T>(v)));}};w<E M1,E M2,E=std::enable_if_t<QS<M1>or QS<M2>>>X O P<(d M1&m1,d M2&m2){W composed<M1,M2>{m1,m2};}w<H n>B nth_impl{Y QX=R;w<E...Ts>Qb Qk<n,q<Ts...>>&P()(q<Ts...>&u)d{W QY<n>(u);}w<E...Ts>Qb Qk<n,q<Ts...>>P()(q<Ts...>&&u)d{W QY<n>(u);}w<E...Ts>Qb d Qk<n,q<Ts...>>&P()(d q<Ts...>&u)d{W QY<n>(u);}w<E...Ts>Qb d Qk<n,q<Ts...>>P()(d q<Ts...>&&u)d{W QY<n>(u);}};w<H n>Qb nth_impl<n>nth;Qb nth_impl<0>fst;Qb nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)B a{extra QU P!=(d a&o)d neq a&P++()incr Z(O)P*()d val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,Qh,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{Q0(extra extra_it Qu I it;,neq_it,incr_it,val_it);W QM(it_begin,Qh);})
#define def_iterator_manip_2(name,code)Qb B{Y QX=R;w<E T,E I=Z(z(Q7<T>())),E V=QB<Z(*Q7<I>())>>Z(O)P()(T&&v)d code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ B name##_impl{Y QX=R;extra w<E T,E I=Z(z(Q7<T>())),E V=QB<Z(*Q7<I>())>>Z(O)P()(T&&v)d code};templ X Z(O)name args{W name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
w<E T,E=R>B is_iterable:public std::false_type{};w<E T>B is_iterable<T,std::void_t<Z(z(Q7<T>())),Z(Q(Q7<T>()))>>:public std::true_type{};w<E T>Qb QU is_iterable_v=is_iterable<T>::value;w<E I>X O QM(d I&b,d I&e){B Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
Y is_iterable_wrapper=R;Y iterator=I;Y value_type=QB<Z(*Q7<I>())>;
#pragma GCC diagnostic pop
I b,e;O begin()d{W b;}O end()d{W e;}};W Wrapper{b,e};}w<E T>X O QA(T&&iterable){W QM(z(Qm<T>(iterable)),Q(Qm<T>(iterable)));}w<E I>X O QA(d I&b,d I&e){W QM(b,e);}w<E C>B QJ:public C::iterator{QQ<C>p;QJ(QQ<C>p_,E C::iterator it):C::iterator(it),p(p_){}};w<E C>X O iterc(C&&v){Y D=QB<C>;QQ<D>p(new D(Qm<C>(v)));W QM(QJ<D>{p,z(*p)},QJ<D>{p,Q(*p)});}w<E T>X O QA(std::initializer_list<T>l){W iterc(Qs<T>(l));}def_template_lambda(w<E T>,Qg,(T&&v),{Qs<E QB<T>::value_type>s;for(O&&x:v){s.push_back(x);}W s;})w<H n>B Qo{w<E T>X static O make(T&&v){W Qm<T>(v)>QL(FF(u,Qo<n-1>::make(u)))>Qg;}};w<>B Qo<1>{w<E T>X static O make(T&&v){W Qm<T>(v)>Qg;}};w<H n>B to_nested_vector_{Y QX=R;w<E T>X Z(O)P()(T&&v)d{W Qo<n>::make(Qm<T>(v));}};w<H n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(H l,H r),({l,r}),H l;H r;,{W QA(z(v)+l,z(v)+r);})def_iterator_manip(is_nil,{W not(z(v)!=Q(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{H l=0;for(O i=z(v);i!=Q(v);++i){++l;}W l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
w<E T1,E T2,E T3,E T=std::make_signed_t<Z(T1()+T2()+T3())>>X O Qa(d T1&b,d T2&e,d T3&step){Q0(T x;T e;T step;X QU M()d{W(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{W M()xor o.M();},{x+=step;W*Q4;},{W T(x);}) W QA(a{b,e,step},a{e,e,step});}w<E T1,E T2>X O Qa(d T1&b,d T2&e){W Qa(b,e,Z(T1()+T2())(1));}w<E T>X O Qa(d T&e){W Qa(T(),e,T(1));} 
#pragma GCC diagnostic pop
w<E T>X O to_infinity(d T&b=0,d T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
Q0(T x;T step;,{(R)o;W L;},{x+=step;W*Q4;},{W T(x);}) W QA(a{b,step},a{b,step});
#pragma GCC diagnostic pop
}QE(QL,w<E F>,(F f),<F>{f},F f;,(a{f,z(v)}),(a{f,Q(v)}),,{ W it!=o.it;},{++it;W*Q4;},{W f(*it);}) QE(take,,(H n),{n},H n;,(a{n,z(v)}),(a{0,Q(v)}),,{ W n!=o.n;},{--n;if(n>0){++it;}W*Q4;},{W*it;}) QE(take_while,w<E F>,(F f),<F>{f},F f;,(a{f,not(z(v)!=Q(v)and f(*z(v))),z(v)}),(a{f,L,Q(v)}),QU M;,{W M xor o.M;},{++it;if(not f(*it)){M=L;}W*Q4;},{W*it;}) QE(drop,,(H n),{n},Qu H n;,(a{n,Q(v),z(v)}),(a{0,Q(v),Q(v)}),d I end_it;X R Qp()d{Qr(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{Qp();o.Qp();W it!=o.it;},{Qp();++it;W*Q4;},{Qp();W*it;}) QE(drop_while,w<E F>,(F f),<F>{f},F f;,(a{f,Q(v),QO,z(v)}),(a{f,Q(v),L,Q(v)}),d I end_it;Qu QU Qf;X R Qp()d{if(not Qf){Qr(it!=end_it and f(*it)){++it;}Qf=L;}},{Qp();o.Qp();W it!=o.it;},{Qp();++it;W*Q4;},{Qp();W*it;}) def_iterator_manip(head,{W*z(v);})X O tail=drop(1);X O at(H n){W head<drop(n);}QE(cons,w<E S>,(S s),<S>{s},S s;,(a{s,L,z(v)}),(a{s,QO,Q(v)}),QU is_s;,{W is_s!=o.is_s or it!=o.it;},{if(is_s){is_s=QO;}Q9{++it;}W*Q4;},{W(is_s)?(s):(*it);}) def_iterator_manip(snoc,{O it=z(v);O h=*it;++it;W q(h,QA(it,Q(v)));})def_iterator_manip(split_at,,(H n),{n},H n;,{O it=z(v);Qs<T>u;for(O i:Qa(n)){u.push_back(*it);++it;}W q(iterc(QD(u)),QA(it,Q(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
QE(chunks_of,,(H n),{n},H n;,(a{n,{},QO,Q(v),z(v)}),(a{n,{},QO,Q(v),Q(v)}),Qu Qs<V>u;Qu QU Qi;I Qh;R update()d{u.clear();Qi=L;for(O i:Qa(n)){if(it!=Qh){u.push_back(*it);++it;}Q9{break;}}},{W it!=o.it;},{if(Qi){Qi=QO;}Q9{for(O i:Qa(n)){if(it!=Qh){++it;}Q9{break;}}}W*Q4;},{if(not Qi){update();}W iterc(u);})
#pragma GCC diagnostic pop
w<E F,E S>B fold_impl{Y QX=R;F f;S s;w<E T>O P()(d T&v)d{O x=s;for(O y:v){x=f(x,y);}W x;}};w<E F,E S>X O fold(F f,d S&s){W fold_impl<F,S>{f,s};}def_iterator_manip(fold1,w<E F>,(F f),<F>{f},F f;,{O u=v>snoc;W u>snd>fold(f,u>fst);})def_iterator_manip(sum,{W v>fold(_1+_2,V(0));})def_iterator_manip(product,{W v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,w<E F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{W v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,w<E F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,w<E F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{W v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,w<E F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})w<E F,E S>B scan_impl{Y QX=R;F f;S s;w<E T,E I=Z(z(Q7<T>()))>Z(O)P()(T&&v)d{Q0(F f;Qu S s;Qu QU Qi;QU Qf;Qu I it;,{W it!=o.it;},{if(not Qi){s=f(s,*it);};Qi=QO;if(Qf){++it;}Q9{Qf=L;}W*Q4;},{if(not Qi){Qi=L;s=f(s,*it);}W s;}) W QA(a{f,s,L,QO,z(Qm<T>(v))},a{f,s,L,L,Q(Qm<T>(v))});}};w<E F,E S>X O scan(F f,d S&s){W scan_impl<F,S>{f,s};}QE(scan1,w<E F>,(F f),<F>{f},F f;,(a{f,*z(v),L,z(v)}),(a{f,*z(v),L,Q(v)}),Qu V s;Qu QU Qi;,{W it!=o.it;},{if(not Qi){s=f(s,*it);};Qi=QO;++it;W*Q4;},{if(not Qi){Qi=L;s=f(s,*it);}W s;}) w<E T,E S,E I=Z(z(Q7<T>())),E J=Z(z(Q7<S>()))>X O P+(T&&v,S&&u){Q0(I i;I i_end;J j;QU in_i;,{W i!=o.i or j!=o.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=QO;}}Q9{++j;}W*Q4;},{W(in_i)?(*i):(*j);}) I bv=z(v);I ev=Q(v);J bu=z(u);J eu=Q(u);W QA(a{bv,ev,bu,bv!=ev},a{ev,ev,eu,QO});}Qb B{Y QX=R;w<E T>O P()(T&&v)d{O u=Qm<T>(v)>filter(FF(i,not is_nil(i)));O b=z(u);O e=Q(u);Y J=Z(b);Y V=QB<Z(*b)>;Y K=Z(z(*b));B a{J j;J Qn;QQ<V>Q5;K*Qd;QU M;a(J j,J Qn,d V&jv,QU M):j(j),Qn(Qn),Q5(new V(jv)),Qd(new K(z(*Q5))),M(M){} a(J j,J Qn,QU M):j(j),Qn(Qn),Q5(nullptr),Qd(nullptr),M(M){} a(d a&o):j(o.j),Qn(o.Qn),Q5(o.Q5),Qd((o.Qd)?(new K(*o.Qd)):nullptr),M(o.M){} a(a&&o):j(o.j),Qn(o.Qn),Q5(o.Q5),Qd((o.Qd)?(new K(*o.Qd)):nullptr),M(o.M){}~a(){delete Qd;}QU P!=(d a&o)d{W M xor o.M;}a&P++(){++*Qd;if(not(*Qd!=Q(*Q5))){++j;if(j!=Qn){delete Qd;Q5=std::make_shared<V>(*j);Qd=new K(z(*Q5));}Q9{M=L;}} W*Q4;}Z(O)P*()d{W**Qd;}};if(u>is_nil){W QM(a(b,e,L),a(b,e,L));}Q9{W QM(a(b,e,*b,QO),a(e,e,L));}}}flatten;w<E T,E F,E=std::enable_if_t<is_iterable_v<T>>>O P>=(T&&v,F f){W v>QL(f)>flatten;}w<E U,H...Is>X QU all_different_(d U&x,d U&y,QH<Is...>){W((QY<Is>(x)!=QY<Is>(y))&&...);}w<E F,E...Ts>X O zip_with(F f,Ts&&...vs){Q0(F f;q<Z(z(Q7<Ts>()))...>its;,{W all_different_(its,o.its,std::index_sequence_for<Ts...>{});},{Q6([&](O&&...xs){(++xs,...);},its);W*Q4;},{W Q6([&](O&&...xs){W f(*xs...);},its);}) W QA(a{f,q(z(vs)...)},a{f,q(Q(vs)...)});};B zip_default_function_{w<E...Ts>Z(O)P()(Ts&&...xs)d{W q<Ts...>(Qm<Ts>(xs)...);}};w<E...Ts>X O zip(Ts&&...vs){W zip_with(zip_default_function_{},Qm<Ts>(vs)...);}QE(filter,w<E F>,(F f),<F>{f},F f;,(a{f,Q(v),z(v)}),(a{f,Q(v),Q(v)}),d I end_it;X R Qp()d{Qr(it!=end_it and not f(*it)){++it;}},{Qp();o.Qp();W it!=o.it;},{Qp();++it;W*Q4;},{Qp();W*it;}) def_template_lambda(w<E T>,repeat,(T&&v),{B a{d QB<T>v;QU P!=(d a&)d{W L;}a&P++(){W*Q4;}d O&P*()d{W v;}};W QA(a{v},a{v});})X O replicate(H n){W take(n)<repeat;}X O cycle=flatten<repeat;def_iterator_manip(enumerate,{W zip(to_infinity(H(0)),v);})def_iterator_manip(reversed,{O s=v>Qg;std::reverse(s.begin(),s.end());W iterc(QD(s));})def_iterator_manip(sorted_by,w<E F>,(F f),<F>{f},F f;,{O s=v>Qg;std::sort(z(s),Q(s),f);W iterc(QD(s));})def_iterator_manip(sorted,{W v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,w<E F>,(F f),<F>{f},F f;,{W v>QL(FF(i,q(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>QL(fst);})def_iterator_manip(nub,{Q0(I Qh;I it;,{W it!=o.it;},{Z(*it)pr;do{pr=*it;++it;}Qr(it!=Qh and pr==*it);W*Q4;},{W*it;}) O b=z(v);O e=Q(v);W QA(a{e,b},a{e,e});})w<E F,E S>B accum_vector_by_{Y QX=R;H n;F f;S s;w<E T,E I=Z(z(Q7<T>())),E V=QB<Z(*Q7<I>())>>Z(O)P()(d T&v)d{Qs<QB<Qc<F,S,Z(QY<1>(Q7<V>()))>>>u(n,s);for(O&&[i,x]:v){u[i]=f(u[i],x);}W u;}};w<E F,E S>X O accum_vector_by(H n,F f,d S&s){W accum_vector_by_<F,S>{n,f,s};}w<E S>X O accum_vector(H n,d S&s=S()){W accum_vector_by(n,_2,s);}w<E F,E S>B accum_map_by_{Y QX=R;F f;S s;w<E T,E I=Z(z(Q7<T>())),E V=QB<Z(*Q7<I>())>>Z(O)P()(d T&v)d{std::map<QB<Z(QY<0>(Q7<V>()))>,QB<Qc<F,S,Z(QY<1>(Q7<V>()))>>>u;for(O&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Q9{u[i]=f(s,x);}} W u;}};w<E F,E S>X O accum_map_by(F f,d S&s){W accum_map_by_<F,S>{f,s};}w<E S>X O accum_map(d S&s=S()){W accum_map_by(_2,s);}w<E F,E S>B accum_unordered_map_by_{Y QX=R;F f;S s;w<E T,E I=Z(z(Q7<T>())),E V=QB<Z(*Q7<I>())>>Z(O)P()(d T&v)d{std::unordered_map<QB<Z(QY<0>(Q7<V>()))>,QB<Qc<F,S,Z(QY<1>(Q7<V>()))>>>u;for(O&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Q9{u[i]=f(s,x);}} W u;}};w<E F,E S>X O accum_unordered_map_by(F f,d S&s){W accum_unordered_map_by_<F,S>{f,s};}w<E S>X O accum_unordered_map(d S&s=S()){W accum_unordered_map_by(_2,s);}w<E U,H...Is>X QU any_different_(d U&x,d U&y,QH<Is...>){W((QY<Is>(x)!=QY<Is>(y))||...);}w<H N,E a>X R QN(a&it){if Qb(N>=1){++QY<N-1>(it.its);if(not(QY<N-1>(it.its)!=Q(QY<N-1>(*it.my_vs_ptr)))){QY<N-1>(it.its)=z(QY<N-1>(*it.my_vs_ptr));QN<N-1>(it);}} Q9{it.its=Q6([](O&&...xs){W q(Q(xs)...);},*it.my_vs_ptr);}} w<E...Ts>O QI(Ts&&...vs){O Q_=std::make_shared<q<Qy<QR<Ts>,Qt<Ts>,Ts>...>>(vs...);Q0(q<Z(z(Q7<Qy<QR<Ts>,Qt<Ts>,Ts>>()))...>its;Z(Q_)my_vs_ptr;,{W any_different_(its,o.its,std::index_sequence_for<Ts...>{});},{QN<sizeof...(Ts)>(*Q4);W*Q4;},{W Q6([](O&&...xs){W q<Z(*xs)...>(*xs...);},its);}) if(Q6([](O&&...xs){W((xs>is_nil)||...);},*Q_)){W QA(a{Q6([](O&&...xs){W q(Q(xs)...);},*Q_),Q_},a{Q6([](O&&...xs){W q(Q(xs)...);},*Q_),Q_});}Q9{W QA(a{Q6([](O&&...xs){W q(z(xs)...);},*Q_),Q_},a{Q6([](O&&...xs){W q(Q(xs)...);},*Q_),Q_});}};w<E...Ts>X O cartesian_product_range(d Ts&...n){W QI(Qa(n)...);}w<H n,E I>X O cartesian_power(d I&v){W Q6([](d O&...vs){W QI(vs...);},Q8<n>(v));}B{Y QX=R;int n=-1;w<E T>O P()(T&&v)d{if Qb(std::is_convertible_v<T,int>){O x=*Q4;x.n=v;W x;}Q9{O vec=v>Qg;int m=vec.size();B a{int n;Z(vec)Q2;Qs<H>cycles;QU M;QU P!=(d a&o)d{W M xor o.M;}a&P++(){for(O i:Qa(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=Q2.size()-i;std::rotate(Q2.begin()+i,Q2.begin()+i+1,Q2.end());}Q9{std::swap(Q2[i],Q2[Q2.size()-cycles[i]]);W*Q4;}} M=L;W*Q4;}O P*()d{W Q2>array_slice(0,n);}};int n1=(n<0)?(m):(n);W QA(a{n1,QD(vec),Qa(m,m-n1,-1)>QL(FF(x,H(x)))>Qg,QO},a{n1,{},{},L});}}}permutations;B combinations_impl{Y QX=R;int n;w<E T>O P()(T&&v)d{O vec=v>Qg;int m=vec.size();Q0(int n;Z(vec)Q2;Qs<H>idx;QU M;,{W M xor o.M;},{for(O i:Qa(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(O j:Qa(i+1,n)){idx[j]=idx[j-1]+1;}W*Q4;}} M=L;W*Q4;},{W idx>array_slice(0,n)>QL(FF(i,Q2[i]));}) W QA(a{n,QD(vec),Qa(0,m)>QL(FF(x,H(x)))>Qg,QO},a{n,{},{},L});}};X O combinations(int n){W combinations_impl{n};}B QW{Y QX=R;int n;w<E T>O P()(T&&v)d{O vec=v>Qg;int m=vec.size();Q0(int n;Z(vec)Q2;Qs<H>idx;QU M;,{W M xor o.M;},{for(O i:Qa(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(O j:Qa(i+1,n)){idx[j]=idx[i];}W*Q4;}} M=L;W*Q4;},{W idx>array_slice(0,n)>QL(FF(i,Q2[i]));}) W QA(a{n,QD(vec),H(0)>replicate(m)>Qg,QO},a{n,{},{},L});}};X O combinations_with_replacement(int n){W QW{n};}w<E T>X O istream_iterable(std::istream&in){Q0(std::istream&in;Qu T val;QU M;Qu QU has_read;,{W M xor o.M;},{if(not(in>>val)){M=L;}W*Q4;},{if(not has_read){has_read=L;in>>val;}W val;}) W QA(a{in,T{},QO,QO},a{in,T{},L,L});}w<E T>X O input=istream_iterable<T>(std::cin);w<E T>Qw&print_iterable(Qw&out,d T&v,d std::string&sep= " "){for(O it=z(v);it!=Q(v);){ out<<*it;++it;if(it!=Q(v)){out<<sep;}Q9{W out;}} W out;}w<E T,E=E T::is_iterable_wrapper>X Qw&P<<(Qw&out,d T&v){out<< "[";W print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)w<E...Ts>Qw&P<<(Qw&out,d I<Ts...>&v){W out<<QA(v);}
Qq(Qs)Qq(std::map)Qq(std::unordered_map)Qq(std::set)Qq(std::unordered_set)w<H n,E T>B QZ{Y type=Qs<E QZ<n-1,T>::type>;static O make(d QK<n,H>&sz,d T&val=T()){W Qs(QC(sz),QZ<n-1,T>::make(QP(sz),val));}};w<E T>B QZ<1,T>{Y type=Qs<T>;static O make(d q<H>&sz,d T&val=T()){W Qs(QC(sz),val);}};w<H n,E T>Y nested_vector=E QZ<n,T>::type;w<H n,E T>O make_nested_vector(d QK<n,H>&sz,d T&val=T()){W QZ<n,T>::make(sz,val);}w<H n,E T>X O Q3(d T&v){if Qb(n==1){W q(v.size());}Q9{W std::tuple_cat(q(v.size()),Q3<n-1>(v[0]));}} w<H n,E T>X O nested_vector_indices(d T&v){W Q6([&](O...x){W cartesian_product_range(x...);},Q3<n>(v));}w<H n,E T>X Z(O)Ql(d Qs<T>&v,d QK<n,H>&i){if Qb(n==1){W v[QC(i)];}Q9{W Ql<n-1>(v[QC(i)],QP(i));}} w<H n,E T>X Z(O)Ql(Qs<T>&v,d QK<n,H>&i){if Qb(n==1){W v[QC(i)];}Q9{W Ql<n-1>(v[QC(i)],QP(i));}} w<E U,H i,H s>Qw&QG(Qw&out,d U&u){if Qb(i==0){out<< "{ ";}out<<QY<i>(u);if Qb(i+1<s){out<< ", ";W QG<U,i+1,s>(out,u);}Q9{W out<< " }";}} w<E...Ts>Qw&P<<(Qw&out,d q<Ts...>&u){W QG<Z(u),0,sizeof...(Ts)>(out,u);}w<E T,E S>Qw&P<<(Qw&out,d std::pair<T,S>&p){W out<<q(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(QO);std::cin.tie(0);std::cout.tie(0);
#define END }
Y namespace std;Y LL=long long;BEGIN O x=input<int>>take(4)>Qg;vector<int>S;O no=[](){cout<< "NO\n";exit(0);};O add=[&](int i){--x[i];if(x[i]<0){no();}S.push_back(i);};if(x[2]+x[3]==0){if(x[0]>x[1]){add(0);}Qr(x[0]>0){add(1);add(0);}if(x[1]>0){add(1);}if(x[1]>0){no();}} Q9 if(x[0]+x[1]==0){if(x[2]>x[3]){add(2);}Qr(x[2]>0){add(3);add(2);}if(x[3]>0){add(3);}if(x[3]>0){no();}} Q9{if(x[0]+x[2]<x[1]+x[3]){add(1);}Qr(x[0]>0){add(0);add(1);}Qr(x[3]>0){add(2);add(3);}Qr(x[1]>0){add(2);add(1);}if(x[2]>0){add(2);}if(x[2]>0){no();}} cout<< "YES\n";for(O i:S){cout<<i<< " ";}cout<< "\n";END