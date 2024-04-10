#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20005;
const int MAXM = 2005;
const int MAXL = 805;
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
struct ACAutomaton {
	struct Node {
		int child[10];
		int fail, sum[MAXL];
	} a[MAXN];
	int lenl, lenr, root, size, dp[MAXM][MAXN];
	char l[MAXN], r[MAXN];
	void buildfail() {
		int l = 0, r = -1;
		static int q[MAXN];
		a[root].fail = root;
		for (int i = 0; i <= 9; i++)
			if (a[root].child[i]) {
				a[a[root].child[i]].fail = root;
				q[++r] = a[root].child[i];
			} else a[root].child[i] = root;
		while (l <= r) {
			int pos = q[l++];
			for (int i = 0; i <= lenr; i++)
				a[pos].sum[i] += a[a[pos].fail].sum[i];
			for (int i = 0; i <= 9; i++)
				if (a[pos].child[i]) {
					a[a[pos].child[i]].fail = a[a[pos].fail].child[i];
					q[++r] = a[pos].child[i];
				} else a[pos].child[i] = a[a[pos].fail].child[i];
		}
		for (int i = 0; i <= size; i++)
		for (int j = 1; j <= lenr; j++)
			a[i].sum[j] += a[i].sum[j - 1];
	}
	void init() {
		scanf("%s", l + 1);
		scanf("%s", r + 1);
		lenl = strlen(l + 1);
		lenr = strlen(r + 1);
		root = size = 0;
		if (lenl == lenr) {
			bool flg = false;
			for (int i = 1, posl = root, posr = root; i <= lenl; posl = a[posl].child[l[i] - '0'], posr = a[posr].child[r[i] - '0'], i++) {
				if (flg) {
					for (int j = l[i] - '0'; j <= 9; j++) {
						if (a[posl].child[j] == 0) a[posl].child[j] = ++size;
						if (i == lenl || j != l[i] - '0') a[a[posl].child[j]].sum[lenl - i] = 1;
					}
					for (int j = 0; j <= r[i] - '0'; j++) {
						if (a[posr].child[j] == 0) a[posr].child[j] = ++size;
						if (i == lenl || j != r[i] - '0') a[a[posr].child[j]].sum[lenl - i] = 1;
					}
				} else {
					for (int j = l[i] - '0'; j <= r[i] - '0'; j++) {
						if (a[posl].child[j] == 0) a[posl].child[j] = ++size;
						if (i == lenl || j != l[i] - '0' && j != r[i] - '0') a[a[posl].child[j]].sum[lenl - i] = 1;
					}
				}
				flg |= l[i] != r[i];
			}
		} else {
			for (int i = 1, pos = root; i <= lenl; pos = a[pos].child[l[i] - '0'], i++) {
				for (int j = l[i] - '0'; j <= 9; j++) {
					if (a[pos].child[j] == 0) a[pos].child[j] = ++size;
					if (i == lenl || j != l[i] - '0') a[a[pos].child[j]].sum[lenl - i] = 1;
				}
			}
			for (int i = 1, pos = root; i <= lenr; pos = a[pos].child[r[i] - '0'], i++) {
				for (int j = 0 + (i == 1); j <= r[i] - '0'; j++) {
					if (a[pos].child[j] == 0) a[pos].child[j] = ++size;
					if (i == lenr || j != r[i] - '0') a[a[pos].child[j]].sum[lenr - i] = 1;
				}
			}
			for (int i = lenl + 1; i <= lenr - 1; i++) {
				for (int j = 1; j <= 9; j++) {
					if (a[root].child[j] == 0) a[root].child[j] = ++size;
					a[a[root].child[j]].sum[i - 1] = 1;
				}
			}
		}
		buildfail();
	}
	void query(int n) {
		memset(dp, -1, sizeof(dp)), dp[0][0] = 0;
		for (int i = 0; i <= n - 1; i++)
		for (int j = 0; j <= size; j++) {
			if (dp[i][j] == -1) continue;
			int tmp = dp[i][j];
			for (int k = 0; k <= 9; k++) {
				int dest = a[j].child[k];
				chkmax(dp[i + 1][dest], tmp + a[dest].sum[min(n - i - 1, lenr)]);
			}
		}
		int ans = 0;
		for (int i = 0; i <= size; i++)
			chkmax(ans, dp[n][i]);
		printf("%d\n", ans);
		bool opt[MAXM][MAXN];
		for (int i = 0; i <= size; i++)
			if (dp[n][i] == ans) opt[n][i] = true;
		for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j <= size; j++) {
			if (dp[i][j] == -1) continue;
			int tmp = dp[i][j];
			for (int k = 0; k <= 9; k++) {
				int dest = a[j].child[k];
				if (opt[i + 1][dest] && dp[i + 1][dest] == tmp + a[dest].sum[min(n - i - 1, lenr)]) opt[i][j] = true; 
			}
		}
		assert(opt[0][0]);
		int pos = 0;
		for (int i = 1; i <= n; i++) {
			int tmp = dp[i - 1][pos];
			for (int j = 0; j <= 9; j++) {
				int dest = a[pos].child[j];
				if (opt[i][dest] && dp[i][dest] == tmp + a[dest].sum[min(n - i, lenr)]) {
					printf("%d", j);
					pos = a[pos].child[j];
					break;
				}
			}
		}
		printf("\n");
	}
} ACAM;
int main() {
	ACAM.init();
	int n; read(n);
	ACAM.query(n);
	return 0;
}