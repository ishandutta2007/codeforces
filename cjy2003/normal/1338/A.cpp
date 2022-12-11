#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[100010],mx,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		mx=-1000000000,ans=0;
		for(int i=1,x;i<=n;++i)
		{
			scanf("%d",&x);
			mx=max(mx,x);
			ans=max(ans,mx-x);
		}
		if(!ans)
		{
			printf("0\n");
			continue;
		}
		for(int i=30;~i;--i)if(ans>>i&1){printf("%d\n",i+1);break;}
	}
	return 0;
}