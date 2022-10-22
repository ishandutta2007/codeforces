#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=1e6+9,inf=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct pt{ll s,w,id,x,y;}p[N];int operator<(const pt&a,const pt&b){return a.w!=b.w?a.w<b.w:a.w>>1^(a.s<b.s);}
ll db=0;
ll query(ll t,ll i,ll j,ll k){printf("%lld %lld %lld %lld\n",t,i,j,k),fflush(stdout);
if(db){ll s=(p[j].x-p[i].x)*(p[k].y-p[i].y)-(p[k].x-p[i].x)*(p[j].y-p[i].y);ll res=t==1?std::max(s,-s):s>0?1:-1;
printf("%lld\n",res);return res;}
return readll();}
int main(){
    ll n=readll(),ans=2,max=0;if(db)rep(i,1,n)p[i].x=readll(),p[i].y=readll();
    rep(i,1,n)p[i].id=i;rep(i,3,n)if(query(2,1,i,ans)==1)ans=i;
    rep(i,2,n)if(i!=ans)if((p[i].s=query(1,1,ans,i))>p[max].s)max=i;p[max].w=1;
    rep(i,2,n)if(i!=ans&&i!=max)p[i].w=(query(2,1,max,i)==1)*2;std::sort(p+2,p+n+1);
    printf("0 ");rep(i,1,n)printf("%lld ",p[i].id);fflush(stdout);return 0;
}