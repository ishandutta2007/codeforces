#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 1e5 + 7;
const int INF = (int) 1e9;
int n, a[N], dp[N], b[N], Dif[N];

int sb(int l, int r) {
        assert(l <= r + 1);
        return b[r] - b[l - 1];
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++)
                cin >> a[i];
        for (int i = 1; i <= n; i++) {
                dp[i] = INF;
                Dif[i] = INF;
                b[i] = b[i - 1] + (a[i] != a[i - 1]);
        }
        int BestDif = INF;
        for (int i = 1; i <= n; i++) {
                dp[i] = sb(2, i) - b[i - 1];
                dp[i] = min(dp[i], BestDif);
                dp[i] = min(dp[i], Dif[a[i]] - 1);
                dp[i] += b[i - 1];
                BestDif = min(BestDif, dp[i] - b[i] + 1);
                Dif[a[i - 1]] = min(Dif[a[i - 1]], dp[i] - b[i] + 1);
        }

        int ret = INF;
        for (int i = 1; i <= n; i++) {
                int cost = dp[i] + sb(i + 1, n);
                ret = min(ret, cost);
        }
        cout << min(ret + 1, n) << "\n";
}