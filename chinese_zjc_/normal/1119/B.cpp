#include<cstdio>
#include<algorithm>
using namespace std;
int a[1001],n,h;
bool go(int m)
{
	int l=h;
	for(int i=m;i>0;i-=2)
	{
		if(l>=a[i])
		{
			l-=a[i];
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i)
	{
		sort(a+1,a+1+i);
		if(!go(i))
		{
			printf("%d",i-1);
			return 0;
		}
	}
	printf("%d",n);
	return 0;
}