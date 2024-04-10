#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 150005;

int a[N], p[1000002];

struct dsu {
	vi p, sz;
	dsu(int n) {
		p = vi(n);
		iota(ALL(p), 0);
		sz = vi(n, 1);
	}
	int find(int u) {
		return p[u] == u ? u : p[u] = find(p[u]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return;
		if(sz[x] > sz[y]) swap(x, y);
		sz[y] += sz[x];
		p[x] = y;
	}
};

int id[1000002];

signed main()
{
	IO_OP;

	int cnt = 0;
	for(int i = 2; i <= 1000001; i++) {
		if(p[i]) continue;
		p[i] = i;
		id[i] = cnt++;

		for(ll j = (ll) i * i; j <= 1000001; j += i)
			p[j] = i;
	}

	int n, q;
	cin >> n >> q;
	dsu d1(n + cnt);
	V<set<int>> G(n + cnt);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		int x = a[i];
		while(x != 1) {
			int pp = p[x];
			while(x % pp == 0) 
				x /= pp;
			d1.unite(i, n + id[pp]);
		}
	}
	for(int i = 0; i < n; i++) {
		int x = a[i] + 1;
		vi tt({d1.find(i)});
		while(x != 1) {
			int pp = p[x];
			while(x % pp == 0) 
				x /= pp;
			for(int j:tt) {
				G[j].insert(d1.find(n + id[pp]));
				G[d1.find(n + id[pp])].insert(j);
			}
			tt.PB(d1.find(n + id[pp]));
		}
	}

	while(q--) {
		int s, t;
		cin >> s >> t;
		s--, t--;
		s = d1.find(s), t = d1.find(t);
		if(s == t) {
			cout << 0 << '\n';
			continue;
		}
		if(G[s].count(t))  {
			cout << 1 << '\n';
			continue;
		}
		cout << 2 << '\n';
	}

}