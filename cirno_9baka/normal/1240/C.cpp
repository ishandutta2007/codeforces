#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
const int M=1000000007;
#define ri register int 
int n,i,k,u,v,w,head[500005],Next[1000005],adj[1000005],op,leng[1000005],q;
ll f[500005][2],pre[500005],suf[500005];
void Push(int u,int v,int w)
{
	Next[++op]=head[u];
	head[u]=op;
	adj[op]=v;
	leng[op]=w;
}
struct str{
	ll s0,s1;
}p[500005];
bool cmp(str a,str b)
{
	return a.s1-a.s0>b.s1-b.s0;
}
void dfs(int i,int fa)
{
	int j,n=0;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
			dfs(adj[j],i);
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
			p[++n]=(str){max(f[adj[j]][0],f[adj[j]][1]),f[adj[j]][0]+leng[j]};
	sort(p+1,p+1+n,cmp);
	pre[0]=suf[n+1]=0;
	for(j=1;j<=n;j++)
		pre[j]=pre[j-1]+p[j].s1;
	for(j=n;j>=1;j--)
		suf[j]=suf[j+1]+p[j].s0;
	for(j=0;j<k&&j<=n;j++)
		f[i][0]=max(f[i][0],pre[j]+suf[j+1]);
	f[i][1]=f[i][0];
	if(k<=n)
		f[i][1]=max(f[i][1],pre[k]+suf[k+1]);
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&n,&k);
		op=0;
		for(i=1;i<=n;i++)
			f[i][0]=f[i][1]=head[i]=0;
		for(i=1;i<n;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			Push(u,v,w);
			Push(v,u,w);
		}
		dfs(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
	}
}