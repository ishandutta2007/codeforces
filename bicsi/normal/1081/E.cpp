#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long

using namespace std;

int Sqrt(int x) {
    int ans = sqrt(x) - 1;
    while (ans * ans <= x) ++ans;
    return ans - 1;
}
int IsSquare(int x) { 
    int ans = Sqrt(x);
    return ans * ans == x;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> x(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        cin >> x[i];
    }

    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        if (i % 2) {
            int at = dp[i - 1];
            while (!IsSquare(at * at + x[i / 2])) {
                if (2 * at + 1 > x[i / 2]) {
                    cout << "No\n";
                    return 0;
                }
                ++at;
            }
            dp[i - 1] = at; 
            dp[i] = Sqrt(at * at + x[i / 2]);
        } else {
            dp[i] = dp[i - 1] + 1;
        }
    }
    
    cout << "Yes\n";
    cout << dp[0] * dp[0] << " ";
    for (int i = 1; i < n; ++i) {
        cout << dp[i] * dp[i] - dp[i - 1] * dp[i - 1] << " ";
    }
    cout << endl;

    return 0;
}