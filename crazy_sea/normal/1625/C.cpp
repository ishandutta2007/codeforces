#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 510
using namespace std;
int n,m,k,a[N],d[N],f[N][N],ans;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	k=n-k;
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	d[n+1]=m;
	memset(f,0x3f,sizeof(f));
	ans=f[0][0];
	f[1][0]=0;
	for(int i=2;i<=n+1;i++)
		for(int j=1;j<=n+1;j++)
			for(int p=1;p<i;p++)
				f[i][j]=min(f[i][j],f[p][j-1]+a[p]*(d[i]-d[p]));
	for(int i=k;i<=n+1;i++) ans=min(ans,f[n+1][i]);
	printf("%d",ans);
}