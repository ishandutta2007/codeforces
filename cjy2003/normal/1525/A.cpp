#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int k;
		scanf("%d",&k);
		int g=gcd(k,100-k);
		printf("%d\n",100/g);
	}
	return 0;
}