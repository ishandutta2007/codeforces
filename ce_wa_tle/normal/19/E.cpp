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
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
ll cnt=0,flag=0,vis2[114541],f1[114541],
f2[114541],deep[114541],no_xm1[114541],no_xm2[114541],
to[114541],e[114541],next[114541],head[114541];
void add(ll u,ll v,ll id){
	++cnt;
	to[cnt]=v;
	e[cnt]=id;
	next[cnt]=head[u];
	head[u]=cnt;
}
void dfs(ll u,ll fa){
//	vis[u]=1;
	deep[u]=deep[fa]+1;
//	printf("d=%lld %lld\n",u,deep[u]);
	rfor(ll i=head[u];i;i=next[i])
	if(to[i]^fa){
		if(!deep[to[i]])
		dfs(to[i],u);
		else
		if(deep[to[i]]>=deep[u])continue;
		else
		if(((deep[to[i]]^deep[u])&1)==0){
//			printf("p=%lld %lld %lld %lld\n",to[i],u,deep[1],deep[2]);
			flag++;
			f1[e[i]]=-1;
//			printf("p=%lld %lld\n",e[i],f1[e[i]]);
			no_xm1[u]++;
			no_xm1[to[i]]--;
		}
		else{
//			printf("ps=%lld %lld %lld %lld\n",to[i],u,deep[1],deep[2]);
			no_xm2[u]++;
			no_xm2[to[i]]--;
		}
	}
}
void dfs2(ll u,ll fa,ll id){
	vis2[u]=1;
	rfor(ll i=head[u];i;i=next[i])
	if(to[i]^fa){
		if(!vis2[to[i]]){
			dfs2(to[i],u,e[i]);
			no_xm1[u]+=no_xm1[to[i]];
			no_xm2[u]+=no_xm2[to[i]];
		}
	}
//	printf("sf=%lld %lld\n",id,no_xm1[u]);
	f1[id]=no_xm1[u];
	f2[id]=no_xm2[u];
}
int main(){
	ll n=readll(),m=readll();
	rep(i,1,m){
		ll x=readll(),y=readll();
		add(x,y,i);
		add(y,x,i);
	}
	rep(i,1,n)
	if(!deep[i]){
		dfs(i,0);
	}
	rep(i,1,n)
	if(!vis2[i]){
		dfs2(i,0,0);
	}
//	printf("f=%lld\n",flag);
	if(flag==0){
		printf("%lld\n",m);
		rep(i,1,m)printf("%lld ",i);
	}
	if(flag==1){
		ll top=1;
//		rep(i,1,m){
//			printf("ssf=%lld %lld %lld\n",i,f1[i],f2[i]);
//		}
		rep(i,1,m)if(f1[i]==1)if(f2[i]==0)++top;
		printf("%lld\n",top);
		rep(i,1,m)if(f1[i]==1||f1[i]==-1)
		if(f2[i]==0||f1[i]==-1)printf("%lld ",i);
	}
	if(flag>1){
		ll top=0;
//		rep(i,1,m){
//			printf("ssf=%lld %lld %lld\n",i,f1[i],f2[i]);
//		}
		rep(i,1,m)if(f1[i]==flag&&f2[i]==0)++top;
		printf("%lld\n",top);
		rep(i,1,m)if(f1[i]==flag&&f2[i]==0)printf("%lld ",i);
	}
	return 0;
}
/*
4 5
1 3
4 1
3 4
2 3
1 2
*/