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
ll iabs(ll x){
	return max(x,-x);
}
int readchar(void){
	int ch=getchar();
	for(;ch<'a'||ch>'z';ch=getchar());
	return ch;
}
ll p[1145141],min_d[1145141],ans[1145141],top=0;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	rep(i,2,100000){
		if(!p[i])p[++top]=i,ans[i]=2,min_d[i]=i;
		rfor(ll j=1;j<=top&&p[j]*i<=100000;j++){
			p[i*p[j]]=1;min_d[i*p[j]]=p[j];
			ans[i*p[j]]=ans[i]*ans[p[j]];
			if(!(i%p[j])){
				min_d[i*p[j]]=min_d[i]*p[j];
				if(min_d[i*p[j]]!=i*p[j])
				ans[i*p[j]]=ans[i/min_d[i]]*ans[min_d[i]*p[j]];//,(i*p[j]==12)&&printf("%lld %lld %lld\n",i*p[j],ans[i/min_d[i]],ans[min_d[i]*p[j]]);
				else ans[i*p[j]]=ans[i]+1;
				break;
			}
		}
	}
	ans[1]=1;
//	rep(i,1,100){
//		printf("i=%lld,ans=%lld\n",i,ans[i]);
////		ll cnt=0;
////		rep(j,1,i)
////		if(i%j==0){
////			cnt++;
////		}
////		if(cnt!=ans[i])while(1)puts("YD");
//	}
	ll T=readll();
	while(T --> 0){
		ll a=readll(),b=readll(),c=readll();
		ll ab=ans[gcd(a,b)],bc=ans[gcd(b,c)],ac=ans[gcd(a,c)],abc=ans[gcd(gcd(a,b),c)];
		a=ans[a],b=ans[b],c=ans[c];
//		ll na=a+abc-ab-ac,nb=b+abc-ab-bc,nc=c+abc-ca-bc;
		ll nab=ab-abc,nbc=bc-abc,nac=ac-abc;//,ha=a-na,hb=b-nb,hc=c-nc;
		printf("%lld\n",
			+a*b*c
		 +((-ab*~-ab*c
			-bc*~-bc*a
			-ac*~-ac*b
			+abc*~-abc*(nab+nac+nbc))>>1)
			-nab*nac*nbc
			+(abc*~-abc*~-~-abc<<1)/3
			+abc*~-abc
		);
//		printf("%lld\n",a*b*c
//		+(-ab*ab*c+ab*c-ac*b*ac+ac*b-b*bc*bc+bc*a)/2);
//		printf("%lld\n",ans[a]*ans[b]*ans[c]);
//		printf("%lld\n",ans[a]*ans[b]*ans[c]+
//	   (-ans[gcd(a,b)]*ans[gcd(a,b)]*ans[c]+ans[gcd(a,b)]*ans[c]
//		-ans[gcd(a,c)]*ans[gcd(a,c)]*ans[b]+ans[gcd(a,c)]*ans[b]
//		-ans[gcd(c,b)]*ans[gcd(c,b)]*ans[a]+ans[gcd(c,b)]*ans[a])/2
//		+(4*ans[gcd(a,gcd(b,c))]*ans[gcd(a,gcd(b,c))]*ans[gcd(a,gcd(b,c))]-
//		6*ans[gcd(a,gcd(b,c))]*ans[gcd(a,gcd(b,c))]
//		+2*ans[gcd(a,gcd(b,c))])/6
//		);
	}
	return 0;
}