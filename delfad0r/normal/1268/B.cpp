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
#define QB combinations_with_replacement_impl
#define Q8 advance
#define Q6 it_end
#define Qv std::decay_t
#define Qc mutable
#define QU std::forward
#define R other
#define z __arg1__
#define Q7 __arg3__
#define k template
#define E std::begin
#define A struct
#define QQ implicit_lambda
#define QA implicit_lambda_unary_operator
#define Q3 GET_5TH_ARG
#define Qs nested_vector_impl
#define Q decltype
#define Y std::end
#define Qu def_iterable_ostream
#define M is_end
#define Qe constexpr
#define QI this
#define P size_t
#define W return
#define QH container_carrying_iterator
#define Qw bool
#define Q2 std::ostream
#define Qb std::is_rvalue_reference_v
#define QZ has_advanced
#define Ql jv_ptr
#define o Iterator
#define B true
#define Qt k_ptr
#define Qp std::vector
#define Qo std::conditional_t
#define QK __tuple__
#define QO j_end
#define X std::tuple
#define QT __arg2__
#define Qi def_iterator_manip_iter
#define H operator
#define QR std::index_sequence
#define Qz vs_ptr
#define d auto
#define Q4 range
#define QL ostream_tuple_helper_
#define QS std::apply
#define QP std::invoke_result_t
#define QV is_composable_
#define Qk cartesian_product
#define Q0 tuple_many_of_t
#define QG to_vector
#define Qq iterator_macro
#define q void
#define Q5 apply
#define Qx tuple_head
#define QE my_v
#define Qj __expr1__
#define QW nested_vector_at
#define O const
#define Z inline
#define QY iter
#define Qa to_nested_vector_impl
#define QC cartesian_product_incr_
#define Qh is_composable_v
#define Qy using
#define QF has_updated
#define Q9 iterable_wrapper
#define QD std::shared_ptr
#define Qr std::move
#define L typename
#define QJ std::remove_reference_t
#define Qd std::get
#define Qg nested_vector_size
#define Qm implicit_lambda_binary_operator
#define Qf std::declval
#define QX false
#define Q1 else
#define Qn std::tuple_element_t

