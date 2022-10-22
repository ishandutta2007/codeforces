#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=2e6+9;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
#define ms(x,y) (((x)-1)*ansc+(y))
aN a,b,ma,p;int cmp(ll x,ll y){return b[x]>b[y];}
int main(){
    ll n=readll(),sn=n,ansr=0,ansc=0,top=0,m,now=1;rep(i,1,n)a[p[i]=i]=readll();std::sort(a+1,a+n+1);
    rep(i,1,n)if(a[top]==a[i])b[top]++;else a[++top]=a[i],b[top]=1;std::sort(p+1,p+top+1,cmp);
    per(r,n,1){rep(i,1,top)if(b[p[i]]>r)sn--;else break;if(sn>=r*r&&sn/r*r>ansr*ansc)ansr=r,ansc=sn/r;}
    printf("%lld\n%lld %lld\n",m=ansr*ansc,ansr,ansc);rep(i,1,top)if(b[i]>ansr)b[i]=ansr;
    rep(i,1,m)ma[ms((i-1)%ansr+1,(((i-1)%ansr+1+(i-1)/ansr)-1)%ansc+1)]=a[p[now+=!b[p[now]],b[p[now]]--,now]];
    rep(i,1,ansr){rep(j,1,ansc)printf("%lld ",ma[ms(i,j)]);puts("");}return 0;
}