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
#define L decltype
#define QW std::index_sequence
#define QK checkpoints
#define Qb is_composable
#define Qn ostream_tuple_helper_
#define W6 implicit_lambda
#define W5 has_advanced
#define QQ range
#define A is_end
#define QJ GET_5TH_ARG
#define W4 constexpr
#define QH advance
#define Qr std::forward
#define QG range_query
#define k std::begin
#define Qm j_end
#define q __arg1__
#define H true
#define Qu vs_ptr
#define Y std::end
#define QD std::ostream
#define QS combinations_with_replacement_impl
#define Qt std::get
#define QR make_disjoint_sparse_table
#define QU my_v
#define R const
#define QA __arg3__
#define W3 implicit_lambda_unary_operator
#define Qi def_iterable_ostream
#define Qe this
#define z template
#define Qw disjoint_sparse_table
#define d auto
#define M void
#define E inline
#define Ql else
#define QF int
#define W size_t
#define Qq tuple_head
#define Qc container_carrying_iterator
#define Qx iterator_macro
#define Q6 has_updated
#define Q0 nested_vector_size
#define QX implicit_lambda_binary_operator
#define QP __expr1__
#define Q2 using
#define Qz tuple_tail
#define W2 nested_vector_impl
#define QO cartesian_product
#define W1 __tuple__
#define B std::tuple
#define QI std::apply
#define o Iterator
#define QY mutable
#define Q3 apply
#define Q9 size
#define Q8 is_composable_v
#define Qk std::declval
#define Qj std::conditional_t
#define Q1 is_composable_
#define Q7 k_ptr
#define Q_ public
#define Qh tuple_many_of_t
#define QT cartesian_product_incr_
#define w operator
#define P return
#define Q5 std::tuple_element_t
#define Qg std::vector
#define Qy it_end
#define Qd to_nested_vector_impl
#define Qs nested_vector_at
#define X typename
#define Qf std::remove_reference_t
#define QN iter
#define QB iterable_wrapper
#define Q4 std::shared_ptr
#define QV false
#define QC std::is_rvalue_reference_v
#define QM def_iterator_manip_iter
#define Z struct
#define O other
#define QE __arg2__
#define Qa jv_ptr
#define QZ std::invoke_result_t
#define Qp to_vector
#define QL std::decay_t
#define Qo std::move
#define Qv bool

