#include <bits/stdc++.h>

using namespace std;

const int max_n = 205, inf = 1000111222;

int dp[max_n][max_n][max_n];
char pc[max_n][max_n][max_n];
int pi[max_n][max_n][max_n];
int pj[max_n][max_n][max_n];
int pbal[max_n][max_n][max_n];
string s, t;

void proc(int i, int j, int bal) {
    if (dp[i][j][bal] == inf) {
        return;
    }
    for (char c = '('; c <= ')'; ++c) {
        int s1 = i < s.length() && s[i] == c;
        int s2 = j < t.length() && t[j] == c;
        int nbal = bal;
        if (c == '(') {
            ++nbal;
        } else {
            --nbal;
        }
        if (nbal < 0) {
            continue;
        }
        if (dp[i + s1][j + s2][nbal] > dp[i][j][bal] + 1) {
            dp[i + s1][j + s2][nbal] = dp[i][j][bal] + 1;
            pc[i + s1][j + s2][nbal] = c;
            pi[i + s1][j + s2][nbal] = i;
            pj[i + s1][j + s2][nbal] = j;
            pbal[i + s1][j + s2][nbal] = bal;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> t;
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            for (int k = 0; k < max_n; ++k) {
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i <= s.length(); ++i) {
        for (int j = 0; j <= t.length(); ++j) {
            for (int bal = 0; bal + 1 < max_n; ++bal) {
                proc(i, j, bal);
            }
            for (int bal = max_n - 2; bal >= 0; --bal) {
                proc(i, j, bal);
            }
        }
    }
    int i = s.length();
    int j = t.length();
    int bal = 0;
    //cout << dp[i][j][bal] << endl;
    string ans;
    while (i || j || bal) {
        ans += pc[i][j][bal];
        int ni = pi[i][j][bal];
        int nj = pj[i][j][bal];
        int nbal = pbal[i][j][bal];
        i = ni;
        j = nj;
        bal = nbal;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}