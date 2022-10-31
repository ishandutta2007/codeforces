#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000000000000009ll
#define MAXN 100005

int dp[MAXN];

void solve(){
    int n, k; cin >> n >> k;
    if(dp[n] < k){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i<n;){
        for(int j = 0; j<n; j++){
            if(dp[n-i-j-1] >= k){
                for(int a = j; a>=0; a--){
                    cout << i+a+1 << " ";
                }
                i += j+1;
                break;
            }
            k -= dp[n-i-j-1];
        }
    }
    cout << endl;
}

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<MAXN; i++){
        dp[i] = 2*dp[i-1];
        if(dp[i] > INF) dp[i] = INF;
    }
    int t; cin >> t;
    while(t--) solve();
}