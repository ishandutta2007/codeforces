#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
const int N=1e3+5;
int n,m,s,t,dis[2][N],ans;bool lk[N][N];
vector<int>adj[N];
void adde(int u,int v){adj[u].pb(v);adj[v].pb(u);}
void bfs(int s,int c){
	queue<int>que;while(!que.empty())que.pop();
	que.push(s);dis[c][s]=0;
	while(!que.empty()){
		int u=que.front();que.pop();
		for(auto v:adj[u])if(dis[c][v]<0)dis[c][v]=dis[c][u]+1,que.push(v);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),lk[u][v]=lk[v][u]=true,adde(u,v);
	memset(dis,-1,sizeof(dis));
	bfs(s,0);bfs(t,1);
	for(int i=1;i<=n;i++)for(int j=i+1,nm;j<=n;j++)if(!lk[i][j]){
		nm=min(dis[0][i]+1+dis[1][j],dis[0][j]+1+dis[1][i]);
		if(nm>=dis[0][t])ans++;
	}
	printf("%d\n",ans);
	return 0;
}