#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[200020];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int mi=0x3f3f3f3f,p;
		bool flag=0;
		for(int i=1;i<=n;++i)
		{
			if(mi<a[i]-i)
			{
				flag=1;
				printf("YES\n%d %d\n",p,i);
				break;
			}
			if(a[i]-i<mi)mi=a[i]-i,p=i;
		}
		if(!flag)
		{
			reverse(a+1,a+1+n);
			mi=0x3f3f3f3f;
			for(int i=1;i<=n;++i)
			{
				if(mi<a[i]-i)
				{
					flag=1;
					printf("YES\n%d %d\n",n+1-i,n+1-p);
					break;
				}
				if(a[i]-i<mi)mi=a[i]-i,p=i;			
			}
	
		}
		if(!flag)printf("NO\n");
	}
	return 0;
}