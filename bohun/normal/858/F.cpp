#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " " << x << endl;


using namespace std;

const int nax = 200005;

int n, m;		
int a, b;
struct odp {
	int x, y, z;
	odp () {}
	odp (int xx, int yy, int zz) {
		x = xx;
		y = yy;
		z = zz;
	}
};
bool odw[nax];
vector <pair<int, int>> v[nax];
vector <odp> ans;
int h[nax];
bool byl[nax];

void dfs(int u, int p) {
	byl[u] = 1;
	vector <pair<int, int>> son;
	vector <pair<int, int>> up;
	for(auto it: v[u]) {
		if(it.fi == p) {
			up.pb(mp(it.fi, it.se));
			continue;
		}
		if(!h[it.fi]) {
			h[it.fi] = h[u] + 1;
			dfs(it.fi, u);
			if(!odw[it.se])
				son.pb(mp(it.fi, it.se));
		}
		else if(!odw[it.se] && h[it.fi] > h[u]) {
			son.pb(mp(it.fi, it.se));
		}
		else if(!odw[it.se] && h[it.fi] < h[u]){
			up.pb(mp(it.fi, it.se));
		}
	}
	for(int i = 0; i + 1 < ss(son); i += 2) {
		odp X;
		X.x = son[i].fi;
		X.y = u;
		X.z = son[i + 1].fi;
		odw[son[i].se] = 1;
		odw[son[i + 1].se] = 1;
		ans.pb(X);
	}
	int pocz = 0;
	if((ss(son) & 1) && ss(up) > 0) {
		pocz = 1;
		odp X;
		X.x = son[ss(son) - 1].fi;
		X.y = u;
		X.z = up[0].fi;
		odw[up[0].se] = 1;
		ans.pb(X);
	}
	for(int i = pocz; i + 1 < ss(up); i += 2) {
		odp X;
		X.x = up[i].fi;
		X.y = u;
		X.z = up[i + 1].fi;
		odw[up[i].se] = 1;
		odw[up[i + 1].se] = 1;
		ans.pb(X);
	}
}
		
		
	
			
		
		
				
int main() {
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		v[a].pb(mp(b, i));
		v[b].pb(mp(a, i));
	}
	for(int i = 1; i <= n; ++i) {
		if(!byl[i]) {
			h[i] = 1;
			dfs(i, 0);
		}
	}
	printf("%d\n", ss(ans));
	for(auto it: ans) {
		printf("%d %d %d\n", it.x, it.y, it.z);
	}
	
	
	
	
	
	
	
		
	return 0;
}