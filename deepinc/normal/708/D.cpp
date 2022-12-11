#include<bits/stdc++.h>
using namespace std;
const int $=5555,inf=2e8;
int deg[$],fir[$],l[$],to[$],w[$],c[$],ec=1,n,m,ans,al[$],d[$],q[$];
void link(int a,int b,int v,int C){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;w[ec]=v;c[ec]=C;}
void con(int a,int b,int v,int C){link(a,b,v,C);link(b,a,0,-C);}
bool SPFA(){
	for(int i=1;i<=n+2;++i)d[i]=inf,al[i]=0; d[n+1]=0; q[1]=n+1;
	for(int h=1,t=1,p;p=q[h],h<=t;++h)for(int i=fir[p],y;y=to[i];i=l[i])if(d[y]>d[p]+c[i]&&w[i])
		d[q[++t]=y]=d[p]+c[i];
	return d[n+2]<inf;
}
int dfs(int p,int f){ int r=f;
	if(p==n+2)return f; al[p]=1;
	for(int i=fir[p],y;(y=to[i])&&r;i=l[i])if(d[y]==d[p]+c[i]&&w[i]&&!al[y]){
		int x=dfs(y,min(r,w[i]));
		if(!x)d[y]=inf;
		w[i]-=x;w[i^1]+=x;ans+=c[i]*x;r-=x;
	}return f-r;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,c,f;i<=m;++i)scanf("%d%d%d%d",&u,&v,&c,&f),deg[u]+=f,deg[v]-=f,
		con(u,v,inf,2),con(v,u,min(c,f),1),f<=c?(con(u,v,c-f,1)):(ans+=f-c,con(v,u,f-c,0));
	for(int i=1;i<=n;++i)if(deg[i]<0)con(n+1,i,-deg[i],0);else con(i,n+2,deg[i],0);
	con(n,1,inf,0);
	while(SPFA())dfs(n+1,inf);
	printf("%d",ans);
}