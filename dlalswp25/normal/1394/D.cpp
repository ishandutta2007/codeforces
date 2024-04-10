#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll D[202020];
ll E[202020];
vector<int> adj[202020];
int T[202020];
int H[202020];

ll ans;

void dfs(int v, int p) {
	int l = 0, h = 0;
	priority_queue<ll, vector<ll>, greater<ll> > pq;

	ll sum = 0;
	for(int i : adj[v]) {
		if(i == p) continue;
		dfs(i, v);

		if(H[i] >= H[v]) { h++; sum += D[i]; }
		else { l++; sum += E[i]; }

		if(H[i] == H[v]) pq.push(E[i] - D[i]);
	}

	// printf("%d %lld\n", v, sum);
	// printf("h l %d %d\n", h, l);

	D[v] = sum + max(h - 1, l) * (ll)T[v] + T[v];
	E[v] = sum + max(h, l - 1) * (ll)T[v] + T[v];
	if(v == 1) ans = sum + max(h, l) * (ll)T[v];
	while(pq.size()) {
		ll x = pq.top(); pq.pop();
		sum += x;
		h--; l++;
		D[v] = min(D[v], sum + max(h - 1, l) * (ll)T[v] + T[v]);
		E[v] = min(E[v], sum + max(h, l - 1) * (ll)T[v] + T[v]);
		if(v == 1) ans = min(ans, sum + max(h, l) * (ll)T[v]);
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &T[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &H[i]);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	// for(int i = 1; i <= N; i++) printf("%lld ", D[i]); puts("");
	// for(int i = 1; i <= N; i++) printf("%lld ", E[i]); puts("");
	printf("%lld\n", ans);

	return 0;
}