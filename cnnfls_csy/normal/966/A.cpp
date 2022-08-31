#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,q,c1,c2,v,x,y,xx,yy,i,j,num[500005],num2[500005],ans;
int main()
{
	scanf("%lld%lld%lld%lld%lld",&n,&m,&c1,&c2,&v); 
	for (i=1;i<=c1;i++) scanf("%lld",&num[i]);
	for (i=1;i<=c2;i++) scanf("%lld",&num2[i]);
	scanf("%lld",&q);
	while (q--)
	{
		scanf("%lld%lld%lld%lld",&x,&y,&xx,&yy);
		if (x==xx)
		{
			printf("%lld\n",abs(y-yy));
			continue;
		}
		ans=1ll<<60;
		long long pos=upper_bound(num+1,num+c1+1,y)-num;
		if (pos<=c1) ans=min(ans,abs(y-num[pos])+abs(yy-num[pos])+abs(x-xx));
		pos--;
		if (pos>=1) ans=min(ans,abs(y-num[pos])+abs(yy-num[pos])+abs(x-xx));
		pos=upper_bound(num2+1,num2+c2+1,y)-num2;
		if (pos<=c2) ans=min(ans,abs(y-num2[pos])+abs(yy-num2[pos])+(abs(x-xx)+v-1)/v);
		pos--;
		if (pos>=1) ans=min(ans,abs(y-num2[pos])+abs(yy-num2[pos])+(abs(x-xx)+v-1)/v);
		printf("%lld\n",ans); 
	}
	return 0;
}