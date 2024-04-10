
/*
 template by c8kbf
 */

// macOS doesn't have <bits/stdc++.h> (shame)
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



constant maxn = 1E5+8;

_ n, m, t[12][maxn<<2];
char a[maxn];

void update(_ l, _ r, _ p, char c, _ pos);
void build(_ l, _ r, _ pos);
void pushUp(_ pos);
inline void AC() {
    
    n = read();
    m = read();
    read(a+1);
    build(1, n, 1);
    for(_ i = 1; i <= m; ++i) {
        _ x;
        char c;
        x = read();
        c = getLw();
        update(1, n, x, c, 1);
        writeln(t[0][1]);
    }
    
    return;
}

void pushUp(_ pos) {
    t[11][pos] = t[11][pos<<1]+t[11][pos<<1|1];
    t[10][pos] = t[10][pos<<1]+t[10][pos<<1|1];
    t[9][pos] = t[9][pos<<1]+t[9][pos<<1|1];
    t[8][pos] = t[8][pos<<1]+t[8][pos<<1|1];
    t[7][pos] = min(t[7][pos<<1]+t[11][pos<<1|1], t[10][pos<<1]+t[7][pos<<1|1]);
    t[6][pos] = t[6][pos<<1]+t[6][pos<<1|1];
    t[5][pos] = min(t[5][pos<<1]+t[10][pos<<1|1], t[9][pos<<1]+t[5][pos<<1|1]);
    t[4][pos] = t[4][pos<<1]+t[4][pos<<1|1];
    t[3][pos] = min(min(t[3][pos<<1]+t[11][pos<<1|1], t[6][pos]), min(t[5][pos<<1]+t[7][pos<<1|1], t[9][pos<<1]+t[3][pos<<1|1]));
    t[2][pos] = min(t[2][pos<<1]+t[8][pos<<1|1], t[6][pos<<1]+t[2][pos<<1|1]);
    t[1][pos] = min(t[1][pos<<1]+t[6][pos<<1|1], t[4][pos<<1]+t[1][pos<<1|1]);
    t[0][pos] = min(min(t[4][pos<<1]+t[0][pos<<1|1], t[0][pos<<1]+t[8][pos<<1|1]), t[1][pos<<1]+t[2][pos<<1|1]);
    return;
}

void build(_ l, _ r, _ pos) {
    if(l == r) {
        for(_ i = 0; i <= 11; ++i) t[i][pos] = 1;
        if(a[l] == 'a') for(_ i : (v_){0, 1, 2, 3, 6, 7, 8, 11}) t[i][pos] = 0;
        ef(a[l] == 'b') for(_ i : (v_){0, 1, 2, 3, 4, 5, 7, 8, 10}) t[i][pos] = 0;
        else for(_ i : (v_){0, 1, 2, 3, 4, 5, 6, 9}) t[i][pos] = 0;
        return;
    }
    _ md = (l+r)>>1;
    build(l, md, pos<<1);
    build(md+1, r, pos<<1|1);
    pushUp(pos);
    return;
}

void update(_ l, _ r, _ p, char c, _ pos) {
    if(l == r) {
        for(_ i = 0; i <= 11; ++i) t[i][pos] = 1;
        if(c == 'a') for(_ i : (v_){0, 1, 2, 3, 6, 7, 8, 11}) t[i][pos] = 0;
        ef(c == 'b') for(_ i : (v_){0, 1, 2, 3, 4, 5, 7, 8, 10}) t[i][pos] = 0;
        else for(_ i : (v_){0, 1, 2, 3, 4, 5, 6, 9}) t[i][pos] = 0;
        return;
    }
    _ md = (l+r)>>1;
    if(p <= md) update(l, md, p, c, pos<<1);
    else update(md+1, r, p, c, pos<<1|1);
    pushUp(pos);
    return;
}