#include <bits/stdc++.h>
using namespace std;

const int MX = (int)1e5 + 5;

int test;

vector<int> con[MX];

int dp[MX], sz[MX], prv[MX];
void dfs(int u) {
	sz[u] = 1;
	for (int v : con[u]) {
		dp[v] = dp[u] + 1;
		dfs(v);
		sz[u] += sz[v];
	}
}

int fst[MX], st[MX], en[MX], pn;
void hld(int u, int hd) {
	fst[u] = hd;
	st[u] = ++pn;
	int w = 0;
	for (int v : con[u]) if (sz[w] < sz[v]) w = v;
	if (w) hld(w, hd);
	for (int v : con[u]) if (v != w) hld(v, v);
	en[u] = pn;
}

struct Node {
	int a, b, clr, len;
	Node(int a = 0, int b = 0, int clr = 0) : a(a), b(b), clr(clr) {}
	Node operator + (const Node &d) const {
		if (b >= d.a) return Node(a, b - d.a + d.b);
		else return Node(a + d.a - b, d.b);
	}
	void clear() {
		a = len, b = 0, clr = 1;
	}
} node[1 << 20];

void push_down(int id) {
	if (node[id].clr) {
		node[id + id].clear();
		node[id + id + 1].clear();
		node[id].clr = 0;
	}
}

void push_up(int id) {
	node[id] = node[id + id] + node[id + id + 1];
	node[id].len = node[id + id].len + node[id + id + 1].len;
}

void build(int id, int st, int en) {
	if (st == en) {
		node[id] = Node(1, 0, 0);
		node[id].len = 1;
		return;
	}
	int mid = st + en >> 1;
	build(id + id, st, mid);
	build(id + id + 1, mid + 1, en);
	push_up(id);
}

void add(int id, int st, int en, int pos, int val) {
	if (pos <= st && en <= pos) {
		node[id].b += val;
		return;
	}
	push_down(id);
	int mid = st + en >> 1;
	if (pos <= mid) add(id + id, st, mid, pos, val);
	if (pos > mid) add(id + id + 1, mid + 1, en, pos, val);
	push_up(id);
}

Node get(int id, int st, int en, int l, int r) {
	if (l <= st && en <= r) {
		return node[id];
	}
	push_down(id);
	Node res = Node(0, 0);
	int mid = st + en >> 1;
	if (l <= mid) res = res + get(id + id, st, mid, l, r);
	if (r > mid) res = res + get(id + id + 1, mid + 1, en, l, r);
	push_up(id);
	return res;
}

vector<pair<int, int> > cur;

int get_val(int u, int v, int n) {
	int fu, fv;
	Node res = Node(0, 0);
	cur.clear();
	while (true) {
		fu = fst[u], fv = fst[v];
		if (fu == fv) break;
		if (dp[fu] > dp[fv]) swap(u, v), swap(fu, fv);
		cur.push_back(make_pair(st[fv], st[v]));
//		res = res + get(1, 1, n, st[fv], st[v]);
		
//		if (test) cerr<<res.a<<" "<<res.b<<endl;
		
		v = prv[fv];
	}
	if (st[u] > st[v]) swap(u, v);
	cur.push_back(make_pair(st[u], st[v]));
//	res = res + get(1, 1, n, st[u], st[v]);
	
	for (int i = cur.size() - 1; i >= 0; i--) res = res + get(1, 1, n, cur[i].first, cur[i].second);
	
//	if (test) cerr<<res.a<<" "<<res.b<<endl;
	
	return res.b;
}

void clear(int id, int st, int en, int l, int r) {
	if (l <= st && en <= r) {
		node[id].clear();
		return;
	}
	push_down(id);
	int mid = st + en >> 1;
	if (l <= mid) clear(id + id, st, mid, l, r);
	if (r > mid) clear(id + id + 1, mid + 1, en, l, r);
	push_up(id);
}

int main() {

//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	
	int n, q; cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		int u; cin >> u;
		con[u].push_back(i);
		prv[i] = u;
	}
	
	dp[1] = 1;
	dfs(1);
	hld(1, 1);
	build(1, 1, n); 
	
	while (q--) {
		int type, v; cin >> type >> v;
		if (type == 1) add(1, 1, n, st[v], 1);
		else {
//			if (v == 7) test = 1;
//			else test = 0;
			int val = get_val(v, 1, n);
			if (type == 3) cout << (val > 0 ? "black" : "white") << endl;
			else add(1, 1, n, st[v], -val), clear(1, 1, n, st[v] + 1, en[v]);
		}
	}
	
	return 0;

}