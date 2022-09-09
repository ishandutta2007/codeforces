#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
const int MAXP = 3e4 + 5;
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
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
namespace ACAutomaton {
	const int MAXP = 3e4 + 5;
	const int MAXC = 10;
	int root, size;
	bool key[MAXP];
	int child[MAXP][MAXC];
	int depth[MAXP], fail[MAXP], last[MAXP];
	void init() {root = size = 0; }
	int index(char x) {
		return x - '0';
	}
	void insert(char *s, int len) {
		int now = root;
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
	bool run(char *s, int n) {
		int pos = root;
		for (int i = 1; i <= n; i++) {
			pos = child[pos][index(s[i])];
			if (key[pos]) return true;
		}
		return false;
	}
	int dp[MAXN][2][MAXP];
	int work(char *s, int n) {
		memset(dp, 0, sizeof(dp)), dp[0][1][root] = 1;
		for (int i = 1; i <= n; i++)
		for (int j = 0; j <= size; j++) {
			int tmp = dp[i - 1][0][j];
			if (tmp) {
				for (int k = 0; k <= 9; k++) {
					int nxt = key[j] ? j : child[j][k];
					update(dp[i][0][nxt], tmp);
				}
			}
			tmp = dp[i - 1][1][j];
			if (tmp) {
				int tnp = index(s[i]);
				for (int k = 0; k <= tnp; k++) {
					int nxt = key[j] ? j : child[j][k];
					update(dp[i][k == tnp][nxt], tmp);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= size; i++)
			if (key[i]) {
				update(ans, dp[n][0][i]);
				update(ans, dp[n][1][i]);
			}
		return ans;
	}
}
char s[MAXN], x[MAXN], y[MAXN];
int main() {
	scanf("\n%s", s + 1);
	scanf("\n%s", x + 1);
	scanf("\n%s", y + 1);
	int n = strlen(s + 1), m = strlen(x + 1);
	for (int i = 0; i + m / 2 <= n; i++)
		ACAutomaton :: insert(s + i, m / 2);
	ACAutomaton :: build();
	int ans = ACAutomaton :: work(y, m);
	update(ans, P - ACAutomaton :: work(x, m));
	update(ans, ACAutomaton :: run(x, m));
	cout << ans << endl;
	return 0;
}