#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m, k; cin >> n >> m >> k;
    long long temp[n+1];
    for(long long i = 1; i<=n; i++) cin >> temp[i];
    long long arr[k+1];
    sort(temp+1, temp+n+1);
    for(long long i = 1; i<=k; i++) arr[i] = temp[i];
    long long offers[k+1];
    fill(offers, offers+k+1, 0);
    vector<pair<long long, long long>> bigOffers;
    for(long long i = 0; i<m; i++){
        long long a, b; cin >> a >> b;
        if(a <= k) offers[a] = max(offers[a], b);
    }
    long long prefix[n+1];
    prefix[0] = 0;
    for(long long i = 1; i<=n; i++){
        prefix[i] = prefix[i-1]+temp[i];
    }
    long long dp[k+1];
    for(long long i = 0; i<=k; i++){
        dp[i] = prefix[i];
    }
    for(long long i = 1; i<=k; i++){
        for(long long j = 1; j<=i; j++){
            dp[i] = min(dp[i], dp[i-j]+prefix[i]-prefix[i-j+offers[j]]);
        }
    }
    cout << dp[k] << endl;
}