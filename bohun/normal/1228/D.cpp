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
const int nax = 1e5 + 111;

int n, m, a, b;
vector <int> v[nax];
int ans[nax];
int col[nax];
bool odw[nax];
int ile[4];

void dfs(int u, int p) {
	col[u] = !col[p];
	odw[u] = 1;
	for(auto it : v[u]) {
		if(odw[it] && col[u] == col[it]) {
			printf("-1\n");
			exit(0);
		}
		if(!odw[it] && ans[it] == 0) 
			dfs(it, u);	
	}
}

int main() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, m) {
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	ans[1] = 1;
	sort(v[1].begin(), v[1].end());
	
	FOR(i, 2, n) {
		if(lower_bound(v[1].begin(), v[1].end(), i) == v[1].end() || *lower_bound(v[1].begin(), v[1].end(), i) != i) {
			ans[i] = 1;
		}
	}
	FOR(i, 1, n) {
		if(ans[i] == 1 && ss(v[i]) != ss(v[1])) {
			printf("-1\n");
			return 0;
		}
		for(auto it : v[i]) {
			if(ans[i] == 1 && ans[it] == 1) {
				printf("-1\n");
				return 0;
			}
		}
	}
	FOR(i, 1, n) {
		if(!odw[i] && !ans[i])
			dfs(i, 0);
	}
	
	FOR(i, 1, n) {
		if(ans[i] == 0)
			ans[i] = col[i] + 2;
		ile[ans[i]] += 1;
	}
	
	FOR(i, 1, n) {
		if(ans[i] == 2 && ss(v[i]) != ile[1] + ile[3]) {
			printf("-1\n");
			return 0;
		}
	}
	
	if(!ile[2] || !ile[3]) {
		printf("-1\n");
		return 0;
	}
	FOR(i, 1, n)
		printf("%d ", ans[i]);
	
	
	
	
	return 0;
}