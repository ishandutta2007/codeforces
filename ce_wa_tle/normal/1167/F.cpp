#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=1e6+7,mod=1e9+7;typedef ll aN[N];aN a,p;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct bit{
    aN f;ll n,sum;ll query(ll u){ll res=0;while(u)res+=f[u],u&=~-u;return res%mod;}
    void set(ll n_){memset(f,sum=0,sizeof(ll)*(1+(n=n_)));}void add(ll u,ll c){sum+=c;while(u<=n)f[u]+=c,u+=u&-u;}
}t1,t2;int cmp(ll x,ll y){return a[x]<a[y];}
int main(){
    ll n=readll(),sum=0;rep(i,1,n)a[p[i]=i]=readll();std::sort(p+1,p+n+1,cmp);t1.set(n),t2.set(n);
    rep(i,1,n){ll now=p[i];sum+=a[now]*((n-now+1)*t1.query(now)%mod+now*(t2.sum-t2.query(now))%mod+now*(n-now+1)%mod)%mod;
    t1.add(now,now),t2.add(now,n-now+1);}printf("%lld\n",sum%mod);return 0; 
}
//....o...o....
//    j   i    
//ans=(n-i+1)j