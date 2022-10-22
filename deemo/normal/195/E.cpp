#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, par[MAXN], sz[MAXN];
ll sm, sec[MAXN], gec[MAXN], depth[MAXN], ss[MAXN];
vector<int>	adj[MAXN];

int get_par(int v){return par[v] == -1?v:get_par(par[v]);}

void go(int v, ll a, ll b){
	depth[v] = ((depth[v] + a - b) % MOD + MOD) % MOD;
	for (int u:adj[v])	go(u, a, b);
}

void merge(int u, int v){
	if (sz[u] < sz[v])	swap(u, v);
		
	go(v, ss[v], ss[u]);
	sz[u] += sz[v];
	par[v] = u;
	adj[u].push_back(v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(par, -1, sizeof(par));
	fill(sz, sz + n, 1);
	for (int i = 0; i < n; i++){
		int t;	cin >> t;
		for (int j = 0; j < t; j++){
			int v; ll x;	cin >> v >> x, v--;
			int p = get_par(v);
			ll de = ((depth[v] + ss[p] + x) % MOD + MOD) % MOD;
			sm = (sm + de) % MOD;
			ss[p] = (ss[p] + de) % MOD;
			merge(get_par(i), p);
		}
	}

	cout << sm << "\n";
	return 0;
}