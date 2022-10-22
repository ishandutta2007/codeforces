#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e4 + 10;
const int LOG = 15;
const int INF = 1e9;
const int MAXV = (LOG+3)*MAXN;
const int MAXE = MAXV*6;

int n, q, uu[MAXN], vv[MAXN];
int from[MAXE], to[MAXE], cap[MAXE], head[MAXV], pt[MAXV], prv[MAXE], ec, curNode;
int par[LOG][MAXN], id[LOG][MAXN], depth[MAXN];
vector<int> adj[MAXN];

void addEdge(int u, int v, int uv, int vu = 0){
	from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u], head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v], head[v] = ec++;
}

void plant(int v, int pe = -1, int pv = -1, int de = 0){
	depth[v] = de;
	par[0][v] = pv;
	id[0][v] = curNode++;
	if (~pe)
		addEdge(id[0][v], q+pe, INF);
	for (int e:adj[v])
		if (e^pe){
			int u = uu[e]^vv[e]^v;
			plant(u, e, v, de + 1);
		}
}

void init(){
	for (int w = 1; w < LOG; w++)
		for (int v = 0; v < n; v++){
			id[w][v] = curNode++;
			if (~par[w - 1][v])
				par[w][v] = par[w-1][par[w-1][v]], addEdge(id[w][v], id[w-1][v], INF), addEdge(id[w][v], id[w-1][par[w-1][v]], INF);
			else
				par[w][v] = par[w-1][v], addEdge(id[w][v], id[w-1][v], INF);
		}
}

void lca(int u, int v, int ind){
	if (depth[u] < depth[v]) swap(u, v);
	for (int w = LOG-1; ~w; w--)
		if (depth[u] - (1<<w) >= depth[v])
			addEdge(ind, id[w][u], INF), u = par[w][u];
	if (u == v) return;

	for (int w = LOG-1; ~w; w--)
		if (par[w][u] == par[w][v])
			addEdge(ind, id[w][u], INF), addEdge(ind, id[w][v], INF), u = par[w][u], v = par[w][v];
	addEdge(ind, id[0][u], INF);
	addEdge(ind, id[0][v], INF);
}

int que[MAXV], lv[MAXV];
bool bfs(int source, int sink){
	memset(lv, 63, sizeof(lv));
	int h = 0, t = 0;
	lv[source] = 0, que[t++] = source;
	while (t-h){
		int v = que[h++];
		for (int e = head[v]; ~e; e = prv[e])
			if (cap[e] && lv[v] + 1 < lv[to[e]]){
				lv[to[e]] = lv[v] + 1;
				que[t++] = to[e];
			}
	}
	return lv[sink] < 1e8;
}

int dfs(int v, int sink, int f){
	if (v == sink || f == 0) return f;

	int ret = 0;
	for (; ~pt[v]; pt[v]=prv[pt[v]])
		if (lv[v] + 1 == lv[to[pt[v]]]){
			int x = dfs(to[pt[v]], sink, min(f, cap[pt[v]]));
			f -= x;
			ret += x;
			cap[pt[v]] -= x;
			cap[pt[v]^1] += x;
			if (f == 0) break;
		}
	return ret;
}

int go(int source, int sink){
	int ret = 0;
	while (bfs(source, sink)){
		memcpy(pt, head, sizeof(head));
		ret += dfs(source, sink, INF);
	}
	return ret;
}

int sec[MAXN], cc;
int main(){
	memset(head, -1, sizeof(head));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++){
		cin >> uu[i] >> vv[i], uu[i]--, vv[i]--;
		adj[uu[i]].push_back(i);
		adj[vv[i]].push_back(i);
	}
	curNode = q+(n-1);
	int source = curNode++, sink = curNode++;
	for (int i = 0; i < q; i++) addEdge(source, i, 1);
	for (int i = 0; i < n-1; i++) addEdge(q+i, sink, 1);

	plant(0);
	init();
	for (int i = 0; i < q; i++){
		int u, v; cin >> u >> v, u--, v--;
		lca(u, v, i);
	}

	cout << go(source, sink) << "\n";
	int cur = 0;
	for (int i = 0; i < q; i++)
		if (lv[i] > 1e8)
			sec[cc++] = i;

	cout << cc << " ";
	for (int i = 0; i < cc; i++)
		cout << sec[i]+1 << " ";
	cout << "\n";

	cc = 0;
	for (int i = 0; i < n-1; i++)
		if (lv[i+q] < 1e8)
			sec[cc++] = i;
	cout << cc << " ";
	for (int i = 0; i < cc; i++)
		cout << sec[i]+1 << " ";
	cout << "\n";
	return 0;
}