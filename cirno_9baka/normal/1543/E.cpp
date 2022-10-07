#include<bits/stdc++.h>
using namespace std;
const int N=65536;
int T,n,i,vis[N],l,r,p[N],id[N],tmp[N],k,u,v,q[N],j,as[N];
vector<int> g[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<(1<<n);++i)
		{
			p[i]=vis[i]=0;
			g[i].clear();
		}
		for(i=1;i<=n*(1<<n-1);++i)
		{
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		r=0;
		vis[0]=1;
		int s=1;
		for(auto it:g[0])
		{
			q[++r]=it;
			p[it]=s;
			vis[it]=1;
			s<<=1;
		}
		while(r)
		{
			k=0;
			for(i=1;i<=r;++i)
				for(auto it:g[q[i]])
					if(!vis[it])
						p[it]|=p[q[i]];
			for(i=1;i<=r;++i)
				for(auto it:g[q[i]])
					if(!vis[it])
					{
						tmp[++k]=it;
						vis[it]=1;
					}
			r=k;
			for(i=1;i<=r;++i)
				q[i]=tmp[i];
		}
		for(i=0;i<(1<<n);++i)
			id[p[i]]=i;
		for(i=0;i<(1<<n);++i)
			printf("%d ",id[i]);
		printf("\n");
		if((-n&n)==n)
		{
			for(i=0;i<(1<<n);++i)
			{
				int ans=0;
				for(j=0;j<n;++j)
					if(i>>j&1)
						ans^=j;
				as[id[i]]=ans;
			}
			for(i=0;i<(1<<n);++i)
				printf("%d ",as[i]);
			printf("\n");
		}
		else
			puts("-1");
	}
}