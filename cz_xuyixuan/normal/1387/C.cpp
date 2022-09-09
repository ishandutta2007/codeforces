#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXM = 55;
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
namespace ACAutomaton {
	const int MAXN = 55;
	bool key[MAXN]; int fail[MAXN];
	int size, root, child[MAXN][2];
	void insert(int len, int *s) {
		int now = root;
		for (int i = 1; i <= len; i++) {
			if (!child[now][s[i]]) child[now][s[i]] = ++size;
			now = child[now][s[i]];
		}
		key[now] = true;
	}
	void build() {
		static int q[MAXN];
		int l = 0, r = 0;
		while (l <= r) {
			int pos = q[l++];
			for (int i = 0; i <= 1; i++)
				if (child[pos][i]) q[++r] = child[pos][i];
		}
		for (int i = 1; i <= r; i++) {
			int pos = q[i];
			key[pos] |= key[fail[pos]];
			for (int j = 0; j <= 1; j++)
				if (child[pos][j]) fail[child[pos][j]] = child[fail[pos]][j];
				else child[pos][j] = child[fail[pos]][j];
		}
	}
}
int n, m, s, t[MAXN];
vector <int> a[MAXN];
ull dp[MAXN][MAXM][MAXM];
void init() {
	using namespace ACAutomaton; s = size;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= s; j++)
		for (int k = 0; k <= s; k++)
			dp[i][j][k] = -1;
	}
	for (int i = 0; i <= 1; i++)
	for (int j = 0; j <= s; j++)
		if (!key[child[j][i]] && !key[j]) dp[i][j][child[j][i]] = 1;
}
int main() {
	read(n), read(m), read(s);
	for (int i = 1; i <= m; i++) {
		int cnt; read(t[i]), read(cnt);
		for (int j = 1; j <= cnt; j++) {
			int x; read(x);
			a[i].push_back(x);
		}
	}
	for (int i = 1; i <= s; i++) {
		static int t[MAXN];
		int len; read(len);
		for (int j = 1; j <= len; j++)
			read(t[j]);
		ACAutomaton :: insert(len, t);
	}
	ACAutomaton :: build(), init();
	bool changed = true;
	while (changed) {
		changed = false;
		for (int p = 1; p <= m; p++) {
			static ull cur[MAXM][MAXM];
			for (int i = 0; i <= s; i++)
			for (int j = 0; j <= s; j++)
				cur[i][j] = (i == j) ? 0 : -1;
			for (auto x : a[p]) {
				static ull tmp[MAXM][MAXM];
				for (int i = 0; i <= s; i++)
				for (int j = 0; j <= s; j++)
					tmp[i][j] = -1;
				for (int i = 0; i <= s; i++)
				for (int j = 0; j <= s; j++)
					if (cur[i][j] != -1) {
						for (int k = 0; k <= s; k++)
							if (dp[x][j][k] != -1)
								chkmin(tmp[i][k], cur[i][j] + dp[x][j][k]);
					}
				memcpy(cur, tmp, sizeof(tmp));
			}
			for (int i = 0; i <= s; i++)
			for (int j = 0; j <= s; j++)
				if (cur[i][j] < dp[t[p]][i][j]) {
					changed = true;
					dp[t[p]][i][j] = cur[i][j];
				}
		}
	}
	for (int i = 2; i <= n - 1; i++) {
		ull ans = -1;
		for (int j = 0; j <= s; j++)
			chkmin(ans, dp[i][0][j]);
		if (ans == -1) puts("YES");
		else printf("NO %llu\n", ans);
	}
	return 0;
}