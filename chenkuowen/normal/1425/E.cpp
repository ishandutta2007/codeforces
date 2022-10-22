#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e6;
ll a[N],d[N],mi[N],mi2[N],sum[N];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	mi[0]=mi2[n+1]=(ll)1e18; sum[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		scanf("%lld",&d[i]);
		mi[i]=min(mi[i-1],d[i]);
	}
	for(int i=n;i>=1;--i) mi2[i]=min(mi2[i+1],d[i]);
	ll ans=0;
	if(k==0){
		for(int i=1;i<=n;++i)
			ans=max(ans,sum[n]-sum[i-1]-d[i]);
	}else if(k==1){
		for(int i=1;i<n;++i)
			ans=max(ans,sum[n]-mi2[i+1]-d[i]);
		ans=max(ans,sum[n-1]-mi[n-1]);
		for(int i=2;i<=n;++i)
			ans=max(ans,sum[n]-sum[i-1]-d[i]);
		for(int i=2;i<n;++i)
			ans=max(ans,sum[n]-d[1]-a[i]);
	}else if(k>=2){
		for(int i=1;i<n;++i)
			ans=max(ans,sum[n]-d[i]);
		ans=max(ans,a[n]-d[n]);
	}
	printf("%lld\n",ans);
	return 0;
}