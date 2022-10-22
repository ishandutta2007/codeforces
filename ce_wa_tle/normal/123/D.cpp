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
bool p1;
ll cur,cnt,p,last;
struct node{
	int val,len,link,v[26];
}sam[1145141];
void add_char(int c){
	sam[c-='a',p=last=cur,cur=++cnt]=(node){1,sam[last].len+1,0,0};
	for(;~p&&!sam[p].v[c];sam[p].v[c]=cur,p=sam[p].link);if(!~p)return;
	ll q=sam[p].v[c];if(sam[p].len+1==sam[q].len)return(void)(sam[cur].link=q);
	ll clone=++cnt;sam[clone]=sam[q],sam[sam[q].link=sam[cur].link=clone].val=0,sam[clone].len=sam[p].len+1;
	for(;~p&&sam[p].v[c]==q;sam[p].v[c]=clone,p=sam[p].link);
}
char s[1145141];
ll t[1145141],d[1145141];
bool p2;
int main(int QwQcOrZ,char*Recall_902_[]){
//	IO(P);
//printf("%.2lfMiB",(&p1-&p2)/1048576.0);
	(void)QwQcOrZ,(void)Recall_902_;
	scanf("%s",s+1);
	sam[cur=cnt=0].link=-1;
	ll len=strlen(s+1);
	rep(i,1,len)add_char(s[i]);
	for(ll i=1;i<=cnt;i++)t[sam[i].len]++;
	t[0]=1;for(ll i=1;i<=cnt;i++)t[i]+=t[i-1];
    for(ll i=1;i<=cnt;i++)d[--t[sam[i].len]]=i;
    ll sum=0;
//    printf("%lld\n",cnt);
    per(i,cnt,1){
    	ll u=d[i];
    	sum+=(sam[u].len-sam[sam[u].link].len)*(1ll*sam[u].val*-~sam[u].val>>1);
//    printf("f[%lld]=%lld %lld %lld %lld\n",u,sam[u].val,sam[u].len,(sam[u].len-sam[sam[u].link].len),(sam[u].len-sam[sam[u].link].len)*(sam[u].val*-~sam[u].val>>1));
    	sam[sam[u].link].val+=sam[u].val;
	}
	printf("%lld\n",sum);
	return 0;
}