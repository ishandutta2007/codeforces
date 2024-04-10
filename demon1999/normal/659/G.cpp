#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define sz(a) a.size()
#define re  return
#define fi first
#define se second

typedef std::pair<int, int> pii;
typedef long long ll;
using namespace std;
const ll mod = 1000000007;
void my_assert(bool q) {
    if (!q) while(true);
}

ll n, m, k, p11, qq, cc, ans, dp[3][1000100];
vector<ll> h, q[1000010];

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("point.in", "r", stdin);
    //freopen("point.out", "w", stdout);
    cin >> n;
    h.resize(n);
    forn (i, n) {
        cin >> h[i];
        h[i]--;
    }
    forn (j, n) {
        q[j].push_back(h[j] - 1);
        if (j && h[j - 1] < h[j])
            q[j].push_back(h[j - 1] - 1);
        if (j < n - 1 && h[j + 1] < h[j])
            q[j].push_back(h[j + 1] - 1);
        sort(q[j].begin(), q[j].end());
    }
    forn (j, n) {
        for (int i = 0; i < sz(q[j]); i++) {
            ll cc = 0;
            if (i == 0) cc = q[j][i] + 1;
            else cc = q[j][i] - q[j][i - 1];
            //cout << q[j][i] << " " << cc << " ";
            dp[i][j] = cc;
            if (j)
                for (int p = 0; p < sz(q[j - 1]); p++) {
                    if (q[j - 1][p] <= h[j] - 1 && h[j - 1] - 1 >= q[j][i]) {
                        dp[i][j] = (dp[i][j] + cc * dp[p][j - 1]) % mod;
                    }
                }
            //cout << dp[i][j] << " ";
            ans += dp[i][j];
            ans %= mod;
        }
        //cout << endl;
    }
    cout << ans;
    return 0;
}