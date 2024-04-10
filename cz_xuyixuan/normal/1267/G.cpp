#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXM = 1e4 + 5;
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
int n, x, a[MAXN];
double dp[MAXN][MAXM], binom[MAXN][MAXN];
int main() {
	read(n), read(x);
	int sum = 0; dp[0][0] = binom[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		read(a[i]), binom[i][0] = 1;
		for (int j = 1; j <= i; j++)
			binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
		for (int j = i; j >= 1; j--)
		for (int k = 0; k <= sum; k++)
			dp[j][k + a[i]] += dp[j - 1][k];
		sum += a[i];
	}
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		double cost = (n + i) / 2.0 / i * x;
		for (int j = 0; j <= sum; j++)
			ans += dp[i][j] / binom[n][i] * min(cost, 1.0 * j / i);
	}
	printf("%.10lf\n", ans);
	return 0;
}