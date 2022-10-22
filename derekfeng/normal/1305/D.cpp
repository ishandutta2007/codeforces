#include <bits/stdc++.h>
using namespace std;
vector<int>g[1003];
int lca;
bool vis[1003];
pair<int,int> WANT(int x,int par,int d,int gt){
	if (d==gt) return make_pair(x,par);
	for (int i=0;i<g[x].size();i++) if (g[x][i]!=par && !vis[g[x][i]]){
		pair<int,int> val=WANT(g[x][i],x,d+1,gt);
		if (val.first!=-1) return val;
	}
	return make_pair(-1,-1);
}
void dfs(int x,int par,int a,int b){
	vis[x]=1;
	for (int i=0;i<g[x].size();i++) if (g[x][i]!=par && g[x][i]!=a && g[x][i]!=b) dfs(g[x][i],x,a,b);
}
bool still(int x){
	for (int i=0;i<g[x].size();i++) if (!vis[g[x][i]]) return 1;
	return 0;
}
int main(){
	int n;cin>>n;
	for (int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v),g[v].push_back(u);  
	}
	if (n==2){
		cout<<"? "<<1<<" "<<2<<"\n";
		cin>>lca;
		fflush(stdout);
		cout<<"! "<<lca;
		return 0;
	}
	int st=1;
	while (1){
		pair<int,int> F;
		F=WANT(st,-1,0,2);
		if (F.first>0){
			cout<<"? "<<F.first<<" "<<st<<"\n";
			cin>>lca;
			fflush(stdout);
			int a=st,b=F.first,c=F.second;
			if (lca==a) dfs(b,-1,a,c),dfs(c,-1,a,b);
			if (lca==b) dfs(a,-1,b,c),dfs(c,-1,a,b);
			if (lca==c) dfs(a,-1,b,c),dfs(b,-1,a,c);
			st=lca;
		}else if (still(st)){ 
			vector<int>v;
			for (int i=0;i<g[st].size();i++) if (!vis[g[st][i]]) v.push_back(g[st][i]);
			for (int i=0;i+1<v.size();i+=2){
				cout<<"? "<<v[i]<<" "<<v[i+1]<<"\n";
				cin>>lca;
				fflush(stdout);
				if (lca!=st){
					cout<<"! "<<lca;return 0;
				}
			}
			if (v.size()%2==1){
				cout<<"? "<<v[v.size()-1]<<" "<<st<<"\n";
				cin>>lca;
				fflush(stdout);
				cout<<"! "<<lca;return 0;
			}
			cout<<"! "<<st;return 0;
		}else{
			cout<<"! "<<st;return 0;
		}
	}
}