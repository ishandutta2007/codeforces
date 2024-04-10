#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=1e5+7,k=65535,mod=1e9+7;typedef ll aN[N];
void qmax(ll&a,ll b){if(a<b)a=b;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll a[66],ny[66],jc[66],njc[66],popcount[k],S[66],T[66],r[66],p[66],dp[66][k],c[k],f[66],vis[66];
#define f(x...) af(x)
ll f(ll u){return f[u]^u?f[u]=f(f[u]):u;}
int main(){
    ll n=readll(),no,ans=1,sumT=0;rep(i,1,n)a[f[i]=i]=readll();
    ny[1]=jc[0]=jc[1]=njc[0]=njc[1]=1;rep(i,1,n)rep(j,1,n)if(i!=j&&a[j]%a[i]==0)(f(i)^f(j))&&(f[f(i)]=f(j)),r[j]=1;
    rep(i,2,n)jc[i]=jc[i-1]*i%mod,njc[i]=njc[i-1]*(ny[i]=(mod-mod/i)*ny[mod%i]%mod)%mod;
    rep(now,1,n)if(!vis[no=f(now)]){
        vis[no]=1;ll topT=0,topS=0;rep(i,now,n)if(f(i)==no)(r[i]?T[++topT]:S[++topS])=i;if(!topT)continue;sumT+=topT-1;
        rep(j,1,topT)p[j]=0;rep(i,1,topS)rep(j,1,topT)if(a[T[j]]%a[S[i]]==0)p[j]|=1<<(i-1);
        rep(i,1,(1<<topS)-1)c[i]=0;rep(j,1,topT)c[p[j]]++;
        ref(j,0,topS)rep(i,1,(1<<topS)-1)if(i>>j&1)c[i]+=c[i^1<<j];
        rep(j,0,topT)rep(i,0,(1<<topS)-1)dp[j][i]=0;dp[0][0]=1;
        rep(j,0,topT)rep(i,0,(1<<topS)-1)if(dp[j][i]){
            if(c[i]>j)dp[j+1][i]=(dp[j+1][i]+dp[j][i]*(c[i]-j)%mod)%mod;
            rep(k,1,topT)if(((p[k]&~i)&&(p[k]&i))||!i)dp[j+1][i|p[k]]=(dp[j+1][i|p[k]]+dp[j][i])%mod;
        }ans=ans*njc[topT-1]%mod*dp[topT][(1<<topS)-1]%mod;
    }printf("%lld\n",ans*jc[sumT]%mod);return 0; 
}