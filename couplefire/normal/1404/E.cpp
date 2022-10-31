#include<bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct Kuhn {
	int n; vector<vector<int>> g;
	vector<int> l, r; vector<bool> vis;
	Kuhn(int _n, int _m) {
		n = _n;
		g.resize(n + 1); vis.resize(n + 1, false);
		l.resize(n + 1, -1); r.resize(_m + 1, -1);
	}
	void add_edge(int a, int b) {
		g[a].push_back(b);
	}
	bool yo(int u) {
		if (vis[u])  return false;
		vis[u] = true;
		for (auto v : g[u]) {
			if (r[v] == -1 || yo(r[v])) {
				l[u] = v;
				r[v] = u;
				return true;
			}
		}
		return false;
	}
	int maximum_matching() {
		for (int i = 1; i <= n; i++) shuffle(g[i].begin(), g[i].end(), rnd);
		vector<int> p(n); iota(p.begin(), p.end(), 1);
		shuffle(p.begin(), p.end(), rnd);
		bool ok = true;
		while (ok) {
			ok = false;
			vis.assign(n + 1, false);
			for (auto &i: p) if(l[i] == -1) ok |= yo(i);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) ans += l[i] != -1;
		return ans;
	}
};

string s[205];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; 
    cin >> n >> m;
	s[0] = string(m + 2, '.');
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = "." + s[i] + ".";
	}
	s[n + 1] = string(m + 2, '.');
	Kuhn F(n * m, n * m);
	int black = 0, vertex = 0;
	#define id(i, j) (i - 1) * m + j
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '#') {
				black++;
				if (s[i][j - 1] == '#') {
					vertex++;
					if (s[i - 1][j - 1] == '#') {
						F.add_edge(id(i - 1, j - 1), id(i, j - 1));
					}					
					if (s[i - 1][j] == '#') {
						F.add_edge(id(i - 1, j), id(i, j - 1));
					}
				}				
				if (s[i + 1][j] == '#') {
					vertex++;
					if (s[i][j - 1] == '#') {
						F.add_edge(id(i, j), id(i, j - 1));
					}					
					if (s[i][j + 1] == '#') {
						F.add_edge(id(i, j), id(i, j));
					}
				}
			}
		}
	}
	int ans = vertex - F.maximum_matching();
	cout << black - ans << endl;;
    return 0;
}