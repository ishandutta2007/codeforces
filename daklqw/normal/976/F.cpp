#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define MAXPoint 4010
#define MAXEdge 80010
#define INF 0x3f3f3f3f
int head[MAXPoint],to[MAXEdge],nxt[MAXEdge],val[MAXEdge],tot=1,n1,n2,m,S,T,dis[MAXPoint],deg[MAXPoint],t1,t2;
vector<int>ansl[MAXPoint];
inline void addedge(int b,int e,int v){
	nxt[++tot]=head[b];head[b]=tot;to[tot]=e;val[tot]=v;
	nxt[++tot]=head[e];head[e]=tot;to[tot]=b;val[tot]=0;
}
queue<int>q;
bool bfs(){
	for(int i=S+1;i<=T;++i)dis[i]=0;
	dis[S]=1;q.push(S);
	while(!q.empty()){
		int t=q.front();q.pop();
		for(int i=head[t];i;i=nxt[i])
			if(val[i]&&!dis[to[i]]){
				q.push(to[i]);
				dis[to[i]]=dis[t]+1;
			}
	}
	return dis[T]>0;
}
int dinic(int u,int minv){
	if(u==T||!minv)return minv;
	int ans=0,t;
	for(int i=head[u];i;i=nxt[i])
		if(val[i]&&dis[to[i]]==dis[u]+1&&(t=dinic(to[i],min(minv,val[i])))){
			val[i]-=t;
			val[i^1]+=t;
			minv-=t;
			ans+=t;
			if(!minv)break;
		}
	if(!ans)dis[u]=-1;
	return ans;
}
int main(){
	scanf("%d%d%d",&n1,&n2,&m);
	S=0;T=n1+n2+1;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&t1,&t2);
		addedge(t1,n1+t2,1);
		++deg[t1];
		++deg[n1+t2];
	}
	int mind=0x3f3f3f3f;
	for(int i=1;i<=n1+n2;++i)
		mind=min(mind,deg[i]);
	for(int i=1;i<=n1;++i)addedge(S,i,deg[i]-mind);
	for(int i=1;i<=n2;++i)addedge(n1+i,T,deg[i+n1]-mind);
	for(int i=mind;i>=1;--i){
		while(bfs())dinic(S,INF);
		for(int j=2;j<(1+m<<1);j+=2)if(val[j])ansl[i].push_back(j>>1);
		for(int j=1+m<<1;j<=tot;j+=2)++val[j];
	}
	for(int i=0;i<=mind;++i){
		printf("%d ",ansl[i].size());
		for(int j=0;j<ansl[i].size();++j)
			printf("%d ",ansl[i][j]);
		putchar(10);
	}
	return 0;
}