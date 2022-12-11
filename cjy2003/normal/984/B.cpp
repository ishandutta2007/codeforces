#include<stdio.h>
#include<string.h>
int n,m,a[102][102],b[102][102];
void jia(int x,int y)
{
	b[x][y-1]++;
	b[x][y+1]++;
	b[x+1][y]++;
	b[x-1][y]++;
	b[x-1][y-1]++;
	b[x-1][y+1]++;
	b[x+1][y-1]++;
	b[x+1][y+1]++;
}
bool bj()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]!='*'&&a[i][j]!=b[i][j])return 0;	
	return 1;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf(" %c",&a[i][j]);
			if(a[i][j]=='.')a[i][j]=0;
			else if(a[i][j]!='*')a[i][j]-='0';
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='*')jia(i,j);			
	if(bj())printf("YES");
	else printf("NO");
	return 0;
}