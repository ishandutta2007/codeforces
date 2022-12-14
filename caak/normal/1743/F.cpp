
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
#include <functional>

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
typedef double _D;
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

inline bool read(_ & x, v(char) tl = {'\n', EOF}) {
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

inline void read(vector<reference_wrapper<_> > a) {
    for(_ & i : a) i = read();
    return;
}

inline void read(_p & x) {
    x.first = read();
    x.second = read();
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

inline void write(_0 x) {
    write((_)x);
    return;
}

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

inline void write(v_ a, char const * b = " ") {
    bool fs = false;
    for(_ i : a) {
        if(!fs) fs = true;
        else write(b);
        write(i);
    }
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

inline void writeln(v_ a, char const * b = " ") {
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




constant maxn = 3E5+8;
constant mod = 998244353;

struct matrx {
    _ a, b, c, d;
} t[maxn<<2], id = (matrx){1, 0, 0, 1};
_ n, ln = 3E5+1, x, y, xa, ya;

matrx qr(_ l, _ r, _ p, _ pos);
void mult(_ L, _ R, _ l, _ r, matrx c, _ pos);
void init(_ l, _ r, _ pos);
void pushDown(_ pos);
matrx mult(matrx a, matrx b);
inline void AC() {

    init(1, ln, 1);
    read({n, x, y});
    ++x;
    ++y;
    matrx ta = {3, 1, 0, 2}, tb = {1, 1, 2, 2};
    for(_ i = 2; i <= n; ++i) {
        read({xa, ya});
        ++xa;
        ++ya;
//        if(xa != 1) mult(1, xa-1, 1, ln, (matrx){3, 1, 0, 2}, 1);
//        if(ya != ln) mult(ya+1, ln, 1, ln, (matrx){3, 1, 0, 2}, 1);
//        mult(xa, ya, 1, ln, (matrx){1, 1, 2, 2}, 1);
        if(xa != 1) mult(1, xa-1, 1, ln, ta, 1);
        if(ya != ln) mult(ya+1, ln, 1, ln, ta, 1);
        mult(xa, ya, 1, ln, tb, 1);
    }
    _ s = 0;
    for(_ i = 1; i <= ln; ++i) {
        if(x <= i && i <= y) {
            matrx ts = qr(1, ln, i, 1);
            s = (s+ts.d)%mod;
        } else {
            matrx ts = qr(1, ln, i, 1);
            s = (s+ts.c)%mod;
        }
    }
    writeln(s);
 
    return;
}

matrx mult(matrx a, matrx b) {
    swap(a, b);
    return (matrx){(a.a*b.a+a.b*b.c)%mod, (a.a*b.b+a.b*b.d)%mod, (a.c*b.a+a.d*b.c)%mod, (a.c*b.b+a.d*b.d)%mod};
}

void pushDown(_ pos) {
    t[pos<<1] = mult(t[pos<<1], t[pos]);
    t[pos<<1|1] = mult(t[pos<<1|1], t[pos]);
    t[pos] = id;
    return;
}

void init(_ l, _ r, _ pos) {
    t[pos] = id;
    if(l != r) {
        _ md = (l+r)>>1;
        init(l, md, pos<<1);
        init(md+1, r, pos<<1|1);
    }
    return;
}

void mult(_ L, _ R, _ l, _ r, matrx c, _ pos) {
    if(L <= l && r <= R) {
        t[pos] = mult(t[pos], c);
        return;
    }
    _ md = (l+r)>>1;
    pushDown(pos);
    if(L <= md) mult(L, R, l, md, c, pos<<1);
    if(R > md) mult(L, R, md+1, r, c, pos<<1|1);
    return;
}

matrx qr(_ l, _ r, _ p, _ pos) {
    if(l == r) return t[pos];
    pushDown(pos);
    _ md = (l+r)>>1;
    if(p <= md) return qr(l, md, p, pos<<1);
    else return qr(md+1, r, p, pos<<1|1);
}