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
#define ycl_t(x) static ll x=0;if(!x++)
#define ycl ycl_t(cl_lj(x,__LINE__))
typedef long long ll;
//const ll mod=2520,inf=0x3f3f3f3f3f3f3f3f;
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
const ll mod=1e9+7,k=1145;
ll mc[1145141];
struct hash{
	ll val[1145141],len;
	const char*s;
	hash():len(0){
		memset(val,0,sizeof val);
	}
	hash(const char*s2):s(s2){
		val[0]=0;
		len=strlen(s+1);
		rep(i,1,len)val[i]=(val[i-1]*k+s[i]-'a')%mod;
	}
	hash&operator=(const char*s2){
		s=s2;
		val[0]=0;
		len=strlen(s+1);
		rep(i,1,len)val[i]=(val[i-1]*k+s[i]-'a')%mod;
		return*this;
	}
	ll operator()(register ll l,register ll r){
		if(r>len)r=len;
		if(l<1)l=1;
		if(l>r)return 0;
		ycl{
			mc[0]=1;
			rep(i,1,1145000)mc[i]=k*mc[i-1]%mod;
		}
//		printf("hash[\"");
//		rep(i,l,r)putchar(s[i]);
//		printf("\"]=%lld\n",(val[r]+mod-val[l-1]*mc[r-l+1]%mod)%mod);
		return(val[r]+mod-val[l-1]*mc[r-l+1]%mod)%mod;
	}
}hs1,hs2;
char s1[1145141],s2[1145141],s3[1145141];
ll next[1145411],next2[1145411];
int main(int QwQcOrZ,char*Recall_902_[]){
//	IO(P);
	(void)QwQcOrZ,(void)Recall_902_;
	scanf("%[^\n]",s1+1);
	scanf("%*[\n]%[^\n]",s2+1);
	hs1=s1,hs2=s2;
	ll len=strlen(s1+1);
	if(len!=strlen(s2+1))return puts("-1 -1"),0;
	rep(i,1,len)s3[i]=s1[len-i+1];
	ll j=0;
	rep(i,2,len){
		while(j&&s3[j+1]!=s3[i])j=next[j];
		if(s3[j+1]==s3[i])++j;next[i]=j;
//		printf("next[%lld]=%lld\n",i,next[i]);
	}
	j=0;
	rep(i,1,len){
		while(j&&s3[j+1]!=s2[i])j=next[j];
		if(s3[j+1]==s2[i])++j;next2[i]=j;
//		printf("next2[%lld]=%lld\n",i,next2[i]);
	}
	ll ansi=-1,ansj=-1;
	per(i,len-1,1){
		if(s2[i+1]!=s3[i+1]){break;}
		ll now=next2[i];
//		printf("%lld %lld\n",i,now);
		if(now==i)now=1;
//		printf("%lld %lld\n",i,now);
		if(hs1(len-i+1,len-now)==hs2(1,i-now)){
			ansi=len-i-1,ansj=len-now;
		}
	}
	printf("%lld %lld\n",ansi,ansj);
	return 0;
}
/*
Die Polizei untersucht eine Straftat im IT-Bereich.
untersucht eine Straftat.hciereB-TI mi  ieziloP eiD
.hciereB-TI mi tatfartS enie thcusretnu ieziloP eiD
*/