#include<cstdio>
#include<cmath>
using namespace std;
int n,T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",((int)floor(sqrt(n+n-1))-1)/2);
	}
}