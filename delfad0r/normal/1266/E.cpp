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
#define H std::tuple
#define QT def_iterable_ostream
#define Q6 implicit_lambda_binary_operator
#define q __arg1__
#define QD std::get
#define O std::end
#define QB std::invoke_result_t
#define Qt int
#define Qk std::decay_t
#define L is_end
#define Qr implicit_lambda
#define QG __arg3__
#define QF std::vector
#define Qa std::declval
#define Qi GET_5TH_ARG
#define Y typename
#define Ql combinations_with_replacement_impl
#define Qz j_end
#define Qo std::remove_reference_t
#define QY ostream_tuple_helper_
#define QE std::conditional_t
#define QZ def_iterator_manip_iter
#define Qj iterable_wrapper
#define Qu std::index_sequence
#define Qp implicit_lambda_unary_operator
#define a void
#define QC iterator_macro
#define QW std::tuple_element_t
#define Qh nested_vector_impl
#define P inline
#define QQ std::apply
#define Qm has_advanced
#define z decltype
#define Q0 __expr1__
#define QX constexpr
#define Q8 std::is_rvalue_reference_v
#define Qw __arg2__
#define QO using
#define Qg tuple_many_of_t
#define QI else
#define QR true
#define Qq nested_vector_at
#define Qv nested_vector_size
#define Qb is_composable_
#define Q3 __tuple__
#define Qf to_nested_vector_impl
#define k size_t
#define QU vs_ptr
#define QH struct
#define Q2 cartesian_product
#define Qy range
#define QS std::forward
#define o other
#define QA mutable
#define Qc k_ptr
#define R operator
#define QL container_carrying_iterator
#define Qd false
#define Q4 this
#define Qs to_vector
#define Q7 std::move
#define QK advance
#define Q5 is_composable_v
#define Q1 jv_ptr
#define Qx std::shared_ptr
#define E template
#define QP has_updated
#define Q9 iter
#define Z const
#define QV cartesian_product_incr_
#define w std::begin
#define W return
#define X Iterator
#define d auto
#define Qe std::ostream
#define QJ bool
#define Qn tuple_head

