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
const ll N=2e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
std::set<ll>se[N];
aN s,a;
struct sgt{
    struct node{
        ll mx,mn,lf,rt,sm,tg;
        void merge(const node&u,const node&v){
            mx=std::max(u.mx,v.mx);
            const ll a=u.mn+u.tg,b=v.mn+v.tg;
            if(a==b)mn=a,lf=u.lf,rt=v.rt,sm=u.sm+v.sm+std::max(u.rt,v.lf);
            else if(a<b)mn=a,lf=u.lf,rt=std::max(u.rt,v.mx),sm=u.sm;
            else mn=b,lf=std::max(u.mx,v.lf),rt=v.rt,sm=v.sm;
        }
    }f[N<<2];
    ll n;
    void build(ll n_,const ll*c){
        n=2<<(63^__builtin_clzll(n_+2));
        rep(i,1,n_)f[i+n].mx=f[i+n].lf=c[i];
        per(i,n-1,1)f[i].merge(f[i<<1],f[i<<1|1]);
    }
    void update(ll u,ll c){
        u+=n,f[u].mx=f[u].lf=c;
        red(i,u>>1)f[i].merge(f[i<<1],f[i<<1|1]);
    }
    void update(ll l,ll r,ll c){
        ll lt=0,rt=0;
        for(l+=n-1,r+=n+1;(l^r)>1;l>>=1,r>>=1)
        ~l&1&&(f[l^1].tg+=c,lt=1),lt&&(f[l>>1].merge(f[l&~1],f[l|1]),1),
         r&1&&(f[r^1].tg+=c,rt=1),rt&&(f[r>>1].merge(f[r&~1],f[r|1]),1);
        red(i,l>>1)f[i].merge(f[i<<1],f[i<<1|1]);
    }
    ll getans()const{
        return f[1].sm+f[1].lf+f[1].rt;
    }
}t;
int main(){
    IO();
    const ll n=readll(),q=readll(),m=2e5;
    rep(i,1,n)se[a[i]=readll()].insert((ll)i);
    rep(i,1,m)if(i==*se[a[i]].begin())s[i]=se[a[i]].size();
    t.build(n,s);
    rep(i,1,m)if(se[i].size())t.update(*se[i].begin(),*se[i].rbegin()-1,1);
    ll lstans=n-t.getans();
    writell(lstans,10);
    rep(i,1,q){
        const ll x=readll(),y=readll();
        if(a[x]==y){
            writell(lstans);
            continue;
        }
        std::set<ll>&lst=se[a[x]],&now=se[a[x]=y];
        if(lst.size()==1)t.update(x,0),lst.erase(lst.begin());
        else{
            if(x==*lst.begin())t.update(x,0),lst.erase(lst.begin()),t.update(x,*lst.begin()-1,-1);
            else if(x==*lst.rbegin())lst.erase(--lst.end()),t.update(*lst.rbegin(),x-1,-1);
            else lst.erase(x);
            t.update(*lst.begin(),lst.size());
        }
        if(!now.size())t.update(x,1),now.insert(x);
        else{
            const ll l=*now.begin(),r=*now.rbegin();
            if(x<l)t.update(l,0),t.update(x,l-1,1);
            else if(x>r)t.update(r,x-1,1);
            now.insert(x),t.update(*now.begin(),now.size());
        }
        writell(lstans=n-t.getans(),10);
    }
    return 0;
}