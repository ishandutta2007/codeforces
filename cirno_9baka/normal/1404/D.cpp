#include<bits/stdc++.h>
using namespace std;
const int N=1000005,E=1000005;
int n,i,a[N],b[N],head[N],Next[N*2],adj[N*2],k,ans[N];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int f)
{
	if(ans[i]!=-1)
		return;
	ans[i]=f;
	int j;
	for(j=head[i];j;j=Next[j])
		dfs(adj[j],f^1);
}
int main()
{
	scanf("%d",&n);
	if(n&1)
	{
		puts("Second");
		fflush(stdout);
		for(i=1;i<=2*n;++i)
			scanf("%d",&a[i]);
		for(i=1;i<=n;++i)
		{
			Push(i,i+n);
			Push(i+n,i);
		}
		for(i=1;i<=2*n;++i)
			if(b[a[i]]==0)
				b[a[i]]=i;
			else
			{
				Push(b[a[i]],i);
				Push(i,b[a[i]]);
			}
		memset(ans,-1,sizeof(ans));
		for(i=1;i<=2*n;++i)
			if(ans[i]==-1)
				dfs(i,0);
		long long s=0;
		for(i=1;i<=2*n;++i)
			s+=ans[i]*i;
		if(s%(2*n)!=0)
			for(i=1;i<=2*n;++i)
				ans[i]^=1;
		for(i=1;i<=2*n;++i)
			if(ans[i])
				printf("%d ",i);
		fflush(stdout);
	}
	else
	{
		puts("First");
		for(i=0;i<2*n;++i)
			printf("%d ",i%n+1);
		fflush(stdout);
	}	
}