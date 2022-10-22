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
#define N 477777
ll cnt=1,head[N],to[N],next[N],w[N],h[N],cur[N];
void add(ll x,ll y,ll v) {++cnt,to[cnt]=y,w[cnt]=v,next[cnt]=head[x],head[x]=cnt;}
void add1(ll x,ll y,ll v) {/*printf("l=%lld %lld %lld\n",x,y,v),*/add(x,y,v),add(y,x,0);}
ll s,t;
int bfs(void){
	static std::queue<ll>q;
	while(!q.empty())q.pop();
	memset(h,-1,sizeof(h));
    memcpy(cur,head,sizeof(head));
	h[s]=0,q.push(s);
	while(!q.empty()){
		ll now=q.front();q.pop();
		for(ll i=head[now];i;i=next[i]){
			if(w[i]&&!~h[to[i]])h[to[i]]=h[now]+1,q.push(to[i]);
		}
	}
	return ~h[t];
}
ll dfs(ll now,ll flow){
	if(now==t)return flow;
	ll leave=flow;
	for(ll i=cur[now];i;i=next[i]){
		ll son=to[cur[now]=i];
		if(w[i]&&h[son]==h[now]+1){
			ll f=dfs(son,min(leave,w[i]));
			leave-=f,w[i]-=f,w[i^1]+=f;
			if(leave<=0)break;
		}
	}
	return flow-leave;
}
ll qz=1e10,sum=0,n;
void dinic(void){
	ll ans=0;while(bfs())ans+=dfs(s,inf);
	printf("%lld\n",sum+ans-n*qz);
}
void init(void){
	n=readll();
	s=0,t=2*n+1;
	rep(i,1,n){
		add1(i+n,t,qz);
	}
	rep(i,1,n){
		ll k=readll();
		rep(j,1,k){
			add1(i,n+readll(),qz);
		}
	}
	rep(i,1,n){
		ll x=readll();
		sum+=x;
		add1(0,i,qz-x);
	}
}
int main(int QwQcOrZ,char*Recall_902_[]){
//	IO(P);
	(void)QwQcOrZ,(void)Recall_902_;
	init();
	dinic();
	return 0;
}