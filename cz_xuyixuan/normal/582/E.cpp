#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXS = 1 << 16;
const int P = 1e9 + 7;
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
char s[MAXN];
int tot, dp[MAXN][MAXS];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
void FWTOR(int *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++)
		a[j] = (a[i] + a[j]) % P;
}
void UFWTOR(int *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++)
		a[j] = (a[j] - a[i] + P) % P;
}
void FWTAND(int *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++)
		a[i] = (a[i] + a[j]) % P;
}
void UFWTAND(int *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++)
		a[i] = (a[i] - a[j] + P) % P;
}
void getor(int *f, int *g, int *h) {
	static int a[MAXS], b[MAXS], c[MAXS];
	for (int i = 0; i < MAXS; i++)
		a[i] = f[i], b[i] = g[i];
	FWTOR(a, MAXS), FWTOR(b, MAXS);
	for (int i = 0; i < MAXS; i++)
		c[i] = 1ll * a[i] * b[i] % P;
	UFWTOR(c, MAXS);
	for (int i = 0; i < MAXS; i++)
		update(h[i], c[i]);
}
void getand(int *f, int *g, int *h) {
	static int a[MAXS], b[MAXS], c[MAXS];
	for (int i = 0; i < MAXS; i++)
		a[i] = f[i], b[i] = g[i];
	FWTAND(a, MAXS), FWTAND(b, MAXS);
	for (int i = 0; i < MAXS; i++)
		c[i] = 1ll * a[i] * b[i] % P;
	UFWTAND(c, MAXS);
	for (int i = 0; i < MAXS; i++)
		update(h[i], c[i]);
}
int solve(int l, int r) {
	int res = ++tot;
	if (l == r) {
		if (s[l] == 'A' || s[l] == '?') {
			int mask = 0;
			for (int s = 0; s <= 15; s++)
				if (s & 1) mask += 1 << s;
			dp[res][mask]++;
		}
		if (s[l] == 'B' || s[l] == '?') {
			int mask = 0;
			for (int s = 0; s <= 15; s++)
				if (s & 2) mask += 1 << s;
			dp[res][mask]++;
		}
		if (s[l] == 'C' || s[l] == '?') {
			int mask = 0;
			for (int s = 0; s <= 15; s++)
				if (s & 4) mask += 1 << s;
			dp[res][mask]++;
		}
		if (s[l] == 'D' || s[l] == '?') {
			int mask = 0;
			for (int s = 0; s <= 15; s++)
				if (s & 8) mask += 1 << s;
			dp[res][mask]++;
		}
		if (s[l] == 'a' || s[l] == '?') {
			int mask = 0;
			for (int s = 0; s <= 15; s++)
				if ((s ^ 1) & 1) mask += 1 << s;
			dp[res][mask]++;
		}
		if (s[l] == 'b' || s[l] == '?') {
			int mask = 0;
			for (int s = 0; s <= 15; s++)
				if ((s ^ 2) & 2) mask += 1 << s;
			dp[res][mask]++;
		}
		if (s[l] == 'c' || s[l] == '?') {
			int mask = 0;
			for (int s = 0; s <= 15; s++)
				if ((s ^ 4) & 4) mask += 1 << s;
			dp[res][mask]++;
		}
		if (s[l] == 'd' || s[l] == '?') {
			int mask = 0;
			for (int s = 0; s <= 15; s++)
				if ((s ^ 8) & 8) mask += 1 << s;
			dp[res][mask]++;
		}
		return res;
	}
	int mid = 0, pre = 0;
	for (int i = l; i <= r; i++) {
		if (s[i] == '(') pre++;
		else if (s[i] == ')') pre--;
		else if (pre == 0) mid = i;
	}
	int x = solve(l + 1, mid - 2), y = solve(mid + 2, r - 1);
	if (s[mid] == '|' || s[mid] == '?') getor(dp[x], dp[y], dp[res]);
	if (s[mid] == '&' || s[mid] == '?') getand(dp[x], dp[y], dp[res]);
	return res;
}
int main() {
	scanf("%s", s + 1);
	int T, f = 0, g = 0; read(T);
	while (T--) {
		int a, b, c, d, x;
		read(a), read(b), read(c), read(d), read(x);
		int mask = a + b * 2 + c * 4 + d * 8;
		if (x == 0) f |= 1 << mask;
		else g |= 1 << mask;
	}
	int res = solve(1, strlen(s + 1)), ans = 0;
	for (int i = 0; i < MAXS; i++)
		if ((i & g) == g && (~i & f) == f) update(ans, dp[res][i]);
	cout << ans << endl;
	return 0;
}