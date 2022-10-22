#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define mem(x) memset(x,0,sizeof(x))
#define memn(x,n) memset(x,0,sizeof(ll)*((n)+1))
typedef long long ll;const ll N=2222221,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];ll cnt,tc,tu,ts,flag=0;
ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,head,fa,to,in,d,ans,fl,vis,q,nm,s,dp,sl;void add(ll u,ll v){next[++cnt]=head[u],d[to[head[u]=cnt]=v]=(d[v]+1)%3;}
ll dfs0(ll u,ll fa){in[q[1]=u]=1,::fa[u]=fa;rfor(ll h=1,t=1,u;h<=t;)
    rfor(ll i=head[u=q[h++]],v;v=to[i],i;i=next[i])if(!in[v]){::fa[q[++t]=v]=u,in[v]=1;if(d[v]==1)return v;}return 0;
}ll dfs3(ll u,ll fa){ll res=0,f;::fa[u]=fa,in[u]=1;
    rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(fa&&d[v]==1)res=u;else if(!in[v])if((f=dfs3(v,u))&&!res)res=f;return res;
}ll dfs2(ll u,ll fa){ll res=0;in[u]=vis[u]=1;dp[u]=dp[::fa[u]=fa]+1;rfor(ll i=head[u],v,f;v=to[i],i;i=next[i])
    if(d[v]==2&&!vis[v]){if((f=dfs2(v,u))&&!res)res=f;}else if(in[v]&&v!=fa)res=u,q[u]=dp[v]>dp[q[u]]?v:q[u];return in[u]=0,res;
}ll solve(ll n,ll m){
    ll u,v,f[3],l[3],res,top;cnt=0,memn(head,n),memn(d,n);rep(i,1,m)u=nm[i]=readll(),v=sl[i]=readll(),add(u,v),add(v,u);mem(f),mem(l);
    rep(u,1,n)f[d[u]]=f[d[u]]?:u,l[d[u]]=u;if(f[0])return ans[1]=f[0],1;tc=tu=ts=0;memn(vis,n);memn(in,n);memn(q,n);
    rep(u,1,n)if(d[u]==2&&(res=dfs2(u,0))){ll top=0,s=q[res];while(res!=s)ans[++top]=res,res=fa[res];ans[++top]=res;return top;}//puts("???");
    if(f[1]&&l[1]&&f[1]!=l[1]){memn(in,n);ll v=dfs0(f[1],0);top=0;rfor(ll i=v;i;i=fa[i])ans[++top]=i;return top;}
    if(!f[1])return 0;memn(in,n);top=1,ts=0;ans[1]=f[1];in[f[1]]=1;rfor(ll i=head[f[1]],v;v=to[i],i;i=next[i]){
    ll u=dfs3(v,0);if(u){rfor(ll i=u;i;i=fa[i])ans[++top]=i;if(++ts==2)break;}}return top;
}int calc(int cases){ll n=readll(),m=readll(),top=solve(n,m);if(!flag){if(top==0||top==n)return puts("No");memn(fl,n);
    rep(i,1,top)fl[ans[i]]=1;printf("Yes\n%lld\n",n-top);rep(i,1,n)if(!fl[i])printf("%lld ",i);return puts(""),cases;}
    if(flag&&cases==511){puts("input:");printf("%lld %lld\n",n,m);rep(i,1,m)printf("%lld %lld\n",nm[i],sl[i]);}return 0;
}int main(){ll T=readll(),cnt=0;if(T==34273)flag=0;while(T --> 0)calc(++cnt);return 0;}
/*
1
5 4
2 3
5 4
4 3
1 5
1
6 9
6 2
2 1
4 2
2 5
5 1
6 1
2 3
4 1
1 3
1
7 16
1 4
6 5
2 3
3 4
5 4
6 3
3 1
7 5
5 1
2 7
6 1
2 4
1 7
5 2
6 2
7 4
*/