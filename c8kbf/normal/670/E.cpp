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

constant maxn = 5E5+8;

_ n, m, p, c, b;
char ch;
struct nd {
    char dt;
    _ ls, nx;
} a[maxn];

void prf();
void erase(_ x);
char gc();
inline void AC() {
    
    scanf("%lld%lld%lld", &n, &m, &p);
    for(_ i = 1; i <= n; ++i) {
        a[i].dt = gc();
        a[i].ls = i-1;
        a[i].nx = i+1;
    }
    a[0].nx = 1;
    a[n+1].ls = n;
    for(_ i = 1; i <= m; ++i) {
        ch = gc();
        if(ch == 'L') p = a[p].ls;
        ef(ch == 'R') p = a[p].nx;
        ef(ch == 'D') {
            if(a[p].dt == '(') {
                c = 1;
                b = p;
                p = a[p].nx;
                erase(b);
                for(; c; ) {
                    if(a[p].dt == '(') ++c;
                    ef(a[p].dt == ')') --c;
                    b = p;
                    p = a[p].nx;
                    erase(b);
                }
                if(p == n+1) p = a[p].ls;
            } else {
                c = -1;
                b = p;
                p = a[p].ls;
                erase(b);
                for(; c; ) {
                    if(a[p].dt == '(') ++c;
                    ef(a[p].dt == ')') --c;
                    b = p;
                    p = a[p].ls;
                    erase(b);
                    prf();
                }
                p = a[p].nx;
                if(p == n+1) p = a[p].ls;
            }
        }
        prf();
    }
    for(_ i = a[0].nx; i <= n; i = a[i].nx) putchar(a[i].dt);
    putchar(10);
    
    return;
}

char gc() {
    char ch = getchar();
    for(; ch == ' ' || ch == '\n'; ) ch = getchar();
    return ch;
}

void erase(_ x) {
    a[a[x].ls].nx = a[x].nx;
    a[a[x].nx].ls = a[x].ls;
    return;
}

void prf() {
//    for(_ i = 1; i <= n; i = a[i].nx) putchar(a[i].dt);
//    putchar(10);
    return;
}