k<L T,P>Qy ignore_second=T;k<P...Ix,L T>d tuple_many_of_impl(QR<Ix...>,O T&x){W X(ignore_second<T,Ix>(x)...);}k<P n,L T>d tuple_many_of(O T&x){W tuple_many_of_impl(std::make_index_sequence<n>{},x);}k<P n,L T>Qy Q0=Q(tuple_many_of<n,T>(Qf<T>()));k<L...Args>d Qx(O X<Args...>&t){W Qd<0>(t);}k<P...Ix,L...Args>d tuple_tail_impl(QR<Ix...>,O X<Args...>&t){W X(Qd<Ix+1>(t)...);}k<L...Args>d tuple_tail(O X<Args...>&t){W tuple_tail_impl(std::make_index_sequence<sizeof...(Args)-1>{},t);}A empty_t{};Qe empty_t empty_v;k<L T1,L T2>std::common_type_t<T1,T2>maxx(O T1&x,O T2&y){if(x<y){W y;}Q1{W x;}} k<L T1,L T2,L...Ts>Z d maxx(O T1&x,O T2&y,O Ts&...xs){W maxx(maxx(x,y),xs...);}k<L T1,L T2>d minn(O T1&x,O T2&y){if(x<=y){W x;}Q1{W y;}} k<L T1,L T2,L...Ts>Z d minn(O T1&x,O T2&y,O Ts&...xs){W minn(minn(x,y),xs...);}Qe int _log2(int x){if(x==0){W 0;}W 31^__builtin_clz(x);} 
#define GET_4TH_ARG(arg1,arg2,arg3,arg4,...)arg4
#define GET_5TH_ARG(arg1,arg2,arg3,arg4,arg5,...)arg5
#define GET_6TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,...)arg6
#define FF_0(f)[&](){W f;}
#define FF_1(z,f)[&](d&&z){(q)z;W f;}
#define FF_2(z,QT,f)[&](d&&z,d&&QT){(q)z;(q)QT;W f;}
#define FF_3(z,QT,Q7,f)[&](d&&z,d&&QT,d&&Q7){(q)z;(q)QT;(q)Q7;W f;}
#define FF_macro_chooser(...)Q3(__VA_ARGS__,FF_3,FF_2,FF_1,FF_0)
#define FF(...)(FF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FREF_0(f)[&]()->d&{W f;}
#define FREF_1(z,f)[&](d&&z)->d&{(q)z;W f;}
#define FREF_2(z,QT,f)[&](d&&z,d&&QT)->d&{(q)z;(q)QT;W f;}
#define FREF_3(z,QT,Q7,f)[&](d&&z,d&&QT,d&&Q7)->d&{(q)z;(q)QT;(q)Q7;W f;}
#define FREF_macro_chooser(...)Q3(__VA_ARGS__,FREF_3,FREF_2,FREF_1,FREF_0)
#define FREF(...)(FREF_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC_0(f,c)[&,c](){W f;}
#define FC_1(z,f,c)[&,c](d&&z){(q)z;W f;}
#define FC_2(z,QT,f,c)[&,c](d&&z,d&&QT){(q)z;(q)QT;W f;}
#define FC_macro_chooser(...)Q3(__VA_ARGS__,FC_2,FC_1,FC_0)
#define FC(...)(FC_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FC2_0(f,c1,c2)[&,c1,c2](){W f;}
#define FC2_1(z,f,c1,c2)[&,c1,c2](d&&z){(q)z;W f;}
#define FC2_2(z,QT,f,c1,c2)[&,c1,c2](d&&z,d&&QT){(q)z;(q)QT;W f;}
#define FC2_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FC2_2,FC2_1,FC2_0)
#define FC2(...)(FC2_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define FT_1(z,f)[&](d&&QK){d&[z]=QK;(q)z;W f;}
#define FT_2(z,QT,f)[&](d&&QK){d&[z,QT]=QK;(q)z;(q)QT;W f;}
#define FT_3(z,QT,Q7,f)[&](d&&QK){d&[z,QT,Q7]=QK;(q)z;(q)QT;(q)Q7;W f;}
#define FT_4(z,QT,Q7,__arg4__,f)[&](d&&QK){d&[z,QT,Q7,__arg4__]=QK;(q)z;(q)QT;(q)Q7;(q)__arg4__;W f;}
#define FT_macro_chooser(...)GET_6TH_ARG(__VA_ARGS__,FT_4,FT_3,FT_2,FT_1)
#define FT(...)(FT_macro_chooser(__VA_ARGS__)(__VA_ARGS__))
#define LET_1(Qj,f)[&](){d&&Qj;W f;}()
#define LET_2(Qj,__expr2__,f)[&](){d&&Qj;d&&__expr2__;W f;}()
#define LET_3(Qj,__expr2__,__expr3__,f)[&](){d&&Qj;d&&__expr2__;d&&__expr3__;W f;}()
#define LET_macro_chooser(...)Q3(__VA_ARGS__,LET_3,LET_2,LET_1)
#define LET(...)LET_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ,name,args,code)Qe A{Qy QV=q;templ Z Q(d)H()args O code}name;
k<L F>class QQ{private:F f;public:QQ(F f_):f(f_){} k<L...Ts>Qe d H()(Ts&&...xs)O{W f(QU<Ts>(xs)...);}};QQ _([](d&&x)->Qo<Qb<Q(x)>,QJ<Q(x)>,Q(x)>{W x;});QQ _1([](d&&x,d&&)->Qo<Qb<Q(x)>,QJ<Q(x)>,Q(x)>{W x;});QQ _2([](d&&,d&&y)->Qo<Qb<Q(y)>,QJ<Q(y)>,Q(y)>{W y;});
#define implicit_lambda_unary_operator(op)k<L F>Qe Q(d)H op(QQ<F>f){W QQ([=](d&&...xs){W op f(QU<Q(xs)>(xs)...);});}
#define implicit_lambda_binary_operator(op)k<L F,L T>Qe Q(d)H op(QQ<F>f,O T&y){W QQ([=](d&&...xs){W f(QU<Q(xs)>(xs)...)op y;});}k<L F,L T>Qe Q(d)H op(O T&y,QQ<F>f){W QQ([=](d&&...xs){W y op f(QU<Q(xs)>(xs)...);});}k<L F,L G>Qe Q(d)H op(QQ<F>f,QQ<G>g){W QQ([=](d&&...xs){W f(QU<Q(xs)>(xs)...)op g(QU<Q(xs)>(xs)...);});}
QA(+)QA(-)QA(!)QA(~)QA(*)QA(&)Qm(+)Qm(-)Qm(*)Qm(/)Qm(%)Qm(<)Qm(>)Qm(<=)Qm(>=)Qm(==)Qm(!=)Qm(<<)Qm(>>)Qm(&)Qm(|)Qm(^)Qm(&&)k<L T,L=q>A is_composable:public std::false_type{};k<L T>A is_composable<T,std::void_t<L T::is_composable_>>:public std::true_type{};k<L T>Qe Qw Qh=is_composable<T>::value;k<L T,L F,L=QP<F,T>>Q(d)H>(T&&v,O F&f){W f(QU<T>(v));}k<L M1,L M2>A composed{Qy QV=q;O M1 m1;O M2 m2;k<L T>Q(d)H()(T&&v)O{W m1(m2(QU<T>(v)));}};k<L M1,L M2,L=std::enable_if_t<Qh<M1>or Qh<M2>>>Z d H<(O M1&m1,O M2&m2){W composed<M1,M2>{m1,m2};}k<P n>A nth_impl{Qy QV=q;k<L...Ts>Qe Qn<n,X<Ts...>>&H()(X<Ts...>&u)O{W Qd<n>(u);}k<L...Ts>Qe Qn<n,X<Ts...>>H()(X<Ts...>&&u)O{W Qd<n>(u);}k<L...Ts>Qe O Qn<n,X<Ts...>>&H()(O X<Ts...>&u)O{W Qd<n>(u);}k<L...Ts>Qe O Qn<n,X<Ts...>>H()(O X<Ts...>&&u)O{W Qd<n>(u);}};k<P n>Qe nth_impl<n>nth;Qe nth_impl<0>fst;Qe nth_impl<1>snd;
#define GET_7TH_ARG(arg1,arg2,arg3,arg4,arg5,arg6,arg7,...)arg7
#define iterator_macro(extra,neq,incr,val)A o{extra Qw H!=(O o&R)O neq o&H++()incr Q(d)H*()O val};
#define def_iterator_manip_iter(name,templ,args,args_,extra,it_begin,Q6,extra_it,neq_it,incr_it,val_it)def_iterator_manip(name,templ,args,args_,extra,{Qq(extra extra_it Qc I it;,neq_it,incr_it,val_it);W Q9(it_begin,Q6);})
#define def_iterator_manip_2(name,code)Qe A{Qy QV=q;k<L T,L I=Q(E(Qf<T>())),L V=Qv<Q(*Qf<I>())>>Q(d)H()(T&&v)O code}name;
#define def_iterator_manip_6(name,templ,args,args_,extra,code)templ A name##_impl{Qy QV=q;extra k<L T,L I=Q(E(Qf<T>())),L V=Qv<Q(*Qf<I>())>>Q(d)H()(T&&v)O code};templ Z Q(d)name args{W name##_impl args_;}
#define def_iterator_manip_chooser(...)GET_7TH_ARG(__VA_ARGS__,def_iterator_manip_6,,,,def_iterator_manip_2)
#define def_iterator_manip(...)def_iterator_manip_chooser(__VA_ARGS__)(__VA_ARGS__)
k<L T,L=q>A is_iterable:public std::false_type{};k<L T>A is_iterable<T,std::void_t<Q(E(Qf<T>())),Q(Y(Qf<T>()))>>:public std::true_type{};k<L T>Qe Qw is_iterable_v=is_iterable<T>::value;k<L I>Z d Q9(O I&b,O I&e){A Wrapper{ 
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
Qy is_iterable_wrapper=q;Qy iterator=I;Qy value_type=Qv<Q(*Qf<I>())>;
#pragma GCC diagnostic pop
I b,e;d begin()O{W b;}d end()O{W e;}};W Wrapper{b,e};}k<L T>Z d QY(T&&iterable){W Q9(E(QU<T>(iterable)),Y(QU<T>(iterable)));}k<L I>Z d QY(O I&b,O I&e){W Q9(b,e);}k<L C>A QH:public C::iterator{QD<C>p;QH(QD<C>p_,L C::iterator it):C::iterator(it),p(p_){}};k<L C>Z d iterc(C&&v){Qy D=Qv<C>;QD<D>p(new D(QU<C>(v)));W Q9(QH<D>{p,E(*p)},QH<D>{p,Y(*p)});}k<L T>Z d QY(std::initializer_list<T>l){W iterc(Qp<T>(l));}def_template_lambda(k<L T>,QG,(T&&v),{Qp<L Qv<T>::value_type>s;for(d&&x:v){s.push_back(x);}W s;})k<P n>A Qa{k<L T>Z static d make(T&&v){W QU<T>(v)>Q5(FF(u,Qa<n-1>::make(u)))>QG;}};k<>A Qa<1>{k<L T>Z static d make(T&&v){W QU<T>(v)>QG;}};k<P n>A to_nested_vector_{Qy QV=q;k<L T>Z Q(d)H()(T&&v)O{W Qa<n>::make(QU<T>(v));}};k<P n>to_nested_vector_<n>to_nested_vector;def_iterator_manip(array_slice,,(P l,P r),({l,r}),P l;P r;,{W QY(E(v)+l,E(v)+r);})def_iterator_manip(is_nil,{W not(E(v)!=Y(v));});
#pragma GCC diagnostic ignored "-Wunused-variable"
def_iterator_manip(length,{P l=0;for(d i=E(v);i!=Y(v);++i){++l;}W l;});
#pragma GCC diagnostic pop
#pragma GCC diagnostic ignored "-Wnarrowing"
k<L T1,L T2,L T3,L T=std::make_signed_t<Q(T1()+T2()+T3())>>Z d Q4(O T1&b,O T2&e,O T3&step){Qq(T x;T e;T step;Z Qw M()O{W(step>=T(0)and x>=e)or(step<T(0)and x<=e);},{W M()xor R.M();},{x+=step;W*QI;},{W T(x);}) W QY(o{b,e,step},o{e,e,step});}k<L T1,L T2>Z d Q4(O T1&b,O T2&e){W Q4(b,e,Q(T1()+T2())(1));}k<L T>Z d Q4(O T&e){W Q4(T(),e,T(1));} 
#pragma GCC diagnostic pop
k<L T>Z d to_infinity(O T&b=0,O T&step=1){ 
#pragma GCC diagnostic ignored "-Wunused-variable"
Qq(T x;T step;,{(q)R;W B;},{x+=step;W*QI;},{W T(x);}) W QY(o{b,step},o{b,step});
#pragma GCC diagnostic pop
}Qi(Q5,k<L F>,(F f),<F>{f},F f;,(o{f,E(v)}),(o{f,Y(v)}),,{ W it!=R.it;},{++it;W*QI;},{W f(*it);}) Qi(take,,(P n),{n},P n;,(o{n,E(v)}),(o{0,Y(v)}),,{ W n!=R.n;},{--n;if(n>0){++it;}W*QI;},{W*it;}) Qi(take_while,k<L F>,(F f),<F>{f},F f;,(o{f,not(E(v)!=Y(v)and f(*E(v))),E(v)}),(o{f,B,Y(v)}),Qw M;,{W M xor R.M;},{++it;if(not f(*it)){M=B;}W*QI;},{W*it;}) Qi(drop,,(P n),{n},Qc P n;,(o{n,Y(v),E(v)}),(o{0,Y(v),Y(v)}),O I end_it;Z q Q8()O{while(n>0){if(not(it!=end_it)){n=0;break;}--n;++it;}},{Q8();R.Q8();W it!=R.it;},{Q8();++it;W*QI;},{Q8();W*it;}) Qi(drop_while,k<L F>,(F f),<F>{f},F f;,(o{f,Y(v),QX,E(v)}),(o{f,Y(v),B,Y(v)}),O I end_it;Qc Qw QZ;Z q Q8()O{if(not QZ){while(it!=end_it and f(*it)){++it;}QZ=B;}},{Q8();R.Q8();W it!=R.it;},{Q8();++it;W*QI;},{Q8();W*it;}) def_iterator_manip(head,{W*E(v);})Z d tail=drop(1);Z d at(P n){W head<drop(n);}Qi(cons,k<L S>,(S s),<S>{s},S s;,(o{s,B,E(v)}),(o{s,QX,Y(v)}),Qw is_s;,{W is_s!=R.is_s or it!=R.it;},{if(is_s){is_s=QX;}Q1{++it;}W*QI;},{W(is_s)?(s):(*it);}) def_iterator_manip(snoc,{d it=E(v);d h=*it;++it;W X(h,QY(it,Y(v)));})def_iterator_manip(split_at,,(P n),{n},P n;,{d it=E(v);Qp<T>u;for(d i:Q4(n)){u.push_back(*it);++it;}W X(iterc(Qr(u)),QY(it,Y(v)));})
#pragma GCC diagnostic ignored "-Wunused-variable"
Qi(chunks_of,,(P n),{n},P n;,(o{n,{},QX,Y(v),E(v)}),(o{n,{},QX,Y(v),Y(v)}),Qc Qp<V>u;Qc Qw QF;I Q6;q update()O{u.clear();QF=B;for(d i:Q4(n)){if(it!=Q6){u.push_back(*it);++it;}Q1{break;}}},{W it!=R.it;},{if(QF){QF=QX;}Q1{for(d i:Q4(n)){if(it!=Q6){++it;}Q1{break;}}}W*QI;},{if(not QF){update();}W iterc(u);})
#pragma GCC diagnostic pop
k<L F,L S>A fold_impl{Qy QV=q;F f;S s;k<L T>d H()(O T&v)O{d x=s;for(d y:v){x=f(x,y);}W x;}};k<L F,L S>Z d fold(F f,O S&s){W fold_impl<F,S>{f,s};}def_iterator_manip(fold1,k<L F>,(F f),<F>{f},F f;,{d u=v>snoc;W u>snd>fold(f,u>fst);})def_iterator_manip(sum,{W v>fold(_1+_2,V(0));})def_iterator_manip(product,{W v>fold(_1*_2,V(1));})def_iterator_manip(maximum_by,k<L F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(x,y))?(y):(x)));})def_iterator_manip(maximum,{W v>maximum_by(_1<_2);})def_iterator_manip(maximum_on,k<L F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(x)<f(y))?(y):(x)));})def_iterator_manip(minimum_by,k<L F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(y,x))?(y):(x)));})def_iterator_manip(minimum,{W v>minimum_by(_1<_2);})def_iterator_manip(minimum_on,k<L F>,(F f),<F>{f},F f;,{W v>fold1(FF(x,y,(f(y)<f(x))?(y):(x)));})k<L F,L S>A scan_impl{Qy QV=q;F f;S s;k<L T,L I=Q(E(Qf<T>()))>Q(d)H()(T&&v)O{Qq(F f;Qc S s;Qc Qw QF;Qw QZ;Qc I it;,{W it!=R.it;},{if(not QF){s=f(s,*it);};QF=QX;if(QZ){++it;}Q1{QZ=B;}W*QI;},{if(not QF){QF=B;s=f(s,*it);}W s;}) W QY(o{f,s,B,QX,E(QU<T>(v))},o{f,s,B,B,Y(QU<T>(v))});}};k<L F,L S>Z d scan(F f,O S&s){W scan_impl<F,S>{f,s};}Qi(scan1,k<L F>,(F f),<F>{f},F f;,(o{f,*E(v),B,E(v)}),(o{f,*E(v),B,Y(v)}),Qc V s;Qc Qw QF;,{W it!=R.it;},{if(not QF){s=f(s,*it);};QF=QX;++it;W*QI;},{if(not QF){QF=B;s=f(s,*it);}W s;}) k<L T,L S,L I=Q(E(Qf<T>())),L J=Q(E(Qf<S>()))>Z d H+(T&&v,S&&u){Qq(I i;I i_end;J j;Qw in_i;,{W i!=R.i or j!=R.j;},{if(in_i){++i;if(not(i!=i_end)){in_i=QX;}}Q1{++j;}W*QI;},{W(in_i)?(*i):(*j);}) I bv=E(v);I ev=Y(v);J bu=E(u);J eu=Y(u);W QY(o{bv,ev,bu,bv!=ev},o{ev,ev,eu,QX});}Qe A{Qy QV=q;k<L T>d H()(T&&v)O{d u=QU<T>(v)>filter(FF(i,not is_nil(i)));d b=E(u);d e=Y(u);Qy J=Q(b);Qy V=Qv<Q(*b)>;Qy K=Q(E(*b));A o{J j;J QO;QD<V>Ql;K*Qt;Qw M;o(J j,J QO,O V&jv,Qw M):j(j),QO(QO),Ql(new V(jv)),Qt(new K(E(*Ql))),M(M){} o(J j,J QO,Qw M):j(j),QO(QO),Ql(nullptr),Qt(nullptr),M(M){} o(O o&R):j(R.j),QO(R.QO),Ql(R.Ql),Qt((R.Qt)?(new K(*R.Qt)):nullptr),M(R.M){} o(o&&R):j(R.j),QO(R.QO),Ql(R.Ql),Qt((R.Qt)?(new K(*R.Qt)):nullptr),M(R.M){}~o(){delete Qt;}Qw H!=(O o&R)O{W M xor R.M;}o&H++(){++*Qt;if(not(*Qt!=Y(*Ql))){++j;if(j!=QO){delete Qt;Ql=std::make_shared<V>(*j);Qt=new K(E(*Ql));}Q1{M=B;}} W*QI;}Q(d)H*()O{W**Qt;}};if(u>is_nil){W Q9(o(b,e,B),o(b,e,B));}Q1{W Q9(o(b,e,*b,QX),o(e,e,B));}}}flatten;k<L T,L F,L=std::enable_if_t<is_iterable_v<T>>>d H>=(T&&v,F f){W v>Q5(f)>flatten;}k<L U,P...Is>Z Qw all_different_(O U&x,O U&y,QR<Is...>){W((Qd<Is>(x)!=Qd<Is>(y))&&...);}k<L F,L...Ts>Z d zip_with(F f,Ts&&...vs){Qq(F f;X<Q(E(Qf<Ts>()))...>its;,{W all_different_(its,R.its,std::index_sequence_for<Ts...>{});},{QS([&](d&&...xs){(++xs,...);},its);W*QI;},{W QS([&](d&&...xs){W f(*xs...);},its);}) W QY(o{f,X(E(vs)...)},o{f,X(Y(vs)...)});};A zip_default_function_{k<L...Ts>Q(d)H()(Ts&&...xs)O{W X<Ts...>(QU<Ts>(xs)...);}};k<L...Ts>Z d zip(Ts&&...vs){W zip_with(zip_default_function_{},QU<Ts>(vs)...);}Qi(filter,k<L F>,(F f),<F>{f},F f;,(o{f,Y(v),E(v)}),(o{f,Y(v),Y(v)}),O I end_it;Z q Q8()O{while(it!=end_it and not f(*it)){++it;}},{Q8();R.Q8();W it!=R.it;},{Q8();++it;W*QI;},{Q8();W*it;}) def_template_lambda(k<L T>,repeat,(T&&v),{A o{O Qv<T>v;Qw H!=(O o&)O{W B;}o&H++(){W*QI;}O d&H*()O{W v;}};W QY(o{v},o{v});})Z d replicate(P n){W take(n)<repeat;}Z d cycle=flatten<repeat;def_iterator_manip(enumerate,{W zip(to_infinity(P(0)),v);})def_iterator_manip(reversed,{d s=v>QG;std::reverse(s.begin(),s.end());W iterc(Qr(s));})def_iterator_manip(sorted_by,k<L F>,(F f),<F>{f},F f;,{d s=v>QG;std::sort(E(s),Y(s),f);W iterc(Qr(s));})def_iterator_manip(sorted,{W v>sorted_by(_1<_2);})def_iterator_manip(sorted_on,k<L F>,(F f),<F>{f},F f;,{W v>Q5(FF(i,X(i,f(i))))>sorted_by(FF(x,y,(x>snd)<(y>snd)))>Q5(fst);})def_iterator_manip(nub,{Qq(I Q6;I it;,{W it!=R.it;},{Q(*it)pr;do{pr=*it;++it;}while(it!=Q6 and pr==*it);W*QI;},{W*it;}) d b=E(v);d e=Y(v);W QY(o{e,b},o{e,e});})k<L F,L S>A accum_vector_by_{Qy QV=q;P n;F f;S s;k<L T,L I=Q(E(Qf<T>())),L V=Qv<Q(*Qf<I>())>>Q(d)H()(O T&v)O{Qp<Qv<QP<F,S,Q(Qd<1>(Qf<V>()))>>>u(n,s);for(d&&[i,x]:v){u[i]=f(u[i],x);}W u;}};k<L F,L S>Z d accum_vector_by(P n,F f,O S&s){W accum_vector_by_<F,S>{n,f,s};}k<L S>Z d accum_vector(P n,O S&s=S()){W accum_vector_by(n,_2,s);}k<L F,L S>A accum_map_by_{Qy QV=q;F f;S s;k<L T,L I=Q(E(Qf<T>())),L V=Qv<Q(*Qf<I>())>>Q(d)H()(O T&v)O{std::map<Qv<Q(Qd<0>(Qf<V>()))>,Qv<QP<F,S,Q(Qd<1>(Qf<V>()))>>>u;for(d&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Q1{u[i]=f(s,x);}} W u;}};k<L F,L S>Z d accum_map_by(F f,O S&s){W accum_map_by_<F,S>{f,s};}k<L S>Z d accum_map(O S&s=S()){W accum_map_by(_2,s);}k<L F,L S>A accum_unordered_map_by_{Qy QV=q;F f;S s;k<L T,L I=Q(E(Qf<T>())),L V=Qv<Q(*Qf<I>())>>Q(d)H()(O T&v)O{std::unordered_map<Qv<Q(Qd<0>(Qf<V>()))>,Qv<QP<F,S,Q(Qd<1>(Qf<V>()))>>>u;for(d&&[i,x]:v){if(u.count(i)){u[i]=f(u[i],x);}Q1{u[i]=f(s,x);}} W u;}};k<L F,L S>Z d accum_unordered_map_by(F f,O S&s){W accum_unordered_map_by_<F,S>{f,s};}k<L S>Z d accum_unordered_map(O S&s=S()){W accum_unordered_map_by(_2,s);}k<L U,P...Is>Z Qw any_different_(O U&x,O U&y,QR<Is...>){W((Qd<Is>(x)!=Qd<Is>(y))||...);}k<P N,L o>Z q QC(o&it){if Qe(N>=1){++Qd<N-1>(it.its);if(not(Qd<N-1>(it.its)!=Y(Qd<N-1>(*it.my_vs_ptr)))){Qd<N-1>(it.its)=E(Qd<N-1>(*it.my_vs_ptr));QC<N-1>(it);}} Q1{it.its=QS([](d&&...xs){W X(Y(xs)...);},*it.my_vs_ptr);}} k<L...Ts>d Qk(Ts&&...vs){d Qz=std::make_shared<X<Qo<Qb<Ts>,QJ<Ts>,Ts>...>>(vs...);Qq(X<Q(E(Qf<Qo<Qb<Ts>,QJ<Ts>,Ts>>()))...>its;Q(Qz)my_vs_ptr;,{W any_different_(its,R.its,std::index_sequence_for<Ts...>{});},{QC<sizeof...(Ts)>(*QI);W*QI;},{W QS([](d&&...xs){W X<Q(*xs)...>(*xs...);},its);}) if(QS([](d&&...xs){W((xs>is_nil)||...);},*Qz)){W QY(o{QS([](d&&...xs){W X(Y(xs)...);},*Qz),Qz},o{QS([](d&&...xs){W X(Y(xs)...);},*Qz),Qz});}Q1{W QY(o{QS([](d&&...xs){W X(E(xs)...);},*Qz),Qz},o{QS([](d&&...xs){W X(Y(xs)...);},*Qz),Qz});}};k<L...Ts>Z d cartesian_product_range(O Ts&...n){W Qk(Q4(n)...);}k<P n,L I>Z d cartesian_power(O I&v){W QS([](O d&...vs){W Qk(vs...);},tuple_many_of<n>(v));}A{Qy QV=q;int n=-1;k<L T>d H()(T&&v)O{if Qe(std::is_convertible_v<T,int>){d x=*QI;x.n=v;W x;}Q1{d vec=v>QG;int m=vec.size();A o{int n;Q(vec)QE;Qp<P>cycles;Qw M;Qw H!=(O o&R)O{W M xor R.M;}o&H++(){for(d i:Q4(n-1,-1,-1)){cycles[i]--;if(cycles[i]==0){cycles[i]=QE.size()-i;std::rotate(QE.begin()+i,QE.begin()+i+1,QE.end());}Q1{std::swap(QE[i],QE[QE.size()-cycles[i]]);W*QI;}} M=B;W*QI;}d H*()O{W QE>array_slice(0,n);}};int n1=(n<0)?(m):(n);W QY(o{n1,Qr(vec),Q4(m,m-n1,-1)>Q5(FF(x,P(x)))>QG,QX},o{n1,{},{},B});}}}permutations;A combinations_impl{Qy QV=q;int n;k<L T>d H()(T&&v)O{d vec=v>QG;int m=vec.size();Qq(int n;Q(vec)QE;Qp<P>idx;Qw M;,{W M xor R.M;},{for(d i:Q4(n-1,-1,-1)){if(idx[i]!=idx.size()-n+i){idx[i]++;for(d j:Q4(i+1,n)){idx[j]=idx[j-1]+1;}W*QI;}} M=B;W*QI;},{W idx>array_slice(0,n)>Q5(FF(i,QE[i]));}) W QY(o{n,Qr(vec),Q4(0,m)>Q5(FF(x,P(x)))>QG,QX},o{n,{},{},B});}};Z d combinations(int n){W combinations_impl{n};}A QB{Qy QV=q;int n;k<L T>d H()(T&&v)O{d vec=v>QG;int m=vec.size();Qq(int n;Q(vec)QE;Qp<P>idx;Qw M;,{W M xor R.M;},{for(d i:Q4(n-1,-1,-1)){if(idx[i]!=idx.size()-1){idx[i]++;for(d j:Q4(i+1,n)){idx[j]=idx[i];}W*QI;}} M=B;W*QI;},{W idx>array_slice(0,n)>Q5(FF(i,QE[i]));}) W QY(o{n,Qr(vec),P(0)>replicate(m)>QG,QX},o{n,{},{},B});}};Z d combinations_with_replacement(int n){W QB{n};}k<L T>Z d istream_iterable(std::istream&in){Qq(std::istream&in;Qc T val;Qw M;Qc Qw has_read;,{W M xor R.M;},{if(not(in>>val)){M=B;}W*QI;},{if(not has_read){has_read=B;in>>val;}W val;}) W QY(o{in,T{},QX,QX},o{in,T{},B,B});}k<L T>Z d input=istream_iterable<T>(std::cin);k<L T>Q2&print_iterable(Q2&out,O T&v,O std::string&sep= " "){for(d it=E(v);it!=Y(v);){ out<<*it;++it;if(it!=Y(v)){out<<sep;}Q1{W out;}} W out;}k<L T,L=L T::is_iterable_wrapper>Z Q2&H<<(Q2&out,O T&v){out<< "[";W print_iterable(out,v, ", ")<< "]";} 
#define def_iterable_ostream(I)k<L...Ts>Q2&H<<(Q2&out,O I<Ts...>&v){W out<<QY(v);}
Qu(Qp)Qu(std::map)Qu(std::unordered_map)Qu(std::set)Qu(std::unordered_set)k<P n,L T>A Qs{Qy type=Qp<L Qs<n-1,T>::type>;static d make(O Q0<n,P>&sz,O T&val=T()){W Qp(Qx(sz),Qs<n-1,T>::make(tuple_tail(sz),val));}};k<L T>A Qs<1,T>{Qy type=Qp<T>;static d make(O X<P>&sz,O T&val=T()){W Qp(Qx(sz),val);}};k<P n,L T>Qy nested_vector=L Qs<n,T>::type;k<P n,L T>d make_nested_vector(O Q0<n,P>&sz,O T&val=T()){W Qs<n,T>::make(sz,val);}k<P n,L T>Z d Qg(O T&v){if Qe(n==1){W X(v.size());}Q1{W std::tuple_cat(X(v.size()),Qg<n-1>(v[0]));}} k<P n,L T>Z d nested_vector_indices(O T&v){W QS([&](d...x){W cartesian_product_range(x...);},Qg<n>(v));}k<P n,L T>Z Q(d)QW(O Qp<T>&v,O Q0<n,P>&i){if Qe(n==1){W v[Qx(i)];}Q1{W QW<n-1>(v[Qx(i)],tuple_tail(i));}} k<P n,L T>Z Q(d)QW(Qp<T>&v,O Q0<n,P>&i){if Qe(n==1){W v[Qx(i)];}Q1{W QW<n-1>(v[Qx(i)],tuple_tail(i));}} k<L U,P i,P s>Q2&QL(Q2&out,O U&u){if Qe(i==0){out<< "{ ";}out<<Qd<i>(u);if Qe(i+1<s){out<< ", ";W QL<U,i+1,s>(out,u);}Q1{W out<< " }";}} k<L...Ts>Q2&H<<(Q2&out,O X<Ts...>&u){W QL<Q(u),0,sizeof...(Ts)>(out,u);}k<L T,L S>Q2&H<<(Q2&out,O std::pair<T,S>&p){W out<<X(p.first,p.second);} 
#define BEGIN  int main(){std::ios_base::sync_with_stdio(QX);std::cin.tie(0);std::cout.tie(0);
#define END }
Qy namespace std;Qy LL=long long;BEGIN int N;cin>>N;LL w=0,b=0;for(int n=0;n<N;++n){int a;cin>>a;w+=(a+(n%2))/2;b+=(a+((n+1)%2))/2;}cout<<min(b,w)<< "\n";END