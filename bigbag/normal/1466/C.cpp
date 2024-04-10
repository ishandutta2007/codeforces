/**
 *  created: 30/12/2020, 16:42:45
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;
const int max_c = 26;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, dp[2][max_c][max_c];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        string s = read();
        int q1 = 0, q2 = 1;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < max_c; ++i) {
            dp[q1][i][i] = inf;
        }
        //cout << s << endl;
        for (char c : s) {
            for (int pr = 0; pr < max_c; ++pr) {
                int id1 = min_element(dp[q1][pr], dp[q1][pr] + max_c) - dp[q1][pr], id2 = -1;
                for (int pr2 = 0; pr2 < max_c; ++pr2) {
                    if (pr2 != id1 && pr2 != pr && (id2 == -1 || dp[q1][pr][pr2] < dp[q1][pr][id2])) {
                        id2 = pr2;
                    }
                }
                for (int nxt = 0; nxt < max_c; ++nxt) {
                    if (pr == nxt) {
                        dp[q2][pr][nxt] = inf;
                        continue;
                    }
                    if (nxt == id1) {
                        dp[q2][nxt][pr] = dp[q1][pr][id2] + (nxt != (c - 'a'));
                    } else {
                        dp[q2][nxt][pr] = dp[q1][pr][id1] + (nxt != (c - 'a'));
                    }
                }
            }
            swap(q1, q2);
        }
        int ans = inf;
        for (int i = 0; i < max_c; ++i) {
            for (int j = 0; j < max_c; ++j) {
                ans = min(ans, dp[q1][i][j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}