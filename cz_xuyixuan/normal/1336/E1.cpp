#include<bits/stdc++.h>
using namespace std;
const int MAXN = 36;
const int MAXS = 1 << 13;
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
int n, m, k; ll dp[2][MAXN][MAXS];
ll bit[MAXN], ans[MAXN], a[MAXN];
void work(int pos, ll cur) {
	if (pos == m) {
		int cnt = 0;
		while (cur != 0) {
			cnt += cur & 1;
			cur >>= 1;
		}
		ans[cnt]++;
		return;
	}
	work(pos + 1, cur);
	if (a[pos] != 0) work(pos + 1, cur ^ a[pos]);
}
int main() {
	read(n), read(m);
	for (int i = 0; i <= m - 1; i++)
		bit[i] = 1ll << i;
	int mul = 1;
	for (int i = 1; i <= n; i++) {
		ll x; read(x);
		for (int j = 0; j <= m - 1; j++)
			if (x & bit[j]) {
				if (a[j]) x ^= a[j];
				else {
					a[j] = x;
					break;
				}
			}
		if (x == 0) mul = 2ll * mul % P;
		else k++;
	}
	if (k <= 22) work(0, 0);
	else {
		for (int i = 0; i <= m - 1; i++)
			if (a[i]) {
				for (int j = 0; j <= m - 1; j++)
					if (j != i && (a[j] & bit[i])) a[j] ^= a[i];
			}
		dp[0][0][0] = 1;
		for (int i = 0, from = 0, to = 1; i <= m - 1; i++, swap(from, to)) {
			if (a[i]) {
				memset(dp[to], 0, sizeof(dp[to]));
				int now = 0, cur = 1;
				for (int j = 0; j <= m - 1; j++)
					if (a[j] == 0) {
						if (a[i] & bit[j]) now |= cur;
						cur <<= 1;
					}
				for (int j = 0; j <= m - 1; j++)
				for (int s = 0; s < MAXS; s++) {
					dp[to][j][s] += dp[from][j][s];
					dp[to][j + 1][s ^ now] += dp[from][j][s];
				}
			} else memcpy(dp[to], dp[from], sizeof(dp[to]));
		}
		for (int s = 0; s < MAXS; s++) {
			int cnt = 0, tmp = s;
			while (tmp != 0) {
				cnt += tmp & 1;
				tmp >>= 1;
			}
			for (int i = 0; i <= m; i++)
				ans[i + cnt] += dp[m & 1][i][s];
		}
	}
	for (int i = 0; i <= m; i++)
		printf("%lld ", ans[i] % P * mul % P);
	printf("\n");
	return 0;
}