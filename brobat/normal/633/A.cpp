#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    bool dp[c + 1]; 
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    forn(i, 1, c + 1) {
        if(i >= a) dp[i] = dp[i] | dp[i - a];
        if(i >= b) dp[i] = dp[i] | dp[i - b];
    }
    if(dp[c]) cout << "Yes";
    else cout << "No";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}