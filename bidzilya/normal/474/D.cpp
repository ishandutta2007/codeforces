#include <bits/stdc++.h>
using namespace std;

const int kMaxA = 1e5;
const int kModulus = 1e9 + 7;

inline void IncModulus(int& x, int y)
{
    x += y;
    if (x >= kModulus) {
        x -= kModulus;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, k;
    cin >> t >> k;
    vector<int> dp(kMaxA + 1);
    dp[0] = 1;
    for (int i = 0; i <= kMaxA; ++i) {
        if (i + 1 <= kMaxA) {
            IncModulus(dp[i + 1], dp[i]);
        }
        if (i + k <= kMaxA) {
            IncModulus(dp[i + k], dp[i]);
        }
    }
    for (int i = 1; i <= kMaxA; ++i) {
        IncModulus(dp[i], dp[i - 1]);
    }
    for (int test = 0; test < t; ++test) {
        int a, b;
        cin >> a >> b;
        if (a == 0) {
            cout << dp[b] << endl;
        } else {
            int ans = dp[b] - dp[a - 1];
            if (ans < 0) {
                ans += kModulus;
            }
            cout << ans << endl;
        }
    }
    return 0;
}