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
const ll N=350000;
typedef ll arr[N];
arr next,head,to;
ll cnt=0;
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
//void add(ll u,ll v){++cnt;to[cnt]=v,next[cnt]=head[u];head[u]=cnt;}
struct line_t{ll k,b;ll y(ll x)const{return k*x+b;}}line[N];
ll id[N<<2];
void build(ll u,ll l,ll r){
	id[u]=0;
	if(l!=r){
		ll mid=(l+r)>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
	}
}
void update(ll u,ll l,ll r,ll q){
	//if(u==1)printf("i=%lld:y=%lldx+%lld\n",q,line[q].k,line[q].b);
	ll mid=(l+r)>>1;
	if(line[q].y(mid)>line[id[u]].y(mid))std::swap(q,id[u]);
	if(l==r)return;
	if(line[q].y(l)>line[id[u]].y(l))update(u<<1,l,mid,q);
	if(line[q].y(r)>line[id[u]].y(r))update(u<<1|1,mid+1,r,q);
}
arr size,vis,v;
ll query(ll u,ll l,ll r,ll q){
	//if(u==1)printf("q=%lld\n",q);
	if(l==r)return line[id[u]].y(q);
	ll mid=(l+r)>>1;
	if(q<=mid)return max(line[id[u]].y(q),query(u<<1,l,mid,q));
	else return max(line[id[u]].y(q),query(u<<1|1,mid+1,r,q));
}
void find(ll u,ll fa,ll n,ll&w){
//	static ll cnt=0;
//	vis[u]=1;
	ll max=0;size[u]=1;
	rfor(ll i=head[u];i;i=next[i])if(to[i]^fa&&!vis[to[i]])
	find(to[i],u,n,w),size[u]+=size[to[i]],max=max(max,size[to[i]]);
//	else if(to[i]^fa)fprintf(stderr,"YD");
//	if(++cnt%100==0)fprintf(stderr,"f=%lld %lld %lld %lld %lld\n",cnt,u,fa,n,size[u]);
	max=max(max,n-size[u]);
	if(max*2<=n)w=u;
}
struct lu{
	ll v1,v2,s,l,x;
}e[N<<1];
ll top=0,maxd=0;
void dfs2(ll u,ll fa,ll v1,ll v2,ll s,ll l,ll x){
	!x&&fa&&(x=u);
	maxd=max(maxd,l);
	int f=1;
	rfor(ll i=head[u];i;i=next[i])
	if(to[i]^fa&&!vis[to[i]])f=0,dfs2(to[i],u,v1+s+v[to[i]],v2+l*v[to[i]],s+v[to[i]],l+1,x);
	if(!x||f)e[++top]=(lu){v1,v2,s,l,x},/*printf("add=%lld %lld %lld %lld %lld %lld %lld\n",u,x,v1,v2,s,l,x),*/line[top]=(line_t){s,v2};
}
ll max=0;
void solve(ll u){
//	fprintf(stderr,"%lld\n",u);
	top=0,maxd=1,dfs2(u,0,v[u],0,v[u],1,0);
	if(!top)return;
	build(1,1,maxd);
	ll lst=1;
	e[top+1].x=e[0].x=-1;
	rep(i,2,top+1){
		if(e[i].x!=e[i-1].x){
			ref(j,lst,i)max=max(max,e[j].v1+query(1,1,maxd,e[j].l)-v[u]*e[j].l);
			ref(j,lst,i)update(1,1,maxd,j);
			lst=i;	
		}                         
	}
	//puts("");
	build(1,1,maxd);
	lst=top;
	per(i,top-1,0){
		if(e[i].x!=e[i+1].x){
			pef(j,lst,i)max=max(max,e[j].v1+query(1,1,maxd,e[j].l)-v[u]*e[j].l);
			pef(j,lst,i)update(1,1,maxd,j);
			lst=i;	
		}
	}
	//puts("");
}
void dfs(ll u,ll n){
	//printf("u=%lld %lld\n",u,n);
	vis[u]=1,solve(u);
	rfor(ll i=head[u];i;i=next[i])
	if(!vis[to[i]]){
		ll sz=size[u]>size[to[i]]?size[to[i]]:n-size[u];
		ll son=0;find(to[i],u,sz,son),dfs(son,sz);
	}
}
int main(int QwQcOrZ,char*Recall_902_[]){
	(void)QwQcOrZ,(void)Recall_902_;
	//IO(G);
	ll n=readll();
	rep(i,2,n){
		ll u=readll(),v=readll();
		add(u,v),add(v,u);
//		if(u<v)puts("YD"),exit(0);
	}
	rep(i,1,n)v[i]=readll();
	ll root=0;find(1,0,n,root),dfs(root,n);
	printf("%lld\n",max);
	fprintf(stderr,"%ld\n",clock());
	return 0;
}
/*
7
1 2
2 3
4 5
5 3
6 7
7 3
1 1 1 1 1 1 1
*/