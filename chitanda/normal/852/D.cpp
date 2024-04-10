#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back

const int inf = 1e9;
int d[603][603];
bool inq[603];
int N, V, E, K;
int pla[603];
vector<pii> g[603];
bool tag[603];

void spfa(int S){
	memset(d[S], 127, sizeof(d[S]));
	memset(inq, 0, sizeof(inq));
	d[S][S] = 0;
	queue<int> q; q.push(S);
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(pii e : g[t]){
			int v = e.fi, w = e.se;
			if(d[S][t] + w < d[S][v]){
				d[S][v] = d[S][t] + w;
				if(!inq[v]){
					inq[v] = 1;
					q.push(v);
				}
			}
		}
		inq[t] = 0;
	}
}

int a[203][603], p[603];
bool vis[603];

bool dfs(int t){
	for(int i = 1; i <= V; ++i)
		if(!vis[i] && a[t][i]){
			vis[i] = 1;
			if(!p[i] || dfs(p[i])){
				p[i] = t;
				return 1;
			}
		}
	return 0;
}

bool check(int T){
	for(int i = 1; i <= N; ++i)
		for(int v = 1; v <= V; ++v)
			if(d[pla[i]][v] <= T) a[i][v] = 1;
			else a[i][v] = 0;
	int tmp = 0;
	memset(p, 0, sizeof(p));
	for(int i = 1; i <= N; ++i){
		memset(vis, 0, sizeof(vis));
		tmp += dfs(i);
	}
	return tmp >= K;
}

int main(){
	scanf("%d%d%d%d", &V, &E, &N, &K);
	for(int i = 1; i <= N; ++i){
		scanf("%d", pla + i);
		tag[pla[i]] = 1;
	}
	for(int i = 0, u, v, w; i < E; ++i){
		scanf("%d%d%d", &u, &v, &w);
		g[u].pb(mkp(v, w));
		g[v].pb(mkp(u, w));
	}
	for(int i = 1; i <= V; ++i)
		if(tag[i]) spfa(i);
	
	int l = -1, r = 1731311;
	if(!check(r)) puts("-1");
	else{
		while(l + 1 < r){
			int d = (l + r) >> 1;
			if(check(d)) r = d;
			else l = d;
		}
		printf("%d\n", r);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}