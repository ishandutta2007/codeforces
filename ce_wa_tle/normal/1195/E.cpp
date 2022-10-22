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
ll ws(ll u){
	ll cnt=0;
	while(u){
		u/=10;
		cnt++;
	}
	return cnt;
}
ll as[3333][3333];
ll qs[3333][3333],q[3333],hs[3333],ts[3333];
//template<typename fc>
//struct dddl{
//	ll q[3333];
//	ll x;
//	fc func;
//	ll h,t;
//	dddl(ll n,fc function):x(n),func(function),h(1),t(0){}
//	void push_back(const ll&xx){
//		while(h<=t&&func(q[t])<func(xx))t--;
//		while(h<=t&&q[h]<xx-x+1)h++;
//	}
//	void top(){
//		return func(q[h]);
//	}
//};
int main(){
	ll n=readll(),m=readll(),a=readll(),b=readll(),sum=0;
	ll g0=readll(),x=readll(),y=readll(),z=readll();
	rep(i,1,n){
		rep(j,1,m){
			as[i][j]=g0;
			g0=(g0*x+y)%z;
//			printf("%lld\n",as[i][j]);
		}
	}
	rep(i,1,m)hs[i]=1;
	rep(i,1,n){
		rep(j,1,m){
			#define push1(h,t,q,minss,i)\
			while(h<=t&&minss(q[t])>minss(i))t--;\
			q[++t]=i
			#define push2(h,t,q,limit)\
			while(h<=t&&q[h]<limit)h++;
			#define min_(x) as[x][j]
			push1(hs[j],ts[j],qs[j],min_,i);
//			while(hs[j]<=ts[j]&&as[qs[j][ts[j]]][j]>as[i][j])ts[j]--;
//			qs[j][++ts[j]]=i;//qs[w]->h
		}
		if(i>=a){
			if(i>a){
				rep(j,1,m){
					push2(hs[j],ts[j],qs[j],i-a+1);
//					while(hs[j]<=ts[j]&&qs[j][hs[j]]<i-a+1)hs[j]++;
				}
			}
			ll h=1,t=0;
			rep(j,1,m){
				#define ans(minss,q,h) minss(q[h]) 
				#define mins(s) as[qs[s][hs[s]]][s]
				push1(h,t,q,mins,j);
//				while(h<=t&&mins(q[t])>mins(j))t--;
//				q[++t]=j;
				if(j>=b){
					if(j>b){
						push2(h,t,q,j-b+1);
	//					while(h<=t&&q[h]<j-b+1)h++;
					}
					sum+=ans(mins,q,h);
				}
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}