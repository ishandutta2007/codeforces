#pragma G++ optimize("Ofast")
/*
 template by c8kbf
 */

// macOS doesn't have <bits/++.h> (shame)
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <algorithm>
#include <numeric>
#include <random>

//dont worry bout me, i'm not high
#define ef else if
#define leave exit(0);

#define v(x) vector<x >
#define v2(x) vector<vector<x > >
#define v3(x) vector<vector<vector<x > > >

#define q(x) queue<x >
#define dq(x) deque<x >
#define s(x) set<x >
#define st(x) stack<x >
#define ms(x) multiset<x >
#define m(x, y) map<x , y >
#define b(x) bitset<x >
#define l(x) list<x >

#define ss(x) v(_)(x+8, 0)
#define ssz(type, x) v(type)(x+8, 0)
#define s2(x, y) v2(_)(x+8, v(_)(y+8, 0))
#define s2z(type, x, y) v2(type)(x+8, v(type)(y+8, 0))
#define s3(x, y, z) v3(_)(x+8, v2(_)(y+8, v(_)(z+8, 0)))
#define s3z(type, x, y, z) v3(type)(x+8, v2(type)(y+8, v(type)(z+8, 0)))
#define rd(a, sz) for(_ i = 1; i <= sz; ++i) a[i] = read();
#define wr(a, sz) for(_ i = 1; i <= sz; ++i) writesc(a[i]); clr();

#define i(x) x::iterator

#define pr(x, y) pair< x, y >
#define mp(x, y) make_pair(x, y)

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef int _0;
typedef long double _D;
typedef unsigned long long u_;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

//fastIO cos why not
inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline bool read(_ &x, v(char) tl = {'\n', EOF}) {
    x = 0;
    _ f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    x *= f;
    if(ch == '\r') ch = getchar();
    return !count(tl.begin(), tl.end(), ch);
}

inline void read(char * a, v(char) tl = {' ', '\n', '\r', '\t', '\0', EOF}, v(char) skp = {' ', '\n', '\r', '\t'}) {
    char ch = getchar();
    for(; count(skp.begin(), skp.end(), ch); ) ch = getchar();
    for(; !count(tl.begin(), tl.end(), ch); ch = getchar()) {
        *a = ch;
        ++a;
    }
    *a = '\0';
    return;
}

inline void read(str & a, v(char) tl = {' ', '\n', '\r', '\t', '\0', EOF}, v(char) skp = {' ', '\n', '\r', '\t'}) {
    a.clear();
    char ch = getchar();
    for(; count(skp.begin(), skp.end(), ch); ) ch = getchar();
    for(; !count(tl.begin(), tl.end(), ch); ch = getchar()) a += ch;
    return;
}

inline char getDg() {
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
    return ch;
}

inline char getLw() {
    char ch = getchar();
    for(; !(ch >= 'a' && ch <= 'z'); ) ch = getchar();
    return ch;
}

inline char getUp() {
    char ch = getchar();
    for(; !(ch >= 'A' && ch <= 'Z'); ) ch = getchar();
    return ch;
}

inline char getLtr() {
    char ch = getchar();
    for(; !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); ) ch = getchar();
    return ch;
}

inline char gc() {
    char ch = getchar();
    for(; ch == '\n' || ch == '\r' || ch == ' '; ) ch = getchar();
    return ch;
}

