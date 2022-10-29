#include <bits/stdc++.h>
using namespace std;
 
#pragma optimize("-O3")
#define int long long int

#define pb push_back
#define f first
#define s second
#define endl '\n'
int tot[100005];
int hap[100005];
int nhap[100005];
int num[100005];
int pa[100005];
vector<vector<int>>adj;
int n, m;
bool b=1;
void dfs(int v, int p){
	pa[v]=p;
	tot[v]=num[v];
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfs(u, v);
		tot[v]+=tot[u];
	}
	if((hap[v]+tot[v])%2!=0){
		b=0;
	}
	nhap[v]=(hap[v]+tot[v])/2;
	if(nhap[v]<0 || nhap[v]>tot[v]){
		
		b=0;
	}
	int s1=0;
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		s1+=nhap[u];
	}
	if(s1>nhap[v]){
		b=0;
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
		adj.clear();
		adj.resize(n+1);
		for(int i=1; i<=n; i++){
			cin>>num[i];
		}
		for(int i=1; i<=n; i++){
			cin>>hap[i];
		}
		for(int i=0; i<n-1; i++){
			int u, v;
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1, 1);
		
		for(int i=1; i<=n; i++){
			if(nhap[i]>nhap[pa[i]]){
				b=0;
			}
		}
		if(b==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		b=1;
		for(int i=0; i<=n; i++){
			num[i]=0;
			tot[i]=0;
			hap[i]=0;
			nhap[i]=0;
			pa[i]=0;
		}
	}
	return 0;
}