#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 4 * 10000 + 4;
const int MOD = (int)1E9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector <int> c;
    for(int i = 1; i <= N; i++) {
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t) c.push_back(i);
    }
    int m = c.size();
    vector <int> dp(N, 1);
    for(int j = 0; j < m - 1; j++) {
        for(int i = 0; i < N; i++) {
            if(i >= c[j + 1]) {
                dp[i] = (dp[i] + dp[i - c[j + 1]]) % MOD;
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}