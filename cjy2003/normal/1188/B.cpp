#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<int,int>m;
int n,mod,k;
long long ans;
int main()
{
	scanf("%d %d %d",&n,&mod,&k);
	int a;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		int res=(1ll*a*a%mod*a%mod*a%mod+mod-1ll*k*a%mod)%mod;
		ans+=m[res];
		++m[res];
	}
	printf("%lld",ans);
	return 0;
}