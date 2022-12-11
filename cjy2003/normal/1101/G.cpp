#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p[40],a,s,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		s^=a;
		for(int j=30;j>=0;--j)
			if((a>>j)&1)
			{
				if(!p[j])
				{
					p[j]=a;
					++ans;
					break;
				}
				else a^=p[j];
			}
	}
	if(s)printf("%d",ans);
	else printf("-1");
	return 0;
}