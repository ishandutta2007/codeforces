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
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
#define NO return puts("-1"),0
ll m[314541],s[314514];
//struct plane{
//	ll x,w;
//}a[114514];
struct fs{
	ll fz,fm;
	double real()const{
		return fz*1.0/fm;
	}
	fs zh()const{
		if(fm<0)return(fs){-fz,-fm};
		else return*this;
	}
	int operator<(fs b)const{
////		return fz*b.fm*1.0/fm<b.fz*1.0;
//		if(fz==0&&b.fz==0)return 0;
//		if(fz<0&&b.fz>=0)return 1;
//		if(fz>=0&&b.fz<0)return 0;
////		if(fz>=0&&b.fz>=0)
//if((fz*b.fm<b.fz*fm)!=(fz*b.fm*1.0/fm<b.fz*1.0))
//fprintf(stderr,"%lld %lld %lld %lld\n",fz,fm,b.fz,b.fm);
		fs a=zh();
		b=b.zh();
		return a.fz*b.fm<b.fz*a.fm;
//		else return
	}
	int operator==(const fs&b)const{
		return fz*b.fm==b.fz*fm;
	}
}c[314541];
struct qj{
	fs l,r;
	int operator<(const qj&b)const{
		return l==b.l?r<b.r:l<b.l;
	}
}a[114514];
#define lowbit(u) ((u)&-(u))
ll n,w,top;
ll f[314514];
void add(ll u,ll c){
//	printf("%lld %lld\n",u,c);
	while(u<=top+1){
		f[u]+=c;
		u+=lowbit(u);
	}
}
void update(ll l,ll r,ll c){
	add(l,c);
	add(r+1,-c);
}
ll query(ll u){
//	printf("%lld\n",u);
	ll ans=0;
	while(u){
		ans+=f[u];
		u&=~-u;
	}
	return ans;
}
int main(){
	n=readll(),w=readll();
	ll cnt=0;
	top=0;
	if(w!=0){
		rep(i,1,n){
			ll x=readll(),v=readll();
			//x+tv
			//-tw=x+tv
			//t=-x/(v+w)
			//y=x+-xv/(v+w)=xw/(v+w)
			//x+tv
			//tw=x+tv
			//t=x/(w-v)
			//y=x+xv/(w-v)=xw/(w-v)
			c[++top]=a[i].l=(fs){x*w,v+w},
			c[++top]=a[i].r=(fs){-x*w,v-w};
			if(a[i].r<a[i].l)std::swap(a[i].l,a[i].r);
	//		fprintf(stderr,"%.2lf %.2lf\n",a[i].l.real(),a[i].r.real());
		}
		std::sort(a+1,a+n+1);
		std::sort(c+1,c+top+1);
		top=std::unique(c+1,c+top+1)-c-1;
		rep(i,1,n){
			ll l=std::lower_bound(c+1,c+top+1,a[i].l)-c,
			r=std::lower_bound(c+1,c+top+1,a[i].r)-c;
			cnt+=query(l)-query(r+1);
//			rep(j,1,11)printf("%lld ",query(j));
//			puts("");
//			printf("%lld %lld %lld %lld\n",l,r,query(l),query(r));
			update(l,r,1);
		}
	}
	else {
//		static _t[224514],*t=_t+111111;
		static std::map<fs,ll>ma;
		rep(i,1,n){
			ll x=readll(),v=readll();
			fs tx={x,v};
			cnt+=ma[tx];
			ma[tx]++;
		}
	}
	printf("%lld\n",cnt);
	return 0;
}
/*
4 0
-10 10
-1 10
1 -10
10 -10
*/