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

constant maxn = 2E5+8;

_ n, a[maxn], g[maxn], dfn[maxn], low[maxn], cnt, cnum, c[maxn], b[maxn];
b(maxn) v;
stack<_> st;

void tarjan(_ x);
inline void AC() {
    
    memset(b, 4, sizeof b);
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &g[i]);
    for(_ i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
    v.reset();
    for(_ i = 1; i <= n; ++i) if(c[i] != c[g[i]]) v.set(c[i]);
    _ s = 0;
    for(_ i = 1; i <= cnum; ++i) if(!v.test(i)) s += b[i];
    printf("%lld\n", s);
    
    return;
}

void paint(_ x);
void tarjan(_ x) {
    st.push(x);
    dfn[x] = low[x] = ++cnt;
    v.set(x);
    _ i = g[x];
    if(!dfn[i]) {
        tarjan(i);
        low[x] = min(low[x], low[i]);
    } else if(v.test(i)) low[x] = min(low[x], dfn[i]);
    if(low[x] == dfn[x]) {
        ++cnum;
        for(; !st.empty() && st.top() != x; ) paint(st.top());
        paint(st.top());
    }
    return;
}

void paint(_ x) {
    b[cnum] = min(b[cnum], a[x]);
    v.reset(x);
    c[x] = cnum;
    st.pop();
    return;
}