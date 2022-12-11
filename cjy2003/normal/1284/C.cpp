#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,mod,jc[250050],ans;
int main()
{
	scanf("%d %d",&n,&mod);
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=1ll*jc[i-1]*i%mod;
	for(int i=1;i<=n;++i)ans=(ans+1ll*(n+1-i)*(n+1-i)%mod*jc[i]%mod*jc[n-i])%mod;
	printf("%d",ans);
	return 0;
}