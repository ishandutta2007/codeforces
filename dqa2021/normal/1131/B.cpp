#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[10010],b[10010];
int ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",a+i,b+i);
		ans+=max(0,min(a[i],b[i])-max(a[i-1],b[i-1])+1);
		if (a[i]==b[i]&&i!=n) ans--;
	}
	printf("%d\n",ans);
	return 0;
}