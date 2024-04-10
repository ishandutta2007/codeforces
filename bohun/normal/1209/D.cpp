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
const int nax = 1e5 + 111;
int n, k;
int a, b;
vector <int> v[nax];
int res = 0;
int ile = 0;
int odw[nax];

void dfs(int u) {
	ile += 1;
	odw[u] = 1;
	for(auto it: v[u]) 
		if(!odw[it])
			dfs(it);
}

int main() {
	cin >> n >> k;
	FOR(i, 1, k) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	FOR(i, 1, n) {
		if(!odw[i]) {
			ile = 0;
			dfs(i);
			res += ile - 1;
		}
	}
	
	cout << k - res;
	
		
	
	
	return 0;
}