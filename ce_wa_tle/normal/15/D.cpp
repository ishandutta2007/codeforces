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
ll ma[1111][1111],sum[1111][1111];
struct s{
	ll j;
	s(ll f=0):j(f){}
	ll operator()(const ll&i)const{
//		printf("m=%lld %lld %lld\n",i,j,ma[i][j]);
		return ma[i][j];
	}
};
template<typename T>
struct Monotone_queue{
	ll h,t;
	ll q[1111],limit;
	T func;
	Monotone_queue(T fc=T(),ll lim=0):h(1),t(0),limit(lim),func(fc){}
	void push_back(ll u){
		while(h<=t&&func(u)<func(q[t]))--t;
		q[++t]=u;
		while(h<=t&&u-q[h]+1>limit)h++;
	}
	void clear(){
		h=1,t=0;
	}
	ll top()const{
		return func(q[h]);
	}
};
Monotone_queue<s>qh[1111];
struct s2{
	ll operator()(const ll&j)const{
		return qh[j].top();
	}
};
Monotone_queue<s2>q;
int main(){
	ll n=readll(),m=readll(),a=readll(),b=readll();
	rep(j,1,m)qh[j]=Monotone_queue<s>(s(j),a);
	q=Monotone_queue<s2>(s2(),b);
	struct ans_t{
		ll ans,i,j;
		int operator<(const ans_t b)const{
			return ans==b.ans?i==b.i?j<b.j:i<b.i:ans<b.ans;
		}
	};
	static ans_t ans[1145141];
	ll tans=0;
	rep(i,1,n){
		q.clear();
		rep(j,1,m){
			ma[i][j]=readll();
			qh[j].push_back(i);
			q.push_back(j);
			sum[i][j]=ma[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
//				printf("1=%lld %lld %lld\n",i,j,qh[j].top());
			if(i>=a&&j>=b){
				ll min=q.top();
//				printf("2=%lld %lld %lld\n",i,j,min);
				ll sums=sum[i][j]-sum[i-a][j]+sum[i-a][j-b]-sum[i][j-b];
				ans[++tans]=(ans_t){sums-min*a*b,i-a+1,j-b+1};
			}
		}
	}
	std::sort(ans+1,ans+tans+1);
	static ll vis[1111][1111];
	ll top=0;
	rep(i,1,tans){
		if(vis[ans[i].i][ans[i].j])continue;
		ans[++top]=ans[i];
		rep(x,max(1,ans[i].i-a+1),min(n,ans[i].i+a-1))
		rep(y,max(1,ans[i].j-b+1),min(m,ans[i].j+b-1))vis[x][y]=1;
	}
	printf("%lld\n",top);
	rep(i,1,top)printf("%lld %lld %lld\n",ans[i].i,ans[i].j,ans[i].ans);
	return 0;
}