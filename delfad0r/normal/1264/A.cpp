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
#define QV else
#define We std::invoke_result_t
#define Z std::begin
#define QC make_nested_vector
#define QE nested_vector_size
#define QW j_end
#define B inline
#define QX is_composable_
#define Wq prefix_table_nd
#define QZ is_iterable_v
#define Qz __expr1__
#define QG public
#define W2 cartesian_product_incr_
#define k const
#define QK std::apply
#define QY std::index_sequence
#define P return
#define O is_end
#define W0 std::tuple_element_t
#define Qm std::declval
#define Qn this
#define W9 __arg2__
#define W8 using
#define Y std::tuple
#define Qt Finv
#define W3 std::get
#define Qb std::enable_if_t
#define QL vs_ptr
#define a struct
#define Q4 constexpr
#define Ww internal_range_query
#define Qk def_iterator_manip_iter
#define W7 std::ostream
#define W6 def_iterable_ostream
#define Qv it_end
#define Qi GET_5TH_ARG
#define QJ range_query
#define W5 k_ptr
#define H other
#define Qw iter
#define E template
#define QU nested_vector_impl
#define Qq std::conditional_t
#define Q8 std::move
#define QH cartesian_product
#define Qc implicit_lambda_binary_operator
#define QM std::decay_t
#define W4 tuple_many_of_t
#define W void
#define z auto
#define QS tuple_head
#define QA has_updated
#define Q0 has_advanced
#define Qx finv_
#define QP iterable_wrapper
#define L decltype
#define QO std::vector
#define QF range
#define A operator
#define Q_ finv
#define o std::end
#define w Iterator
#define M typename
#define Qj int
#define Qu static
#define Q7 combinations_with_replacement_impl
#define Qh false
#define Q6 to_vector
#define W1 apply
#define Q1 my_v
#define Q2 nested_vector_at
#define QI std::forward
#define Q5 ostream_tuple_helper_
#define Qg advance
#define Qf to_nested_vector_impl
#define Qy __arg3__
#define Qd __tuple__
#define Qs std::remove_reference_t
#define Qr std::make_index_sequence
#define Qa std::shared_ptr
#define X size_t
#define R true
#define QN implicit_lambda_unary_operator
#define Qe std::is_rvalue_reference_v
#define QQ mutable
#define QB implicit_lambda
#define Ql bool
#define Qp iterator_macro
#define Qo container_carrying_iterator
#define Q3 tuple_tail
#define QT internal_build
#define QR jv_ptr
#define QD size
#define Q9 is_composable_v
#define Q __arg1__

