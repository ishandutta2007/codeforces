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
typedef long long ll;
//const ll mod=998244353;
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
char s1[1145411],s2[1145411];
ll f1[55][55][324],f2[55][55][324],f[55][55];
int a[55],b[55],c[55];
int main(int QwQcOrZ,char*Recall_902_[]){
	(void)QwQcOrZ,(void)Recall_902_;
	scanf("%s%s",s1+1,s2+1);
	ll len1=strlen(s1+1),len2=strlen(s2+1);
	ll n=readll();
	rep(i,1,n){
		a[i]=readchar(),readchar(),readchar(),b[i]=readchar(),c[i]=readchar();
	}
	rep(i,1,len1)f1[i][i][s1[i]]=1;
	rep(len,2,len1){
		rep(l,1,len1-len+1){
			ll r=l+len-1;
			rep(mid,l,r-1)
			rep(i,1,n)f1[l][r][a[i]]|=f1[l][mid][b[i]]&f1[mid+1][r][c[i]],
			dprintf("f1[%lld][%lld][%c]=%lld\n",l,r,a[i],f1[l][r][a[i]]);
		}
	}
	rep(i,1,len2)f2[i][i][s2[i]]=1;
	rep(len,2,len2){
		rep(l,1,len2-len+1){
			ll r=l+len-1;
			rep(mid,l,r-1)
			rep(i,1,n)f2[l][r][a[i]]|=f2[l][mid][b[i]]&f2[mid+1][r][c[i]],
			dprintf("f2[%lld][%lld][%c]=%lld\n",l,r,a[i],f2[l][r][a[i]]);
		}
	}
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	rep(i,1,len1)
	rep(j,1,len2){
		rep(_i,0,i-1)
		rep(_j,0,j-1)
		if(f[i][j]>f[_i][_j]+1){
			rep(c,'a','z')
			if(f1[_i+1][i][c]&&f2[_j+1][j][c]){
				f[i][j]=f[_i][_j]+1;
				break;
			}
		}
	}
	printf("%lld\n",f[len1][len2]>=114514?-1:f[len1][len2]);
	return 0;
}