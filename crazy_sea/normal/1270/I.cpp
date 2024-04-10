#include<cstdio>
#define N 514
using namespace std;
struct matrix{
	long long a[N][N];
}f[11],ans,a;
int n,k,x[N],y[N],sum,t;
int w(int x){return x>0?x:x+n;}
matrix mult(matrix a,matrix b)
{
	matrix c;
	int len=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(b.a[i][j]>0) len++,x[len]=i,y[len]=j;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			c.a[i][j]=0;
			for(int k=1;k<=len;k++)
				c.a[i][j]^=a.a[w(i-x[k])][w(j-y[k])];
		}
	return c;
}
int main()
{
	scanf("%d",&k);
	n=1<<k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lld",&a.a[i][j]);
	scanf("%d",&t);
	for(int i=1,x,y;i<=t;i++) scanf("%d%d",&x,&y),f[0].a[x][y]=1;
	ans=mult(a,f[0]);
	for(int i=1;i<k;i++) f[i]=mult(f[i-1],f[i-1]),ans=mult(ans,f[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(ans.a[i][j]>0) sum++;
	printf("%d",sum);
}