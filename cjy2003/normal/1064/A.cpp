#include<cstdio>
#include<algorithm>
using namespace std;
int a[4];
int main()
{
	scanf("%d %d %d",&a[1],&a[2],&a[3]);
	sort(a+1,a+1+3);
	if(a[1]+a[2]>a[3])printf("0");
	else printf("%d",a[3]-a[2]+1-a[1]);
	return 0;
}