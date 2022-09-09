#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int MAXS = 15;
const int P = 1e9 + 9;
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
namespace ACAutomaton {
	const int MAXP = 105;
	const int MAXC = 4;
	int root, size;
	bool key[MAXP];
	int child[MAXP][MAXC];
	int depth[MAXP], fail[MAXN], last[MAXN];
	void init() {root = size = 0; }
	int index(char x) {
		if (x == 'A') return 0;
		if (x == 'C') return 1;
		if (x == 'G') return 2;
		return 3;
	}
	void insert(char *s) {
		int len = strlen(s + 1), now = root;
		for (int i = 1; i <= len; i++) {
			int tmp = index(s[i]);
			if (child[now][tmp] == 0) {
				child[now][tmp] = ++size;
				depth[size] = depth[now] + 1;
			}
			now = child[now][tmp];
		}
		key[now] = true;
	}
	void build() {
		static int q[MAXP];
		int l = 0, r = -1;
		for (int i = 0; i < MAXC; i++)
			if (child[root][i]) {
				q[++r] = child[root][i];
				fail[child[root][i]] = root;
				last[child[root][i]] = root;
			}
		while (l <= r) {
			int tmp = q[l++];
			for (int i = 0; i < MAXC; i++)
				if (child[tmp][i]) {
					q[++r] = child[tmp][i];
					fail[child[tmp][i]] = child[fail[tmp]][i];
				} else child[tmp][i] = child[fail[tmp]][i];
			last[tmp] = key[fail[tmp]] ? fail[tmp] : last[fail[tmp]];
		}
	}
	void update(int &x, int y) {x = (x + y) % P; }
	void dp(int n) {
		static int dp[MAXN][MAXP][MAXS];
		dp[0][root][0] = 1;
		for (int i = 0; i < n; i++)
		for (int j = 0; j <= size; j++)
		for (int k = 0; k < MAXS; k++) {
			int tmp = dp[i][j][k];
			if (tmp == 0) continue;
			for (int c = 0; c < MAXC; c++) {
				int dest = child[j][c];
				if (depth[dest] < k + 1) continue;
				int tk = k + 1;
				if (key[dest]) tk = 0;
				else if (depth[last[dest]] >= tk) tk = 0;
				update(dp[i + 1][dest][tk], tmp);
			}
		}
		int ans = 0;
		for (int i = 0; i <= size; i++)
			update(ans, dp[n][i][0]);
		writeln(ans);
	}
};
int n, m;
char s[MAXS];
int main() {
	read(n), read(m);
	ACAutomaton::init();
	for (int i = 1; i <= m; i++) {
		scanf("\n%s", s + 1);
		ACAutomaton::insert(s);
	}
	ACAutomaton::build();
	ACAutomaton::dp(n);
	return 0;
}