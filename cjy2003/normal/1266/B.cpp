#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	long long x;
	while(t--)
	{
		scanf("%lld",&x);
		if(x<=14){printf("NO\n");continue;}
		x%=14;if(!x)x=14;
		if(x<=6)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}