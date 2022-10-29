#include<bits/stdc++.h>
using namespace std;
#define ppp pair<int,pair<int,int>>
#define pp pair<int,int>
#define fi first
#define se second
const int N=3e5+10;
vector<int> adj1[N];
vector<ppp> adj[N];
pp arr[N];
int visit[N];
int visit2[N];
int ans[N];
void dfs(int root){
	visit[root]=1;
	for(auto e:adj1[root]){
		if(!visit[e]){
			dfs(e);
		}
	}
}
void dfs2(int root){
	visit2[root]=1;
	for(auto e:adj[root]){
		if(e.se.fi>0 && ans[e.se.se]==0){
			ans[e.se.se]=e.se.fi;
		}
		if(!visit2[e.fi]){
			dfs2(e.fi);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n,m,s;
	cin>>n>>m>>s;
	s--;
	int id=0;
	for(int i=0;i<m;i++){
		int t,u,v;
		cin>>t>>u>>v;
		u--,v--;
		if(t==1){
			adj1[u].push_back(v);
			adj[u].push_back({v,{0,0}});
		}else{
			adj[u].push_back({v,{1,id}});
			adj[v].push_back({u,{2,id}});
			arr[id]={u,v};
			id++;
		}
	}
	dfs2(s);
	int res1=0;
	for(int i=0;i<n;i++){
		if(visit2[i]){
			res1++;
		}
	}
	cout<<res1<<endl;
	for(int i=0;i<id;i++){
		if(ans[i]==2){
			cout<<"-";
		}else{
			cout<<"+";
		}
	}
	cout<<endl;
	dfs(s);
	res1=0;
	for(int i=0;i<n;i++){
		if(visit[i]){
			res1++;
		}
	}
	cout<<res1<<endl;
	for(int i=0;i<id;i++){
		if(visit[arr[i].fi]){
			cout<<"-";
		}else{
			cout<<"+";
		}
	}
	cout<<endl;
}