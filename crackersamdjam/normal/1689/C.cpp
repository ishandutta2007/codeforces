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
int const MM = 3e5+5;

int t, n;
vector<int> adj[MM];
int ans;

void dfs(int cur, int pre, int s){
	int ch = (int)size(adj[cur])-1;
	if(ch == 2){
		for(auto u: adj[cur]){
			if(u == pre) continue;
			dfs(u, cur, s+2);
		}
	}
	else if(ch == 1){
		ans = min(ans, s+1);
	}
	else{
		ans = min(ans, s);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0,a,b; i < n-1; i++){
			cin>>a>>b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		ans = INT_MAX;
		adj[1].emplace_back(0);
		dfs(1, 0, 1);
		cout<<n-ans<<'\n';

		for(int i = 1; i <= n; i++){
			adj[i].clear();
		}
	}
}