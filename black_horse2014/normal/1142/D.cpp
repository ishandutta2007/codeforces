#include <bits/stdc++.h>
using namespace std;

int dp[2][11];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.length();
    int now = 0;
    for (int i = 0; i < 11; i++) dp[now][i] = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        now ^= 1;
        for (int j = 0; j < 11; j++) dp[now][j] = 0;
        int x = s[i] - '0';
        for (int j = x + 1; j < 11; j++) dp[now][(j * (j - 1) / 2 + 10 + x) % 11] += dp[!now][j];
        if (x) dp[now][x]++;
        for (int j = 0; j < 11; j++) ans += dp[now][j];
    }
    cout << ans << endl;
	return 0;
}