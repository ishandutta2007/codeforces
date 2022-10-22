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
	for(;ch<'A'||ch>'Z';ch=getchar());
	return ch;
}
ll f[1145141],ls[1145141],rs[1145141],val[1145141],no_xm[1145141];
void dfs1(ll u){
	if(!u)return;
	dfs1(ls[u]);
	dfs1(rs[u]);
	switch(f[u]){
		case'X':
			val[u]=val[ls[u]]^val[rs[u]];
			break;
		case'A':
			val[u]=val[ls[u]]&val[rs[u]];
			if(val[ls[u]]==0)no_xm[rs[u]]=1;
			if(val[rs[u]]==0)no_xm[ls[u]]=1;
			break;
		case'O':
			val[u]=val[ls[u]]|val[rs[u]];
			if(val[ls[u]]==1)no_xm[rs[u]]=1;
			if(val[rs[u]]==1)no_xm[ls[u]]=1;
			break;
		case'N':
			val[u]=!val[ls[u]];
			break;
	}
}
void dfs2(ll u){
	if(!u)return;
	if(no_xm[u])no_xm[ls[u]]=no_xm[rs[u]]=1;
	dfs2(ls[u]);
	dfs2(rs[u]);
}
int main(){
	ll n=readll();
//	return 0;
	rep(i,1,n){
		f[i]=readchar();
		ll x,y;
		switch(f[i]){
			case'X':
			case'A':
			case'O':
				x=readll(),y=readll();
				ls[i]=x,rs[i]=y;
				break;
			case'N':
				x=readll();
				ls[i]=x;
				break;
			case'I':
				x=readll();
				val[i]=x;
				break;
		}
	}
	dfs1(1);
	dfs2(1);
	rep(i,1,n){
		if(f[i]=='I'){
			printf("%lld",val[1]^no_xm[i]^1);
		}
	}
	return 0;
}