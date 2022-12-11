#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e4+50,M=1e6+50,inf=0x3f3f3f3f;
int n,m,g,S,T,cnt,ans;bool a[N];
int ver[M],edge[M],nxt[M],head[M],tot=1,d[M],q[M],l,r,cur[M];
void add(int x,int y,int z){
	ver[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;
	ver[++tot]=x;edge[tot]=0;nxt[tot]=head[y];head[y]=tot;
}
bool bfs(){
	memset(d,0x3f,sizeof(int)*(cnt+1));
	memcpy(cur,head,sizeof(int)*(cnt+1));
	q[l=r=1]=S;d[S]=0;
	while(l<=r){
		int x=q[l++];
		for(int i=head[x],y;i;i=nxt[i])
			if(edge[i]&&d[y=ver[i]]>d[x]+1)
				d[y]=d[x]+1,q[++r]=y;
	}
	return d[T]!=inf;
}
int dfs(int x,int flow){
	if(x==T)return flow;int now=0;
	for(int &i=cur[x],y;i;i=nxt[i]){
		if(!edge[i]||d[y=ver[i]]!=d[x]+1)continue;
		int dat=dfs(y,min(flow,edge[i]));
		edge[i]-=dat;edge[i^1]+=dat;
		now+=dat;flow-=dat;
		if(!flow)return now;
	}
	return now;
}
int main(){
	scanf("%d%d%d",&n,&m,&g);S=n+m+1;T=cnt=n+m+2;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,v;i<=n;i++)
		scanf("%d",&v),a[i]?add(S,i,v):add(i,T,v);
	for(int i=n+1,op,w,k,oo;i<=n+m;i++){
		scanf("%d%d%d",&op,&w,&k);ans+=w;
		for(int j=1,x;j<=k;j++)
			scanf("%d",&x),op?add(i,x,inf):add(x,i,inf);
		scanf("%d",&oo);
		op?add(S,i,w+oo*g):add(i,T,w+oo*g);
	}
	while(bfs())ans-=dfs(S,inf);
	cout<<ans;
	return 0;
}