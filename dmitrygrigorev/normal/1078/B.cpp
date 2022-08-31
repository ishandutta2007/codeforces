#include <bits/stdc++.h>
#define int long long
using namespace std;
int A = 1000000007, B = 1000000009;
pair<int, int> dp[101][10001];
signed main(){
    //freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i=0; i < 101; i++) for (int j=0; j < 10001; j++) dp[i][j] = {0, 0};
    dp[0][0] = {1, 1};
    for (int i=0; i < n; i++){
        for (int j=100; j > 0; j--){
            for (int p=10000; p >= v[i]; p--){
                dp[j][p].first += dp[j-1][p-v[i]].first;
                if (dp[j][p].first >= A) dp[j][p].first -= A;
                dp[j][p].second += dp[j-1][p-v[i]].second;
                if (dp[j][p].second >= B) dp[j][p].second -= B;
            }
        }
    }
    map<int, int> kek;
    int ans = 0;
    for (int i=0;i<n;i++) kek[v[i]]++;
    pair<int, int> C[200][200];
    C[0][0] = {1, 1};
    for (int i=1; i < 200; i++){
        C[i][0] = {1, 1};
        C[i][i] = {1, 1};
        for (int j=1; j < i; j++){
            C[i][j].first = (C[i-1][j-1].first + C[i-1][j].first)%A;
            C[i][j].second = (C[i-1][j-1].second + C[i-1][j].second)%B;
        }
    }
    for (auto it = kek.begin(); it != kek.end(); it++){
        pair<int, int> p = *it;
        for (int i=1; i <= p.second; i++){
            int sum = i*p.first;
            if (C[p.second][i] == dp[i][sum]) ans = max(ans, i);
            if (C[p.second][i] == dp[i][sum] && kek.size() == 2 && i == p.second) ans=n;
        }
    }
    cout << ans;



}