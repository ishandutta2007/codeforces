#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
 
const int N=2005;

 
int n, m;
int a[N];
int b[N];

vector<vector<int>>adj;
int col[N];
int pa[N];



bool fu(int val){
	
	col[1]=1;
	int tot=1;
	while(1){
		queue<pair<int, int>>qu;
		int num=val;
		int su=0;
		for(int i=1; i<=n; i++){
			if(col[i]==1){
				num+=b[i];
				su++;
			}
		}
		
		if(su==n){
			return 1;
		}
		
		for(int i=1; i<=n; i++){
			if(col[i]==1){
				qu.push({i, num});
			}
		}
		
		bool bb=1;
		
		while(!qu.empty()){
			int v=qu.front().f;
			int dis=qu.front().s;
			qu.pop();
			
			for(auto u:adj[v]){
				if(dis<=a[u] || (col[u]==1 && col[v]==1) || pa[v]==u){
					continue;
				}
				if(col[u]==1){
					int node=v;
					while(col[node]!=1){
						col[node]=1;
						node=pa[node];
					}
					bb=0;
					break;
				}
				else if(col[u]==2){
					int node=v;
					while(col[node]!=1){
						col[node]=1;
						node=pa[node];
					}
					node=u;
					while(col[node]!=1){
						col[node]=1;
						node=pa[node];
					}
					bb=0;
					break;
				}
				else{
					col[u]=2;
					pa[u]=v;
					qu.push({u, dis+b[u]});
				}
			}
			if(bb==0){
				break;
			}
		}
		if(bb==1){
			return 0;
		}
		for(int i=1; i<=n; i++){
			pa[i]=0;
			if(col[i]==2){
				col[i]=0;
			}
		}
	}
}


 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=2; i<=n; i++){
			cin>>a[i];
		}
		for(int i=2; i<=n; i++){
			cin>>b[i];
		}
		
		int lo=1;
		int hi=2e9;
		adj.clear();
		adj.resize(n+1);
		for(int i=0; i<m; i++){
			int u, v;
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int ans=0;
		while(lo<=hi){
			int mid=(lo+hi)/2;
			for(int i=1; i<=n; i++){
				col[i]=0;
				pa[i]=0;
			}
			if(fu(mid)){
				ans=mid;
				hi=mid-1;
			}
			else{
				lo=mid+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}