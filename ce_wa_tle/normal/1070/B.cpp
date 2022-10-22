#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
bool p1;typedef unsigned int uint;
typedef long long ll;const ll N=(2e5+7)*32,inf=998244353;typedef uint aN[N];aN s[2],fa,d,col,w,f[2];int lc;
#define ms(x,y,z)memset(x,y,sizeof(ll)*((z)+1))
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());lc=c;return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());lc=c;return c;}
bool p2;
int main(){fprintf(stderr,"%.2lfMiB\n",(&p2-&p1)/1048576.0);
    ll n=readll(),t=1;f[1][0]=1;memset(col,-1,sizeof col);rep(i,1,n){
        ll c=readchar('+','-')=='+',x=0;rep(i,1,4)x=x<<8|readll();ll w=lc=='/'?readll():32,u=1;
        ref(i,0,w)f[c][u]=1,u=s[x>>(31^i)&1][u]?:(fa[++t]=u,s[x>>(31^i)&1][u]=t);f[col[u]=c][u]=1;
    }rep(i,2,t)d[i]=d[fa[i]]|(ll)(s[1][fa[i]]==i)<<(32-w[fa[i]]-1),w[i]=w[fa[i]]+1;ll ans=0;
//    rep(i,1,t)printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",col[i],f[1][i],f[0][i],d[i],w[i],fa[i],s[0][i],s[1][i]);
    rep(i,1,t)if(ans+=f[1][fa[i]]&&!f[1][i],~col[i]&&f[col[i]^1][i])return puts("-1"),0;printf("%lld\n",ans);
    rep(i,1,t)if(f[1][fa[i]]&&!f[1][i]){per(j,3,0)printf("%u%s",d[i]>>(j<<3)&255,j?".":"");printf("/%u\n",w[i]);}return 0;
}