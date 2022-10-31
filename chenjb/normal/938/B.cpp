#include<cstdio>
#include<algorithm>
using namespace std;
int n,l,r;
int main()
{
	scanf("%d",&n);
	l=1;
	r=1000000;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x<=500000)
		{
			l=max(l,x);
		}
		else
		{
			r=min(r,x);
		}
	}
	printf("%d\n",max(l-1,1000000-r));
	return 0;
}