#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define IO(x) \
freopen(#x".in","r",stdin);\
freopen(#x".out","w",stdout)
#if 0
#error  
#endif
#include<cstdio>
#define cl_inc(x) cl_lj(cl_inc_,x)
#define cl_inc_0 1
#define cl_inc_1 2
#define cl_inc_2 3
#define cl_inc_3 4
#define cl_inc_4 5
#define cl_inc_5 6
#define cl_inc_6 7
#define cl_inc_7 8
#define cl_inc_8 9
#define cl_inc_9 10
#define cl_inc_10 11
#define cl_inc_11 12
#define cl_inc_13 14
#define cl_inc_14 15
#define cl_inc_15 16
#define cl_inc_16 17
#define cl_inc_17 18
#define cl_inc_18 19
#define cl_inc_19 20
#define cl_get_th(_n,x...) cl_lj(cl_get_th_,_n)(x)
#define cl_get_th_1(_1,x...) _1
#define cl_get_th_2(_1,_2,x...) _2
#define cl_get_th_3(_1,_2,_3,x...) _3
#define cl_get_th_4(_1,_2,_3,_4,x...) _4
#define cl_get_th_5(_1,_2,_3,_4,_5,x...) _5
#define cl_get_th_6(_1,_2,_3,_4,_5,_6,x...) _6
#define cl_get_th_7(_1,_2,_3,_4,_5,_6,_7,x...) _7
#define cl_get_th_8(_1,_2,_3,_4,_5,_6,_7,_8,x...) _8
#define cl_get_th_9(_1,_2,_3,_4,_5,_6,_7,_8,_9,x...) _9
#define cl_get_th_10(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,x...) _10
#define cl_get_th_11(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,x...) _11
#define cl_get_th_12(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,x...) _12
#define cl_get_th_13(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,x...) _13
#define cl_get_th_14(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,x...) _14
#define cl_get_th_15(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,x...) _15
#define cl_get_th_16(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,x...) _16
#define cl_get_th_17(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,x...) _17
#define cl_get_th_18(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,x...) _18
#define cl_get_th_19(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,x...) _19
#define cl_get_th_20(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,x...) _20
#define cl_if(x,y,z) cl_lj(cl_if_,x)(y,z)
#define cl_if_0(y,z) z
#define cl_if_1(y,z) y
#define cl_and(x,y) cl_lj(cl_and_,cl_lj(x,y))
#define cl_and_00 0
#define cl_and_01 0
#define cl_and_10 0
#define cl_and_11 1
#define cl_or(x,y) cl_lj(cl_or_,cl_lj(x,y))
#define cl_or_00 0
#define cl_or_01 1
#define cl_or_10 1
#define cl_or_11 1
#define cl_not(x) cl_lj(cl_not_,x)
#define cl_not_0 1
#define cl_not_1 0
#define _cl_get_th_3(x...) cl_get_th_3(x)
#define cl_bool(x) _cl_get_th_3(cl_lj(cl_bool_is_0_,x),0,1)
#define cl_bool_is_0_0 ,
#define cl_lf() (
#define cl_rt() )
#define cl_dh() ,
#define cl_nn()
#define cl_lj_(a,b) a##b
#define cl_lj(a,b) cl_lj_(a,b)
#define cl_ct __COUNTER__
#define cl_tpf __typeof__
#define cl_txt(x...) #x
#define cl_show(x...) puts(cl_txt(x))
#define cl_zk(x...) x
#define cl_is_nn(x...) cl_and(cl_and(cl_not(cl_has_dh(cl_x_to_dh x)),cl_has_dh(cl_x_to_dh x ())),cl_not(cl_has_dh(x ())))
#define cl_x_to_dh(x...) ,
#define cl_x_to_nn(x...)
#define cl_has_dh(x...) cl_get_th_20(x,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0)
#define cl_kh()
#define cl_if_nn_eat_dh(x...) cl_if(cl_is_nn(x),cl_nn,cl_dh)()
#define cl_len(x...) cl_get_th(20,x cl_if_nn_eat_dh(x) 19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)
#define cl_for(cz,cs,x...) cl_lj(cl_for_,cl_len(x))(cz,cs,1,x)
#define cl_for_0(cz,cs,i,x...)
#define cl_for_1(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_0(cz,cs,cl_inc(i),x))
#define cl_for_2(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_1(cz,cs,cl_inc(i),x))
#define cl_for_3(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_2(cz,cs,cl_inc(i),x))
#define cl_for_4(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_3(cz,cs,cl_inc(i),x))
#define cl_for_5(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_4(cz,cs,cl_inc(i),x))
#define cl_for_6(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_5(cz,cs,cl_inc(i),x))
#define cl_for_7(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_6(cz,cs,cl_inc(i),x))
#define cl_for_8(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_7(cz,cs,cl_inc(i),x))
#define cl_for_9(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_8(cz,cs,cl_inc(i),x))
#define cl_for_10(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_9(cz,cs,cl_inc(i),x))
#define cl_for_11(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_10(cz,cs,cl_inc(i),x))
#define cl_for_12(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_11(cz,cs,cl_inc(i),x))
#define cl_for_13(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_12(cz,cs,cl_inc(i),x))
#define cl_for_14(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_13(cz,cs,cl_inc(i),x))
#define cl_for_15(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_14(cz,cs,cl_inc(i),x))
#define cl_for_16(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_15(cz,cs,cl_inc(i),x))
#define cl_for_17(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_16(cz,cs,cl_inc(i),x))
#define cl_for_18(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_17(cz,cs,cl_inc(i),x))
#define cl_for_19(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_18(cz,cs,cl_inc(i),x))
#define cl_for_20(cz,cs,i,_1,x...) cz(cs,i,_1,cl_for_19(cz,cs,cl_inc(i),x))
#define cl_max_cz(cs,i,_1,x...) cl_if(cl_is_nn(x),_1,max(_1,x))
#define cl_max(x...) cl_if(cl_is_nn(x),,cl_for(cl_max_cz,0,x))
#define cl___to_yz(x...) (x)
#define cl___to_nn(x...)
#define cl_is_yz(x...) cl_if(cl_is_nn(cl___to_nn x),1,0)
#define cl_yz_to_x(x) cl_if(cl_is_yz(x),cl_zk,)x
#define cl_min_cz(_1,x) cl_min_cz_ x
#define cl_min_cz_(_1,x...) cl_if(cl_is_nn(x),_1,(min(_1,cl_get_th_1(x))cl_if_nn_eat_dh(cl_del_th_1(x))cl_del_th_1(x)))
#define cl_min(x...) cl_yz_to_x(cl_while_0(cl_min_cz,cl_min_tj,(x)))
#define cl_del_th_1_(_1,x...) x
#define cl_del_th_1(x...) cl_del_th_1_(x)
#define cl_min_tj(x...) cl_not(cl_if(cl_is_nn(x),1,cl_is_nn(cl_del_th_1(x))))
#define cl_del_nn_s_dh(x...) cl_if(cl_is_nn(x),cl___to_nn,cl_for)(cl_del_nn_s_dh_cz,0,x)
#define cl_del_nn_s_dh_cz(cs,i,_1,x...) cl_zk(_1)cl_if(cl_or(cl_is_nn(_1),cl_is_nn(x)),cl_nn,cl_dh)()x
#define cl_yz_to_x_to(x...) cl_yz_to_x(cl_while_0(cl_yz_to_x_to_cz,cl_yz_to_x_to_tj,(x)))
#define cl_yz_to_x_to_cz(_1,x) cl_yz_to_x(x)
#define cl_yz_to_x_to_tj(x...) cl_is_yz(x)
#define cl_hst(x...) cl_del_nn_s_dh(cl_yz_to_x_to(cl_del_nn_s_dh(cl_yz_to_x_to(cl_while_0(cl_hst_cz,cl_hst_tj,((),x))))))
#define cl_hst_tj(x...) cl_not(cl_is_nn(cl_del_th_1(x)))
#define cl_hst_cz(_1,x) cl_hst_cz__(cl_yz_to_x(x))
#define cl_hst_cz_(_1,_2,x...) ((cl_yz_to_x(_1)cl_if_nn_eat_dh(cl_yz_to_x(_1))cl_hst_each(cl_yz_to_x(_2))),x)
#define cl_hst_cz__(x...) cl_hst_cz_(x)
#define cl_hst_each(cs,x...) cl_for(cl_hst_each_cz,cs,x)
#define cl_hst_each_cz(cs,i,_1,x...) cl_if(cl_is_nn(_1),cl___to_nn,cl_zk)(cl_zk(cl_yz_to_x(cs) _1)cl_if_nn_eat_dh(x)x)
typedef long long ll;
#define cl_hstll(x...) cl_hst((ll,x))
#define cl(x...) cl_lj(cl_,x)
#define cl_ri(cs,x...) cl_for(cl_ri_cz,cs,x)
#define cl_ri_cz(cs,i,_1,x...) cl_zk(_1 cs)cl_if_nn_eat_dh(x)x
#define cl_rill(x...) cl_ri(=readll(),x)
#define cl_ri0(x...) cl_ri(=0,x)
#define cl_usnmspc(cs,x...) cl_for(cl_usnmspc_cz,cs,x) 
#define cl_usnmspc_cz(cs,i,_1,x...) cl_zk(using cs::_1)cl_if(cl_is_nn(x),,;)\
x
#define cl_usstd(x...) cl_usnmspc(std,x)
cl_usstd(max,min);
#define _s1_112
#define cl_lj_x_(x...) x##_112
#define cl_lj_x(x...) cl_lj_x_(x)
#define cl_bl(x...) cl_del_th_1(cl_yz_to_x(cl_yz_to_x(cl_while_0(cl_bl_cz_1,cl_bl_tj,((),x,)))))
#define cl_bl_tj(x...) cl_bl_tjx(x)
#define cl_bl_tjx(_1,x...) cl_not(cl_is_nn(x))
#define cl_bl_cz_1(_1,x) cl_bl_cz_1x(_1,cl_yz_to_x(x))
#define cl_bl_cz_1x(x...) cl_bl_cz_1_(x)
#define cl_bl_cz_1_(_1,_2,_3,x...) ((cl_yz_to_x(_2)cl_if(cl_is_yz(_3),cl_nn,cl_dh)()cl_yz_to_x(cl_yz_to_x(cl_if(cl_is_yz(_3),cl_lj(cl_while_,_1),cl_zk(_3)cl___to_nn)(cl_bl_cz_2,cl_bl_tj,((),cl_zk _3,)))))cl_if_nn_eat_dh(x)x)
#define cl_bl_cz_2(_1,x) cl_bl_cz_2x(_1,cl_yz_to_x(x))
#define cl_bl_cz_2x(x...) cl_bl_cz_2_(x)
#define cl_bl_cz_2_(_1,_2,_3,x...) ((cl_yz_to_x(_2)cl_if(cl_is_yz(_3),cl_nn,cl_dh)()cl_yz_to_x(cl_yz_to_x(cl_if(cl_is_yz(_3),cl_lj(cl_while_,_1),cl_zk(_3)cl___to_nn)(cl_bl_cz_3,cl_bl_tj,((),cl_zk _3,)))))cl_if_nn_eat_dh(x)x)
#define cl_bl_cz_3(_1,x) cl_bl_cz_3x(_1,cl_yz_to_x(x))
#define cl_bl_cz_3x(x...) cl_bl_cz_3_(x)
#define cl_bl_cz_3_(_1,_2,_3,x...) ((cl_yz_to_x(_2)cl_if(cl_is_yz(_3),cl_nn,cl_dh)()cl_yz_to_x(cl_yz_to_x(cl_if(cl_is_yz(_3),cl_lj(cl_while_,_1),cl_zk(_3)cl___to_nn)(cl_bl_cz_4,cl_bl_tj,((),cl_zk _3,)))))cl_if_nn_eat_dh(x)x)
#define cl_while_0(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_1,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(1,x))
#define cl_while_1(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_2,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(2,x))
#define cl_while_2(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_3,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(3,x))
#define cl_while_3(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_4,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(4,x))
#define cl_while_4(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_5,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(5,x))
#define cl_while_5(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_6,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(6,x))
#define cl_while_6(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_7,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(7,x))
#define cl_while_7(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_8,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(8,x))
#define cl_while_8(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_9,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(9,x))
#define cl_while_9(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_10,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(10,x))
#define cl_while_10(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_11,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(11,x))
#define cl_while_11(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_12,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(12,x))
#define cl_while_12(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_13,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(13,x))
#define cl_while_13(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_14,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(14,x))
#define cl_while_14(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_15,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(15,x))
#define cl_while_15(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_16,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(16,x))
#define cl_while_16(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_17,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(17,x))
#define cl_while_17(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_18,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(18,x))
#define cl_while_18(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_19,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(19,x))
#define cl_while_19(cz,tj,x) cl_if(tj(cl_yz_to_x(x)),cl_while_20,cl_zk(x)cl___to_nn)(cz,tj,cl_if(tj(cl_yz_to_x(x)),cz,cl___to_nn)(20,x))
ll readll(void){
	ll x=0,w=1;char c=getchar();
	for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());
	return x*w;
}
ll readchar(void){
	char c=getchar();
	for(;c<=34;c=getchar());
	return c;
}
#define cl_cl_for_zk_th_check_ccfc_1
#define cl_cl_for_zk_th_check(x...) cl_is_nn(cl_lj(cl_cl_for_zk_th_check_,x))
#define cl_rep(i,low,up,x...) for(ll i=low;i<=up;cl_if(cl_is_nn(x),cl_zk(i++)cl___to_nn,cl_zk)(x))
#define rep cl_rep
#define rill cl_rill
#define ri0 cl_ri0
ll w[123][123],f[123][9][9];
int main() {
	//IO(_B);
	rep(i,1,3)rep(j,1,3)rill(w[i][j]);
	ll rill(n);
	rep(i,1,n)rep(u,1,3)rep(v,1,3)(u^v)&&(f[i][u][v]=cl_min(f[i-1][u][u^v]+w[u][v]+f[i-1][u^v][v],f[i-1][u][v]+w[u][u^v]+f[i-1][v][u]+w[u^v][v]+f[i-1][u][v]));
	printf("%lld\n",f[n][1][3]);
 	return 0;
}