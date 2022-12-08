#include <bits/stdc++.h>
using namespace std;
struct edge {
	int v, f, c, nxt;
} e[10010];
int tot = 1, head[110];
inline void addedge(int u, int v, int f, int c) {
	e[++tot] = edge{v, f, c, head[u]};
	head[u] = tot;
	e[++tot] = edge{u, 0, -c, head[v]};
	head[v] = tot;
}
int dis[110], inque[110], pre[110];
int ansc, s, t, n, m;
inline int spfa() {
	queue<int> q;
	q.push(s);
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	inque[s] = 1;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		inque[now] = 0;
		for(int i = head[now]; i; i = e[i].nxt) {
			if(dis[e[i].v] > dis[now] + e[i].c && e[i].f) {
				dis[e[i].v] = dis[now] + e[i].c;
				pre[e[i].v] = i;
				if(!inque[e[i].v]) inque[e[i].v] = 1, q.push(e[i].v);
			}
		}
	}
	if(dis[t] > 1e9) return 0;
	int minf = 1e9;
	for(int i = t; i != s; i = e[pre[i] ^ 1].v) {
		minf = min(minf, e[pre[i]].f);
	}
	for(int i = t; i != s; i = e[pre[i] ^ 1].v) {
		e[pre[i]].f -= minf;
		e[pre[i] ^ 1].f += minf;
	}
	ansc += minf * dis[t];
	return 1;
}
int flow[110], tmp;
int main() {
	cin >> n >> m;
	addedge(n, 1, 1e9, 0);
	for(int i = 1; i <= m; i++) {
		int u, v, f, c;
		cin >> u >> v >> c >> f;
		if(f < c) {
			addedge(u, v, c - f, 1);
			addedge(v, u, f, 1);
			addedge(u, v, 1e9, 2);
			flow[u] -= f, flow[v] += f;
		}
		else {
			tmp += f - c;
			addedge(u, v, f - c, 0);
			addedge(v, u, c, 1);
			addedge(u, v, 1e9, 2);
			flow[u] -= c, flow[v] += c;
		}
	}
	s = 0, t = n + 1;
	for(int i = 1; i <= n; i++) {
		if(flow[i] > 0) addedge(s, i, flow[i], 0);
		else addedge(i, t, -flow[i], 0);
	}
	while(spfa());
	return cout << ansc + tmp << endl, 0;
}