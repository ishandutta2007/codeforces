#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
const int M = 55;

int dp[N][M][M];
int f[2][N], g[2][N][26];

inline void chkmax(int &a, int b) {
    if (a < b) a = b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, s[2]; cin >> a >> s[0] >> s[1];
    auto kmp = [&](int f[], int g[][26], string &s) {
        int n = s.length();
        f[1] = 0;
        for (int j = 0, i = 1; i < n; i++) {
            while (j && s[i] != s[j]) j = f[j];
            if (s[i] == s[j]) j++;
            f[i + 1] = j;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                int k = i;
                while (k && s[k] != j + 'a') k = f[k];
                if (s[k] == j + 'a') k++;
                if (k == n) k = f[k];
                g[i][j] = k;
            }
        }
    };
    for (int i : {0, 1}) kmp(f[i], g[i], s[i]);
    const int inf = 1e9;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) for (int k = 0; k < M; k++) dp[i][j][k] = -inf;
    dp[0][0][0] = 0;
    for (int i = 0; i < a.length(); i++) {
        int st = (a[i] == '*' ? 0 : a[i] - 'a');
        int en = (a[i] == '*' ? 25 : a[i] - 'a');
        for (int j = 0; j < s[0].length(); j++) {
            for (int k = 0; k < s[1].length(); k++) {
                if (dp[i][j][k] != -inf) {
                    for (int l = st; l <= en; l++) {
                        int add = 0;
                        if (j == s[0].length() - 1 && l == s[0][j] - 'a') add++;
                        if (k == s[1].length() - 1 && l == s[1][k] - 'a') add--;
                        chkmax(dp[i+1][g[0][j][l]][g[1][k][l]], dp[i][j][k] + add);
                    }
                }
            }
        }
    }
    int ans = -inf;
    for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) ans = max(ans, dp[a.length()][i][j]);
    cout << ans << endl;
    return 0;
}