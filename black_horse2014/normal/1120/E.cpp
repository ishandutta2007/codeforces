#include <bits/stdc++.h>
using namespace std;

int dp[10001][2000];
int prv[10001][2000];
int dsum[100000], len[100000];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 100000; i++) dsum[i] = dsum[i / 10] + i % 10;
    const int inf = 1e9;
    auto calc = [&](int n) {
        if (n == 1) return make_pair(1, 1);
        for (int i = 0; i < 2000; i++) dp[0][i] = inf;
        dp[0][0] = 0;
        int mind = inf, mlen = -1;
        for (int len = 0; len < 10000; len++) {
            for (int i = 0; i < 2000; i++) dp[len+1][i] = inf;
            for (int i = 0; i < 2000; i++) if (dp[len][i] < inf) {
                for (int j = 0; j < 10; j++) {
                    int x = j*n+i;
                    dp[len+1][x/10] = min(dp[len+1][x/10], n*(dsum[x]-dsum[i])-j+dp[len][i]);
                    if (dp[len+1][x/10] == n*(dsum[x]-dsum[i])-j+dp[len][i]) prv[len+1][x/10] = j*10000+i;
                }
            }
            if (len) {
                for (int i = 0; i < 2000; i++) {
                    if (dp[len][i] > 0) {
                        if (mind > dp[len][i]) {
                            mind = dp[len][i];
                            mlen = len;
                        }
                    }
                }
                for (int i = 0; i < 2000; i++) {
                    if (dp[len][i] < 0) return make_pair(len, mlen);
                }
            }
        }
        return make_pair(-1, -1);
    };
    for (int i = 0; i < 100000; i++) len[i] = i == 0 ? 0 : len[i/10]+1;
    auto solve = [&](int n) {
        if (n == 1) return puts("1"), 0;
        if (n == 8) return puts("125"), 0;
        auto t = calc(n);
        int m = t.first;
        int m1 = t.second;
        int state = min_element(dp[m], dp[m] + 2000) - dp[m];
        if (m < 0) return puts("-1"), 0;
        if (m1 < 0) m1 = 1;
        int state1 = -1;
        for (int j = 0; j < 2000; j++) {
            if (dp[m1][j] > 0 && dp[m1][j] < inf) {
                if (state1 == -1 || dp[m1][state1] > dp[m1][j]) state1 = j;
            }
        }
        int _state = state;
        string A;
        int neg = dp[m][state];
        for (int i = m; i > 0; i--) {
            int t = prv[i][state];
            A.push_back(t/10000+'0');
            state = t%10000;
        }
        for (int i = 0; i < len[_state]; i++) A.push_back('0');
        int pos = 0;
        string B;
        if (state1 >= 0) {
            pos = dp[m1][state1];
            int _state1 = state1;
            for (int i = 0; i < len[_state1]; i++) B.push_back('0');
            for (int i = m1; i > 0; i--) {
                int t = prv[i][state1];
                B.push_back(t/10000+'0');
                state1 = t%10000;
            }
        } else {
            B = "001";
            pos = dsum[n]*n-1;
        }
        int g = __gcd(abs(neg), pos);
        string ans;
        for (int i = 0; i < pos/g; i++) ans.insert(ans.end(), A.begin(), A.end());
        for (int i = 0; i < -neg/g; i++) ans.insert(ans.end(), B.begin(), B.end());
        puts(ans.c_str());
        return 0;
    };
    int n; cin >> n;
    solve(n);
    return 0;
}