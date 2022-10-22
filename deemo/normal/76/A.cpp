//It's so unreal..

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 200 + 10;
const int MAXE = 5e4 + 10;

int n, m;
int from[MAXE], to[MAXE];
ll x, y, gx[MAXE], gy[MAXE];
int ed[MAXE], ge, sec[MAXN], sz;
vector<int>	adj[MAXN];
bool vis[MAXN];
int mark[MAXE], tt, hh;

bool cmp(int e1, int e2){return gx[e1] < gx[e2];}

void dfs(int v){
	if (vis[v]){
		ge = 1;
		return;
	}

	vis[v] = 1;
	for (int e:adj[v])
		if (mark[e] ^ tt){
			mark[e] = tt;
			int u = from[e]^to[e]^v;
			sec[sz++] = e;
			dfs(u);
			if (~ge)
				return;
			sz--;
		}
}

void go(int v){
	if (vis[v])	return;
	vis[v] = 1;
	hh++;
	for (int e:adj[v]){
		int u =from[e]^to[e]^v;
		go(u);
	}
}

ll refresh(int e){
	tt++;
	adj[from[e]].push_back(e);
	adj[to[e]].push_back(e);
	memset(vis, 0, sizeof(vis));
	hh = 0;
	go(0);

	memset(vis, 0, sizeof(vis));

	ge = -1;	sz = 0;
	for (int i = 0; ge == -1 && i < n; i++)
		if (!vis[i])
			sz = 0, dfs(i);

	if (~ge){
		memset(vis, 0, sizeof(vis));

		int tv = to[sec[sz - 1]];
		tt++;
		ge = -1;	sz = 0;
		dfs(tv);
		
		pair<int, int>	mx(-1, -1);
		for (int i = sz - 1; ~i; i--)
			mx = max(mx, {gy[sec[i]], sec[i]});
		ge = mx.S;

		for (int i = 0; i < adj[from[ge]].size(); i++)
			if (adj[from[ge]][i] == ge){
				adj[from[ge]].erase(adj[from[ge]].begin() + i);
				break;
			}

		for (int i = 0; i < adj[to[ge]].size(); i++)
			if (adj[to[ge]][i] == ge){
				adj[to[ge]].erase(adj[to[ge]].begin() + i);
				break;
			}
	}

	if (hh != n)	return 3e18;

	ll ms = 0;
	for (int v = 0; v < n; v++)
		for (int z:adj[v])
			ms = max(ms, gy[z] * y);

	return ms;
}

int main(){
	scanf("%d %d", &n, &m);
	scanf("%lld %lld", &x, &y);
	for (int i = 0; i < m; i++)
		scanf("%d %d %lld %lld", &from[i], &to[i], &gx[i], &gy[i]), from[i]--, to[i]--;

	ll ans = 3e18;
	iota(ed, ed + m, 0);
	sort(ed, ed + m, cmp);
	for (int i = 0; i < m; i++)
		if (from[ed[i]] ^ to[ed[i]])
			ans = min(ans, refresh(ed[i]) + gx[ed[i]] * x);

	if (ans > 2e18)
		printf("-1\n");
	else
		printf("%lld\n", ans);
	return 0;
}