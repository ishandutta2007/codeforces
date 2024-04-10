#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n, dp[N][N], arr[N];

void solve(){
    cin >> n;
    for(int i = 0; i<n; ++i)
        cin >> arr[i], --arr[i];
    for(int i = n-1; i>=0; --i){
        dp[i][i] = 0; vector<int> pos;
        for(int j = i+1; j<n; ++j){
            dp[i][j] = dp[i+1][j];
            if(arr[j]==arr[i]) pos.push_back(j);
            for(auto x : pos)
                dp[i][j] = max(dp[i][j], dp[i+1][x-1]+dp[x][j]+1);
        }
    }
    cout << n-1-dp[0][n-1] << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}