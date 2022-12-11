#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int p[1000010],b[500010][2];
bool vis[500010];
int st[500010],tp;
int ans[500010],l,r,tot;
int main()
{
	scanf("%d",&n);
	if(n&1)
	{
		puts("Second");
		fflush(stdout);
		for(int i=1;i<=2*n;++i)scanf("%d",&p[i]),b[p[i]][b[p[i]][0]!=0]=i;
		for(int i=1;i<=n;++i)
			if(!vis[i])
			{
				int x=i,y=i;tp=0;
				while(!vis[y])
				{
					vis[y]=1;st[++tp]=y;ans[++tot]=x;
					x=b[p[x]][b[p[x]][0]==x];
					if(x<=n)x+=n;
					else x-=n;
					y=x>n?x-n:x;
				}
				if(tp&1)l=tot-tp+1,r=tot;
			}
		long long sum=0;
		for(int i=1;i<=n;++i)sum+=ans[i];
		if(sum%(2*n))
		{
			for(int i=l;i<=r;++i)
				if(ans[i]<=n)ans[i]+=n;
				else ans[i]-=n;
		}
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);
		printf("\n");
		fflush(stdout);
	}
	else
	{
		puts("First");
		for(int i=1;i<=n;++i)printf("%d ",i);
		for(int i=1;i<=n;++i)printf("%d ",i);
		fflush(stdout);
	}
	return 0;
}