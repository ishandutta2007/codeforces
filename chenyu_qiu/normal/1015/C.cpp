#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	int n,m;
	long long sum=0;
	long long compressed=0;
	scanf("%d%d",&n,&m);
	int before;
	int after;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&before,&after);
		sum+=before;
		compressed+=after;
		a[i]=before-after;
	}
	int num;
	sort(a,a+n);
	if(compressed>m)num=-1;
	else{
		long long space=sum-m;
		int i=n-1;
		while(space>0)
		{
			space-=a[i];
			i--;
		}
		num=n-1-i;
	}
	printf("%d",num);
	return 0;
}