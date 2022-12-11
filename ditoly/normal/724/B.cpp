#include<cstdio>
#define MAX 20
int n,m,a[MAX+5][MAX+5],c[MAX+5][MAX+5];
bool check()
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0,k=0;j<m;j++)if(c[i][j]!=j+1)k++;
		if(k>2)return false;
	}
	return true;
}
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)for(j=0;j<m;j++)c[i][j]=a[i][j];
	if(check())return 0*puts("YES");
	for(i=0;i<m;i++)for(j=i+1;j<m;j++)
	{
		for(k=0;k<n;k++)c[k][i]=a[k][j],c[k][j]=a[k][i];
		if(check())return 0*puts("YES");
		for(k=0;k<n;k++)c[k][i]=a[k][i],c[k][j]=a[k][j];
	}
	puts("NO");
}