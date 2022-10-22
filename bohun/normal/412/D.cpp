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

const int nax = 100005;
int n, m, a, b;
vector <int> v[nax], post;		
bool odw[nax];

void dfs(int u, int p) {
	odw[u] = 1;
	for(auto it: v[u]) {
		if(!odw[it])
			dfs(it, u);
	}
	post.pb(u);
}
				
int main() {
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		v[a].pb(b);
	}
	for(int i = 1; i <= n; ++i)
		if(!odw[i])
			dfs(i, 0);
	for(auto it: post)
		printf("%d ", it);
	
	
	
	
	
	
	
	
		
	return 0;
}