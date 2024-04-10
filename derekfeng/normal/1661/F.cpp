#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200004];
ll m,ans;
map<ll,int>mp;
int cnt[1000005];
ll calc(int t,int b){
	int A=t%b,B=b-t%b,x=t/b;
	return (ll)(x+1)*(x+1)*A+(ll)x*x*B;
}
void add(ll x,int w){
	if(x<=1e6)cnt[x]+=w;
	else mp[-x]+=w;
}
void upd(int t){
	ll cur=(ll)t*t;
	for(int l=1,r;l<=t;l=r+1){
		int x=t/l;r=t/x;
		if(x==t)continue;
		add(cur-calc(t,l),1);
		if(l<r)add(calc(t,l)-calc(t,l+1),r-l);
		cur=calc(t,r);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		ans+=(ll)(a[i]-a[i-1])*(a[i]-a[i-1]);
		upd(a[i]-a[i-1]);
	}
	if(ans<=m)return puts("0"),0;
	int ret=0;
	for(auto [d,x]:mp){
		ll w=-d;
		if(ans-w*x>m){
			ans-=w*x,ret+=x;
			continue;
		}
		ret+=(ans-m+w-1)/w;
		printf("%d\n",ret);
		return 0;
	}
	for(ll i=1e6;i>0;i--)if(cnt[i]){
		ll w=i;int x=cnt[i];
		if(ans-w*x>m){
			ans-=w*x,ret+=x;
			continue;
		}
		ret+=(ans-m+w-1)/w;
		printf("%d\n",ret);
		return 0;
	}
}