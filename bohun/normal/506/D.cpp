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
const int P = 400;

int a, b, c;
int n, m, q;
map <int, vector <int>> mapa[nax];

vector <int> co[nax];
unordered_map <int, int> col[nax], odw[nax];
int timer = 1;

map <pair<int, int>, int> res;

void dfs(int u, int kol) {
	col[u][kol] = timer;
	odw[u][kol] = 1;
	for(auto it : mapa[kol][u])
		if(!odw[it][kol])
			dfs(it, kol);
}

int main() {	
	scanf("%d %d", &n, &m);
	FOR(i, 1, m) {
		scanf("%d %d %d", &a, &b, &c);
		mapa[c][a].pb(b);
		mapa[c][b].pb(a);
		co[c].pb(a);
		co[c].pb(b);
	}
	
	FOR(i, 1, 100 * 1000) {
		for(auto it : co[i]) {
			if(odw[it][i] == 0) {
				timer += 1;
				dfs(it, i);
			}
		}
	}
	
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d", &a, &b);
		if(res.find(mp(a, b)) != res.end()) {
			printf("%d\n", res[mp(a, b)]);
			continue;
		}
		if(ss(col[a]) > ss(col[b])) 
			swap(a, b);
		int ww = 0;
		for(auto it : col[a])
			if(col[b].find(it.fi) != col[b].end() && col[b][it.fi] == it.se)
				ww += 1;
		res[mp(a, b)] = res[mp(b, a)] = ww;
		printf("%d\n", ww);
	}
	
	
	
	
		
	
		
	
	return 0;
}