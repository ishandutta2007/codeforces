#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m;
bool vis[300030];
int st[100010],tp;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		int x,y;
		for(int i=1;i<=m;++i)
		{
			scanf("%d %d",&x,&y);
			if(!vis[x]&&!vis[y])st[++tp]=i,vis[x]=vis[y]=1;
		}
		if(tp>=n)
		{
			printf("Matching\n");
			for(int i=1;i<=n;++i)printf("%d ",st[i]);
			printf("\n");
		}
		else
		{
			printf("IndSet\n");
			int cnt=0;
			for(int i=1;cnt<n;++i)
				if(!vis[i])printf("%d ",i),++cnt;
			printf("\n");
		}
		memset(vis+1,0,3*n);
		tp=0;
	}
	return 0;
}