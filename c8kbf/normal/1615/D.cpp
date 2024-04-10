
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



constant maxn = 5E5+8;

_ n, m, x, y, c, low[maxn], dfn[maxn], cnt, col[maxn], cnum;
struct edge {
    _ to, cost;
};
v(edge) t[maxn];
v_ g[maxn];
stack<_> s;
bool v[maxn];
struct edgeo {
    _ x, y, c;
};
v(edgeo) o;

void ret(_ x, _ fa);
void paint(_ x);
void tarjan(_ x);
void treefs(_ x, _ fa);
_ ew(_ x);
inline void AC() {
    
    n = read();
    m = read();
    for(_ i = 1; i <= n+n+100; ++i) {
        g[i].clear();
        t[i].clear();
        v[i] = false;
        low[i] = dfn[i] = col[i] = cnt = cnum = 0;
    }
    for(; !s.empty(); ) s.pop();
    o.clear();
    for(_ i = n; --i; ) {
        x = read();
        y = read();
        c = read();
        t[x].push_back((edge){y, c});
        t[y].push_back((edge){x, c});
    }
    for(_ i = m; i--; ) {
        x = read();
        y = read();
        c = read();
        if(c) {
            g[x].push_back(y+n);
            g[y+n].push_back(x);
            g[y].push_back(x+n);
            g[x+n].push_back(y);
        } else {
            g[x].push_back(y);
            g[x+n].push_back(y+n);
            g[y].push_back(x);
            g[y+n].push_back(x+n);
        }
    }
    treefs(1, -1);
    for(_ i = 1; i <= (n<<1); ++i) if(!dfn[i]) tarjan(i);
    for(_ i = 1; i <= n; ++i) if(col[i] == col[i+n]) {
        no(7);
        return;
    }
    yes(7);
    ret(1, -1);
    for(edgeo i : o) {
        writesc(i.x);
        writesc(i.y);
        writeln(i.c);
    }
    
    return;
}

_ ew(_ x) {
    _ c = 0;
    for(; x; x >>= 1) if(x&1) ++c;
    return c&1;
}

void treefs(_ x, _ fa) {
    for(edge i : t[x]) if(i.to != fa) {
        treefs(i.to, x);
        if(i.cost != -1) {
            if(ew(i.cost)) {
                g[i.to].push_back(x+n);
                g[x+n].push_back(i.to);
                g[i.to+n].push_back(x);
                g[x].push_back(i.to+n);
            } else {
                g[i.to].push_back(x);
                g[x].push_back(i.to);
                g[i.to+n].push_back(x+n);
                g[x+n].push_back(i.to+n);
            }
        }
    }
    return;
}

void tarjan(_ x) {
    low[x] = dfn[x] = ++cnt;
    s.push(x);
    v[x] = true;
    for(_ i : g[x]) if(!dfn[i]) {
        tarjan(i);
        low[x] = min(low[x], low[i]);
    } ef(v[i]) low[x] = min(low[x], dfn[i]);
    if(low[x] == dfn[x]) {
        ++cnum;
        while(!s.empty() && s.top() != x) paint(s.top());
        paint(x);
    }
    return;
}

void paint(_ x) {
    s.pop();
    col[x] = cnum;
    v[x] = false;
    return;
}

void ret(_ x, _ fa) {
    for(edge i : t[x]) if(i.to != fa) {
        ret(i.to, x);
        if(i.cost == -1) {
            _ va = (col[i.to] < col[i.to+n]), vb = (col[x] < col[x+n]);
            o.push_back((edgeo){x, i.to, va^vb});
        } else o.push_back((edgeo){x, i.to, i.cost});
    }
    return;
}