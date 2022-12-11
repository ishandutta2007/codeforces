#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
long long n,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		int p=0;ans=0;
		for(int i=30;~i;--i)if(n>=(1ll<<2*i)){p=i;break;}
	//	printf("%d\n",p);
		ans=(1ll<<2*p)+(n-(1ll<<2*p))/3;
		if(n%3==2)
		{
			long long ans1=2;
			for(int i=p-1;~i;--i)
			{
				ans1<<=2;
				switch ((ans>>2*i)&3)
				{
					case 0:break;
					case 1:ans1|=2;break;
					case 2:ans1|=3;break;
					case 3:ans1|=1;break;
				}
			}
			ans=ans1;
		}
		else if(n%3==0)
		{
			long long ans1=3;
			for(int i=p-1;~i;--i)
			{
				ans1<<=2;
				switch ((ans>>2*i)&3)
				{
					case 0:break;
					case 1:ans1|=3;break;
					case 2:ans1|=1;break;
					case 3:ans1|=2;break;
				}
			}
			ans=ans1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}