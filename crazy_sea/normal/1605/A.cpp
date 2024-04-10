#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",(abs(a+c-b-b)%3)>0);
	}
}