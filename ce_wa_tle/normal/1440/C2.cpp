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
//ll a[1145141];
struct ans_t{
	ll x1,y1,x2,y2,x3,y3;
	ans_t add(ll i,ll j)const{
		return(ans_t){x1+i,y1+j,x2+i,y2+j,x3+i,y3+j};
	}
}search[4]={
	0,0,0,1,1,0,
	0,0,0,1,1,1,
	0,0,1,0,1,1,
	0,1,1,0,1,1
},ans[114541];
ll a[1145][1145],top;
void dfs(ll x1,ll y1,ll x2,ll y2){
	static ll _q[4][4][513],_dis[4][4][513],dq[4][4];
	static ans_t _prek[4][4][513];
	ll n=x2-x1+1,m=y2-y1+1;
//	printf("q=%lld %lld\n",n,m);
	#define id(i,j) (1<<((i)*m+(j)))
	#define s(u,fl) u^id(fl.x1,fl.y1)^id(fl.x2,fl.y2)^id(fl.x3,fl.y3)
	if(!dq[n][m]){
		dq[n][m]=1;
		ll*q=_q[n][m],*dis=_dis[n][m];//,*pre=_pre[n][m];
		ans_t*prek=_prek[n][m];
		ll h=1,t=1;q[1]=0,dis[0]=1;
		while(h<=t){
			ll u=q[h++];
//			printf("s=%lld %lld\n",u,s(u,prek[u]));
			rep(i,0,n-2)
			rep(j,0,m-2){
				rep(k,0,3){
					ans_t op=search[k].add(i,j);
					ll to=s(u,op);
					if(!dis[to]){
						dis[to]=1;
						q[++t]=to;
						prek[to]=op;
//			printf("t=%lld %lld\n",u,s(to,op));
					}
				}
			}
		}
	}
//	return;
	ll hs=0;
	per(i,x2,x1)
	per(j,y2,y1)hs=hs<<1|a[i][j];
//	return;
	while(hs){
		ans[++top]=_prek[n][m][hs].add(x1,y1);
		hs=s(hs,_prek[n][m][hs]);
//			printf("f=%lld\n",hs);
	}
}
int main(){
	ll t=readll();
	while(t --> 0){
		top=0;
		ll n=readll(),m=readll();
		rep(i,1,n){
			rep(j,1,m){
				a[i][j]=readchar()^48;
			}
		}
		rep(i,1,n){
			if(i%2==1&&i+1<=n){
			rep(j,1,m)
				if(j%2==1&&j+1<=m){
//					printf("%lld %lld %lld\n",i,i+2==n?n:i+1,j);
					dfs(i,j,i+2==n?n:i+1,j+2==m?m:j+1);
				}
			}
		}
//		return 0;
		printf("%lld\n",top);
		rep(i,1,top){
			printf("%lld %lld %lld %lld %lld %lld\n"
			,ans[i].x1,ans[i].y1,ans[i].x2,ans[i].y2,ans[i].x3,ans[i].y3);
		}
	}
	return 0;
}