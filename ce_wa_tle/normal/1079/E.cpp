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
#define max(x,y) std::max((x),(y))
#define min(x,y) std::min((x),(y))
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
typedef long long ll;
typedef long double ld;
const ll mod=1e9+9;
ll readll(void){
	ll x=0,w=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
	for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	return x*w;
}
ll a[114514],t[114514],f[111][11111],c[111][111],sum[114514];
int main(){
	ll n=readll();
	rep(i,1,n)a[i]=readll(),sum[i]=sum[i-1]+a[i];
	c[0][0]=1;
	rep(i,1,n){
		rep(j,0,i){
			c[i][j]=(c[i-1][j]+(j?c[i-1][j-1]:0))%mod;
		}
	}
	f[0][0]=1;
	rep(i,1,n){
		per(k,n,1)
		per(j,sum[i],a[i])(f[k][j]=f[k][j]+f[k-1][j-a[i]])%=mod,0;
//		(f[k-1][j-a[i]])&&
//			printf("f[2][8]=%lld f[%lld][%lld]=%lld f[%lld][%lld]=%lld\n",f[2][8],k,j,f[k][j],k-1,j-a[i],f[k-1][j-a[i]]);
		t[a[i]]++;
	}
	ll max=0;
	ll cnt=0;
	rep(i,1,100){
		if(t[i])cnt++;
		rep(j,1,t[i]){
//			printf("f[%lld][%lld]=%lld %lld\n",j,i*j,f[j][i*j],c[3][2]);
			if(f[j][i*j]==c[t[i]][j])max=max(max,j);
		}
	}
	printf("%lld\n",cnt<=2?n:max);
	return 0;
}