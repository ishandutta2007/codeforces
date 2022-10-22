#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, m, k, q;
vector<pii> adj[MAXN];
ll dist[MAXN];
int par[MAXN];
set<pair<ll, int>> st;
pair<pii, ll> sec[MAXN]; int sz;

void update(int v){
	for (auto e: adj[v]) {
		int u = e.F, w = e.S;
		if (dist[v] + w < dist[u]){
			st.erase({dist[u], u});
			dist[u] = dist[v] + w;
			par[u] = (v < k? v: par[v]);
			st.insert({dist[u], u});
		}
	}
}

void dijk(int v){
	memset(dist, 63, sizeof(dist));
	dist[v] = 0;
	par[v] = -1;
	st.insert({dist[v], v});

	while (st.size()){
		v = st.begin()->S;
		st.erase(st.begin());
		if (v < k && ~par[v])
			sec[sz++] = {{v, par[v]}, dist[v]}, dist[v] = 0;
		update(v);
	}
}

int lo[MAXN], hi[MAXN], mid[MAXN];
int uu[MAXN], vv[MAXN];
pii gec[MAXN];

int getPar(int v){return par[v]==v? v: par[v]=getPar(par[v]);}

bool cmp(pair<pii, ll> a, pair<pii, ll> b){return a.S < b.S;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k >> q;
	while (m--){
		int u, v, w; cin >> u >> v >> w, u--, v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dijk(0);
	sort(sec, sec + sz, cmp);
	for (int i = 0; i < q; i++) cin >> uu[i] >> vv[i], uu[i]--, vv[i]--, lo[i] = 0, hi[i] = sz;

	bool changed = true;
	while (changed){
		changed = false;
		int tt = 0;
		for (int i = 0; i < q; i++)
			if (lo[i]+1 < hi[i]){
				changed = true;
				mid[i] = lo[i] + hi[i] >> 1;
				gec[tt++] = {mid[i], i};
			}

		sort(gec, gec + tt);
		iota(par, par + n, 0);
		int cur = 0;
		for (int i = 0; i < tt; i++){
			while (cur < gec[i].F){
				par[getPar(sec[cur].F.F)] = getPar(sec[cur].F.S);
				cur++;
			}
			int id = gec[i].S;
			if (getPar(uu[id]) != getPar(vv[id]))
				lo[id] = mid[id];
			else
				hi[id] = mid[id];
		}
	}
	for (int i = 0; i < q; i++)
		cout << sec[lo[i]].S << "\n";
	return 0;
}