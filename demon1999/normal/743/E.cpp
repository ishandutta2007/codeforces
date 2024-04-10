#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define x first
#define y second
#define point pair <int, int>
#define re return
#define se second
#define fi first
#define mp(a, b) make_pair(a, b)
#define mp1(a, b, c, d) make_pair(mp(a, b), mp(c, d))
using namespace std;
typedef long long ll;
const ll mod = (1e9) + 7;

ll n, ans, c[2000], cnt[8][2000], dp[256][2000], num[8][2000], jj[8];

int main() {
    iostream::sync_with_stdio(0);
    //freopen("a.in", "r", stdin);
    cin >> n;
    forn (i, n) {
        cin >> c[i];
        cnt[c[i] - 1][i + 1] = 1;
        forn (j, 8) {
            cnt[j][i + 1] += cnt[j][i];
            dp[(1 << j)][i + 1] = cnt[j][i + 1];
        }
    }
    forn (j, 8)
        jj[j] = n + 1;
    for (int i = n; i >= 0; i--) {
        forn (j, 8)
            num[j][i] = jj[j];
        if (i)
            jj[c[i - 1] - 1] = i;
    }
    forn (j, 256)
        for (int i = 0; i <= n; i++) {
            if (i) dp[j][i] = max(dp[j][i], dp[j][i - 1]);
            int p = 0;
            forn (k, 8) {
                if (j & (1 << k))
                    p++;
            }
            if (p == 0)
                continue;
            forn (k, 8) {
                if ((j & (1 << k)) == 0) {
                    int q = dp[j][i] / p;
                    for (int ii = i; ii <= n; ) {
                        if (q < cnt[k][ii] - cnt[k][i]) {
                            dp[j | (1 << k)][ii] = max(dp[j | (1 << k)][ii], dp[j][i] + q + 1);
                            break;
                        }
                        else
                            if (q == cnt[k][ii] - cnt[k][i])
                                dp[j | (1 << k)][ii] = max(dp[j | (1 << k)][ii], dp[j][i] + q);
                            else
                                dp[j | (1 << k)][ii] = max(dp[j | (1 << k)][ii], (cnt[k][ii] - cnt[k][i]) * (p + 1) + p);
                        ii = num[k][ii];
                    } 
                }
            }
        }
    cout << dp[255][n];
}