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
#include <cstdio>
#include <cctype>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define ssss(p_1,p_2,p_3,p_4,p_5,p_6,p_7,p_8,p_9,p_10,p_11,p_12,p_13,p_14,p_15,p_16,p_17,p_18,p_19,p_20,n,...) n
#define shu_liang(a...) ssss(12,##a,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)
#define sho(x) #x
#define show(x) sho(x)
#define lia(x,y) x##y
#define lian(x,y) lia(x,y)
#define mk(x) do{x}while(0)
#define dg_1 0
#define dg_2 1
#define dg_3 2
#define dg_4 3
#define dg_5 4
#define dg_6 5
#define dg_7 6
#define dg_8 7
#define dg_9 8
#define dg_10 9
#define dg_11 10
#define dg_12 11
#define dg_13 12
#define dg_14 13
#define dg_15 14
#define dg_16 15
#define dg_17 16
#define dg_18 17
#define dg_19 18
#define dg_(n) dg_##n
#define dg(n) dg_(n)
#define ZJH_0(sb,n,arg,x...) 
#define ZJH_1(sb,n,arg,x...) sb(arg)
#define ZJH_2(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_3(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_4(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_5(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_6(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_7(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_8(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_9(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_10(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_11(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_12(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_13(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_14(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_15(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_16(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_17(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_18(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH_19(sb,n,arg,x...) sb(arg),lian(ZJH_,dg(n))(sb,dg(n),x)
#define ZJH(sb,x...) lian(ZJH_,shu_liang(x))(sb,shu_liang(x),x,2,3,4)
#define ZJH2_0(sb,n,arg,x...) 
#define ZJH2_1(sb,n,arg,x...) arg
#define ZJH2_2(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_3(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_4(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_5(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_6(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_7(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_8(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_9(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_10(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_11(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_12(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_13(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_14(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_15(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_16(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_17(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_18(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2_19(sb,n,arg,x...) sb(arg,lian(ZJH2_,dg(n))(sb,dg(n),x))
#define ZJH2(sb,x...) lian(ZJH2_,shu_liang(x))(sb,shu_liang(x),x,2,3,4)
#define ZJH0_0(sb,n,arg,x...) 
#define ZJH0_1(sb,n,arg,x...) sb(arg)
#define ZJH0_2(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_3(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_4(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_5(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_6(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_7(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_8(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_9(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_10(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_11(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_12(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_13(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_14(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_15(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_16(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_17(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_18(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0_19(sb,n,arg,x...) sb(arg) lian(ZJH0_,dg(n))(sb,dg(n),x)
#define ZJH0(sb,x...) lian(ZJH0_,shu_liang(x))(sb,shu_liang(x),x,2,3,4)
#define IO(ss) \
freopen(#ss".in","r",stdin);\
freopen(#ss".out","w",stdout)
#define debug
#undef debug
#ifdef debug
#define s__u__m 1
#else
#define s__u__m 0
#endif
#define she_(x) \
for(ll error_##x=0;(error_##x<s__u__m)&&(puts("error_"#x":"),1);++error_##x)
#define sh_(x) \
for(ll error_##x=0;error_##x<s__u__m;++error_##x)
#define she(x) she_(x)
#define sh(x) sh_(x)
#define checks(x) check##x
#define checkdy(x) template<typename T>class checks(x);
#define checksy(x) typename checks(x)<T>::type
#define joincheck(x,T) template<>class checks(x)<T>{public:typedef T type;};
#define joincheck1(T) joincheck(1,T)
checkdy(1);
ZJH0(joincheck1,short,signed,long long,long,unsigned short,unsigned,unsigned long,unsigned long long);
#define ccc __c___sss__jdd
char ccc=0;
template<typename T>
void reads(checksy(1)&_) {
	checksy(1) x=0,w=1;
	for(;ccc<'0'||ccc>'9';(ccc^'-')||(w=-w),ccc=getchar());
	for(;ccc>='0'&&ccc<='9';x=(x<<1)+(x<<3)+(ccc^48),ccc=getchar());
	//puts("s1:");
	_=x*w;
	return;
}
template<typename T>
void writes(checksy(1)_) {
	if(_<0)putchar('-'),_=-_;
	if(_<10)putchar(_^48);
	else writes<checksy(1)>(_/10),putchar((_%10)^48);
	return;
}
#define joincheck2(T) joincheck(2,T)
checkdy(2);
ZJH0(joincheck2,char,unsigned char);
template<typename T>
void reads(checksy(2)&_) {
	for(;ccc<33||ccc>126;ccc=getchar());
	//puts("s2:");
	_=ccc;
	ccc=getchar();
	return;
}
template<typename T>//233
void writes(checksy(2)_) {
	if(_)
	putchar(_);
	return;
}
template<typename T>
void reads(checksy(2)*_) {
	for(;ccc<33||ccc>126;ccc=getchar());
	//puts("s2:");
	ll a=1;_[0]=ccc;
	ccc=getchar();
	for(;ccc>=33&&ccc<=126;_[a]=ccc,a++,ccc=getchar());
	_[a]=0;
	return;
}
template<typename T>
void writes(checksy(2)*_) {
	ll a=0;
	while(_[a])putchar(_[a]),a++;
	return;
}
template<typename T>
void writes(const checksy(2)*_) {
	ll a=0;
	while(_[a])putchar(_[a]),a++;
	return;
}
#define joincheck3(T) joincheck(3,T)
checkdy(3);
ZJH0(joincheck3,double,long double);
template<typename T>
void reads(checksy(3)&_) {
	checksy(3) x=0;
	int w=1;
	for(;ccc<'0'||ccc>'9';(ccc^'-')||(w=-w),ccc=getchar());
	for(;ccc>='0'&&ccc<='9';x=x*10+int(ccc^48),ccc=getchar());
	if(ccc^'.') {
		//puts("s3:");
		//printf("%lf %d\n",(double)x,w);
		_=x*w;
		return;
	}
	ccc=getchar();
	checksy(3) m=0.1;
	for(;ccc>='0'&&ccc<='9';x+=int(ccc^48)*m,ccc=getchar(),m/=10);
	//puts("s3:");
	_=x*w;
	return;
}
ll ws=6;
template<typename T>
void writes(checksy(3)_) {
	if(_<0)putchar('-'),_=-_;
	ll m=1;
	for(ll i=1;i<=ws;i++)m*=10;
	writes<long long>((long long)(_*m+0.5)/m);
	if(ws==0)return;
	putchar('.');
	ll l_=(long long)((_-(long long)_)*m+0.5);
	m/=10;
	for(ll i=1;i<=ws;i++,m/=10){
		putchar((l_/m%10)^48);
	}
	return;
}
template<typename T> 
void reads_(T&x) {reads<T>(x);}
template<typename T> 
void reads_(T*x) {reads<T>(x);}
#define read(x...) ZJH(reads_,##x)
#define readln(x...) ({read(x);while(ccc>=32)ccc=getchar();void(0);})
template<typename T> 
void writes_(T x) {writes<T>(x);}
template<typename T> 
void writes_(T*x) {writes<T>(x);}
template<typename T> 
void writes_(const T*x) {writes<T>(x);}
#define writ_e(x...) ZJH(writes_,##x)
#define write(x...) writ_e(x)
#define writ_eln(x...) write(char(0),##x,'\n')
#define writeln(x...) writ_eln(x)
#define typeof __typeof__
#define maxs_(x,y) ({typeof(x) ss___x=x;typeof(y) ss___y=y;ss___x>ss___y?ss___x:ss___y;})
#define mins_(x,y) ({typeof(x) ss___x=x;typeof(y) ss___y=y;ss___x<ss___y?ss___x:ss___y;})
#define sums_(x,y) ({typeof(x) ss___x=x;typeof(y) ss___y=y;ss___x+ss___y;})
#define ma_x(x...) ZJH2(maxs_,##x)
#define mi_n(x...) ZJH2(mins_,##x)
#define su_m(x...) ZJH2(sums_,##x)
#define max(x...) ma_x(x)
#define min(x...) mi_n(x)
#define sum(x...) su_m(x)








///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll x[222222],y[222222];
int main(int wcr,char**AKIOI) {
	//IO(d);
	ll n;
	read(n);
	for(ll i=1;i<=n;i++)read(x[i],y[i]);
	if(n&1)writeln("NO");
	else {
		ll p=1;
		for(ll i=2;i<=n/2;i++)
		if(x[i-1]+x[i-1+n/2]!=x[i]+x[i+n/2]||y[i-1]+y[i-1+n/2]!=y[i]+y[i+n/2]) {
			p=0;
			break;
			}
		writeln(p?"YES":"NO");
		}
	return 0;
}