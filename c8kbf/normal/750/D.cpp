#include <bits/stdc++.h>
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
#define rd(a, sz) for(_ i = 1; i <= sz; ++i) a[i] = read();
#define wr(a, sz) for(_ i = 1; i <= sz; ++i) writesc(a[i]); clr();
#define i(x) x::iterator
#define pr(x, y) pair< x, y >
#define mp(x, y) make_pair(x, y)
using namespace std;typedef long long _;typedef int _0;typedef double _D;typedef unsigned long long u_;typedef string str;typedef vector<_> v_;typedef pair<_, _> _p;typedef const long long constant;inline void AC();
int main(int argc, char * argv[]) {
    //    #define multiple_testcases
#ifdef multiple_testcases
    _ tc = read(); for(; tc--; ) AC();
#else
    AC();// good luck!
#endif
    return 0;}

constant maxn = 30+8;

_ n, a[maxn], dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
set<_p> st;
struct qr {
    _ x, y, dr, lv;
    bool operator < (const qr &b) const {
        if(x != b.x) return x < b.x;
        if(y != b.y) return y < b.y;
        if(dr != b.dr) return dr < b.dr;
        return lv < b.lv;
    }
};
set<qr> bn;

void dfs(_ x, _ y, _ dr, _ lv);
inline void AC() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    dfs(1, 1, 0, 1);
    printf("%lld\n", (_)st.size());
    
    return;
}

void dfs(_ x, _ y, _ dr, _ lv) {
    if(bn.count((qr){x, y, dr, lv})) return;
    bn.insert((qr){x, y, dr, lv});
    if(lv > n) return;
    if(dr < 0) dr = 7;
    if(dr > 7) dr = 0;
    x += dx[dr];
    y += dy[dr];
    for(_ i = a[lv]; i--; ) {
        st.insert(mp(x, y));
        x += dx[dr];
        y += dy[dr];
    }
    x -= dx[dr];
    y -= dy[dr];
    dfs(x, y, dr+1, lv+1);
    dfs(x, y, dr-1, lv+1);
    return;
}