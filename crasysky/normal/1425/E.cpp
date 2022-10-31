#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,ll>
#define mp make_pair
#define fi first
#define se second
#define ll long long 
using namespace std;
const int N=1e6+6; ll a[N]; int d[N];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%lld",&a[i]),a[i]+=a[i-1];
	rep(i,1,n) scanf("%d",&d[i]);
	if (k==0){
		ll ans=0; rep(i,1,n) ans=max(ans,a[n]-a[i-1]-d[i]);
		printf("%lld\n",ans);
	}
	if (k==1){
		ll ans=max(a[n]-a[n-1]-d[n],0LL);
		rep(i,1,n-1) ans=max(ans,a[n-1]-d[i]);
		rep(i,2,n) ans=max(ans,a[n]-a[i-1]-d[i]);
		rep(i,2,n) ans=max(ans,a[n]-d[1]-(a[i]-a[i-1]));
		sort(d+1,d+1+n),ans=max(ans,a[n]-d[1]-d[2]);
		printf("%lld\n",ans);
	}
	if (k>=2){
		ll ans=max(a[n]-a[n-1]-d[n],0LL); 
		rep(i,1,n-1) ans=max(ans,a[n]-d[i]);
		printf("%lld\n",ans);
	}
	return 0;
}