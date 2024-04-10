#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

const int MaxN = 301234;
int n, m, iq[MaxN], in[MaxN], showtime[MaxN], siz[MaxN], ans[MaxN]; pii a[MaxN], dis[MaxN]; map<pii, int> id;
set<int> e[MaxN]; VI g[MaxN], q[MaxN];

void addEdge(int u, int v) {
//	cout << u << " -- " << v << endl;
	e[u].insert(v); e[v].insert(u);
}

VI cur; int sz[MaxN], vs[MaxN], son[MaxN], mark;
void dfs(int x, int fa = 0) {
	cur.pb(x); sz[x] = 1; son[x] = 0; vs[x] = mark;
	for (auto y : e[x]) {
		if(y != fa) {
			dfs(y, x); sz[x] += sz[y]; 
			cmax(son[x], sz[y]);
		} 
	}
}

int A[MaxN], B[MaxN]; 
void solve(int x) {
	cur.clear(); ++mark; dfs(x, 0);

	int c = 0;
	for (auto y : cur) {
		cmax(son[y], sz[x] - sz[y]);
		if(!c || son[y] < son[c]) c = y;
	} 
	for (auto y : cur) if(y ^ c){
		for (int i = 0; i < siz[y]; i++)
			dis[y + i] = mp(n + 1, 0);
	}
	queue<int> Q;
	for (int i = 0; i < siz[c]; i++)
		dis[c + i] = mp(0, i + 1), Q.push(c + i);
	while(!Q.empty()) {
		int c = Q.front(); Q.pop();
		for (auto b : g[c]) {
			if(vs[in[b]] != mark) continue;
			if(cmin(dis[b], mp(dis[c].fi + 1, dis[c].se)))
				Q.push(b);
		} 
	}
//	cout << c << "!!\n";
	
	vector<pii> ev, qv;
	for (auto y : cur) {
		for (int i = 0; i < siz[y]; i++) {
			if(showtime[y + i] <= m)
				ev.pb(mp(showtime[y + i], y + i));
			for (auto x : q[y + i])
				qv.pb(mp(x, y + i));
		}
	}
	sort(ALL(ev)); sort(ALL(qv));
	for (int i = 1; i <= siz[c]; i++) A[i] = B[i] = 1e9;
	int ei = 0;
	for (auto i : qv) {
		for (; ei < SZ(ev) && ev[ei].fi < i.fi; ei++) {
			pii u = ev[ei];
			for (int p = dis[u.se].se; p <= siz[c]; p += p & -p)
				cmin(A[p], dis[u.se].fi - dis[u.se].se);
			for (int p = dis[u.se].se; p; p -= p & -p)
				cmin(B[p], dis[u.se].fi + dis[u.se].se);
		}
		for (int p = dis[i.se].se; p; p -= p & -p)
			cmin(ans[i.fi], A[p] + dis[i.se].fi + dis[i.se].se);
		for (int p = dis[i.se].se; p <= siz[c]; p += p & -p)
			cmin(ans[i.fi], B[p] + dis[i.se].fi - dis[i.se].se);
	}
	for (auto y : e[c]) e[y].erase(c); for(auto y : e[c]) solve(y);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d%d", &a[i].fi, &a[i].se);
	sort(a + 1, a + n + 1);
	
	scanf("%d", &m);
	for (int i = 1, j; i <= n; i++) {
		if(a[i].fi == a[i - 1].fi && a[i].se == a[i - 1].se + 1) {
			in[i] = in[i - 1]; g[i].pb(i - 1); g[i - 1].pb(i);
		} else 
			in[i] = i;
		if(j = id[mp(a[i].fi - 1, a[i].se)]) {
			g[i].pb(j); g[j].pb(i); addEdge(in[i], in[j]); // multiple edges alert 
		}
		++siz[in[i]]; id[a[i]] = i; showtime[i] = m + 1;
	}
	
	for (int i = 1; i <= m; i++) {
		int t, x, y; scanf("%d%d%d", &t, &x, &y);
		if(t == 1) {
			cmin(showtime[id[mp(x, y)]], i);
		} else {
			q[id[mp(x, y)]].pb(i); iq[i] = 1;
		}
		ans[i] = n + 1;
	}
	solve(1);
	for (int i = 1; i <= m; i++) 
		if(iq[i])
			printf("%d\n", ans[i] > n ? -1 : ans[i]);
	return 0;
}