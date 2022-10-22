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
const ll mod=2520;
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
long long f[21][2521][50][2];
#define lcm(x...) fdsj(x)
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
ll vol[3217],lol[4323][10],slog[1132],col;
long long getans(ll r){
	#define ll int
	calc_in_func(
		vol[0]=1,slog[1]=0;
		rep(i,2,511)slog[i]=slog[i>>1]+1;
		#define lowbit(u) ((u)&-(u))
		rep(i,1,511){
			vol[i]=lcm(vol[i^lowbit(i)],slog[lowbit(i)]+1);
		}
		std::sort(vol,vol+512);
		col=std::unique(vol,vol+512)-vol-1;
//		printf("%lld\n",col);
//		rep(i,0,col)printf("%lld\n",vol[i]);
		rep(i,0,col)
		rep(j,0,9){
			lol[i][j]=std::lower_bound(vol,vol+col+1,lcm(vol[i],max(1,j)))-vol;
//			if(i<=20)
//			printf("lol[%lld][%lld]=%lld\n",i,j,lol[i][j]);
		}
//		exit(0);
	);
	if(r==0)return 1;
	static ll m[21];
	rep(i,1,20){m[i]=r%10,r/=10;}
	f[20][0][0][1]=1;
	per(i,20,1){
		rep(j,0,2520){
			rep(k,0,col){
				if(f[i][j][k][0])
//				printf("f[%lld][%lld][%lld][%lld]=%lld\n",i,j,vol[k],0ll,f[i][j][k][0]);
//				if(f[i][j][k][1])
//				printf("f[%lld][%lld][%lld][%lld]=%lld\n",i,j,vol[k],1ll,f[i][j][k][1]);
//				if(f[i][j][k][0])
				rep(l,0,9)
				f[i-1][(j*10+l)%mod][lol[k][l]][0]+=f[i][j][k][0];
				if(f[i][j][k][1]){
					rep(l,0,m[i-1]-1)
					f[i-1][(j*10+l)%mod][lol[k][l]][0]+=f[i][j][k][1];//,printf("%lld %lld %lld\n",k,l,lol[k][l]);
					rep(l,m[i-1],m[i-1])
					f[i-1][(j*10+l)%mod][lol[k][l]][1]+=f[i][j][k][1];//,printf("%lld %lld %lld\n",k,l,lol[k][l]);
//					printf("m=%lld\n",m[i]);
				}
			}
		}
//	return 0;
	}
	long long sum=0;
	rep(j,0,2520)
		rep(k,0,col)if(j%vol[k]==0)sum+=f[1][j][k][1]+f[1][j][k][0];
	per(i,20,1){
		rep(j,0,2520){
			rep(k,0,col){
				f[i][j][k][0]=f[i][j][k][1]=0;
			}
		}
//	return 0;
	}
	#undef ll 
//		printf("%lld\n",sum);
	return sum;
	
}
int main(int QwQcOrZ,char*Recall_902_[]){
	//IO(k);
	(void)QwQcOrZ,(void)Recall_902_;
	ll T=readll();
	while(T --> 0){
		ll l=readll(),r=readll();
		printf("%lld\n",getans(r)-getans(l-1));
	}
	return 0;
}