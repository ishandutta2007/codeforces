#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
int mi=0x3f3f3f3f,s[510],a[510],w[510],ans;
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;++i)a[i]=i;
	int x,y;
	for(int i=1;i<=n-k+1;++i)
	{
		printf("? ");
		for(int j=1;j<=k;++j)printf("%d ",a[j]);printf("\n");
		fflush(stdout);
		scanf("%d %d",&x,&y);w[x]=y;
		if(y<mi)
		{
			mi=y;
			memcpy(s,a,sizeof(s));
		}
		for(int j=1;j<=k;++j)if(a[j]==x)a[j]=i+k;
	}
	int o;
	for(int i=1;i<=n;++i)
	{
		bool flag=0;
		for(int j=1;j<=k;++j)
			if(s[j]==i)flag=1;
		if(!flag){o=i;break;}
	}
	for(int i=1;i<=k;++i)
		if(w[s[i]]!=mi)
		{
			int c=s[i];s[i]=o;
			printf("? ");
			for(int j=1;j<=k;++j)printf("%d ",s[j]);printf("\n");
			fflush(stdout);
			scanf("%d %d",&x,&y);
			ans+=y!=mi;
			s[i]=c;
		}
	printf("! %d",ans+1);
	fflush(stdout);
	return 0;
}