#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> e[1005];
void dfs(int id,int f)
{
	int g[1005]; int cnt=0;
	for(int i=0;i<e[id].size();i++)if(e[id][i]!=f)g[++cnt]=e[id][i];
	for(int i=1;i+1<=cnt;i+=2){
		int u=g[i],v=g[i+1];
		cout<<"? "<<u<<" "<<v<<endl;
		int d; cin>>d;
		if(d==u)dfs(u,id);
		if(d==v)dfs(v,id);
	}
	if(cnt&1){
		int v=g[cnt];
		int p[1005],cc=0;
		for(int i=0;i<e[v].size();i++)if(e[v][i]!=id){
			p[++cc]=e[v][i];
		}
		if(cc==0){
			cout<<"? "<<id<<" "<<v<<endl;
			int d; cin>>d;
			cout<<"! "<<d<<endl,exit(0);
		}
		else{
			int w=p[cc];
			cout<<"? "<<w<<" "<<id<<endl;
			int d; cin>>d;
			if(d==w)dfs(w,v);
			if(d==id)cout<<"! "<<id<<endl,exit(0);
			e[v].clear();
			for(int i=1;i<cc;i++)e[v].push_back(p[i]);
			dfs(v,id);
		}
	}
	cout<<"! "<<id<<endl;
	exit(0);
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u); 
	}
	dfs(1,0);
	return 0;
}