E<Y T,k>QO ignore_second=T;E<k...Ix,Y T>d tuple_many_of_impl(Qu<Ix...>,Z T&x){W H(ignore_second<T,Ix>(x)...);}E<k n,Y T>d tuple_many_of(Z T&x){W tuple_many_of_impl(std::make_index_sequence<n>{},x);}E<k n,Y T>QO Qg=z(tuple_many_of<n,T>(Qa<T>()));E<Y...Args>d Qn(Z H<Args...>&t){W QD<0>(t);}E<k...Ix,Y...Args>d tuple_tail_impl(Qu<Ix...>,Z H<Args...>&t){W H(QD<Ix+1>(t)...);}E<Y...Args>d tuple_tail(Z H<Args...>&t){W tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}QH empty_t{};QX empty_t empty_v;E<Y T1,Y T2>std::common_type_t<T1,T2>maxx(Z T1&x,Z T2&y){if(x<y){W y;}QI{W x;}} E<Y T1,Y T2,Y...Ts>P d maxx(Z T1&x,Z T2&y,Z Ts&...xs){W maxx(maxx(x,y),xs...);}E<Y T1,Y T2>d minn(Z T1&x,Z T2&y){if(x<=y){W x;}QI{W y;}} E<Y T1,Y T2,Y...Ts>P d minn(Z T1&x,Z T2&y,Z Ts&...xs){W minn(minn(x,y),xs...);}QX Qt _log2(Qt x){if(x==0){W 0;}W 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){W f;}
#define FF_1(q,f)[&](d&&q){(a)q;W f;}
#define FF_2(q,Qw,f)[&](d&&q,d&&Qw){(a)q;(a)Qw;W f;}
#define FF_3(q,Qw,QG,f)[&](d&&q,d&&Qw,d&&QG){(a)q;(a)Qw;(a)QG;W f;}
#define FF_macro_chooser(...)Qi(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->d&{W f;}
#define FREF_1(q,f)[&](d&&q)->d&{(a)q;W f;}
#define FREF_2(q,Qw,f)[&](d&&q,d&&Qw)->d&{(a)q;(a)Qw;W f;}
#define FREF_3(q,Qw,QG,f)[&](d&&q,d&&Qw,d&&QG)->d&{(a)q;(a)Qw;(a)QG;W f;}
#define FREF_macro_chooser(...)Qi(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){W f;}
#define FC_1(q,f,c)[&,c](d&&q){(a)q;W f;}
#define FC_2(q,Qw,f,c)[&,c](d&&q,d&&Qw){(a)q;(a)Qw;W f;}
#define FC_macro_chooser(...)Qi(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){W f;}
#define FC2_1(q,f,c1,c2)[&,c1,c2](d&&q){(a)q;W f;}
#define FC2_2(q,Qw,f,c1,c2)[&,c1,c2](d&&q,d&&Qw){(a)q;(a)Qw;W f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(q,f)[&](d&&Q3){d&[q]=Q3;(a)q;W f;}
#define FT_2(q,Qw,f)[&](d&&Q3){d&[q,Qw]=Q3;(a)q;(a)Qw;W f;}
#define FT_3(q,Qw,QG,f)[&](d&&Q3){d&[q,Qw,QG]=Q3;(a)q;(a)Qw;(a)QG;W f;}
#define FT_4(q,Qw,QG,__arg4__,f)[&](d&&Q3){d&[q,Qw,QG,__arg4__]=Q3;(a)q;(a)Qw;(a)QG;(a)__arg4__;W f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Q0,f)[&](){d&&Q0;W f;}()
#define LET_2(Q0,__expr2__,f)[&](){d&&Q0;d&&__expr2__;W f;}()
#define LET_3(Q0,__expr2__,__expr3__,f)[&](){d&&Q0;d&&__expr2__;d&&__expr3__;W f;}()
#define LET_macro_chooser(...)Qi(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)QX QH{QO Qb=a;templ P z(d)R()args Z code}name;
E<Y F>class Qr{private:F f;public:Qr(F f_):f(f_){} E<Y...Ts>QX d R()(Ts&&...xs)Z{W f(QS<Ts>(xs)...);}};Qr _([](d&&x)->QE<Q8<z(x)>,Qo<z(x)>,z(x)>{W x;});Qr _1([](d&&x,d&&)->QE<Q8<z(x)>,Qo<z(x)>,z(x)>{W x;});Qr _2([](d&&,d&&y)->QE<Q8<z(y)>,Qo<z(y)>,z(y)>{W y;});
#define implicit_lambda_unary_operator(op)E<Y F>QX z(d)R op(Qr<F>f){W Qr([=](d&&...xs){W op f(QS<z(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)E<Y F,Y T>QX z(d)R op(Qr<F>f,Z T&y){W Qr([=](d&&...xs){W f(QS<z(xs)>(xs)...)op y;});}E<Y F,Y T>QX z(d)R op(Z T&y,Qr<F>f){W Qr([=](d&&...xs){W y op f(QS<z(xs)>(xs)...);});}E<Y F,Y G>QX z(d)R op(Qr<F>f,Qr<G>g){W Qr([=](d&&...xs){W f(QS<z(xs)>(xs)...)op g(QS<z(xs)>(xs)...);});}
Qp(+)Qp(-)Qp(!)Qp(~)Qp(*)Qp(&)Q6(+)Q6(-)Q6(*)Q6(/)Q6(%)Q6(<)Q6(>)Q6(<=)Q6(>=)Q6(==)Q6(!=)Q6(<<)Q6(>>)Q6(&)Q6(|)Q6(^)Q6(&&)E<Y T,Y=a>QH is_composable:public std::false_type{};E<Y T>QH is_composable<T,std::void_t<Y T::is_composable_>>:public std::true_type{};E<Y T>QX QJ Q5=is_composable<T>::value;E<Y T,Y F,Y=QB<F,T>>z(d)R>(T&&v,Z F&f){W f(QS<T>(v));}E<Y M1,Y M2>QH composed{QO Qb=a;Z M1 m1;Z M2 m2;E<Y T>z(d)R()(T&&v)Z{W m1(m2(QS<T>(v)));}};E<Y M1,Y M2,Y=std::enable_if_t<Q5<M1>or Q5<M2>>>P d R<(Z M1&m1,Z M2&m2){W composed<M1,M2>{m1,m2};}E<k n>QH nth_impl{QO Qb=a;E<Y...Ts>QX QW<n,H<Ts...>>&R()(H<Ts...>&u)Z{W QD<n>(u);}E<Y...Ts>QX QW<n,H<Ts...>>R()(H<Ts...>&&u)Z{W QD<n>(u);}E<Y...Ts>QX Z QW<n,H<Ts...>>&R()(Z H<Ts...>&u)Z{W QD<n>(u);}E<Y...Ts>QX Z QW<n,H<Ts...>>R()(Z H<Ts...>&&u)Z{W QD<n>(u);}};E<k n>QX nth_impl<n>nth;QX nth_impl<0>fst;QX nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)QH X{extra QJ R!=(Z X&o)Z neq X&R++()incr z(d)R*()Z val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,it_end,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{QC(extra extra_it QA I it;,neq_it,incr_it,val_it);W Qj(it_begin,it_end);})
#define def_iterator_manip_2(name,code)QX QH{QO Qb=a;E<Y T,Y I=z(w(Qa<T>())),Y V=Qk<z(*Qa<I>())>>z(d)R()(T&&v)Z code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ QH name##_impl{QO Qb=a;extra E<Y T,Y I=z(w(Qa<T>())),Y V=Qk<z(*Qa<I>())>>z(d)R()(T&&v)Z code};templ P z(d)name args{W name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
E<Y T,Y=a>QH is_iterable:public std::false_type{};E<Y T>QH is_iterable<T,std::void_t<z(w(Qa<T>())),z(O(Qa<T>()))>>:public std::true_type{};E<Y T>QX QJ is_iterable_v=is_iterable<T>::value;E<Y I>P d Qj(Z I&b,Z I&e){QH Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
QO is_iterable_wrapper=a;QO iterator=I;QO value_type=Qk<z(*Qa<I>())>;
#pragma GCC diagnostic pop
I b,e;d begin()Z{W b;}d end()Z{W e;}};W Wrapper{b,e};}E<Y T>P d Q9(T&&iterable){W Qj(w(QS<T>(iterable)),O(QS<T>(iterable)));}E<Y I>P d Q9(Z I&b,Z I&e){W Qj(b,e);}E<Y C>QH QL:public C::iterator{Qx<C>p;QL(Qx<C>p_,Y C::iterator it):C::iterator(it),p(p_){}};E<Y C>P d iterc(C&&v){QO D=Qk<C>;Qx<D>p(new D(QS<C>(v)));W Qj(QL<D>{p,w(*p)},QL<D>{p,O(*p)});}E<Y T>P d Q9(std::initializer_list<T>l){W iterc(QF<T>(l));}def_template_lambda(E<Y T>,Qs,(T&&v),{QF<Y Qk<T>::value_type>s;for(d&&x:v){s.push_back(x);}W s;})E<k n>QH Qf{E<Y T>P static d make(T&&v){W QS<T>(v)>apply(FF(u,Qf<n-1>::make(u)))>Qs;}};E<>QH Qf<1>{E<Y T>P static d make(T&&v){W QS<T>(v)>Qs;}};E<k n>QH to_nested_vector_{QO Qb=a;E<Y T>P z(d)R()(T&&v)Z{W Qf<n>::make(QS<T>(v));}};E<k n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(k l,k r),({l,r}),k l;k r;,{W Q9(w(v)+l,w(v)+r);})def_iterator_manip(is_nil,{W not(w(v)!=O(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{k l=0;for(d i=w(v);i!=O(v);++i){++l;}W l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
E<Y T1,Y T2,Y T3,Y T=std::make_signed_t<z(T1()+T2()+T3())>>P d Qy(Z T1&b,Z T2&e,Z T3&step){QC(T x;T e;T step;P QJ L()Z{W(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{W L()xor o.L();},{x+=step;W*Q4;},{W T(x);}) W Q9(X{b,e,step},X{e,e,step});}E<Y T1,Y T2>P d Qy(Z T1&b,Z T2&e){W Qy(b,e,z(T1()+T2())(1));}E<Y T>P d Qy(Z T&e){W Qy(T(),e,T(1));} 
#pragma GCC diagnostic pop
E<Y T>P d to_infinity(Z T&b=0,Z T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
QC(T x;T step;,{(a)o;W QR;},{x+=step;W*Q4;},{W T(x);}) W Q9(X{b,step},X{b,step});
#pragma GCC diagnostic pop
}QZ(apply,E<Y F>,(F f),<F>{f},F f;,(X{f,w(v)}),(X{f,O(v)}),,{ W it!=o.it;},{++it;W*Q4;},{W f(*it);}) QZ(take,,(k n),{n},k n;,(X{n,w(v)}),(X{0,O(v)}),,{ W n!=o.n;},{--n;if(n>0){++it;}W*Q4;},{W*it;}) QZ(take_while,E<Y F>,(F f),<F>{f},F f;,(X{f,not(w(v)!=O(v)and f(*w(v))),w(v)}),(X{f,QR,O(v)}),QJ L;,{W L xor o.L;},{++it;if(not f(*it)){L=QR;}W*Q4;},{W*it;}) QZ(drop,,(k n),{n},QA k n;,(X{n,O(v),w(v)}),(X{0,O(v),O(v)}),Z I end_it;P a QK()Z{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{QK();o.QK();W it!=o.it;},{QK();++it;W*Q4;},{QK();W*it;}) QZ(drop_while,E<Y F>,(F f),<F>{f},F f;,(X{f,O(v),Qd,w(v)}),(X{f,O(v),QR,O(v)}),Z I end_it;QA QJ Qm;P a QK()Z{if(not Qm){while(it!=end_it and f(*it)){++it;}Qm=QR;}},{QK();o.QK();W it!=o.it;},{QK();++it;W*Q4;},{QK();W*it;}) def_iterator_manip(head,{W*w(v);})P d tail=drop(1);P d at(k n){W head<drop(n);}QZ(cons,E<Y S>,(S s),<S>{s},S s;,(X{s,QR,w(v)}),(X{s,Qd,O(v)}),QJ is_s;,{W is_s!=o.is_s or it!=o.it;},{if(is_s){is_s=Qd;}QI{++it;}W*Q4;},{W(is_s)?(s):(*it);}) def_iterator_manip(snoc,{d it=w(v);d h=*it;++it;W H(h,Q9(it,O(v)));})def_iterator_manip(split_at,,(k n),{n},k n;,{d it=w(v);QF<T>u;for(d i:Qy(n)){u.push_back(*it);++it;}W H(iterc(Q7(u)),Q9(it,O(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
QZ(chunks_of,,(k n),{n},k n;,(X{n,{},Qd,O(v),w(v)}),(X{n,{},Qd,O(v),O(v)}),QA QF<V>u;QA QJ QP;I it_end;a update()Z{u.clear();QP=QR;for(d i:Qy(n)){if(it!=it_end){u.push_back(*it);++it;}QI{break;}}},{W it!=o.it;},{if(QP){QP=Qd;}QI{for(d i:Qy(n)){if(it!=it_end){++it;}QI{break;}}}W*Q4;},{if(not QP){update();}W iterc(u);})
#pragma GCC diagnostic pop
E<Y F,Y S>QH fold_impl{QO Qb=a;F f;S s;E<Y T>d R()(Z T&v)Z{d x=s;for(d y:v){x=f(x,y);}W x;}};E<Y F,Y S>P d fold(F f,Z S&s){W fold_impl<F,S>{f,s};}def_iterator_manip(fold1,E<Y F>,(F f),<F>{f},F f;,{d u=v>snoc;W u>snd>fold(f,u>fst);})def_iterator_manip(sum,{W v>fold(_1+_2,V(0));})def_iterator_manip(product,{W v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,E<Y F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{W v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,E<Y F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,E<Y F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{W v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,E<Y F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})E<Y F,Y S>QH scan_impl{QO Qb=a;F f;S s;E<Y T,Y I=z(w(Qa<T>()))>z(d)R()(T&&v)Z{QC(F f;QA S s;QA QJ QP;QJ Qm;QA I it;,{W it!=o.it;},{if(not QP){s=f(s,*it);};QP=Qd;if(Qm){++it;}QI{Qm=QR;}W*Q4;},{if(not QP){QP=QR;s=f(s,*it);}W s;}) W Q9(X{f,s,QR,Qd,w(QS<T>(v))},X{f,s,QR,QR,O(QS<T>(v))});}};E<Y F,Y S>P d scan(F f,Z S&s){W scan_impl<F,S>{f,s};}QZ(scan1,E<Y F>,(F f),<F>{f},F f;,(X{f,*w(v),QR,w(v)}),(X{f,*w(v),QR,O(v)}),QA V s;QA QJ QP;,{W it!=o.it;},{if(not QP){s=f(s,*it);};QP=Qd;++it;W*Q4;},{if(not QP){QP=QR;s=f(s,*it);}W s;}) E<Y T,Y S,Y I=z(w(Qa<T>())),Y J=z(w(Qa<S>()))>P d R+(T&&v,S&&u){QC(I i;I i_end;J j;QJ in_i;,{W i!=o.i or j!=o.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=Qd;}}QI{++j;}W*Q4;},{W(in_i)?(*i):(*j);}) I bv=w(v);I ev=O(v);J bu=w(u);J eu=O(u);W Q9(X{bv,ev,bu,bv!=ev},X{ev,ev,eu,Qd});}QX QH{QO Qb=a;E<Y T>d R()(T&&v)Z{d u=QS<T>(v)>filter(FF(i,not is_nil(i)));d b=w(u);d e=O(u);QO J=z(b);QO V=Qk<z(*b)>;QO K=z(w(*b));QH X{J j;J Qz;Qx<V>Q1;K*Qc;QJ L;X(J j,J Qz,Z V&jv,QJ L):j(j),Qz(Qz),Q1(new V(jv)),Qc(new K(w(*Q1))),L(L){} X(J j,J Qz,QJ L):j(j),Qz(Qz),Q1(nullptr),Qc(nullptr),L(L){} X(Z X&o):j(o.j),Qz(o.Qz),Q1(o.Q1),Qc((o.Qc)?(new K(*o.Qc)):nullptr),L(o.L){} X(X&&o):j(o.j),Qz(o.Qz),Q1(o.Q1),Qc((o.Qc)?(new K(*o.Qc)):nullptr),L(o.L){}~X(){delete Qc;}QJ R!=(Z X&o)Z{W L xor o.L;}X&R++(){++*Qc;if(not(*Qc!=O(*Q1))){++j;if(j!=Qz){delete Qc;Q1=std::make_shared<V>(*j);Qc=new K(w(*Q1));}QI{L=QR;}} W*Q4;}z(d)R*()Z{W**Qc;}};if(u>is_nil){W Qj(X(b,e,QR),X(b,e,QR));}QI{W Qj(X(b,e,*b,Qd),X(e,e,QR));}}}flatten;E<Y T,Y F,Y=std::enable_if_t<is_iterable_v<T>>>d R>=(T&&v,F f){W v>apply(f)>flatten;}E<Y U,k...Is>P QJ all_different_(Z U&x,Z U&y,Qu<Is...>){W((QD<Is>(x)!=QD<Is>(y))&&...);}E<Y F,Y...Ts>P d zip_with(F f,Ts&&...vs){QC(F f;H<z(w(Qa<Ts>()))...>its;,{W all_different_(its,o.its,std::index_sequence_for<Ts...>{});},{QQ([&](d&&...xs){(++xs,...);},its);W*Q4;},{W QQ([&](d&&...xs){W f(*xs...);},its);}) W Q9(X{f,H(w(vs)...)},X{f,H(O(vs)...)});};QH zip_default_function_{E<Y...Ts>z(d)R()(Ts&&...xs)Z{W H<Ts...>(QS<Ts>(xs)...);}};E<Y...Ts>P d zip(Ts&&...vs){W zip_with(zip_default_function_{},QS<Ts>(vs)...);}QZ(filter,E<Y F>,(F f),<F>{f},F f;,(X{f,O(v),w(v)}),(X{f,O(v),O(v)}),Z I end_it;P a QK()Z{while(it!=end_it and not f(*it)){++it;}},{QK();o.QK();W it!=o.it;},{QK();++it;W*Q4;},{QK();W*it;}) def_template_lambda(E<Y T>,repeat,(T&&v),{QH X{Z Qk<T>v;QJ R!=(Z X&)Z{W QR;}X&R++(){W*Q4;}Z d&R*()Z{W v;}};W Q9(X{v},X{v});})P d replicate(k n){W take(n)<repeat;}P d cycle=flatten<repeat;def_iterator_manip(enumerate,{W zip(to_infinity(k(0)),v);})def_iterator_manip(reversed,{d s=v>Qs;std::reverse(s.begin(),s.end());W iterc(Q7(s));})def_iterator_manip(sorted_by,E<Y F>,(F f),<F>{f},F f;,{d s=v>Qs;std::sort(w(s),O(s),f);W iterc(Q7(s));})def_iterator_manip(sorted,{W v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,E<Y F>,(F f),<F>{f},F f;,{W v>apply(FF(i,H(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>apply(fst);})def_iterator_manip(nub,{QC(I it_end;I it;,{W it!=o.it;},{z(*it)pr;do{pr=*it;++it;}while(it!=it_end and pr==*it);W*Q4;},{W*it;}) d b=w(v);d e=O(v);W Q9(X{e,b},X{e,e});})E<Y F,Y S>QH accum_vector_by_{QO Qb=a;k n;F f;S s;E<Y T,Y I=z(w(Qa<T>())),Y V=Qk<z(*Qa<I>())>>z(d)R()(Z T&v)Z{QF<Qk<QB<F,S,z(QD<1>(Qa<V>()))>>>u(n,s);for(d&&[i,x]:v){u[i]=f(u[i],x);}W u;}};E<Y F,Y S>P d accum_vector_by(k n,F f,Z S&s){W accum_vector_by_<F,S>{n,f,s};}E<Y S>P d accum_vector(k n,Z S&s=S()){W accum_vector_by(n,_2,s);}E<Y F,Y S>QH accum_map_by_{QO Qb=a;F f;S s;E<Y T,Y I=z(w(Qa<T>())),Y V=Qk<z(*Qa<I>())>>z(d)R()(Z T&v)Z{std::map<Qk<z(QD<0>(Qa<V>()))>,Qk<QB<F,S,z(QD<1>(Qa<V>()))>>>u;for(d&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QI{u[i]=f(s,x);}} W u;}};E<Y F,Y S>P d accum_map_by(F f,Z S&s){W accum_map_by_<F,S>{f,s};}E<Y S>P d accum_map(Z S&s=S()){W accum_map_by(_2,s);}E<Y F,Y S>QH accum_unordered_map_by_{QO Qb=a;F f;S s;E<Y T,Y I=z(w(Qa<T>())),Y V=Qk<z(*Qa<I>())>>z(d)R()(Z T&v)Z{std::unordered_map<Qk<z(QD<0>(Qa<V>()))>,Qk<QB<F,S,z(QD<1>(Qa<V>()))>>>u;for(d&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QI{u[i]=f(s,x);}} W u;}};E<Y F,Y S>P d accum_unordered_map_by(F f,Z S&s){W accum_unordered_map_by_<F,S>{f,s};}E<Y S>P d accum_unordered_map(Z S&s=S()){W accum_unordered_map_by(_2,s);}E<Y U,k...Is>P QJ any_different_(Z U&x,Z U&y,Qu<Is...>){W((QD<Is>(x)!=QD<Is>(y))||...);}E<k N,Y X>P a QV(X&it){if QX(N>=1){++QD<N-1>(it.its);if(not(QD<N-1>(it.its)!=O(QD<N-1>(*it.my_vs_ptr)))){QD<N-1>(it.its)=w(QD<N-1>(*it.my_vs_ptr));QV<N-1>(it);}} QI{it.its=QQ([](d&&...xs){W H(O(xs)...);},*it.my_vs_ptr);}} E<Y...Ts>d Q2(Ts&&...vs){d QU=std::make_shared<H<QE<Q8<Ts>,Qo<Ts>,Ts>...>>(vs...);QC(H<z(w(Qa<QE<Q8<Ts>,Qo<Ts>,Ts>>()))...>its;z(QU)my_vs_ptr;,{W any_different_(its,o.its,std::index_sequence_for<Ts...>{});},{QV<sizeof...(Ts)>(*Q4);W*Q4;},{W QQ([](d&&...xs){W H<z(*xs)...>(*xs...);},its);}) if(QQ([](d&&...xs){W((xs>is_nil)||...);},*QU)){W Q9(X{QQ([](d&&...xs){W H(O(xs)...);},*QU),QU},X{QQ([](d&&...xs){W H(O(xs)...);},*QU),QU});}QI{W Q9(X{QQ([](d&&...xs){W H(w(xs)...);},*QU),QU},X{QQ([](d&&...xs){W H(O(xs)...);},*QU),QU});}};E<Y...Ts>P d cartesian_product_range(Z Ts&...n){W Q2(Qy(n)...);}E<k n,Y I>P d cartesian_power(Z I&v){W QQ([](Z d&...vs){W Q2(vs...);},tuple_many_of<n>(v));}QH{QO Qb=a;Qt n=-1;E<Y T>d R()(T&&v)Z{if QX(std::is_convertible_v<T,Qt>){d x=*Q4;x.n=v;W x;}QI{d vec=v>Qs;Qt m=vec.size();QH X{Qt n;z(vec)my_v;QF<k>cycles;QJ L;QJ R!=(Z X&o)Z{W L xor o.L;}X&R++(){for(d i:Qy(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=my_v.size()-i;std::rotate(my_v.begin()+i,my_v.begin()+i+1,my_v.end());}QI{std::swap(my_v[i],my_v[my_v.size()-cycles[i]]);W*Q4;}} L=QR;W*Q4;}d R*()Z{W my_v>array_slice(0,n);}};Qt n1=(n<0)?(m):(n);W Q9(X{n1,Q7(vec),Qy(m,m-n1,-1)>apply(FF(x,k(x)))>Qs,Qd},X{n1,{},{},QR});}}}permutations;QH combinations_impl{QO Qb=a;Qt n;E<Y T>d R()(T&&v)Z{d vec=v>Qs;Qt m=vec.size();QC(Qt n;z(vec)my_v;QF<k>idx;QJ L;,{W L xor o.L;},{for(d i:Qy(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(d j:Qy(i+1,n)){idx[j]=idx[j-1]+1;}W*Q4;}} L=QR;W*Q4;},{W idx>array_slice(0,n)>apply(FF(i,my_v[i]));}) W Q9(X{n,Q7(vec),Qy(0,m)>apply(FF(x,k(x)))>Qs,Qd},X{n,{},{},QR});}};P d combinations(Qt n){W combinations_impl{n};}QH Ql{QO Qb=a;Qt n;E<Y T>d R()(T&&v)Z{d vec=v>Qs;Qt m=vec.size();QC(Qt n;z(vec)my_v;QF<k>idx;QJ L;,{W L xor o.L;},{for(d i:Qy(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(d j:Qy(i+1,n)){idx[j]=idx[i];}W*Q4;}} L=QR;W*Q4;},{W idx>array_slice(0,n)>apply(FF(i,my_v[i]));}) W Q9(X{n,Q7(vec),k(0)>replicate(m)>Qs,Qd},X{n,{},{},QR});}};P d combinations_with_replacement(Qt n){W Ql{n};}E<Y T>P d istream_iterable(std::istream&in){QC(std::istream&in;QA T val;QJ L;QA QJ has_read;,{W L xor o.L;},{if(not(in>>val)){L=QR;}W*Q4;},{if(not has_read){has_read=QR;in>>val;}W val;}) W Q9(X{in,T{},Qd,Qd},X{in,T{},QR,QR});}E<Y T>P d input=istream_iterable<T>(std::cin);E<Y T>Qe&print_iterable(Qe&out,Z T&v,Z std::string&sep= " "){for(d it=w(v);it!=O(v);){ out<<*it;++it;if(it!=O(v)){out<<sep;}QI{W out;}} W out;}E<Y T,Y=Y T::is_iterable_wrapper>P Qe&R<<(Qe&out,Z T&v){out<< "[";W print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)E<Y...Ts>Qe&R<<(Qe&out,Z I<Ts...>&v){W out<<Q9(v);}
QT(QF)QT(std::map)QT(std::unordered_map)QT(std::set)QT(std::unordered_set)E<k n,Y T>QH Qh{QO type=QF<Y Qh<n-1,T>::type>;static d make(Z Qg<n,k>&sz,Z T&val=T()){W QF(Qn(sz),Qh<n-1,T>::make(tuple_tail(sz),val));}};E<Y T>QH Qh<1,T>{QO type=QF<T>;static d make(Z H<k>&sz,Z T&val=T()){W QF(Qn(sz),val);}};E<k n,Y T>QO nested_vector=Y Qh<n,T>::type;E<k n,Y T>d make_nested_vector(Z Qg<n,k>&sz,Z T&val=T()){W Qh<n,T>::make(sz,val);}E<k n,Y T>P d Qv(Z T&v){if QX(n==1){W H(v.size());}QI{W std::tuple_cat(H(v.size()),Qv<n-1>(v[0]));}} E<k n,Y T>P d nested_vector_indices(Z T&v){W QQ([&](d...x){W cartesian_product_range(x...);},Qv<n>(v));}E<k n,Y T>P z(d)Qq(Z QF<T>&v,Z Qg<n,k>&i){if QX(n==1){W v[Qn(i)];}QI{W Qq<n-1>(v[Qn(i)],tuple_tail(i));}} E<k n,Y T>P z(d)Qq(QF<T>&v,Z Qg<n,k>&i){if QX(n==1){W v[Qn(i)];}QI{W Qq<n-1>(v[Qn(i)],tuple_tail(i));}} E<Y U,k i,k s>Qe&QY(Qe&out,Z U&u){if QX(i==0){out<< "{ ";}out<<QD<i>(u);if QX(i+1<s){out<< ", ";W QY<U,i+1,s>(out,u);}QI{W out<< " }";}} E<Y...Ts>Qe&R<<(Qe&out,Z H<Ts...>&u){W QY<z(u),0,sizeof...(Ts)>(out,u);}E<Y T,Y S>Qe&R<<(Qe&out,Z std::pair<T,S>&p){W out<<H(p.first,p.second);} 
#define BEGIN  Qt main(){std::ios_base::sync_with_stdio(Qd);std::cin.tie(0);std::cout.tie(0);
#define END }
QO namespace std;QO LL=long long;BEGIN Qt N;cin>>N;vector<LL>A(N+1);vector<LL>B(N+1);for(Qt n:Qy(1,N+1)){cin>>A[n];}map<tuple<Qt,Qt>,Qt>M;Qt Q;cin>>Q;LL ans=A>sum;d add_milestone=[&](Qt s,Qt t,Qt u){M[{s,t}]=u;if(B[u]<A[u]){--ans;}++B[u];};d remove_milestone=[&](Qt s,Qt t){Qt u=M[{s,t}];M.erase({s,t});--B[u];if(B[u]<A[u]){++ans;}};while(Q--){Qt s,t,u;cin>>s>>t>>u;if(M.count({s,t})){remove_milestone(s,t);}if(u>0){add_milestone(s,t,u);}cout<<ans<< "\n";}END