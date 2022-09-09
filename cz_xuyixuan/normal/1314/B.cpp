#include<bits/stdc++.h>
using namespace std;
const int MAXN = 18;
const int MAXS = (1 << 17) + 5;
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
int n, m, nxt[MAXS];
bool f[MAXS];
void getnxt(int l, int r, int depth) {
	int mid = (l + r) / 2;
	nxt[mid] = depth;
	if (l != r) {
		getnxt(l, mid - 1, depth + 1);
		getnxt(mid + 1, r, depth + 1);
	}
}
int main() {
	read(n), read(m);
	if (m == 0) {
		puts("0");
		return 0;
	}
	int goal = 1 << n;
	for (int i = 1; i <= m; i++) {
		int x; read(x);
		f[x] = true;
	}
	if (n >= 3) getnxt(1, (1 << (n - 2)) - 1, 1);
	int ans = 1;
	for (int i = 1; i <= goal; i += 2)
		ans += f[i] || f[i + 1];
	static int dp[MAXN][MAXN], tmp[MAXN][MAXN];
	memset(dp, 0, sizeof(dp));
	for (int p = 1, q = 1; p <= goal; p += 4, q++) {
		memset(tmp, 0, sizeof(tmp));
		int cnt = f[p] + f[p + 1] + f[p + 2] + f[p + 3];
		for (int i = 0; i <= n - 1; i++)
		for (int j = 0; j <= n - 1; j++) {
			if (cnt >= 2) chkmax(tmp[nxt[q]][nxt[q]], dp[i][j] + (n - 1 - i) + 2 * (n - 1 - j));
			else if (cnt == 1) {
				chkmax(tmp[nxt[q]][min(j, nxt[q])], dp[i][j] + (n - 1 - i));
				chkmax(tmp[min(i, nxt[q])][nxt[q]], dp[i][j] + 2 * (n - 1 - j));
			} else chkmax(tmp[min(i, nxt[q])][min(j, nxt[q])], dp[i][j]);
		}
		memcpy(dp, tmp, sizeof(tmp));
	}
	cout << ans + dp[0][0] << endl;
	return 0;
}