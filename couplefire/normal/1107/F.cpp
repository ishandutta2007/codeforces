#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

typedef long long ll;
const int N = 505;
ll n, f[N][N], ans;
struct node { ll a, b, K; }e[N];

bool cmp(node x, node y) {
    return x.b > y.b;
}

int main() {
    cin >> n;
    rep(i, 1, n) cin >> e[i].a >> e[i].b >> e[i].K;
    sort(e + 1, e + n + 1, cmp);
    memset(f, 192, sizeof(f));
    f[0][0] = 0;
    rep(i, 1, n) {
        rep(j, 0, i) {
            f[i][j] = f[i - 1][j];
            f[i][j] = max(f[i][j], f[i - 1][j] + e[i].a - e[i].b * e[i].K);
            if (j && j - 1 <= e[i].K)
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + e[i].a - e[i].b * (j - 1));
            if (i == n)
                ans = max(ans, f[i][j]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}