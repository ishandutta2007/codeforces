#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 2000
using namespace std;
int T,n,q,ans[N+5][N+5],sum[N+5];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",ans[0]+i);
		for(int i=1;i<=n;++i)
		{
			memset(sum,0,sizeof sum);
			for(int j=1;j<=n;++j) ++sum[ans[i-1][j]];
			for(int j=1;j<=n;++j) ans[i][j]=sum[ans[i-1][j]];
		}
		scanf("%d",&q);int k,x;
		while(q--)
		{
			scanf("%d %d",&x,&k);
			printf("%d\n",ans[min(k,n)][x]);
		}
	}
	return 0;
}