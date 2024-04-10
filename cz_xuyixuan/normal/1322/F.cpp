#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
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
int n, m; vector <int> a[MAXN];
namespace LowestCommonAncestor {
	const int MAXN = 5e5 + 5;
	const int MAXLOG = 20;
	int depth[MAXN], father[MAXN][MAXLOG];
	void work(int pos, int fa) {
		depth[pos] = depth[fa] + 1;
		father[pos][0] = fa;
		for (int i = 1; i < MAXLOG; i++)
			father[pos][i] = father[father[pos][i - 1]][i - 1];
		for (unsigned i = 0; i < a[pos].size(); i++)
			if (a[pos][i] != fa) work(a[pos][i], pos);
	}
	int lca(int x, int y) {
		if (depth[x] < depth[y]) swap(x, y);
		for (int i = MAXLOG - 1; i >= 0; i--)
			if (depth[father[x][i]] >= depth[y]) x = father[x][i];
		if (x == y) return x;
		for (int i = MAXLOG - 1; i >= 0; i--)
			if (father[x][i] != father[y][i]) {
				x = father[x][i];
				y = father[y][i];
			}
		return father[x][0];
	}
	int climb(int x, int y) {
		for (int i = 0; y != 0; i++)
			if (y & (1 << i)) {
				y ^= 1 << i;
				x = father[x][i];
			}
		return x;
	}
}
namespace UnionFind {
	const int MAXN = 1e6 + 5;
	int f[MAXN];
	void init(int n) {
		for (int i = 1; i <= n * 2; i++)
			f[i] = i;
	}
	int find(int x) {
		if (f[x] == x) return x;
		else return f[x] = find(f[x]);
	}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		f[x] = y;
	}
	void addedge(int x, int y, bool z) {
		if (z == false) {
			merge(x, y);
			merge(x + n, y + n);
		} else {
			merge(x, y + n);
			merge(x + n, y);
		}
		if (find(x) == find(x + n)) {
			puts("-1");
			exit(0);
		}
	}
	pair <int, bool> query(int x) {
		int tmp = find(x);
		if (tmp <= n) return make_pair(tmp, false);
		else return make_pair(tmp - n, true);
	}
}
bool rev[MAXN];
int k, timer, p[MAXN];
int dp[MAXN], res[MAXN];
void getans() {
	for (int i = 1; i <= n; i++) {
		int pos = p[i];
		if (!rev[pos]) res[pos] = dp[pos];
		else res[pos] = k + 1 - dp[pos];
		for (auto x : a[pos])
			rev[x] ^= rev[pos];
	}
}
bool check(int mid) {
	k = mid;
	for (int i = n; i >= 1; i--) {
		int pos = p[i];
		vector <int> points;
		static bool trev[MAXN];
		static pair <int, int> inter[MAXN];
		using namespace UnionFind;
		for (auto x : a[pos]) {
			pair <int, bool> tmp = query(x);
			inter[tmp.first] = make_pair(0, 0);
		}
		pair <int, bool> cur = query(pos);
		points.push_back(cur.first);
		inter[cur.first] = make_pair(1, k);
		for (auto x : a[pos]) {
			pair <int, bool> tmp = query(x);
			if (inter[tmp.first].first == 0) {
				points.push_back(tmp.first);
				inter[tmp.first] = make_pair(1, k);
			}
			if (tmp.second == cur.second) chkmax(inter[tmp.first].first, dp[x] + 1);
			else chkmin(inter[tmp.first].second, k - dp[x]);
		}
		pair <int, int> ban = make_pair(k + 1, 0);
		int l = inter[cur.first].first, r = inter[cur.first].second;
		for (auto x : points) {
			pair <int, int> a = inter[x];
			pair <int, int> b = make_pair(k + 1 - a.second, k + 1 - a.first);
			if (a.first > a.second) return false;
			if (a > b) swap(a, b);
			chkmax(l, a.first);
			chkmin(r, b.second);
			if (a.second + 1 < b.first) {
				chkmin(ban.first, a.second + 1);
				chkmax(ban.second, b.first - 1);
			}
		}
		if (l > r) return false;
		if (l < ban.first || l > ban.second) dp[pos] = l;
		else if (ban.second + 1 <= r) dp[pos] = ban.second + 1;
		else return false;
		for (auto x : points) {
			if (inter[x].first <= dp[pos] && inter[x].second >= dp[pos]) trev[x] = false;
			else trev[x] = true;
		}
		for (auto x : a[pos]) {
			pair <int, bool> tmp = query(x);
			rev[x] = trev[tmp.first] ^ (tmp.second != cur.second);
		}
	}
	return true;
}
int subt[MAXN];
void build(int pos, int fa) {
	p[++timer] = pos;
	for (auto x : a[pos])
		if (x != fa) {
			build(x, pos);
			subt[pos] += subt[x];
		}
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] == fa) {
			swap(a[pos][i], a[pos][a[pos].size() - 1]);
			a[pos].pop_back();
			break;
		}
	if (subt[pos]) {
		UnionFind :: addedge(fa, pos, false);
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	UnionFind :: init(n);
	LowestCommonAncestor :: work(1, 0);
	for (int i = 1; i <= m; i++) {
		using namespace LowestCommonAncestor;
		int x, y; read(x), read(y);
		int z = lca(x, y), p, q;
		if (x != z) {
			subt[x]++;
			subt[p = climb(x, depth[x] - depth[z] - 1)]--;
		}
		if (y != z) {
			subt[y]++;
			subt[q = climb(y, depth[y] - depth[z] - 1)]--;
		}
		if (x != z && y != z) {
			UnionFind :: addedge(p, q, true);
		}
	}
	build(1, 0);
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	check(l), getans();
	for (int i = 1; i <= n; i++)
		printf("%d ", res[i]);
	printf("\n");
	return 0;
}