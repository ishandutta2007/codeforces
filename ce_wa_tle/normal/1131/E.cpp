#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=1e9+7,mod2=mod*mod;typedef ll aN[N];char s[N];ll f[N][27];
void qmax(ll&a,ll b){if(a<b)a=b;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll n=readll();rep(i,1,26)f[0][i]=0;
    rep(t,1,n){
        ll*now=f[t];const ll*lst=f[t-1];scanf("%s",s+1);ll m=strlen(s+1),fn=0,ln=0,fc=s[1]-96,lc=s[m]-96;
        ll ls=0;rep(i,1,m)if(s[i+1]!=s[i]){qmax(now[s[i]-96],i-ls),fn=fn?:i-ls,ln=i-ls,ls=i;}
        rep(i,1,26)qmax(now[i],!!lst[i]);if(lst[fc])qmax(now[fc],1+fn);if(lst[lc])qmax(now[lc],1+ln);
        if(fc==lc&&lst[fc])qmax(now[fc],fn+ln+1);if(fn==m)qmax(now[fc],m*(lst[fc]+1)+lst[fc]);
    }ll ans=0;rep(i,1,26)ans=std::max(ans,f[n][i]);printf("%lld\n",ans);return 0;
}