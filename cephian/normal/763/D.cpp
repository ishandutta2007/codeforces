#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned long long ll;

ll hsh(ll x) {
	// return x+1;
	x ^= 0xea2af3bf03fcb7fa;
	x ^= x >> 33;
	x *= 0xff51afd7ed558ccd;
	x ^= x >> 33;
	x *= 0xc4ceb9fe1a85ec53;
	x ^= x >> 33;
	return x;
}

const int N = 1e5+5;
int n;
map<pii,ll> h;
ll hs[N];
vvi T;

ll dfs1(int u, int v) {
	hs[v] = 0;
	for(int w : T[v]) {
		if(w == u) continue;
		hs[v] += dfs1(v,w);
	}
	if(u != -1) return h[pii(u,v)] = hsh(hs[v]);
	return 0;
}

void dfs2(int u, int v, ll ph) {
	h[pii(v,u)] = ph;
	for(int w : T[v]) {
		if(w == u) continue;
		dfs2(v,w,hsh(hs[v] + ph - h[pii(v,w)]));
	}
}

map<ll,int> f; 

void add(int u, int v, int d) {
	ll hs = h[pii(u,v)];
	f[hs] += d;
	if(f[hs] == 0) f.erase(hs);
}

void dfs3(int u, int v) {
	if(u != -1) add(u,v,1);
	for(int w : T[v]) {
		if(u == w) continue;
		dfs3(v,w);
	}
}

int best_vert = 0, best_val;

void dfs4(int u, int v) {
	if(u != -1) {
		add(v,u,1);
		add(u,v,-1);
	}
	if(f.size() > best_val) {
		best_val = f.size();
		best_vert = v;
	}
	for(int w : T[v]) {
		if(w == u) continue;
		dfs4(v,w);
	}
	if(u != -1) {
		add(v,u,-1);
		add(u,v,1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	T = vvi(n,vi());
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		--u; --v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs1(-1,0);
	for(int v : T[0])
		dfs2(0,v,hsh(hs[0]-h[pii(0,v)]));
	dfs3(-1,0);
	best_val = f.size();
	dfs4(-1,0);
	cout << best_vert+1 << endl;
	return 0;
}