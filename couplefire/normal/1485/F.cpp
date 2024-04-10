#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

void solve(){
    int n; cin >> n; vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    map<long long, int> dp;
    long long shift = 0; dp[0] = 1; int tot = 1;
    for(int i = 0; i<n; i++){
        shift += arr[i]; int t = dp[arr[i]-shift];
        dp[arr[i]-shift] = tot; tot = (2ll*tot-t)%MOD;
    }
    cout << (tot%MOD+MOD)%MOD << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}