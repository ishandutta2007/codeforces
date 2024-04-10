#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,k;
int w[100010];
int ww[100010];
int ans;
int main()
{
	scanf("%d%d%d",&n,&m,&k); ans=n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",w+i);
		if (i!=1) ww[i-1]=w[i]-w[i-1]-1;
	}
	sort(ww+1,ww+n); int top=1;
	while (n>k)
	{
		ans+=ww[top++];
		n--;
	}
	printf("%d\n",ans);
	return 0;
}