#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=2e6+9,mod=1e9+7;typedef ll aN[N];char s[N];ll nxt[N],f[222][111][222];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int add(ll&u,ll v){u=(u+v)%mod;return 1;}
int main(){
    ll m=readll()*2,now;scanf("%s",s+1);ll n=strlen(s+1);nxt[1]=0;
    rfor(ll i=2,j=0;i<n;i++){while(j&&s[j+1]!=s[i])j=nxt[j];nxt[i]=s[j+1]!=s[i]?j:++j;/*printf("%lld->%lld\n",i,nxt[i]);*/}
    f[0][0][0]=1;rep(i,0,m-1)rep(j,0,m/2)rep(k,0,n)if(f[i][j][k]){//printf("%lld %lld %lld %lld\n",i,j,k,f[i][j][k]);
        now=k;while(now&&')'!=s[now+1])now=nxt[now];j&&add(f[i+1][j-1][k==n?n:now+(')'==s[now+1])],f[i][j][k]);
        now=k;while(now&&'('!=s[now+1])now=nxt[now];add(f[i+1][j+1][k==n?n:now+('('==s[now+1])],f[i][j][k]);
    }printf("%lld\n",f[m][0][n]);return 0;
}