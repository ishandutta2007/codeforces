#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=1222222,inf=1e18,mod=998244353;typedef ll aN[N];
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll size,v1,v2,fa,son[2];}spl[N];
struct LCT{
    ll wz(ll u){const ll*s=spl[spl[u].fa].son;return((s[1]==u)<<1|(s[0]==u))-1;}
    void pushup(ll u){u&&(spl[u].size=spl[u].v1+spl[spl[u].son[0]].size+spl[spl[u].son[1]].size+1);}
    void pushup_v(ll u,ll f){ll v=spl[u].fa,s=spl[u].size;v&&(spl[v].v1+=s*f,spl[v].v2+=s*s*f);}
    void cct(ll u,ll v,ll w){u&&(spl[u].fa=v),~w&&v&&(spl[v].son[w]=u);}
    void rotate(ll u){if(!~wz(u))return;
        ll v=spl[u].fa,w=spl[v].fa,wu=wz(u),wv=wz(v),wx=wu^1,x=spl[u].son[wx];
        cct(u,w,wv),cct(v,u,wx),cct(x,v,wu);pushup(v),pushup(u);
    }void splay(ll u){rfor(ll v;~wz(u);)v=spl[u].fa,rotate(wz(u)==wz(v)?v:u),rotate(u);}
    void access(ll u){rfor(ll x=0;u;splay(u),pushup_v(spl[u].son[1],1),spl[u].son[1]=x,pushup_v(x,-1),x=u,u=spl[u].fa);}
    ll find_root(ll u){access(u),splay(u);while(spl[u].son[0])u=spl[u].son[0];splay(u);return u;}
    void link(ll u,ll v){access(v),splay(u),splay(v),spl[u].fa=v,pushup_v(u,1),pushup(v);}
    void cut(ll u,ll v){access(v),splay(u),splay(v),pushup_v(u,-1),spl[u].fa=0,pushup(v);}
}t;
inline ll query(ll u){ll v;u=spl[v=t.find_root(u)].son[1];return spl[u].size*spl[u].size;}aN is,f,c;
inline ll update(ll u){
    ll lst=0;return(is[u]^=1)?(lst=query(u),t.cut(u,f[u]),t.access(u),spl[u].v2+(is[f[u]]?0:query(f[u]))-lst)://w
                             (t.access(u),lst=spl[u].v2+(is[f[u]]?0:query(f[u])),t.link(u,f[u]),query(u)-lst);//b
}struct oper{ll u,c,id;operator ll()const{return c*(1e9+7)+id;}}op[N];const ll r=N-1;ll u,v;
aN next,to,head,ans;ll cnt=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll fa){f[u]=fa;rfor(ll i=head[u];i;i=next[i])if(to[i]^fa)dfs(to[i],u);}
int main(){
    ll n=rd,m=rd,to=0,x;rep(i,1,n)op[++to]=(oper){i,c[i]=readll(),0};rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    dfs(1,r);rep(i,1,m)x=readll(),op[++to]=(oper){x,c[x],i},op[++to]=(oper){x,c[x]=readll(),i};std::sort(op+1,op+to+1);
    spl[r].size=1;rep(i,1,n)spl[i].size=1;rep(i,1,n)t.link(i,f[i]);ll lst=1;rep(i,1,to){ll sr;
    ans[op[i].id]+=sr=update(op[i].u);if(op[i+1].c!=op[lst].c){per(j,i,lst)update(op[j].u);lst=i+1;}}
    rep(i,0,m)printf("%lld\n",-(i?ans[i]+=ans[i-1]:ans[i]));return 0;
}
/*
10 0
3 6 6 9 7 6 4 7 8 9
2 4
9 2
6 4
1 9
3 1
8 1
5 8
10 6
7 4
*/