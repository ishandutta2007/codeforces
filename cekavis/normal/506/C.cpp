#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005, M = 5005;
int n, m, k, p, h[N], a[N], f[M];
bool check(ll x){
	ll sum=0;
	memset(f, 0, sizeof f);
	for(int i=1; i<=n; ++i) if(h[i]+(ll)a[i]*m>x){
		ll t=(h[i]+(ll)a[i]*m-x-1)/p+1;
		if((sum+=t)>m*k) return 0;
		for(int j=0; j<t; ++j) ++f[max(1ll, m-(x+(ll)j*p)/a[i]+1)];
	}
	for(int i=m; i; --i) if((f[i]+=f[i+1])>(m-i+1)*k) return 0;
	return 1;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &p);
	ll l=0, r=0, ans=0;
	for(int i=1; i<=n; ++i)
		scanf("%d%d", h+i, a+i), l=max(l, (ll)a[i]), r=max(r, h[i]+(ll)a[i]*m);
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)) ans=mid, r=mid-1; else l=mid+1;
	}
	printf("%lld\n", ans);
	return 0;
}