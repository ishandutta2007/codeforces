#include<bits/stdc++.h>
#define N 100
using namespace std;
int T,n,k[N+5],h[N+5],last,high;
long long ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n),ans=0;
		for(int i=1;i<=n;++i) scanf("%d",k+i);
		for(int i=1;i<=n;++i) scanf("%d",h+i);
		last=k[n],high=h[n];
		for(int i=n-1;i;--i)
			if(last-high>=k[i]) ans+=1ll*high*(high+1)>>1,high=h[i],last=k[i];
			else if(h[i]>high-(last-k[i])) high=h[i]+last-k[i];
		ans+=1ll*high*(high+1)>>1;
		printf("%lld\n",ans);
	}
	return 0;
}