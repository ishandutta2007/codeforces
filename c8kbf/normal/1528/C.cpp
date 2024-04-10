
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
//
//dont worry bout me, i'm not high
#define ef else if
#define leave exit(0);

#define v(x) vector<x >
#define v2(x) vector<vector<x > >
#define v3(x) vector<vector<vector<x > > >

#define ss(x) v(_)(x+8, 0)
#define ssz(type, x) v(type)(x+8, 0)
#define s2(x, y) v2(_)(x+8, v(_)(y+8, 0))
#define s2z(type, x, y) v2(type)(x+8, v(type)(y+8, 0))
#define s3(x, y, z) v3(_)(x+8, v2(_)(y+8, v(_)(z+8, 0)))
#define s3z(type, x, y, z) v3(type)(x+8, v2(type)(y+8, v(type)(z+8, 0)))

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
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

const char untl = '\n';

//fastIO cos why not
inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline bool read(_ &x) {
    x = 0;
    _ f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    x *= f;
    if(ch == '\r') ch = getchar();
    return ch != untl && ch != EOF;
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

inline void write(char const * a) {
    for(_ i = 0; a[i]; ++i) putchar(a[i]);
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

inline void spc() {
    putchar(32);
    return;
}

inline void writeln(_ x) { //pascal vibes
    write(x);
    clr();
    return;
}

inline void writeln(char const * a) { //pascal vibes
    write(a);
    clr();
    return;
}

inline void writeln(char a) { //pascal vibes
    write(a);
    clr();
    return;
}

inline void writeln(_p a, char const * b = " ") {
    write(a, b);
    clr();
    return;
}

inline void writesc(_ x) {
    write(x);
    spc();
    return;
}

inline void writesc(char const * a) {
    write(a);
    spc();
    return;
}

inline void writesc(char a) {
    write(a);
    spc();
    return;
}

inline void writesc(_p a, char const * b = " ") {
    write(a);
    spc();
    return;
}

inline void AC();
int main(int argc, char * argv[]) {

//    #define file_IO
#ifdef file_IO
    str fileN = "";
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif

    #define multiple_testcases
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

_ n, x, st[maxn], ed[maxn], t[maxn<<2], lz[maxn<<2], cnt, s, c;
v_ g[maxn], h[maxn];

void dfs2(_ x, _ fa);
void update(_ L, _ R, _ l, _ r, _ c, _ pos);
_ query(_ L, _ R, _ l, _ r, _ pos);
void pushDown(_ pos);
void build(_ l, _ r, _ pos);
void dfs(_ x, _ fa);
inline void AC() {
    
    n = read();
    cnt = c = 0;
    s = -1E11;
    for(_ i = 1; i <= n; ++i) {
        g[i].clear();
        h[i].clear();
    }
    for(_ i = 2; i <= n; ++i) {
        x = read();
        g[x].push_back(i);
    }
    for(_ i = 2; i <= n; ++i) {
        x = read();
        h[x].push_back(i);
    }
    dfs(1, -1);
    build(1, n, 1);
    dfs2(1, -1);
    writeln(s);
    
    return;
}

void dfs(_ x, _ fa) {
    st[x] = ++cnt;
    for(_ i : h[x]) if(i != fa) dfs(i, x);
    ed[x] = cnt;
    return;
}

void build(_ l, _ r, _ pos) {
    t[pos] = lz[pos] = n+1;
    if(l == r) return;
    _ md = (l+r)>>1;
    build(l, md, pos<<1);
    build(md+1, r, pos<<1|1);
    return;
}

void pushDown(_ pos) {
    lz[pos<<1] = lz[pos<<1|1] = t[pos<<1] = t[pos<<1|1] = lz[pos];
    lz[pos] = 0;
    return;
}

void pushUp(_ pos) {
    t[pos] = min(t[pos<<1], t[pos<<1|1]);
    return;
}

void update(_ L, _ R, _ l, _ r, _ c, _ pos) {
    if(L <= l && r <= R) {
        t[pos] = lz[pos] = c;
        return;
    }
    if(lz[pos]) pushDown(pos);
    _ md = (l+r)>>1;
    if(L <= md) update(L, R, l, md, c, pos<<1);
    if(R > md) update(L, R, md+1, r, c, pos<<1|1);
    pushUp(pos);
    return;
}

_ query(_ L, _ R, _ l, _ r, _ pos) {
    if(L <= l && r <= R) return t[pos];
    if(lz[pos]) pushDown(pos);
    _ md = (l+r)>>1, rv = 1E11;
    if(L <= md) rv = min(rv, query(L, R, l, md, pos<<1));
    if(R > md) rv = min(rv, query(L, R, md+1, r, pos<<1|1));
    return rv;
}

void dfs2(_ x, _ fa) {
    _ sv = query(st[x], st[x], 1, n, 1), t = query(st[x], ed[x], 1, n, 1), tp = 1;
    if(sv != n+1) tp = 2;
    ef(t != n+1) tp = 3;
    if(tp == 1) {
        update(st[x], ed[x], 1, n, x, 1);
        ++c;
    } ef(tp == 2) {
        update(st[sv], ed[sv], 1, n, n+1, 1);
        update(st[x], ed[x], 1, n, x, 1);
    }
    s = max(s, c);
    for(_ i : g[x]) if(i != fa) dfs2(i, x);
    if(tp == 1) {
        update(st[x], ed[x], 1, n, n+1, 1);
        --c;
    } ef(tp == 2) {
        update(st[x], ed[x], 1, n, n+1, 1);
        update(st[sv], ed[sv], 1, n, sv, 1);
    }
    return;
}