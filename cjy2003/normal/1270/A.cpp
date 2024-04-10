#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int n,k1,k2;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&k1,&k2);
		int x;
		bool flag=0;
		for(int i=1;i<=k1;++i)
		{
			scanf("%d",&x);
			if(x==n)flag=1;
		}
		for(int i=1;i<=k2;++i)scanf("%d",&x);
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}