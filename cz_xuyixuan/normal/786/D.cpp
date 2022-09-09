#pragma GCC optimize(3)
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
char from[MAXN];
int n, m, father[MAXN], ans[MAXN];
vector <pair <int, int> > q[MAXN];
vector <pair <int, char> > a[MAXN];
void dfs(int pos, int fa) {
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i].first != fa) {
			father[a[pos][i].first] = pos;
			from[a[pos][i].first] = a[pos][i].second;
			dfs(a[pos][i].first, pos);
		}
}
int solve(int pos, int to) {
	static int vis[MAXN], depth[MAXN], tag = 0;
	static char val[MAXN]; static int cmp[MAXN]; tag++;
	int tmp = n, ans = -1;
	for (int now = to; now != pos; now = father[now], tmp--) {
		val[tmp] = from[now];
		depth[now] = tmp;
		vis[now] = tag;
		cmp[now] = 1;
		ans++;
	}
	vis[pos] = tag, cmp[pos] = 1, depth[pos] = tmp;
	for (int i = 1; i <= n; i++)
		if (vis[i] != tag) {
			int top = 0, now = i;
			static int st[MAXN];
			while (vis[now] != tag) st[top++] = now, now = father[now];
			for (int j = top - 1; j >= 0; j--) {
				int now = st[j];
				depth[now] = depth[father[now]] + 1;
				vis[now] = tag;
				if (cmp[father[now]] != 1) cmp[now] = cmp[father[now]];
				else if (val[depth[now]] > from[now]) cmp[now] = 0;
				else if (val[depth[now]] == from[now]) cmp[now] = 1;
				else cmp[now] = 2;
				ans += (cmp[now] == 0) || (cmp[now] == 1 && depth[now] < n);
			}
		}
	return ans;
}
void work(int pos, int fa) {
	for (unsigned i = 0; i < q[pos].size(); i++)
		ans[q[pos][i].second] = solve(pos, q[pos][i].first);
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i].first != fa) {
			int dest = a[pos][i].first;
			father[pos] = dest;
			father[dest] = 0;
			from[pos] = a[pos][i].second;
			work(dest, pos);
			father[dest] = pos;
			father[pos] = 0;
			from[dest] = a[pos][i].second;
		}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; char c;
		scanf("%d%d %c", &x, &y, &c);
		a[x].push_back(make_pair(y, c));
		a[y].push_back(make_pair(x, c));
	}
	dfs(1, 0);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		q[x].push_back(make_pair(y, i));
	}
	work(1, 0);
	for (int i = 1; i <= m; i++)
		writeln(ans[i]);
	return 0;
}