#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) x.begin(), x..end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
const int N = 200100;
const int MOD = 998244353;
const double EPS = 1E-9;

struct DSU {
	int n;
	vector <int> p;
	DSU(int _n) : n(_n) {
		p.resize(n);
		iota(p.begin(), p.end(), 0);
	}
	int find(int x) {
		if(x == p[x]) return x;
		return p[x] = find(p[x]);
	}
	bool unite(int a, int b) {
		a = find(a);
		b = find(b);
		if(b != a) {
			p[b] = a;
			return true;
		}
		return false;
	}
};

int ask(int x) {
	cout << "? " << x + 1 << endl;
	int y; cin >> y;
	return y - 1;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> deg(n);
	vector<bool> vis(n);
	for(int i = 0; i < n; i++) {
		cin >> deg[i].first;
		deg[i].second = i;
	}
	sort(deg.begin(), deg.end());
	DSU dsu(n);
	while(!deg.empty()) {
		auto [d, v] = deg.back();
		deg.pop_back();
		if(vis[v]) continue;
		vis[v] = true;
		for(int i = 0; i < d; i++) {
			int y = ask(v);
			if(vis[y]) {
				dsu.unite(y, v);
				break;	
			} else {
				dsu.unite(y, v);
				vis[y] = true;
			}
		}
	}
	cout << "! ";
	for(int i = 0; i < n; i++) {
		cout << dsu.find(i) + 1 << ' ';
	}
	cout << endl;
}

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	int t = 1;
#ifdef LOCAL
	// freopen("input.txt", "r", stdin);
#endif
	cin >> t;
	while(t--) {
		solve();
	}
}