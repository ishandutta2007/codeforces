#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int MAXE = (1000 + 30)*2;
const int MAXN = (100 + 50)*2;
const int INF = 1e9 + 2;

int n, m;
int a[MAXN], b[MAXN];
int fs[MAXE];
int from[MAXE], to[MAXE], cap[MAXE], prv[MAXE], head[MAXN], ec;
int ans[MAXN][MAXN];

void addEdge(int u, int v, int uv, int vu = 0){
	fs[ec] = uv;
	from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u], head[u] = ec++;
	fs[ec] = vu;
	from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v], head[v] = ec++;
}

int lv[MAXN], q[MAXN], rec[MAXN], parE[MAXN];
int bfs(int source, int sink) {
	memset(lv, 63, sizeof(lv));
	memset(parE, -1, sizeof(parE));
	memset(rec, 0, sizeof(rec));
	int h = 0, t = 0;
	lv[source] = 0;
	rec[source] = 1e9;
	q[t++] = source;
	while (t-h){
		int v = q[h++];
		for (int e = head[v]; ~e; e = prv[e])
			if (cap[e] && lv[v] + 1 < lv[to[e]]){
				lv[to[e]] = lv[v] + 1;
				parE[to[e]] = e;
				rec[to[e]] = min(cap[e], rec[v]);
				q[t++] = to[e];
			}
	}
	if (lv[sink] > 1e8) return 0;
	int v = sink;
	while (~parE[v]){
		int e = parE[v];
		cap[e] -= rec[sink];
		cap[e^1] += rec[sink];
		v = from[e];
	}
	return rec[sink];
}


int getMaxFlow(int source, int sink){
	int ret = 0, x;
	while (x = bfs(source, sink)) ret += x;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++)	cin >> a[i], s1 += a[i];
	for (int i = 0; i < n; i++)	cin >> b[i], s2 += b[i];
	if (s1 != s2){
		cout << "NO\n";
		return 0;
	}
	
	memset(head, -1, sizeof(head));
	while (m--){
		int u, v;	cin >> u >> v;	u--, v--;
		addEdge(u, v + n, a[u]);
		addEdge(v, u + n, a[v]);
	}

	for (int i = 0; i < n; i++){
		addEdge(i, i + n, a[i]);
		addEdge(2 * n, i, a[i]);
		addEdge(i + n, 2 * n + 1, b[i]);
	}

	if (getMaxFlow(2 * n, 2 * n + 1) != s2)
		cout << "NO\n";
	else{
		cout << "YES\n";
		for (int i = 0; i < ec; i += 2)
			if (to[i] < 2 * n && from[i] < 2 * n)	ans[from[i]][to[i] - n] = fs[i] - cap[i];

		for (int i = 0; i < n; i++){
			for (int j =0 ; j < n; j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}