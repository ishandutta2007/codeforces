#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN = 2e4 + 10;
const int MAXE = 4e4 + 10;
const int INF = 1e9;

int n, b, q, t[MAXN], x[MAXN], tt[MAXN], zz[10];
vector<int>	sec;
int lv[MAXN], que[MAXN], p[MAXN];
int head[MAXN], from[2 * MAXE], to[2 * MAXE], cap[2 * MAXE], prv[2 * MAXE], ec;

void add_edge(int u, int v, int uv, int vu = 0){
	from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u];	head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v];	head[v] = ec++;
}

bool bfs(int source, int sink){
	memset(lv, 63, sizeof(lv));
	lv[source] = 0;
	int hd = 0, tale = 0;
	que[tale++] = source;
	while (hd < tale){
		int v = que[hd++];
		for (int e = head[v]; e != -1; e = prv[e])
			if (cap[e] && lv[to[e]] > lv[v] + 1){
				lv[to[e]] = lv[v] + 1;
				que[tale++] = to[e];
			}
	}
	return	lv[sink] < INF;
}

int dfs(int v, int sink, int flow = INF){
	if (flow == 0 || sink == v)	return	flow;
	int ret = 0;
	for (; p[v] != -1; p[v] = prv[p[v]])
		if (lv[to[p[v]]] == lv[v] + 1){
			int xx = dfs(to[p[v]], sink, min(flow, cap[p[v]]));
			ret += xx;
			flow -= xx;
			cap[p[v]] -= xx;
			cap[p[v]^1] += xx;
			if (flow == 0)	break;
		}
	
	return	ret;	
}

int max_flow(int source, int sink){
	int ret = 0;
	while (bfs(source, sink))
		memcpy(p, head, sizeof(head)), ret += dfs(source, sink);
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> b >> q;

	memset(tt, -1, sizeof(tt));
	q++;	q++;
	for (int i = 0; i < q; i++){
		if (i == q - 2)
			x[i] = b, t[i] = n;
		else if (i == q - 1)
			x[i] = 0, t[i] = 0;
		else
			cin >> x[i] >> t[i];

		if (tt[x[i]] != -1 && tt[x[i]] != t[i]){
			cout << "unfair\n";
			return	0;
		}
		tt[x[i]] = t[i];
		sec.push_back(x[i]);
	}
	sort(sec.begin(), sec.end());
	sec.resize(unique(sec.begin(), sec.end()) - sec.begin());
	for (int i = 1; i < (int)sec.size(); i++)
		if (tt[sec[i]] < tt[sec[i - 1]]){
			cout << "unfair\n";
			return	0;
		}

	memset(head, -1, sizeof(head));
	int source = (int)sec.size() + 5 + 4;
	int sink = source + 1;
	for (int i = 1; i < (int)sec.size(); i++){
		add_edge(i + 5, sink, tt[sec[i]] - tt[sec[i - 1]]);

		memset(zz, 0, sizeof(zz));
		for (int j = sec[i - 1] + 1; j <= sec[i]; j++)	zz[j % 5]++;
		for (int j = 0; j < 5; j++)	add_edge(j, i + 5, zz[j]);
	}
	for (int i = 0; i < 5; i++)	add_edge(source, i, n/5);
	if (max_flow(source, sink) == n)
		cout << "fair\n";
	else
		cout << "unfair\n";
	return	0;	
}