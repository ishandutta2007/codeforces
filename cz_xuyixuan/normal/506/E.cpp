#include<bits/stdc++.h>
using namespace std;
const int MAXN = 205;
const int P = 1e4 + 7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
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
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
namespace LinearSequence {
	const int MAXN = 1205;
	int cnt, delta[MAXN], fail[MAXN];
	int k, h[MAXN], r[MAXN];
	vector <int> a[MAXN];
	int power(int x, int y) {
		if (y == 0) return 1;
		int tmp = power(x, y / 2);
		if (y % 2 == 0) return tmp * tmp % P;
		else return tmp * tmp % P * x % P;
	}
	void times(int *a, int *b, int *res) {
		static int tmp[MAXN];
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i <= k - 1; i++)
		for (int j = 0; j <= k - 1; j++)
			update(tmp[i + j], a[i] * b[j] % P);
		for (int i = 2 * k - 1; i >= k; i--) {
			int val = tmp[i];
			for (int j = 1; j <= k; j++)
				update(tmp[i - j], val * r[j] % P);
		}
		for (int i = 0; i <= k - 1; i++)
			res[i] = tmp[i];
	}
	int getans(int n) {
		if (n <= k) return h[n];
		static int tmp[MAXN], res[MAXN];
		memset(tmp, 0, sizeof(tmp));
		memset(res, 0, sizeof(res));
		n -= k, res[0] = 1, tmp[1] = 1;
		for (int bit = 1; n != 0; bit <<= 1) {
			if (bit & n) {
				n ^= bit;
				times(res, tmp, res);
			}
			times(tmp, tmp, tmp);
		}
		int ans = 0;
		for (int i = 0; i <= k - 1; i++)
			update(ans, res[i] * h[i + k] % P);
		return ans;
	}
	void work(int given, int *val, int n) {
		a[cnt = 0].clear();
		for (int i = 1; i <= given; i++) {
			delta[i] = val[i];
			for (unsigned j = 0; j < a[cnt].size(); j++)
				update(delta[i], P - a[cnt][j] * val[i - j - 1] % P);
			if (delta[i] == 0) continue;
			fail[cnt] = i;
			if (cnt == 0) {
				a[++cnt].clear();
				a[cnt].resize(i);
				continue;
			}
			int mul = delta[i] * power(delta[fail[cnt - 1]], P - 2) % P;
			a[cnt + 1].clear(), a[cnt + 1].resize(i - fail[cnt - 1] - 1);
			a[cnt + 1].push_back(mul);
			for (unsigned i = 0; i < a[cnt - 1].size(); i++)
				a[cnt + 1].push_back((P - a[cnt - 1][i]) * mul % P);
			a[cnt + 1].resize(max(a[cnt + 1].size(), a[cnt].size()));
			for (unsigned i = 0; i < a[cnt].size(); i++)
				update(a[cnt + 1][i], a[cnt][i]);
			cnt++;
		}
		k = a[cnt].size();
		for (int i = 1; i <= 2 * k; i++)
			h[i] = val[i];
		for (int i = 1; i <= k; i++)
			r[i] = a[cnt][i - 1];
		writeln(getans(n));
	}
}
char s[MAXN];
int len, n, ans[MAXN * 8], done[MAXN * 4];
int dp[MAXN * 4][MAXN][MAXN];
int main() {
	scanf("%s", s + 1);
	len = strlen(s + 1), read(n);
	dp[0][1][len] = 1;
	for (int k = 1; k <= len * 4 + 5; k++) {
		done[k] = done[k - 1] * 26 % P;
		for (int i = 1; i <= len; i++)
		for (int j = i; j <= len; j++) {
			if (s[i] == s[j]) {
				if (i + 1 <= j - 1) update(dp[k][i + 1][j - 1], dp[k - 1][i][j]);
				else update(done[k], dp[k - 1][i][j]);
				update(dp[k][i][j], dp[k - 1][i][j] * 25 % P);
			} else {
				if (i == j) update(done[k], dp[k - 1][i][j] * 2 % P);
				else {
					update(dp[k][i + 1][j], dp[k - 1][i][j]);
					update(dp[k][i][j - 1], dp[k - 1][i][j]);
				}
				update(dp[k][i][j], dp[k - 1][i][j] * 24 % P);
			}
		}
	}
	for (int i = 1; i <= len * 8 + 5; i++) {
		if (i & 1) {
			ans[i] = done[i / 2] * 26 % P;
			for (int j = 1; j <= len; j++)
				update(ans[i], dp[i / 2][j][j]);
		} else ans[i] = done[i / 2];
	}
	LinearSequence :: work(len * 7 + 5, ans + len, n);
	return 0;
}