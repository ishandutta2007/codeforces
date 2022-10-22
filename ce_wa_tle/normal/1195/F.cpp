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
bool pl=0;
typedef int ll;
const ll mod=998244353;
ll readll(void){
	ll x=0,w=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
	for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	return x*w;
}
#define gcd(a,b) sadf(a,b)
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
struct frac{
	ll w,c;
	frac(ll x=11451,ll y=1143):w(x),c(y){
		ll gcd=gcd(max(x,-x),max(y,-y));
//		if(x!=11451)printf("gcd(%d,%d)=%d",x,y,gcd);
		w/=gcd,c/=gcd;
	}
	int operator<(const frac&b)const{
		return w==b.w?c<b.c:w<b.w;
	}
}line[314514];
ll root[314514],cnt=0;
struct node{
	ll val,ls,rs;
}sgm[314514<<5];
void pushup(ll u){
	sgm[u].val=sgm[sgm[u].ls].val+sgm[sgm[u].rs].val;
}
void update(ll&u,ll v,ll l,ll r,ll q){
	u?:u=++cnt;
	if(l==r){
		sgm[u].val=sgm[v].val+1;
		return;
	}
	ll mid=(l+r)>>1;
	if(q<=mid)
	update(sgm[u].ls,sgm[v].ls,l,mid,q),sgm[u].rs=sgm[v].rs;
	else
	update(sgm[u].rs,sgm[v].rs,mid+1,r,q),sgm[u].ls=sgm[v].ls;
	pushup(u);
}
ll query(ll u,ll l,ll r,ll ql,ll qr){
	if(ql<=l&&r<=qr){
		return sgm[u].val;
	}
	ll mid=(l+r)>>1;
	ll ans=0;
	if(mid>=ql)
	ans+=query(sgm[u].ls,l,mid,ql,qr);
	if(mid+1<=qr)
	ans+=query(sgm[u].rs,mid+1,r,ql,qr);
	return ans;
}
ll sl[114514],sr[114514];
bool pr=0;
int main(){
//	printf("%.2lfMiB\n",(&pr-&pl)/1048576.0);
	ll n=readll();
	rep(i,1,n){
		ll k=readll();
		ll x1=readll(),y1=readll(),xl=x1,yl=y1;
		sl[i]=cnt+1;
		rep(j,2,k){
//			printf("ij=%d %d\n",i,j);
			ll x=readll(),y=readll();
			line[++cnt]=frac(x-xl,y-yl);
			xl=x,yl=y;
		}
		line[++cnt]=frac(x1-xl,y1-yl);
		sr[i]=cnt;
	}
//	return 0;
	n=sr[n];
	rep(i,1,n){
		static std::map<frac,ll>lst;
//		printf("line%d=%d %d %d\n",i,line[i].w,line[i].c,lst[line[i]]);
		update(root[i],root[i-1],0,n,lst[line[i]]);
		lst[line[i]]=i;
	}
	ll q=readll();
	rep(i,1,q){
		ll l=readll(),r=readll();
		l=sl[l],r=sr[r];
//		printf("real=%d %d\n",l,r);
		printf("%d\n",query(root[r],0,n,0,l-1)-query(root[l-1],0,n,0,l-1));
	}
	return 0;
}