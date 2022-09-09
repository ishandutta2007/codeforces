#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int MAXM = 1e6 + 5;
const long long INF = 2e18;
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
namespace SuffixArray {
	const int MAXN = 100005;
	const int MAXLOG = 20;
	const int MAXC = 256; 
	int sa[MAXN], rnk[MAXN], height[MAXN];
	int Min[MAXN][MAXLOG], bit[MAXN], N;
	void init(char *a, int n) {
		N = n, a[n + 1] = 0;
		for (int i = 0; i <= n + 1; i++)
			sa[i] = rnk[i] = 0;
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
int n, m, tot; ll k;
pair <int, int> a[MAXM];
char s[MAXN];
bool cmp(pair <int, int> a, pair <int, int> b) {
	int tmp = SuffixArray :: lcp(a.first, b.first);
	chkmin(tmp, a.second - a.first + 1);
	chkmin(tmp, b.second - b.first + 1);
	if (tmp == a.second - a.first + 1 && tmp == b.second - b.first + 1) return false;
	if (tmp == a.second - a.first + 1) return false;
	if (tmp == b.second - b.first + 1) return true;
	return s[a.first + tmp] > s[b.first + tmp];
}
int nxt[MAXN]; ll dp[MAXN][MAXN];
ll calc(pair <int, int> a) {
	for (int i = 1; i <= n; i++) {
		nxt[i] = i + 1;
		while (nxt[i] <= n + 1 && cmp(a, make_pair(i, nxt[i] - 1))) nxt[i]++;
	}
	memset(dp, 0, sizeof(dp));
	dp[0][1] = 1, dp[0][2] = -1;
	for (int i = 0; i <= m - 1; i++) {
		for (int j = 1; j <= n + 1; j++) {
			dp[i][j] += dp[i][j - 1];
			chkmin(dp[i][j], INF);
		}
		for (int j = 1; j <= n; j++) {
			dp[i + 1][nxt[j]] += dp[i][j];
			chkmin(dp[i + 1][nxt[j]], INF);
		}
	}
	for (int i = 1; i <= n + 1; i++) {
		dp[m][i] += dp[m][i - 1];
		chkmin(dp[m][i], INF);
	}
	return dp[m][n + 1];
}
int main() {
	read(n), read(m), read(k);
	scanf("%s", s + 1);
	SuffixArray :: init(s, n);
	for (int i = 1; i <= n; i++)
	for (int j = i; j <= n; j++)
		a[++tot] = make_pair(i, j);
	sort(a + 1, a + tot + 1, cmp);
	int l = 1, r = tot;
	while (l < r) {
		int mid = (l + r) / 2;
		if (calc(a[mid]) >= k) r = mid;
		else l = mid + 1;
	}
	for (int i = a[l].first; i <= a[l].second; i++)
		putchar(s[i]);
	puts("");
	return 0;
}