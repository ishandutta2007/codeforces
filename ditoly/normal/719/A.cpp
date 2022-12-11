#include<cstdio>
#define MAXN 92
int a[MAXN+5];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	if(a[n]==15)return 0*puts("DOWN");
	if(a[n]==0)return 0*puts("UP");
	if(n==1)return 0*puts("-1");
	if(a[n]<a[n-1])puts("DOWN");
	else puts("UP");
}