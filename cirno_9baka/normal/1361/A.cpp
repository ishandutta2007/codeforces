#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1000005,M=998244353;
int n,m,p[N],u,v,head[N],Next[N*2],adj[N*2],ans[N],tmp[N],k,i,j;
struct str{
	int p,x;
}a[N];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
bool cmp(str a,str b)
{
	return a.p<b.p;
}
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",&p[i]);
		a[i]=(str){p[i],i};
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;++i)
	{
		k=0;
		for(j=head[a[i].x];j;j=Next[j])
			tmp[++k]=ans[adj[j]];
		sort(tmp+1,tmp+1+k);
		for(j=1;j<=k;++j)
			if(tmp[j]>tmp[j-1]+1)
				break;
		ans[a[i].x]=tmp[j-1]+1;
	}
	for(i=1;i<=n;++i)
		if(p[i]!=ans[i])
		{
			puts("-1");
			return 0;
		}
	for(i=1;i<=n;++i)
		printf("%d ",a[i].x);
}