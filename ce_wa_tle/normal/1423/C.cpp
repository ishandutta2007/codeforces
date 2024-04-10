#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef unsigned long long ull;const ll N=22163,inf=1e17,mod=1e9+7;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll u,n;}fs[N];ll ts;
aN next,head,to,f,k,del,ydel,st,sz,t,cl;ll cnt=0,top,tk,col;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs0(ll u,ll fa){f[u]=fa;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa)dfs0(v,u);}
struct ans_t{ll cnt;struct{ll x,y;void print()const{printf("%lld %lld\n",x,y);}}val[10*N+7];
ans_t():cnt(0){};void push(ll u,ll v){if(f[u]^v&&f[v]^u)val[++cnt].x=u,val[cnt].y=v;}}ans;
void dfs2(ll u,ll fa,ll size){
    ydel[u]=0;rfor(ll i=head[u],cur=top,v;v=to[i],i;i=next[i])if(v^fa&&!del[v])dfs2(v,u,size),
    ((top-cur)*(top-cur)>=size)&&(ydel[u]=1,top=cur);ydel[u]||(st[++top]=u);
}void dfs3(ll u,ll fa,ll k){ans.push(k,u);rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa&&!del[v])dfs3(v,u,k);}
void dfs4(ll u,ll fa){
    ydel[u]?sz[u]=0,del[k[++tk]=u]=1:ydel[f[u]]||!fa?t[cl[u]=col++]=u:cl[u]=cl[fa];
    sz[u]=1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa&&!del[v])dfs4(v,u),sz[u]+=sz[v];
}void solve(ll u,ll n){//printf("solve:%lld %lld\n",u,n);
    if(n<=4)return;top=0,col=1,dfs2(u,tk=0,n),dfs4(u,0),col--;rep(i,1,tk)rep(j,i+1,tk)ans.push(k[i],k[j]);
    rep(j,1,tk)rfor(ll i=head[k[j]],v;v=to[i],i;i=next[i])if(!del[v])dfs3(t[cl[v]],0,k[j]);
    ll fst=ts+1;rep(i,1,col)fs[++ts]=(node){t[i],sz[t[i]]};ll lst=ts;rep(i,fst,lst)solve(fs[i].u,fs[i].n);
}int main(){
    ll n=readll(),k=readll(),u,v;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);(void)k;
    dfs0(1,0),solve(1,n);printf("%lld\n",ans.cnt);rep(i,1,ans.cnt)ans.val[i].print();return 0;
}/*rep(i,1,tk)printf("%lld:k=%lld\n",n,k[i]);rep(i,1,col)printf("%lld:t=%lld\n",n,t[i]);*/
/*
5 3
1 2
2 3
1 4
4 5
*/