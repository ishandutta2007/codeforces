#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second


const int N = 50 + 1;
const int C = 130;
const int MAXN = (C+2) * N;
const int MAXE = 1e7;

int from[MAXE], to[MAXE], cap[MAXE], ww[MAXE], prv[MAXE], head[MAXN], ec;

void addEdge(int u, int v, int uv, int w, int vu = 0){
	from[ec] = u, to[ec] = v, cap[ec] = uv, ww[ec] = w, prv[ec] = head[u], head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = vu, ww[ec] = -w, prv[ec] = head[v], head[v] = ec++;
}

int lv[MAXN], q[MAXN], rec[MAXN], parE[MAXN];
bool mark[MAXN];
pii spfa(int source, int sink) {
	memset(lv, 63, sizeof(lv));
	memset(parE, -1, sizeof(parE));
	memset(rec, 0, sizeof(rec));
	memset(mark, 0, sizeof(mark));
	int h = 0, t = 0;
	lv[source] = 0;
	rec[source] = 1e9;
	q[t++] = source;
	mark[source] = true;
	while (t^h){
		int v = q[h++];
		if (h == MAXN) h = 0;
		mark[v] = false;
		for (int e = head[v]; ~e; e = prv[e])
			if (cap[e] && lv[v] + ww[e] < lv[to[e]]){
				lv[to[e]] = lv[v] + ww[e];
				parE[to[e]] = e;
				rec[to[e]] = min(cap[e], rec[v]);
				if (!mark[to[e]]){
					q[t++] = to[e];
					if (t == MAXN) t = 0;
					mark[to[e]] = true;
				}
			}
	}
	if (lv[sink] > 1e8) return {0, 0};

	int v = sink;
	int totW = 0;
	while (~parE[v]){
		int e = parE[v];
		cap[e] -= rec[sink];
		cap[e^1] += rec[sink];
		totW += ww[e] * rec[sink];
		v = from[e];
	}
	return {rec[sink], totW};
}

pii getMCMF(int source, int sink){
	pii ret(0, 0), x;
	while (true){
		x = spfa(source, sink);
		if (!x.F) break;
		ret.F += x.F;
		ret.S += x.S;
	}
	return ret;
}

int n, m, k, c, d, a[MAXN];
vector<int> adj[MAXN];

void solve() {
	memset(head, -1, sizeof(head));
	cin >> n >> m >> k >> c >> d;
	for (int i = 0; i < k; i++) cin >> a[i], a[i]--;
	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int source = MAXN-2, sink = MAXN-1;
	for (int i = 0; i < k; i++)
		addEdge(source, a[i], 1, 0);
	for (int i = 0; i+1 < C; i++) {
		for (int v = 0; v < n; v++) {
			for (int u: adj[v])
				for (int t = 1; t <= k; t++)
					addEdge(i*n+v, (i+1)*n+u, 1, (2*t-1)*d + c);
			addEdge(i*n+v, (i+1)*n+v, k, c);
		}
		addEdge((i+1)*n, sink, k, 0);
	}
	auto ans = getMCMF(source, sink);
	cout << ans.S << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}