E<M T,X>W8 ignore_second=T;E<X...Ix,M T>z tuple_many_of_impl(QY<Ix...>,k T&x){P Y(ignore_second<T,Ix>(x)...);}E<X n,M T>z tuple_many_of(k T&x){P tuple_many_of_impl(Qr<n>{},x);}E<X n,M T>W8 W4=L(tuple_many_of<n,T>(Qm<T>()));E<M...Args>z QS(k Y<Args...>&t){P W3<0>(t);}E<X...Ix,M...Args>z tuple_tail_impl(QY<Ix...>,k Y<Args...>&t){P Y(W3<Ix+1>(t)...);}E<M...Args>z Q3(k Y<Args...>&t){P tuple_tail_impl(Qr<sizeof...(Args)-1>{},t);}a empty_t{};Q4 empty_t empty_v;E<M T1,M T2>std::common_type_t<T1,T2>maxx(k T1&x,k T2&y){if(x<y){P y;}QV{P x;}} E<M T1,M T2,M...Ts>B z maxx(k T1&x,k T2&y,k Ts&...xs){P maxx(maxx(x,y),xs...);}E<M T1,M T2>z minn(k T1&x,k T2&y){if(x<=y){P x;}QV{P y;}} E<M T1,M T2,M...Ts>B z minn(k T1&x,k T2&y,k Ts&...xs){P minn(minn(x,y),xs...);}Q4 Qj _log2(Qj x){if(x==0){P 0;}P 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){P f;}
#define FF_1(Q,f)[&](z&&Q){(W)Q;P f;}
#define FF_2(Q,W9,f)[&](z&&Q,z&&W9){(W)Q;(W)W9;P f;}
#define FF_3(Q,W9,Qy,f)[&](z&&Q,z&&W9,z&&Qy){(W)Q;(W)W9;(W)Qy;P f;}
#define FF_macro_chooser(...)Qi(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->z&{P f;}
#define FREF_1(Q,f)[&](z&&Q)->z&{(W)Q;P f;}
#define FREF_2(Q,W9,f)[&](z&&Q,z&&W9)->z&{(W)Q;(W)W9;P f;}
#define FREF_3(Q,W9,Qy,f)[&](z&&Q,z&&W9,z&&Qy)->z&{(W)Q;(W)W9;(W)Qy;P f;}
#define FREF_macro_chooser(...)Qi(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){P f;}
#define FC_1(Q,f,c)[&,c](z&&Q){(W)Q;P f;}
#define FC_2(Q,W9,f,c)[&,c](z&&Q,z&&W9){(W)Q;(W)W9;P f;}
#define FC_macro_chooser(...)Qi(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){P f;}
#define FC2_1(Q,f,c1,c2)[&,c1,c2](z&&Q){(W)Q;P f;}
#define FC2_2(Q,W9,f,c1,c2)[&,c1,c2](z&&Q,z&&W9){(W)Q;(W)W9;P f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(Q,f)[&](z&&Qd){z&[Q]=Qd;(W)Q;P f;}
#define FT_2(Q,W9,f)[&](z&&Qd){z&[Q,W9]=Qd;(W)Q;(W)W9;P f;}
#define FT_3(Q,W9,Qy,f)[&](z&&Qd){z&[Q,W9,Qy]=Qd;(W)Q;(W)W9;(W)Qy;P f;}
#define FT_4(Q,W9,Qy,__arg4__,f)[&](z&&Qd){z&[Q,W9,Qy,__arg4__]=Qd;(W)Q;(W)W9;(W)Qy;(W)__arg4__;P f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Qz,f)[&](){z&&Qz;P f;}()
#define LET_2(Qz,__expr2__,f)[&](){z&&Qz;z&&__expr2__;P f;}()
#define LET_3(Qz,__expr2__,__expr3__,f)[&](){z&&Qz;z&&__expr2__;z&&__expr3__;P f;}()
#define LET_macro_chooser(...)Qi(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)Q4 a{W8 QX=W;templ B L(z)A()args k code}name;
E<M F>class QB{private:F f;QG:QB(F f_):f(f_){} E<M...Ts>Q4 z A()(Ts&&...xs)k{P f(QI<Ts>(xs)...);}};QB _([](z&&x)->Qq<Qe<L(x)>,Qs<L(x)>,L(x)>{P x;});QB _1([](z&&x,z&&)->Qq<Qe<L(x)>,Qs<L(x)>,L(x)>{P x;});QB _2([](z&&,z&&y)->Qq<Qe<L(y)>,Qs<L(y)>,L(y)>{P y;});
#define implicit_lambda_unary_operator(op)E<M F>Q4 L(z)A op(QB<F>f){P QB([=](z&&...xs){P op f(QI<L(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)E<M F,M T>Q4 L(z)A op(QB<F>f,k T&y){P QB([=](z&&...xs){P f(QI<L(xs)>(xs)...)op y;});}E<M F,M T>Q4 L(z)A op(k T&y,QB<F>f){P QB([=](z&&...xs){P y op f(QI<L(xs)>(xs)...);});}E<M F,M G>Q4 L(z)A op(QB<F>f,QB<G>g){P QB([=](z&&...xs){P f(QI<L(xs)>(xs)...)op g(QI<L(xs)>(xs)...);});}
QN(+)QN(-)QN(!)QN(~)QN(*)QN(&)Qc(+)Qc(-)Qc(*)Qc(/)Qc(%)Qc(<)Qc(>)Qc(<=)Qc(>=)Qc(==)Qc(!=)Qc(<<)Qc(>>)Qc(&)Qc(|)Qc(^)Qc(&&)E<M T,M=W>a is_composable:QG std::false_type{};E<M T>a is_composable<T,std::void_t<M T::is_composable_>>:QG std::true_type{};E<M T>Q4 Ql Q9=is_composable<T>::value;E<M T,M F,M=We<F,T>>L(z)A>(T&&v,k F&f){P f(QI<T>(v));}E<M M1,M M2>a composed{W8 QX=W;k M1 m1;k M2 m2;E<M T>L(z)A()(T&&v)k{P m1(m2(QI<T>(v)));}};E<M M1,M M2,M=Qb<Q9<M1>or Q9<M2>>>B z A<(k M1&m1,k M2&m2){P composed<M1,M2>{m1,m2};}E<X n>a nth_impl{W8 QX=W;E<M...Ts>Q4 W0<n,Y<Ts...>>&A()(Y<Ts...>&u)k{P W3<n>(u);}E<M...Ts>Q4 W0<n,Y<Ts...>>A()(Y<Ts...>&&u)k{P W3<n>(u);}E<M...Ts>Q4 k W0<n,Y<Ts...>>&A()(k Y<Ts...>&u)k{P W3<n>(u);}E<M...Ts>Q4 k W0<n,Y<Ts...>>A()(k Y<Ts...>&&u)k{P W3<n>(u);}};E<X n>Q4 nth_impl<n>nth;Q4 nth_impl<0>fst;Q4 nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)a w{extra Ql A!=(k w&H)k neq w&A++()incr L(z)A*()k val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,Qv,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{Qp(extra extra_it QQ I it;,neq_it,incr_it,val_it);P QP(it_begin,Qv);})
#define def_iterator_manip_2(name,code)Q4 a{W8 QX=W;E<M T,M I=L(Z(Qm<T>())),M V=QM<L(*Qm<I>())>>L(z)A()(T&&v)k code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ a name##_impl{W8 QX=W;extra E<M T,M I=L(Z(Qm<T>())),M V=QM<L(*Qm<I>())>>L(z)A()(T&&v)k code};templ B L(z)name args{P name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
E<M T,M=W>a is_iterable:QG std::false_type{};E<M T>a is_iterable<T,std::void_t<L(Z(Qm<T>())),L(o(Qm<T>()))>>:QG std::true_type{};E<M T>Q4 Ql QZ=is_iterable<T>::value;E<M I>B z QP(k I&b,k I&e){a Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
W8 is_iterable_wrapper=W;W8 iterator=I;W8 value_type=QM<L(*Qm<I>())>;
#pragma GCC diagnostic pop
I b,e;z begin()k{P b;}z end()k{P e;}};P Wrapper{b,e};}E<M T>B z Qw(T&&iterable){P QP(Z(QI<T>(iterable)),o(QI<T>(iterable)));}E<M I>B z Qw(k I&b,k I&e){P QP(b,e);}E<M C>a Qo:QG C::iterator{Qa<C>p;Qo(Qa<C>p_,M C::iterator it):C::iterator(it),p(p_){}};E<M C>B z iterc(C&&v){W8 D=QM<C>;Qa<D>p(new D(QI<C>(v)));P QP(Qo<D>{p,Z(*p)},Qo<D>{p,o(*p)});}E<M T>B z Qw(std::initializer_list<T>l){P iterc(QO<T>(l));}def_template_lambda(E<M T>,Q6,(T&&v),{QO<M QM<T>::value_type>s;for(z&&x:v){s.push_back(x);}P s;})E<X n>a Qf{E<M T>B Qu z make(T&&v){P QI<T>(v)>W1(FF(u,Qf<n-1>::make(u)))>Q6;}};E<>a Qf<1>{E<M T>B Qu z make(T&&v){P QI<T>(v)>Q6;}};E<X n>a to_nested_vector_{W8 QX=W;E<M T>B L(z)A()(T&&v)k{P Qf<n>::make(QI<T>(v));}};E<X n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(X l,X r),({l,r}),X l;X r;,{P Qw(Z(v)+l,Z(v)+r);})def_iterator_manip(is_nil,{P not(Z(v)!=o(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{X l=0;for(z i=Z(v);i!=o(v);++i){++l;}P l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
E<M T1,M T2,M T3,M T=std::make_signed_t<L(T1()+T2()+T3())>>B z QF(k T1&b,k T2&e,k T3&step){Qp(T x;T e;T step;B Ql O()k{P(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{P O()xor H.O();},{x+=step;P*Qn;},{P T(x);}) P Qw(w{b,e,step},w{e,e,step});}E<M T1,M T2>B z QF(k T1&b,k T2&e){P QF(b,e,L(T1()+T2())(1));}E<M T>B z QF(k T&e){P QF(T(),e,T(1));} 
#pragma GCC diagnostic pop
E<M T>B z to_infinity(k T&b=0,k T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
Qp(T x;T step;,{(W)H;P R;},{x+=step;P*Qn;},{P T(x);}) P Qw(w{b,step},w{b,step});
#pragma GCC diagnostic pop
}Qk(W1,E<M F>,(F f),<F>{f},F f;,(w{f,Z(v)}),(w{f,o(v)}),,{ P it!=H.it;},{++it;P*Qn;},{P f(*it);}) Qk(take,,(X n),{n},X n;,(w{n,Z(v)}),(w{0,o(v)}),,{ P n!=H.n;},{--n;if(n>0){++it;}P*Qn;},{P*it;}) Qk(take_while,E<M F>,(F f),<F>{f},F f;,(w{f,not(Z(v)!=o(v)and f(*Z(v))),Z(v)}),(w{f,R,o(v)}),Ql O;,{P O xor H.O;},{++it;if(not f(*it)){O=R;}P*Qn;},{P*it;}) Qk(drop,,(X n),{n},QQ X n;,(w{n,o(v),Z(v)}),(w{0,o(v),o(v)}),k I end_it;B W Qg()k{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{Qg();H.Qg();P it!=H.it;},{Qg();++it;P*Qn;},{Qg();P*it;}) Qk(drop_while,E<M F>,(F f),<F>{f},F f;,(w{f,o(v),Qh,Z(v)}),(w{f,o(v),R,o(v)}),k I end_it;QQ Ql Q0;B W Qg()k{if(not Q0){while(it!=end_it and f(*it)){++it;}Q0=R;}},{Qg();H.Qg();P it!=H.it;},{Qg();++it;P*Qn;},{Qg();P*it;}) def_iterator_manip(head,{P*Z(v);})B z tail=drop(1);B z at(X n){P head<drop(n);}Qk(cons,E<M S>,(S s),<S>{s},S s;,(w{s,R,Z(v)}),(w{s,Qh,o(v)}),Ql is_s;,{P is_s!=H.is_s or it!=H.it;},{if(is_s){is_s=Qh;}QV{++it;}P*Qn;},{P(is_s)?(s):(*it);}) def_iterator_manip(snoc,{z it=Z(v);z h=*it;++it;P Y(h,Qw(it,o(v)));})def_iterator_manip(split_at,,(X n),{n},X n;,{z it=Z(v);QO<T>u;for(z i:QF(n)){u.push_back(*it);++it;}P Y(iterc(Q8(u)),Qw(it,o(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
Qk(chunks_of,,(X n),{n},X n;,(w{n,{},Qh,o(v),Z(v)}),(w{n,{},Qh,o(v),o(v)}),QQ QO<V>u;QQ Ql QA;I Qv;W update()k{u.clear();QA=R;for(z i:QF(n)){if(it!=Qv){u.push_back(*it);++it;}QV{break;}}},{P it!=H.it;},{if(QA){QA=Qh;}QV{for(z i:QF(n)){if(it!=Qv){++it;}QV{break;}}}P*Qn;},{if(not QA){update();}P iterc(u);})
#pragma GCC diagnostic pop
E<M F,M S>a fold_impl{W8 QX=W;F f;S s;E<M T>z A()(k T&v)k{z x=s;for(z y:v){x=f(x,y);}P x;}};E<M F,M S>B z fold(F f,k S&s){P fold_impl<F,S>{f,s};}def_iterator_manip(fold1,E<M F>,(F f),<F>{f},F f;,{z u=v>snoc;P u>snd>fold(f,u>fst);})def_iterator_manip(sum,{P v>fold(_1+_2,V(0));})def_iterator_manip(product,{P v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,E<M F>,(F f),<F>{f},F f;,{P v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{P v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,E<M F>,(F f),<F>{f},F f;,{P v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,E<M F>,(F f),<F>{f},F f;,{P v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{P v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,E<M F>,(F f),<F>{f},F f;,{P v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})E<M F,M S>a scan_impl{W8 QX=W;F f;S s;E<M T,M I=L(Z(Qm<T>()))>L(z)A()(T&&v)k{Qp(F f;QQ S s;QQ Ql QA;Ql Q0;QQ I it;,{P it!=H.it;},{if(not QA){s=f(s,*it);};QA=Qh;if(Q0){++it;}QV{Q0=R;}P*Qn;},{if(not QA){QA=R;s=f(s,*it);}P s;}) P Qw(w{f,s,R,Qh,Z(QI<T>(v))},w{f,s,R,R,o(QI<T>(v))});}};E<M F,M S>B z scan(F f,k S&s){P scan_impl<F,S>{f,s};}Qk(scan1,E<M F>,(F f),<F>{f},F f;,(w{f,*Z(v),R,Z(v)}),(w{f,*Z(v),R,o(v)}),QQ V s;QQ Ql QA;,{P it!=H.it;},{if(not QA){s=f(s,*it);};QA=Qh;++it;P*Qn;},{if(not QA){QA=R;s=f(s,*it);}P s;}) E<M T,M S,M I=L(Z(Qm<T>())),M J=L(Z(Qm<S>()))>B z A+(T&&v,S&&u){Qp(I i;I i_end;J j;Ql in_i;,{P i!=H.i or j!=H.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=Qh;}}QV{++j;}P*Qn;},{P(in_i)?(*i):(*j);}) I bv=Z(v);I ev=o(v);J bu=Z(u);J eu=o(u);P Qw(w{bv,ev,bu,bv!=ev},w{ev,ev,eu,Qh});}Q4 a{W8 QX=W;E<M T>z A()(T&&v)k{z u=QI<T>(v)>filter(FF(i,not is_nil(i)));z b=Z(u);z e=o(u);W8 J=L(b);W8 V=QM<L(*b)>;W8 K=L(Z(*b));a w{J j;J QW;Qa<V>QR;K*W5;Ql O;w(J j,J QW,k V&jv,Ql O):j(j),QW(QW),QR(new V(jv)),W5(new K(Z(*QR))),O(O){} w(J j,J QW,Ql O):j(j),QW(QW),QR(nullptr),W5(nullptr),O(O){} w(k w&H):j(H.j),QW(H.QW),QR(H.QR),W5((H.W5)?(new K(*H.W5)):nullptr),O(H.O){} w(w&&H):j(H.j),QW(H.QW),QR(H.QR),W5((H.W5)?(new K(*H.W5)):nullptr),O(H.O){}~w(){delete W5;}Ql A!=(k w&H)k{P O xor H.O;}w&A++(){++*W5;if(not(*W5!=o(*QR))){++j;if(j!=QW){delete W5;QR=std::make_shared<V>(*j);W5=new K(Z(*QR));}QV{O=R;}} P*Qn;}L(z)A*()k{P**W5;}};if(u>is_nil){P QP(w(b,e,R),w(b,e,R));}QV{P QP(w(b,e,*b,Qh),w(e,e,R));}}}flatten;E<M T,M F,M=Qb<QZ<T>>>z A>=(T&&v,F f){P v>W1(f)>flatten;}E<M U,X...Is>B Ql all_different_(k U&x,k U&y,QY<Is...>){P((W3<Is>(x)!=W3<Is>(y))&&...);}E<M F,M...Ts>B z zip_with(F f,Ts&&...vs){Qp(F f;Y<L(Z(Qm<Ts>()))...>its;,{P all_different_(its,H.its,std::index_sequence_for<Ts...>{});},{QK([&](z&&...xs){(++xs,...);},its);P*Qn;},{P QK([&](z&&...xs){P f(*xs...);},its);}) P Qw(w{f,Y(Z(vs)...)},w{f,Y(o(vs)...)});};a zip_default_function_{E<M...Ts>L(z)A()(Ts&&...xs)k{P Y<Ts...>(QI<Ts>(xs)...);}};E<M...Ts>B z zip(Ts&&...vs){P zip_with(zip_default_function_{},QI<Ts>(vs)...);}Qk(filter,E<M F>,(F f),<F>{f},F f;,(w{f,o(v),Z(v)}),(w{f,o(v),o(v)}),k I end_it;B W Qg()k{while(it!=end_it and not f(*it)){++it;}},{Qg();H.Qg();P it!=H.it;},{Qg();++it;P*Qn;},{Qg();P*it;}) def_template_lambda(E<M T>,repeat,(T&&v),{a w{k QM<T>v;Ql A!=(k w&)k{P R;}w&A++(){P*Qn;}k z&A*()k{P v;}};P Qw(w{v},w{v});})B z replicate(X n){P take(n)<repeat;}B z cycle=flatten<repeat;def_iterator_manip(enumerate,{P zip(to_infinity(X(0)),v);})def_iterator_manip(reversed,{z s=v>Q6;std::reverse(s.begin(),s.end());P iterc(Q8(s));})def_iterator_manip(sorted_by,E<M F>,(F f),<F>{f},F f;,{z s=v>Q6;std::sort(Z(s),o(s),f);P iterc(Q8(s));})def_iterator_manip(sorted,{P v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,E<M F>,(F f),<F>{f},F f;,{P v>W1(FF(i,Y(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>W1(fst);})def_iterator_manip(nub,{Qp(I Qv;I it;,{P it!=H.it;},{L(*it)pr;do{pr=*it;++it;}while(it!=Qv and pr==*it);P*Qn;},{P*it;}) z b=Z(v);z e=o(v);P Qw(w{e,b},w{e,e});})E<M F,M S>a accum_vector_by_{W8 QX=W;X n;F f;S s;E<M T,M I=L(Z(Qm<T>())),M V=QM<L(*Qm<I>())>>L(z)A()(k T&v)k{QO<QM<We<F,S,L(W3<1>(Qm<V>()))>>>u(n,s);for(z&&[i,x]:v){u[i]=f(u[i],x);}P u;}};E<M F,M S>B z accum_vector_by(X n,F f,k S&s){P accum_vector_by_<F,S>{n,f,s};}E<M S>B z accum_vector(X n,k S&s=S()){P accum_vector_by(n,_2,s);}E<M F,M S>a accum_map_by_{W8 QX=W;F f;S s;E<M T,M I=L(Z(Qm<T>())),M V=QM<L(*Qm<I>())>>L(z)A()(k T&v)k{std::map<QM<L(W3<0>(Qm<V>()))>,QM<We<F,S,L(W3<1>(Qm<V>()))>>>u;for(z&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QV{u[i]=f(s,x);}} P u;}};E<M F,M S>B z accum_map_by(F f,k S&s){P accum_map_by_<F,S>{f,s};}E<M S>B z accum_map(k S&s=S()){P accum_map_by(_2,s);}E<M F,M S>a accum_unordered_map_by_{W8 QX=W;F f;S s;E<M T,M I=L(Z(Qm<T>())),M V=QM<L(*Qm<I>())>>L(z)A()(k T&v)k{std::unordered_map<QM<L(W3<0>(Qm<V>()))>,QM<We<F,S,L(W3<1>(Qm<V>()))>>>u;for(z&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}QV{u[i]=f(s,x);}} P u;}};E<M F,M S>B z accum_unordered_map_by(F f,k S&s){P accum_unordered_map_by_<F,S>{f,s};}E<M S>B z accum_unordered_map(k S&s=S()){P accum_unordered_map_by(_2,s);}E<M U,X...Is>B Ql any_different_(k U&x,k U&y,QY<Is...>){P((W3<Is>(x)!=W3<Is>(y))||...);}E<X N,M w>B W W2(w&it){if Q4(N>=1){++W3<N-1>(it.its);if(not(W3<N-1>(it.its)!=o(W3<N-1>(*it.my_vs_ptr)))){W3<N-1>(it.its)=Z(W3<N-1>(*it.my_vs_ptr));W2<N-1>(it);}} QV{it.its=QK([](z&&...xs){P Y(o(xs)...);},*it.my_vs_ptr);}} E<M...Ts>z QH(Ts&&...vs){z QL=std::make_shared<Y<Qq<Qe<Ts>,Qs<Ts>,Ts>...>>(vs...);Qp(Y<L(Z(Qm<Qq<Qe<Ts>,Qs<Ts>,Ts>>()))...>its;L(QL)my_vs_ptr;,{P any_different_(its,H.its,std::index_sequence_for<Ts...>{});},{W2<sizeof...(Ts)>(*Qn);P*Qn;},{P QK([](z&&...xs){P Y<L(*xs)...>(*xs...);},its);}) if(QK([](z&&...xs){P((xs>is_nil)||...);},*QL)){P Qw(w{QK([](z&&...xs){P Y(o(xs)...);},*QL),QL},w{QK([](z&&...xs){P Y(o(xs)...);},*QL),QL});}QV{P Qw(w{QK([](z&&...xs){P Y(Z(xs)...);},*QL),QL},w{QK([](z&&...xs){P Y(o(xs)...);},*QL),QL});}};E<M...Ts>B z cartesian_product_range(k Ts&...n){P QH(QF(n)...);}E<X n,M I>B z cartesian_power(k I&v){P QK([](k z&...vs){P QH(vs...);},tuple_many_of<n>(v));}a{W8 QX=W;Qj n=-1;E<M T>z A()(T&&v)k{if Q4(std::is_convertible_v<T,Qj>){z x=*Qn;x.n=v;P x;}QV{z vec=v>Q6;Qj m=vec.QD();a w{Qj n;L(vec)Q1;QO<X>cycles;Ql O;Ql A!=(k w&H)k{P O xor H.O;}w&A++(){for(z i:QF(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=Q1.QD()-i;std::rotate(Q1.begin()+i,Q1.begin()+i+1,Q1.end());}QV{std::swap(Q1[i],Q1[Q1.QD()-cycles[i]]);P*Qn;}} O=R;P*Qn;}z A*()k{P Q1>array_slice(0,n);}};Qj n1=(n<0)?(m):(n);P Qw(w{n1,Q8(vec),QF(m,m-n1,-1)>W1(FF(x,X(x)))>Q6,Qh},w{n1,{},{},R});}}}permutations;a combinations_impl{W8 QX=W;Qj n;E<M T>z A()(T&&v)k{z vec=v>Q6;Qj m=vec.QD();Qp(Qj n;L(vec)Q1;QO<X>idx;Ql O;,{P O xor H.O;},{for(z i:QF(n-1,-1,-1)){if(idx[i]!=idx.QD()-n+i){idx[i]++;for(z j:QF(i+1,n)){idx[j]=idx[j-1]+1;}P*Qn;}} O=R;P*Qn;},{P idx>array_slice(0,n)>W1(FF(i,Q1[i]));}) P Qw(w{n,Q8(vec),QF(0,m)>W1(FF(x,X(x)))>Q6,Qh},w{n,{},{},R});}};B z combinations(Qj n){P combinations_impl{n};}a Q7{W8 QX=W;Qj n;E<M T>z A()(T&&v)k{z vec=v>Q6;Qj m=vec.QD();Qp(Qj n;L(vec)Q1;QO<X>idx;Ql O;,{P O xor H.O;},{for(z i:QF(n-1,-1,-1)){if(idx[i]!=idx.QD()-1){idx[i]++;for(z j:QF(i+1,n)){idx[j]=idx[i];}P*Qn;}} O=R;P*Qn;},{P idx>array_slice(0,n)>W1(FF(i,Q1[i]));}) P Qw(w{n,Q8(vec),X(0)>replicate(m)>Q6,Qh},w{n,{},{},R});}};B z combinations_with_replacement(Qj n){P Q7{n};}E<M T>B z istream_iterable(std::istream&in){Qp(std::istream&in;QQ T val;Ql O;QQ Ql has_read;,{P O xor H.O;},{if(not(in>>val)){O=R;}P*Qn;},{if(not has_read){has_read=R;in>>val;}P val;}) P Qw(w{in,T{},Qh,Qh},w{in,T{},R,R});}E<M T>B z input=istream_iterable<T>(std::cin);E<M T>W7&print_iterable(W7&out,k T&v,k std::string&sep= " "){for(z it=Z(v);it!=o(v);){ out<<*it;++it;if(it!=o(v)){out<<sep;}QV{P out;}} P out;}E<M T,M=M T::is_iterable_wrapper>B W7&A<<(W7&out,k T&v){out<< "[";P print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)E<M...Ts>W7&A<<(W7&out,k I<Ts...>&v){P out<<Qw(v);}
W6(QO)W6(std::map)W6(std::unordered_map)W6(std::set)W6(std::unordered_set)E<X n,M T>a QU{W8 type=QO<M QU<n-1,T>::type>;Qu z make(k W4<n,X>&sz,k T&val=T()){P QO(QS(sz),QU<n-1,T>::make(Q3(sz),val));}};E<M T>a QU<1,T>{W8 type=QO<T>;Qu z make(k Y<X>&sz,k T&val=T()){P QO(QS(sz),val);}};E<X n,M T>W8 nested_vector=M QU<n,T>::type;E<X n,M T>z QC(k W4<n,X>&sz,k T&val=T()){P QU<n,T>::make(sz,val);}E<X n,M T>B z QE(k T&v){if Q4(n==1){P Y(v.QD());}QV{P std::tuple_cat(Y(v.QD()),QE<n-1>(v[0]));}} E<X n,M T>B z nested_vector_indices(k T&v){P QK([&](z...x){P cartesian_product_range(x...);},QE<n>(v));}E<X n,M T>B L(z)Q2(k QO<T>&v,k W4<n,X>&i){if Q4(n==1){P v[QS(i)];}QV{P Q2<n-1>(v[QS(i)],Q3(i));}} E<X n,M T>B L(z)Q2(QO<T>&v,k W4<n,X>&i){if Q4(n==1){P v[QS(i)];}QV{P Q2<n-1>(v[QS(i)],Q3(i));}} E<M U,X i,X s>W7&Q5(W7&out,k U&u){if Q4(i==0){out<< "{ ";}out<<W3<i>(u);if Q4(i+1<s){out<< ", ";P Q5<U,i+1,s>(out,u);}QV{P out<< " }";}} E<M...Ts>W7&A<<(W7&out,k Y<Ts...>&u){P Q5<L(u),0,sizeof...(Ts)>(out,u);}E<M T,M S>W7&A<<(W7&out,k std::pair<T,S>&p){P out<<Y(p.first,p.second);} 
#define BEGIN  Qj main(){std::ios_base::sync_with_stdio(Qh);std::cin.tie(0);std::cout.tie(0);
#define END }
W8 namespace std;W8 LL=long long;E<X d,M T,M F,M Qt>class Wq{friend class Wq<d+1,T,F,Qt>;private:F f;Qt Q_;T id;W4<d,X>n;nested_vector<d,T>pt;E<M I>B Qu W QT(nested_vector<d,T>&p,k I&v,F f_){for(z[i,j]:zip(p>tail,v)){Wq<d-1,T,F,Qt>::internal_build(i,j,f_);}for(z i:nested_vector_indices<d-1>(p[0])){for(z j:QF(1,p.QD())){Q2<d-1>(p[j],i)=f_(Q2<d-1>(p[j-1],i),Q2<d-1>(p[j],i));}}}E<M I>B Qu T Ww(k W4<d,X>&l,k W4<d,X>&r,k I&v,Qt Qx){P Qx(Wq<d-1,T,F,Qt>::internal_range_query(Q3(l),Q3(r),v[QS(r)],Qx),Wq<d-1,T,F,Qt>::internal_range_query(Q3(l),Q3(r),v[QS(l)],Qx));}QG:Wq(F f_,Qt Qx,k T&id_):f(f_),Q_(Qx),id(id_){} Wq(k W4<d,X>&n_,F f_,Qt Qx,k T&id_):f(f_),Q_(Qx),id(id_),n(n_),pt(QC<d,T>(QK([](z...x){P Y((x+1)...);},n),id)){} E<M J,M=Qb<QZ<J>>>Wq(k W4<d,X>&n_,k J&v,F f_,Qt Qx,k T&id_):f(f_),Q_(Qx),id(id_){build(n_,v);}E<M I>W build(k W4<d,X>&n_,k I&v){n=n_;pt=QC<d,T>(QK([](z...x){P Y((x+1)...);},n),id);QT(pt,v,f);}B T QJ(k W4<d,X>&l,k W4<d,X>&r)k{P Ww(l,r,pt,Q_);}B z QD()k{P n;}};E<M T,M F,M Qt>class Wq<1,T,F,Qt>{friend class Wq<2,T,F,Qt>;private:F f;Qt Q_;T id;X n;QO<T>pt;E<M I>B Qu W QT(QO<T>&p,k I&v,F f_){for(z[i,j]:zip(p>tail,v)){i=j;}for(z i:QF(1,p.QD())){p[i]=f_(p[i-1],p[i]);}} E<M I>B Qu T Ww(k Y<X>&l,k Y<X>&r,k I&v,Qt Qx){P Qx(v[QS(r)],v[QS(l)]);}QG:Wq(F f_,Qt Qx,k T&id_):f(f_),Q_(Qx),id(id_){} Wq(k Y<X>&n_,F f_,Qt Qx,k T&id_):f(f_),Q_(Qx),id(id_),n(QS(n_)),pt(n,id){} E<M J,M=Qb<QZ<J>>>Wq(k Y<X>&n_,k J&v,F f_,Qt Qx,k T&id_):f(f_),Q_(Qx),id(id_){build(n_,v);}E<M I>W build(k Y<X>&n_,k I&v){n=QS(n_);pt=QO(n+1,id);QT(pt,v,f);}B T QJ(k Y<X>&l,k Y<X>&r)k{P Ww(l,r,pt,Q_);}B T QJ(X l,X r)k{P QJ(Y(l),Y(r));}B z QD()k{P n;}};E<X d,M T,M F=std::plus<T>,M Qt=std::minus<T>>z make_prefix_table_nd(F f=F(),Qt Q_=Qt(),k T&id=T{}){P Wq<d,T,F,Qt>(f,Q_,id);}E<M T,M F=std::plus<T>,M Qt=std::minus<T>>z make_prefix_table(F f=F(),Qt Q_=Qt(),k T&id=T{}){P Wq<1,T,F,Qt>(f,Q_,id);}W solve(){Qj N;cin>>N;z p=input<Qj>>take(N)>Q6;vector<tuple<Qj,Qj>>q;for(z x:p){if(q.empty()or(q.back()>fst)!=x){q.emplace_back(x,1);}QV{get<1>(q.back())++;}} z r=q>W1(snd)>Q6;z rt=make_prefix_table<Qj>();rt.build(r.QD(),r);Qj lo=0,hi=r.QD();while(lo+1<hi){Qj m=(lo+hi)/2;if(rt.QJ(0,m)<=N/2){lo=m;}QV{hi=m;}} Qj b=lo;Qj g=1;z g_cnt=rt.QJ(0,g);if(rt.QJ(g,r.QD())<=g_cnt){cout<< "0 0 0\n";P;}lo=g,hi=rt.QD();while(lo+1<hi){Qj m=(lo+hi)/2;if(rt.QJ(g,m)>g_cnt){hi=m;}QV{lo=m;}} Qj s=hi;Qj s_cnt=rt.QJ(g,s);if(b<=s or rt.QJ(s,b)<=g_cnt){cout<< "0 0 0\n";P;}cout<<g_cnt<< " " <<s_cnt<< " " <<rt.QJ(s,b)<< "\n";}BEGIN Qj T;cin>>T;while(T--){solve();}END