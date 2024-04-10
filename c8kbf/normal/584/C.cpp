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

constant maxn = 1E5+8;

_ n, m, dx;
char a[maxn], b[maxn], o[maxn];

void no();
inline void AC() {
    
    scanf("%lld%lld %s %s", &n, &m, a+1, b+1);
    _ sc = 0, dc = 0;
    for(_ i = 1; i <= n; ++i) {
        if(a[i] == b[i]) ++sc;
        else ++dc;
    }
    if(((dc+1)>>1) > m) no();
    if(dc & 1) {
        for(_ i = 1; i <= n; ++i) if(a[i] != b[i]) {
            dx = i;
            break;
        }
    }
    _ t = n-m;
    bool dn = false;
    for(_ i = 1; i <= n; ++i) {
        for(char j = 'a' ; j <= 'z'; ++j) if(j != a[i] && j != b[i]) {
            o[i] = j;
            break;
        }
    }
    for(_ i = 1; (t || dn) && i <= n; ++i) if(i != dx) {
        if(a[i] == b[i]) {
            if(!t && dn) continue;
            o[i] = a[i];
            --t;
        } else {
            if(!dn) {
                o[i] = a[i];
                --t;
                dn = true;
            } else {
                o[i] = b[i];
                dn = false;
            }
        }
    }
    printf("%s\n", o+1);
    
    return;
}

void no() {
    puts("-1");
    exit(0);
}