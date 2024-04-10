#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 998244353;
int dp[300000][3], dp2[300000][3];
vector<vector<int> > data;
void dfs(int vertex, int last){
    dp[vertex][0] = 0, dp[vertex][1] = 0, dp[vertex][2] = 1;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to==last) continue;
        dfs(to, vertex);
        dp2[vertex][0] = (dp[vertex][0] * (dp[to][0] + dp[to][2])) % MOD;
        dp2[vertex][1] = (dp[vertex][1] * (dp[to][0] + dp[to][2])) % MOD;
        dp2[vertex][2] = (dp[vertex][2] * (dp[to][0] + dp[to][2])) % MOD;
        dp2[vertex][0] += (dp[vertex][0] * dp[to][0]);
        dp2[vertex][0] %= MOD;
        dp2[vertex][1] += ((dp[vertex][1] + dp[vertex][2]) * dp[to][0]);
        dp2[vertex][1] %= MOD;
        dp2[vertex][0] += ((dp[vertex][1] + dp[vertex][2]) * (dp[to][1] + dp[to][2]));
        dp2[vertex][0] %= MOD;
        for (int j=0;j<3;j++) dp[vertex][j] = dp2[vertex][j];
        //if (vertex == 0) cout << "FOUND = " << dp[vertex][0] << " NON = " << dp[vertex][1] << " SOLE = " << dp[vertex][2] << endl;

    }
}
signed main(){
    //freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    data.resize(n, {});
    for (int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        data[a-1].push_back(b-1);
        data[b-1].push_back(a-1);
    }
    dfs(0,-1);
    cout << (dp[0][0] + dp[0][2]) % MOD;
}