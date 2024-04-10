#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	int op=0,x;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(x&1)
		{
			if(op)printf("%d\n",(x-1)/2);
			else printf("%d\n",(x+1)/2);
			op^=1;
		}
		else printf("%d\n",x/2);
	}
	return 0;
}