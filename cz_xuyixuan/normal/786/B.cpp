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
namespace ShortestPath {
	const ll INF = 1e18;
	const int MAXP = 1e6;
	struct edge {int dest, len; };
	int n; ll dist[MAXP];
	vector <edge> a[MAXP];
	set <pair <ll, int> > st;
	void addedge(int x, int y, int z) {
		a[x].push_back((edge) {y, z});
	}
	void init(int x) {
		n = x; st.clear();
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
			a[i].clear();
		}
	}
	void work(int s) {
		dist[s] = 0;
		st.insert(make_pair(0, s));
		while (!st.empty()) {
			pair <ll, int> tmp = *st.begin();
			st.erase(tmp);
			for (unsigned i = 0; i < a[tmp.second].size(); i++) {
				int dest = a[tmp.second][i].dest;
				ll newlen = tmp.first + a[tmp.second][i].len;
				if (newlen < dist[dest]) {
					st.erase(make_pair(dist[dest], dest));
					dist[dest] = newlen;
					st.insert(make_pair(dist[dest], dest));
				}
			}
		}
	}
}
int tot, n, q, s, totp, root;
int lc[MAXN], rc[MAXN], point[MAXN][2];
void build(int &root, int l, int r) {
	root = ++totp;
	point[root][0] = ++tot;
	point[root][1] = ++tot;
	if (l == r) return;
	int mid = (l + r) / 2;
	build(lc[root], l, mid);
	build(rc[root], mid + 1, r);
}
void query(int from, int root, int l, int r, int ql, int qr, int len, int type) {
	if (l == ql && r == qr) {
		if (type == 0) ShortestPath :: addedge(from, point[root][0], len);
		else ShortestPath :: addedge(point[root][1], from, len);
		return;
	}
	int mid = (l + r) / 2;
	if (mid >= ql) query(from, lc[root], l, mid, ql, min(mid, qr), len, type);
	if (mid + 1 <= qr) query(from, rc[root], mid + 1, r, max(mid + 1, ql), qr, len, type);
}
int main() {
	read(n), read(q), read(s), tot = n;
	build(root, 1, n);
	ShortestPath :: init(tot);
	for (int i = 1, j = 0; i <= totp; i++) {
		if (lc[i]) {
			ShortestPath :: addedge(point[i][0], point[lc[i]][0], 0);
			ShortestPath :: addedge(point[i][0], point[rc[i]][0], 0);
			ShortestPath :: addedge(point[lc[i]][1], point[i][1], 0);
			ShortestPath :: addedge(point[rc[i]][1], point[i][1], 0);
		} else {
			j++;
			ShortestPath :: addedge(point[i][0], j, 0);
			ShortestPath :: addedge(j, point[i][1], 0);
		}
	}
	for (int i = 1; i <= q; i++) {
		int opt; read(opt);
		if (opt == 1) {
			int x, y, z;
			read(x), read(y), read(z);
			ShortestPath :: addedge(x, y, z);
		}
		if (opt == 2) {
			int x, l, r, z;
			read(x), read(l), read(r), read(z);
			query(x, root, 1, n, l, r, z, 0);
		}
		if (opt == 3) {
			int x, l, r, z;
			read(x), read(l), read(r), read(z);
			query(x, root, 1, n, l, r, z, 1);
		}
	}
	ShortestPath :: work(s);
	for (int i = 1; i <= n; i++) {
		ll tmp = ShortestPath :: dist[i];
		if (tmp == 1e18) printf("-1 ");
		else write(tmp), putchar(' ');
	}
	return 0;
}