#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int n, m, q;
vector<pair<int, int>> adj[MM];
int dfn[MM], low[MM], t, id[MM];
bool ins[MM];
stack<int> stk;

void dfs(int cur){
	dfn[cur] = low[cur] = ++t;
	stk.push(cur);
	ins[cur] = 1;
	
	for(auto [u, w]: adj[cur]){
		if(!dfn[u]){
			dfs(u);
			low[cur] = min(low[cur], low[u]);
		}
		else if(ins[u])
			low[cur] = min(low[cur], dfn[u]);
	}
	
	if(dfn[cur] == low[cur]){
		int u = -1;
		while(u != cur){
			u = stk.top(); stk.pop();
			ins[u] = 0;
			id[u] = cur;
		}
	}
}

bool vis[MM];
ll dis[MM];
ll tt[MM];

void dfs2(int cur){
	vis[cur] = 1;
	for(auto [u, w]: adj[cur]){
		if(id[u] != id[cur]) continue;

		if(!vis[u]){
			dis[u] = dis[cur]+w;
			dfs2(u);
		}
		else{

			ll dif = abs(dis[cur]+w-dis[u]);
			
			if(dif){
				tt[id[cur]] = __gcd(tt[id[cur]], dif);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>m;
	while(m--){
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].emplace_back(b, c);
	}

	for(int i = 1; i <= n; i++){
		if(!dfn[i]){
			dfs(i);
		}
	}

	for(int i = 1; i <= n; i++){
		if(id[i] == i){
			dfs2(i);
		}
	}

	cin>>q;
	while(q--){
		int u;
		ll s, t;
		cin>>u>>s>>t;
		int i = id[u];
		bool ans = 0;
		ll g = __gcd(tt[i], t);

		// ax + by = c
		// sol exists iff c % (a, b) == 0

		if(tt[i] == 0){
			ans = !s;
		}
		else{
			if(s%g == 0){
				ans = 1;
			}
		}

		cout<<(ans ? "YES" : "NO")<<'\n';
	}
}