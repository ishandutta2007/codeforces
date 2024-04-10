#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	   scanf("%d",&a[i]);
	sort(a,a+n);
	if(!(n%2))printf("%d",a[(n/2)-1]);
	else printf("%d",a[n/2]);
	return 0;
 }