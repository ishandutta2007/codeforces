#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=2e5+9,inf=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll d[3333],g[3333][3333],p[3333],pop[222],n,jc[114];
int cmp(ll a,ll b){return d[a]<d[b];}void rev(ll u){d[u]=n-d[u]-1;rep(i,1,n)if(i^u)d[i]+=(g[u][i]^=1,g[i][u]^=1)*2-1;}
int check(){if(!p[1])rep(i,1,n)p[i]=i;std::sort(p+1,p+n+1,cmp);ll s=0;rep(i,1,n-1)if(!(s+=i-1-d[p[i]]))return 0;return 1;}
int main(){
    n=readll();rep(i,1,n)rep(j,1,n)d[i]+=g[i][j]=readchar()^48;if(check())return puts("0 1"),0;
    if(n<=6){ll min=inf,sum=0;ref(i,1,(1<<n)){if((pop[i]=pop[i>>1]+(i&1))>min)continue;rep(j,1,n)if(i>>(j-1)&1)rev(j);
    if(check()){if(pop[i]<min)min=pop[i],sum=0;sum++;}rep(j,1,n)if(i>>(j-1)&1)rev(j);}jc[0]=1;rep(i,1,n)jc[i]=jc[i-1]*i;
    min==inf?puts("-1"):printf("%lld %lld\n",min,sum*jc[min]);return 0;}
    ll sum=0;rep(i,1,n){if(rev(i),check())sum++;rev(i);}printf("1 %lld\n",sum);return 0;
}