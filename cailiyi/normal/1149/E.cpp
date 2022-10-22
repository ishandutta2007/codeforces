#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200000
#define y e[i].to
using namespace std;
int n,m,h[N+5],head[N+5],cnt,val[N+5],maxv,w[705];
struct edge
{
	int to,next;
}e[N+5];
void dfs(int x)
{
	if(val[x]!=-1) return;
	bool sf[705]={0};
	for(int i=head[x];i;i=e[i].next)
		dfs(y),sf[val[y]]=1;
	for(val[x]=0;sf[val[x]];++val[x]);
	maxv=max(maxv,val[x]),w[val[x]]^=h[x];
}
int main()
{
	memset(val,-1,sizeof val);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",h+i);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d %d",&u,&v),e[++cnt]=(edge){v,head[u]},head[u]=cnt;
	for(int i=1;i<=n;++i) dfs(i);
	for(int p=maxv;p>=0;--p)
		if(w[p])
		{
			puts("WIN");
			for(int x=1;x<=n;++x)
				if(val[x]==p && (h[x]^w[p])<h[x])
				{
					h[x]^=w[p],w[p]=0;
					for(int i=head[x];i;i=e[i].next)
						h[y]^=w[val[y]],w[val[y]]=0;
					for(int i=1;i<=n;++i) printf("%d ",h[i]);
					return 0;
				}
		}
	puts("LOSE");
	return 0;
}