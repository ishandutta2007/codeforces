#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, p, k; cin >> n >> p >> k;
    int arr[n+1];
    pair<int, int> tarr[n+1];
    int s[n+1][p];
    for(int i = 1; i<=n;i++){
        cin >> tarr[i].first;
        tarr[i].second = i;
    }
    sort(tarr+1, tarr+n+1);
    reverse(tarr+1, tarr+n+1);
    for(int i = 1; i<=n; i++) arr[i] = tarr[i].first;
    int mp[n+1];
    for(int i = 1; i<=n; i++) mp[tarr[i].second] = i;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<p; j++) cin >> s[mp[i]][j];
    }
    ll dp[n+1][1<<p];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<(1<<p); j++){
            ll cur = 0;
            if(__builtin_popcount(j) <= i-1) cur = dp[i-1][j]+arr[i];
            for(int m = 0; m<p; m++){
                if(j&(1<<m)) cur = max(cur, 0ll+s[i][m]+dp[i-1][j^(1<<m)]);
            }
            dp[i][j] = cur;
        }
    }
    // cout << dp[1][2] << endl;
    int mx[p];
    memset(mx, 0, sizeof mx);
    for(int i = k+p+1; i<=n; i++) for(int j = 0; j<p; j++) mx[j] = max(mx[j], s[i][j]);
    ll ans = 0;
    for(int i = k; i<=k+p; i++){
        for(int j = 0; j<(1<<p); j++){
            if(__builtin_popcount(j) != i-k) continue;
            ll cur = dp[i][j];
            for(int m = 0; m<p; m++){
                if(j&(1<<m)) continue;
                cur += mx[m];
            }
            ans = max(cur, ans);
        }
    }
    cout << ans << endl;
}