#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,b[400040];
long long ans,sum[600060];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]),sum[b[i]-i+200000]+=b[i];
	for(int i=1;i<=n;++i)ans=max(ans,sum[b[i]-i+200000]);
	printf("%lld",ans);
	return 0;
}