#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAXEdge 200010
#define MAXPoint 210
#define Throw {puts("-1");return 0;}
int head[MAXPoint],to[MAXEdge],nxt[MAXEdge],val[MAXEdge],cost[MAXEdge],tot=1,S,T,dis[MAXPoint],pre[MAXPoint],
	n,Q,t1,t2,t3,t4,up[MAXPoint],low[MAXPoint];
inline void addedge(int b,int e,int v,int c){
	nxt[++tot]=head[b];head[b]=tot;to[tot]=e;val[tot]=v;cost[tot]=c;
	nxt[++tot]=head[e];head[e]=tot;to[tot]=b;val[tot]=0;cost[tot]=-c;
}
queue<int>q;bool inq[MAXPoint];
bool spfa(){
	for(int i=S+1;i<=T;++i)dis[i]=0x3f3f3f3f;
	dis[S]=0;q.push(S);inq[S]=true;
	while(!q.empty()){
		int t=q.front();q.pop();inq[t]=false;
		for(int i=head[t];i;i=nxt[i])
			if(val[i]&&dis[to[i]]>dis[t]+cost[i]){
				dis[to[i]]=dis[t]+cost[i];
				pre[to[i]]=i^1;
				if(!inq[to[i]]){
					q.push(to[i]);
					inq[to[i]]=true;
				}
			}
	}
	return dis[T]!=0x3f3f3f3f;
}
int MCMF(){
	int now=pre[T],minv=0x3f3f3f3f;
	while(now){
		minv=min(minv,val[now^1]);
		now=pre[to[now]];
	}
	now=pre[T];
	while(now){
		val[now]+=minv;
		val[now^1]-=minv;
		now=pre[to[now]];
	}
	return dis[T]*minv;
}
int main(){
	scanf("%d%d",&n,&Q);
	S=0;T=n<<1|1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			addedge(i,T,1,(j<<1)-1);
		addedge(S,i+n,1,0);
		up[i]=n;low[i]=1;
	}
	for(int i=1;i<=Q;++i){
		scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		for(int j=t2;j<=t3;++j){
			if(t1==1)low[j]=max(low[j],t4);
			else up[j]=min(up[j],t4);
			if(up[j]<low[j])Throw;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=low[i];j<=up[i];++j)
			addedge(i+n,j,1,0);
	int ans=0;
	while(spfa())ans+=MCMF();
	printf("%d\n",ans);
	return 0;
}