#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        auto F = [&](int a, int b, int x, int y) -> int {
            // alice takes s[a], bob takes s[b], remaining is s[x...y].
            if(dp[x][y] == 0) return 0;
            if(dp[x][y] == 2) return 2;
            if(s[a] < s[b]) return 0; // alice wins.
            if(s[a] > s[b]) return 2; // bob wins.
            return dp[x][y]; // draw.
        };

        for(int k = 2; k <= n; k += 2) {
            for(int i = 0; i <= n - k; i++) {
                int j = i + k - 1;
                // calculate dp[i][j]. 0 --> Alice, 1 --> Draw, 2--> Bob.
                if(k == 2) {
                    if(s[i] == s[j]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                    continue;
                }
                vector <int> ans(4, -1);
                ans[0] = F(i, i + 1, i + 2, j);
                ans[1] = F(i, j, i + 1, j - 1);
                ans[2] = F(j, j - 1, i, j - 2);
                ans[3] = F(j, i, i + 1, j - 1);
                int a = max(ans[0], ans[1]);
                int b = max(ans[2], ans[3]);
                int c = min(a, b);
                dp[i][j] = c;
            }
        }

        if(dp[0][n - 1] == 0) cout << "Alice";
        else if(dp[0][n - 1] == 1) cout << "Draw";
        else if(dp[0][n - 1] == 2) cout << "Bob";
        else assert(false);
        cout << '\n';
    }
    
    return 0;
}