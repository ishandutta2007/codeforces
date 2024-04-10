#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,ntot,mtot;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		if (x&1) ntot++;
	}
	for (int i=1,x;i<=m;i++)
	{
		scanf("%d",&x);
		if (x&1) mtot++;
	}
	printf("%d\n",min(ntot,m-mtot)+min(n-ntot,mtot));
	return 0;
}