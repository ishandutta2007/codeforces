#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,T,a,s1,s2;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(a>s1) s2=s1,s1=a;
			else if(a>s2) s2=a;
		}
		printf("%d\n",s1+s2);s1=s2=0;
	}
}