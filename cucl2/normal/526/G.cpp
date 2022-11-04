#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n, q;
vector<pair<int, int> > nei[100005];

struct Tree {
	int rt, mxd;
	int mx[100005], dep[100005], fa[18][100005], dis[100005];
	int son[100005], ro[100005], len[100005];
	int ros[100005], roo, ans[100005], be[100005];
	vector<int> ch[100005];

	void dfs1(int now, int lst, int tp) {
		if (tp) {
			fa[0][now] = lst;
			cont(i, 17) fa[i][now] = fa[i - 1][fa[i - 1][now]];
		}
		mx[now] = dep[now];
		if (!tp && dep[mxd] < dep[now]) mxd = now;
		parse(it, nei[now]) {
			int to = it.first, w = it.second;
			if (to == lst) continue;
			dep[to] = dep[now] + w;
			dfs1(to, now, tp);
			mx[now] = max(mx[now], mx[to]);
			if (tp && mx[son[now]] < mx[to]) son[now] = to;
		}
	}

	void dfs2(int now, int lst, int rt) {
		ch[rt].pub(now); ro[now] = rt;
		if (son[now]) dfs2(son[now], now, rt);
		parse(it, nei[now]) {
			int to = it.first;
			if (to == lst || to == son[now]) continue;
			dfs2(to, now, to);
			len[to] = mx[to] - dep[now];
		}
	}

	int init(int x) {
		dfs1(x, 0, 0);
		rt = mxd; dep[rt] = 0;
		dfs1(rt, 0, 1);
		dfs2(rt, 0, rt);
		len[rt] = mx[rt];
		cont(i, n) if (ro[i] == i) ros[++roo] = i;
		sort(ros + 1, ros + roo + 1, [&] (int a, int b) { return len[a] > len[b]; });
		cont(i, roo) {
			ans[i] = ans[i - 1] + len[ros[i]];
			for (int now = ros[i]; now; now = son[now]) be[now] = i;
		}
		return rt;
	}

	int get(int x, int y, int arr[]) {
		int now = x;
		range(i, 17, 0, -1) if (be[fa[i][now]] > y) now = fa[i][now];
		now = fa[0][now];
		return ans[y] + mx[x] - arr[now];
	}

	int get(int x, int y) {
		y = 2 * y - 1;
		if (y >= roo) return ans[roo];
		if (be[x] <= y) return ans[y];
		return max(get(x, y - 1, dep), get(x, y, mx));
	}
} t1, t2;

int main() {
	scanf("%d%d", &n, &q);
	cont(i, n - 1) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		nei[u].emb(v, w); nei[v].emb(u, w);
	}
	t2.init(t1.init(1));
	int lst = 0;
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		x = (x + lst - 1) % n + 1;
		y = (y + lst - 1) % n + 1;
		printf("%d\n", lst = max(t1.get(x, y), t2.get(x, y)));
	}
	return 0;
}