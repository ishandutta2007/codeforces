#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) a.begin(), a.end()

const int MOD = 998244353;

void add(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mul(int64_t a, int b) { return a * b % MOD; }

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	struct Edge {
		int w, i, j;
		bool operator < (Edge e) { return w < e.w; }
	};

	int n, x;
	cin >> n;
	vector<Edge> es;
	es.reserve(n * (n - 1) / 2);
	forn(i, n) forn(j, n) {
		cin >> x;
		if (i < j)
			es.push_back({x, i, j});
	}

	struct DSU {
		vector<int> p;
		DSU(int n) : p(n) {
			iota(all(p), 0);
		}
		int get(int i) {
			return i == p[i] ? i : (p[i] = get(p[i]));
		}
	} dsu(n);

	sort(all(es));

	struct Component {
		int size, in_edges;
		vector<int> f;
		bool full() { return in_edges == size * (size - 1) / 2; }
	};
	vector<Component> g(n, {1, 0, {0, 1}});
	auto combine = [&](vector<int> &a, const vector<int> &b) {
		static vector<int> tmp;
		tmp.assign(a.size() + b.size() - 1, 0);
		forn(ia, a.size())
			forn(ib, b.size())
				add(tmp[ia + ib], mul(a[ia], b[ib]));
		a.swap(tmp);
	};
	for (auto e : es) {
		int i = dsu.get(e.i), j = dsu.get(e.j);
		if (i != j) {
			dsu.p[j] = i;
			g[i].size += g[j].size;
			g[i].in_edges += g[j].in_edges;
			combine(g[i].f, g[j].f);
		}
		g[i].in_edges++;
		if (g[i].full())
			g[i].f[1]++;
	}

	int root = dsu.get(0);
	for (int i = 1; i <= n; i++)
		cout << g[root].f[i] << " ";
	cout << endl;
}