#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 70 + 10;
const int MAXE = 1e4 + 10;

int n, m, k;
int from[2 * MAXE], to[2 * MAXE], cap[2 * MAXE], scap[2 * MAXE], prv[2 * MAXE], head[MAXN], ec;
int lv[MAXN], pt[MAXN], q[MAXN * 5];

void add_edge(int u, int v, int uv){
	from[ec] = u, to[ec] = v, cap[ec] = scap[ec] = uv, prv[ec] = head[u];	head[u] = ec++;
	from[ec] = v, to[ec] = v, cap[ec] = scap[ec] = 0, prv[ec] = head[v];	head[v] = ec++;
}

bool bfs(int source, int sink){
	memset(lv, 63, sizeof(lv));
	lv[source] = 0;
	int h = 0, t = 0;
	q[t++] = source;
	while (h < t){
		int v = q[h++];
		for (int e = head[v]; e != -1; e = prv[e])
			if (cap[e] && lv[v] + 1 < lv[to[e]])
				lv[to[e]] = lv[v] + 1, q[t++] = to[e];
	}
	return	lv[sink] < (int)1e6;
}

int dfs(int v, int sink, int flow){
	if (flow == 0 || v == sink)
		return flow;

	int ret = 0;
	for (; pt[v] != -1; pt[v] = prv[pt[v]])
		if (lv[v] + 1 == lv[to[pt[v]]]){
			int x = dfs(to[pt[v]], sink, min(flow, cap[pt[v]]));
			ret += x;
			flow -= x;
			cap[pt[v]] -= x;
			cap[pt[v]^1] += x;
			if (flow == 0)	break;
		}
	return	ret;
}

int dinic(int source, int sink, ld mid){
	for (int e = 0; e < ec; e += 2){
		cap[e^1] = 0;
		if (e < ec - 2){
			if (mid * k < scap[e])
				cap[e] = k;
			else
				cap[e] = (ld)scap[e] / mid;
		}
		else
			cap[e] = scap[e];
	}

	int ret = 0;
	while (bfs(source, sink)){
		memcpy(pt, head, sizeof(head));
		ret += dfs(source, sink, 1e7);
	}
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	memset(head, -1, sizeof(head));
	for (int i = 0; i < m; i++){
		int a, b, c;	cin >> a >> b >> c;	a--, b--;
		add_edge(a, b, c);
	}
	

	ld b = 0, e = 1e9;
	int source = n, sink = n - 1;
	add_edge(source, 0, k);
	for (int i = 0; i < 100; i++){
		ld mid = (b + e)/ 2;
		if (dinic(source, sink, mid) == k)
			b = mid;
		else
			e = mid;
	}
	
	cout << fixed << setprecision(12);
	cout << b * ld(k) << "\n";
	return	0;
}