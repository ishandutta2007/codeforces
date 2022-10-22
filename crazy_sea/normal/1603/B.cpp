#include<cstdio>
using namespace std;
int x,y,T;
bool check(int x,int y,int n)
{
	if(n%x==y%n) return 1;
	else return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		if(x==y) printf("%d\n",x);
		else
		{
			if(x>y) printf("%lld\n",x*999999999ll+y);
			else
			{
				x=y-y%x;
				printf("%d\n",(x+y)/2);
			}
		}
	}
}