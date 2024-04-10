#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+3, LOG = 18, MOD = 1e9+7;
const double EPS = 1e-15;
int p[MN][LOG], depth[MN];
ll up[MN][LOG];
bool vis[MN];
vector<pii> adj[MN];
struct REE {int a,b,c;};
vector<REE> extra;
ll dist[105][MN];
void dfs (int cur) {
	vis[cur] = 1;
	for (pii i : adj[cur]) if (i.first != p[cur][0]) {
		if (vis[i.first]) extra.push_back({i.first,cur,i.second});
		else {
			p[i.first][0] = cur; depth[i.first] = depth[cur] + 1;
			up[i.first][0] = i.second;
			for (int j = 1; j < LOG; j++)
				if (p[i.first][j-1])
					p[i.first][j] = p[p[i.first][j-1]][j-1], up[i.first][j] = up[i.first][j-1] + up[p[i.first][j-1]][j-1];
			dfs(i.first);
		}
	}
}
void dijkstra (int st, int id) {
	priority_queue<pli,vector<pli>,greater<pli>> pq;
	pq.push({0,st});
	memset(dist[id],0x3f,sizeof dist[id]);
	dist[id][st] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second; ll d = pq.top().first; pq.pop();
		if (d > dist[id][cur]) continue;
		for (pii i : adj[cur]) if (d + i.second < dist[id][i.first]) {
			dist[id][i.first] = d + i.second;
			pq.push({dist[id][i.first],i.first});
		}
	}
}
ll treedist (int a, int b) {
	if (depth[a] < depth[b]) swap(a,b);
	ll ret = 0;
	for (int i = LOG-1; i >= 0; i--)
		if (p[a][i] && depth[p[a][i]] >= depth[b])
			ret += up[a][i], a = p[a][i];
	if (a == b) return ret;
	for (int i = LOG-1; i >= 0; i--)
		if (p[a][i] != p[b][i])
			ret += up[a][i], ret += up[b][i], a = p[a][i], b = p[b][i];
	return ret + up[a][0] + up[b][0];
}
int main() {
	int n,m;
	scanf ("%d %d",&n,&m);
	while (m--) {
		int a,b,c;
		scanf ("%d %d %d",&a,&b,&c);
		adj[a].emplace_back(b,c);
		adj[b].emplace_back(a,c);
	}
	dfs(1);
	for (int i = 0; i < extra.size(); i++) {
		dijkstra(extra[i].a,i<<1);
		dijkstra(extra[i].b,i<<1|1);
	}
	int q;
	scanf ("%d",&q);
	while (q--) {
		int a,b;
		scanf ("%d %d",&a,&b);
		ll ret = treedist(a,b);
		for (int i = 0; i < extra.size(); i++) {
			ret = min(ret,min(dist[i<<1][a]+dist[i<<1|1][b],dist[i<<1][b]+dist[i<<1|1][a])+extra[i].c);
		}
		printf ("%lld\n",ret);
	}
    return 0;
}