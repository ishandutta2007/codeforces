#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	printf("%d\n",min(min(a,b),min(c/2,min(d/7,e/4))));
}