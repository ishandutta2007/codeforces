#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,k,t,i,j,u,v,d[N],vis[N],ans[N];
unordered_map<long long,int> g;
vector<int> p[N];
struct str{
	int s,x;
};
bool operator <(str a,str b)
{
	return a.s>b.s;
}
priority_queue<str> q;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&k);
		g.clear();
		for(i=1;i<=n;++i)
		{
			vis[i]=d[i]=0;
			p[i].clear();
		}
		for(i=1;i<=m;++i)
		{
			scanf("%d %d",&u,&v);
			++d[u],++d[v];
			g[1ll*u*(n+1)+v]=g[1ll*v*(n+1)+u]=1;
			p[u].push_back(v);
			p[v].push_back(u);
		}
		for(i=1;i<=n;++i)
			q.push((str){d[i],i});
		bool flag=true;
		while(!q.empty())
		{
			str x=q.top();
			q.pop();
			if(vis[x.x])
				continue;
			if(d[x.x]>=k)
			{
				int s=0;
				for(i=1;i<=n;++i)
					if(!vis[i])
						++s;
				printf("1 %d\n",s);
				for(i=1;i<=n;++i)
					if(!vis[i])
						printf("%d ",i);
				printf("\n");
				flag=false;
				break;
			}
			if(d[x.x]==k-1&&1ll*k*(k-1)/2<=m)
			{
				int k=0;
				ans[++k]=x.x;
				for(auto it:p[x.x])
					if(!vis[it])
						ans[++k]=it;
				for(i=2;i<=k;++i)
				{
					for(j=i+1;j<=k;++j)
						if(!g[1ll*ans[i]*(n+1)+ans[j]])
							break;
					if(j<=k)
						break;
				}
				if(i>k)
				{
					printf("2\n");
					for(i=1;i<=k;++i)
						printf("%d ",ans[i]);
					printf("\n");
					flag=false;
					break;
				}
			}
			vis[x.x]=1;
			for(auto it:p[x.x])
				if(!vis[it])
				{
					--d[it];
					q.push((str){d[it],it});
				}
		}
		while(!q.empty())
			q.pop();
		if(flag)
			puts("-1");
	}
}