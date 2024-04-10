#include <bits/stdc++.h>
using namespace std;
#define maxn 1000009

int t, n, dp[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> t;
    
    dp[0] = 1;
    for (int i = 1; i < maxn; ++ i) {
        if (i >= 2020) dp[i] |= dp[i - 2020];
        if (i >= 2021) dp[i] |= dp[i - 2021];
    }

    while (t --) {
        cin >> n;
        cout << (dp[n] ? "YES\n" : "NO\n");
    }
    return 0;
}