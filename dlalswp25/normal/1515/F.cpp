#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M, X;
ll A[303030];
vector<pii> adj[303030];
set<pll> S;

int p[303030];

int par(int x) {
	if(p[x] == x) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = par(a); b = par(b);
	if(a == b) return;
	if(adj[a].size() > adj[b].size()) swap(a, b);
	for(auto i : adj[a]) adj[b].emplace_back(i);
	p[a] = b;
	S.erase(S.find(pll(A[a], a)));
	S.erase(S.find(pll(A[b], b)));
	A[b] += A[a];
	A[b] -= X;
	S.insert(pll(A[b], b));
}

int main() {
	scanf("%d%d%d", &N, &M, &X);
	ll tot = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		tot += A[i];
	}

	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
	}

	if(tot < (ll)(N - 1) * X) { puts("NO"); return 0; }

	for(int i = 1; i <= N; i++) {
		p[i] = i;
		S.insert(pll(A[i], i));
	}

	puts("YES");

	for(int i = 1; i < N; i++) {
		pll t = *(--S.end());
		int x = t.second;
		while(1) {
			assert(adj[x].size() > 0);
			pii j = adj[x].back();
			if(par(j.first) == par(x)) { adj[x].pop_back(); continue; }
			printf("%d\n", j.second);
			unite(j.first, x);
			break;
		}
	}

	return 0;
}