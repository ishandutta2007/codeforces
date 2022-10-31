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
    int n, m; rii(n, m);
    const char p[] = "face";
    char s[110][110];
    rep(i, n) rs(s[i]);
    int ans = 0;
    rep(i, n - 1) rep(j, m - 1) {
        int cnt[128] = {};
        rep(k, 2) rep(l, 2)
            cnt[s[i + k][j + l]]++;
        bool f = true;
        rep(k, 4) if(!cnt[p[k]]) {
            f = false;
            break;
        }
        if(f) ans++;
    }
    pi(ans);
    return 0;
}