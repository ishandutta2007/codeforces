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

_ n, m, c[maxn];
_p a[maxn];
_D b[maxn], s = -1E11;
v_ o;

bool cmp(_ x, _ y);
void test(_ x);
inline void AC() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
        m = max(m, a[i].first);
    }
    for(_ i = 1; i <= min(n, 20LL); ++i) test(i);
    printf("%lld\n", (_)o.size());
    for(_ i : o) printf("%lld ", i);
    putchar(10);
    
    return;
}

void test(_ x) {
    for(_ i = 1; i <= m; ++i) {
        b[i] = 0;
        c[i] = i;
    }
    for(_ i = 1; i <= n; ++i) b[a[i].first] += min(1.L, 1.L*a[i].second/x);
    sort(c+1, c+1+m, cmp);
    _D cr = 0;
    for(_ i = 1; i <= x; ++i) cr += b[c[i]];
    if(cr > s) {
        s = cr;
        o.clear();
        for(_ i = 1; i <= x; ++i) o.push_back(c[i]);
    }
    return;
}

bool cmp(_ x, _ y) {
    return b[x] > b[y];
}