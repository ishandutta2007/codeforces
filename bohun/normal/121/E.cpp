#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e5 + 100;
const int pod = (1 << 17);

int e[N];

void add(int x, int d) {
	for (; x < N; x += (x & -x))
		e[x] += d;
}

int query(int x) {
	int res = 0;
	for (; x; x -= (x & -x))
		res += e[x];
	return res;
}

pair<int, int> tree[2 * pod];
int lazy[2 * pod];

void init() {
	rep(i, 1, 2 * pod - 1) tree[i] = {-1e9, 0};
}

void push(int v) {
	for (int u : {2 * v, 2 * v + 1}) {
		lazy[u] += lazy[v];
		tree[u].fi += lazy[v];
	}
	lazy[v] = 0;
}

void ustaw(int x, int z, int v = 1, int l = 0, int r = pod - 1) {
	if (l == r) {
		assert(z < 0);
		tree[v] = {z, l};
		return;
	}
	push(v);
	int m = (l + r) / 2;
	if (x <= m) ustaw(x, z, 2 * v, l, m);
	if (m < x) ustaw(x, z, 2 * v + 1, m + 1, r);
	tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

void add(int x, int y, int z, int v = 1, int l = 0, int r = pod - 1) {
	if (x <= l && r <= y) {
		tree[v].fi += z;
		lazy[v] += z;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	if (x <= m) add(x, y, z, 2 * v, l, m);
	if (m < y) add(x, y, z, 2 * v + 1, m + 1, r);
	tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}	

int n, m;
int t[N];
int a, b, c;
int g[N], ok[N];

bool good(int x) {
	while (x > 0) {
		if (x % 10 != 4 && x % 10 != 7) return false;
		x /= 10;
	}
	return true;
}

set <int> s;
vector <int> del;

int main() {
	init();
	int last = 1e4 + 10;
	per(i, 1, 10000) {
		g[i] = last;
		if (good(i)) {
			ok[i] = 1;
			last = i;
		}
	}
	
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf ("%d", t + i);
		if (good(t[i])) {
			s.insert(i);
			add(i, 1);
		}
		ustaw(i, t[i] - g[t[i]]);
		//cat(t[i] - g[t[i]]);
		//cat(tree[1].fi);
	}
	
	while (m--) {
		char sa[20];
		scanf ("%s", sa);
		if (sa[0] == 'c') {
			scanf ("%d%d", &a, &b);
			printf ("%d\n", query(b) - query(a - 1));
		}
		else {
			del.clear();
			scanf ("%d%d%d\n", &a, &b, &c);
			auto it = s.lower_bound(a);
			while (it != s.end() && *it <= b) {
				add(*it, -1);
				del.pb(*it);
				it++;
			}
			for (auto it : del) s.erase(it);
			add(a, b, c);
			while (tree[1].fi >= 0) {
				int pos = tree[1].se;
				//cat(pos);
				//cat(t[pos]);
				//cat(g[t[pos]]);
				t[pos] = g[t[pos]] + tree[1].fi;
				if (ok[t[pos]]) {
					s.insert(pos);
					add(pos, 1);
				}
				ustaw(pos, t[pos] - g[t[pos]]);
			}
		}
	}
		

	return 0;
}