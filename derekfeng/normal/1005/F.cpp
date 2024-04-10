#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,m,K;
vector<pii>g[200004];
vector<int>f[200004];
int lev[200004];
bool used[200004];
vector<string>res;
void dfs(int x){
	if(x==n+1){
		K--;
		string S="";
		for(int i=0;i<m;i++)S+=(used[i]?"1":"0");
		res.push_back(S);
		if(K==0){
			printf("%d\n",res.size());
			for(auto x:res)printf("%s\n",x.c_str());
			exit(0);
		}
	}
	for(auto z:f[x]){
		used[z]=1;
		dfs(x+1);
		used[z]=0;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back({v,i}),g[v].push_back({u,i});
	}
	memset(lev,0x3f,sizeof(lev));
	queue<int>que;
	lev[1]=0,que.push(1);
	while(!que.empty()){
		int u=que.front();que.pop();
		for(auto v:g[u]){
			if(lev[v.fi]>lev[u]+1)lev[v.fi]=lev[u]+1,que.push(v.fi);
			if(lev[v.fi]==lev[u]+1)f[v.fi].push_back(v.se);
		}
	}
	dfs(2);
	printf("%d\n",res.size());
	for(auto x:res)printf("%s\n",x.c_str());
}