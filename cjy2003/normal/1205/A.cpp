#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(!(n&1))printf("NO\n");
	else
	{
		printf("YES\n");
		printf("1 ");
		for(int i=4;i<=2*n;++i)
		{
			printf("%d ",i);
			if(i&1)i+=2; 
		}
		for(int i=2;i<=2*n;++i)
		{
			printf("%d ",i);
			if(i&1)i+=2; 
		}
	}
	return 0;
}