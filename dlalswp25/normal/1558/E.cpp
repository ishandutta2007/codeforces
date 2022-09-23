#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

int N, M;
int p[1010];
ll X[1010];
int A[1010];
ll B[1010];
int U[2020];
int V[2020];
int up[1010];
bool chk[2020];
bool vst[1010];
bool chkv[1010];
ll mn[2020];
vector<int> adj[1010];

priority_queue<pii, vector<pii>, greater<pii> > pq;

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = par(a); b = par(b);
	p[a] = b;
}

void add(int e) {
	int a = U[e], b = V[e];
	assert(vst[a] || vst[b]);
	if(vst[b]) swap(a, b);
	if(vst[b]) {
		int t = par(b);
		while(t > 1) {
			B[1] += B[t];
			p[t] = 1;
			t = up[t];
			t = par(t);
		}

		t = par(a);
		while(t > 1) {
			B[1] += B[t];
			p[t] = 1;
			t = up[t];
			t = par(t);
		}
	}
	else {
		int t = par(a);
		vst[b] = true;
		up[b] = t;
	}
	chk[e] = true;
}

void dfs(int v) {
	X[v] += B[v];
	for(int i : adj[v]) {
		X[i] += X[v]; dfs(i);
	}
}

void add_edges() {
	for(int i = 1; i <= N; i++) { adj[i].clear(); X[i] = 0; }
	for(int i = 2; i <= N; i++) {
		if(p[i] != i || !vst[i]) continue;
		adj[par(up[i])].push_back(i);
	}
	dfs(1);

	for(int i = 1; i <= M; i++) {
		if(chk[i]) continue;
		int a = U[i], b = V[i];
		a = par(a); b = par(b);
		if(a == b) { chk[i] = true; continue; }
		if(vst[a]) {
			if(mn[i] > A[V[i]] - X[a] + 1) {
				mn[i] = A[V[i]] - X[a] + 1;
				pq.emplace(mn[i], i);
			}
		}
		if(vst[b]) {
			if(mn[i] > A[U[i]] - X[b] + 1) {
				mn[i] = A[U[i]] - X[b] + 1;
				pq.emplace(mn[i], i);
			}
		}
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		int mxv = 0;
		for(int i = 2; i <= N; i++) {
			scanf("%d", &A[i]);
			if(A[mxv] < A[i]) mxv = i;
		}
		B[1] = 0;
		for(int i = 2; i <= N; i++) scanf("%lld", &B[i]);
		for(int i = 1; i <= M; i++) scanf("%d%d", &U[i], &V[i]);
		while(pq.size()) pq.pop();
		for(int i = 1; i <= N; i++) p[i] = i;
		for(int i = 1; i <= N; i++) {
			chkv[i] = vst[i] = false;
			X[i] = up[i] = 0;
		}
		for(int i = 1; i <= M; i++) chk[i] = false;

		vst[1] = true;

		ll ans = 0;

		for(int i = 1; i <= M; i++) mn[i] = 1LL << 60;

		add_edges();

		while(pq.size()) {
			if(vst[mxv]) break;
			pii t = pq.top(); pq.pop();
			// printf("%lld %d\n", t.first, t.second);
			if(t.first > mn[t.second] || chk[t.second]) continue;
			if(par(U[t.second]) == par(V[t.second])) {
				chk[t.second] = true;
				continue;
			}
			ans = max(ans, t.first);
			add(t.second);
			add_edges();
		}

		assert(vst[mxv]);
		printf("%lld\n", ans);
	}
	return 0;
}