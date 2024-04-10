#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

ll n, m, L, s, t, comp[10000];
vector<ll> dst;
vector<pair<ll, ll> > e[100000];
vector<pair<ll, pair<ll, ll> > > q;

int kk = 0;
void deijkstra(int nu) {
	dst.assign(n, L + 1);
	dst[nu] = 0;
	set<pair<ll, ll> > d;
	forn (i, n) {
		d.insert(mp(dst[i], i));
	} 
	forn (i, n) {
		int nu = (d.begin()->se);
		d.erase(d.begin());
		for (auto v : e[nu]) {
			if (dst[v.fi] > dst[nu] + v.se) {
				d.erase(mp(dst[v.fi], v.fi));
				dst[v.fi] = dst[nu] + v.se;
				d.insert(mp(dst[v.fi], v.fi));
			}
		}
	}
}

void dfs(int nu) {
	comp[nu] = kk;
	for (auto v : e[nu]) {
		if (comp[v.fi] == 0) {
			dfs(v.fi);
		}
	}
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> m >> L >> s >> t;
	forn (i, m) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		q.push_back(mp(u, mp(v, w)));
		if (w == 0) {
			continue;
		}
		e[u].push_back(mp(v, w));
		e[v].push_back(mp(u, w));
	}
	deijkstra(s);
	if (dst[t] < L) {
		cout << "NO\n";
		re 0;
	}
	for (auto& v : q) {
		if (v.se.se == 0) {
			v.se.se = 1;
			e[v.fi].push_back(mp(v.se.fi, 1));
			e[v.se.fi].push_back(mp(v.fi, 1));
			deijkstra(s);
			if (dst[t] < L) {
				//e[v.fi][sz(e[v.fi]) - 1] = 1 + L - dst[t];
				v.se.se += L - dst[t];
				break;
			}
		}
	}
	deijkstra(s);
	if (dst[t] > L) {
		cout << "NO\n";
		re 0;
	}
	for (auto& v : q)
		if (v.se.se == 0)
			v.se.se = L + 1;
	cout << "YES\n";
	for (auto v : q)
		cout << v.fi << " " << v.se.fi << " " << v.se.se << "\n";
	re 0;
}