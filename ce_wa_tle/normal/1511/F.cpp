#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e6+7,mod=998244353,mod2=mod*mod;typedef ll aN[N];aN son[26],w;ll cnt=1;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void lim(ll&a,ll b){if(a>b)a-=b;}
struct mtr{
    ll n,m,val[200][200];void set(ll n_,ll m_,int clear=1){n=n_,m=m_;if(clear)memset(val,0,sizeof val);}
    ll*operator[](ll b){return val[b];}const ll*operator[](ll b)const{return val[b];}
}f,g;mtr operator*(const mtr&a,const mtr&b){
    mtr res;ll n=a.n,m=a.m,t=b.m;res.set(n,t);rep(k,1,m)rep(i,1,n)rep(j,1,t)lim(res[i][j]+=a[i][k]*b[k][j],mod2);
    rep(i,1,n)rep(j,1,t)res[i][j]%=mod;return res;
}void pow(mtr&res,mtr a,ll b){while(b){if(b&1)res=res*a;a=a*a,b>>=1;}}ll id[44][44],top;char s[122][122];
void insert(const char*s){ll now=1;while(*s)now=son[*s-'a'][now]?:son[*s-'a'][now]=++cnt,s++;++w[now];}
ll dfs(ll u,ll v){//printf("%lld %lld\n",u,v);
    if(id[u][v]|id[v][u])return id[u][v]|id[v][u];ll res=id[u][v]=++top,*to=f[res],su,sv;
    rep(i,0,25)if(son[i][u]&&son[i][v])su=son[i][u],sv=son[i][v],to[dfs(su,sv)]++,w[su]&&(to[dfs(1,sv)]+=w[su]),
    w[sv]&&(to[dfs(su,1)]+=w[sv]),to[1]+=w[su]*w[sv];return res;
}
int main(){//exit(0);
    ll n=readll(),m=readll();rep(i,1,n)scanf("%s",s[i]+1),insert(s[i]+1);//exit(0);
//    rep(i,0,25)rep(j,1,cnt)if(son[i][j])printf("%lld %lld %c\n",j,son[i][j],(int)i+'a');
    dfs(1,1),f.set(top,top,0),g.set(1,top);g[1][1]=1;pow(g,f,m);printf("%lld\n",g[1][1]);return 0;
}