inline void write(_ x) {
    if(x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if(x > 9) write(x/10);
    putchar((x%10)^48);
    return;
}

//inline void write(_0 x) {
//    write((_)x);
//    return;
//}

inline void write(char const * a) {
    for(_ i = 0; a[i]; ++i) putchar(a[i]);
    return;
}

inline void write(const str a) {
    write(a.c_str());
    return;
}

inline void write(char ch) {
    putchar(ch);
    return;
}

inline void write(_p a, char const * b = " ") {
    write(a.first);
    write(b);
    write(a.second);
    return;
}

inline void clr() {
    putchar(10);
    return;
}

inline void flsh(bool nl = true) {
    if(nl) clr();
    fflush(stdout);
    return;
}

inline void spc() {
    putchar(32);
    return;
}

template <class tp>
inline void writeln(tp x) {
    write(x);
    clr();
}

inline void writeln(_p a, char const * b = " ") {
    write(a, b);
    clr();
    return;
}

template <class tp>
inline void writesc(tp x) {
    write(x);
    spc();
}

inline void writesc(_p a, char const * b = " ") {
    write(a);
    spc();
    return;
}

template <class tp>
inline void writeflsh(tp x, bool nl = true) {
    write(x);
    flsh(nl);
}

inline void writeflsh(_p a, char const * b = " ", bool nl = true) {
    write(a, b);
    flsh(nl);
    return;
}

inline void yes(_ a = 1) {
    write(a & 1 ? 'Y' : 'y');
    write(a & 2 ? 'E' : 'e');
    write(a & 4 ? 'S' : 's');
    clr();
    return;
}

inline void no(_ a = 1) {
    write(a & 1 ? 'N' : 'n');
    write(a & 2 ? 'O' : 'o');
    clr();
    return;
}

//loop systems
inline v_ rg(_ r, _ l = 1, _ d = 1) {
    v_ rv;
    for(_ i = l; i <= r; i += d) rv.push_back(i);
    return rv;
}

inline v_ dg(_ r, _ l = 1, _ d = -1) {
    v_ rv;
    for(_ i = r; i >= l; i += d) rv.push_back(i);
    return rv;
}

inline void AC();
int main(int argc, char * argv[]) {

//    #define file_IO
#ifdef file_IO
    str fileN = "";
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

//    #define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
    for(; tc--; ) AC(); // good luck!
#else
    AC(); // good luck!
#endif

    return 0;
}

// ----- End of Template -----



constant maxn = 2E7+8;

_ n, mn[maxn], mx[maxn], lz[maxn], cnt, r, lt[maxn], rt[maxn], la, m, x, dp;

inline _ query(_ l, _ r, _ ad, _ p, _ pos);
inline _p update(_ l, _ r, _ c, _ ad, _ &pos);
inline _ newNode(_ l, _ r);
inline void AC() {
//    freopen("/Users/ryanzhang/Desktop/sample.txt", "r", stdin);
    n = read();
    mn[0] = 1E17;
    mx[0] = -1E17;
    for(register _ i = 1; i <= n; ++i) {
        dp = 0;
        update(0, 1E9, read(), 0, r);
        m = read();
        for(; m --> 0; ) {
            dp = 0;
            x = (read()+la)%(1000000001);
            la = query(0, 1E9, 0, x, r);
            writeln(la = query(0, 1E9, 0, x, r));
//            writeln(i);
        }
    }
    
    return;
}

inline _ newNode(_ l, _ r) {
    if(cnt > 2E7) exit(2);
    mn[++cnt] = l;
    mx[cnt] = r;
    return cnt;
}

inline _p update(_ l, _ r, _ c, _ ad, _ &pos) {
//    ++dp;
//    if(dp > 1000) {
//        writeln("wat");
//        dp = -1E9;
//    }
    ad += lz[pos];
    if(!pos) pos = newNode(l, r);
    if(mn[pos]+ad == c && mx[pos]+ad == c) return mp(mn[pos]+lz[pos], mx[pos]+lz[pos]);
    if(mx[pos]+ad < c) {
        ++lz[pos];
        return mp(mn[pos]+lz[pos], mx[pos]+lz[pos]);
    }
    ef(mn[pos]+ad > c) {
        --lz[pos];
        return mp(mn[pos]+lz[pos], mx[pos]+lz[pos]);
    }
    ef(mn[pos]+ad <= c && mx[pos]+ad >= c) {
        register _ md = (l+r)>>1;
        _p pl = update(l, md, c, ad, lt[pos]), pr = update(md+1, r, c, ad, rt[pos]);
        mn[pos] = min(pl.first, pr.first);
        mx[pos] = max(pl.second, pr.second);
        return mp(mn[pos], mx[pos]);
    } else exit(1);
}

inline _ query(_ l, _ r, _ ad, _ p, _ pos) {
    if(!pos) pos = newNode(l, r);
    if(l == r) {
        return mn[pos]+ad+lz[pos];
    }
    register _ md = (l+r)>>1;
    if(p <= md) {
        return query(l, md, ad+lz[pos], p, lt[pos]);
    } else {
        return query(md+1, r, ad+lz[pos], p, rt[pos]);
    }
}

/*
3
50
3
1 2 3
50
3
4 5 6
0
3
7 8 9
  
10
1000000000
1
1000000000
1000000000
1
1000000000
1000000000
1
1000000000
1000000000
1
999999999
1000000000
1
1000000000
1000000000
1
1000000000
1000000000
1
999999999
1000000000
1
1000000000
1000000000
1
1000000000
999999998
1
999999999
 */