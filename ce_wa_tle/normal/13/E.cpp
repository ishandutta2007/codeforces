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
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
struct node{
	ll size,fa,son[2],lazy;
}spl[114514];
struct splay{
	#define splay(x...) s_p_l_a_y(x)
	#define w(x...) www(x)
	private:
//	inline ll w(ll u){
//		return spl[spl[u].fa].son[1]==u?1:
//			   spl[spl[u].fa].son[0]==u?0:
//			   -1;
//	}
	inline ll w(ll u){
		return spl[spl[u].fa].son[1]==u?:
		spl[spl[u].fa].son[0]==u?0:-1;
	}
	public:
	inline void pushup(ll u){
		if(!u)return;
		spl[u].size=spl[spl[u].son[0]].size+
					spl[spl[u].son[1]].size+1;
	}
	inline void pushdown(ll u){
		if(!u)return;
		spl[u].lazy&&(
			std::swap(spl[u].son[0],spl[u].son[1]),
			spl[spl[u].son[0]].lazy^=1,
			spl[spl[u].son[1]].lazy^=1,
			spl[u].lazy=0);
	}
	private:
	inline void rotate(ll u){
		ll v=spl[u].fa,wu=w(u),w=spl[v].fa,wv=w(v),x=spl[u].son[wu^1],wx=wu^1;
		spl[u].fa=w;
		~wv&&(conect(u,w,wv),0),conect(v,u,wx),conect(x,v,wu);
		pushup(v),pushup(u);
	}
	public:
	inline void conect(ll u,ll fa,ll w){
		spl[u?spl[u].fa=fa:fa].son[w]=fa?u:0;
	}
	inline void splay(ll u){
		static ll st[114514];
		ll y=u,z=0;st[++z]=y;
		while(~w(y))st[++z]=y=spl[y].fa;
		while(z)pushdown(st[z--]);
		while(~w(u)){
			ll v=spl[u].fa;
			~w(v)&&(rotate(w(u)^w(v)?u:v),0);
			rotate(u);
//			printf("%lld %lld\n",u,v);
		}
	}
	inline ll pre(ll u){
		splay(u);
		pushdown(u);
		ll v=spl[u].son[0];
		pushdown(v);
		while(spl[v].son[1])pushdown(v=spl[v].son[1]);
		return v;
	}
};
struct lct{
	splay s;
	private:
	void access(ll u){
		rfor(ll x=0;u;u=spl[x=u].fa)
		s.splay(u),s.conect(x,u,1),s.pushup(u);//,printf("%lld\n",u);
	}
	public:
	void makeroot(ll u){
		access(u),s.splay(u);
		spl[u].lazy^=1;
	}
	int findroot(ll u){
		access(u),s.splay(u),s.pushdown(u);
		while(spl[u].son[0])s.pushdown(u=spl[u].son[0]);
		s.splay(u);
		return u;
	}
	void split(ll u,ll v){
		makeroot(u);
		access(v);
		//return;
		s.splay(v);
	}
	int link(ll u,ll v){
		makeroot(u);
		if(findroot(v)==u)return 0;
		spl[u].fa=v;
		return 1;
	}
	int cut(ll u,ll v){
		makeroot(u);
		if(findroot(v)!=u||spl[u].size!=2)return 0;
		spl[u].son[1]=spl[v].fa=0;
		s.pushup(u);
		return 1;
	}
}T;
int main(){
	ll n=readll(),m=readll();
	static ll to[114541];
	rep(i,1,n){
		to[i]=i+readll();
		if(to[i]>n)to[i]=n+1;
		T.link(i,to[i]);
	}
	rep(i,1,m){
		ll f=readll();
		if(f==0){
			ll x=readll(),y=readll();
			if(!T.cut(x,to[x]))puts("0");
			to[x]=x+y;
			if(to[x]>n)to[x]=n+1;
			T.link(x,to[x]);
		}
		else{
			ll x=readll();
			T.split(x,n+1);
		//	return 0;
			ll sz=spl[n+1].size;
			printf("%lld %lld\n",T.s.pre(n+1),sz-1);
		}
	}
	return 0;
}