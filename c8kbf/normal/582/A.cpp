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

_ n, x;
multiset<_, greater<_> > st;
v_ g;

_ gcd(_ a, _ b);
inline void AC() {
    
    scanf("%lld", &n);
    n = n*n;
    for(; n--; ) {
        scanf("%lld", &x);
        st.insert(x);
    }
    for(; !st.empty(); ) {
        _ s = *st.begin();
        st.erase(st.find(s));
        for(_ i : g) {
            st.erase(st.find(gcd(i, s)));
            st.erase(st.find(gcd(i, s)));
        }
        g.push_back(s);
    }
    for(_ i : g) printf("%lld ", i);
    putchar(10);
    
    return;
}

_ gcd(_ a, _ b) {
    return !b ? a : gcd(b, a%b);
}