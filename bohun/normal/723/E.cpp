#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
	
		
using namespace std;

const int nax = 100000;

int T;
vector <pair<int,int>> v[nax], res;
vector <int> odd;
int a, b;
int n, m;
int ans = 0;
int deg[nax];
bool odw[nax];

void dfs(int u) {
	for(auto it : v[u]) {
		if(!odw[it.se]) {
			odw[it.se] = 1;
			if(it.se <= m)
				res.pb(mp(u, it.fi));
			dfs(it.fi);
		}
	}
}

int main() {	
	scanf("%d", &T);
	while(T--) {
		odd.clear();
		res.clear();
		ans = 0;
		scanf("%d %d", &n, &m);
		FOR(i, 1, n) {
			deg[i] = 0;
			v[i].clear();
		}
		FOR(i, 1, m) {
			scanf("%d %d", &a, &b);
			v[a].pb(mp(b, i));
			v[b].pb(mp(a, i));
			deg[a] += 1;
			deg[b] += 1;
		}
		FOR(i, 1, n) {
			ans += deg[i] % 2 == 0;
			if(deg[i] & 1)
				odd.pb(i);
		}
		for(int i = 1; i < ss(odd); i += 2) {
			int x = odd[i];
			int y = odd[i - 1];
			v[x].pb(mp(y, m + i));
			v[y].pb(mp(x, m + i));
		}
		FOR(i, 1, m + n)
			odw[i] = 0;
		for(int i = 1; i <= n; ++i)
			dfs(i);
		printf("%d\n", ans);
		for(auto it : res)
			printf("%d %d\n", it.fi, it.se);
	}
	
	
	return 0;
}