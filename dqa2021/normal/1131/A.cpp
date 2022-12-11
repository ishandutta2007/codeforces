#include<cstdio>
#include<algorithm>
using namespace std;

int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n",b+d+b+d+a+a+4);
	return 0;
}