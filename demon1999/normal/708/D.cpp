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

const ll ma1 = 8, ma = 128 * 1024 * 2;

int n, k;

struct edge {
	ll v, nu, cost, f, c;
	edge(int v1, int nu1, int cc, int c1) {
		v = v1;
		nu = nu1;
		cost = cc;
		c = c1;
		f = 0;
	}
};

vector<int> use;
vector<edge> e[2300];
vector<pair<pair<int, int>, pair<int, int> > > q;

void add_edge(int u, int v, int cost, int c) {
	e[u].push_back(edge(v, sz(e[v]), cost, c));
	e[v].push_back(edge(u, sz(e[u]) - 1, -cost, 0));
}

bool dfs(int u, int vv) {
	use[u] = 1;
	if (u == vv)
		re true;
	for (auto v : e[u])
		if (!use[v.v] && v.c - v.f > 0)
			if (dfs(v.v, vv)) re true;
	re false;
}

ll cst[2300];
ll ans = 0;
vector<pair<int, int> > ek[2300];
ll usek[2300];

void dfs(int nu) {
	usek[nu] = 1;
	for (auto v : ek[nu]) {
		if (!usek[v.fi])
			dfs(v.fi);
		ans += v.se;
	}
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen("stringsqueries.out", "w", stdout);
	int m;
	cin >> n >> m;
	forn (i, m) {
		int a, b, c, f;
		cin >> a >> b >> c >> f;
		a--;
		b--;
		//ek[a].push_back(mp(b, f));
		ans += f;
		if (c > f) {
			add_edge(a, b, -1, f);
			add_edge(a, b, 1, c - f);
			add_edge(a, b, 2, 1000000000);
		}
		else {
			add_edge(a, b, -1, c);
			add_edge(a, b, 0, f - c);
			add_edge(a, b, 2, 1000000000);	
		}
	}
	/*
	forn (i, n) {
		add_edge(0, i, 0, 1000000000);
		add_edge(i, n - 1, 0, 1000000000);
	}*/
	//dfs(0);
	int s = 0;
	int t = n - 1;
	use.assign(n, 0);
	//cout << ans << endl;
	bool okkkk = false;
	while(true) {
		vector<ll> pr(2 * n + 3, -1), pos(2 * n + 3, -1), dist(2 * n + 3, ll(1e16));
		vector<edge> pr1(2 * n + 3, edge(-1, -1, -1, -1));
		dist[s] = 0;
		int ps = -1;
		forn (i, n + 1) {
			bool ok = false;
			forn (nu, n)
				for (int j = 0; j < sz(e[nu]); j++) {
					auto v = e[nu][j];
					if (dist[v.v] > dist[nu] + v.cost && v.c - v.f > 0) {
						//cout << v.v << " " << nu << " " << dist[nu] << endl;
						pr[v.v] = nu;
						pos[v.v] = j;
						pr1[v.v] = v;
						dist[v.v] = dist[nu] + v.cost;
						ok = true;
						ps = v.v;
					}
				}
			if (ok && i == n) {
			}
			else
				ps = -1;
		}
		if (ps != -1) {
			//cout << "heh\n";
//			re 0;
			vector<int> uu(n, 0);
			vector<int> p;
			ll mi = 1000000000;
			ll sum = 0;
			while (uu[ps] != 1) {
				uu[ps] = 1;
				ps = pr[ps];
				//cout << ps << " ";
			}
			uu.assign(n, 0);
			//re 0;
			while (uu[ps] != 1) {
				p.push_back(ps);
				uu[ps] = 1;
				mi = min(mi, pr1[ps].c - pr1[ps].f);
				sum += pr1[ps].cost;
				ps = pr[ps];
			}
			ans += sum * ll(mi);
			//cout << sum << " " << mi << endl;
			
			forn (i, sz(p)) {
				//cout << p[i] << " ";
				e[pr[p[i]]][pos[p[i]]].f += mi;
				e[e[pr[p[i]]][pos[p[i]]].v][e[pr[p[i]]][pos[p[i]]].nu].f -= mi;	
			}
			//re 0;
			/*cout << endl;
			if (okkkk)
				break;
			okkkk = true;*/
			continue;
		}
		vector<int> p;
		int nu = t;
		ll mi = 1000000000;
		if (dist[t] >= 0)
			break;
		while (nu != -1) {
			p.push_back(nu);
			if (nu != s) mi = min(mi, pr1[nu].c - pr1[nu].f);
			nu = pr[nu];
		}	
		ans += mi * dist[t];
		//cout << "\n" << dist[t] * mi << endl;
		forn (i, sz(p) - 1) {
			e[pr[p[i]]][pos[p[i]]].f += mi;
			e[e[pr[p[i]]][pos[p[i]]].v][e[pr[p[i]]][pos[p[i]]].nu].f -= mi;
		}
		use.assign(n, 0);
	}
	cout << ans;
	re 0;
}