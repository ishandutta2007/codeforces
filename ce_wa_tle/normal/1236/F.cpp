#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define mem(x) memset(x,0,sizeof(x))
#define memn(x,n) memset(x,0,sizeof(ll)*((n)+1))
typedef long long ll;const ll N=2222221,mod=1e9+7,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];ll cnt,tc;
ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}aN next,to,head,u,v,p,d,dp,sz;
ll sqr(ll u){u=(u%mod+mod)%mod;return u*u%mod;}ll n,m;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
enum{a=0,b=1,c=4,ab=5,ac=7,bc=8};aN vis,f,ny;
void print(const char*s,ll x){
    printf(s);ll resi=0,resj=0;
    rep(i,0,70){rep(j,1,20)if(i*ny[j]%mod==x){resi=i,resj=j;break;}if(resj)break;}
    if(resj)printf("=%lld/%lld\n",resi,resj);else printf("=%lld\n",x);
}
#define print(x...)print(#x,x)
void dfs(ll u,ll fa){
    vis[u]=1,dp[u]=dp[f[u]=fa]+1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(!vis[v])dfs(v,u);else if(dp[v]<dp[u]&&v!=fa){
    p[++tc]=1;rfor(ll now=u;now!=f[v];now=f[now])add(tc+n,now),p[tc]=p[tc]*ny[2]%mod,sz[tc]++;}
}ll E(int cs){static ll cx[9];if(cx[cs])return cx[cs];
    switch(cs){
        case a^2:return cx[a^2]=n*(n+1)%mod*ny[4]%mod;
        case b^2:{ll res=0;rep(i,1,m)d[u[i]]++,d[v[i]]++;rep(i,1,m)res=(res+(m+1+d[u[i]]+d[v[i]])*ny[16])%mod;
            rep(i,1,m)d[u[i]]=0,d[v[i]]=0;return cx[b^2]=res;
        }case c^2:{ll sum=E(c),res=0;rep(i,1,tc)rfor(ll j=head[i+n];j;j=next[j])d[to[j]]=(d[to[j]]+p[i])%mod;//,printf("%lld\n",to[j]);
            rep(i,1,tc)res=(res+p[i]*(sum-p[i]+1-sz[i]*p[i]%mod)%mod+mod)%mod;
            rep(i,1,tc)rfor(ll j=head[i+n];j;j=next[j])res=(res+p[i]*d[to[j]])%mod;rep(i,1,n)d[i]=0;return cx[c^2]=res;
        }case ab:return cx[ab]=m*(n+2)%mod*ny[8]%mod;
        case ac:{ll res=0;rep(i,1,tc)res+=p[i]*(n+sz[i])%mod*ny[2]%mod;return cx[ac]=(res%mod+mod)%mod;}
        case bc:{ll res=0;rep(i,1,m)d[u[i]]++,d[v[i]]++;rep(i,1,tc)res=(res+p[i]*(m+sz[i])%mod*ny[4])%mod;
            rep(i,1,tc)rfor(ll j=head[i+n];j;j=next[j])res=(res+p[i]*d[to[j]]%mod*ny[4])%mod;
            rep(i,1,m)d[u[i]]=0,d[v[i]]=0;return cx[bc]=res;}
        case a:return cx[a]=n*ny[2]%mod;
        case b:return cx[b]=m*ny[4]%mod;
        case c:{ll res=0;rep(i,1,tc)res+=p[i];return cx[c]=res%mod;}
    }return 0;
}int main(){
    n=readll(),m=readll();rep(i,1,m)u[i]=readll(),v[i]=readll(),add(u[i],v[i]),add(v[i],u[i]);ny[1]=1;
    rep(i,2,std::max(30ll,n))ny[i]=(mod-mod/i)*ny[mod%i]%mod;dfs(1,0);
//    print(tc);print(E(a));print(E(b));print(E(c));print(E(a^2));print(E(b^2));print(E(c^2));print(E(ab));print(E(ac));print(E(bc));
    printf("%lld\n",(E(a^2)+E(b^2)+E(c^2)+(E(ac)-E(ab)-E(bc))*2+6*mod-sqr(E(a)-E(b)+E(c)))%mod);return 0; 
}