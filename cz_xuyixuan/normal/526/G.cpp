#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXLOG = 18;
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
int n, q, depth[MAXN];
vector <pair <int, int>> a[MAXN];
struct Answer {
	int depth[MAXN], Max[MAXN], son[MAXN], leaf[MAXN];
	int father[MAXN][MAXLOG], Min[MAXN][MAXLOG];
	int inc[MAXN], sum[MAXN], vis[MAXN];
	pair <int, int> seg[MAXN]; int tot;
	void dfs(int pos, int fa) {
		father[pos][0] = fa;
		Max[pos] = depth[pos];
		leaf[pos] = pos;
		for (auto x : a[pos])
			if (x.first != fa) {
				depth[x.first] = depth[pos] + x.second;
				dfs(x.first, pos);
				if (Max[x.first] > Max[pos]) {
					leaf[pos] = leaf[x.first];
					Max[pos] = Max[x.first];
					son[pos] = x.first;
				}
			}
	}
	void efs(int pos, int fa) {
		if (pos != son[fa]) seg[++tot] = make_pair(Max[pos] - depth[fa], leaf[pos]);
		for (auto x : a[pos]) if (x.first != fa) efs(x.first, pos);
	}
	void init(int from) {
		dfs(from, 0);
		efs(from, 0);
		sort(seg + 1, seg + tot + 1);
		reverse(seg + 1, seg + tot + 1);
		for (int i = 1; i <= tot; i++) {
			int pos = seg[i].second;
			while (vis[pos] == 0) {
				vis[pos] = Min[pos][0] = i;
				pos = father[pos][0];
			}
			inc[i] = seg[i].first;
			sum[i] = inc[i] + sum[i - 1];
		}
		for (int p = 1; p < MAXLOG; p++)
		for (int i = 1; i <= n; i++) {
			father[i][p] = father[father[i][p - 1]][p - 1];
			Min[i][p] = min(Min[i][p - 1], Min[father[i][p - 1]][p - 1]);
		}
	}
	int query(int x, int y) {
		y = y * 2 - 1;
		if (y >= tot) return sum[tot];
		if (vis[x] <= y) return sum[y];
		int ans = sum[y], pos = x;
		for (int i = MAXLOG - 1; i >= 0; i--)
			if (Min[pos][i] > y) pos = father[pos][i];
		ans += Max[x] - depth[pos];
		ans -= min(inc[y], Max[pos] - depth[pos]);
		return ans;
	}
} s, t;
void getdepth(int pos, int fa) {
	for (auto x : a[pos])
		if (x.first != fa) {
			depth[x.first] = depth[pos] + x.second;
			getdepth(x.first, pos);
		}
}
int main() {
	read(n), read(q);
	for (int i = 1; i <= n - 1; i++) {
		int x, y, z;
		read(x), read(y), read(z);
		a[x].emplace_back(y, z);
		a[y].emplace_back(x, z);
	}
	getdepth(1, 0);
	int x = max_element(depth + 1, depth + n + 1) - depth;
	depth[x] = 0, getdepth(x, 0);
	int y = max_element(depth + 1, depth + n + 1) - depth;
	s.init(x), t.init(y);
	int lastans = 0;
	for (int i = 1; i <= q; i++) {
		int x, y; read(x), read(y);
		x = (x + lastans - 1) % n + 1;
		y = (y + lastans - 1) % n + 1;
		printf("%d\n", lastans = max(s.query(x, y), t.query(x, y)));
	}
	return 0;
}