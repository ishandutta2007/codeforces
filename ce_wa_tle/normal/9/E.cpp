#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126){
    if(l>r)std::swap(l,r);
    int c=gc();
    for(;c<l||c>r;c=gc());
    return c;
}
ll readll(){
    ll x=0,w=1;
    int c=gc();
    for(;c<48||c>57;c=gc())c-45||(w=-w);
    for(;c>47&&c<58;c=gc())x=x*10+c-48;
    return x*w;
}
void writell(ll u,int c=32){
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10^48;
    for(t||pc(48);t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0){
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s=0,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
aN a,b,t,vis;
ll dfs(ll u,ll fa){
    if(!u||vis[u])return 0;
    vis[u]=1;
    return dfs(a[u]==fa?b[u]:a[u],u)?:u;
}
ll add(ll&u,ll&v,ll i){
    if(!u){
        u=i;
        return 1;
    }
    if(t[u]!=i){
        writell(u),writell(i,10);
        ll x=t[i],y=t[u];
        t[x]=y,t[y]=x,
        u=v,v=0;
        return 2;
    }
    if(!v){
        v=i;
        return 3;
    }
    writell(v),writell(i,10),
    t[t[v]]=i,t[t[i]]=v;
    return 4;
}
int main(){
    IO();
    ll n=readll(),m=readll(),u,v;
    rep(i,1,m){
        u=readll(),v=readll();
        if(b[u])return!myputs("NO");
        else (a[u]?b[u]:a[u])=v;
        if(b[v])return!myputs("NO");
        else (a[v]?b[v]:a[v])=u;
    }
    if(m==n){
        dfs(1,0);
        rep(i,1,n)if(!vis[i])return!myputs("NO");
        return!myputs("YES\n0");
    }
    ll j=0;
    rep(i,1,n)if(!b[i]&&!vis[i])j=dfs(i,0),t[i]=j,t[j]=i;
    rep(i,1,n)if(!vis[i])return!myputs("NO");
    myputs("YES");
    writell(n-m,10);
    u=0,v=0;
    rep(i,1,n)b[i]||add(u,v,i),a[i]||add(u,v,i);
    writell(u),writell(v,10);
    return 0;
}