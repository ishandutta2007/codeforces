#include<cstdio>
#include<queue>
using namespace std;
const int N=1e5+1;
struct edge{int v,nxt;}g[N+N];
int n,m,head[N],k,a[N],inq[N];
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
priority_queue<int,vector<int>,greater<int> >p;
int main()
{
	int u,v;
	scanf("%d%d",&n,&m);
	for(;m--;)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	k=0;
	p.push(1);inq[1]=1;
	for(;!p.empty();){
	  u=p.top();p.pop();
	  a[++k]=u;
	  for(int i=head[u];i;i=g[i].nxt)
		if(!inq[g[i].v])p.push(g[i].v),inq[g[i].v]=1;
	}for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}