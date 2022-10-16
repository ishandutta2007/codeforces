#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 4e5+5, LOG = 20;

int n, q;
ll in[MM];
vector<pair<int, int>> adj[MM];
int dep[MM];
int par[MM];
ll pw[MM];
ll dp[MM], dpall[MM], tmp[MM];
int sp[LOG][MM];
ll val[MM];
ll path[MM];

int getlca(int u, int v){
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] and dep[sp[i][u]] >= dep[v])
			u = sp[i][u];
	}
	if(u == v)
		return u;
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] and ~sp[i][v] and sp[i][u] != sp[i][v]){
			u = sp[i][u];
			v = sp[i][v];
		}
	}
	return sp[0][u];
}

tuple<int, int, int> getnodes(int a, int b){
	int lca = getlca(a, b);
	for(int i = LOG-1; i >= 0; i--){
		if(dep[a] > dep[lca]+(1<<i)){
			a = sp[i][a];
		}
	}
	for(int i = LOG-1; i >= 0; i--){
		if(dep[b] > dep[lca]+(1<<i)){
			b = sp[i][b];
		}
	}
	return {lca, a, b};
}

void dfs(int cur){
	dp[cur] = in[cur];
	for(auto [u, w]: adj[cur]){
		if(u == par[cur]) continue;
		dep[u] = dep[cur]+1;
		par[u] = cur;
		pw[u] = w;
		dfs(u);
		dp[cur] += max(0LL, dp[u]-2*w);
	}
	tmp[cur] = dp[cur];
}

void go(int cur){
	sp[0][cur] = par[cur];
	val[cur] = val[par[cur]] + dp[cur] - max(0LL, dp[cur]-2*pw[cur]);
	//dont' let par come to cur

	dpall[cur] = tmp[cur];
	path[cur] = path[par[cur]] - pw[cur];

	for(auto [u, w]: adj[cur]){
		if(u == par[cur]) continue;
		tmp[cur] -= max(0LL, tmp[u]-2*w);
		tmp[u] += max(0LL, tmp[cur]-2*w);
		go(u);
		tmp[u] -= max(0LL, tmp[cur]-2*w);
		tmp[cur] += max(0LL, tmp[u]-2*w);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>q;
	for(int i = 1; i <= n; i++)
		cin>>in[i];
	for(int i = 0,a,b,c; i < n-1; i++){
		cin>>a>>b>>c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	memset(sp, -1, sizeof sp);

	dep[1] = 1;
	dfs(1);
	go(1);

	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++){
			int u = sp[i-1][j];
			if(~u){
				sp[i][j] = sp[i-1][u];
			}
		}
	}

	while(q--){
		int a, b;
		cin>>a>>b;
		auto [c, d, e] = getnodes(a, b);
		ll ans = val[a]+val[b]-2*val[c]+dpall[c];
		ll p = path[a]+path[b]-2*path[c];
		ans += p;
		cout<<ans<<'\n';
	}
}