#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=13,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];aN a,b,s,c[N];ll f[N][N][16667]; 
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void qmin(ll&a,ll b){if(a>b)a=b;}ll zh(ll u){return u<inf?u:-1;}
int main(){
    ll n=readll(),m=readll();rep(i,1,n)a[i]=readll();rep(i,1,m)b[i]=readll();rep(i,1,n)rep(j,1,m)c[i][j]=readll();
    s[1]=1;rep(i,1,m)s[i+1]=s[i]*(b[i]+1);const ll mx=s[m+1];memset(f,0x3f,sizeof f),f[1][0][0]=0;
    rep(i,1,n)rep(j,0,a[i]){rep(k,0,mx)if(f[i][j][k]<inf){//printf("f[%lld][%lld][%lld]=%lld\n",i,j,k,f[i][j][k]);
    rep(u,1,m)rep(v,1,std::min(a[i]-j,b[u]-k/s[u]%(b[u]+1)))qmin(f[i][j+v][k+v*s[u]],f[i][j][k]+c[i][u]);
    qmin(f[i+1][0][k],f[i][a[i]][k]);}}ll res=inf;rep(j,0,mx)qmin(res,f[n][a[n]][j]);printf("%lld\n",zh(res));return 0;
}