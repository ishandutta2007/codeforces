#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
vector<int> adj[202020];

ll W[202020];

bool chk[202020];
int dfn[202020];
bool bck[202020];

int ID;

ll ans, mx;

ll calc(int now, int par) {
	ll ret = 0;
	for(int i : adj[now]) {
		if(i == par) continue;
		ret = max(ret, calc(i, now));
	}
	return ret + W[now];
}

bool init(int now, int par) {
	dfn[now] = ++ID;
	bck[now] = false;
	for(int i : adj[now]) {
		if(i == par) continue;
		if(dfn[i]) { bck[now] = true; continue; }
		bck[now] |= init(i, now);
	}
	return bck[now];
}

void dfs(int now, int par) {
	chk[now] = true;
	if(!bck[now]) {
		mx = max(mx, calc(now, par)); return;
	}
	ans += W[now];
	for(int i : adj[now]) {
		if(i == par) continue;
		if(chk[i]) continue;
		dfs(i, now);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%lld", &W[i]);
	for(int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int s; scanf("%d", &s);

	init(s, 0);
	dfs(s, 0);

	printf("%lld\n", ans + mx);

	return 0;
}