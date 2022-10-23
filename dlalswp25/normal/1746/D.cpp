#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, K;
vector<int> adj[202020];
ll A[202020];
map<pii, ll> mp;

void init(int v) {
	for(int i : adj[v]) {
		A[i] += A[v];
		init(i);
	}
}

ll dfs(int v, int k) {
	if(mp.find({v, k}) != mp.end()) return mp[{v, k}];
	ll ret = 0;
	int ch = adj[v].size();
	if(!ch) return k * A[v];
	int q = k / ch, r = k % ch;
	vector<ll> X;
	for(int i : adj[v]) {
		ll t = dfs(i, q);
		ret += t;
		if(r) {
			ll s = dfs(i, q + 1);
			X.push_back(s - t);
		}
	}
	sort(X.begin(), X.end());
	reverse(X.begin(), X.end());
	for(int i = 0; i < r; i++) ret += X[i];
	return mp[{v, k}] = ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 2; i <= N; i++) {
			int p; scanf("%d", &p);
			adj[p].push_back(i);
		}
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		init(1);
		mp.clear();
		printf("%lld\n", dfs(1, K));
	}
	return 0;
}