#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
ll x,y,z,ans,T;
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&x,&y);
		z=ceil(sqrt(x+1));
		if(z>y+1) z=y+1;
		ans=(z-2)*(z-1)/2;
		for(ll l=z+1,r;l<=min(x,y+1);l=r+1)
		{
			r=min(x/(x/l),y+1);
			ans+=(r-l+1)*(x/l);
		}
		printf("%lld\n",ans);
	}
	return 0;
}