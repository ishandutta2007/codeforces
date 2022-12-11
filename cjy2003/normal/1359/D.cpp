#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100010],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int mx=1;mx<=30;++mx)
	{
		int nmi=0,cur=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i]>mx)nmi=0,cur=0;
			else
			{
				cur+=a[i];
				if(nmi>cur)nmi=cur;
				ans=max(ans,cur-nmi-mx);
			}
		}
	}
	printf("%d",ans);
	return 0;
}