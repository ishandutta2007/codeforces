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
const ll N=1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
    while((*s=gc())<3);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
aN f,next,to,head,w,max,a,mu,mv,mc;
ll cnt=0;
void add(ll u,ll v,ll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
void dfs(ll u,ll fa,ll c){
    max[u]=std::max(max[fa],c);
    rev(i,u,v)if(v^fa)dfs(v,u,w[i]);
}
ll find(ll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
struct ss1{
    ll zy,cy;
    ss1():zy(0),cy(0){}
    void ins(ll u=-1){
        if(u==-1)u=zy+1;
        if(find(u)!=find(zy))cy=zy;
        zy=u;
    }
    ll getans(ll u){
        return find(u)==find(zy)?cy:zy;
    }
};
struct ss2{
    ll zy,cy;
    ss2(){
        zy=cy=1;
        while(find(cy)&&find(zy)==find(cy))cy++;
    }
    void del(){
        zy++;
        while(find(cy)&&find(zy)==find(cy))cy++;
    }
    ll getans(ll u){
        return find(u)==find(zy)?cy:zy;
    }
};
ll getdis(ll u,ll v,ll d){
    return llabs(llabs(a[u]-a[v])-d);
}
ll merge(ll u,ll v,ll c){
    if(v==0||a[v]==mod)return 0;
    if(find(u)==find(v))return 0;
    //printf("%lld %lld %lld\n",u,v,c);
    f[find(u)]=find(v),add(u,v,c),add(v,u,c);
    return 1;
}
int main(){
    IO();
    ll n=readll(),q=readll(),s=readll(),d=readll();
    rep(i,1,n)a[i]=readll(),f[i]=i;
    a[n+1]=mod,a[0]=-mod;
    ll cnt=0;
    while(cnt<n-1){
        ss1 l1,r1;
        ss2 l2,r2;
        rep(i,1,n){
            #define gx(ss)({\
            g=getdis(i,v=ss.getans(i),d);\
            if(!mu[f]||mc[f]>g)mu[f]=i,mv[f]=v,mc[f]=g;})
            ll v,g,f=find(i);
            while(a[l1.zy+1]<=a[i]-d)l1.ins();
            gx(l1);
            while(a[r1.zy+1]<=a[i]+d)r1.ins();
            gx(r1);
            while(a[l2.zy]<a[i]-d)l2.del();
            gx(l2);
            while(a[r2.zy]<a[i]+d)r2.del();
            gx(r2);
        }
        //rep(i,1,n)printf("%lld-%lld %lld\n",mu[i],mv[i],mc[i]);
        rep(i,1,n)if(mu[i])cnt+=merge(mu[i],mv[i],mc[i]),mu[i]=0;
    }
    dfs(s,0,0);
    rep(i,1,q){
        ll u=readll(),k=readll();
        myputs(k>=max[u]?"YES":"NO");
    }
    return 0;
}