#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int t;
		for(int i=30;;--i)if(n>>i&1){t=i;break;}
		printf("%d\n",(1<<t)-1);
	}
	return 0;
}