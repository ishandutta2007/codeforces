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

const int nax = 10005;

int n, m;
vector <pair<int, int>> v[nax];	
int a, b;		
int dp[nax];
int dp2[nax];
int h[nax];

int ile = 0;
int id = -1;
int col[nax];

bool is_bipartite(int u, int p) {
	bool ok = 1;
	for(auto it: v[u]) {
		if(it.fi == p)
			continue;
		if(!col[it.fi]) {
			col[it.fi] = (3 ^ col[u]);
			ok &= is_bipartite(it.fi, u);
		}
		if(col[it.fi] == col[u]) {
			ok = 0;
		}
	}
	return ok;
}
	
vector <int> res, opt;
int bad = 0;
int edge[nax];
	
void dfs(int u, int p) {
	for(auto it: v[u]) {
		if(it.fi == p)
			continue;
		bool son = 0;
		if(h[it.fi] == 0) {
			son = 1;
			edge[it.fi] = it.se;
			h[it.fi] = h[u] + 1;
			dfs(it.fi, u);
			dp[u] += dp[it.fi];
			dp2[u] += dp2[it.fi];
		}
		else if(h[it.fi] > h[u] && col[it.fi] == col[u]) {
			--dp[u];
		}
		else if(col[it.fi] == col[u]) {
			dp[u]++;
			++bad;
			opt.pb(it.se);
		}
		if(!son && h[it.fi] > h[u]) {
			dp2[u]--;
		}
		else if(!son && h[it.fi] < h[u]) {
			dp2[u]++;
		}
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
		if(!col[i]) {
			col[i] = 1;
			bool tak = is_bipartite(i, 0);
			if(!tak) {
				++ile;
				id = i;
			}
		}
	}
	
	if(!ile) {
		printf("%d\n", m);
		for(int i = 1; i <= m; ++i) 
			printf("%d ", i);
		return 0;
	}
	if(ile > 1) {
		printf("0");
		return 0;
	}
	
	h[id] = 1;
	dfs(id, 0);
	
	if(ss(opt) == 1) {
		res.pb(opt[0]);
	}
	for(int i = 1; i <= n; ++i)
		if(dp[i] == bad && dp2[i] == dp[i]) {
			res.pb(edge[i]);
		}
	sort(res.begin(), res.end());
	printf("%d\n", ss(res));
	for(auto it: res)
		printf("%d ", it);
	
	
	
	
		
	return 0;
}