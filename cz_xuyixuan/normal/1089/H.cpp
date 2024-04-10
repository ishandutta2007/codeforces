#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
char s[MAXN];
int n, m, point[MAXN][2];
int tot, belong[MAXN], dp[MAXN];
int timer, dfn[MAXN], low[MAXN];
int top, Stack[MAXN], Max[MAXN];
bool instack[MAXN], vis[MAXN];
vector <int> a[MAXN], b[MAXN];
void tarjan(int pos) {
	dfn[pos] = low[pos] = ++timer;
	Stack[++top] = pos, instack[pos] = true;
	for (auto x : a[pos]) {
		if (dfn[x] == 0) {
			tarjan(x);
			chkmin(low[pos], low[x]);
		} else if (instack[x]) chkmin(low[pos], dfn[x]);
	}
	if (dfn[pos] == low[pos]) {
		int tmp = Stack[top--];
		belong[tmp] = ++tot;
		instack[tmp] = false;
		while (tmp != pos) {
			tmp = Stack[top--];
			belong[tmp] = tot;
			instack[tmp] = false;
		}
	}
}
void dfs(int pos) {
	vis[pos] = true;
	for (auto x : b[pos]) {
		for (auto y : a[x]) {
			int dest = belong[y];
			if (!vis[dest]) dfs(dest);
			if (dest != pos) {
				dp[pos] += dp[dest];
				chkmin(dp[pos], 2);
			}
		}
	}
}
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m);
		scanf("\n%s", s + 1);
		for (int i = 1, tot = 0; i <= n; i++) {
			a[point[i][0] = ++tot].clear();
			a[point[i][1] = ++tot].clear();
		}
		bool ans = true;
		for (int i = 1; i <= m; i++) {
			int x, y; read(x), read(y);
			if (x <= 0) {
				if (y <= 0) {
					a[point[abs(x)][1]].push_back(point[abs(y)][0]);
					a[point[abs(y)][1]].push_back(point[abs(x)][0]);
				} else {
					a[point[abs(x)][1]].push_back(point[abs(y)][1]);
					a[point[abs(y)][0]].push_back(point[abs(x)][0]);
				}
			} else {
				if (y <= 0) {
					a[point[abs(x)][0]].push_back(point[abs(y)][0]);
					a[point[abs(y)][1]].push_back(point[abs(x)][1]);
				} else {
					a[point[abs(x)][0]].push_back(point[abs(y)][1]);
					a[point[abs(y)][0]].push_back(point[abs(x)][1]);
				}
			}
		}
		tot = timer = 0;
		for (int i = 1; i <= 2 * n; i++) {
			dfn[i] = 0;
			low[i] = 0;
		}
		for (int i = 1; i <= 2 * n; i++)
			if (dfn[i] == 0) tarjan(i);
		for (int i = 1; i <= n; i++) {
			if (belong[point[i][0]] == belong[point[i][1]]) {
				ans = false;
			}
		}
		for (int i = 1; i <= tot; i++) {
			vis[i] = false;
			dp[i] = Max[i] = 0;
			b[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			b[belong[point[i][0]]].push_back(point[i][0]);
			b[belong[point[i][1]]].push_back(point[i][1]);
			if (s[i] == 'A') {
				dp[belong[point[i][0]]]++;
				dp[belong[point[i][1]]]++;
				chkmax(Max[belong[point[i][0]]], i);
				chkmax(Max[belong[point[i][1]]], i);
			}
		}
		for (int i = 1; i <= tot; i++)
			if (!vis[i]) dfs(i);
		for (int i = 1; i <= n; i++)
			if (s[i] == 'A') {
				if (dp[belong[point[i][0]]] >= 2) ans = false;
				if (dp[belong[point[i][1]]] >= 2) ans = false;
			} else {
				if (Max[belong[point[i][0]]] > i) ans = false;
				if (Max[belong[point[i][1]]] > i) ans = false;
			}
		if (ans) puts("TRUE");
		else puts("FALSE");
	}
	return 0;
}