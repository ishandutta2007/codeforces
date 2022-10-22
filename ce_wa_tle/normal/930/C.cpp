#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=414514,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(){char c=getchar();for(;c<'A'||c>'z';c=getchar());return c;}
ll a[1145141],f[1145141],h[1145141];
struct bit{
    ll n;void clear(ll n_=0){memset(f,0,sizeof(ll)*((n=n_?:n)+2));}
    void update(ll u,ll c){for(u++;u<=n;f[u]<c&&(f[u]=c),u+=u&-u);}
    ll query(ll u){ll c=0;for(u++;u;c<f[u]&&(c=f[u]),u&=~-u);return c;}
}b;
int main(){
    ll n=readll(),m=readll(),ans=0,x;rep(i,1,n)a[readll()]++,a[readll()+1]--;
    b.clear(n);rep(i,1,m)a[i]+=a[i-1],b.update(a[i],h[i]=b.query(a[i])+1);//,printf("%lld\n",h[i]);
    b.clear(n);per(i,m,1)b.update(a[i],x=b.query(a[i])+1),ans=std::max(ans,x+h[i-1]);printf("%lld\n",ans);
	return 0;
}