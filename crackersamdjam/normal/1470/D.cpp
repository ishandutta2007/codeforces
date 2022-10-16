#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 3e5+5;

int t, n, m;
vector<int> adj[MM];
bool on[MM], vis[MM];

queue<int> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 0,a,b; i < m; i++){
			cin>>a>>b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}

		vector<int> v;
		q.push(1);
		vis[1] = 1;

		while(size(q)){
			int i = q.front(); q.pop();
			on[i] = 1;
			for(int j: adj[i]){
				if(on[j])
					on[i] = 0;
				if(!vis[j]){
					q.push(j);
					vis[j] = 1;
				}
			}
			if(on[i])
				v.emplace_back(i);
		}

		if(accumulate(vis, vis+1+n, 0) != n)
			cout<<"NO\n";
		else{
			cout<<"YES\n";
			cout<<size(v)<<'\n';
			for(int i: v)
				cout<<i<<' ';
			cout<<'\n';
		}

		for(int i = 1; i <= n; i++){
			on[i] = 0;
			adj[i].clear();
			vis[i] = 0;
		}
	}
}