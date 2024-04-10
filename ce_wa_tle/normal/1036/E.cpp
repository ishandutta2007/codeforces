// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2014 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
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

// C++
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
#define max(x,y) std::max((ll)(x),(ll)(y))
#define min(x,y) std::min((ll)(x),(ll)(y))
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
typedef long long ll;
const ll mod=998244353;
ll readll(void){
	ll x=0,w=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
	for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	return x*w;
}
const ll sint=1ll<<32,mint=sint-1;
//struct wint_256{
//	unsigned int val[8];
//	wint_256(){
//		memset(val,0,sizeof val);
//	}
//	wint_256 operator~()const{
//		wint_256 result;
//		rep(i,0,7)result.val[i]^=unsigned(-1);
//		return result;
//	}
//	wint_256 operator+(wint_256 result)const{
//		ll p=0;
//		rep(i,0,7){
//			result.val[i]=result.val[i]+val[i]+p;
//			p=0ll+result.val[i]+val[i]+p>sint;
//		}
//		return result;
//	}
//	wint_256 operator++(int){
//		ll s=0;
//		while(s<=6&&val[s]==unsigned(-1))val[s]=0,s++;
//		val[s]++;
//		return*this;
//	}
//	wint_256 operator-()const{
//		wint_256 result=operator~();
//		result++;
//		return result;
//	}
//	wint_256 operator-(const wint_256&b)const{
//		return*this+-b;
//	}
//	wint_256(int a){
//		if(a>=0){
//			val[0]=a;
//		}
//		else{
//			val[0]=a;
//			*this=-*this;
//		} 
//	}
//	wint_256 operator*(wint_256 b)const{
//		ll f[9]={0,0,0,0,0,0,0,0,0};
//		ll fh=;
//		rep(i,0,7)
//		rep(j,0,7)
//		f[i+j]+=val[i]*b.val[j];
//		rep(i,0,7)f[i+1]+=f[i]>>32,b.val[i]=f[i]&mint;
//		return b;
//	}
//	wint_256 operator>>()
//};
//#define ll wint_256
struct pt{
	ll x,y;
	void read(){
		x=readll(),y=readll();
	}
	int operator<(const pt&b)const{
		return x==b.x?y<b.y:x<b.x;
	}
};
ll sqr(ll x){
	return x*x;
}
ll dis(const pt&a,const pt&b){
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}
ll iabs(ll x){
	return max(x,-x);
}
ll fh(ll x){
	return x>0?1:x<0?-1:0;
}
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll hls(ll a,ll b,ll c,ll d){
	return a*d-b*c;
}
struct line{
	pt p1,p2;
	void read(){
		p1.read(),p2.read();
	}
	ll ds()const{
		return 1+gcd(iabs(p1.x-p2.x),iabs(p1.y-p2.y));
	}
//	#undef ll
	ll incl(const pt&b)const{
//		printf("d=%lld %lld %lld\n",dis(b,p1),dis(b,p2),dis(p1,p2));
		ll aa=dis(b,p1),bb=dis(b,p2),sab=(ll)(sqrt((long double)aa*bb+0.1)),c=dis(p1,p2);
//		if(sqr(sab%mod)%mod==aa%mod*(bb%mod)%mod)
		if((aa%mod+bb%mod+2*sab%mod)%mod==c%mod)
		return 1;
		return 0;
	}
//	#define ll wint
	int xlj(const pt&b)const{
		return hls(b.x-p1.x,b.y-p1.y,
		b.x-p2.x,b.y-p2.y);
	}
	int xj(const line&b)const{
		return fh(xlj(b.p1))*fh(xlj(b.p2))<=0;
	}
	pt jd(const line&b)const{
		//(x-a.p1.x)*(y-a.p2.y)=(x-a.p2.x)*(y-a.p1.y)
		//(x-b.p1.x)*(y-b.p2.y)=(x-b.p2.x)*(y-b.p1.y)
		//(a1y-a2y)*x-(a1x-a2x)*y=a1y*a2x-a1x*a2y
		//-b2yx-b1xy+b1xb2y=-b1yx-b2xy+b2xb1y
		//(a1x-a2x)*y-(a2y-a1y)*x=+a2x*a1y-a1x*a2y
		//(b1x-b2x)*y-(b2y-b1y)*x=+b2x*b1y-b1x*b2y
		const line&a=*this;
//		if(!a.xj(b)||!b.xj(a))
//		return(pt){114514,-114514};
		ll a1=a.p1.y-a.p2.y,a2=-(a.p1.x-a.p2.x),a3=a.p2.x*a.p1.y-a.p1.x*a.p2.y;
		ll b1=b.p1.y-b.p2.y,b2=-(b.p1.x-b.p2.x),b3=b.p2.x*b.p1.y-b.p1.x*b.p2.y;
		ll ga=gcd(gcd(a1,a2),a3),gb=gcd(gcd(b1,b2),b3);
		a1/=ga,a2/=ga,a3/=ga;
		b1/=gb,b2/=gb,b3/=gb;
		ll d=hls(a1,a2,
		b1,b2),
		ty=hls(a1,a3,
		b1,b3),
		tx=hls(a3,a2,
		b3,b2);
//		printf("j1=%lld %lld %lld\n",a1,a2,a3);
//		printf("j2=%lld %lld %lld\n",b1,b2,b3);
//		printf("j=%lld %lld %lld\n",d,tx,ty);
		if(d!=0&&(tx%d==0&&ty%d==0))
		return(pt){tx/d,ty/d};
		else
		return(pt){114514,-114514};
	}
}l[1111];
//#undef ll
std::map<pt,ll>ma;
int main(){
	long long n=readll(),cnt=0;
	rep(i,1,n){
		l[i].read();
		cnt+=l[i].ds();
		ma.clear();
		rep(j,1,i-1){
			pt jd=l[i].jd(l[j]);
//			printf("s=%lld %lld %lld %lld\n",i,j,jd.x,jd.y);
//			printf("s=%lld %lld\n",l[i].incl(jd),l[j].incl(jd));
			if(l[i].incl(jd)&&l[j].incl(jd)){
//			printf("sdsfadsfa");
				if(!ma.count(jd)){
					cnt--;
					ma[jd]=1;
				}
			}
		}
	}
	printf("%lld\n",cnt);
	return 0;
}