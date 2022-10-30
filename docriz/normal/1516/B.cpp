#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,a[2005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]^=a[i-1];
		int ok=0;
		int i;
		for(i=1;i<n;i++)
		{
			if(a[i]==a[n])break;
		}
		if(i==n)goto tag;
		for(i++;i<n;i++)if(a[i]==0)ok=1;
		tag:;
		if(ok||a[n]==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}