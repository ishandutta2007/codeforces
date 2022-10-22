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
ll a[2333][2333],sa[2333][2333];
int readchar(void){
	char ch=getchar();
	for(;ch=='\n'||ch==' '||ch=='\t'||ch=='\r';ch=getchar());
	return ch;
}
int main(){
	ll n=readll(),k=readll();
	if(k>=2*n-1){
		rep(i,1,2*n-1)putchar(97);
		return 0;
	}
	rep(i,1,n){
		rep(j,1,n){
			a[i][j]=readchar();
		}
	}
	memset(sa,1145141,sizeof sa);
	sa[0][1]=0;
	rep(i,1,n){
		rep(j,1,n){
			sa[i][j]=(a[i][j]!='a')+min(sa[i-1][j],sa[i][j-1]);
			if(sa[i][j]<=k)a[i][j]='a';
		}
	}
//	rep(i,1,n){
//		rep(j,1,n){
//			printf("%lld ",sa[i][j]);
//		}
//		puts("");
//	}
	static ll is_best[2222][2222];
	is_best[1][1]=1;
//	rep(i,1,n){
//		rep(j,1,n){
//			printf("%c",a[i][j]);
//		}
//		puts("");
//	}
	putchar(a[1][1]);
	rep(i_j,3,n*2){
		ll min='z'+1;
		rep(i,1,n)
		if(i_j-i>=1&&i_j-i<=n){
			ll j=i_j-i;
			if(is_best[i-1][j]||is_best[i][j-1])min=min(min,a[i][j]);
		}
		rep(i,1,n)
		if(i_j-i>=1&&i_j-i<=n){
			ll j=i_j-i;
			if(is_best[i-1][j]||is_best[i][j-1])
			if(min==a[i][j])is_best[i][j]=1;
		}
		putchar(min);
	}
//	rep(i,1,n){
//		rep(j,1,n){
//			printf("%lld ",is_best[i][j]);
//		}
//		puts("");
//	}
//	#define id(x,y) ((x-1)*n+y-1)
//	per(i,n,1){
//		per(j,n,1){
//			if(a[i+1][j]>a[i][j+1]){
//				to[i][j]=id(i+1,j);
//			}
//			if(a[i+1][j]<a[i][j+1]){
//				to[i][j]=id(i,j+1);
//			}
//			if(a[i+1][j]==a[i][j+1]){
//				if(fst[i][j])
//			}
//		}
//	}
	return 0;
}
/*
7 6
ypnxnnp
pnxonpm
nxanpou
xnnpmud
nhtdudu
npmuduh
pmutsnz
*/