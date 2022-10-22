#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=998244353;typedef ll aN[N];ll p[1024],s[33];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll sum,s;void add(const node&b,ll k){sum=(sum+b.sum*10+k*b.s)%mod,s=(s+b.s)%mod;}}f[33][1024],g[33][1024];
ll calc(ll r,ll k){
    static ll pq=0;if(!pq++){ref(i,1,1024)p[i]=p[i>>1]+(i&1);}ll t=0;while(r)s[t++]=r%10,r/=10;
    rep(i,0,t)ref(j,0,1024)f[i][j]=g[i][j]=(node){0,0};f[t][0].s=1;per(i,t-1,0)ref(j,0,1024)rep(k,0,9){
        const node&lstg=g[i+1][j];const node&lstf=f[i+1][j];
//        if(lstg.s||lstf.s)printf("%lld %lld %lld %lld %lld %lld %lld\n",k,i+1,j,lstg.s,lstf.s,lstg.sum,lstf.sum);
        node &nowg=k||j?g[i][j|1<<k]:g[i][0],&nowf=k||j?f[i][j|1<<k]:f[i][0];
        if(k<s[i])nowg.add(lstf,k);else nowg.add(lstg,k);if(k<=s[i])nowf.add(lstf,k);else nowf.add(lstg,k);
    }ll res=0;ref(i,0,1024)if(p[i]<=k)res=(res+f[0][i].sum)%mod;return res;
}int main(){ll l=readll(),r=readll(),k=readll();printf("%lld\n",(calc(r,k)-calc(l-1,k)+mod)%mod);return 0;}