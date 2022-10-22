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
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define rep(i,l,u) rfor(ll i=l;i<=u;++i)
#define per(i,l,u) rfor(ll i=l;i>=u;--i)
#define rfor(x...) for(register x)
#define ifn(x...) if(!(x))
#define max(x,y) std::max(ll(x),ll(y))
#define min(x,y) std::min(ll(x),ll(y))
typedef long long ll;
#define getchar myGetchar
#define putchar myPutchar
typedef long double ld;
namespace IO {
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;
 
	inline char myGetchar() {
		static char buf[IN_BUF], *ps = buf, *pt = buf;
		if (ps == pt) {
			ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
		}
		return ps == pt ? EOF : *ps++;
	}
 
	template<typename T>
	inline bool read(T &x) {
		bool op = 0;
		char ch = getchar();
		x = 0;
		for (; !isdigit(ch) && ch != EOF; ch = getchar()) {
			op ^= (ch == '-');
		}
		if (ch == EOF) {
			return false;
		}
		for (; isdigit(ch); ch = getchar()) {
			x = x * 10 + (ch ^ '0');
		}
		if (op) {
			x = -x;
		}
		return true;
	}
 
	inline int readStr(char *s) {
		int n = 0;
		char ch = getchar();
		for (; isspace(ch) && ch != EOF; ch = getchar())
			;
		for (; !isspace(ch) && ch != EOF; ch = getchar()) {
			s[n++] = ch;
		}
		s[n] = '\0';
		return n;
	}
 
	inline void myPutchar(char x) {
		static char pbuf[OUT_BUF], *pp = pbuf;
		struct _flusher {
			~_flusher() {
				fwrite(pbuf, 1, pp - pbuf, stdout);
			}
		};
		static _flusher outputFlusher;
		if (pp == pbuf + OUT_BUF) {
			fwrite(pbuf, 1, OUT_BUF, stdout);
			pp = pbuf;
		}
		*pp++ = x;
	}
 
	template<typename T>
	inline void print_(T x) {
		if (x == 0) {
			putchar('0');
			return;
		}
		static int num[40];
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		for (*num = 0; x; x /= 10) {
			num[++*num] = x % 10;
		}
		while (*num){
			putchar(num[*num] ^ '0');
			--*num;
		}
	}
 
	template<typename T>
	inline void print(T x, char ch = '\n') {
		print_(x);
		putchar(ch);
	}
 
	inline void printStr_(const char *s, int n = -1) {
		if (n == -1) {
			n = strlen(s);
		}
		for (int i = 0; i < n; ++i) {
			putchar(s[i]);
		}
	}
 
	inline void printStr(const char *s, int n = -1, char ch = '\n') {
		printStr_(s, n);
		putchar(ch);
	}
}
using namespace IO;
inline ll readll(){return({ll x;read(x),x;});}
//ll t[1145141],a[1145141],lst1[1145141],lst2[1145141],cnt1=0,cnt2=0;
struct node{
	ll w,t;
	int operator<(const node&b)const{
		return w>b.w;
	}
}l[714514];
std::priority_queue<ll,std::vector<ll>,std::greater<ll> >qu;
int main(){
//	IO(t2);
	ll n=readll();
	rep(i,1,n){
		l[i].w=readll(),l[i].t=readll();
	}
	std::sort(l+2,l+n+1);
	ll p=1;
	while(l[p+1].w>l[1].w&&p<n)++p,qu.push(l[p].t-l[p].w+1);
	ll min=p,rk=p;
	while(!qu.empty()){
		l[1].w-=qu.top();
		if(l[1].w<0)break;
//		print(l[1].w);
		qu.pop();
		--rk;
		while(l[p+1].w>l[1].w&&p<n)++p,++rk,qu.push(l[p].t-l[p].w+1);
		min=min(min,rk);
//		print(rk);
	}
	print(min);
	return 0;
}