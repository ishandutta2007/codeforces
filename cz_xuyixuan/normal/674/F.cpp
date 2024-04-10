#include<bits/stdc++.h>
using namespace std;
const int MAXN = 205;
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
int n, p, q; unsigned dp[MAXN];
unsigned trans[MAXN][MAXN];
unsigned coef[MAXN][MAXN][MAXN];
int main() {
	read(n), read(p), read(q);
	chkmin(p, n - 1);
	for (int i = 0; i <= p; i++) {
		static unsigned value[MAXN]; trans[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			value[j] = n - p + i - j + 1;
			unsigned tmp = j;
			for (int k = 1; k <= j && tmp != 1; k++) {
				unsigned g = __gcd(tmp, value[k]);
				value[k] /= g, tmp /= g;
			}
			unsigned res = 1;
			for (int k = 1; k <= j; k++)
				res *= value[k];
			trans[i][j] = res;
		}
	}
	int block = 100;
	for (int i = 0; i <= p; i++)
		coef[0][i][i] = 1;
	for (int i = 1; i <= block; i++)
	for (int j = 0; j <= p; j++) {
		for (int k = 0; k <= j; k++)
		for (int t = 0; t <= p; t++)
			coef[i][j][t] += trans[j][k] * coef[i - 1][j - k][t];
	}
	for (int i = 0; i <= p; i++)
		dp[i] = 1;
	unsigned ans = 0, day = 0;
	while (day + block <= q) {
		for (int i = 1; i <= block; i++) {
			unsigned res = 0;
			for (int j = 0; j <= p; j++)
				res += coef[i][p][j] * dp[j];
			ans ^= ++day * res;
		}
		static unsigned tmp[MAXN];
		for (int i = 0; i <= p; i++) {
			unsigned res = 0;
			for (int j = 0; j <= p; j++)
				res += coef[block][i][j] * dp[j];
			tmp[i] = res;
		}
		memcpy(dp, tmp, sizeof(tmp));
	}
	while (day < q) {
		for (int i = p; i >= 1; i--)
		for (int j = 1; j <= i; j++)
			dp[i] += dp[i - j] * trans[i][j];
		ans ^= dp[p] * ++day;
	}
	cout << ans << endl;
	return 0;
}