
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
typedef __int128 _;
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




constant maxn = 8E5+8;

_ n, m, a[maxn], d[maxn], nn, c[maxn], t[maxn], lz[maxn], tt[maxn];
struct grp {
    v_ st;
    _ sm;
    bool operator < (const grp &b) const {
        return sm*b.st.size() < b.sm*st.size();
    }
} b[maxn];
bitset<maxn> o;

_ query(_ l, _ r, _ pos);
void update(_ L, _ R, _ l, _ r, _ c, _ pos);
void pushDown(_ pos);
void build(_ l, _ r, _ pos);
void pushUp(_ pos);
inline void AC() {
    
    n = read();
    m = read();
    rd(a, n);
    sort(a+1, a+1+n);
    for(_ i : rg(n)) d[i] = a[i];
    nn = unique(d+1, d+1+n)-d-1;
    _ cnt = 0;
    for(_ i = 1; i <= m; ++i) {
        b[i].st.clear();
        b[i].sm = 0;
        _ k = read();
        for(; k--; ) {
            _ x = read();
            c[++cnt] = x;
            b[i].st.push_back(cnt);
            b[i].sm += x;
        }
    }
//    sort(b+1, b+1+m);
    build(1, nn+1, 1);
    for(_ i = 1; i <= n; ++i) {
//        writeln((_)(lower_bound(d+1, d+1+nn, a[i])-d));
        update(1, lower_bound(d+1, d+1+nn, a[i])-d, 1, nn+1, 1, 1);
    }
    for(_ i = 1; i <= m; ++i) {
        _ vl = (b[i].sm-1)/(b[i].st.size())+1;
        if(vl != ceil(1.L*b[i].sm/b[i].st.size())) exit(1);
//        writeln((_)(lower_bound(d+1, d+1+nn, vl)-d));
        update(1, lower_bound(d+1, d+1+nn, vl)-d, 1, nn+1, -1, 1);
    }
    for(_ i : rg(m)) {
        _ vl = (b[i].sm-1)/(b[i].st.size())+1;
        if(vl != ceil(1.L*b[i].sm/b[i].st.size())) exit(1);
        update(1, lower_bound(d+1, d+1+nn, vl)-d, 1, nn+1, 1, 1);
        _ cr = query(1, nn+1, 1);
        for(_ j : b[i].st) {
            if(cr > nn || !~cr) o.reset(j);
            ef(d[cr] < (b[i].sm-c[j]-1)/(b[i].st.size()-1)+1) {
                o.reset(j);
                if(ceil(1.L*(b[i].sm-c[j])/(b[i].st.size()-1)) != (b[i].sm-c[j]-1)/(b[i].st.size()-1)+1) exit(1);
            } else o.set(j);
        }
        update(1, lower_bound(d+1, d+1+nn, vl)-d, 1, nn+1, -1, 1);
    }
    for(_ i : rg(cnt)) write(o[i] ? '1' : '0');
    clr();
    
    return;
}

void pushUp(_ pos) {
    t[pos] = min(t[pos<<1], t[pos<<1|1]);
    tt[pos] = max(tt[pos<<1], tt[pos<<1|1]);
    return;
}

void build(_ l, _ r, _ pos) {
    t[pos] = tt[pos] = lz[pos] = 0;
    if(l == r) return;
    _ md = (l+r)>>1;
    build(l, md, pos<<1);
    build(md+1, r, pos<<1|1);
    pushUp(pos);
    return;
}

void pushDown(_ pos) {
    t[pos<<1] += lz[pos];
    t[pos<<1|1] += lz[pos];
    tt[pos<<1] += lz[pos];
    tt[pos<<1|1] += lz[pos];
    lz[pos<<1] += lz[pos];
    lz[pos<<1|1] += lz[pos];
    lz[pos] = 0;
    return;
}

void update(_ L, _ R, _ l, _ r, _ c, _ pos) {
    if(L <= l && r <= R) {
        t[pos] += c;
        tt[pos] += c;
        lz[pos] += c;
        return;
    }
    _ md = (l+r)>>1;
    pushDown(pos);
    if(L <= md) update(L, R, l, md, c, pos<<1);
    if(R > md) update(L, R, md+1, r, c, pos<<1|1);
    pushUp(pos);
    return;
}

_ query(_ l, _ r, _ pos) {
    if(l == r) {
        if(!tt[pos]) return -1;
        return l;
    }
    if(t[pos] < 0) return -1;
    pushDown(pos);
    _ md = (l+r)>>1;
    if(t[pos<<1] <= 0) return query(l, md, pos<<1);
    _ qr = query(md+1, r, pos<<1|1);
    if(~qr) return qr;
    return md;
}