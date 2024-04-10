#include <bits/stdc++.h>

using namespace std;

#define long int64_t

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    while (T--) {
        string s;
        cin >> s;
        int N = s.size();
        s = "#" + s;

        // a: latest 0 on even position; b: latest 0 on odd position
        // c: latest 1 on even position; d: latest 1 on odd position
        // c: latest ?
        int a[2] = {}, b[2] = {};
        vector<long> dp(N + 1);
        for (int i = 1; i <= N; i++) {
            if (s[i] == '0') {
                dp[i] = i - max(a[!(i & 1)], b[i & 1]);
                a[i & 1] = i;
            } else if (s[i] == '1') {
                dp[i] = i - max(a[(i & 1)], b[!(i & 1)]);
                b[i & 1] = i;
            } else {
                dp[i] = 1 + dp[i - 1];
            }
        }
        long ans = accumulate(begin(dp) + 1, end(dp), 0LL);
        cout << ans << endl;
    }
    return 0;
}