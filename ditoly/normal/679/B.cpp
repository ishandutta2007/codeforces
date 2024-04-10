#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
#define MN 100000
ll u[MN+5],z[MN+5],cnt;
inline ll f(ll x){return x*x*x;}
ll cal()
{
	ll s=0,i;
	for(i=1;i<=cnt;++i)z[i]=u[i];
	sort(z+1,z+cnt+1);
	for(i=1;i<=cnt;++i)if((s+=f(z[i]))>=f(z[i]+1))return 1e18;
	return s;
}
int main()
{
	ll m,i,x;
	scanf("%I64d",&m);
	for(i=1;i<=1e5;++i){do u[++cnt]=i;while(cal()<=m);--cnt;}
	while(true)
	{
		for(i=cnt;i;--i)
		{
			++u[i];
			if(cal()<=m)break;
			--u[i]; 
		}
		if(!i)break;
		sort(u+1,u+cnt+1);
	}
	printf("%I64d %I64d",cnt,cal());
}