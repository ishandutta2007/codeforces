#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 5;
const int P = 998244353;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
char s[MAXN], t[MAXN];
int dp[MAXN][MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	scanf("\n%s\n%s", s + 1, t + 1);
	int n = strlen(s + 1);
	int m = strlen(t + 1);
	for (int i = 0; i <= n; i++)
		dp[0][i] = 1;
	int ans = 0;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= n; j++) {
			int tmp = dp[i][j];
			if (j != 0 && (j > m || s[i + 1] == t[j])) update(dp[i + 1][j - 1], tmp);
			if (j + i + 1 != 0 && (j + i + 1 > m || s[i + 1] == t[j + i + 1])) update(dp[i + 1][j], tmp);
		}
	}
	for (int i = m; i <= n; i++)
		update(ans, dp[i][0]);
	cout << ans << endl;
	return 0;
}