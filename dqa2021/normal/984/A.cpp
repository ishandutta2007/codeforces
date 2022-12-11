#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[1010];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
	nth_element(a+1,a+(n+1>>1),a+n+1);
	printf("%d\n",a[n+1>>1]);
	return 0;
}