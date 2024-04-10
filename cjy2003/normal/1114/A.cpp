#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x,y,z,a,b,c;
int main()
{
	scanf("%d %d %d %d %d %d",&x,&y,&z,&a,&b,&c);
	if(a<x)
	{
		printf("NO");
		return 0;
	}
	if(a+b<x+y)
	{
		printf("NO");
		return 0;
	}
	if(a+b+c<x+y+z)
	{
		printf("NO");
		return 0;
	}
	printf("YES");
	return 0;
}