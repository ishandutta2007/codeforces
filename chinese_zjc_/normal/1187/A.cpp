#include<cstdio>
using namespace std;
int n,a,b,c;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(b>c)
		{
			printf("%d\n",a-c+1);
			continue;
		}
		else
		{
			printf("%d\n",a-b+1);
		}
	}
	return 0;
}