#include <cstdio>

using namespace std;

int main()
{
	int n,k,i;

	scanf("%d%d",&n,&k);

	k = (240-k)/5;

	for(i=1;i*(i+1)<=k*2;i++);

	printf("%d\n",i-1>n?n:i-1);

	return 0;
}