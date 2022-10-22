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
#define ll long long
#define ifn(x) if(!(x))
ll readll() {
	ll x=0,w=1;
	char c=getchar();
	for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());
	return x*w;
}
char readc() {
	char c=getchar();
	for(;c<=33;c=getchar());
	return c;
}
ll a[2222][2222],f[2222][2222];
ll gcd(ll a,ll b) {
	return a?gcd(b%a,a):b;
}
ll lcm(ll a,ll b) {
	return a*b/gcd(a,b);
}
using namespace std;
//std::queue<std::pair<ll,ll> >qu;
pair<ll,ll> qu[2222222];
ll h=1,t;
ll dx[5]={0,1,-1,0,0};
ll dy[5]={0,0,0,1,-1};
int main() {
	std::srand(std::time(0));
	//freopen("e.in","r",stdin); 
	//freopen("e.out","w",stdout);
	ll n=readll(),m=readll();
	ll t1=readll();
	memset(a,-1,sizeof(a));
	memset(f,0x7f,sizeof(f));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++) {
			a[i][j]=readc()^48;
		} 
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++) {
			if(a[i-1][j]==a[i][j]||a[i][j-1]==a[i][j]||a[i+1][j]==a[i][j]||a[i][j+1]==a[i][j]) {
				f[i][j]=0;
				qu[++t]=make_pair(i,j);
			}
		} 
	}
	while(h<=t){
		pair<ll,ll> pa=qu[h];
		//qu.pop();
		ll i=pa.first,j=pa.second;
//		printf("%lld %lld\n",i,j);
		cout<<flush;
		for(ll ii=1;ii<=4;ii++) {
		ll ti=i+dx[ii],tj=j+dy[ii];
		if(a[ti][tj]>=0&&f[ti][tj]>2333333){
			f[ti][tj]=f[i][j]+1;
			++t;
			qu[t]=make_pair(ti,tj);
		}
		}
		++h;
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=m;j++) {
//			printf("%lld ",f[i][j]);
//		} 
//		puts("");
//	}
	while(t1 --> 0) {
		ll i=readll(),j=readll(),p=readll();
		if(f[i][j]==0)
		printf("%lld\n",(a[i][j]^p)&1);
		else
		if(p<f[i][j])
		printf("%lld\n",a[i][j]);
		else
		printf("%lld\n",((p-f[i][j])&1)^a[i][j]);
	}
	return 0;
}