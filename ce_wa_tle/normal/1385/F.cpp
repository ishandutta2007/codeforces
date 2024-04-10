#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=1116333,inf=1e9,mod=1e9+7;typedef ll aN[N];aN next,to,head,d,nm,sl;ll cnt=0,flag=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void add_(ll u,ll v){++d[u],next[++cnt]=head[u],to[head[u]=cnt]=v;}void add(ll u,ll v){add_(u,v),add_(v,u);}
int dfs(ll u,ll fa,ll k){
    ll ans=0,d1=0,d2=0,x;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v!=fa)x=dfs(v,u,k),ans+=x/2,d1+=!(x%2),d2++;
    /*printf(">%lld %lld %lld %lld %lld\n",u,fa,ans,d1,d2);*/return ans*2+d1/k*2+!!(d2-d1/k*k);
}int calc(ll cases){
    ll n=rd,k=rd,u,v,root=1;cnt=0,memset(head,0,sizeof(ll)*(n+1)),memset(d,0,sizeof(ll)*(n+1)),(void)cases;
    rep(i,2,n)u=nm[i]=rd,v=sl[i]=rd,add(u,v);if(k==1)return printf("%lld\n",n-1),-1;rep(i,1,n)if(d[i]%k!=1)root=i;
    if(!flag)printf("%lld\n",dfs(root,0,k)/2ll);return-1;
}int main(){ll T=readll(),cnt=0;if(T==-21)flag=1;while(T --> 0)calc(++cnt);return 0;}
/*
1
5 2
4 1
1 2
2 3
3 5
*/