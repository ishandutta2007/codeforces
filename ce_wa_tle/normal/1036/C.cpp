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
ll getans(ll r){
	struct calc{
		ll sz[5555555],cnt;
		calc():cnt(0){
			static ll ws[21];
			ws[0]=1;
			rep(i,1,19)ws[i]=ws[i-1]*10;
//			rep(i,1,99)sz[++cnt]=i;
			rep(w1,1,19)
			rep(s1,1,(w1==19?1:9)){
				sz[++cnt]=s1*ws[w1-1];
				rep(w2,1,w1-1)
				rep(s2,1,9){
					sz[++cnt]=s1*ws[w1-1]+s2*ws[w2-1];
					rep(w3,1,w2-1)
					rep(s3,1,9){
						sz[++cnt]=s1*ws[w1-1]+s2*ws[w2-1]+s3*ws[w3-1];
						if(sz[cnt]<=sz[cnt-1])
//						if(sz[cnt]<=1000)
						printf("YD %lld %lld\n",sz[cnt],sz[cnt-1]);
					}
				}
			}
		}
	};
	static calc calcer;
	return std::upper_bound(calcer.sz,calcer.sz+calcer.cnt+1,r)-calcer.sz;
//	if(r==-1)return 0;
//	dp[0][0]=1;
//	rep(i,1,19){
//		ll dq=r%10;
//		rep(j,1,3)
//		dp[i][j]=dp[i-1][j-!(dq==0)];
//		r/=10;
//	}
//	return dp[19][1]+dp[19][2]+dp[19][3];
}
int main(){
	ll T=readll();
	while(T --> 0){
		ll l=readll(),r=readll();
		printf("%lld\n",getans(r)-getans(l-1));
	}
	return 0;
}