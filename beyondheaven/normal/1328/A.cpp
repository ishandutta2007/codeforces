#include<cstdio>
int main()
{
	int T,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",(b-a%b)%b);
	}
	return 0;
}