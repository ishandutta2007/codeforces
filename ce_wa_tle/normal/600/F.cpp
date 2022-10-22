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
#define dprintf(x...) (void)(0)
#define _cl_lj(a,b) a##b
#define cl_lj(a,b) _cl_lj(a,b)
#define calc_in_func_df(calcer_t,calcer,code...) struct calcer_t{calcer_t(){code}};static calcer_t calcer
#define calc_in_func(code...) calc_in_func_df(cl_lj(calcer_t,__LINE__),cl_lj(calcer,__LINE__),code)
typedef long long ll;
const ll mod=2520,inf=0x3f3f3f3f3f3f3f3f;
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
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
ll w0[1111][1111],w1[1111][1111],id[1111][1111],x[114514],y[114514],ans[114514],vis[2111];//,p,q;
ll p0,p1;
void dfs(ll cl,ll u,ll v){
	if(vis[u+1000*cl])return;
	ll p=cl?p1:p0;
//	printf("s=%lld %lld %lld\n",u,v,p);
	vis[u+1000*cl]=1;
	if(v[cl?w0:w1][p])dfs(cl^1,v,v[cl?w0:w1][p]);
	if(u[cl?w1:w0][p^p0^p1]==v)u[cl?w1:w0][p^p0^p1]=0;
	if(v[cl?w0:w1][p^p0^p1]==u)v[cl?w0:w1][p^p0^p1]=0;
	u[cl?w1:w0][p]=v,v[cl?w0:w1][p]=u;
}
int main(int QwQcOrZ,char*Recall_902_[]){
	//IO(S);
	(void)QwQcOrZ,(void)Recall_902_;
	ll a=readll(),b=readll(),m=readll(),max=0;
	rep(i,1,m){
		x[i]=readll(),y[i]=readll(),id[x[i]][y[i]]=i;
	}
	rep(i,1,m){
		for(p0=1;w0[x[i]][p0];p0++);
		for(p1=1;w1[y[i]][p1];p1++);
		memset(vis,0,sizeof vis);
//		printf("%lld %lld\n",p0,p1);
		dfs(0,x[i],y[i]);
//		puts("");
		max=max(max,max(p0,p1));
	}
	rep(i,1,a)rep(j,1,max)ans[id[i][w0[i][j]]]=j;
	printf("%lld\n",max);
	rep(i,1,m)printf("%lld ",ans[i]);
	return 0;
}
/*
10 10 67
1 1
1 2
1 3
1 7
1 9
1 10
2 1
2 2
2 3
2 6
2 8
2 10
3 2
3 3
3 6
3 8
3 9
3 10
4 1
4 4
4 5
4 6
4 7
4 8
5 2
5 4
5 7
5 8
5 9
5 10
6 1
6 2
6 3
6 4
6 6
6 8
6 9
6 10
7 2
7 4
7 6
7 9
7 10
8 3
8 4
8 5
8 6
8 7
8 8
8 9
8 10
9 1
9 2
9 3
9 5
9 6
9 7
9 8
9 9
9 10
10 1
10 3
10 4
10 5
10 8
10 9
10 10
*/