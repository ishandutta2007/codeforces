#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,h;
int a[110],b[110],c[110][110];
int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for (int i=1;i<=m;i++) scanf("%d",a+i);
	for (int i=1;i<=n;i++) scanf("%d",b+i);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&c[i][j]);
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (!c[i][j]) putchar('0');
			else printf("%d",min(b[i],a[j]));
			putchar(j==m?'\n':' ');
		}
	return 0;
}