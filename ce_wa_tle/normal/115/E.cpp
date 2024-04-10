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
#define _cl_lj(a,b) a##b
#define cl_lj(a,b) _cl_lj(a,b)
#define calc_in_func_df(calcer_t,calcer,code...) struct calcer_t{calcer_t(){code}};static calcer_t calcer
#define calc_in_func(code...) calc_in_func_df(cl_lj(calcer_t,__LINE__),cl_lj(calcer,__LINE__),code)
typedef long long ll;
const ll mod=2520,inf=0x3f3f3f3f3f3f3f3f;
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
struct rd_t{
	ll l,r,s;
	int operator<(const rd_t&b)const{
		return r==b.r?l>b.l:r<b.r;
	}
}rd[214514];
struct node{
	ll val,lazy;
}sgm[8145141];
void pushup(ll u){
	sgm[u].val=max(sgm[u<<1].val,sgm[u<<1|1].val);
}
void pushdown(ll u){
	sgm[u].val+=sgm[u].lazy;
	sgm[u<<1].lazy+=sgm[u].lazy;
	sgm[u<<1|1].lazy+=sgm[u].lazy;
	sgm[u].lazy=0;
}
void update(ll u,ll l,ll r,ll ql,ll qr,ll c){
//	printf("%lld %lld %lld %lld %lld\n",u,l,r,ql,qr);;
	pushdown(u);
	if(ql<=l&&r<=qr){
		sgm[u].lazy=c;
		pushdown(u);
		return;
	}
	ll mid=(l+r)>>1;
	if(ql<=mid)update(u<<1,l,mid,ql,qr,c);
	else pushdown(u<<1);
	if(qr>=mid+1)update(u<<1|1,mid+1,r,ql,qr,c);
	else pushdown(u<<1|1);
	pushup(u);
}
ll query(ll u,ll l,ll r,ll ql,ll qr){
	pushdown(u);
	if(ql<=l&&r<=qr)return sgm[u].val;
	ll mid=(l+r)>>1;
	return max(
		ql<=mid?query(u<<1,l,mid,ql,qr):0,
		qr>=mid+1?query(u<<1|1,mid+1,r,ql,qr):0
	);
}
ll s[214514],a[214514],f[214514];
int main(int QwQcOrZ,char*Recall_902_[]){
//	IO(P);
	(void)QwQcOrZ,(void)Recall_902_;
	ll n=readll(),m=readll();
	rep(i,1,n)s[i]=s[i-1]+(a[i]=readll());
	rep(i,1,m){
		rd[i].l=readll(),rd[i].r=readll(),rd[i].s=readll();
	}
	//f[i]=max(f[i],d[l-1]-s[i]+s[l-1])
	std::sort(rd+1,rd+m+1);
	ll p=1;
	ll max=0;
	rep(i,1,n){
		f[i]=f[i-1];
		update(1,0,n,i,i,f[i]+s[i]);
//			rep(j,0,n)printf("%lld ",query(1,0,n,j,j));
//			puts("");
		while(rd[p].r==i){
			update(1,0,n,0,rd[p].l-1,rd[p].s);
//			rep(j,0,n)printf("%lld ",query(1,0,n,j,j));
//			puts("");
			ll fi=f[i];
			f[i]=max(f[i],query(1,0,n,0,i)-s[i]);
			update(1,0,n,i,i,f[i]-fi);
			max=max(max,f[i]);
//			printf("f[%lld]=%lld\n",i,f[i]);
//			rep(j,0,n)printf("%lld ",query(1,0,n,j,j));
//			puts("");
			p++;
		}
	}
	printf("%lld\n",max);
	return 0;
}