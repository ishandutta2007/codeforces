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
#define IO(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout)
#define PB push_back
#define MP make_pair

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 200010;
const double eps = 1e-8;
int p[maxn], nxt[maxn];
int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }

int main() {
    int n, q; rii(n, q);
    for(int i = 1; i <= n; ++i) p[i] = i, nxt[i] = i + 1;
    rep(__, q) {
        int op, x, y; riii(op, x, y); if(x > y) swap(x, y);
        if(op == 1) {
            int fa = f(x), fb = f(y);
            p[fb] = fa;
        }
        else if(op == 2) {
            int fa = f(x);
            for(;;) {
                int t = nxt[x];
                if(t > y) break;
                nxt[x] = y + 1;
                x = t;
                p[f(x)] = fa;
            }
        }
        else puts(f(x) == f(y) ? "YES" : "NO");
    }
    
    return 0;
}