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
#define ref(i,l,r) rfor(ll i=l;i<r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define pef(i,l,r) rfor(ll i=l;i>r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define dprintf(x...) (void)(0)
#define cl_lj_(a,b) a##b
#define cl_lj(a,b) cl_lj_(a,b)
#define calc_in_func_df(calcer_t,calcer,code...) struct calcer_t{calcer_t(){code}};static calcer_t calcer
#define calc_in_func(code...) calc_in_func_df(cl_lj(calcer_t,__LINE__),cl_lj(calcer,__LINE__),code)
#define re register
typedef long long ll;
inline int gc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)) ? EOF : *p1++;
    //return getchar();
}
//#define getchar() gc()
inline ll readll(void){
	re ll x=0,w=1;
	re char ch=getchar();
	for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
	for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	return x*w;
}
inline ll iabs(ll x){
	return x>0?x:-x;
}
int readchar(void){
	int ch=getchar();
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
const ll N=4e5;
typedef ll arr[N];
arr next,to,head,deep,nfd,dfn,st[23],fa,v,f,LOG,s,loc,q,sta;
ll cnt=0,top=0;
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
ll min_2(ll u,ll v){return deep[u]<deep[v]?u:v;}
void dfs(ll u,ll fa){
	deep[st[0][dfn[u]=++top]=u]=deep[fa]+1;
	rfor(ll i=head[u];i;i=next[i])
	if(to[i]^fa)dfs(to[i],u),st[0][++top]=u;
	nfd[u]=top;
}
void calc(void){
	rep(i,2,top)LOG[i]=LOG[i>>1]+1;//printf("st=");
//	rfor(ll i=1;i<=top;i++)printf("%lld ",st[0][i]);puts("");
	rfor(ll j=1;(1<<j)<=top;j++)
	rfor(ll i=1;i+(1<<j)-1<=top;i++)
	st[j][i]=min_2(st[j-1][i],st[j-1][i+(1<<(j-1))]);
}
ll lca(ll u,ll v){
	u=dfn[u],v=dfn[v],(u>v)&&(std::swap(u,v),0);ll loglen=LOG[v-u+1];
	return min_2(st[loglen][u],st[loglen][v-(1<<loglen)+1]);
}
ll dis(ll u,ll v){return deep[u]+deep[v]-2*deep[lca(u,v)];}
ll hhs(ll u,ll v){return (dis(u,v)-1+s[v])/s[v];}
ll cmp(ll u,ll v){return dfn[u]<dfn[v];}
ll chs(ll u,ll x,ll y){if(!x)return y;if(!y)return x;ll dx=hhs(u,loc[x]),dy=hhs(u,loc[y]);return (dx==dy?x<y:dx<dy)?x:y;}
int main(int QwQcOrZ,char*Recall_902_[]){
	(void)QwQcOrZ,(void)Recall_902_;
	ll n=readll();
	rep(i,2,n){
		ll u=readll(),v=readll();
		add(u,v),add(v,u);
	}
	dfs(1,0);
	nfd[0]=1145141;
	calc();
	ll qs=readll();
	while(qs --> 0){
		ll k=readll(),m=readll();
//		exit(0);
		rep(i,1,k)loc[i]=v[i]=readll(),s[v[i]]=readll();
		rep(i,1,k)f[v[i]]=i;ll t=k,top=0;
		rep(i,1,m)q[i]=v[++t]=readll();
//		rep(i,1,t)printf("%lld ",v[i]);puts("");
		std::sort(v+1,v+t+1,cmp),v[++t]=1;
//		rep(i,1,t)printf("%lld ",v[i]);puts("");
		rep(i,2,k+m)v[++t]=lca(v[i],v[i-1]);
		std::sort(v+1,v+t+1,cmp);
//		rep(i,1,t)printf("%lld ",v[i]);puts("");
		t=std::unique(v+1,v+t+1)-v-1;
//		rep(i,1,t)printf("%lld ",v[i]);puts("");
		rep(i,1,t){
			for(++top;dfn[v[i]]>nfd[sta[--top]];);
			fa[v[i]]=sta[top],sta[++top]=v[i];
//			printf("fa[%lld]=%lld\n",v[i],fa[v[i]]);
//			rep(i,1,top)printf("%lld ",sta[i]);puts("");
		}
		per(i,t,2)f[fa[v[i]]]=chs(fa[v[i]],f[fa[v[i]]],f[v[i]]);
//		rep(i,1,t)printf("f[%lld]=%lld\n",v[i],f[v[i]]);
//		puts("");
		rep(i,2,t)f[v[i]]=chs(v[i],f[fa[v[i]]],f[v[i]]);
//		rep(i,1,t)printf("f[%lld]=%lld\n",v[i],f[v[i]]);
//		puts("");
		rep(i,1,m)printf("%lld ",f[q[i]]);
		puts("");
		rep(i,1,t)f[v[i]]=fa[v[i]]=s[v[i]]=0;
	}
	return 0;
}
/*
10
2 4
7 8
6 3
9 2
6 8
7 1
9 8
9 10
5 4
1
8 5
7 1
9 2
5 1
2 5
10 3
4 4
6 1
1 1
2 8 6 4 10
*/
/*
10
2 4
7 8
6 3
9 2
6 8
7 1
9 8
9 10
5 4
10
1 8
8 1
10 2 3 4 1 9 8 5
8 1
9 2
3 1
10 4
8 5
5 3
6 2
4 2
2 4
9
8 5
7 1
9 2
5 1
2 5
10 3
4 4
6 1
1 1
2 8 6 4 10
4 2
6 5
4 3
1 2
3 1
8 1
8 2
7 5
8 3
6 2
5 3
3 5
9 3
10 1
4 1
6 1
3 4
1 2
7 3
8 1
7 1 8 6
2 7
5 5
4 4
7 3 9 8 6 4 2
4 7
4 2
9 2
2 2
3 3
2 9 10 7 5 6 3
6 9
4 4
5 4
9 1
2 3
7 5
10 2
6 3 9 10 4 8 2 5 7
4 8
4 4
6 1
3 3
2 5
3 4 10 8 6 1 9 7
*/