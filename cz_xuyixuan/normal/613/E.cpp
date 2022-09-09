#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int MAXM = 1e5 + 5;
const int P = 1e9 + 7;
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
namespace SuffixArray {
	const int MAXN = 100005;
	const int MAXLOG = 20;
	const int MAXC = 256;
	int sa[MAXN], rnk[MAXN], height[MAXN];
	int Min[MAXN][MAXLOG], bit[MAXN], N;
	void init(char *a, int n) {
		N = n;
		static int x[MAXN], y[MAXN], cnt[MAXN], rk[MAXN];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
			cnt[(int) a[i]]++;
		for (int i = 1; i <= MAXC; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n; i >= 1; i--)
			sa[cnt[(int) a[i]]--] = i;
		rnk[sa[1]] = 1;
		for (int i = 2; i <= n; i++)
			rnk[sa[i]] = rnk[sa[i - 1]] + (a[sa[i]] != a[sa[i - 1]]);
		for (int k = 1; rnk[sa[n]] != n; k <<= 1) {
			for (int i = 1; i <= n; i++) {
				x[i] = rnk[i];
				y[i] = (i + k <= n) ? rnk[i + k] : 0;
			}
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[y[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; i--)
				rk[cnt[y[i]]--] = i;
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[x[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; i--)
				sa[cnt[x[rk[i]]]--] = rk[i];
			rnk[sa[1]] = 1;
			for (int i = 2; i <= n; i++)
				rnk[sa[i]] = rnk[sa[i - 1]] + (x[sa[i]] != x[sa[i - 1]] || y[sa[i]] != y[sa[i - 1]]);		
		}
		int now = 0;
		for (int i = 1; i <= n; i++) {
			if (now) now--;
			while (a[i + now] == a[sa[rnk[i] + 1] + now]) now++;
			height[rnk[i]] = now;
		}
		for (int i = 1; i <= n; i++)
			Min[i][0] = height[i];
		for (int p = 1; p < MAXLOG; p++) {
			int tmp = 1 << (p - 1);
			for (int i = 1, j = tmp + 1; j <= n; i++, j++)
				Min[i][p] = min(Min[i][p - 1], Min[i + tmp][p - 1]);
		}
		for (int i = 1; i <= n; i++) {
			bit[i] = bit[i - 1];
			if (i >= 1 << (bit[i] + 1)) bit[i]++;
		}
	}
	int lcp(int x, int y) {
		if (x == y) return N - x + 1;
		x = rnk[x], y = rnk[y];
		if (x > y) swap(x, y);
		int tmp = bit[y - x];
		return min(Min[x][tmp], Min[y - (1 << tmp)][tmp]);
	}
}
int n, m, tot, dp[MAXN][MAXN][2], f[2][MAXN], g[2][MAXN];
char s[2][MAXN], t[MAXN], all[MAXM];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int solve() {
	tot = 0;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
		all[++tot] = s[0][i], f[0][i] = tot;
	for (int i = 1; i <= n; i++)
		all[++tot] = s[1][i], f[1][i] = tot;
	for (int i = 1; i <= m; i++)
		all[++tot] = t[i], g[0][i] = tot;
	for (int i = m; i >= 1; i--)
		all[++tot] = t[i], g[1][i] = tot;
	SuffixArray :: init(all, tot);
	int ans = 0;
	for (int i = 1; i <= n + 1; i++) {
		update(dp[i][0][0], 1);
		update(dp[i][0][1], 1);
		for (int j = 2; j <= i - 1 && j * 2 <= m; j++) {
			using namespace SuffixArray;
			if (lcp(g[0][j + 1], f[0][i - j]) >= j && lcp(g[1][j], f[1][i - j]) >= j) update(dp[i][j * 2][0], 1);
			if (lcp(g[0][j + 1], f[1][i - j]) >= j && lcp(g[1][j], f[0][i - j]) >= j) update(dp[i][j * 2][1], 1);
		}
		for (int j = 0; j <= m - 1; j++) {
			if (t[j + 1] == s[0][i]) {
				update(dp[i + 1][j + 1][0], dp[i][j][0]);
				if (j <= m - 2 && t[j + 2] == s[1][i]) update(dp[i + 1][j + 2][1], dp[i][j][0]);
			}
			if (t[j + 1] == s[1][i]) {
				update(dp[i + 1][j + 1][1], dp[i][j][1]);
				if (j <= m - 2 && t[j + 2] == s[0][i]) update(dp[i + 1][j + 2][0], dp[i][j][1]);
			}
		}
		update(ans, dp[i][m][0]);
		update(ans, dp[i][m][1]);
		for (int j = 2; j <= n - i + 1 && j * 2 <= m; j++) {
			using namespace SuffixArray;
			if (lcp(g[0][m - 2 * j + 1], f[0][i]) >= j && lcp(g[1][m], f[1][i]) >= j) update(ans, dp[i][m - j * 2][0]);
			if (lcp(g[0][m - 2 * j + 1], f[1][i]) >= j && lcp(g[1][m], f[0][i]) >= j) update(ans, dp[i][m - j * 2][1]);
		}
	}
	return ans;
}
int main() {
	scanf("\n%s", s[0] + 1);
	scanf("\n%s", s[1] + 1);
	scanf("\n%s", t + 1);
	n = strlen(s[0] + 1), m = strlen(t + 1);
	int ans = solve();
	reverse(t + 1, t + m + 1);
	update(ans, solve());
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			update(ans, P - (t[1] == s[0][i]));
			update(ans, P - (t[1] == s[1][i]));
		}
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			update(ans, P - (t[1] == s[0][i] && t[2] == s[1][i]));
			update(ans, P - (t[1] == s[1][i] && t[2] == s[0][i]));
		}
	} else if (m % 2 == 0) {
		using namespace SuffixArray;
		for (int i = m / 2; i <= n; i++) {
			if (lcp(g[0][m / 2 + 1], f[0][i - m / 2 + 1]) >= m / 2 && lcp(g[1][m / 2], f[1][i - m / 2 + 1]) >= m / 2) update(ans, P - 1);
			if (lcp(g[0][m / 2 + 1], f[1][i - m / 2 + 1]) >= m / 2 && lcp(g[1][m / 2], f[0][i - m / 2 + 1]) >= m / 2) update(ans, P - 1);
		}
		for (int i = 1; i + m / 2 - 1 <= n; i++) {
			if (lcp(g[0][1], f[0][i]) >= m / 2 && lcp(g[1][m], f[1][i]) >= m / 2) update(ans, P - 1);
			if (lcp(g[0][1], f[1][i]) >= m / 2 && lcp(g[1][m], f[0][i]) >= m / 2) update(ans, P - 1);
		}
	}
	cout << ans << endl;
	return 0;
}