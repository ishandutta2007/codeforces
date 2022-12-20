#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXn = 2e5 + 5;
ll dp[MAXn], vis[MAXn];
vector<int> v[MAXn];

bool dfs(ll now) {
    vis[now] = 1;
    dp[now] = 1;
    for (ll k : v[now]) {
        if (vis[k] == 1)
            return false;
        if (!vis[k]) {
            if (!dfs(k))
                return false;
        }
        if (k < now)
            dp[now] = max(dp[now], dp[k]);
        else
            dp[now] = max(dp[now], dp[k] + 1);
    }
    vis[now] = 2;
    return true;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            v[i].clear();
            for (int j = 1; j <= k; j++) {
                int x;
                cin >> x;
                v[i].pb(x);
            }
            dp[i] = -1;
            vis[i] = 0;
        }
        bool fg = 0;
        for (int i = 1; i <= n; i++)
            if (dp[i] == -1) {
                if (!dfs(i)) {
                    fg = 1;
                    break;
                }
            }
        if (fg) {
            cout << -1 << endl;
            continue;
        }
        cout << (*max_element(dp + 1, dp + 1 + n)) << "\n";
    }
}