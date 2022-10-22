#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef unsigned long long ull;const ll N=4e5+7,inf=998244353;typedef ll aN[N];aN st,a,b,f;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct ps{ll s,h,id;void read(ll i){s=readll(),h=readll(),id=i;}operator ll()const{return s;}}p[N];
int main(){
    ll n=readll(),m=readll();rep(i,1,m)p[i].read(i);std::sort(p+1,p+m+1);rep(i,1,n)a[i]=readll();
    rep(t,1,n){
        ll s=m;rep(i,1,m)f[i]=0;while(p[s].s>t)s--;
        per(i,s+1,1)if(i==s+1||f[i]){ll now=i==s+1?t:p[i].s,lim=std::max(0ll,-a[now]);
        per(j,i-1,1){while(now>p[j].s)lim=std::max(lim-a[--now],0ll);if(p[j].h>=lim)f[j]=i;}}
        rep(i,s,m)if(i==s||f[i]){ll now=i==s?t+1:p[i].s,lim=std::max(0ll,-a[now]);
        rep(j,i+1,m){while(now<p[j].s)lim=std::max(lim-a[++now],0ll);if(p[j].h>=lim)f[j]=i;}}
//        printf("s=%lld\n",s);rep(i,1,m)printf("%lld ",f[i]);puts("");
        if(f[1]&&f[m]){printf("%lld\n",t);ll now=1,top=0;while(now!=s+1)b[st[++top]=now]=1,now=f[now];
        while(top)printf("%lld ",p[st[top--]].id);now=m,top=0;while(now!=s)b[st[++top]=now]=1,now=f[now];
        while(top)printf("%lld ",p[st[top--]].id);rep(i,1,m)if(!b[i])printf("%lld ",p[i].id);return 0;}
    }puts("-1");return 0;
}