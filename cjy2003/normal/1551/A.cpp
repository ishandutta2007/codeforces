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
		int c1=n/3,c2=n/3;
		if(n%3==1)++c1;
		else if(n%3==2)++c2;
		printf("%d %d\n",c1,c2);
	}
	return 0;
}