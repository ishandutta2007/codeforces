#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,used[403][403];
int dis[403][403],edg[403];
vector<int>g[403],v[403];
void bfs(int s){
	memset(dis[s],-1,sizeof(dis[s]));
	queue<int>que;
	que.push(s);dis[s][s]=0;
	while(!que.empty()){
		int u=que.front();que.pop();
		for(auto v:g[u])if(dis[s][v]<0)
			dis[s][v]=dis[s][u]+1,que.push(v);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)bfs(i);
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=n;j++){
		if(i>j){printf("%d ",used[j][i]);continue;}
		int cnt=0;
		for(int k=1;k<=n;k++)if(dis[i][j]==dis[i][k]+dis[k][j])cnt++;
		if(cnt>dis[i][j]+1){
			used[i][j]=0;
			printf("0 ");
			continue;
		}
		int ans=1;
		for(int k=0;k<=n;k++)edg[k]=0,v[k].clear();
		for(int k=1;k<=n;k++)v[dis[k][i]].push_back(k);
		for(int k=0;k<n;k++){
			if(v[k].empty())break;
			for(auto x:v[k])for(auto y:g[x])
				if(dis[i][y]==k+1&&dis[j][y]==dis[j][x]+1)edg[y]++;
			for(auto x:v[k+1])if(dis[x][i]+dis[x][j]!=dis[i][j])ans=(long long)ans*edg[x]%MOD;
			if(ans==0)break;
		}
		used[i][j]=ans;
		printf("%d ",ans);
	}
}