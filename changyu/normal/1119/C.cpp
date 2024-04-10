#include<cstdio>
const int N=501;
int n,m,a[N][N],t;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	  scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
	  scanf("%d",&t),a[i][j]^=t^a[i-1][j]^a[i][j-1]^a[i-1][j-1];
	  if((i==n||j==m)&&a[i][j])return 0*puts("No");
	}return 0*puts("Yes");
}