#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int a[N],ans[N],n,q,T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int x=0;
		for(int i=n;i;i--)
		{
			ans[i]=0;
			if(a[i]<=x) ans[i]=1;
			else if(x+1<=q) x++,ans[i]=1;
		}
		for(int i=1;i<=n;i++) printf("%d",ans[i]);
		printf("\n");
	}
}