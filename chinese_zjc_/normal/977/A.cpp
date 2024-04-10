#include<cstdio>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	while(k>0)
	{
		if(n%10==0)
		{
			n/=10;
		}
		else
		{
			--n;
		}
		--k;
	}
	printf("%d",n);
	return 0;
}