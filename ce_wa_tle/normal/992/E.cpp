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
ll iabs(ll x){
	return max(x,-x);
}
int readchar(void){
	int ch=getchar();
	for(;ch<'a'||ch>'z';ch=getchar());
	return ch;
}
//ll f[222222],*t=f+111111;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll power(ll a,ll b){
//	a%=mod;
	ll ans=1;
	while(b){
		b&1&&(ans=ans*a%mod);
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll a[214541],next[214514],f[214514];
#define lowbit(u) (u)&-(u)
ll n;
ll lower_bound(ll pos){
	ll now=0,val=0;
	rfor(ll i=131072<<1;i;i>>=1)
	if(now+i<=n&&val+f[now+i]<pos){
		val+=f[now+=i];
	}
	return now+1;
}
ll query(ll u){
	ll ans=0;
	while(u){
		ans+=f[u];
		u&=~-u;
	}
	return ans;
}
void update(ll u,ll c){
	while(u<=n){
		f[u]+=c;
		u+=lowbit(u);
	}
}
int main(){
	n=readll();
	ll q=readll();
	rep(i,1,n)a[i]=readll(),update(i,a[i]);
	rep(i,1,q){
		ll x=readll(),y=readll();
		update(x,y-a[x]);
		a[x]=y;
		if(a[1]==0){
			puts("1");
			continue;
		}
		ll now=1,lnow=now,val=query(now),p=0;
//			printf("%lld %lld\n",now,val);
//			return 0;
		while(now<=n&&val<=1e9){
//			val=query(now);
			now=lower_bound(val*2);
			if(now<=lnow)break;
			if(now>n)break;
			val=query(now);
			if(val==a[now]*2){
				p=1;
				printf("%lld\n",now);
				break;
			};
			lnow=now;
//			now++;
//			val=query(now);
//			printf("%lld %lld\n",now,val);
//		return 0;
		}
		if(!p){
			puts("-1");
		}
	}
	return 0;
}