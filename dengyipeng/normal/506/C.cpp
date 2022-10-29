#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100005
#define ll long long 
using namespace std;

int n,m,K,i,j,k;
ll h[maxn],v[maxn],p,s[maxn];

int check(ll lim){
	ll cnt=0;
	for(i=1;i<=n;i++) cnt+=max(0ll,(h[i]+v[i]*m-lim+p-1)/p);
	if (cnt>m*K) return 0;
	for(i=0;i<=m;i++) s[i]=0;
	for(i=1;i<=n;i++) if (h[i]+v[i]*m>lim){
		for(ll res=(h[i]+v[i]*m-lim)%p;res<=h[i]+v[i]*m-lim;res+=p) if (res){
			if (res<=h[i]) s[1]++; else 
			if ((res-h[i]+v[i]-1)/v[i]+1>m) return 0; else 
				s[(res-h[i]+v[i]-1)/v[i]+1]++;
		}
	}
	cnt=0;
	for(i=1;i<=m;i++){
		cnt+=s[i];
		cnt=max(0ll,cnt-K);
	}
	return !cnt;
}

int main(){
	scanf("%d%d%d%lld",&n,&m,&K,&p);
	for(i=1;i<=n;i++) scanf("%lld%lld",&h[i],&v[i]);
	ll l=0,r=0,mid,ans;
	for(i=1;i<=n;i++) r=max(r,h[i]+v[i]*m);
	while (l<=r){
		mid=(l+r)>>1;
		if (check(mid)) 
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld",ans);
}