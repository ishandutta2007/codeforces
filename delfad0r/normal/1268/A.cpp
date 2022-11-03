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
#define QG iter
#define A __arg1__
#define QO nested_vector_size
#define QA std::remove_reference_t
#define QX iterable_wrapper
#define Qe bool
#define QI iterator_macro
#define d decltype
#define a std::end
#define QF cartesian_product_incr_
#define Q2 combinations_with_replacement_impl
#define QZ std::tuple_element_t
#define Qa range
#define Q8 __expr1__
#define QB mutable
#define QV implicit_lambda_binary_operator
#define Qw tuple_head
#define QT apply
#define W void
#define P true
#define Qy it_end
#define QD has_updated
#define Qh tuple_many_of_t
#define L using
#define QE to_vector
#define QC std::forward
#define k size_t
#define Qb ostream_tuple_helper_
#define QS implicit_lambda_unary_operator
#define o return
#define QU std::conditional_t
#define O template
#define Qj std::index_sequence
#define QY def_iterable_ostream
#define w std::tuple
#define Q0 __tuple__
#define Q9 __arg3__
#define Q1 tuple_tail
#define R struct
#define Qm std::get
#define Qf std::decay_t
#define Qo k_ptr
#define E Iterator
#define Qi std::shared_ptr
#define QR std::move
#define Q6 is_composable_
#define QL nested_vector_at
#define Qn vs_ptr
#define Qv std::apply
#define QQ implicit_lambda
#define Qt std::invoke_result_t
#define Qq nested_vector_impl
#define Qc false
#define Qg container_carrying_iterator
#define Ql to_nested_vector_impl
#define QW GET_5TH_ARG
#define Q5 std::is_rvalue_reference_v
#define B inline
#define Q7 is_composable_v
#define Qu cartesian_product
#define Qk constexpr
#define Y auto
#define Qp my_v
#define q other
#define Q is_end
#define Qx else
#define H const
#define QJ has_advanced
#define QH advance
#define Qd std::vector
#define Qs std::declval
#define Qr jv_ptr
#define Q3 def_iterator_manip_iter
#define Qz j_end
#define M operator
#define QK std::ostream
#define QP __arg2__
#define X typename
#define z std::begin
#define Q4 this

