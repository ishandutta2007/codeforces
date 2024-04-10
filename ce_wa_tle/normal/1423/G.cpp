#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
bool p1;
typedef long long ll;typedef long double ld;const ll N=1e5+7,Q=1e5+7,V=42;typedef ll aN[N];
ld sqr(ld x){return x*x;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}ld readld(){
	ll x=0,w=1;ld s=0,d=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());
    if(c=='.')for(c=getchar();c>='0'&&c<='9';s+=(d*=0.1)*(c^48),c=getchar());return(x+s)*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct bit{
    aN f,f2;ll n;void set(ll x){n=x;};void update(ll u,ll c){/*printf("update %lld %lld\n",u,c);*/ll c2=u*c;while(u<=n)f[u]+=c,f2[u]+=c2,u+=u&-u;}
    ll query(ll u)const{ll l=u+1,res=0,res2=0;while(u)res+=f[u],res2+=f2[u],u&=~-u;return res*l-res2;}
    void add_ij(ll i,ll j,ll w){/*printf("add_ij %lld %lld %lld\n",i,j,w);*/update(1,w),update(n-j+2,-w),update(j-i+1,-w),update(n-i+2,w);}
    void add_lr(ll l,ll r,ll w){/*printf("add_lr %lld %lld %lld\n",l,r,w);*/update(1,(r-l)*w),update(2,(l-r)*w),update(n-r+2,-w),update(n-l+2,w);}
}ans;
struct hash{
    const static ll mod=9260817;
    #define hss ll now=b%mod,k=0;while(key[now]&&key[now]!=b)now=(now+2*k+++1)%mod
    ll val[mod];ll key[mod];int count(ll b)const{hss;return!!key[now];}
    ll operator[](ll b)const{hss;return key[now]?val[now]:0;}
    ll&operator[](ll b){hss;return!key[now]?key[now]=b,val[now]:val[now];}
}hs;ll ls(ll u){static ll cnt=0;return hs.count(u)?hs[u]:hs[u]=++cnt;}
typedef std::map<ll,ll>mapl;typedef std::map<ll,ll>::iterator iter;
struct ds{//val[l]=r
    mapl val;
    void del(ll l,ll r){
        split(l),split(r+1);iter it=val.lower_bound(l);ll lr=it!=val.begin()?--it,it++->second:0,
        rl=++it!=val.end()?it->first:0;/*if(lr)*/ans.add_ij(lr,l,-1);if(rl)ans.add_ij(r,rl,-1);
        if(/*lr&&*/rl)ans.add_ij(lr,rl,1);ans.add_lr(l,r,-1),val.erase(--it);
    }void ins(ll l,ll r){
        iter it=val.lower_bound(l);ll lr=0,rl=0;if(it!=val.end())rl=it->first;
        if(it!=val.begin())lr=(--it)->second;/*if(lr)*/ans.add_ij(lr,l,1);if(rl)ans.add_ij(r,rl,1);
        if(/*lr&&*/rl)ans.add_ij(lr,rl,-1);ans.add_lr(l,r,1),val[l]=r;
    }void split(ll x){iter it=val.lower_bound(x);if(it!=val.begin()&&(--it)->second>=x)val[x]=it->second,it->second=x-1;}
}m[N+Q];
struct ds2{//val[l]=c
    mapl val;void ins(ll l,ll r,ll c){val[l]=c;if(c)m[c].ins(l,r);}
    void del(ll l,ll r){//for(iter i=val.begin();i!=val.end();i++)printf("%lld %lld\n",i->first,i->second);puts("");
        split(l),split(r+1);/*for(iter i=val.begin();i!=val.end();i++)printf("%lld %lld\n",i->first,i->second);exit(0);*/for(iter it=val.lower_bound(l),it1;it1=it,it->first<=r;it=it1)
        m[it->second].del(it->first,(++it1)->first-1),val.erase(it);
    }void split(ll x){iter it=val.lower_bound(x);if(it--->first==x)return;val[x]=it->second;}
}t;bool p2;
int main(){fprintf(stderr,"%.2lfMiB\n",(&p2-&p1)/1048576.0);
    ll n=readll(),q=readll();ans.set(n);rep(i,1,n)t.ins(i,i,ls(readll()));t.ins(n+1,n+1,0);
    rep(i,1,q)if(readll()^2){ll l=readll(),r=readll(),x=ls(readll());t.del(l,r),t.ins(l,r,x);}
    else printf("%lld\n",ans.query(readll()));return 0;
}
/*
5 5
1 2 3 4 5
2 3
1 1 2 5
2 4
1 2 4 5
2 2

*/
/*
     o   o  .
     i   j  n
     add(1,1),add(n-j+2,-1),add(j-i+1,-1),add(n-i+1,1)
     ooooo  .
     l   r  n
     add(1,r-l),add(2,l-r),add(n-r+2,-1),add(n-l+2,1)
*/