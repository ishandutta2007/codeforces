#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=998244353;typedef ll aN[N];aN ny,b,a,s;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct bit{
    aN f;ll n;void set(ll n_){n=n_;}void update(ll u,ll c){while(u<=n)f[u]+=c,u+=u&-u;}
    ll query(ll u){ll res=0;while(u)res+=f[u],u&=~-u;return res;}
}t;
int main(){
    ll n=readll(),sum;ny[1]=1;rep(i,2,std::max(4ll,n))ny[i]=(mod-mod/i)*ny[mod%i]%mod;t.set(n);
    rep(i,1,n)s[i]=s[i-1],~(a[i]=readll())?b[a[i]]=1:++s[i];sum=s[n]*(s[n]-1)%mod*ny[4]%mod;rep(i,1,n)b[i]=!b[i]+b[i-1];
    rep(i,1,n)if(~a[i])sum=(sum+i-s[i]-t.query(a[i])-1+(s[i]*(b[n]-b[a[i]])+(s[n]-s[i])*b[a[i]])%mod*ny[b[n]])%mod,
    t.update(a[i],1);printf("%lld\n",sum);return 0;
}