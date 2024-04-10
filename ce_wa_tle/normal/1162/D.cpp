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
struct ss2{
	ll l,r;
	int operator<(const ss2&b)const{
		return l==b.l?r<b.r:l<b.l;
	}
}line[214514],cpy[214514];
ll p[114514];
int main(){
	ll n=readll(),m=readll();
	rep(i,1,m){
		line[i].l=readll(),line[i].r=readll();
		if(line[i].l<line[i].r)std::swap(line[i].l,line[i].r);
	}
	std::sort(line+1,line+m+1);
	ll top=0;
	rep(i,2,n){
		if(!p[i]){
			p[++top]=i;
		}
		rfor(ll j=1;j<=top&&p[j]*i<=n;j++){
			p[i*p[j]]=1;
			if(!(i%p[j])){
				break;
			}
		}
	}
	rep(i,1,top)
	if(n%p[i]==0){
		ll k=n/p[i],ssr=0;
		rep(j,1,m){
			cpy[j].l=(line[j].l+k-1)%n+1;
			cpy[j].r=(line[j].r+k-1)%n+1;
			if(cpy[j].l<cpy[j].r)std::swap(cpy[j].l,cpy[j].r);
//			printf("%lld %lld %lld %lld %lld\n",k,line[j].l,line[j].r,cpy[j].l,cpy[j].r);
			if(cpy[j].l==line[1].l){
				ssr=ssr?:j;
			}
		}
	std::sort(cpy+1,cpy+m+1);
		ll p=1;
		rep(j,1,m){
//			printf("%lld %lld %lld %lld %lld\n",k,line[j].l,line[j].r,cpy[j].l,cpy[j].r);
			if(line[j].l!=cpy[j].l||line[j].r!=cpy[j].r){
//			printf("%lld %lld %lld %lld %lld\n",k,line[j].l,line[j].r,cpy[j].l,cpy[j].r);
				p=0;break;
			}
		}
//		ll p=1;
//		rep(j,1,m){
//			if(line[j].l!=cpy[ssr].l&&line[j].r!=cpy[ssr].r){
////			printf("%lld %lld %lld %lld %lld %lld %lld\n",k,j,ssr,line[j].l,line[j].r,cpy[ssr].l,cpy[ssr].r);
//				p=0;break;
//			}
//			++(ssr%=m);
//		}
		if(p==1){
			return puts("YES"),0;
		}
	}
	puts("NO");
	return 0;
}