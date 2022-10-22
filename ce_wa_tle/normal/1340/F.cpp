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
typedef long double ld;
const ll mod=1e9+9,K=233,inf=0x3f3f3f3f3f3f3f3f,N=114514;
inline ll readll(void){
	register ll x=0,w=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
	for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	return x*w;
}
inline ll iabs(ll x){
	return max(x,-x);
}
inline int readchar(void){
	int ch=getchar();
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
ll mc[N+7];
struct calc_t{
	calc_t(){
		mc[0]=1;
		rep(i,1,N)mc[i]=mc[i-1]*K%mod;
	}
}calc;
struct hs{
	ll len,val;
	hs operator+(const hs&b)const{
		return(hs){len+b.len,(val*mc[b.len]+b.val)%mod};
	}
	hs operator-(const hs&b)const{
		return(hs){len-b.len,(val+mod-b.val*mc[len-b.len]%mod)%mod};
	}
	int operator==(const hs&b)const{
		return len==b.len&&val==b.val;
	}
	int operator!=(const hs&b)const{
		return len!=b.len||val!=b.val;
	}
};
struct node{
	ll hf:2;
	hs l,r;//)]}>({[<
	ll ls,rs;
	void print()const{
		printf("%lld %lld,%lld %lld,%lld %lld %lld\n",hf,l.len,l.val,r.len,r.val,ls,rs);
	}
}sgm[N*4+233];
ll cnt=0;
hs pre(ll u,ll x){
	const node&lson=sgm[sgm[u].ls],&now=sgm[u];
	if(x==0)return(hs){0,0};if(x==now.l.len)return now.l;
	if(x>lson.l.len){
		return lson.l+(pre(sgm[u].rs,lson.r.len+x-lson.l.len)-lson.r);
	}
	else return pre(sgm[u].ls,x);
}
hs suc(ll u,ll x){
	const node&rson=sgm[sgm[u].rs],&now=sgm[u];
	if(x==0)return(hs){0,0};if(x==now.r.len)return now.r;
	if(x>rson.r.len){
		return rson.r+(suc(sgm[u].ls,rson.l.len+x-rson.r.len)-rson.l);
	}
	else return suc(sgm[u].rs,x);
}
inline void pushup(register ll u){
//	if(u<N*2)return;
	const node&rson=sgm[sgm[u].rs],&lson=sgm[sgm[u].ls];
	if(!lson.hf||!rson.hf)return void(sgm[u].hf=0);
//	puts("YD");
	if(lson.r.len>=rson.l.len){
//		if(u==2)
//		printf("\nDSFA=%lld %lld %lld %lld\n",sgm[u].ls,rson.l.len,suc(sgm[u].ls,rson.l.len).val,rson.r.val),
//		printf("%lld\n\n",(lson.r+(lson.r-rson.l)).len,lson.r.len,lson.r);
		if(suc(sgm[u].ls,rson.l.len)!=rson.l)sgm[u].hf=0;
		else sgm[u]=(node){1,lson.l,rson.r+(lson.r-rson.l),sgm[u].ls,sgm[u].rs};
	}
	else {
		if(pre(sgm[u].rs,lson.r.len)!=lson.r)sgm[u].hf=0;
		else sgm[u]=(node){1,lson.l+(rson.l-lson.r),rson.r,sgm[u].ls,sgm[u].rs};
	}
//	puts("YD");
}
ll a[N];
ll build(ll l,ll r){
	ll u=++cnt;
	if(l==r)
	if(a[l]<0)sgm[u]=(node){1,1,-a[l],0,0,0,0};
	else sgm[u]=(node){1,0,0,1,a[l],0,0};
	else{ll mid=(l+r)>>1;sgm[u].ls=build(l,mid),sgm[u].rs=build(mid+1,r),pushup(u);}
//	printf("q=%lld %lld %lld\ns=",u,l,r);
//	sgm[u].print();
	return u;
}
//~;'n@#[i2]$dA\-a%&/y#,=i*"Al+)Ie|^(!>.<
ll tm=0;
void update(ll u,ll l,ll r,ll q,ll c){
	if(l==r)
	if(c<0)sgm[u]=(node){1,1,-c,0,0,0,0};
	else sgm[u]=(node){1,0,0,1,c,0,0};
	else{
		ll mid=(l+r)>>1;q<=mid?update(sgm[u].ls,l,mid,q,c):
		update(sgm[u].rs,mid+1,r,q,c),pushup(u);
	}
}
ll query(ll u,ll l,ll r,ll ql,ll qr){
//	printf("%lld\n",u);
	if(r<ql||qr<l)return 0;
	if(ql<=l&&r<=qr)return u;
	ll mid=(l+r)>>1;
	ll n=++cnt;
	node&now=sgm[n];
	now.ls=query(sgm[u].ls,l,mid,ql,qr);
	now.rs=query(sgm[u].rs,mid+1,r,ql,qr);
	pushup(n);
	return n;
}
int main(){
//	IO(H);
	ll n=readll(),k=readll();
	rep(i,1,n)a[i]=readll();
	sgm[0].hf=1;
	build(1,n);
	ll lcnt=cnt;
	ll m=readll();
	rep(i,1,m){
		ll f=readll(),x=readll(),y=readll();
		if(f==1){
			update(1,1,n,x,y);
		}
		else{
			cnt=lcnt;
			const node&jc=sgm[query(1,1,n,x,y)];
//			jc.print();
			puts(jc.hf&&jc.l.len==0&&jc.r.len==0?"Yes":"No");
		}
	}
	return 0;
}
/*
10 10
10 4 2 -2 1 -1 -4 8 -8 -10
100000
1 1 4
1 10 -4
2 6 9
1 3 4
1 4 -4
2 2 8
2 3 4
2 2 9
2 3 7
2 8 9
2 2 4
2 1 7
2 3 8
1 5 6
1 6 -6
2 5 6
1 8 5
1 9 -5
1 3 7
1 4 -7
1 8 10
1 9 -10
1 2 8
1 7 -8
2 3 4
2 4 6
2 1 3
1 8 1
1 9 -1
2 2 5
1 1 9
1 10 -9
1 5 4
1 6 -4
1 5 4
1 6 -4
2 2 7
2 8 9
2 2 7
2 2 7
1 2 3
1 7 -3
1 3 7
1 4 -7
2 1 10
2 5 6
2 5 8
1 8 6
1 9 -6
1 1 3
1 10 -3
1 3 3
1 4 -3
2 5 6
2 5 6
2 3 6
1 1 10
1 10 -10
1 2 3
1 7 -3
1 8 10
1 9 -10
*/