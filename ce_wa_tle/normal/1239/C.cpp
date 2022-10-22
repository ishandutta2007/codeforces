#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2222222,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];aN a,c,ans;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}aN s;
struct cmp_t{int operator()(ll x,ll y){return a[x]==a[y]?x<y:a[x]<a[y];}};
std::priority_queue<ll,std::vector<ll>,std::greater<ll>>qu;aN q;ll h=1,t=0;
int main(){//IO(1239C);
    ll n=readll(),k=readll();rep(i,1,n)a[c[i]=i]=readll();std::sort(c+1,c+n+1,cmp_t());ll i=1,now=0;
    while(h<=n){while(i<=n&&a[c[i]]<=now)if(c[i]<q[t])q[++t]=c[i++];else qu.push(c[i++]);
    while(!qu.empty()&&(h>t||qu.top()<q[t]))q[++t]=qu.top(),qu.pop();if(h>t)q[++t]=c[i++];
    ll u=q[h++];ans[u]=now=std::max(now,a[u])+k;}rep(i,1,n)printf("%lld ",ans[i]);return 0;
}
/*
6 1
0 4 1 0 2 3
*/