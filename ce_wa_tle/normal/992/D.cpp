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
const ll mod=1e9+7;
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
ll f[222222],*t=f+111111;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll power(ll a,ll b){
//	a%=mod;
	ll ans=1;
	while(b){
		b&1&&(ans=ans*a%mod);
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll a[214541],next[214514],pre[214514];
int main(){
	ll n=readll(),k=readll();
	rep(i,1,n)a[i]=readll();
	ll lst=0;
	rep(i,1,n)
	if(a[i]!=1){
		next[lst]=i;
		pre[i]=lst;
		lst=i;
	}
	next[lst]=n+1;
	pre[n+1]=lst;
	ll cnt=0;
	rfor(ll i=next[0];i;i=next[i]){
		ll sum=i-pre[i]-1;
		if(k==1)cnt+=sum-k+1;
	}
	rfor(ll i=next[0];i<=n;i=next[i]){
		ll mul=a[i],add=a[i];
		rfor(ll j=i;j<=n&&(j==i||mul<=n*k*1.0/a[j]*1e8);j=next[j]){
			if(j!=i)mul*=a[j],add+=j-pre[j]-1+a[j];
			if(mul%k)continue;
			ll ls=i-pre[i]-1,rs=next[j]-j-1,limit=mul/k-add;
			//l+r==mul/k-tot
			if(limit<0||limit>ls+rs)continue;
//		printf("%lld %lld %lld\n",ls,rs,limit);
			if(ls>rs)std::swap(ls,rs);
			//ls<rs
			if(limit>=rs)
			cnt+=ls+rs-limit+1;
			else
			if(limit>=ls)
			cnt+=ls+1;
			else
			cnt+=limit+1;
		}
	}
	printf("%lld\n",cnt);
	return 0;
}