#include<cstdio>
#include<algorithm>
using namespace std;

int n,w[20];
int ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",w+i);
	for (int i=0;(1<<i)<=n;i++)
	{
		for (int j=1;j<=n;j+=(1<<i))
		{
			bool flg=true;
			for (int u=j+1;u<j+(1<<i);u++) if (w[u]<w[u-1]) flg=false;
//			printf("from %d to %d len %d %d\n",j,j+(1<<i)-1,(1<<i),flg);
			if (flg) ans=max(ans,(1<<i));
		}
	}
	printf("%d\n",ans);
	return 0;
}