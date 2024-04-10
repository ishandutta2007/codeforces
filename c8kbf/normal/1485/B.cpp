
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

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef long double _D;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

char untl = '\n';

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

inline void AC();
int main(int argc, char * argv[]) {

    str fileN = "";

    //#define Submit
#ifdef Submit
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    //#define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
#else
    _ tc = 1;
#endif
    
    for(; tc--; ) AC(); // good luck!

    return 0;
}



// ----- End of Template -----



constant maxn = 1E5+8;
constant srt = 320;

_ n, q, k, a[maxn], x, y, o[maxn];
struct query {
    _ l, r, id;
    bool operator < (const query &b) const {
        return r < b.r;
    }
} t;
vector<query> g[srt+8];

inline void AC() {
    
    n = read();
    q = read();
    k = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    for(_ i = 1; i <= q; ++i) {
        t.l = read();
        t.r = read();
        t.id = i;
        g[(_)sqrt(t.l)].push_back(t);
    }
    for(_ i = 0; i <= srt; ++i) {
        if(g[i].empty()) continue;
        sort(g[i].begin(), g[i].end());
        _ t = 0;
        for(_ j = g[i][0].l; j <= g[i][0].r; ++j) {
            t += k-1;
            if(j != g[i][0].l) {
                t -= k-a[j]+1;
                t -= a[j-1];
            }
        }
        o[g[i][0].id] = t;
        for(_ j = 1; j < g[i].size(); ++j) {
            for(_ k = g[i][j-1].r+1; k <= g[i][j].r; ++k) {
                t += ::k-1;
                t -= ::k-a[k]+1;
                t -= a[k-1];
            }
            if(g[i][j].l > g[i][j-1].l) for(_ k = g[i][j-1].l; k <= g[i][j].l-1; ++k) {
                t -= a[k+1]-2;
                t += a[k];
            }
            else for(_ k = g[i][j-1].l-1; k >= g[i][j].l; --k) {
                t += a[k+1]-2;
                t -= a[k];
            }
            o[g[i][j].id] = t;
        }
    }
    for(_ i = 1; i <= q; ++i) writeln(o[i]);
    
    return;
}