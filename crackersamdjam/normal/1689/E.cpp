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
int const MM = 2035;

int t, n, a[MM];
vector<int> adj[MM];
bool vis[MM];

void dfs(int cur){
	if(vis[cur]) return;
	vis[cur] = 1;
	for(int u: adj[cur])
		dfs(u);
}

bool check(){
	for(int i = 0; i < n; i++){
		vector<int> v;
		for(int j = 0; j < 30; j++){
			if(a[i]>>j&1){
				adj[i].emplace_back(n+j);
				adj[n+j].emplace_back(i);
			}
		}
	}
	bool ret = 1;
	dfs(0);

	for(int i = 0; i < n+30; i++){
		if(i < n)
			ret &= vis[i];
		adj[i].clear();
		vis[i] = 0;
	}
	return ret;
}

void out(int x){
	cout<<x<<'\n';
	for(int i = 0; i < n; i++)
		cout<<a[i]<<' ';
	cout<<'\n';
}

void go(){
	cin>>n;
	int add = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		if(!a[i]){
			a[i] = 1;
			add++;
		}
	}
	if(check()){
		out(add);
		return;
	}

	for(int i = 0; i < n; i++){
		a[i]--;
		if(check()){
			out(add+1);
			return;
		}
		a[i] += 2;
		if(check()){
			out(add+1);
			return;
		}
		a[i]--;
	}

	vector<int> v;
	int mb = 0;
	for(int i = 0; i < n; i++){
		int ii = a[i]&-a[i];
		if(ii > mb){
			mb = ii;
			v = {i};
		}
		else if(ii == mb){
			v.emplace_back(i);
		}
	}
	assert(size(v) > 1);
	a[v[0]]--;
	a[v[1]]++;
	out(add+2);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		go();
	}
}