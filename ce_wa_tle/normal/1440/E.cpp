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
	for(;ch<'0'||ch>'1';ch=getchar());
	return ch;
}
struct ifm{
	ll an,sum;
	ifm operator+(const ifm&b)const{
		return(ifm){b.an,sum+b.sum};
	}
};
struct node{
	ifm val;
	ll lazy;
}sgm[214541<<3];
ll a[214514];
void pushup(ll u){
	sgm[u].val=sgm[u<<1].val+sgm[u<<1|1].val;
}
void build(ll u,ll l,ll r){
	if(l==r){
		sgm[u].val=(ifm){a[l],a[l]};
		return;
	}
	ll mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void pushdown(ll u,ll l,ll r){
	if(sgm[u].lazy){
		sgm[u].val=(ifm){sgm[u].lazy,sgm[u].lazy*(r-l+1)};
		if(l!=r)
		sgm[u<<1].lazy=sgm[u].lazy,
		sgm[u<<1|1].lazy=sgm[u].lazy;
		sgm[u].lazy=0;
	}
}
void update(ll u,ll l,ll r,ll ql,ll qr,ll c){
	pushdown(u,l,r);
	if(ql>qr)return;
	if(ql<=l&&r<=qr){
		return sgm[u].lazy=c,pushdown(u,l,r);
	}
	ll mid=(l+r)>>1;
	if(ql<=mid)update(u<<1,l,mid,ql,qr,c);
	else pushdown(u<<1,l,mid);
	if(mid+1<=qr)update(u<<1|1,mid+1,r,ql,qr,c);
	else pushdown(u<<1|1,mid+1,r);
	pushup(u);
}
ll query(ll u,ll l,ll r,ll ql,ll qr){
	pushdown(u,l,r);
	if(ql>qr)return 0;
	if(ql<=l&&r<=qr){
//		printf("??%lld\n",sgm[u].val.sum);
		return sgm[u].val.sum;
	}
	ll mid=(l+r)>>1,sum=0;
	if(ql<=mid)sum+=query(u<<1,l,mid,ql,qr);
	if(mid+1<=qr)sum+=query(u<<1|1,mid+1,r,ql,qr);
	return sum;
}
ll n,q;
ll lower_bound(ll pos){
	ll u=1,l=1,r=n;
	pushdown(u,l,r);
	while(l!=r){
		ll mid=(l+r)>>1;
		pushdown(u<<1,l,mid);
		pushdown(u<<1|1,mid+1,r);
		if(sgm[u<<1].val.an<=pos)u<<=1,r=mid;
		else u=u<<1|1,l=mid+1;
	}
	return l;
}
ll upper_bound_sum(ll pos){
	ll u=1,l=1,r=n,ans;
	if(pos>=sgm[1].val.sum)return n;
	pushdown(u,l,r);
	while(l!=r){
		ll mid=(l+r)>>1;
		pushdown(u<<1,l,mid);
		pushdown(u<<1|1,mid+1,r);
		if(sgm[u<<1].val.sum>pos)u<<=1,r=mid,ans=mid-1;
		else pos-=sgm[u<<1].val.sum,u=u<<1|1,l=mid+1,ans=mid;
	}
	return ans;
}
int main(){
	n=readll(),q=readll();
	rep(i,1,n)a[i]=readll();
	build(1,1,n);
	rep(i,1,q){
		ll f=readll(),x=readll(),y=readll();
		if(f==1){
			ll l=lower_bound(y);
			update(1,1,n,l,x,y);
		}
		else{
			ll cnt=0;
			while(x<=n&&y>=sgm[1].val.an){
				ll l=max(x,lower_bound(y));
				ll sum_l=query(1,1,n,1,l-1);
				//y>=sum_r-sum_l
				//sum_r<=y+sum_l
				ll r=upper_bound_sum(y+sum_l);
				ll sum_r=query(1,1,n,1,r);
				y-=sum_r-sum_l,cnt+=r-l+1;
				x=r+1;
//				printf("%lld %lld %lld %lld %lld %lld\n",y,cnt,l,sum_l,r,sum_r);
//				if(r<=l)x;
//			return 0;
			}
			printf("%lld\n",cnt);
		}
	}
	return 0;
}