#include<bits/stdc++.h>
using namespace std;
#define MAXN	1005
#define INF	1e9
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int value[5], now[5][5];
int tot, cost[MAXN], res[MAXN][5];
int dp[MAXN][5][5][5][5];
char s[MAXN][5], st[MAXN];
void chkmin(int &x, int y) {
	x = min(x, y);
}
void chkmax(int &x, int y) {
	x = max(x, y);
}
void work(int pos, int sum) {
	if (pos == 0) {
		cost[++tot] = sum;
		memcpy(res[tot], now[0], sizeof(now[0]));
		return;
	}
	memcpy(now[pos - 1], now[pos], sizeof(now[pos]));
	work(pos - 1, sum);
	for (int i = 1; i <= pos; i++) {
		memcpy(now[pos - 1], now[pos], sizeof(now[pos]));
		for (int j = 1; j <= i; j++)
			chkmax(now[pos - 1][pos - j + 1], i);
		work(pos - 1, sum + value[i]);
	}
}
int main() {
	int n; read(n);
	for (int i = 1; i <= 4; i++)
		read(value[i]);
	for (int i = 1; i <= 4; i++) {
		scanf("%s", st + 1);
		for (int j = 1; j <= n; j++)
			s[j][i] = st[j];
	}
	memset(dp, 127, sizeof(dp));
	work(4, 0); dp[1][0][0][0][0] = 0;
	for (int i = 1; i <= n; i++)
	for (int a = 0; a <= 3; a++)
	for (int b = 0; b <= 3; b++)
	for (int c = 0; c <= 3; c++)
	for (int d = 0; d <= 3; d++) {
		int ta, tb, tc, td, now = dp[i][a][b][c][d];
		for (int j = 1; j <= tot; j++) {
			ta = max(a, res[j][1]);
			tb = max(b, res[j][2]);
			tc = max(c, res[j][3]);
			td = max(d, res[j][4]);
			if (ta == 0 && s[i][1] == '*') continue;
			if (tb == 0 && s[i][2] == '*') continue;
			if (tc == 0 && s[i][3] == '*') continue;
			if (td == 0 && s[i][4] == '*') continue;
			if (ta) ta--; if (tb) tb--;
			if (tc) tc--; if (td) td--;
			chkmin(dp[i + 1][ta][tb][tc][td], now + cost[j]);
		}
	}
	int ans = INF;
	for (int a = 0; a <= 3; a++)
	for (int b = 0; b <= 3; b++)
	for (int c = 0; c <= 3; c++)
	for (int d = 0; d <= 3; d++)
		chkmin(ans, dp[n + 1][a][b][c][d]);
	cout << ans << endl;
	return 0;
}