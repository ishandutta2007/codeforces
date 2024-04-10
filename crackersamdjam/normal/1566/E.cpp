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
int const MM = 2e5+5;

int t, n;
vector<int> adj[MM];

int ans;

bool dfs(int cur, int pre){
	int ch = 0;

	for(int u: adj[cur]){
		if(u == pre) continue;
		if(dfs(u, cur)){
			ch++;
		}
	}

	if(ch){
		ans += ch-1;
		return 0;
	}
	else{
		return 1;
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
		ans = 1;
		dfs(1, 0);
		cout<<ans<<'\n';

		for(int i = 1; i <= n; i++){
			adj[i].clear();
		}
	}
}