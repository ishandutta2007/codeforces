#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
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
vector <int> a[MAXN], pos;
set <int> b[MAXN];
int n, m, degree[MAXN]; bool vis[MAXN];
void bfs() {
	static int fa[MAXN], q[MAXN], depth[MAXN];
	static bool vis[MAXN]; int l, r;
	q[l = r = 1] = 1, depth[1] = 1, vis[1] = true;
	while (l <= r) {
		int tmp = q[l++];
		for (unsigned i = 0; i < a[tmp].size(); i++)
			if (!vis[a[tmp][i]]) {
				q[++r] = a[tmp][i];
				fa[a[tmp][i]] = tmp;
				vis[a[tmp][i]] = true;
				depth[a[tmp][i]] = depth[tmp] + 1;
			}
	}
	if (depth[n] != 0 && depth[n] <= 5) {
		int pos = n; vector <int> ans;
		ans.push_back(n);
		while (pos != 1) {
			pos = fa[pos];
			ans.push_back(pos);
		}
		writeln(ans.size() - 1);
		for (unsigned i = ans.size(); i >= 1; i--)
			printf("%d ", ans[i - 1]);
		exit(0);
	}
	for (int i = 1; i <= r; i++) {
		int pos = q[i];
		if (depth[pos] == 3 && b[pos].count(1) == 0) {
			writeln(4);
			printf("%d %d %d %d %d\n", 1, fa[pos], pos, 1, n);
			exit(0);
		}
	}
}
void work(int x) {
	vis[x] = true; pos.push_back(x);
	for (unsigned i = 0; i < a[x].size(); i++) {
		degree[a[x][i]]++;
		if (!vis[a[x][i]]) work(a[x][i]);
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
		b[x].insert(y);
		b[y].insert(x);
	}
	bfs();
	vis[1] = true;
	for (unsigned i = 0; i < a[1].size(); i++) {
		if (vis[a[1][i]]) continue;
		pos.clear(); work(a[1][i]);
		int x = 0;
		for (unsigned j = 0; j < pos.size(); j++)
			if (degree[pos[j]] < pos.size() - 1) x = pos[j];
		if (x == 0) continue;
		for (unsigned j = 0; j < a[x].size(); j++) {
			if (a[x][j] == 1) continue;
			int y = a[x][j];
			for (unsigned k = 0; k < a[y].size(); k++) {
				int z = a[y][k];
				if (z != x && z != 1 && b[x].count(z) == 0) {
					writeln(5);
					printf("%d %d %d %d %d %d\n", 1, x, y, z, x, n);
					exit(0);
				}
			}
		}
	}
	writeln(-1);
	return 0;
}