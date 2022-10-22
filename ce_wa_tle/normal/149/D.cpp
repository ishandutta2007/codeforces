// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2013 Free Software Foundation, Inc.
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
#define ll long long
#define IO(w) \
freopen(#w".in","r",stdin);\
freopen(#w".out","w",stdout)
ll readll(void) {
	ll x=0,w=1;char c=getchar();
	for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());
	return x*w;
}
char s[1222];
ll z[1222],top=0,f[1222][3][3],g[1222][3][3];
int main(int WCR,char**AK_IOI){
	//IO(4);
	//ll t=readll();
	//while(t --> 0){
		gets(s+1);ll n=strlen(s+1);
		for(ll i=1;i<=n;i++){
			if(s[i]=='('){
				z[++top]=i;
			}
			else {
				ll j=z[top],
				k=z[top-1];top--;
				memset(f[i],0,sizeof(f[i]));
				memset(g[i],0,sizeof(g[i]));
				if(j==i-1){
					f[i][0][1]=f[i][0][2]=f[i][1][0]=f[i][2][0]=1;
				}
				else
				for(ll s1=0;s1<=2;s1++){
					for(ll s2=0;s2<=2;s2++){
						if(s1*s2==0&&(s1||s2)){
							for(ll s3=0;s3<=2;s3++){
								for(ll s4=0;s4<=2;s4++){
									if((s1==0||s1^s3)&&(s2==0||s2^s4))
									f[i][s1][s2]+=g[i-1][s3][s4],f[i][s1][s2]%=1000000007;
								}
							}
						}
					}
				}
				//((())
				if(k==j-1){
				for(ll s1=0;s1<=2;s1++)
					for(ll s2=0;s2<=2;s2++)g[i][s1][s2]=f[i][s1][s2];	
				}
				else
				for(ll s1=0;s1<=2;s1++){
					for(ll s2=0;s2<=2;s2++){
						for(ll s3=0;s3<=2;s3++){
							for(ll s4=0;s4<=2;s4++){
								if((s3==0||s3^s4))
								g[i][s1][s2]+=g[j-1][s1][s3]*f[i][s4][s2],g[i][s1][s2]%=1000000007;
							}
						}
					}
				}
//				f[i][0][1]=
//				g[i-1][0][0]+g[i-1][0][2]+g[i-1][1][0]+g[i-1][1][2]+g[i-1][2][0]+g[i-1][2][2];
//				f[i][0][2]=
//				g[i-1][0][0]+g[i-1][0][1]+g[i-1][1][0]+g[i-1][1][1]+g[i-1][2][0]+g[i-1][2][1];
//				f[i][1][0]=
//				g[i-1][0][0]+g[i-1][0][2]+g[i-1][0][1]+g[i-1][2][1]+g[i-1][2][0]+g[i-1][2][2];
//				f[i][2][0]=
//				g[i-1][0][0]+g[i-1][0][2]+g[i-1][0][1]+g[i-1][1][1]+g[i-1][1][0]+g[i-1][1][2];
//				g[i][0][0]=g[j-1][0][1]*f[i][0][1]+
//				f[i][1]=f[k-1][]*f[i-1];
//				--top;
			}
		}
		ll sum=0;
		for(ll s1=0;s1<=2;s1++)
			for(ll s2=0;s2<=2;s2++)sum+=g[n][s1][s2],sum%=1000000007;
				
		printf("%lld\n",sum);
	//}
	return 0;
}