#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=1e9+7;typedef ll aN[N];aN a,b,c;aN l,r,jc,njc,ny;char s[N],t[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll C(ll n,ll m){return jc[m]*njc[n]%mod*njc[m-n]%mod;}ll F(ll n,ll m){return n<1?n==0&&m==0:C(n-1,m-1);}
ll calc(ll n,ll*r,ll s0,ll f0,ll f1){/*rep(i,1,n)printf("%lld",r[i]);puts("");*/if(!r[n])return 0;ll res=0,s1=n-s0-1;
    per(i,n-1,1)!i||r[i]?res=(res+F(f0,s0)*F(f1-r[i+1],s1))%mod,s1--:s0--,r[i]!=r[i+1]&&(r[i+1]?f1--:f0--);
    r[1]?f1--:f0--;/*printf("%lld %lld %lld %lld\n",s1,s0,f1,f0);*/return res+!(s0||s1||f0||f1);
}int main(){
    scanf("%s%s",t,s);ll c00=readll(),c01=readll(),c10=readll(),c11=readll(),n=c00+c01+c10+c11+1;
    if(c01>c10||c01<c10-1)return puts("0"),0;ny[1]=jc[0]=jc[1]=njc[0]=njc[1]=1;
    rep(i,2,n)jc[i]=jc[i-1]*i%mod,njc[i]=njc[i-1]*(ny[i]=(mod-mod/i)*ny[mod%i]%mod)%mod;
    ll ns=strlen(s),nt=strlen(t);if(ns>n)rep(i,1,n)r[i]=1;else rep(i,1,ns)r[i]=s[ns-i]^48;
    if(nt>n)l[n+1]=1;else rep(i,1,nt)l[i]=t[nt-i]^48;rep(i,1,n)if(l[i]){l[i]=0;break;}else l[i]=1;
    printf("%lld\n",(calc(n,r,c00+c10,c10,c01+1)-calc(n,l,c00+c10,c10,c01+1)+mod)%mod);return 0;
}
/*
10
100
0
0
1
0
*/