#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=4e5+5,mod=1e9+7,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,head,to;ll cnt;
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}std::priority_queue<ll,std::vector<ll>,std::greater<ll>>q;
#define rd readll()
ll calc(){
    ll n=rd,m,p,sum=0,pre=n,now=0;memset(head,cnt=0,sizeof(ll)*(n+1));rep(i,1,n)m=rd,p=rd,add(m,p);while(!q.empty())q.pop(); 
    per(i,n,1){rfor(ll j=head[i];j;j=next[j])q.push(to[j]),pre--;while(pre+now<i)now++,sum+=q.top(),q.pop();}return sum;
}int main(){ll T=rd;while(T --> 0)printf("%lld\n",calc());return 0;}