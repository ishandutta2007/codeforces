#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define pow djsnfianj
typedef long long ll;typedef long double ld;const ll N=2e3+7,inf=1e18;typedef ll aN[N*2];aN head,tail,next,pre,up,to,l,r;
inline ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll cnt=0,top=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}int cmp(ll a,ll b){return r[a]>r[b];}
int qmax(ll&a,ll b){return a<b?a=b,1:0;}ll f[N][N][4],p1[N][N][4],p2[N][N][4],g[N][4];aN sl,sr,ansl,ansr,c,st;
void dfs0(ll u){
    ll x;f[u][0][0]=0,f[u][0][1]=l[u],f[u][0][2]=-l[u],f[u][0][3]=0,up[u]=0;
    rfor(ll i=head[u],v;v=to[i],i;i=next[i]){pre[next[i]]=tail[u]=i;
        dfs0(v),memcpy(g,f[u],sizeof(ll)*4*(up[u]+1)),memset(f[u],-0x3f,sizeof(ll)*4*(up[u]+up[v]+1+1));
        rep(j,0,up[u])rep(a,0,3)rep(k,0,up[v])rep(b,0,3)
        if(((x=a>>1)^(~b&1)||(i==head[u]&&!a))&&qmax(f[u][j+k+x][a^b^(x*3)],g[j][a]+f[v][k][b]))
        p1[v][j+k+x][a^b^(x*3)]=k<<4|a<<2|b;up[u]+=up[v]+1;
    }memcpy(g,f[u],sizeof(ll)*4*(up[u]+1)),memset(f[u],-0x3f,sizeof(ll)*4*(up[u]+1));
    rep(j,0,up[u])rep(a,0,3)rep(b,0,3)if(x=b&1,(a>>1^(~b&1)||(!b))&&j+x-1>=0)
    if(qmax(f[u][j+x-1][a^b^(x*3)],g[j][a]+((b&1)-(b>>1))*r[u]))p2[u][j+x-1][a^b^(x*3)]=a<<2|b;
}void dfs2(ll u,ll j,ll a,ll&nl,ll&nr){
    ll t=p2[u][j][a],x=0,y=0;j-=(t&1)+(t>>4)-1,a=t>>2&3;nl=t&1?r[u]:-1,nr=t&2?r[u]:-1;
    rfor(ll i=tail[u],v;v=to[i],i;i=pre[i])x=0,y=0,t=p1[v][j][a],dfs2(v,t>>4,t&3,x,y),
    t&2&&(~nl?sl[++top]=y,sr[top]=nl,nl=-1:(nr=y)),t&1&&(nl=x),j-=(t>>3&1)+(t>>4),a=t>>2&3;
    a&2&&(~nl?sl[++top]=l[u],sr[top]=nl,nl=-1:(nr=l[u])),a&1&&(nl=l[u]),ansl[u]=sl[top],ansr[u]=sr[top--];
}int main(){
    ll n=readll(),u,v;rep(i,1,n)l[c[i]=i]=readll(),r[i]=readll();std::sort(c+1,c+n+1,cmp);ll top=0,sum=0,x,y;l[0]=-1;
    rep(i,1,n+1){u=c[i];while(l[u]<l[st[top]])top--;!top&&(v=st[1])?dfs0(v),sum+=f[v][0][0],dfs2(v,0,0,x,y):
    add(st[top],c[i]),st[++top]=u;}printf("%lld\n",sum);rep(i,1,n)printf("%lld %lld\n",ansl[i],ansr[i]);return 0;
}
/*
3
0 10
2 5
6 7
*/