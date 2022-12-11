#include<cstdio>
#include<algorithm>
using namespace std;
int a[6010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if(n%2!=0)printf("%d",a[n/2+1]);
	else printf("%d",a[n/2]);
	return 0;
}