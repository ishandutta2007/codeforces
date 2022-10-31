#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

char s[N];
vector<int> dp[26][N];
int vis[33];
int main() {
	int len; scanf("%s", s + 1), len = strlen(s + 1);
	for (int i = len + 1; i <= 2 * len; i++) s[i] = s[i - len];
	for (int i = 1; i <= len; i++) {
		for (int j = i + 1; j <= i + len - 1; j++) dp[s[i] - 'a'][j - i].push_back(s[j] - 'a');
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		
		int ma = 0;
		for (int j = 1; j < len; j++) {
			memset(vis, 0, sizeof vis);
			int cur = 0;
			for (int k = 0; k < dp[i][j].size(); k++) vis[dp[i][j][k]]++;
			for (int k = 0; k < 26; k++) if (vis[k] == 1) cur++;
			ma = max(ma, cur);
		}
		ans += ma;
	}
	printf("%.10lf\n", 1.0 * ans / len);
	return 0;
}