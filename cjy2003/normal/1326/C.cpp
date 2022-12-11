#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,k,p[200020],pos[200020],st[200020],tp;
int ans=1;
long long ans1;
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]),pos[p[i]]=i;
	for(int i=n;i>=n-k+1;--i)st[++tp]=pos[i],ans1+=i;
	sort(st+1,st+1+tp);
	for(int i=1;i<tp;++i)ans=1ll*ans*(st[i+1]-st[i])%mod;
	printf("%lld %d\n",ans1,ans);
	return 0;
}