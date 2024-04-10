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
struct node{
	ll in,out;
	int operator<(const node&b)const{
		return in<b.in;
	}
}ss[314514];
ll cnt=0,to[1514514],next[1514514],head[1514514],w[1514514],dis[1514514],cnts[1514514];
void add(ll u,ll v,ll h){
//	printf("%lld %lld %lld\n",u,v,h);
	++cnt;w[cnt]=h;
	to[cnt]=v;
	next[cnt]=head[u];
	head[u]=cnt;
}
int main(){
	ll n=readll();
	rep(i,1,n){
		ss[i].out=readll();
		ss[i].in=readll();
	}
	std::sort(ss+1,ss+n+1);
	ll s=0,t=n+1;
	rep(i,1,n){
		add(i-1,i,ss[i].in-ss[i-1].in);
		ll tot=std::lower_bound(ss+1,ss+n+1,(node){ss[i].out,0})-ss;
		if(tot<=n)
		add(i,tot,ss[tot].in-ss[i].out);
		else
		add(i,t,0);
	}
	dis[s]=0,cnts[s]=1;
	rep(i,1,t)dis[i]=111111444555111444ll;
//	ll sum=0;
	rep(u,s,t){
//		if(ss[u].out>ss[n].in)
//		sum+=cnts[u];
		rfor(ll i=head[u];i;i=next[i]){
			if(dis[u]+w[i]<dis[to[i]]){
				dis[to[i]]=dis[u]+w[i];
				cnts[to[i]]=0;
			}
			if(dis[u]+w[i]==dis[to[i]]){
				cnts[to[i]]=(cnts[to[i]]+cnts[u])%mod;
			}
		}
	}
	printf("%lld\n",cnts[t]);
	return 0;
}
//[(r-l+1)/m]=ll((r-l)/m)+1
//r/m*k-l/m*k+[(r%m-l%m)/m]*k