#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int q;
long long l,r,d;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%I64d %I64d %I64d",&l,&r,&d);
		if(d<l)printf("%I64d\n",d);
		else printf("%I64d\n",r/d*d+d);
	}
	return 0;
}