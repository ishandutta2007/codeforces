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
#define max(x,y) std::max(ll(x),ll(y))
#define min(x,y) std::min(ll(x),ll(y))
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
typedef long long ll;
typedef long double ld;
const ll mod=998244353;
ll readll(void){
	ll x=0,w=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
	for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	return x*w;
}
ll Log[314514];
struct stt{
	ll st[314514][24],len;
	ll(*func)(ll,ll);
	stt(ll n,ll(*function)(ll,ll)):len(n),func(function){
		rep(i,2,n)Log[i]=Log[i/2]+1;
		rep(i,1,n)st[i][0]=i;
		rep(j,1,22){
			rep(i,1,n-(1<<j)+1){
				st[i][j]=func(st[i][j-1],st[i+(1<<~-j)][j-1]);
			}
		}
	}
	ll query(ll l,ll r)const{
		ll length=r-l+1,loglen=Log[length];
//		printf("%lld %lld %lld\n",l,r,func(st[l][loglen],st[r-(1<<loglen)+1][loglen]));
		return func(st[l][loglen],st[r-(1<<loglen)+1][loglen]);
	}
};
ll l[314154][24],r[314154][24];
ll mini(ll a,ll b){
	return l[a][0]<l[b][0]?a:b;
}
ll maxi(ll a,ll b){
	return r[a][0]<r[b][0]?b:a;
}
ll a[314514];
int main(){
	ll n=readll();
	if(n==1)return puts("0"),0;
	rep(i,1,n){
		a[i]=a[i+n]=a[i+n+n]=readll();
	}
	rep(i,1,3*n){
		l[i][0]=max(1,i-a[i]);
		r[i][0]=min(i+a[i],3*n);
	}
	static stt ql(3*n,mini),qr(3*n,maxi);
	rep(j,1,Log[3*n])
	rep(i,1,3*n){
		ll tl=ql.query(l[i][j-1],r[i][j-1])
		,tr=qr.query(l[i][j-1],r[i][j-1]);
		l[i][j]=min(l[tl][j-1],l[tr][j-1]);
		r[i][j]=max(r[tl][j-1],r[tr][j-1]);
	}
	rep(i,n+1,n*2){
		ll u=i,v=i,ans=0;
		per(j,Log[3*n],0){
//		printf("j=%lld %lld %lld %lld %lld\n",j,l[u][j],r[v][j],max(r[u][j],r[v][j]),min(l[u][j],l[v][j]));
			if(max(r[u][j],r[v][j])-min(l[u][j],l[v][j])+1>=n)continue;
			ll nu=ql.query(l[u][j],r[v][j]),
			nv=qr.query(l[u][j],r[v][j]);
			u=nu,v=nv;
			ans+=1<<j;
		}
		printf("%lld ",ans+1);
	}
	return 0;
}