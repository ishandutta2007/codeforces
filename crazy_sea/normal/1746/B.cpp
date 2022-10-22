#include<cstdio>
#include<algorithm>
using namespace std;
int ans,n,T,x,t[1000010][2],s1,s0;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			t[i][0]=t[i-1][0],t[i][1]=t[i-1][1];
			scanf("%d",&x),t[i][x]++;
		}
		ans=n;
		for(int i=0;i<=n;i++)
		{
			s1=t[i][1];
			s0=t[n][0]-t[i][0];
			ans=min(ans,max(s1,s0));
		}
		printf("%d\n",ans);
	}
}