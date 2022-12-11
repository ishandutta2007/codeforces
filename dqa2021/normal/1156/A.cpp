#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[110];
int ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if (i==1) continue;
		if (a[i-1]==1&&a[i]==2) ans+=3;
		else if (a[i-1]==1&&a[i]==3) ans+=4;
		else if (a[i-1]==2&&a[i]==1) ans+=3;
		else if (a[i-1]==2&&a[i]==3) return puts("Infinite"),0;
		else if (a[i-1]==3&&a[i]==1) ans+=4;
		else if (a[i-1]==3&&a[i]==2) return puts("Infinite"),0;
		if (i>2&&a[i-2]==3&&a[i-1]==1&&a[i]==2) ans--;
	}
	puts("Finite");
	printf("%d\n",ans);
	return 0;
}