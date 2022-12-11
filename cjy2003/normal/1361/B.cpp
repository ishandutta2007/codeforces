#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int T,n,p,a[1000010],cnt[1000010],lim;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&p);
		lim=0;
		long long x=1;
		if(p==1)lim=10000000;
		else while(x<10000000)x*=p,++lim;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),++cnt[a[i]];
		sort(a+1,a+1+n);
		n=unique(a+1,a+1+n)-a-1;
		int ans=0;
		bool flag=0;
		for(int i=n;i;--i)
		{
			if(flag)ans=(ans+mod-cnt[a[i]])%mod;
			else
			{
				int cur=min(ans,cnt[a[i]]);
				ans-=cur,cnt[a[i]]-=cur;
				if(ans==0)
				{
					if(cnt[a[i]]&1)ans=1;
					else ans=0;					
				}
			}
			if(ans&&a[i]-a[i-1]>=lim)flag=1;
			if(a[i]-a[i-1]<lim)
			{
				long long cur=1ll*ans*kpow(p,a[i]-a[i-1]);
				if(cur>10000000)flag=1;
			}
			ans=1ll*ans*kpow(p,a[i]-a[i-1])%mod;
			cnt[a[i]]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}