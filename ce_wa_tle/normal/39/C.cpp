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
typedef int ll;
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
struct limit_t{
	ll l,r;
}limit[1145141];
ll f[4555][4555],c[8555];
std::vector<ll>vec[5555];
ll g[4555][4555],is_w[4555][4555];
void printans(ll l,ll r){
//	printf("%lld %lld\n",l,r);
	if(l==r)return;
	if(is_w[l][r])printf("%d ",is_w[l][r]);
	if(g[l][r]==-1145141){
		printans(l+1,r);
		return;
	}
	if(!is_w[l][limit[g[l][r]].r])
	printf("%d ",g[l][r]);
	printans(l,limit[g[l][r]].r);
	printans(limit[g[l][r]].r,r);
}
ll cmp(ll a,ll b){
	return limit[a].r<limit[b].r;
}
int main(int QwQcOrZ,char*Recall_902_[]){
	ll n=readll(),x,y,top=0;
	rep(i,1,n)x=readll(),y=readll(),limit[i]=(limit_t){x-y,x+y},c[++top]=x-y,c[++top]=x+y,
	dprintf("%lld %lld\n",limit[i].l,limit[i].r);
	std::sort(c+1,c+top+1);
	top=std::unique(c+1,c+top+1)-c-1;
	rep(i,1,n)limit[i]=(limit_t){
	std::lower_bound(c+1,c+top+1,limit[i].l)-c,
	std::lower_bound(c+1,c+top+1,limit[i].r)-c},
	vec[limit[i].l].push_back((ll)i),
	dprintf("%lld %lld\n",limit[i].l,limit[i].r);
	limit[0]=(limit_t){1,top+1};
	vec[1].push_back(0);
	rep(i,1,top+1){
		std::sort(vec[i].begin(),vec[i].end(),cmp);
	}
//	return 0;
	rep(len,2,top+1){
		rep(l,1,top-len+1+1){
			ll r=l+len-1;
			f[l][r]=f[l+1][r];
			g[l][r]=-1145141;
			ll up=(ll)vec[l].size()-1;
			rep(i,0,up)
			if(limit[vec[l][i]].r<=r)
			if(f[l][limit[vec[l][i]].r]-!!is_w[l][limit[vec[l][i]].r]+f[limit[vec[l][i]].r][r]+1>f[l][r]){
				f[l][r]=f[l][limit[vec[l][i]].r]-!!is_w[l][limit[vec[l][i]].r]+f[limit[vec[l][i]].r][r]+1;
				if(limit[vec[l][i]].r==r){
					is_w[l][r]=vec[l][i];
				}
				else
				g[l][r]=vec[l][i];
//				if(g[l][r]==1)printf("s=%lld %lld\n",limit[vec[l][i]].r,r);
//				printf("f[%lld][%lld]=%lld\n",l,r,f[l][r]);
			};
		}
	}
	printf("%d\n",f[1][top+1]-1);
	printans(1,top+1);
	return 0;
}