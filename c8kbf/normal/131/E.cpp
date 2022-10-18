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
#define rd(a, sz) for(_ i = 1; i <= sz; ++i) scanf("%lld", &a[i]);
#define wr(a, sz) for(_ i = 1; i <= sz; ++i) printf("%lld%c", a[i], i == sz ? '\n' : ' ');
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
constant big = 1E5+2;

_ n, m, o[maxn];
_p a[maxn];
set<_> x[maxn], y[maxn], pl[maxn], mn[maxn];

inline void AC() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= m; ++i) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
        x[a[i].first].insert(a[i].second);
        y[a[i].second].insert(a[i].first);
        pl[a[i].first+a[i].second].insert(a[i].first);
        mn[a[i].first-a[i].second+big].insert(a[i].first);
    }
    for(_ i = 1; i <= m; ++i) {
        _ c = 0;
        if(x[a[i].first].upper_bound(a[i].second) != x[a[i].first].end()) ++c;
        set<_>::iterator it = x[a[i].first].lower_bound(a[i].second);
        if(it != x[a[i].first].end() && it != x[a[i].first].begin()) ++c;
        if(y[a[i].second].upper_bound(a[i].first) != y[a[i].second].end()) ++c;
        it = y[a[i].second].lower_bound(a[i].first);
        if(it != y[a[i].second].end() && it != y[a[i].second].begin()) ++c;
        if(pl[a[i].first+a[i].second].upper_bound(a[i].first) != pl[a[i].first+a[i].second].end()) ++c;
        it = pl[a[i].first+a[i].second].lower_bound(a[i].first);
        if(it != pl[a[i].first+a[i].second].begin() && it != pl[a[i].first+a[i].second].end()) ++c;
        if(mn[a[i].first-a[i].second+big].upper_bound(a[i].first) != mn[a[i].first-a[i].second+big].end()) ++c;
        it = mn[a[i].first-a[i].second+big].lower_bound(a[i].first);
        if(it != mn[a[i].first-a[i].second+big].begin() && it != mn[a[i].first-a[i].second+big].end()) ++c;
        ++o[c];
    }
    for(_ i = 0; i <= 8; ++i) printf("%lld ", o[i]);
    putchar(10);
    
    return;
}