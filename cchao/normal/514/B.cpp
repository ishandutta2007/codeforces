#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define rs(s) scanf("%s", s)
#define pi(n) printf("%d\n", n)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define ria(a, n) rep(_, n) scanf("%d", &a[_])
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)
#define PB push_back
#define MP make_pair

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;
const double eps = 1e-8;


int main() {
    int n, x, y;
    riii(n, x, y);
    set<pii> s;
    rep(i, n) {
        int a, b; rii(a, b); a -= x, b -= y;
        if(a<0) a = -a, b = -b;
        int g = __gcd(abs(a), abs(b));
        a /= g, b /= g;
        if(a == 0 && b) b = 1;
        if(b == 0 && a) a = 1;
        s.insert(pii(a, b));
    }
    pi((int)s.size());
    
    return 0;
}