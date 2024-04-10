#include<cstdio>
int n,m,w[20];
bool ok[20];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",w+i);
	while (m--)
	{
		int tmp;
		scanf("%d",&tmp);
		ok[tmp]=true;
	}
	for (int i=1;i<=n;i++) if (ok[w[i]]) printf("%d ",w[i]);
	putchar('\n');
	return 0;
}