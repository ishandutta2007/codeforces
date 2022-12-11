#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[1000010];
bool vis[1000010];
int st[1000010],tp;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int x=1;
		while(!vis[x])
		{
			vis[x]=1;
			st[++tp]=x;
			x-=a[x];
		}
		int p=tp;
		while(st[p]!=x)--p;
		printf("%d\n",tp-p+1);
		for(int i=p;i<=tp;++i)printf("%d ",st[i]);printf("\n");
		tp=0;
		memset(vis+1,0,n);
	}
	return 0;
}