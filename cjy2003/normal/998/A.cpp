#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[11],mini=1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[mini]>a[i])mini=i;
	}
	if(n==1)printf("-1");
	else if(n==2)
	{
		if(a[1]==a[2])printf("-1");
		else printf("1\n%d",1);	
	}
	else printf("1\n%d",mini);
	return 0;
}