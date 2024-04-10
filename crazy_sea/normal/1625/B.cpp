#include<cstdio>
#define N 1500010
using namespace std;
int t[N],a[N],n,ans,T;
void calc(int x,int y)
{
	if(y==0) return;
	if(n-x+y>ans) ans=n-x+y;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);ans=-1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),calc(i,t[a[i]]),t[a[i]]=i;
		for(int i=1;i<=n;i++) t[a[i]]=0;
		printf("%d\n",ans);
	}
}