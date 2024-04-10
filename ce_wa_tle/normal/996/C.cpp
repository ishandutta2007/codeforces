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
	for(;ch<'a'||ch>'z';ch=getchar());
	return ch;
}
ll a[222222],fst[222222],scd[222222];
ll nxtx[5][114514],nxty[5][114514];
struct ans_t{
	ll id,x,y;
}ans[114514];
ll map[5][114514];
int main(){
	ll n=readll(),cnt=0,k;readll();
	rep(i,1,4){
		rep(j,1,n)
		map[i][j]=readll();
	}
	rep(i,1,n-1)nxtx[2][i]=2,nxty[2][i]=i+1;
	nxtx[2][n]=3,nxty[2][n]=n;
	rep(i,2,n)nxtx[3][i]=3,nxty[3][i]=i-1;
	nxtx[3][1]=2,nxty[3][1]=1;
	ll x=2,y=1,prex=3,prey=1;//,cnt=0;
	rep(i,1,20000){
		ll lx=prex,ly=prey;
		while((lx!=x||ly!=y)&&(!map[x][y]||map[prex][prey])){
			if(map[x][y]){
				if(map[x+1][y]==map[x][y]){
					ans[++cnt]=(ans_t){map[x][y],x+1,y};
					map[x][y]=0;
				}
				else
				if(map[x-1][y]==map[x][y]){
					ans[++cnt]=(ans_t){map[x][y],x-1,y};
//					printf("%lld %lld\n",x,y);
					map[x][y]=0;
				}
			}
			prex=x,prey=y;
			x=nxtx[prex][prey];
			y=nxty[prex][prey];
		}
			if(map[x][y]){
				if(map[x+1][y]==map[x][y]){
					ans[++cnt]=(ans_t){map[x][y],x+1,y};
					map[x][y]=0;continue;
				}
				else
				if(map[x-1][y]==map[x][y]){
					ans[++cnt]=(ans_t){map[x][y],x-1,y};
//					printf("%lld %lld\n",x,y);
					map[x][y]=0;continue;
				}
			}
		if((!map[x][y]||map[prex][prey]))continue;
//					printf("%lld %lld\n",x,y);
		ans[++cnt]=(ans_t){map[x][y],prex,prey};
		std::swap(map[x][y],map[prex][prey]);
//			return 0;
	}
	if(cnt==0)
	puts("-1");
	else
	{
		printf("%lld\n",cnt);
		rep(i,1,cnt){
			printf("%lld %lld %lld\n",ans[i].id,ans[i].x,ans[i].y);
		}
	}
	return 0;
}