#include<cstdio>
#include<algorithm>
#define N 1010
using namespace std;
int a[N][N],b[N][N],f[N][N],n,T,ans;
int work()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++) b[i][j]=a[i][j]^a[j][i];
		b[i][i]=a[i][i];
	}
	for(int i=1;i<n;i+=2)
	{
		if(i>1) f[i+1][1]=f[i-1][1]^f[i][2]^b[i][1];
		else f[2][1]=b[1][1];
		for(int j=2;i+j<=n;j++)
			f[i+j][j]=f[i+j-2][j]^f[i+j-1][j+1]^f[i+j-1][j-1]^b[i+j-1][j];
	}
	int s=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			s^=f[i][j],f[i][j]=b[i][j]=0;
	return s;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		ans=work();
		for(int i=1;i<=n;i++)
			for(int j=1;j+j<=n;j++)
				swap(a[i][j],a[i][n-j+1]);
		ans^=work();
		printf("%d\n",ans);
	}
}