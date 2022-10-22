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
typedef const ll cll;
cll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
void writell(cll u,const int c=32){
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
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
struct bit{
    aN f;
    ll n;
    void set(cll n_){
        n=n_;
    }
    void update(ll u,cll c){
        for(;u<=n;u+=u&-u)f[u]+=c;
    }
    ll find(ll k)const{
        ll u=0;
        red(i,1<<20)if(u+i<=n&&k>f[u+i])k-=f[u+=i];
        return u+1;
    }
    ll query(ll u)const{
        ll res=0;
        for(;u;u&=~-u)res+=f[u];
        return res;
    }
}ds,sd;
aN ans,nxt,z,sk;
struct node{
     ll t,l,r,id;
     operator ll()const{
        return t;
     }
     void calc()const{
        //printf("query %lld %lld %lld %lld %lld\n",l,r,t,ds.query(r)-ds.query(l),(sk[r]-sk[l]-sd.query(r)+sd.query(l))*t);
        ans[id]+=ds.query(r)-ds.query(l)+(sk[r]-sk[l]-sd.query(r)+sd.query(l))*t;
     }
}q[N];
struct code{
    ll s,m,k,id;
    void read(ll i){
        s=readll(),m=readll(),k=readll(),id=i;
    }
    ll getr(ll t)const{
        return std::min(m,s+t*k);
    }
    operator ll()const{
        return k?m/k:mod;
    }
    void calc()const{
        //printf("add %lld %lld %lld\n",id,m,k);
        ds.update(id,m),sd.update(id,k);
    }
}p[N];
ll tq;
void add(ll l,ll r,ll t,ll id){
    //printf("%lld %lld %lld %lld %lld\n",l,r,t,id,z[l]);
    if(z[l]==-1)ans[id]+=p[l].getr(t);
    else q[++tq]=(node){t-z[l],l-1,r-1,id};
}
int main(){
    IO();
    cll n=readll();
    ll x=0;
    rep(i,1,n)p[i].read(i),sk[i]=x+=p[i].k;
    cll m=readll();
    ds.set(n),sd.set(n);
    rep(i,1,n)ds.f[i]=i&-i;
    rep(i,1,n)nxt[i]=i+1,z[i]=-1;
    rep(i,1,m){
        cll t=readll(),l=readll(),r=readll()+1,rl=ds.find(ds.query(l));
        if(l!=rl)nxt[l]=nxt[rl],z[nxt[rl]=l]=z[rl],ds.update(l,1);
        ll now=nxt[l],lst=l;
        for(;now<r;lst=now,now=nxt[now])lst!=l&&(ds.update(lst,-1),0),add(lst,now,t,i);
        if(now!=r)nxt[r]=nxt[lst],z[nxt[lst]=r]=z[lst],ds.update(r,1);
        lst!=l&&(ds.update(lst,-1),0),add(lst,r,t,i),nxt[l]=r,z[l]=t;
    }
    for(ll now=1;now<=n;now=nxt[now])ds.update(now,-1);
    //rep(i,1,n)printf("%lld ",ds.query(i));puts("");
    std::sort(q+1,q+tq+1),std::sort(p+1,p+n+1);
    ll k=1;
    rep(i,1,tq){
        while(k<=n&&p[k]<q[i])p[k++].calc();
        q[i].calc();
    }
    rep(i,1,m)writell(ans[i],10);
    return 0;
}