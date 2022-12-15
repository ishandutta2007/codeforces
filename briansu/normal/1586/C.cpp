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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
    auto dp = d;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
            d[i][j] = (s[j - 1] == '.');
    }
    vector<int> ans(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            if (d[i][j]) {
                dp[i][j] = j;
                if (i == 1)
                    dp[i][j] = 1;
                if (d[i - 1][j])
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                if (d[i][j - 1])
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                ans[j] = max(ans[j], dp[i][j]);
            }
            else {
                if (i != 1 && j != 1 && !d[i][j - 1] && !d[i - 1][j])
                    ans[j] = max(ans[j], j);
            }
        }
    }
    for (int i = 1; i <= m; i++)
        ans[i] = max(ans[i], ans[i - 1]);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (ans[r] > l)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    
    
}