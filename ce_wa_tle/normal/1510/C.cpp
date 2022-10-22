#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef long double ld;const ll N=2e5+7,inf=1e18;typedef ll aN[N*2];
inline ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,head,to,dfn,f,l,u,v,c,s;ll cnt,tans,top;void add(ll u,ll v){next[++cnt]=head[u],c[cnt]=0,to[head[u]=cnt]=v;}
void add_ans(ll u_,ll v_){u[++tans]=u_,v[tans]=v_;}void check(ll u,ll&v){v=v?add_ans(u,v),0:u;}
void dfs0(ll u,ll fa,ll e){//printf("%lld %lld %lld\n",u,fa,e);
	dfn[u]=++top,f[u]=fa,l[u]=e;rfor(ll i=head[u],v,now;v=to[i],i;i=next[i])if(v==fa||dfn[v]>dfn[u])c[i]=1;
	else if(!dfn[v])dfs0(v,u,i);else for(c[i]=1,now=u;now!=v;now=f[now])c[l[now]]=1;//,printf("%lld %lld\n",now,v);
}void dfs1(ll u,ll fa,ll x){(void)fa;//printf("%lld %lld %lld\n",u,fa,x);
	ll son=0,lst=0;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(!c[i])dfs1(v,u,1),
	check(s[v],son||s[v]^v?lst:son);son=son?:u;s[u]=lst?!x?add_ans(lst,son),son:lst:son;//printf("%lld %lld\n",u,s[u]);
}void calc(ll n,ll m){//puts("---------------");
	ll sz=sizeof(ll)*(n+1);memset(head,cnt=0,sz),memset(dfn,top=tans=0,sz);
	rep(i,1,m){ll k=readll(),x=readll(),l;rep(i,2,k)l=x,add(x=readll(),l),add(l,x);}dfs0(1,0,0);
	rep(i,1,n)if(c[l[i]]||i==1)dfs1(i,0,0);printf("%lld\n",tans);rep(i,1,tans)printf("%lld %lld\n",u[i],v[i]);
}int main(){rfor(ll n,m;n=readll(),m=readll(),n;calc(n,m));return 0;}
/*
2 1
2 1 2
7 2
5 1 2 3 4 5
2 5 7
11 3
6 1 2 3 4 5 6
3 5 7 8
3 5 9 10
5 3
3 1 2 3
2 2 4
2 2 5
*/