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
#define ld long double
#define cio cwtinout
#define end_of_line '\n'
#define eol end_of_line
#define longinf (0x3f3f3f3f3f3f3f3f)
#define pp(a,b) template<>struct a<b>{typedef b Type;};

namespace quick_IO {
    template <typename T> struct Checker1;
    pp(Checker1,int)
    pp(Checker1,long)
    pp(Checker1,long long)
    pp(Checker1,unsigned int)
    pp(Checker1,unsigned long)
    pp(Checker1,unsigned long long)
    template <typename T> struct Checker2;
    pp(Checker2,char)
    template <typename T> struct Checker3;
    pp(Checker3,double)
    pp(Checker3,long double)
    pp(Checker3,float)
    template <typename T>
    typename Checker1<T>::Type read(void) {
        T w=1,x=0;
        char c=getchar();
        for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());
        for(;!(c<'0'||c>'9');x=(x<<1)+(x<<3)+(c^48),c=getchar());
        return x*w;
    }
    template <typename T>
    typename Checker2<T>::Type read(void) {
        char c=getchar();
        for(;c<'0'||c>'z';c=getchar());
        return c;
    }
    template <typename T>
    typename Checker3<T>::Type read(void) {
        long long w=1,x=0;
        T m,n;
        char c=getchar();
        for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());
        for(;!(c<'0'||c>'9');x=(x<<1)+(x<<3)+(c^48),c=getchar());
        if(c=='.') {
            m=0,n=1;
            c=getchar();
            for(;!(c<'0'||c>'9');n/=10,m+=n*(c^48),c=getchar());
        }
        return (x+m)*w;
    }
    template<typename T>
    void write(typename Checker1<T>::Type c,int x=0) {
        if(c<0)putchar('-'),c=-c;
        if(c<10)return putchar(c^48),void(0);
        write<T>(c/10);
        putchar((c%10)^48);
    }
    template<typename T>
    void write(typename Checker2<T>::Type c,int x=0) {
		if(c=='\n')return puts(""),void(0);
        putchar(c);
    }
    template<typename T>
    void write(typename Checker3<T>::Type c,int x=0) {
        long double y=0.5;
        for(ll i=1;i<=x;i++)y/=10;
        c+=y;
        write<long long>((long long)(c));
        if(!x)return;
        c-=(long long)c;
        putchar('.');
        for(ll i=1;i<=x;i++)c*=10,putchar(char(c)^48),c-=char(c);
    }
}
namespace cwts_IO{
    using namespace quick_IO;
    class ge_shi{
        public:
        char s;
        bool ss;
        char _c;
        bool sc;
        int wei_shu;
        bool swei_shu;
        ge_shi():s(' '),_c('\n'),ss(0),sc(0),wei_shu(6),swei_shu(0){};
        ge_shi(char cs,char cc,int cwei_shu):s(cs),_c(cc),ss(1),sc(1),wei_shu(cwei_shu),swei_shu(1){};
        ge_shi &operator =(const ge_shi&x) {
            if(x.ss) {
                s=x.s;
                ss=x.ss;
            }
            if(x.sc) {
                _c=x._c;
                sc=x.sc;
            }
            if(x.swei_shu) {
                wei_shu=x.wei_shu;
                swei_shu=x.swei_shu;
            }
            return *this;
        }
        ge_shi(const ge_shi&x) {
            if(x.ss) {
                s=x.s;
                ss=x.ss;
            }
            if(x.sc) {
                _c=x._c;
                sc=x.sc;
            }
            if(x.swei_shu) {
                wei_shu=x.wei_shu;
                swei_shu=x.swei_shu;
            }
        }
    };
    ge_shi ds(char x) {
        ge_shi c;
        c.s=x;
        c.ss=1;
        return c;
    }
    ge_shi dc(char x) {
        ge_shi c;
        c._c=x;
        c.sc=1;
        return c;
    }
    ge_shi dwei_shu(int x) {
        ge_shi c;
        c.wei_shu=x;
        c.swei_shu=1;
        return c;
    }
    class cwt_IO{
        public:
        void*a;
        void*b;
        ge_shi ca,cb;
        cwt_IO():a(NULL),b(NULL){}
    };
    cwt_IO cwtinout;
    cwt_IO & operator>>(cwt_IO&_input,const ge_shi &x) {
        _input.ca=x;
        return _input;
    }
    cwt_IO & operator<<(cwt_IO&_output,const ge_shi &x) {
        _output.cb=x;
        return _output;
    }
    template<typename T>
    cwt_IO & operator>>(cwt_IO&_input,T&x) {
        x=read<T>();
        return _input;
    }
    template<typename T>
    cwt_IO & operator>>(cwt_IO&_input,T*f) {
        if(_input.a==NULL) {
            _input.a=(void*)f;return _input;
        }  
        for(T*s=(T*)(_input.a);s!=f;s++) {
            _input>>(*s);
        }
        _input.a=NULL;
        return _input;
    }
    template<typename T>
    cwt_IO & operator<< (cwt_IO&_output,const T&x) {
        write<T>(x,_output.cb.wei_shu);
        return _output;
    }
    template<typename T>
    cwt_IO & operator<<(cwt_IO&_output,T*f) {
        if(_output.b==NULL) {
            _output.b=(void*)f;return _output;
        } 
        T*s;
        for(s=(T*)(_output.b);s+1-f;s++) {
            _output<<(*s)<<_output.cb.s;
        }
        _output<<(*s)<<_output.cb._c;
        _output.b=NULL;
        return _output;
    }
}
using namespace std;
using namespace cwts_IO;
ll fa[201010];
ll find(ll u) {
	return u-fa[u]?fa[u]=find(fa[u]):u;
}
int main(){
	//freopen("s.in","r",stdin);
	//freopen("s.out","w",stdout);
	ll n,m,ans=0,x,y;
	cio>>n>>m;
	for(ll i=1;i<=n;i++)fa[i]=i;
	for(ll i=1;i<=m;i++) {
		cio>>x>>y;
		x=find(x),y=find(y);
		if(x==y) {
			++ans;
			continue;
		}
		fa[x]=y;
	}
	cio<<ans;
	return 0;
}