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
	for(;ch==' '/*||ch=='\n'*/||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
//ll ny[114514],a[114514],b[114514];
//char p[114541];
ll p,m;
ll ls[114541],rs[114514],size[114514],sn[114541],tn=0,cnt=0,min[34514][111],max[34514][111];
void dfs1(ll u){
	if(!ls[u])return;
	dfs1(ls[u]);
	dfs1(rs[u]);
	size[u]=size[ls[u]]+size[rs[u]]+1;
//	printf("s=%lld\n",size[u]);
	rep(i,0,min(size[u],p)){
		min[u][i]=123456789ll;
		max[u][i]=-123456789ll;
		rep(j,0,i){
			min[u][i]=min(min[u][i],min[ls[u]][j]-max[rs[u]][i-j]);
			if(j>=1)
			min[u][i]=min(min[u][i],min[ls[u]][j-1]+min[rs[u]][i-j]);
			max[u][i]=max(max[u][i],max[ls[u]][j]-min[rs[u]][i-j]);
			if(j>=1)
			max[u][i]=max(max[u][i],max[ls[u]][j-1]+max[rs[u]][i-j]);
//			printf("%lld %lld %lld %lld \n",max[1][0],j-1,max[2][0],i-j);
		}
//		printf("%lld %lld %lld %lld\n",u,i,min[u][i],max[u][i]);
	}
}
void dfs2(ll u){
	if(!ls[u])return;
	dfs2(ls[u]);
	dfs2(rs[u]);
	size[u]=size[ls[u]]+size[rs[u]]+1;
	rep(i,0,min(size[u],m)){
		min[u][i]=123456789ll;
		max[u][i]=-123456789ll;
		rep(j,0,i){
			min[u][i]=min(min[u][i],min[ls[u]][j]+min[rs[u]][i-j]);
			if(j>=1)
			min[u][i]=min(min[u][i],min[ls[u]][j-1]-max[rs[u]][i-j]);
			max[u][i]=max(max[u][i],max[ls[u]][j]+max[rs[u]][i-j]);
			if(j>=1)
			max[u][i]=max(max[u][i],max[ls[u]][j-1]-min[rs[u]][i-j]);
		}
//		printf("%lld %lld %lld %lld\n",u,i,min[u][i],max[u][i]);
	}
}
int main(){
	int ch=readchar();
	memset(min,0x3f,sizeof min);
	memset(max,~0x3f,sizeof max);
	while(ch!='\n'){
//		printf("%c",ch);
//		if(ch=='('){
////			sc[++tc]='(';
//		}
		if(ch==')'){
			++cnt;
//			puts("+1");
			rs[cnt]=sn[tn--];
			ls[cnt]=sn[tn];
			sn[tn]=cnt;
//			tc--;
		}
//		if(ch=='?'){
////			sc[++tc]='?';
//		}
		if(ch>='0'&&ch<='9'){
//			char ch=getchar();
//			for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
//			for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
//puts("+2");
			sn[++tn]=++cnt;
			min[cnt][0]=max[cnt][0]=ch^48;
//			continue;
		}
		ch=readchar();
	}
	p=readll(),m=readll();
	ll s;
//	printf("%lld\n",cnt);
	if(p<=100)dfs1(cnt),s=p;
	if(m<=100)dfs2(cnt),s=m;
	printf("%lld\n",max[cnt][s]);
	return 0;
}