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
typedef int ll;
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
struct sl{
	int x,y;
	sl operator+(const sl&b)const{
		return(sl){x+b.x,y+b.y};
	}
	sl operator-(const sl&b)const{
		return(sl){x-b.x,y-b.y};
	}
	sl operator-()const{
		return(sl){-x,-y};
	}
	ll dis()const{
		return sqrt(1ll*x*x+1ll*y*y);
	}
	int safe()const{
		return dis()<=1.5e6;
	}
};
struct slf{
	sl val;
	int last,zf;
}f[114514];
ll cmp(slf a,slf b){
	return a.val.dis()*!!b.zf<b.val.dis()*!!a.zf;
}
int main(){
	srand(114514);
	ll n=readll();
	rep(i,1,n){
		f[i].val.x=readll(),f[i].val.y=readll();
		f[i].zf=i;
	}
	while(1){
		std::random_shuffle(f+1,f+n+1);
		static slf bl[114514][100];
		memset(bl,0,sizeof bl);
		ll sz=1;
		rep(i,1,n){
			ll lsz=sz;sz=0;
			lsz=min(lsz,1);
			rep(j,1,lsz){
//				bl[]
				bl[i][++sz]=(slf){.val=bl[i-1][j].val+f[i].val,.last=j,.zf=+1},
				bl[i][++sz]=(slf){.val=bl[i-1][j].val-f[i].val,.last=j,.zf=-1};
//				printf("%d %d s=%d \n",i,j,bl[i][j].zf);
			}
			std::sort(bl[i]+1,bl[i]+sz+1,cmp);
		}
		if(bl[n][1].val.safe()&&bl[n][1].zf!=0){
			ll j=1;
			static ll ans[114514];
			per(i,n,1)ans[f[i].zf]=bl[i][j].zf,j=bl[i][j].last;
			rep(i,1,n){
				printf("%d ",ans[i]);
				if(ans[i]==0)bl[-114514][-233].zf=1;
			}
			return 0;
		}
	}
	return 0;
}