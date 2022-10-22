// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2013 Free Software Foundation, Inc.
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
#define ll long long
#define IO(x) \
freopen(#x".in","r",stdin);\
freopen(#x".out","w",stdout)
ll readll(void){
	ll x=0,w=1;char c=getchar();
	for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());
	return x*w;
}
ll st[222222][20],to[222222],head[222222],cnt=0,top=0,next[222222],tree_to_ol[111111],deep[111111],f[222222],t[222222],a[111111];
void add(ll x,ll y){to[++cnt,head[x]^=next[cnt]^=head[x]^=next[cnt]=cnt]=y;}
void dfs(ll u,ll fa){
	tree_to_ol[u]=++top;
	//ol_to_tree[top]=u;
	deep[u]=deep[fa]+1;
	st[top][0]=u;
	for(ll i=head[u];i;i=next[i])
	if(to[i]^fa){
		dfs(to[i],u);
		st[++top][0]=u;
	}
}
ll mi(ll x,ll y){
	return deep[x]<deep[y]?x:y;
}
void ycl(){
	for(ll j=1;(1<<j)<=top;j++){
		for(ll i=1;i+(1<<j)-1<=top;i++){
			st[i][j]=mi(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
ll lca(ll x,ll y){
	if(x==y)return x;
	x=tree_to_ol[x];
	y=tree_to_ol[y];
	if(x>y)std::swap(x,y);
	//1 2 3 4 5 6 7 8 9
	//0 1 1 2 2 2 2 3 3
	ll len=log(y-x+1.5)/log(2.0);
	//printf("%lld %lld %lld %lld %lld\n",x,y,1<<len,st[x][len],y+1-(1<<len));
	return mi(st[x][len],st[y+1-(1<<len)][len]);
}
ll _dfs(ll u,ll fa){
	for(ll i=head[u];i;i=next[i])
	if(to[i]^fa){
		_dfs(to[i],u);
		a[u]+=a[to[i]];
	}
}
int main(int SXM,char**is_a_duliu){
	//IO(A);
	ll n=readll();
//	return 0;
	for(ll i=1;i<=n-1;i++){
		ll x=f[i]=readll(),y=t[i]=readll();
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	ycl();
	ll m=readll();
	for(ll i=1;i<=m;i++){
		ll x=readll(),y=readll();
		a[x]++,a[y]++,a[lca(x,y)]-=2;
		//printf("%lld %lld %lld\n",x,y,lca(x,y));
	}
	_dfs(1,0);
	for(ll i=1;i<=n-1;i++){
		printf("%lld ",a[f[i]^t[i]^mi(f[i],t[i])]);
	}
	return 0;
}