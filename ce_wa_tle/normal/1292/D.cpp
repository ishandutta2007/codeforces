#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=1e5+7;typedef ll aN[N];
void qmax(ll&a,ll b){if(a<b)a=b;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct bit{aN a,f;ll n,s;void set(ll n_){n=n_,s=0;};void update(ll u,ll c){s+=c,a[u]+=c;while(u<=n)f[u]+=c,u+=u&-u;}
ll query(ll u){ll res=0;while(u)res+=f[u],u&=~-u;return res;}}t;aN next,head,to,d,c,w,fa,sz,v,p,m;ll cnt=0;
void add(ll u,ll v,ll c){/*printf("%lld %lld %lld\n",u,v,c);*/next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}
ll dfs(ll u,ll fa,ll n){
    ll f=0,m=0;sz[u]=v[u];rfor(ll i=head[u];i;i=next[i])if(to[i]^fa)
    {if((f=dfs(to[i],u,n)))return f;else sz[u]+=sz[to[i]],qmax(m,sz[to[i]]);}return m<=n/2&&n-sz[u]<=n/2?u:0;
}
ll dfs(ll u,ll fa){
    ll s=0;rfor(ll i=head[u];i;i=next[i])if(to[i]^fa)d[to[i]]=d[u]+w[i],s+=dfs(to[i],u);return s+v[u]*d[u];
}
int main(){
//IO(1292D);
    static ll N=5000;ll cnt=N,top=0;t.set(N);p[0]=1e9+7;rep(i,2,N){
        if(!p[i])m[p[++top]=i]=i;rfor(ll j=1;j<=top&&i*p[j]<=N&&i%p[j-1];j++)p[i*p[j]]=1,m[i*p[j]]=std::max(m[i],p[j]);
        ll n=i,d=t.s-t.query(m[i]-1),ls=t.s,now=i-1,f;//if(i==6)fprintf(stderr,"%lld %lld %lld\n",ls,d,t.query(3));
        while(n!=1)t.update(m[n],1),n/=m[n];//fprintf("%lld %lld\n",i,m[i]);
        while(ls&&ls-c[now]>=d)ls-=c[now],now=fa[now];if(ls==d)fa[i]=now;
        else f=fa[now],c[++cnt]=d-ls+c[now],fa[c[now]=ls-d,fa[i]=fa[now]=cnt]=f;c[i]=t.s-d;//printf("%lld %lld\n",cnt,c[cnt]);
    }rep(i,2,cnt)add(fa[i],i,c[i]),add(i,fa[i],c[i]);//ll s=0,now=5000;while(now)s+=c[now],now=fa[now];printf("%lld\n",s);
    /*exit(0);*/ll n=readll();rep(i,1,n)v[readll()]++;v[1]+=v[0],printf("%lld\n",dfs(dfs(1,0,n),0));/*printf("%lld\n",d[1]);*/return 0;
}
/*
2
3 4
*/