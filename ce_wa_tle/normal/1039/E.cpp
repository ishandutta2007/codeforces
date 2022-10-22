#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=4e5+9,inf=998244353,S=250;typedef ll aN[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll size,fa,son[2];}spl[N];
struct LCT{
    ll wz(ll u){const ll*s=spl[spl[u].fa].son;return((s[1]==u)<<1|(s[0]==u))-1;}
    void pushup(ll u){u&&(spl[u].size=spl[spl[u].son[0]].size+spl[spl[u].son[1]].size+1);}
    void cct(ll u,ll v,ll w){u&&(spl[u].fa=v),~w&&v&&(spl[v].son[w]=u);}
    void rotate(ll u){
        if(!~wz(u))return;ll v=spl[u].fa,w=spl[v].fa,wu=wz(u),wv=wz(v),wx=wu^1,x=spl[u].son[wx];
        cct(u,w,wv),cct(v,u,wx),cct(x,v,wu);pushup(v),pushup(u);
    }void splay(ll u){rfor(ll v;~wz(u);)v=spl[u].fa,rotate(wz(u)==wz(v)?v:u),rotate(u);}
    void access(ll u){rfor(ll x=0;u;splay(u),spl[u].son[1]=x,x=u,u=spl[u].fa);}
    ll find_root(ll u){access(u),splay(u);while(spl[u].son[0])u=spl[u].son[0];splay(u);return u;}
    void link(ll u,ll v){access(v),splay(u),splay(v),spl[u].fa=v;}
    void cut(ll u,ll v){access(v),splay(u),splay(v),spl[u].fa=0;}
    ll move(ll&u){return spl[access(u),splay(u),u=find_root(u)].size-1;}
}t;struct ST{
    aN log,max[32],min[32];ll n;
    void calc(ll n,const ll*a){
        memcpy(max[0],a,sizeof(ll)*(n+1)),memcpy(min[0],a,sizeof(ll)*(n+1));rep(i,2,n)log[i]=log[i>>1]+1;
        rep(i,1,log[n])rep(j,1,n-(1<<i)+1)max[i][j]=std::max(max[i-1][j],max[i-1][j+(1<<(i-1))]),
                                          min[i][j]=std::min(min[i-1][j],min[i-1][j+(1<<(i-1))]);
    }ll query(ll l,ll r){
        ll lg=log[r-l+1];return std::max(max[lg][l],max[lg][r-(1<<lg)+1])-std::min(min[lg][l],min[lg][r-(1<<lg)+1]);
    }
}st;std::vector<ll>cg[N];aN ans,a,to;ll n,w,tq;
struct query{ll k,id;void read(ll w,ll i){k=w-readll(),id=i;}operator ll()const{return k;}}q[N]; 
ll getnxt(ll u,ll k){ll l=u,r=n,mid;while(l<=r)if(st.query(u,mid=(l+r)>>1)>k)r=mid-1;else l=mid+1;return r+1;}
int main(){
    n=readll(),w=readll(),tq=readll();rep(i,1,n)a[i]=readll();st.calc(n,a);rep(i,1,n)cg[1].emplace_back(to[i]=i);
    q[tq+1].k=inf;rep(i,1,tq)q[i].read(w,i);std::sort(q+1,q+tq+1);rep(i,1,tq){ref(j,0,(ll)cg[i].size()){
        ll s=cg[i][j],&now=to[s],d;if(now==n+1)continue;if(now!=s)t.cut(s,now++);
        while(now<=n&&now-s<=S&&(d=st.query(s,now))<=q[i].k)now++;
//        printf("%lld %lld %lld %lld\n",s,now,d,std::lower_bound(q+1,q+tq+1,(query){d,0})-q);
        if(now-s<=S){t.link(s,now),cg[std::lower_bound(q+1,q+tq+2,(query){d,0})-q].emplace_back(s);}}//exit(0);
        for(ll j=1;j<=n;)if(to[j]-j<=S)ans[q[i].id]+=t.move(j);else j=getnxt(j,q[i].k),ans[q[i].id]++;
    }rep(i,1,tq)printf("%lld\n",ans[i]-1);return 0;
}