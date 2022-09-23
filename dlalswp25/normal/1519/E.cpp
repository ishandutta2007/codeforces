#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int id;
map<pll, int> mp;
vector<pii> adj[404040];
vector<pii> ans;
bool vst[404040];
int tre[404040];
bool chk[202020];

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }
pll f(pll x) {
	ll g = gcd(x.first, x.second);
	return pll(x.first / g, x.second / g);
}

void dfs(int v) {
	vst[v] = true;
	for(pii i : adj[v]) {
		if(vst[i.first]) continue;
		tre[i.first] = i.second;
		dfs(i.first);
	}
}

void solve(int v) {
	vst[v] = true;
	for(pii i : adj[v]) {
		if(vst[i.first]) continue;
		solve(i.first);
	}

	vector<int> edges;
	for(pii i : adj[v]) {
		if(chk[i.second] || i.second == tre[v]) continue;
		edges.push_back(i.second);
	}

	for(int i = 1; i < edges.size(); i += 2) {
		int x = edges[i - 1], y = edges[i];
		ans.emplace_back(x, y);
		chk[x] = chk[y] = true;
	}

	if(tre[v] && (edges.size() & 1)) {
		int x = tre[v], y = edges.back();
		ans.emplace_back(x, y);
		chk[x] = chk[y] = true;
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		pll u = pll((ll)b * c, (ll)d * (a + b));
		u = f(u);
		pll v = pll((ll)b * (c + d), (ll)a * d);
		v = f(v);

		int i1, i2;
		if(mp.find(u) != mp.end()) i1 = mp[u];
		else i1 = mp[u] = ++id;
		if(mp.find(v) != mp.end()) i2 = mp[v];
		else i2 = mp[v] = ++id;
		adj[i1].emplace_back(i2, i);
		adj[i2].emplace_back(i1, i);
	}

	for(int i = 1; i <= id; i++) {
		if(!vst[i]) dfs(i);
	}

	for(int i = 1; i <= id; i++) vst[i] = false;
	for(int i = 1; i <= id; i++) {
		if(!vst[i]) solve(i);
	}

	printf("%d\n", ans.size());
	for(pii i : ans) printf("%d %d\n", i.first, i.second);

	return 0;
}