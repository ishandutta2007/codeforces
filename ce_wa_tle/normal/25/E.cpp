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
//const ll mod=998244353;
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
const ll mod=1e9+9,k=37;
ll mc[314541];
struct hash_t{
	ll val[314541],n;
	const char*s;
	void calc(const char*ss){
		s=ss;
//		strcpy(s+1,ss+1);
		n=strlen(s+1);
		struct calcer_t{
			calcer_t(){
				mc[0]=1;
				rep(i,1,311111)mc[i]=k*mc[i-1]%mod;
			}
		};
		static calcer_t calcer;
		val[0]=0;
		rep(i,1,n+1)val[i]=(val[i-1]*k+s[i]-'a'+1)%mod;
	}
	operator()(ll l,ll r)const{
		if(r>n)r=n;
		if(l<=0)l=1;
		if(l>r)return 0;
//		printf("hash(\"");
//		rep(i,l,r)putchar(s[i]);
//		printf("\")=%lld\n",(val[r]+mod-val[l-1]*mc[r-l+1]%mod)%mod);
		return (val[r]+mod-val[l-1]*mc[r-l+1]%mod)%mod;
	}
};
//ll ss[114541];
struct st{
	char s[114541];
	hash_t hash;
	ll len;
	void in(){scanf("%s",s+1),len=strlen(s+1),hash.calc(s);}
	char&operator[](ll i){return s[i];}
	const char&operator[](ll i)const{return s[i];}
	void out()const{printf("%s",s+1);}
	int incl(const st&b)const{
		if(b.len>len)return 0;
		ll sd=b.hash(1,b.len);
		rep(i,1,len-b.len+1)
		if(hash(i,i+b.len-1)==sd)return 1;
		return 0; 
	}
	ll getmax(const st&b)const{
		ll m=min(len,b.len);
		per(i,m,1)if(hash(len-i+1,len)==b.hash(1,i))return i;
		return 0; 
	}
	int operator<(const st&b)const{
		return strcmp(s+1,b.s+1)==-1;
	}
//	st(const char*sd):len(strlen(s)){strcpy(s,sd);}
}s[3];
int cmp(const st&a,const st&b){
	return a.len<b.len;
}
int main(){
	rep(i,0,2)s[i].in();
	std::sort(s,s+3,cmp);
	ll ans;
	do{
		if(s[2].incl(s[1])&&s[2].incl(s[0])){
			ans=s[2].len;
			break;
		}
		if(s[2].incl(s[1])){
			ans=s[2].len+s[0].len-max(s[2].getmax(s[0]),s[0].getmax(s[2]));
			break;
		}
		if(s[2].incl(s[0])){
			ans=s[2].len+s[1].len-max(s[2].getmax(s[1]),s[1].getmax(s[2]));
			break;
		}
		if(s[1].incl(s[0])){
			ans=s[2].len+s[1].len-max(s[2].getmax(s[1]),s[1].getmax(s[2]));
			break;
		}
		ll max=0;ans=s[2].len+s[1].len+s[0].len;
		std::sort(s,s+3);
		do{
//			rep(i,0,2)s[i].out(),puts("");puts("");
			max=max(max,s[0].getmax(s[1])+s[1].getmax(s[2]));
		}while(std::next_permutation(s,s+3));
//		return 0;
		ans-=max;
	}while(0);
	printf("%lld\n",ans);
	return 0;
}