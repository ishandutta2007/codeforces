#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXn = 1e5 + 5;
const long long MOD = 1000000007;
vector<int> v[MAXn];
ll dp[MAXn][2];
ll d[MAXn];

void dfs(int now) {
    if (d[now])
        dp[now][0] = 0, dp[now][1] = 1;
    else
        dp[now][0] = 1, dp[now][1] = 0;
    for (ll k : v[now]) {
        dfs(k);
        ll n0 = dp[now][0] * (dp[k][0] + dp[k][1]);
        ll n1 = dp[now][0] * dp[k][1] + dp[now][1] * (dp[k][0] + dp[k][1]);
        dp[now][0] = n0 % MOD;
        dp[now][1] = n1 % MOD;
    }

}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        v[p].push_back(i);
    }
    for (int i = 0; i < n; i++)
        cin >> d[i];
    dfs(0);
    cout << dp[0][1] << endl;
}