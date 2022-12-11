#include<cstdio>
bool check(int x)
{
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	if(check(n))return 0*puts("1");
	if(n&1)
	{
		if(check(n-2))return 0*puts("2");
		else puts("3");
	}
	else puts("2");
}