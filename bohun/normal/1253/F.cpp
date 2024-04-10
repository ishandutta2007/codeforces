#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define int long long
 
using namespace std;

const int nax = 3e5 + 1111;
const long long inf = 1e18;

int n, m, k, q;
pair<int, int> edge[nax];
int cost[nax];
int a, b;
int kol[nax];
ll dis[nax];
int odw[nax];
vector <pair<int, int>> v[nax];
priority_queue <pair<pair<ll, int>, int>> Q;

ll out[nax];
vector <pair<ll, int>> elo;

vector <pair<int, int>> zap[nax];

int p[nax];
vector <int> nodes[nax];

int find(int x) {
	if(x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void unia(int x, int y, int koszt) {
	x = find(x);
	y = find(y);
	if(x != y) {
		if(ss(nodes[x]) > ss(nodes[y]))
			swap(x, y);
		p[x] = y;
		for(auto it : nodes[x])
			nodes[y].pb(it);
		for(auto it: nodes[x]) {
			for(auto i : zap[it]) {
				if(find(i.fi) == y && out[i.se] == -1)
					out[i.se] = koszt;
			}
		}
	}
}
				
	

int32_t main() {
	scanf("%lld %lld %lld %lld", &n, &m, &k, &q);
	FOR(i, m) {
		scanf("%lld %lld %lld", &a, &b, &cost[i]);
		edge[i] = mp(a, b);
		v[a].pb(mp(b, cost[i]));
		v[b].pb(mp(a, cost[i]));
	}
	FOR(i, n) 
		dis[i] = inf;
	FOR(i, k) {
		dis[i] = 0;
		kol[i] = i;
		Q.push(mp(mp(0, i), i));
	}
	
	while(!Q.empty()) {
		int ja = Q.top().fi.se;
		int JA = Q.top().se;
		Q.pop();
		if(odw[ja])
			continue;
		odw[ja] = 1;
		kol[ja] = JA;
		for(auto it : v[ja]) {
			ll droga = dis[ja] + it.se;
			if(droga < dis[it.fi]) {
				dis[it.fi] = droga;
				Q.push(mp(mp(-droga, it.fi), JA));
			}
		}
	}
	
	FOR(i, m) {
		if(kol[edge[i].fi] != kol[edge[i].se])
			elo.pb(mp(dis[edge[i].fi] + dis[edge[i].se] + cost[i], i));
		else
			elo.pb(mp(max(dis[edge[i].fi], dis[edge[i].se]), i));
	}
	sort(elo.begin(), elo.end());
	
	FOR(i, q) {
		scanf("%lld %lld", &a, &b);
		zap[a].pb(mp(b, i));
		zap[b].pb(mp(a, i));
		out[i] = -1;
	}
	
	FOR(i, n) {
		nodes[i].pb(i);
		p[i] = i;
	}
	for(int i = 0; i < ss(elo); ++i) {
		unia(edge[elo[i].se].fi, edge[elo[i].se].se, elo[i].fi);
	}
	FOR(i, q) printf("%lld\n", out[i]);
	
	
	
	
	
		
		
	
	
	
	return 0;
}