#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a[3];
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	int ret;
	sort(a,a+3);
	ret=(a[0]+a[1]-1)*(a[0]+a[2]-1);
	ret-=(a[0]-1)*a[0];
	printf("%d\n",ret);
}