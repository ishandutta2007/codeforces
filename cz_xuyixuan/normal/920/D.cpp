#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int INF = 1e9;
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, k, v, sum, a[MAXN];
int dp[MAXN][MAXN];
bool flg[MAXN];
int main() {
	read(n), read(k), read(v);
	for (int i = 1; i <= n; i++)
		read(a[i]), sum += a[i];
	if (sum < v) {
		printf("NO\n");
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= k - 1; j++) {
		dp[i][j] = dp[i - 1][j];
		int x = (j - a[i] % k + k) % k;
		if (dp[i - 1][x] != -1) dp[i][j] = i;
	}
	if (dp[n][v % k] == -1) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int pos = v % k;
	for (int i = n; i >= 1; i--)
		if (i == dp[i][pos]) {
			flg[i] = true;
			pos = (pos - a[i] % k + k) % k;
		}
	bool all = true, none = true;
	for (int i = 1; i <= n; i++)
		all &= flg[i], none &= !flg[i];
	if (all) {
		for (int i = 2; i <= n; i++)
			printf("%d %d %d\n", INF, i, 1);
		if (sum != v) printf("%d %d %d\n", (sum - v) / k, 1, 2);
	} else if (none) {
		for (int i = 2; i <= n; i++)
			printf("%d %d %d\n", INF, i, 1);
		if (v != 0) printf("%d %d %d\n", v / k, 1, 2);
	} else {
		int s = 0, t = 0, sum = 0, tum = 0;
		for (int i = 1; i <= n; i++)
			if (flg[i]) s = i, sum += a[i];
			else t = i, tum += a[i];
		for (int i = 1; i <= n; i++) {
			if (flg[i] && i != s) printf("%d %d %d\n", INF, i, s);
			if (!flg[i] && i != t) printf("%d %d %d\n", INF, i, t);
		}
		if (sum != v) {
			if (sum > v) printf("%d %d %d\n", (sum - v) / k, s, t);
			else printf("%d %d %d\n", (v - sum) / k, t, s);
		}
	}
	return 0;
}