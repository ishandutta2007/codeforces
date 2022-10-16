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

int n, v[MM];
vector<int> adj[MM];
set<int> st[MM];
int d[MM];
int ans;

void insert(int i, int x){
	st[i].insert(x^d[i]);
}
bool count(int i, int x){
	return st[i].count(x^d[i]);
}

void dfs(int cur, int pre){
	int uu = 0;
	for(int u: adj[cur]){
		if(u == pre) continue;
		dfs(u, cur);
		if(size(st[u]) > size(st[uu])){
			uu = u;
		}
	}
	if(!uu){
		st[cur].insert(v[cur]);
		return;
	}
	st[cur] = move(st[uu]);
	d[cur] = d[uu]^v[cur];
	
	int bad = 0;
	for(int u: adj[cur]){
		if(u == pre or u == uu) continue;
		for(int i: st[u]){
			if(count(cur, i^d[u])){
				bad = 1;
			}
		}
		for(int i: st[u]){
			insert(cur, i^d[u]^v[cur]);
		}
	}
	if(count(cur, 0)){
		bad = 1;
	}
	insert(cur, v[cur]);

	if(bad){
		st[cur].clear();
		ans++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>v[i];
	}
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(1, 0);
	cout<<ans<<'\n';
}