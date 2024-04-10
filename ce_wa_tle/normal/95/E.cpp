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
#define f(x...) rfjslkjs(x)
ll f[1145141],fl[1145141],t[1145141],q[1145411],v[1145114];
ll f(ll u){return f[u]^u?f[u]=f(f[u]):u;}
int main(int QwQcOrZ,char*Recall_902_[]){
//	IO(P);
	(void)QwQcOrZ,(void)Recall_902_;
	ll n=readll(),m=readll();
	rep(i,1,n){f[i]=i;}
	rep(i,1,m){
		ll x=readll(),y=readll();
		f[f(x)]=f(y);
	}
	rep(i,1,n)t[f(i)]++;
	std::sort(t+1,t+n+1);
//	rep(i,0,n){
//		printf("t[%lld]=%lld\n",i,t[i]);
//	}
	memset(f,0x3f,sizeof f);
	fl[0]=0;
	ll g=0;
	rep(s,1,n+1){
		if(t[s]!=t[s-1]){
			ll i=t[s-1];
//			printf("g=%lld\n",g);
			rep(jmodi,0,i-1){
				ll h=1,t=0;
				rep(jdivi,0,n/i){
					ll j=jdivi*i+jmodi;
					if(j>n)break;
					//f[j]=min(f[j-i*k]+k)(1<=k<=g);
					//f[jdivi*i+jmodi]=min(f[jdivi'*i+jmodi]-jdivi'+jdivi)(1<=k<=g)
					#undef f
					#define f(x) (fl[x*i+jmodi]-x)
					while(h<=t&&f(q[t])>=f(jdivi))t--;
					q[++t]=jdivi;
					while(h<=t&&jdivi-q[h]>g)h++;
//					printf("%lld %lld %lld\n",i,j,q[h]*i+jmodi);
					f[j]=min(fl[j],f(q[h])+jdivi);
				}
			}
			rep(j,1,n){
				fl[j]=f[j];
			}
			g=1;
		}
		else{
			g++;
		}
	}
//	rep(i,0,n){
//		printf("f[%lld]=%lld\n",i,f[i]);
//	}
	v[4]=1,v[7]=1;
	rep(i,43,n)v[i]=v[i/10]&&v[i%10];
	ll min=0x3f3f3f3f3f3f3f3f;
	rep(i,1,n)if(v[i])min=min(min,f[i]-1);
	printf("%lld\n",min<=n?min:-1);
	return 0;
}