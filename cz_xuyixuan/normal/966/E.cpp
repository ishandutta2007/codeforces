#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXLOG = 20;
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
vector <int> a[MAXN], b[MAXN], c[MAXN];
int n, m, father[MAXN], val[MAXN], q[MAXN];
int timer, dfn[MAXN], depth[MAXN], parent[MAXN][MAXLOG];
int btot, bsize, bl[MAXN], br[MAXN], belong[MAXN];
int ans, size[MAXN], newfa[MAXN], point[MAXN];
bool flg[MAXN];
int lca(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (depth[parent[x][i]] >= depth[y]) x = parent[x][i];
	if (x == y) return x;
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	return father[x];
}
void dfs(int pos, int fa) {
	dfn[pos] = ++timer;
	parent[pos][0] = fa;
	for (int i = 1; i < MAXLOG; i++)
		parent[pos][i] = parent[parent[pos][i - 1]][i - 1];
	depth[pos] = depth[fa] + 1;
	for (unsigned i = 0; i < a[pos].size(); i++)
		dfs(a[pos][i], pos);
}
void calc(int pos) {
	for (unsigned i = 0; i < a[pos].size(); i++) {
		calc(a[pos][i]);
		size[pos] += size[a[pos][i]];
	}
	val[pos] += size[pos];
	if (!flg[pos] && val[pos] <= 0) ans++;
}
bool cmp(int x, int y) {
	return dfn[x] < dfn[y];
}
int main() {
	read(n), read(m);
	for (int i = 2; i <= n; i++) {
		read(father[i]);
		a[father[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		read(val[i]), val[i]++;
	for (int i = 1; i <= m; i++)
		read(q[i]);
	dfs(1, 0);
	bsize = pow(m, 0.68); btot = 0;
	for (int i = 1; i <= m; i++) {
		if (i % bsize == 1 % bsize) bl[++btot] = i;
		belong[i] = btot, br[btot] = i;
	}
	for (int t = 1; t <= btot; t++) {
		static int tmp[MAXN]; int tot = 0;
		for (int i = bl[t]; i <= br[t]; i++)
			tmp[++tot] = abs(q[i]);
		sort(tmp + 1, tmp + tot + 1, cmp);
		static int stk[MAXN], used[MAXN]; int top = 0, cnt = 0;
		stk[++top] = used[++cnt] = 1;
		for (int i = 1; i <= tot; i++) {
			if (tmp[i] == stk[top]) continue;
			int Lca = lca(tmp[i], stk[top]);
			if (Lca == stk[top]) stk[++top] = used[++cnt] = tmp[i];
			else {
				while (dfn[Lca] < dfn[stk[top - 1]]) {
					newfa[stk[top]] = stk[top - 1];
					top--;
				}
				newfa[stk[top]] = Lca; top--;
				if (Lca == stk[top]) stk[++top] = used[++cnt] = tmp[i];
				else {
					stk[++top] = used[++cnt] = Lca;
					stk[++top] = used[++cnt] = tmp[i];
				}
			}
		}
		while (top >= 2) {
			newfa[stk[top]] = stk[top - 1];
			top--;
		}
		for (int i = 1; i <= cnt; i++) {
			int now = used[i], pos = father[now];
			b[now].clear(), c[now].clear();
			while (pos != newfa[now]) {
				if (!flg[pos]) b[now].push_back(val[pos]);
				pos = father[pos];
			}
			sort(b[now].begin(), b[now].end());
			int top = -1;
			for (unsigned i = 0; i < b[now].size(); i++)
				if (i == 0 || b[now][i] != b[now][i - 1]) b[now][++top] = b[now][i], c[now].push_back(1);
				else c[now][top]++;
			b[now].resize(top + 1);
			point[now] = 0;
			for (unsigned i = 0; i < b[now].size(); i++)
				if (b[now][i] <= 0) point[now]++;
				else break;
		}
		memset(size, 0, sizeof(size));
		for (int i = bl[t]; i <= br[t]; i++) {
			int now = abs(q[i]);
			if (q[i] >= 0) {
				if (val[now] + size[now] <= 0) ans--; flg[now] = true;
				int pos = now;
				while (pos) {
					size[pos]--;
					if (!flg[pos] && val[pos] + size[pos] == 0) ans++;
					if (point[pos] < b[pos].size() && b[pos][point[pos]] + size[pos] <= 0) ans += c[pos][point[pos]++];
					pos = newfa[pos];
				}
			} else {
				if (val[now] + size[now] + 1 <= 0) ans++; flg[now] = false;
				int pos = now;
				while (pos) {
					if (now != pos && !flg[pos] && val[pos] + size[pos] == 0) ans--;
					size[pos]++;
					if (point[pos] > 0 && b[pos][point[pos] - 1] + size[pos] > 0) ans -= c[pos][--point[pos]];
					pos = newfa[pos];
				}
			}
			printf("%d ", ans);
		}
		ans = 0; memset(size, 0, sizeof(size));
		for (int i = bl[t]; i <= br[t]; i++)
			if (q[i] >= 0) size[q[i]]--, flg[q[i]] = true;
			else size[-q[i]]++, flg[-q[i]] = false;
		calc(1);
	}
	return 0;
}