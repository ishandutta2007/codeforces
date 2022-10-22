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
struct node{
	ll a,c,id;
}f[1145141],qu[1145141];
ll s[1145141],use[1145141];
struct fff{
	operator()(const node&a,const node&b)const{
		if(use[a.id]==0&&use[b.id]!=0)return 1;
		if(use[a.id]!=0&&use[b.id]==0)return 0;
		return s[a.a]!=s[b.a]?s[a.a]<s[b.a]:a.c>b.c;
	}
}cmp1;
int cmp2(const node&a,const node&b){
	if(use[a.id]==0&&use[b.id]!=0)return 1;
	if(use[a.id]!=0&&use[b.id]==0)return 0;
	return a.c<b.c;
}
int main(){
	ll n=readll(),m=readll(),limit=0,sum1=0,sum2=0,top=0;
	rep(i,1,n){
		f[i].a=readll(),f[i].c=readll(),f[i].id=i;
		s[f[i].a]++;
		if(f[i].a!=1){
			limit=max(limit,s[f[i].a]);
			qu[++top]=f[i];
		}
	}
	n=top;
	rep(i,1,n)f[i]=qu[i];
	std::sort(f+1,f+n+1,cmp2);
//	std::sort(qu+1,qu+top+1,cmp1);
	rep(i,1,limit+1-s[1])sum2+=f[i].c;//,use[f[i].id]=1;
	ll min=sum2;//,p=up,count=up;
	while(top){
		std::sort(qu+1,qu+top+1,cmp1);
//		printf("%lld %lld %d\n",qu[top].a,top,cmp1((node){4,300,3},(node){5,400,4}));
		s[qu[top].a]--;
		s[1]++;
		use[qu[top].id]=1;
		sum1+=qu[top].c;
		limit=0;
		rep(i,2,m)limit=max(limit,s[i]);
		top--;
		sum2=0;
		std::sort(f+1,f+n+1,cmp2);
		rep(i,1,limit+1-s[1]){
			sum2+=f[i].c;
		}
//		printf("limit=%lld\n",limit);
//		rep(i,1,n)
//			printf("YD=%lld\n",use[f[i].id]);
		min=min(min,sum1+sum2);
//		printf("%lld %lld\n",sum1,sum2);
	}
	printf("%lld\n",min);
	return 0;
}
//std::priority_queue<node,std::vector<node>,fff>qu;
//		node wt=qu.top();
//		sum+=wt.c;
//		s[wt.a]--;
//		s[1]++;
//		qu.pop();
//		while(s[1]+count>s[qu.top().a]+1){
//			while(p>0&&use[f[p].id]!=1)p--;
//			if(!p)break;
//			sum-=f[p].c;
//			count--;
//			p--;
//		}
//		use[wt.id]=-1;
//	ll up=s[qu[top].a]+1-s[1];
//	static ll use[1145141];
//	return 0;
//	rep(i,1,up)sum+=f[i].c,use[f[i].id]=1;
//			qu.push(f[i]);
//		limit=max(limit,s[a[i]]);