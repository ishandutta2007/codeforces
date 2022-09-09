#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
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
int father[MAXN], s[MAXN], t[MAXN]; ll depth[MAXN];
vector <pair <ll, ll>> res;
struct LinkCutTree {
	struct Node {
		int child[2];
		int val, father, up;
	} a[MAXN];
	bool get(int root) {return a[a[root].father].child[1] == root; }
	void rotate(int x) {
		int f = a[x].father, g = a[f].father;
		bool tmp = get(x), tnp = get(f);
		a[a[x].child[tmp ^ 1]].father = f;
		a[f].child[tmp] = a[x].child[tmp ^ 1];
		a[x].child[tmp ^ 1] = f;
		a[f].father = x;
		a[x].father = g;
		if (g != 0) a[g].child[tnp] = x;
		a[x].up = a[f].up;
		a[x].val = a[f].val;
		a[f].up = a[f].val = 0;
	}
	void splay(int x) {
		for (int f = a[x].father; (f = a[x].father) != 0; rotate(x)) {
			if (a[f].father != 0) {
				if (get(f) == get(x)) rotate(f);
				else rotate(x);
			}
		}
	}
	int findroot(int x) {
		int bak = x;
		while (a[x].child[0]) x = a[x].child[0];
		int ans = x; splay(x), splay(bak);
		return ans;
	}
	int findnxt(int x) {
		int bak = x; x = a[x].child[1];
		while (a[x].child[0]) x = a[x].child[0];
		int ans = x; splay(x), splay(bak);
		return ans;
	}
	void access(int x, int timer) {
		splay(x);
		if (a[x].child[1]) {
			int son = findnxt(x);
			if (son != s[timer]) {
				if (a[x].val == 0) res.emplace_back(1, t[timer] + depth[x]);
				else res.emplace_back(1 + t[a[x].val] + depth[x], t[timer] + depth[x]);
			}
		} else {
			int son = s[a[x].val];
			if (son != s[timer]) {
				if (a[x].val == 0) res.emplace_back(1, t[timer] + depth[x]);
				else res.emplace_back(1 + t[a[x].val] + depth[x], t[timer] + depth[x]);
			}
		}
		int tmp = a[x].child[1];
		a[tmp].up = x;
		a[x].child[1] = 0;
		a[tmp].val = a[x].val;
		a[tmp].father = 0;
		while (a[x].up) {
			int f = a[x].up;
			splay(f);
			if (a[f].child[1]) {
				int son = findnxt(f);
				if (son != findroot(x)) {
					if (a[f].val == 0) res.emplace_back(1, t[timer] + depth[f]);
					else res.emplace_back(1 + t[a[f].val] + depth[f], t[timer] + depth[f]);
				}
			} else {
				int son = s[a[f].val];
				if (son != findroot(x)) {
					if (a[f].val == 0) res.emplace_back(1, t[timer] + depth[f]);
					else res.emplace_back(1 + t[a[f].val] + depth[f], t[timer] + depth[f]);
				}
			}
			int tmp = a[f].child[1];
			a[f].child[1] = x;
			a[x].father = f;
			a[x].up = 0;
			a[tmp].father = 0;
			a[tmp].up = f;
			a[tmp].val = a[f].val;
			splay(x);
		}
		a[x].val = timer;
	}
	void maketree(int x, int y) {
		a[x].up = y;
	}
	void link(int x, int y) {
		splay(y);
		a[y].child[1] = x;
		a[x].father = y;
	}
} LCT;
vector <pair <int, int>> a[MAXN];
int n, m, son[MAXN], x[MAXN], y[MAXN], z[MAXN];
void dfs(int pos, int fa) {
	father[pos] = fa;
	for (auto x : a[pos])
		if (x.first != fa) {
			depth[x.first] = depth[pos] + x.second;
			dfs(x.first, pos);
		}
}
void build(int pos, int fa, int from) {
	if (pos == from) LCT.maketree(pos, fa);
	else LCT.link(pos, fa);
	if (son[pos]) build(son[pos], pos, from);
	for (auto x : a[pos])
		if (x.first != fa && x.first != son[pos]) {
			build(x.first, pos, x.first);
		}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n - 1; i++) {
		read(x[i]), read(y[i]), read(z[i]);
		a[x[i]].emplace_back(y[i], z[i]);
		a[y[i]].emplace_back(x[i], z[i]);
	}
	dfs(1, 0);
	for (int i = 1; i <= n - 1; i++) {
		if (depth[x[i]] > depth[y[i]]) swap(x[i], y[i]);
		son[x[i]] = y[i];
	}
	build(1, 0, 1);
	for (int i = 1; i <= m; i++) {
		read(s[i]), read(t[i]);
		if (s[i] == 1) continue;
		else LCT.access(father[s[i]], i);
	}
	sort(res.begin(), res.end(), [&] (pair <ll, ll> x, pair <ll, ll> y) {
		return x.first < y.first;
	});
	priority_queue <ll, vector <ll>, greater <ll>> Heap;
	sort(res.begin(), res.end(), [&] (pair <ll, ll> x, pair <ll, ll> y) {
		return x.first < y.first;
	});
	vector <ll> used;
	ll now = 0, cnt = 0;
	for (auto x : res) {
		while (now < x.first) {
			if (Heap.size()) {
				if (Heap.top() < now) {
					int ans = 0;
					for (auto x : used) if (x < now - 1) ans++;
					cout << now - 1 << ' ' << ans << endl;
					return 0;
				}
				used.push_back(Heap.top());
				Heap.pop(), now++;
			} else now = x.first;
		}
		Heap.push(x.second);
	}
	while (!Heap.empty()) {
		if (Heap.top() < now) {
			int ans = 0;
			for (auto x : used) if (x < now - 1) ans++;
			cout << now - 1 << ' ' << ans << endl;
			return 0;
		}
		used.push_back(Heap.top());
		Heap.pop(), now++;
	}
	cout << -1 << ' ' << used.size() << endl;
	return 0;
}