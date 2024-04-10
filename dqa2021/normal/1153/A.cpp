#include<cstdio>
#include<algorithm>
using namespace std;

int n,t;
int mint=0x7fffffff,minpos;
int main()
{
	scanf("%d%d",&n,&t);
	for (int i=1,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if (x>=t)
		{
			if (x<mint) mint=x,minpos=i;
		}
		else if ((t-x)%y==0) mint=t,minpos=i;
		else
		{
			if (t+y-(t-x)%y<mint) mint=t+y-(t-x)%y,minpos=i;
		}
	}
	printf("%d\n",minpos);
	return 0;
}