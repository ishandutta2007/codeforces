#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll maxn=5e5+10;
ll n,m,a[maxn],fa[maxn],pre[maxn],Two[maxn],suf[maxn],blo[maxn];
ll sum[maxn],ans[maxn];
vector <pair <ll,ll> > que[maxn];
inline ll power(ll a,ll b){
	ll res=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) res=1ll*res*a%mod;
	return res;
}
inline ll add(ll x){
	return x>=mod?x-mod:x;
}
inline ll sub(ll x){
	return x<0?x+mod:x;
}
inline ll Get(ll l,ll r){
	return sub((suf[l]-1ll*suf[r+1]*Two[r-l+1])%mod);
}
inline ll ask(ll x){
	if (fa[x]==x) return x; else return fa[x]=ask(fa[x]);
}
inline void merge(ll x,ll y){
	fa[x]=fa[y]; pre[y]=pre[x];
	ll dis=x-pre[x];
	if (blo[y]>0&&dis>=30) blo[y]=mod; else 
	if ((blo[x]+((1ll*blo[y])<<dis))>mod) blo[y]=mod;
	else blo[y]=(blo[x]+((1ll*blo[y])<<dis));
}
int main(){
	//freopen(".in","r",stdin);
//	freopen("my.out","w",stdout);
	scanf("%lld%lld",&n,&m); Two[0]=1;
	for (ll i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		Two[i]=2ll*Two[i-1]%mod; fa[i]=i; pre[i]=i-1; blo[i]=a[i];
		a[i]=sub(a[i]);
	}
	for (ll i=n;i>=1;--i) suf[i]=add(2*suf[i+1]%mod+a[i]);
	for (ll i=1,l,r;i<=m;++i){
		scanf("%lld%lld",&l,&r);
		que[r].push_back(make_pair(i,l));
	}
	for (ll i=1;i<=n;++i){
		while (blo[i]>=0&&pre[i]>0) merge(pre[i],i);
		sum[i]=add(sum[pre[i]]+2ll*Get(pre[i]+1,i)%mod);
		for (ll j=0;j<(ll)que[i].size();++j){
			ll now=ask(que[i][j].second);
			ans[que[i][j].first]=add(sub(sum[i]-sum[now])+Get(que[i][j].second,now));
		}
	}
	for (ll i=1;i<=m;++i) printf("%lld\n",ans[i]);
	return 0;
}