z<X T,W>Q2 ignore_second=T;z<W...Ix,X T>d tuple_many_of_impl(QW<Ix...>,R T&x){P B(ignore_second<T,Ix>(x)...);}z<W n,X T>d tuple_many_of(R T&x){P tuple_many_of_impl(std::make_index_sequence<n>{},x);}z<W n,X T>Q2 Qh=L(tuple_many_of<n,T>(Qk<T>()));z<X...Args>d Qq(R B<Args...>&t){P Qt<0>(t);}z<W...Ix,X...Args>d tuple_tail_impl(QW<Ix...>,R B<Args...>&t){P B(Qt<Ix+1>(t)...);}z<X...Args>d Qz(R B<Args...>&t){P tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}Z empty_t{};W4 empty_t empty_v;z<X T1,X T2>std::common_type_t<T1,T2>maxx(R T1&x,R T2&y){if(x<y){P y;}Ql{P x;}} z<X T1,X T2,X...Ts>E d maxx(R T1&x,R T2&y,R Ts&...xs){P maxx(maxx(x,y),xs...);}z<X T1,X T2>d minn(R T1&x,R T2&y){if(x<=y){P x;}Ql{P y;}} z<X T1,X T2,X...Ts>E d minn(R T1&x,R T2&y,R Ts&...xs){P minn(minn(x,y),xs...);}W4 QF _log2(QF x){if(x==0){P 0;}P 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){P f;}
#define FF_1(q,f)[&](d&&q){(M)q;P f;}
#define FF_2(q,QE,f)[&](d&&q,d&&QE){(M)q;(M)QE;P f;}
#define FF_3(q,QE,QA,f)[&](d&&q,d&&QE,d&&QA){(M)q;(M)QE;(M)QA;P f;}
#define FF_macro_chooser(...)QJ(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->d&{P f;}
#define FREF_1(q,f)[&](d&&q)->d&{(M)q;P f;}
#define FREF_2(q,QE,f)[&](d&&q,d&&QE)->d&{(M)q;(M)QE;P f;}
#define FREF_3(q,QE,QA,f)[&](d&&q,d&&QE,d&&QA)->d&{(M)q;(M)QE;(M)QA;P f;}
#define FREF_macro_chooser(...)QJ(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){P f;}
#define FC_1(q,f,c)[&,c](d&&q){(M)q;P f;}
#define FC_2(q,QE,f,c)[&,c](d&&q,d&&QE){(M)q;(M)QE;P f;}
#define FC_macro_chooser(...)QJ(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){P f;}
#define FC2_1(q,f,c1,c2)[&,c1,c2](d&&q){(M)q;P f;}
#define FC2_2(q,QE,f,c1,c2)[&,c1,c2](d&&q,d&&QE){(M)q;(M)QE;P f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(q,f)[&](d&&W1){d&[q]=W1;(M)q;P f;}
#define FT_2(q,QE,f)[&](d&&W1){d&[q,QE]=W1;(M)q;(M)QE;P f;}
#define FT_3(q,QE,QA,f)[&](d&&W1){d&[q,QE,QA]=W1;(M)q;(M)QE;(M)QA;P f;}
#define FT_4(q,QE,QA,__arg4__,f)[&](d&&W1){d&[q,QE,QA,__arg4__]=W1;(M)q;(M)QE;(M)QA;(M)__arg4__;P f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(QP,f)[&](){d&&QP;P f;}()
#define LET_2(QP,__expr2__,f)[&](){d&&QP;d&&__expr2__;P f;}()
#define LET_3(QP,__expr2__,__expr3__,f)[&](){d&&QP;d&&__expr2__;d&&__expr3__;P f;}()
#define LET_macro_chooser(...)QJ(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)W4 Z{Q2 Q1=M;templ E L(d)w()args R code}name;
z<X F>class W6{private:F f;Q_:W6(F f_):f(f_){} z<X...Ts>W4 d w()(Ts&&...xs)R{P f(Qr<Ts>(xs)...);}};W6 _([](d&&x)->Qj<QC<L(x)>,Qf<L(x)>,L(x)>{P x;});W6 _1([](d&&x,d&&)->Qj<QC<L(x)>,Qf<L(x)>,L(x)>{P x;});W6 _2([](d&&,d&&y)->Qj<QC<L(y)>,Qf<L(y)>,L(y)>{P y;});
#define implicit_lambda_unary_operator(op)z<X F>W4 L(d)w op(W6<F>f){P W6([=](d&&...xs){P op f(Qr<L(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)z<X F,X T>W4 L(d)w op(W6<F>f,R T&y){P W6([=](d&&...xs){P f(Qr<L(xs)>(xs)...)op y;});}z<X F,X T>W4 L(d)w op(R T&y,W6<F>f){P W6([=](d&&...xs){P y op f(Qr<L(xs)>(xs)...);});}z<X F,X G>W4 L(d)w op(W6<F>f,W6<G>g){P W6([=](d&&...xs){P f(Qr<L(xs)>(xs)...)op g(Qr<L(xs)>(xs)...);});}
W3(+)W3(-)W3(!)W3(~)W3(*)W3(&)QX(+)QX(-)QX(*)QX(/)QX(%)QX(<)QX(>)QX(<=)QX(>=)QX(==)QX(!=)QX(<<)QX(>>)QX(&)QX(|)QX(^)QX(&&)z<X T,X=M>Z Qb:Q_ std::false_type{};z<X T>Z Qb<T,std::void_t<X T::is_composable_>>:Q_ std::true_type{};z<X T>W4 Qv Q8=Qb<T>::value;z<X T,X F,X=QZ<F,T>>L(d)w>(T&&v,R F&f){P f(Qr<T>(v));}z<X M1,X M2>Z composed{Q2 Q1=M;R M1 m1;R M2 m2;z<X T>L(d)w()(T&&v)R{P m1(m2(Qr<T>(v)));}};z<X M1,X M2,X=std::enable_if_t<Q8<M1>or Q8<M2>>>E d w<(R M1&m1,R M2&m2){P composed<M1,M2>{m1,m2};}z<W n>Z nth_impl{Q2 Q1=M;z<X...Ts>W4 Q5<n,B<Ts...>>&w()(B<Ts...>&u)R{P Qt<n>(u);}z<X...Ts>W4 Q5<n,B<Ts...>>w()(B<Ts...>&&u)R{P Qt<n>(u);}z<X...Ts>W4 R Q5<n,B<Ts...>>&w()(R B<Ts...>&u)R{P Qt<n>(u);}z<X...Ts>W4 R Q5<n,B<Ts...>>w()(R B<Ts...>&&u)R{P Qt<n>(u);}};z<W n>W4 nth_impl<n>nth;W4 nth_impl<0>fst;W4 nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)Z o{extra Qv w!=(R o&O)R neq o&w++()incr L(d)w*()R val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,Qy,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{Qx(extra extra_it QY I it;,neq_it,incr_it,val_it);P QB(it_begin,Qy);})
#define def_iterator_manip_2(name,code)W4 Z{Q2 Q1=M;z<X T,X I=L(k(Qk<T>())),X V=QL<L(*Qk<I>())>>L(d)w()(T&&v)R code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ Z name##_impl{Q2 Q1=M;extra z<X T,X I=L(k(Qk<T>())),X V=QL<L(*Qk<I>())>>L(d)w()(T&&v)R code};templ E L(d)name args{P name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
z<X T,X=M>Z is_iterable:Q_ std::false_type{};z<X T>Z is_iterable<T,std::void_t<L(k(Qk<T>())),L(Y(Qk<T>()))>>:Q_ std::true_type{};z<X T>W4 Qv is_iterable_v=is_iterable<T>::value;z<X I>E d QB(R I&b,R I&e){Z Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
Q2 is_iterable_wrapper=M;Q2 iterator=I;Q2 value_type=QL<L(*Qk<I>())>;
#pragma GCC diagnostic pop
I b,e;d begin()R{P b;}d end()R{P e;}};P Wrapper{b,e};}z<X T>E d QN(T&&iterable){P QB(k(Qr<T>(iterable)),Y(Qr<T>(iterable)));}z<X I>E d QN(R I&b,R I&e){P QB(b,e);}z<X C>Z Qc:Q_ C::iterator{Q4<C>p;Qc(Q4<C>p_,X C::iterator it):C::iterator(it),p(p_){}};z<X C>E d iterc(C&&v){Q2 D=QL<C>;Q4<D>p(new D(Qr<C>(v)));P QB(Qc<D>{p,k(*p)},Qc<D>{p,Y(*p)});}z<X T>E d QN(std::initializer_list<T>l){P iterc(Qg<T>(l));}def_template_lambda(z<X T>,Qp,(T&&v),{Qg<X QL<T>::value_type>s;for(d&&x:v){s.push_back(x);}P s;})z<W n>Z Qd{z<X T>E static d make(T&&v){P Qr<T>(v)>Q3(FF(u,Qd<n-1>::make(u)))>Qp;}};z<>Z Qd<1>{z<X T>E static d make(T&&v){P Qr<T>(v)>Qp;}};z<W n>Z to_nested_vector_{Q2 Q1=M;z<X T>E L(d)w()(T&&v)R{P Qd<n>::make(Qr<T>(v));}};z<W n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(W l,W r),({l,r}),W l;W r;,{P QN(k(v)+l,k(v)+r);})def_iterator_manip(is_nil,{P not(k(v)!=Y(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{W l=0;for(d i=k(v);i!=Y(v);++i){++l;}P l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
z<X T1,X T2,X T3,X T=std::make_signed_t<L(T1()+T2()+T3())>>E d QQ(R T1&b,R T2&e,R T3&step){Qx(T x;T e;T step;E Qv A()R{P(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{P A()xor O.A();},{x+=step;P*Qe;},{P T(x);}) P QN(o{b,e,step},o{e,e,step});}z<X T1,X T2>E d QQ(R T1&b,R T2&e){P QQ(b,e,L(T1()+T2())(1));}z<X T>E d QQ(R T&e){P QQ(T(),e,T(1));} 
#pragma GCC diagnostic pop
z<X T>E d to_infinity(R T&b=0,R T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
Qx(T x;T step;,{(M)O;P H;},{x+=step;P*Qe;},{P T(x);}) P QN(o{b,step},o{b,step});
#pragma GCC diagnostic pop
}QM(Q3,z<X F>,(F f),<F>{f},F f;,(o{f,k(v)}),(o{f,Y(v)}),,{ P it!=O.it;},{++it;P*Qe;},{P f(*it);}) QM(take,,(W n),{n},W n;,(o{n,k(v)}),(o{0,Y(v)}),,{ P n!=O.n;},{--n;if(n>0){++it;}P*Qe;},{P*it;}) QM(take_while,z<X F>,(F f),<F>{f},F f;,(o{f,not(k(v)!=Y(v)and f(*k(v))),k(v)}),(o{f,H,Y(v)}),Qv A;,{P A xor O.A;},{++it;if(not f(*it)){A=H;}P*Qe;},{P*it;}) QM(drop,,(W n),{n},QY W n;,(o{n,Y(v),k(v)}),(o{0,Y(v),Y(v)}),R I end_it;E M QH()R{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{QH();O.QH();P it!=O.it;},{QH();++it;P*Qe;},{QH();P*it;}) QM(drop_while,z<X F>,(F f),<F>{f},F f;,(o{f,Y(v),QV,k(v)}),(o{f,Y(v),H,Y(v)}),R I end_it;QY Qv W5;E M QH()R{if(not W5){while(it!=end_it and f(*it)){++it;}W5=H;}},{QH();O.QH();P it!=O.it;},{QH();++it;P*Qe;},{QH();P*it;}) def_iterator_manip(head,{P*k(v);})E d tail=drop(1);E d at(W n){P head<drop(n);}QM(cons,z<X S>,(S s),<S>{s},S s;,(o{s,H,k(v)}),(o{s,QV,Y(v)}),Qv is_s;,{P is_s!=O.is_s or it!=O.it;},{if(is_s){is_s=QV;}Ql{++it;}P*Qe;},{P(is_s)?(s):(*it);}) def_iterator_manip(snoc,{d it=k(v);d h=*it;++it;P B(h,QN(it,Y(v)));})def_iterator_manip(split_at,,(W n),{n},W n;,{d it=k(v);Qg<T>u;for(d i:QQ(n)){u.push_back(*it);++it;}P B(iterc(Qo(u)),QN(it,Y(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
QM(chunks_of,,(W n),{n},W n;,(o{n,{},QV,Y(v),k(v)}),(o{n,{},QV,Y(v),Y(v)}),QY Qg<V>u;QY Qv Q6;I Qy;M update()R{u.clear();Q6=H;for(d i:QQ(n)){if(it!=Qy){u.push_back(*it);++it;}Ql{break;}}},{P it!=O.it;},{if(Q6){Q6=QV;}Ql{for(d i:QQ(n)){if(it!=Qy){++it;}Ql{break;}}}P*Qe;},{if(not Q6){update();}P iterc(u);})
#pragma GCC diagnostic pop
z<X F,X S>Z fold_impl{Q2 Q1=M;F f;S s;z<X T>d w()(R T&v)R{d x=s;for(d y:v){x=f(x,y);}P x;}};z<X F,X S>E d fold(F f,R S&s){P fold_impl<F,S>{f,s};}def_iterator_manip(fold1,z<X F>,(F f),<F>{f},F f;,{d u=v>snoc;P u>snd>fold(f,u>fst);})def_iterator_manip(sum,{P v>fold(_1+_2,V(0));})def_iterator_manip(product,{P v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,z<X F>,(F f),<F>{f},F f;,{P v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{P v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,z<X F>,(F f),<F>{f},F f;,{P v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,z<X F>,(F f),<F>{f},F f;,{P v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{P v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,z<X F>,(F f),<F>{f},F f;,{P v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})z<X F,X S>Z scan_impl{Q2 Q1=M;F f;S s;z<X T,X I=L(k(Qk<T>()))>L(d)w()(T&&v)R{Qx(F f;QY S s;QY Qv Q6;Qv W5;QY I it;,{P it!=O.it;},{if(not Q6){s=f(s,*it);};Q6=QV;if(W5){++it;}Ql{W5=H;}P*Qe;},{if(not Q6){Q6=H;s=f(s,*it);}P s;}) P QN(o{f,s,H,QV,k(Qr<T>(v))},o{f,s,H,H,Y(Qr<T>(v))});}};z<X F,X S>E d scan(F f,R S&s){P scan_impl<F,S>{f,s};}QM(scan1,z<X F>,(F f),<F>{f},F f;,(o{f,*k(v),H,k(v)}),(o{f,*k(v),H,Y(v)}),QY V s;QY Qv Q6;,{P it!=O.it;},{if(not Q6){s=f(s,*it);};Q6=QV;++it;P*Qe;},{if(not Q6){Q6=H;s=f(s,*it);}P s;}) z<X T,X S,X I=L(k(Qk<T>())),X J=L(k(Qk<S>()))>E d w+(T&&v,S&&u){Qx(I i;I i_end;J j;Qv in_i;,{P i!=O.i or j!=O.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=QV;}}Ql{++j;}P*Qe;},{P(in_i)?(*i):(*j);}) I bv=k(v);I ev=Y(v);J bu=k(u);J eu=Y(u);P QN(o{bv,ev,bu,bv!=ev},o{ev,ev,eu,QV});}W4 Z{Q2 Q1=M;z<X T>d w()(T&&v)R{d u=Qr<T>(v)>filter(FF(i,not is_nil(i)));d b=k(u);d e=Y(u);Q2 J=L(b);Q2 V=QL<L(*b)>;Q2 K=L(k(*b));Z o{J j;J Qm;Q4<V>Qa;K*Q7;Qv A;o(J j,J Qm,R V&jv,Qv A):j(j),Qm(Qm),Qa(new V(jv)),Q7(new K(k(*Qa))),A(A){} o(J j,J Qm,Qv A):j(j),Qm(Qm),Qa(nullptr),Q7(nullptr),A(A){} o(R o&O):j(O.j),Qm(O.Qm),Qa(O.Qa),Q7((O.Q7)?(new K(*O.Q7)):nullptr),A(O.A){} o(o&&O):j(O.j),Qm(O.Qm),Qa(O.Qa),Q7((O.Q7)?(new K(*O.Q7)):nullptr),A(O.A){}~o(){delete Q7;}Qv w!=(R o&O)R{P A xor O.A;}o&w++(){++*Q7;if(not(*Q7!=Y(*Qa))){++j;if(j!=Qm){delete Q7;Qa=std::make_shared<V>(*j);Q7=new K(k(*Qa));}Ql{A=H;}} P*Qe;}L(d)w*()R{P**Q7;}};if(u>is_nil){P QB(o(b,e,H),o(b,e,H));}Ql{P QB(o(b,e,*b,QV),o(e,e,H));}}}flatten;z<X T,X F,X=std::enable_if_t<is_iterable_v<T>>>d w>=(T&&v,F f){P v>Q3(f)>flatten;}z<X U,W...Is>E Qv all_different_(R U&x,R U&y,QW<Is...>){P((Qt<Is>(x)!=Qt<Is>(y))&&...);}z<X F,X...Ts>E d zip_with(F f,Ts&&...vs){Qx(F f;B<L(k(Qk<Ts>()))...>its;,{P all_different_(its,O.its,std::index_sequence_for<Ts...>{});},{QI([&](d&&...xs){(++xs,...);},its);P*Qe;},{P QI([&](d&&...xs){P f(*xs...);},its);}) P QN(o{f,B(k(vs)...)},o{f,B(Y(vs)...)});};Z zip_default_function_{z<X...Ts>L(d)w()(Ts&&...xs)R{P B<Ts...>(Qr<Ts>(xs)...);}};z<X...Ts>E d zip(Ts&&...vs){P zip_with(zip_default_function_{},Qr<Ts>(vs)...);}QM(filter,z<X F>,(F f),<F>{f},F f;,(o{f,Y(v),k(v)}),(o{f,Y(v),Y(v)}),R I end_it;E M QH()R{while(it!=end_it and not f(*it)){++it;}},{QH();O.QH();P it!=O.it;},{QH();++it;P*Qe;},{QH();P*it;}) def_template_lambda(z<X T>,repeat,(T&&v),{Z o{R QL<T>v;Qv w!=(R o&)R{P H;}o&w++(){P*Qe;}R d&w*()R{P v;}};P QN(o{v},o{v});})E d replicate(W n){P take(n)<repeat;}E d cycle=flatten<repeat;def_iterator_manip(enumerate,{P zip(to_infinity(W(0)),v);})def_iterator_manip(reversed,{d s=v>Qp;std::reverse(s.begin(),s.end());P iterc(Qo(s));})def_iterator_manip(sorted_by,z<X F>,(F f),<F>{f},F f;,{d s=v>Qp;std::sort(k(s),Y(s),f);P iterc(Qo(s));})def_iterator_manip(sorted,{P v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,z<X F>,(F f),<F>{f},F f;,{P v>Q3(FF(i,B(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>Q3(fst);})def_iterator_manip(nub,{Qx(I Qy;I it;,{P it!=O.it;},{L(*it)pr;do{pr=*it;++it;}while(it!=Qy and pr==*it);P*Qe;},{P*it;}) d b=k(v);d e=Y(v);P QN(o{e,b},o{e,e});})z<X F,X S>Z accum_vector_by_{Q2 Q1=M;W n;F f;S s;z<X T,X I=L(k(Qk<T>())),X V=QL<L(*Qk<I>())>>L(d)w()(R T&v)R{Qg<QL<QZ<F,S,L(Qt<1>(Qk<V>()))>>>u(n,s);for(d&&[i,x]:v){u[i]=f(u[i],x);}P u;}};z<X F,X S>E d accum_vector_by(W n,F f,R S&s){P accum_vector_by_<F,S>{n,f,s};}z<X S>E d accum_vector(W n,R S&s=S()){P accum_vector_by(n,_2,s);}z<X F,X S>Z accum_map_by_{Q2 Q1=M;F f;S s;z<X T,X I=L(k(Qk<T>())),X V=QL<L(*Qk<I>())>>L(d)w()(R T&v)R{std::map<QL<L(Qt<0>(Qk<V>()))>,QL<QZ<F,S,L(Qt<1>(Qk<V>()))>>>u;for(d&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Ql{u[i]=f(s,x);}} P u;}};z<X F,X S>E d accum_map_by(F f,R S&s){P accum_map_by_<F,S>{f,s};}z<X S>E d accum_map(R S&s=S()){P accum_map_by(_2,s);}z<X F,X S>Z accum_unordered_map_by_{Q2 Q1=M;F f;S s;z<X T,X I=L(k(Qk<T>())),X V=QL<L(*Qk<I>())>>L(d)w()(R T&v)R{std::unordered_map<QL<L(Qt<0>(Qk<V>()))>,QL<QZ<F,S,L(Qt<1>(Qk<V>()))>>>u;for(d&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Ql{u[i]=f(s,x);}} P u;}};z<X F,X S>E d accum_unordered_map_by(F f,R S&s){P accum_unordered_map_by_<F,S>{f,s};}z<X S>E d accum_unordered_map(R S&s=S()){P accum_unordered_map_by(_2,s);}z<X U,W...Is>E Qv any_different_(R U&x,R U&y,QW<Is...>){P((Qt<Is>(x)!=Qt<Is>(y))||...);}z<W N,X o>E M QT(o&it){if W4(N>=1){++Qt<N-1>(it.its);if(not(Qt<N-1>(it.its)!=Y(Qt<N-1>(*it.my_vs_ptr)))){Qt<N-1>(it.its)=k(Qt<N-1>(*it.my_vs_ptr));QT<N-1>(it);}} Ql{it.its=QI([](d&&...xs){P B(Y(xs)...);},*it.my_vs_ptr);}} z<X...Ts>d QO(Ts&&...vs){d Qu=std::make_shared<B<Qj<QC<Ts>,Qf<Ts>,Ts>...>>(vs...);Qx(B<L(k(Qk<Qj<QC<Ts>,Qf<Ts>,Ts>>()))...>its;L(Qu)my_vs_ptr;,{P any_different_(its,O.its,std::index_sequence_for<Ts...>{});},{QT<sizeof...(Ts)>(*Qe);P*Qe;},{P QI([](d&&...xs){P B<L(*xs)...>(*xs...);},its);}) if(QI([](d&&...xs){P((xs>is_nil)||...);},*Qu)){P QN(o{QI([](d&&...xs){P B(Y(xs)...);},*Qu),Qu},o{QI([](d&&...xs){P B(Y(xs)...);},*Qu),Qu});}Ql{P QN(o{QI([](d&&...xs){P B(k(xs)...);},*Qu),Qu},o{QI([](d&&...xs){P B(Y(xs)...);},*Qu),Qu});}};z<X...Ts>E d cartesian_product_range(R Ts&...n){P QO(QQ(n)...);}z<W n,X I>E d cartesian_power(R I&v){P QI([](R d&...vs){P QO(vs...);},tuple_many_of<n>(v));}Z{Q2 Q1=M;QF n=-1;z<X T>d w()(T&&v)R{if W4(std::is_convertible_v<T,QF>){d x=*Qe;x.n=v;P x;}Ql{d vec=v>Qp;QF m=vec.Q9();Z o{QF n;L(vec)QU;Qg<W>cycles;Qv A;Qv w!=(R o&O)R{P A xor O.A;}o&w++(){for(d i:QQ(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=QU.Q9()-i;std::rotate(QU.begin()+i,QU.begin()+i+1,QU.end());}Ql{std::swap(QU[i],QU[QU.Q9()-cycles[i]]);P*Qe;}} A=H;P*Qe;}d w*()R{P QU>array_slice(0,n);}};QF n1=(n<0)?(m):(n);P QN(o{n1,Qo(vec),QQ(m,m-n1,-1)>Q3(FF(x,W(x)))>Qp,QV},o{n1,{},{},H});}}}permutations;Z combinations_impl{Q2 Q1=M;QF n;z<X T>d w()(T&&v)R{d vec=v>Qp;QF m=vec.Q9();Qx(QF n;L(vec)QU;Qg<W>idx;Qv A;,{P A xor O.A;},{for(d i:QQ(n-1,-1,-1)){if(idx[i]!=idx.Q9()-n+i){idx[i]++;for(d j:QQ(i+1,n)){idx[j]=idx[j-1]+1;}P*Qe;}} A=H;P*Qe;},{P idx>array_slice(0,n)>Q3(FF(i,QU[i]));}) P QN(o{n,Qo(vec),QQ(0,m)>Q3(FF(x,W(x)))>Qp,QV},o{n,{},{},H});}};E d combinations(QF n){P combinations_impl{n};}Z QS{Q2 Q1=M;QF n;z<X T>d w()(T&&v)R{d vec=v>Qp;QF m=vec.Q9();Qx(QF n;L(vec)QU;Qg<W>idx;Qv A;,{P A xor O.A;},{for(d i:QQ(n-1,-1,-1)){if(idx[i]!=idx.Q9()-1){idx[i]++;for(d j:QQ(i+1,n)){idx[j]=idx[i];}P*Qe;}} A=H;P*Qe;},{P idx>array_slice(0,n)>Q3(FF(i,QU[i]));}) P QN(o{n,Qo(vec),W(0)>replicate(m)>Qp,QV},o{n,{},{},H});}};E d combinations_with_replacement(QF n){P QS{n};}z<X T>E d istream_iterable(std::istream&in){Qx(std::istream&in;QY T val;Qv A;QY Qv has_read;,{P A xor O.A;},{if(not(in>>val)){A=H;}P*Qe;},{if(not has_read){has_read=H;in>>val;}P val;}) P QN(o{in,T{},QV,QV},o{in,T{},H,H});}z<X T>E d input=istream_iterable<T>(std::cin);z<X T>QD&print_iterable(QD&out,R T&v,R std::string&sep= " "){for(d it=k(v);it!=Y(v);){ out<<*it;++it;if(it!=Y(v)){out<<sep;}Ql{P out;}} P out;}z<X T,X=X T::is_iterable_wrapper>E QD&w<<(QD&out,R T&v){out<< "[";P print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)z<X...Ts>QD&w<<(QD&out,R I<Ts...>&v){P out<<QN(v);}
Qi(Qg)Qi(std::map)Qi(std::unordered_map)Qi(std::set)Qi(std::unordered_set)z<W n,X T>Z W2{Q2 type=Qg<X W2<n-1,T>::type>;static d make(R Qh<n,W>&sz,R T&val=T()){P Qg(Qq(sz),W2<n-1,T>::make(Qz(sz),val));}};z<X T>Z W2<1,T>{Q2 type=Qg<T>;static d make(R B<W>&sz,R T&val=T()){P Qg(Qq(sz),val);}};z<W n,X T>Q2 nested_vector=X W2<n,T>::type;z<W n,X T>d make_nested_vector(R Qh<n,W>&sz,R T&val=T()){P W2<n,T>::make(sz,val);}z<W n,X T>E d Q0(R T&v){if W4(n==1){P B(v.Q9());}Ql{P std::tuple_cat(B(v.Q9()),Q0<n-1>(v[0]));}} z<W n,X T>E d nested_vector_indices(R T&v){P QI([&](d...x){P cartesian_product_range(x...);},Q0<n>(v));}z<W n,X T>E L(d)Qs(R Qg<T>&v,R Qh<n,W>&i){if W4(n==1){P v[Qq(i)];}Ql{P Qs<n-1>(v[Qq(i)],Qz(i));}} z<W n,X T>E L(d)Qs(Qg<T>&v,R Qh<n,W>&i){if W4(n==1){P v[Qq(i)];}Ql{P Qs<n-1>(v[Qq(i)],Qz(i));}} z<X U,W i,W s>QD&Qn(QD&out,R U&u){if W4(i==0){out<< "{ ";}out<<Qt<i>(u);if W4(i+1<s){out<< ", ";P Qn<U,i+1,s>(out,u);}Ql{P out<< " }";}} z<X...Ts>QD&w<<(QD&out,R B<Ts...>&u){P Qn<L(u),0,sizeof...(Ts)>(out,u);}z<X T,X S>QD&w<<(QD&out,R std::pair<T,S>&p){P out<<B(p.first,p.second);} 
#define BEGIN  QF main(){std::ios_base::sync_with_stdio(QV);std::cin.tie(0);std::cout.tie(0);
#define END }
Q2 namespace std;Q2 LL=long long;z<X T,X F>class sparse_table{private:W n;Qg<W>LOG2;F f;Qg<Qg<T>>st;Q_:explicit sparse_table(F f_):f(f_){} z<X I>M build(R I&v){st.emplace_back(v>Qp);n=st[0].Q9();LOG2.assign(n+1,0);for(d i:QQ(2,n+1)){LOG2[i]=LOG2[i/2]+1;}st.resize(LOG2[n]+1);for(d j:QQ(1,st.Q9())){st[j].resize(n-(1<<j)+1);for(d i:QQ(st[j].Q9())){st[j][i]=f(st[j-1][i],st[j-1][i+(1<<(j-1))]);}}}T QG(W l,W r)R{d j=LOG2[r-l];P f(st[j][l],st[j][r-(1<<j)]);}E W Q9()R{P n;}};z<X T,X F>d make_sparse_table(F f=F()){P sparse_table<T,F>(f);}z<X T,X F>class Qw{private:W n;Qg<W>LOG2;F f;Qg<Qg<T>>dst;Qg<T>a;Q_:explicit Qw(F f_):f(f_){} z<X I>M build(R I&v){a=v>Qp;n=a.Q9();LOG2.assign(2*n,0);for(d i:QQ(2,2*n)){LOG2[i]=LOG2[i/2]+1;}dst.resize(LOG2[n-1]+1,Qg<T>(n));for(d h:QQ(dst.Q9())){d half=1<<h;for(W i:QQ(half,n,2*half)){dst[h][i-1]=a[i-1];for(W j:QQ(i-1,i-half,-1)){dst[h][j-1]=f(a[j-1],dst[h][j]);}dst[h][i]=a[i];for(d j:QQ(i+1,minn(n,i+half))){dst[h][j]=f(dst[h][j-1],a[j]);}}}} T QG(W l,W r)R{--r;if(l==r){P a[l];}QF h=LOG2[l^r];P f(dst[h][l],dst[h][r]);}W Q9()R{P n;}};z<X T,X F>d QR(F f=F()){P Qw<T,F>(f);}R QF MOD=998244353;Z Val{LL a,b;};Z Operation{W4 static Val identity={1,0};static Val merge(R Val&x,R Val&y){P Val{(x.a*y.a)%MOD,(y.a*x.b+y.b)%MOD};}};LL fast_exp(LL b,QF e){LL ans=1;while(e){if(e&1){ans=(ans*b)%MOD;}e>>=1;b=(b*b)%MOD;}P ans;}BEGIN QF N,Q;cin>>N>>Q;set<QF>QK;QK.insert(0);QK.insert(N);d rt=QR<Val>(FF(x,y,(Val{(x.a*y.a)%MOD,(y.a*x.b+y.b)%MOD})));rt.build(input<LL>>take(N)>Q3(FF(p,(100*fast_exp(p,MOD-2))%MOD))>Q3(FF(x,(Val{x,x}))));d f=FF(x,x.b%MOD);LL ans=f(rt.QG(0,N));vector<Qv>is_c(N+1,0);is_c[0]=is_c[N]=1;while(Q--){QF u;cin>>u;--u;if(is_c[u]){is_c[u]=QV;QK.erase(u);d it=QK.lower_bound(u);QF j=*it;--it;QF i=*it;ans=(((ans-f(rt.QG(u,j))-f(rt.QG(i,u))+f(rt.QG(i,j)))%MOD)+MOD)%MOD;}Ql{d it=QK.lower_bound(u);QF j=*it;--it;QF i=*it;ans=(((ans-f(rt.QG(i,j))+f(rt.QG(i,u))+f(rt.QG(u,j)))%MOD)+MOD)%MOD;QK.insert(u);is_c[u]=H;}cout<<ans<< "\n";}END