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

int n, m, q, a[510][510], score[510];

int cal(int *a) {
    int t = 0, r = 0;
    rep(i, m) {
        t = a[i] ? t + 1 : 0;
        r = max(r, t);
    }
    return r;
}

int main() {
    riii(n, m, q);
    rep(i, n) ria(a[i], m);
    rep(i, n) score[i] = cal(a[i]);
    rep(i, q) {
        int x, y; rii(x, y);
        a[x - 1][y - 1] ^= 1;
        score[x - 1] = cal(a[x - 1]);
        int ans = 0;
        rep(i, n) ans = max(ans, score[i]);
        pi(ans);
    }
    return 0;
}