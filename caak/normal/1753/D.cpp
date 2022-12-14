
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




_ n, m, x, y;
v2(char) a;
v2(_) d, da, fx, fy;
struct edge {
    _p p;
    _ d;
};
v2(v(edge)) g;
struct node {
    _p p;
    _ d;
    bool operator < (const node &b) const {
        return d > b.d;
    }
};
priority_queue<node> q;

inline void AC() {
    
    read({n, m, x, y});
    a = s2z(char, n, m);
    d = da = fx = fy = s2(n, m);
    g = v2(v(edge))(n+8, v(v(edge))(m+8, v(edge)())); //what the fuck have i done
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) a[i][j] = gc();
    for(_ i = 0; i <= n+3; ++i) for(_ j = 1; j <= m; ++j) d[i][j] = da[i][j] = fx[i][j] = fy[i][j] = (_)1E16;
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) {
        if(a[i][j] == '.') {
            d[i][j] = 0;
            fx[i][j] = i;
            fy[i][j] = j;
            q.push((node){mp(i, j), 0});
        }
        if(a[i][j] != '#') {
            if(a[i-1][j] == 'D') g[i][j].push_back((edge){mp(i-2, j), y});
            if(a[i+1][j] == 'U') g[i][j].push_back((edge){mp(i+2, j), y});
            if(a[i][j-1] == 'R') g[i][j].push_back((edge){mp(i, j-2), y});
            if(a[i][j+1] == 'L') g[i][j].push_back((edge){mp(i, j+2), y});
            if(a[i-1][j] == 'L') g[i][j].push_back((edge){mp(i-1, j+1), x});
            if(a[i-1][j] == 'R') g[i][j].push_back((edge){mp(i-1, j-1), x});
            if(a[i+1][j] == 'L') g[i][j].push_back((edge){mp(i+1, j+1), x});
            if(a[i+1][j] == 'R') g[i][j].push_back((edge){mp(i+1, j-1), x});
            if(a[i][j-1] == 'D') g[i][j].push_back((edge){mp(i-1, j-1), x});
            if(a[i][j-1] == 'U') g[i][j].push_back((edge){mp(i+1, j-1), x});
            if(a[i][j+1] == 'D') g[i][j].push_back((edge){mp(i-1, j+1), x});
            if(a[i][j+1] == 'U') g[i][j].push_back((edge){mp(i+1, j+1), x});
        }
    }
    for(; !q.empty(); ) {
        node t = q.top();
        q.pop();
        if(da[t.p.first][t.p.second] < t.d) continue;
        for(edge i : g[t.p.first][t.p.second]) {
            if(d[i.p.first][i.p.second] > t.d+i.d) {
                da[i.p.first][i.p.second] = d[i.p.first][i.p.second];
                d[i.p.first][i.p.second] = t.d+i.d;
                fx[i.p.first][i.p.second] = fx[t.p.first][t.p.second];
                fy[i.p.first][i.p.second] = fy[t.p.first][t.p.second];
                q.push((node){i.p, d[i.p.first][i.p.second]});
            } ef(da[i.p.first][i.p.second] > t.d+i.d && mp(fx[i.p.first][i.p.second], fy[i.p.first][i.p.second]) != t.p) {
//            } ef(da[i.p.first][i.p.second] > t.d+i.d) {
                da[i.p.first][i.p.second] = t.d+i.d;
                q.push((node){i.p, d[i.p.first][i.p.second]});
            }
            d[i.p.first][i.p.second] = min(d[i.p.first][i.p.second], (_)1E16);
            da[i.p.first][i.p.second] = min(da[i.p.first][i.p.second], (_)1E16);
        }
    }
    _ s = 1E17;
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m-1; ++j) {
        if(mp(fx[i][j], fy[i][j]) != mp(fx[i][j+1], fy[i][j+1]) || fx[i][j] == n+2) s = min(s, d[i][j]+d[i][j+1]);
        else s = min({s, d[i][j]+da[i][j+1], da[i][j]+d[i][j+1]});
    }
    for(_ i = 1; i <= n-1; ++i) for(_ j = 1; j <= m; ++j) {
        if(mp(fx[i][j], fy[i][j]) != mp(fx[i+1][j], fy[i+1][j]) || fx[i][j] == n+2) s = min(s, d[i+1][j]+d[i][j]);
        else s = min({s, d[i+1][j]+da[i][j], da[i+1][j]+d[i][j]});
    }
    if(s > 1E15) writeln(-1);
    else writeln(s);
    
    return;
}