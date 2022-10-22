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
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
struct lct{
    aN s[2],f,id,sor,rev,tag,&ls,&rs;
    lct():ls(s[0]),rs(s[1]){memset(tag,-1,sizeof tag);}
    void pushup(ll u){
        if(!u)return;
        sor[u]=sor[ls[u]]|sor[rs[u]];
        if(~id[u])sor[u]|=id[u];
    }
    void pushdown(ll u){
        if(!u)return;
        if(rev[u])std::swap(ls[u],rs[u]),rev[ls[u]]^=1,rev[rs[u]]^=1,rev[u]=0;
        if(~tag[u])(ls[u]||rs[u])&&(tag[ls[u]]=tag[rs[u]]=sor[u]=tag[u]),~id[u]&&(id[u]=sor[u]=tag[u]),tag[u]=-1;
    }
    void pushson(ll u){
        //printf("%lld %lld %lld\n",u,ls[u],rs[u]);
        pushdown(ls[u]),pushdown(rs[u]);
    }
    ll wz(ll u)const{
        const ll fa=f[u];
        return((u==rs[fa])<<1|(u==ls[fa]))-1;
    }
    void cct(ll u,ll fa,ll w){
        u&&(f[u]=fa),~w&&fa&&(s[w][fa]=u);
    }
    void rtt(ll u){
        //printf("%lld\n",u),assert(f[u]),assert(!rev[f[u]]),assert(!~tag[f[u]]);
        const ll v=f[u],w=f[v],wu=wz(u),wx=wu^1,x=s[wx][u],wv=wz(v);
        cct(v,u,wx),cct(x,v,wu),cct(u,w,wv),pushup(v),pushup(u);
    }
    void splay(ll u){
        static aN st;
        ll ts=0;
        rfor(ll now=u;now;now=~wz(now)?f[now]:0)st[++ts]=now;
        //printf("splay %lld %lld\n???\n",u,ts);
        for(pushdown(st[ts]);ts;)pushson(st[ts--]);
        //printf("[%lld %lld %lld %lld]\n",f[0],ls[0],rs[0],tag[0]);
        rfor(ll v;~wz(u);rtt(u))if(~wz(v=f[u]))rtt(wz(u)==wz(v)?v:u);
        assert(!~wz(u));
    }
    void access(ll u){
        rfor(ll x=0;u;x=u,u=f[u])splay(u),assert(!rev[u]),rs[u]=x,pushup(u);
        //printf("access %lld\n",u);
    }
    ll findroot(ll u){
        //printf("findroot %lld\n",u);
        for(access(u),splay(u),pushdown(u);const ll s=ls[u];pushdown(u=s));
        return splay(u),u;
    }
    void makeroot(ll u){
        //printf("makeroot %lld\n",u);
        access(u),splay(u),rev[u]^=1;
    }
    void show(ll u){
        if(!u)return;
        pushdown(u);
        show(ls[u]);
        printf("id[%lld]=%lld %lld %lld %lld %lld %lld\n",u,ls[u],id[u],rs[u],f[u],sor[u],tag[u]);
        show(rs[u]);
    }
    int split(ll u,ll v){
        //printf("split %lld %lld\n",u,v);
        return makeroot(u),findroot(v)==u?splay(v),1:(splay(v),0);
    }
    int link(ll u,ll v){
        //printf("link %lld %lld\n",u,v);
        return makeroot(u),findroot(v)!=u?f[u]=v,1:0;
    }
    int cut(ll u,ll v){
        //printf("cut %lld %lld\n",u,v);
        return makeroot(u),findroot(v)==u&&f[v]==u&&!ls[v]?f[v]=rs[u]=0,pushup(u),1:0;
    }
    void set(ll n){
        memset(id+1,-1,n<<3);
    }
}t;
aN u,v;
ll n,m;
int check(ll x){
    //printf("check %lld\n",x);
    const ll u=::u[x],v=::v[x];
    x+=n;
    //#define return(x...)ll res=(x);t.show(v);printf("[%lld %lld]->%lld\n",u,v,res);return res
    return(!t.split(u,v)||!t.sor[v]);
}
void add(ll x){
    //printf("add %lld\n",x);
    const ll u=::u[x],v=::v[x];
    //rep(i,1,m)printf("%lld %lld\n",::u[i],::v[i]);
    x+=n;
    if(t.split(u,v))t.tag[v]=t.id[x]=x;
    else t.link(u,x),t.link(x,v);
}
void del(ll x){
    //printf("del %lld\n",x);
    const ll u=::u[x],v=::v[x];
    //rep(i,1,m)printf("%lld %lld\n",::u[i],::v[i]);
    x+=n;
    t.cut(u,x)&&t.cut(x,v);
    if(const ll d=t.id[x]){
        if(d!=x)add(d-n);
        t.split(u,v),t.tag[v]=0;
    }
}
int main(){
    IO();
    ll n=::n=readll(),m=::m=readll(),sum=0,l=1;
    t.set(n);
    rep(i,1,m)u[i]=readll(),v[i]=readll();
    rep(r,1,m)for(add(r),sum+=r-l+1;r<m&&l<r&&!check(r+1);)del(l++);
    writell(sum);
    return 0;
}
/*
5 6
1 2
2 3
3 4
4 5
5 1
2 4



8 11
1 2
2 3
2 4
3 4
4 1
5 6
6 8
6 7
7 8
7 5
8 5
*/