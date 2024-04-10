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
const ll N=4e5+7,mod=998244353,iz=1<<21,oz=1<<22;
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
struct ACAM{
    aN s[26],f,q;
    ll cnt;
    ACAM():cnt(1){}
    ll insert(const char*t){
        ll now=1;
        while(const int c=*t++)now=s[c-97][now]?:s[c-97][now]=++cnt;
        return now;
    }
    void getfail(){
        f[q[1]=1]=0;
        ref(i,0,26)s[i][0]=1;
        rfor(ll h=1,t=1;const ll u=q[h++];)
        ref(i,0,26)(s[i][u]?q[++t]=s[i][u],f[s[i][u]]:s[i][u])=s[i][f[u]];
    }
}a;
struct LCT{
    aN s[2],&ls,&rs,v,f,max;
    LCT():ls(s[0]),rs(s[1]){}
    void set(const ll*fa,ll n){
        memcpy(f+1,fa+1,n<<3),memset(v,-1,sizeof v),memset(max,-1,sizeof max);
    }
    ll wz(ll u)const{
        if(const ll fa=f[u])return((u==rs[fa])<<1|(u==ls[fa]))-1;
        else return-1;
    }
    void pushup(ll u){
        if(u)max[u]=std::max(max[ls[u]],std::max(v[u],max[rs[u]]));
    }
    void cct(ll u,ll fa,ll w){
        if(u)f[u]=fa;
        if(fa&&~w)s[w][fa]=u;
    }
    void rtt(ll u){
        //printf("rtt =%lld %lld\n",f[2],ls[f[2]]);
        const ll v=f[u],w=f[v],wu=wz(u),wv=wz(v),wx=wu^1,x=s[wx][u];
        cct(x,v,wu),cct(u,w,wv),cct(v,u,wx),pushup(v),pushup(u);
    }
    void splay(ll u){
        //printf("splay =%lld %lld\n",u,ls[1]);
        for(ll v;v=f[u],~wz(u);rtt(u))if(~wz(v))rtt(wz(u)==wz(v)?v:u);
    }
    void access(ll u){
        for(ll x=0;u;x=u,u=f[u])splay(u),rs[u]=x,pushup(u);
    }
    void update(ll u,ll c){
        //printf("%lld=%lld\n",u,c);
        splay(u),v[u]=c,pushup(u);
    }
    ll query(ll u){
        //printf("query %lld %lld %lld\n",u,f[u],ls[1]);
        return access(u),splay(u),max[u];
    }
}t;
char s[N];
aN lst,id;
std::multiset<ll>val[N];
int main(){
    IO();
    ll n=readll(),m=readll();
    rep(i,1,n)mygets(s),id[i]=a.insert(s);
    a.getfail(),t.set(a.f,a.cnt);
    rep(i,1,n)val[id[i]].insert(t.v[id[i]]=t.max[id[i]]=0);
    rep(i,1,m)if(readll()==1){
        const ll u=readll(),c=readll(),g=id[u];
        val[g].erase(val[g].lower_bound(lst[u])),val[g].insert(lst[u]=c),t.update(g,*--val[g].end());
    }else{
        mygets(s);
        ll now=1,ans=-1;
        for(const char*t=s;const int c=*t++;)
        ans=std::max(ans,::t.query(now=a.s[c-97][now]));
        writell(ans);
    }
    return 0;
}