O<X T,k>L ignore_second=T;O<k...Ix,X T>Y tuple_many_of_impl(Qj<Ix...>,H T&x){o w(ignore_second<T,Ix>(x)...);}O<k n,X T>Y tuple_many_of(H T&x){o tuple_many_of_impl(std::make_index_sequence<n>{},x);}O<k n,X T>L Qh=d(tuple_many_of<n,T>(Qs<T>()));O<X...Args>Y Qw(H w<Args...>&t){o Qm<0>(t);}O<k...Ix,X...Args>Y tuple_tail_impl(Qj<Ix...>,H w<Args...>&t){o w(Qm<Ix+1>(t)...);}O<X...Args>Y Q1(H w<Args...>&t){o tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}R empty_t{};Qk empty_t empty_v;O<X T1,X T2>std::common_type_t<T1,T2>maxx(H T1&x,H T2&y){if(x<y){o y;}Qx{o x;}} O<X T1,X T2,X...Ts>B Y maxx(H T1&x,H T2&y,H Ts&...xs){o maxx(maxx(x,y),xs...);}O<X T1,X T2>Y minn(H T1&x,H T2&y){if(x<=y){o x;}Qx{o y;}} O<X T1,X T2,X...Ts>B Y minn(H T1&x,H T2&y,H Ts&...xs){o minn(minn(x,y),xs...);}Qk int _log2(int x){if(x==0){o 0;}o 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){o f;}
#define FF_1(A,f)[&](Y&&A){(W)A;o f;}
#define FF_2(A,QP,f)[&](Y&&A,Y&&QP){(W)A;(W)QP;o f;}
#define FF_3(A,QP,Q9,f)[&](Y&&A,Y&&QP,Y&&Q9){(W)A;(W)QP;(W)Q9;o f;}
#define FF_macro_chooser(...)QW(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->Y&{o f;}
#define FREF_1(A,f)[&](Y&&A)->Y&{(W)A;o f;}
#define FREF_2(A,QP,f)[&](Y&&A,Y&&QP)->Y&{(W)A;(W)QP;o f;}
#define FREF_3(A,QP,Q9,f)[&](Y&&A,Y&&QP,Y&&Q9)->Y&{(W)A;(W)QP;(W)Q9;o f;}
#define FREF_macro_chooser(...)QW(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){o f;}
#define FC_1(A,f,c)[&,c](Y&&A){(W)A;o f;}
#define FC_2(A,QP,f,c)[&,c](Y&&A,Y&&QP){(W)A;(W)QP;o f;}
#define FC_macro_chooser(...)QW(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){o f;}
#define FC2_1(A,f,c1,c2)[&,c1,c2](Y&&A){(W)A;o f;}
#define FC2_2(A,QP,f,c1,c2)[&,c1,c2](Y&&A,Y&&QP){(W)A;(W)QP;o f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(A,f)[&](Y&&Q0){Y&[A]=Q0;(W)A;o f;}
#define FT_2(A,QP,f)[&](Y&&Q0){Y&[A,QP]=Q0;(W)A;(W)QP;o f;}
#define FT_3(A,QP,Q9,f)[&](Y&&Q0){Y&[A,QP,Q9]=Q0;(W)A;(W)QP;(W)Q9;o f;}
#define FT_4(A,QP,Q9,__arg4__,f)[&](Y&&Q0){Y&[A,QP,Q9,__arg4__]=Q0;(W)A;(W)QP;(W)Q9;(W)__arg4__;o f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Q8,f)[&](){Y&&Q8;o f;}()
#define LET_2(Q8,__expr2__,f)[&](){Y&&Q8;Y&&__expr2__;o f;}()
#define LET_3(Q8,__expr2__,__expr3__,f)[&](){Y&&Q8;Y&&__expr2__;Y&&__expr3__;o f;}()
#define LET_macro_chooser(...)QW(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)Qk R{L Q6=W;templ B d(Y)M()args H code}name;
O<X F>class QQ{private:F f;public:QQ(F f_):f(f_){} O<X...Ts>Qk Y M()(Ts&&...xs)H{o f(QC<Ts>(xs)...);}};QQ _([](Y&&x)->QU<Q5<d(x)>,QA<d(x)>,d(x)>{o x;});QQ _1([](Y&&x,Y&&)->QU<Q5<d(x)>,QA<d(x)>,d(x)>{o x;});QQ _2([](Y&&,Y&&y)->QU<Q5<d(y)>,QA<d(y)>,d(y)>{o y;});
#define implicit_lambda_unary_operator(op)O<X F>Qk d(Y)M op(QQ<F>f){o QQ([=](Y&&...xs){o op f(QC<d(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)O<X F,X T>Qk d(Y)M op(QQ<F>f,H T&y){o QQ([=](Y&&...xs){o f(QC<d(xs)>(xs)...)op y;});}O<X F,X T>Qk d(Y)M op(H T&y,QQ<F>f){o QQ([=](Y&&...xs){o y op f(QC<d(xs)>(xs)...);});}O<X F,X G>Qk d(Y)M op(QQ<F>f,QQ<G>g){o QQ([=](Y&&...xs){o f(QC<d(xs)>(xs)...)op g(QC<d(xs)>(xs)...);});}
QS(+)QS(-)QS(!)QS(~)QS(*)QS(&)QV(+)QV(-)QV(*)QV(/)QV(%)QV(<)QV(>)QV(<=)QV(>=)QV(==)QV(!=)QV(<<)QV(>>)QV(&)QV(|)QV(^)QV(&&)O<X T,X=W>R is_composable:public std::false_type{};O<X T>R is_composable<T,std::void_t<X T::is_composable_>>:public std::true_type{};O<X T>Qk Qe Q7=is_composable<T>::value;O<X T,X F,X=Qt<F,T>>d(Y)M>(T&&v,H F&f){o f(QC<T>(v));}O<X M1,X M2>R composed{L Q6=W;H M1 m1;H M2 m2;O<X T>d(Y)M()(T&&v)H{o m1(m2(QC<T>(v)));}};O<X M1,X M2,X=std::enable_if_t<Q7<M1>or Q7<M2>>>B Y M<(H M1&m1,H M2&m2){o composed<M1,M2>{m1,m2};}O<k n>R nth_impl{L Q6=W;O<X...Ts>Qk QZ<n,w<Ts...>>&M()(w<Ts...>&u)H{o Qm<n>(u);}O<X...Ts>Qk QZ<n,w<Ts...>>M()(w<Ts...>&&u)H{o Qm<n>(u);}O<X...Ts>Qk H QZ<n,w<Ts...>>&M()(H w<Ts...>&u)H{o Qm<n>(u);}O<X...Ts>Qk H QZ<n,w<Ts...>>M()(H w<Ts...>&&u)H{o Qm<n>(u);}};O<k n>Qk nth_impl<n>nth;Qk nth_impl<0>fst;Qk nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)R E{extra Qe M!=(H E&q)H neq E&M++()incr d(Y)M*()H val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,Qy,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{QI(extra extra_it QB I it;,neq_it,incr_it,val_it);o QX(it_begin,Qy);})
#define def_iterator_manip_2(name,code)Qk R{L Q6=W;O<X T,X I=d(z(Qs<T>())),X V=Qf<d(*Qs<I>())>>d(Y)M()(T&&v)H code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ R name##_impl{L Q6=W;extra O<X T,X I=d(z(Qs<T>())),X V=Qf<d(*Qs<I>())>>d(Y)M()(T&&v)H code};templ B d(Y)name args{o name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
O<X T,X=W>R is_iterable:public std::false_type{};O<X T>R is_iterable<T,std::void_t<d(z(Qs<T>())),d(a(Qs<T>()))>>:public std::true_type{};O<X T>Qk Qe is_iterable_v=is_iterable<T>::value;O<X I>B Y QX(H I&b,H I&e){R Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
L is_iterable_wrapper=W;L iterator=I;L value_type=Qf<d(*Qs<I>())>;
#pragma GCC diagnostic pop
I b,e;Y begin()H{o b;}Y end()H{o e;}};o Wrapper{b,e};}O<X T>B Y QG(T&&iterable){o QX(z(QC<T>(iterable)),a(QC<T>(iterable)));}O<X I>B Y QG(H I&b,H I&e){o QX(b,e);}O<X C>R Qg:public C::iterator{Qi<C>p;Qg(Qi<C>p_,X C::iterator it):C::iterator(it),p(p_){}};O<X C>B Y iterc(C&&v){L D=Qf<C>;Qi<D>p(new D(QC<C>(v)));o QX(Qg<D>{p,z(*p)},Qg<D>{p,a(*p)});}O<X T>B Y QG(std::initializer_list<T>l){o iterc(Qd<T>(l));}def_template_lambda(O<X T>,QE,(T&&v),{Qd<X Qf<T>::value_type>s;for(Y&&x:v){s.push_back(x);}o s;})O<k n>R Ql{O<X T>B static Y make(T&&v){o QC<T>(v)>QT(FF(u,Ql<n-1>::make(u)))>QE;}};O<>R Ql<1>{O<X T>B static Y make(T&&v){o QC<T>(v)>QE;}};O<k n>R to_nested_vector_{L Q6=W;O<X T>B d(Y)M()(T&&v)H{o Ql<n>::make(QC<T>(v));}};O<k n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(k l,k r),({l,r}),k l;k r;,{o QG(z(v)+l,z(v)+r);})def_iterator_manip(is_nil,{o not(z(v)!=a(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{k l=0;for(Y i=z(v);i!=a(v);++i){++l;}o l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
O<X T1,X T2,X T3,X T=std::make_signed_t<d(T1()+T2()+T3())>>B Y Qa(H T1&b,H T2&e,H T3&step){QI(T x;T e;T step;B Qe Q()H{o(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{o Q()xor q.Q();},{x+=step;o*Q4;},{o T(x);}) o QG(E{b,e,step},E{e,e,step});}O<X T1,X T2>B Y Qa(H T1&b,H T2&e){o Qa(b,e,d(T1()+T2())(1));}O<X T>B Y Qa(H T&e){o Qa(T(),e,T(1));} 
#pragma GCC diagnostic pop
O<X T>B Y to_infinity(H T&b=0,H T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
QI(T x;T step;,{(W)q;o P;},{x+=step;o*Q4;},{o T(x);}) o QG(E{b,step},E{b,step});
#pragma GCC diagnostic pop
}Q3(QT,O<X F>,(F f),<F>{f},F f;,(E{f,z(v)}),(E{f,a(v)}),,{ o it!=q.it;},{++it;o*Q4;},{o f(*it);}) Q3(take,,(k n),{n},k n;,(E{n,z(v)}),(E{0,a(v)}),,{ o n!=q.n;},{--n;if(n>0){++it;}o*Q4;},{o*it;}) Q3(take_while,O<X F>,(F f),<F>{f},F f;,(E{f,not(z(v)!=a(v)and f(*z(v))),z(v)}),(E{f,P,a(v)}),Qe Q;,{o Q xor q.Q;},{++it;if(not f(*it)){Q=P;}o*Q4;},{o*it;}) Q3(drop,,(k n),{n},QB k n;,(E{n,a(v),z(v)}),(E{0,a(v),a(v)}),H I end_it;B W QH()H{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{QH();q.QH();o it!=q.it;},{QH();++it;o*Q4;},{QH();o*it;}) Q3(drop_while,O<X F>,(F f),<F>{f},F f;,(E{f,a(v),Qc,z(v)}),(E{f,a(v),P,a(v)}),H I end_it;QB Qe QJ;B W QH()H{if(not QJ){while(it!=end_it and f(*it)){++it;}QJ=P;}},{QH();q.QH();o it!=q.it;},{QH();++it;o*Q4;},{QH();o*it;}) def_iterator_manip(head,{o*z(v);})B Y tail=drop(1);B Y at(k n){o head<drop(n);}Q3(cons,O<X S>,(S s),<S>{s},S s;,(E{s,P,z(v)}),(E{s,Qc,a(v)}),Qe is_s;,{o is_s!=q.is_s or it!=q.it;},{if(is_s){is_s=Qc;}Qx{++it;}o*Q4;},{o(is_s)?(s):(*it);}) def_iterator_manip(snoc,{Y it=z(v);Y h=*it;++it;o w(h,QG(it,a(v)));})def_iterator_manip(split_at,,(k n),{n},k n;,{Y it=z(v);Qd<T>u;for(Y i:Qa(n)){u.push_back(*it);++it;}o w(iterc(QR(u)),QG(it,a(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
Q3(chunks_of,,(k n),{n},k n;,(E{n,{},Qc,a(v),z(v)}),(E{n,{},Qc,a(v),a(v)}),QB Qd<V>u;QB Qe QD;I Qy;W update()H{u.clear();QD=P;for(Y i:Qa(n)){if(it!=Qy){u.push_back(*it);++it;}Qx{break;}}},{o it!=q.it;},{if(QD){QD=Qc;}Qx{for(Y i:Qa(n)){if(it!=Qy){++it;}Qx{break;}}}o*Q4;},{if(not QD){update();}o iterc(u);})
#pragma GCC diagnostic pop
O<X F,X S>R fold_impl{L Q6=W;F f;S s;O<X T>Y M()(H T&v)H{Y x=s;for(Y y:v){x=f(x,y);}o x;}};O<X F,X S>B Y fold(F f,H S&s){o fold_impl<F,S>{f,s};}def_iterator_manip(fold1,O<X F>,(F f),<F>{f},F f;,{Y u=v>snoc;o u>snd>fold(f,u>fst);})def_iterator_manip(sum,{o v>fold(_1+_2,V(0));})def_iterator_manip(product,{o v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,O<X F>,(F f),<F>{f},F f;,{o v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{o v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,O<X F>,(F f),<F>{f},F f;,{o v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,O<X F>,(F f),<F>{f},F f;,{o v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{o v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,O<X F>,(F f),<F>{f},F f;,{o v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})O<X F,X S>R scan_impl{L Q6=W;F f;S s;O<X T,X I=d(z(Qs<T>()))>d(Y)M()(T&&v)H{QI(F f;QB S s;QB Qe QD;Qe QJ;QB I it;,{o it!=q.it;},{if(not QD){s=f(s,*it);};QD=Qc;if(QJ){++it;}Qx{QJ=P;}o*Q4;},{if(not QD){QD=P;s=f(s,*it);}o s;}) o QG(E{f,s,P,Qc,z(QC<T>(v))},E{f,s,P,P,a(QC<T>(v))});}};O<X F,X S>B Y scan(F f,H S&s){o scan_impl<F,S>{f,s};}Q3(scan1,O<X F>,(F f),<F>{f},F f;,(E{f,*z(v),P,z(v)}),(E{f,*z(v),P,a(v)}),QB V s;QB Qe QD;,{o it!=q.it;},{if(not QD){s=f(s,*it);};QD=Qc;++it;o*Q4;},{if(not QD){QD=P;s=f(s,*it);}o s;}) O<X T,X S,X I=d(z(Qs<T>())),X J=d(z(Qs<S>()))>B Y M+(T&&v,S&&u){QI(I i;I i_end;J j;Qe in_i;,{o i!=q.i or j!=q.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=Qc;}}Qx{++j;}o*Q4;},{o(in_i)?(*i):(*j);}) I bv=z(v);I ev=a(v);J bu=z(u);J eu=a(u);o QG(E{bv,ev,bu,bv!=ev},E{ev,ev,eu,Qc});}Qk R{L Q6=W;O<X T>Y M()(T&&v)H{Y u=QC<T>(v)>filter(FF(i,not is_nil(i)));Y b=z(u);Y e=a(u);L J=d(b);L V=Qf<d(*b)>;L K=d(z(*b));R E{J j;J Qz;Qi<V>Qr;K*Qo;Qe Q;E(J j,J Qz,H V&jv,Qe Q):j(j),Qz(Qz),Qr(new V(jv)),Qo(new K(z(*Qr))),Q(Q){} E(J j,J Qz,Qe Q):j(j),Qz(Qz),Qr(nullptr),Qo(nullptr),Q(Q){} E(H E&q):j(q.j),Qz(q.Qz),Qr(q.Qr),Qo((q.Qo)?(new K(*q.Qo)):nullptr),Q(q.Q){} E(E&&q):j(q.j),Qz(q.Qz),Qr(q.Qr),Qo((q.Qo)?(new K(*q.Qo)):nullptr),Q(q.Q){}~E(){delete Qo;}Qe M!=(H E&q)H{o Q xor q.Q;}E&M++(){++*Qo;if(not(*Qo!=a(*Qr))){++j;if(j!=Qz){delete Qo;Qr=std::make_shared<V>(*j);Qo=new K(z(*Qr));}Qx{Q=P;}} o*Q4;}d(Y)M*()H{o**Qo;}};if(u>is_nil){o QX(E(b,e,P),E(b,e,P));}Qx{o QX(E(b,e,*b,Qc),E(e,e,P));}}}flatten;O<X T,X F,X=std::enable_if_t<is_iterable_v<T>>>Y M>=(T&&v,F f){o v>QT(f)>flatten;}O<X U,k...Is>B Qe all_different_(H U&x,H U&y,Qj<Is...>){o((Qm<Is>(x)!=Qm<Is>(y))&&...);}O<X F,X...Ts>B Y zip_with(F f,Ts&&...vs){QI(F f;w<d(z(Qs<Ts>()))...>its;,{o all_different_(its,q.its,std::index_sequence_for<Ts...>{});},{Qv([&](Y&&...xs){(++xs,...);},its);o*Q4;},{o Qv([&](Y&&...xs){o f(*xs...);},its);}) o QG(E{f,w(z(vs)...)},E{f,w(a(vs)...)});};R zip_default_function_{O<X...Ts>d(Y)M()(Ts&&...xs)H{o w<Ts...>(QC<Ts>(xs)...);}};O<X...Ts>B Y zip(Ts&&...vs){o zip_with(zip_default_function_{},QC<Ts>(vs)...);}Q3(filter,O<X F>,(F f),<F>{f},F f;,(E{f,a(v),z(v)}),(E{f,a(v),a(v)}),H I end_it;B W QH()H{while(it!=end_it and not f(*it)){++it;}},{QH();q.QH();o it!=q.it;},{QH();++it;o*Q4;},{QH();o*it;}) def_template_lambda(O<X T>,repeat,(T&&v),{R E{H Qf<T>v;Qe M!=(H E&)H{o P;}E&M++(){o*Q4;}H Y&M*()H{o v;}};o QG(E{v},E{v});})B Y replicate(k n){o take(n)<repeat;}B Y cycle=flatten<repeat;def_iterator_manip(enumerate,{o zip(to_infinity(k(0)),v);})def_iterator_manip(reversed,{Y s=v>QE;std::reverse(s.begin(),s.end());o iterc(QR(s));})def_iterator_manip(sorted_by,O<X F>,(F f),<F>{f},F f;,{Y s=v>QE;std::sort(z(s),a(s),f);o iterc(QR(s));})def_iterator_manip(sorted,{o v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,O<X F>,(F f),<F>{f},F f;,{o v>QT(FF(i,w(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>QT(fst);})def_iterator_manip(nub,{QI(I Qy;I it;,{o it!=q.it;},{d(*it)pr;do{pr=*it;++it;}while(it!=Qy and pr==*it);o*Q4;},{o*it;}) Y b=z(v);Y e=a(v);o QG(E{e,b},E{e,e});})O<X F,X S>R accum_vector_by_{L Q6=W;k n;F f;S s;O<X T,X I=d(z(Qs<T>())),X V=Qf<d(*Qs<I>())>>d(Y)M()(H T&v)H{Qd<Qf<Qt<F,S,d(Qm<1>(Qs<V>()))>>>u(n,s);for(Y&&[i,x]:v){u[i]=f(u[i],x);}o u;}};O<X F,X S>B Y accum_vector_by(k n,F f,H S&s){o accum_vector_by_<F,S>{n,f,s};}O<X S>B Y accum_vector(k n,H S&s=S()){o accum_vector_by(n,_2,s);}O<X F,X S>R accum_map_by_{L Q6=W;F f;S s;O<X T,X I=d(z(Qs<T>())),X V=Qf<d(*Qs<I>())>>d(Y)M()(H T&v)H{std::map<Qf<d(Qm<0>(Qs<V>()))>,Qf<Qt<F,S,d(Qm<1>(Qs<V>()))>>>u;for(Y&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qx{u[i]=f(s,x);}} o u;}};O<X F,X S>B Y accum_map_by(F f,H S&s){o accum_map_by_<F,S>{f,s};}O<X S>B Y accum_map(H S&s=S()){o accum_map_by(_2,s);}O<X F,X S>R accum_unordered_map_by_{L Q6=W;F f;S s;O<X T,X I=d(z(Qs<T>())),X V=Qf<d(*Qs<I>())>>d(Y)M()(H T&v)H{std::unordered_map<Qf<d(Qm<0>(Qs<V>()))>,Qf<Qt<F,S,d(Qm<1>(Qs<V>()))>>>u;for(Y&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Qx{u[i]=f(s,x);}} o u;}};O<X F,X S>B Y accum_unordered_map_by(F f,H S&s){o accum_unordered_map_by_<F,S>{f,s};}O<X S>B Y accum_unordered_map(H S&s=S()){o accum_unordered_map_by(_2,s);}O<X U,k...Is>B Qe any_different_(H U&x,H U&y,Qj<Is...>){o((Qm<Is>(x)!=Qm<Is>(y))||...);}O<k N,X E>B W QF(E&it){if Qk(N>=1){++Qm<N-1>(it.its);if(not(Qm<N-1>(it.its)!=a(Qm<N-1>(*it.my_vs_ptr)))){Qm<N-1>(it.its)=z(Qm<N-1>(*it.my_vs_ptr));QF<N-1>(it);}} Qx{it.its=Qv([](Y&&...xs){o w(a(xs)...);},*it.my_vs_ptr);}} O<X...Ts>Y Qu(Ts&&...vs){Y Qn=std::make_shared<w<QU<Q5<Ts>,QA<Ts>,Ts>...>>(vs...);QI(w<d(z(Qs<QU<Q5<Ts>,QA<Ts>,Ts>>()))...>its;d(Qn)my_vs_ptr;,{o any_different_(its,q.its,std::index_sequence_for<Ts...>{});},{QF<sizeof...(Ts)>(*Q4);o*Q4;},{o Qv([](Y&&...xs){o w<d(*xs)...>(*xs...);},its);}) if(Qv([](Y&&...xs){o((xs>is_nil)||...);},*Qn)){o QG(E{Qv([](Y&&...xs){o w(a(xs)...);},*Qn),Qn},E{Qv([](Y&&...xs){o w(a(xs)...);},*Qn),Qn});}Qx{o QG(E{Qv([](Y&&...xs){o w(z(xs)...);},*Qn),Qn},E{Qv([](Y&&...xs){o w(a(xs)...);},*Qn),Qn});}};O<X...Ts>B Y cartesian_product_range(H Ts&...n){o Qu(Qa(n)...);}O<k n,X I>B Y cartesian_power(H I&v){o Qv([](H Y&...vs){o Qu(vs...);},tuple_many_of<n>(v));}R{L Q6=W;int n=-1;O<X T>Y M()(T&&v)H{if Qk(std::is_convertible_v<T,int>){Y x=*Q4;x.n=v;o x;}Qx{Y vec=v>QE;int m=vec.size();R E{int n;d(vec)Qp;Qd<k>cycles;Qe Q;Qe M!=(H E&q)H{o Q xor q.Q;}E&M++(){for(Y i:Qa(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=Qp.size()-i;std::rotate(Qp.begin()+i,Qp.begin()+i+1,Qp.end());}Qx{std::swap(Qp[i],Qp[Qp.size()-cycles[i]]);o*Q4;}} Q=P;o*Q4;}Y M*()H{o Qp>array_slice(0,n);}};int n1=(n<0)?(m):(n);o QG(E{n1,QR(vec),Qa(m,m-n1,-1)>QT(FF(x,k(x)))>QE,Qc},E{n1,{},{},P});}}}permutations;R combinations_impl{L Q6=W;int n;O<X T>Y M()(T&&v)H{Y vec=v>QE;int m=vec.size();QI(int n;d(vec)Qp;Qd<k>idx;Qe Q;,{o Q xor q.Q;},{for(Y i:Qa(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(Y j:Qa(i+1,n)){idx[j]=idx[j-1]+1;}o*Q4;}} Q=P;o*Q4;},{o idx>array_slice(0,n)>QT(FF(i,Qp[i]));}) o QG(E{n,QR(vec),Qa(0,m)>QT(FF(x,k(x)))>QE,Qc},E{n,{},{},P});}};B Y combinations(int n){o combinations_impl{n};}R Q2{L Q6=W;int n;O<X T>Y M()(T&&v)H{Y vec=v>QE;int m=vec.size();QI(int n;d(vec)Qp;Qd<k>idx;Qe Q;,{o Q xor q.Q;},{for(Y i:Qa(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(Y j:Qa(i+1,n)){idx[j]=idx[i];}o*Q4;}} Q=P;o*Q4;},{o idx>array_slice(0,n)>QT(FF(i,Qp[i]));}) o QG(E{n,QR(vec),k(0)>replicate(m)>QE,Qc},E{n,{},{},P});}};B Y combinations_with_replacement(int n){o Q2{n};}O<X T>B Y istream_iterable(std::istream&in){QI(std::istream&in;QB T val;Qe Q;QB Qe has_read;,{o Q xor q.Q;},{if(not(in>>val)){Q=P;}o*Q4;},{if(not has_read){has_read=P;in>>val;}o val;}) o QG(E{in,T{},Qc,Qc},E{in,T{},P,P});}O<X T>B Y input=istream_iterable<T>(std::cin);O<X T>QK&print_iterable(QK&out,H T&v,H std::string&sep= " "){for(Y it=z(v);it!=a(v);){ out<<*it;++it;if(it!=a(v)){out<<sep;}Qx{o out;}} o out;}O<X T,X=X T::is_iterable_wrapper>B QK&M<<(QK&out,H T&v){out<< "[";o print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)O<X...Ts>QK&M<<(QK&out,H I<Ts...>&v){o out<<QG(v);}
QY(Qd)QY(std::map)QY(std::unordered_map)QY(std::set)QY(std::unordered_set)O<k n,X T>R Qq{L type=Qd<X Qq<n-1,T>::type>;static Y make(H Qh<n,k>&sz,H T&val=T()){o Qd(Qw(sz),Qq<n-1,T>::make(Q1(sz),val));}};O<X T>R Qq<1,T>{L type=Qd<T>;static Y make(H w<k>&sz,H T&val=T()){o Qd(Qw(sz),val);}};O<k n,X T>L nested_vector=X Qq<n,T>::type;O<k n,X T>Y make_nested_vector(H Qh<n,k>&sz,H T&val=T()){o Qq<n,T>::make(sz,val);}O<k n,X T>B Y QO(H T&v){if Qk(n==1){o w(v.size());}Qx{o std::tuple_cat(w(v.size()),QO<n-1>(v[0]));}} O<k n,X T>B Y nested_vector_indices(H T&v){o Qv([&](Y...x){o cartesian_product_range(x...);},QO<n>(v));}O<k n,X T>B d(Y)QL(H Qd<T>&v,H Qh<n,k>&i){if Qk(n==1){o v[Qw(i)];}Qx{o QL<n-1>(v[Qw(i)],Q1(i));}} O<k n,X T>B d(Y)QL(Qd<T>&v,H Qh<n,k>&i){if Qk(n==1){o v[Qw(i)];}Qx{o QL<n-1>(v[Qw(i)],Q1(i));}} O<X U,k i,k s>QK&Qb(QK&out,H U&u){if Qk(i==0){out<< "{ ";}out<<Qm<i>(u);if Qk(i+1<s){out<< ", ";o Qb<U,i+1,s>(out,u);}Qx{o out<< " }";}} O<X...Ts>QK&M<<(QK&out,H w<Ts...>&u){o Qb<d(u),0,sizeof...(Ts)>(out,u);}O<X T,X S>QK&M<<(QK&out,H std::pair<T,S>&p){o out<<w(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(Qc);std::cin.tie(0);std::cout.tie(0);
#define END }
L namespace std;L LL=long long;BEGIN int N,K;cin>>N>>K;string S;cin>>S;string Z(N, '0');for(int n=0;n<N;++n){Z[n]=S[n%K];}if(Z<S){for(int n=K-1;;--n){assert(n>=0);if(S[n]!= '9'){++S[n];break;}S[n]= '0';}for(int n=0;n<N;++n){Z[n]=S[n%K];}} cout<<N<< "\n" <<Z<< "\n";END