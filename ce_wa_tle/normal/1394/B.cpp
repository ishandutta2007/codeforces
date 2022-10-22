#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1116333,inf=1e9,mod=1e9+7;typedef ll aN[N];aN u,v,d,rk,p,c;ll ans=0,n,m,k,cnt,no=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int cmp1(ll a,ll b){return u[a]==u[b]?c[a]<c[b]:u[a]<u[b];}ll id[17][17],limit[100];
int cmp2(ll a,ll b){return v[a]==v[b]?c[a]<c[b]:v[a]<v[b];}
void dfs(ll u,ll now){if(u==k+1)return(void)++ans;rep(i,1,u)if(!(limit[id[u][i]]&now))dfs(u+1,now|1ll<<id[u][i]);}
int main(){
    n=readll(),m=readll(),k=readll(),cnt=0;rep(i,1,m)u[i]=readll(),v[i]=readll(),c[p[i]=i]=readll();
    rep(i,1,k)rep(j,1,i)id[i][j]=++cnt;std::sort(p+1,p+m+1,cmp1);ll w=0,x=0;
    rep(i,1,m)d[u[p[i]]]++,rk[p[i]]=u[p[i]]!=u[p[i-1]]?1:rk[p[i-1]]+1;std::sort(p+1,p+m+1,cmp2);
    rep(i,1,m)x=id[d[u[p[i]]]][rk[p[i]]],v[p[i]]!=v[p[i-1]]&&(w=0),d[v[p[i]]]?limit[x]|=w:no|=1ll<<x,w|=1ll<<x;
    rep(i,1,cnt)if(limit[i]>>i&1)no|=1ll<<i;rep(i,1,cnt)limit[i]|=no;
//    if(n==200000)rep(i,1,cnt){rep(j,1,cnt)putchar((limit[i]>>j&1)^48),putchar(' ');puts("");}
    if(k==1&&no==2)return puts("0"),0;
    rep(i,1,cnt)rep(j,1,cnt)if(limit[i]>>j&1)limit[j]|=1ll<<i;dfs(1,0);printf("%lld\n",ans);
    return 0;
}