#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,c[300030],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	if(c[1]!=c[n])printf("%d",n-1);
	else
	{
		int p=n;
		while(c[p]==c[1])--p;
		ans=p-1;
		p=1;
		while(c[p]==c[n])++p;
		ans=max(ans,n-p);
		printf("%d",ans);
	}
	return 0;
}