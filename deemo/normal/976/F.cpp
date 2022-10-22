#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 4e3 + 10;//XXX
const int MAXE = 6e3 * 2 + 50;//XXX

int n1, n2, m;
int head[MAXN], _head[MAXN], pt[MAXN];
int from[MAXE], to[MAXE], cap[MAXE], prv[MAXE], eID[MAXE], ec;
vector<int> ans[MAXN];

void addEdge(int u, int v, int uv, int vu, int e){
	from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u], head[u] = ec, eID[ec++] = e;
	from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v], head[v] = ec, eID[ec++] = e;
}

int q[MAXN], lv[MAXN];
bool bfs(int source, int sink){
	memset(lv, 63, sizeof(lv));
	int h = 0, t = 0;
	lv[source] = 0;
	q[t++] = source;
	while (t^h){
		int v = q[h++];
		for (int e = head[v]; ~e; e = prv[e])
			if (cap[e] && lv[v] + 1 < lv[to[e]]){
				lv[to[e]] = lv[v] + 1;
				q[t++] = to[e];
			}
	}
	return lv[sink] < 1e8;
}

int dfs(int v, int sink, int f = 1e9){
	if (f == 0 || v == sink) return f;

	int ret = 0;
	int &e = pt[v];
	for (; ~e; e = prv[e])
		if (lv[v]+1 == lv[to[e]]){
			int x = dfs(to[e], sink, min(f, cap[e]));
			cap[e] -= x;
			cap[e^1] += x;
			f -= x;
			ret += x;
			if (!f)
				break;
		}
	return ret;
}

void dinic(int source, int sink){
	while (bfs(source, sink)) {
		memcpy(pt, head, sizeof(head));
		dfs(source, sink);
	}
}

int cc[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(head, -1, sizeof(head));
	cin >> n1 >> n2 >> m;
	for (int e = 0; e < m; e++) {
		int a, b; cin >> a >> b, a--, b--;
		cc[a]++, cc[n1+b]++;
		addEdge(a, n1+b, 1, 0, e+1);
	}
	int mn = 1e9;
	for (int i = 0; i < n1+n2; i++) mn = min(mn, cc[i]);
	
	int source = n1+n2, sink = n1+n2+1;
	int _ec = ec;
	memcpy(_head, head, sizeof(head));
	for (int i = mn; ~i; i--){

		for (int v = 0; v < n1; v++)
			if (cc[v] > i)
				addEdge(source, v, cc[v]-i, 0, -1);
		for (int v = n1; v < n1+n2; v++)
			if (cc[v] > i)
				addEdge(v, sink, cc[v]-i, 0, -1);

		dinic(source, sink);
		memset(cc, 0, sizeof(cc));
		for (int e = 0; e < _ec; e += 2)
			if (cap[e])
				ans[i].push_back(eID[e]), cc[from[e]]++, cc[to[e]]++;

		memcpy(head, _head, sizeof(head));
		ec = _ec;
	}

	for (int i = 0; i <= mn; i++) {
		cout << ans[i].size() << " ";
		for (int e:ans[i])
			cout << e << " ";
		cout << "\n";
	}
	return 0;
}