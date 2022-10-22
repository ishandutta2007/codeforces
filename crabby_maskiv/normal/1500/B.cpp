#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll n,m;
ll k;
int a[N],b[N];
ll d;
pair<ll,ll> exgcd(ll a,ll b){
	if(!b){
		d=a;
		return {1,0};
	}
	pair<ll,ll> ans=exgcd(b,a%b);
	return {ans.second,ans.first-(a/b)*ans.second};
}
int pos[N];
ll x[N];
int main(){
	int i,j;
	scanf("%d%d%lld",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	int len=2*max(n,m);
	for(i=1;i<=n;i++) pos[a[i]]=i;
	pair<ll,ll> f=exgcd(n,m);
	ll l=0,r=1e18;
	for(i=1;i<=m;i++){
		if(!pos[b[i]]) continue;
		int c=i-pos[b[i]];
		if(c%d){
			x[i]=-1;
			continue;
		}
		x[i]=f.first*(c/d);
		x[i]=(x[i]%(m/d)+(m/d))%(m/d);
	}
	while(r>l){
		ll mid=l+r+1>>1;
		ll cnt=mid;
		for(i=1;i<=m;i++){
			if(!pos[b[i]]||x[i]==-1) continue;
			if(x[i]*n+pos[b[i]]>mid) continue;
			cnt-=(mid-(x[i]*n+pos[b[i]]))/(n*m/d)+1;
		}
		if(cnt<k) l=mid;
		else r=mid-1;
	}
	cout<<l+1;
	return 0;
}