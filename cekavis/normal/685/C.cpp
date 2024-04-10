#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
const ll inf = 3e18;
int T, n;
ll a[3], x[N], y[N], z[N];
bool check(ll mid){
	ll l[4]={-2*inf, -2*inf, -2*inf, -2*inf}, r[4]={2*inf, 2*inf, 2*inf, 2*inf};
	for(int i=1; i<=n; ++i){
		l[0]=max(l[0], -x[i]+y[i]+z[i]-mid);
		l[1]=max(l[1], x[i]+y[i]-z[i]-mid);
		l[2]=max(l[2], x[i]-y[i]+z[i]-mid);
		l[3]=max(l[3], x[i]+y[i]+z[i]-mid);
		r[0]=min(r[0], -x[i]+y[i]+z[i]+mid);
		r[1]=min(r[1], x[i]+y[i]-z[i]+mid);
		r[2]=min(r[2], x[i]-y[i]+z[i]+mid);
		r[3]=min(r[3], x[i]+y[i]+z[i]+mid);
	}
	for(int i=0; i<2; ++i){
		ll L=0, R=0;
		for(int j=0; j<3; ++j){
			if((l[j]-i+1)>>1>(r[j]-i)>>1) goto skip;
			L+=a[j]=(l[j]-i+1)>>1, R+=(r[j]-i)>>1;
		}
		if((r[3]-i*3)>>1<(l[3]-i*3+1)>>1) goto skip;
		if(L<=(r[3]-i*3)>>1 && R>=(l[3]-i*3+1)>>1){
			ll x=max(0ll, ((l[3]-i*3+1)>>1)-L);
			for(int j=0; j<3; ++j){
				ll y=min(x, ((r[j]-i)>>1)-a[j]);
				a[j]+=y, x-=y;
			}
			for(int j=0; j<3; ++j) a[j]=a[j]*2+i;
			a[1]=(a[0]+a[1])/2, a[2]=(a[0]+a[2])/2, a[0]=a[1]+a[2]-a[0];
			return 1;
		}
		skip:;
	}
	return 0;
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%lld%lld%lld", x+i, y+i, z+i);
		ll l=0, r=inf, ans=0;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(check(mid)) ans=mid, r=mid-1; else l=mid+1;
		}
		check(ans);
		printf("%lld %lld %lld\n", a[0], a[1], a[2]);
	}
	return 0;
}