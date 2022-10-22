#include<cstdio>
using namespace std;
int n,T,a,s,mn;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		mn=0x3f3f3f3f;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(mn==a) s++;
			else if(mn>a)
			{
				mn=a;
				s=1;
			}
		}
		printf("%d\n",n-s);
	}
}