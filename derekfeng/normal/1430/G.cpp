#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=4e11;
struct edge{
	int to,rev;
	ll cap;
	edge(int to,int rev,ll cap): to(to),rev(rev),cap(cap){} 
};
vector<edge>g[403]; 
void addedge(int u,int v,ll w){
	g[u].push_back(edge(v,g[v].size(),w+INF));
	g[v].push_back(edge(u,g[u].size()-1,0));
}
int n,m,s,t;
int f[403],iter[403];
void bfs(){
	memset(f,-1,sizeof(f));
	queue<int>que;
	f[s]=0,que.push(s);
	while(!que.empty()){
		int u=que.front();que.pop();
		for(auto x:g[u]){
			if(x.cap==0||f[x.to]>=0)continue;
			f[x.to]=f[u]+1,que.push(x.to);
		}
	}
}
ll dfs(int x,ll F){
	if(x==t)return F;
	for(int &i=iter[x];i<g[x].size();i++){
		edge &e=g[x][i];
		if(f[e.to]>f[x]&&e.cap>0){
			ll d=dfs(e.to,min(F,e.cap));
			if(d>0){
				e.cap-=d;
				g[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
ll maxflow(){
	ll ret=0;
	for(;;){
		bfs();
		if(f[t]<0)return ret;
		memset(iter,0,sizeof(iter));
		ll f;
		while((f=dfs(s,INF))>0)ret+=f; 
	}
}
int edg[20][20],cnt;
ll res[23];
bool vis1[403];
void dfs1(int x){
	vis1[x]=1;
	for(auto e:g[x])if(e.cap>0&&!vis1[e.to])dfs1(e.to);
}
int main(){
	scanf("%d%d",&n,&m);
	s=0,t=n*(n+1)+1;
	for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)edg[i][j]=++cnt;
	for(int i=0;i<m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		res[u]+=w,res[v]-=w;
		for(int j=0;j<n;j++)addedge(edg[v][j],edg[u][j+1],INF);
	}
	for(int i=1;i<=n;i++){
		addedge(s,edg[i][0],INF);
		for(int j=0;j<n;j++)addedge(edg[i][j],edg[i][j+1],res[i]*j);
		addedge(edg[i][n],t,INF);
	}
	maxflow();
	dfs1(s);
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=0;j<n;j++)
			for(auto e:g[edg[i][j]])if(e.to==edg[i][j+1]){
				if(e.cap==0&&vis1[edg[i][j]]){
					ans=j;
					break;
				}
			}
		printf("%d ",ans);
	}
}