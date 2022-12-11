#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,ans[3],p[400040];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&p[i]);
		int last=0,tot=0;
		for(int i=1;i<=n/2;++i)
			if(p[i]!=p[i+1]&&(tot==0||i-last>ans[0]))
			{
				if(tot<=1)
				{
					ans[tot++]=i-last;
					last=i;
					if(tot==2)break;
				}
			}
		ans[2]=0;
		for(int i=last+1;i<=n/2;++i)
			if(p[i]!=p[i+1])ans[2]=i-last;
		if(tot==2&&ans[2]>ans[0])printf("%d %d %d\n",ans[0],ans[1],ans[2]);
		else printf("0 0 0\n");
	}
	return 0;
}