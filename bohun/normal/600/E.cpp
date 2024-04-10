#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;
const int nax = 1e5 + 111;

int n;
int col[nax];
int a, b;
vector <int> v[nax];
int siz[nax];
int in[nax];
int out[nax];
int Pre = 1;
int ord[nax];

void dfs(int u, int p) {
	siz[u] = 1;
	ord[Pre] = u;
	in[u] = Pre++;
	for(auto it: v[u])
		if(it != p) {
			dfs(it, u);
			siz[u] += siz[it];
		}
	out[u] = Pre - 1;
}

ll ans[nax];
int ile[nax];
ll sum[nax];
multiset <int> secik;

void add(int u) {
	if(ile[col[u]] > 0) {
		sum[ile[col[u]]] -= col[u];
		secik.erase(secik.find(ile[col[u]]));
	}
	ile[col[u]] += 1;
	sum[ile[col[u]]] += col[u];
	secik.insert(ile[col[u]]);
}

void era(int u) {
	sum[ile[col[u]]] -= col[u];
	secik.erase(secik.find(ile[col[u]]));
	ile[col[u]] -= 1;
	
	if(ile[col[u]] > 0) {
		sum[ile[col[u]]] += col[u];
		secik.insert(ile[col[u]]);
	}
}

void solve(int u, int p, bool keep = 1) {
	for(auto &it: v[u]) {
		if(it != p) {
			if(v[u][0] == p || siz[v[u][0]] < siz[it])
				swap(v[u][0], it);
		}
	}
	
	for(auto it: v[u]) 
		if(it != p && it != v[u][0])
			solve(it, u, 0);
	
	if(v[u][0] != p)
		solve(v[u][0], u, 1);
	
	add(u);
	for(auto it: v[u]) 
		if(it != p && it != v[u][0]) 
			FOR(i, in[it], out[it])
				add(ord[i]);
	ans[u] = sum[*--secik.end()];
	
	if(!keep) {
		FOR(i, in[u], out[u])
			era(ord[i]);
	}
}	



int main() {
	ios;
	cin >> n;
	FOR(i, 1, n)
		cin >> col[i];
	
	FOR(i, 1, n - 1) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	dfs(1, 0);
	
	solve(1, 0);
	
	FOR(i, 1, n)
		cout << ans[i] << " ";
	
	
	
	
	return 0;
}