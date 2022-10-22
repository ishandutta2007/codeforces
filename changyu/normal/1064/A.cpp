#include<cstdio>
#include<algorithm>
int a[3];
int main()
{
	scanf("%d%d%d",a,a+1,a+2);
	std::sort(a,a+3);
	printf("%d",std::max(a[2]+1-a[1]-a[0],0));
	return 0;
}