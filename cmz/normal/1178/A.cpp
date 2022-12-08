// luogu-judger-enable-o2
#include<cstdio>
using namespace std;
long long a[1001],sum,mx,ans[1001],n,sm,tot;
int kk;
int main() {
	scanf("%I64d",&n);
	for(long long i = 1; i <= n; i++)scanf("%I64d",&a[i]);
	for (long long i=1; i<=n; ++i) sum+=a[i];
	mx=a[1]; ans[1]=1; tot=1; sm=a[1];
	for(long long i=1;i<=n;i++) if(a[i]*2<=mx) sm+=a[i],ans[++tot]=i;
	if(sm*2 > sum) { 
		printf("%I64d\n",tot);
		for(long long i = 1; i <= tot; i++) printf("%I64d ",ans[i]);
	} else printf("0\n");
	return 0;
}