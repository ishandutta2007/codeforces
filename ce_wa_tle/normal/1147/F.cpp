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
#define flush(x...) printf(x),fflush(stdout)
const ll N=203;
ll a[N][N],id[N][N],w1[N],w2[N];
struct cmp{
	ll i;
	cmp(ll i_):i(i_){}
	int operator()(ll x,ll y)const{
		return a[i][x]<a[i][y];
	}
};
std::queue<ll>q;
int main(int QwQcOrZ,char*Recall_902_[]){
	(void)QwQcOrZ,(void)Recall_902_;
	ll T=readll();
	while(T-->0){
		ll n=readll();
		rep(i,1,n)rep(j,1,n)a[i][j]=readll();
		flush("B\n");
//		while(readll()>0)
//		flush("B\n1\n");
////		readll();
//		continue;
		ll z=readchar(),b=readll();
		if((z=='D')^(b>n))rep(i,1,n)rep(j,1,n)a[i][j]*=-1;
		rep(i,1,n){
			q.push((ll)i);
			w1[i]=w2[i]=0;
			rep(j,1,n)id[i][j]=j;
			std::sort(id[i]+1,id[i]+n+1,cmp(i));
		}
		while(!q.empty()){
			ll u=q.front();q.pop();
//			printf("%lld\n",u);
			while(w1[u]<n){
				ll v=id[u][++w1[u]];
				if(!w2[v]||a[w2[v]][v]<a[u][v]){
					w1[w2[w1[u]=v]]=0;
					if(w2[v])q.push(w2[v]);
//					printf("5=%lld %lld %lld\n",w1[u]=v,u,v);
					w2[v]=u;
					break;
				}
			}
//		rep(i,1,n)printf("%lld %lld\n",w1[i],w2[i]);
//		puts("");
		}
//		rep(i,1,n)printf("%lld %lld\n",w1[i],w2[i]);
		do flush("%lld\n",b<=n?w1[b]+n:w2[b-n]),b=readll();while(b>0);
	}
	return 0;
}
/*
2
3
3 1 9
2 5 7
6 4 8
I 1
*/