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
using pii = pair<ll, int>;
const int MM = 3e5+5;

int n, m, par[MM];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

ll x, v[MM];
priority_queue<pii> q;
vector<pair<int, int>> adj[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>m>>x;
	for(int i = 1; i <= n; i++){
		par[i] = i;
		cin>>v[i];
		q.emplace(v[i], i);
	}

	for(int i = 1,a,b; i <= m; i++){
		cin>>a>>b;
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
	}

	vector<int> ans;

	while(size(q)){
		auto [f, cur] = q.top(); q.pop();
		if(cur != find(cur) or f != v[cur]) continue;

		while(size(adj[cur]) and find(adj[cur].back().first) == cur)
			adj[cur].pop_back();
	
		if(size(adj[cur])){
			auto [u, i] = adj[cur].back(); adj[cur].pop_back();
			u = find(u);

			if(v[cur] + v[u] < x){
				cout<<"NO\n";
				return 0;
			}

			par[u] = cur;
			v[cur] += v[u]-x;
			ans.emplace_back(i);

			if(size(adj[u]) > size(adj[cur]))
				swap(adj[cur], adj[u]);
			adj[cur].insert(adj[cur].end(), all(adj[u]));

			q.emplace(v[cur], cur);
		}
	}

	cout<<"YES\n";
	for(int i: ans)
		cout<<i<<'\n';
}