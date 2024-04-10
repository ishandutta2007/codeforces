#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
void writell(cll u,int c=32){
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
cll IO_res=IO(),T=readll();
aN p,st,a,ls,rs,s,lm,rm,f;
ll cnt;
void dfs(cll u,cll fa){
    if(u==0)return;
    //printf("%lld -> %lld\n",fa,u);
    if(a[u])lm[u]=rm[u]=a[u];
    else lm[u]=-mod,rm[u]=mod;
    rm[u]=std::min(rm[u],rm[fa]);
    dfs(ls[u],u),dfs(rs[u],u);
    lm[u]=std::max(lm[u],std::max(lm[ls[u]],lm[rs[u]]));
}
struct sgt{
    ll f[1<<21|1<<17],w[1<<21|1<<17];
    ll n;
    void pushup(cll u){
        cll t=std::min(f[u<<1],f[u<<1|1]);
        f[u]+=t,f[u<<1]-=t,f[u<<1|1]-=t,w[u]=w[u<<1|!f[u<<1|1]];
    }
    void set(cll n_){
        n=2<<(31^__builtin_clz(n_+2));
        memset(f,0,(n+1)<<4);
        rep(i,1,n_)w[i+n]=i;
        per(i,n-1,1)pushup(i);
    }
    void update(ll l,ll r,cll c){
        //printf("update %lld %lld %lld\n",l,r,c);
        for(l+=n-1,r+=n+1;l^r^1;pushup(l>>=1),pushup(r>>=1))
        ~l&1&&(f[l^1]+=c),r&1&&(f[r^1]+=c);
        red(i,l>>1)pushup(i);
        //printf("%lld %lld\n",f[1],w[1]);
    }
    ll getans()const{
        return f[1]<-1?mod:f[1]==-1?w[1]:-mod;
    }
}dt;
int cmp(ll a,ll b){
    return rm[a]<rm[b];
}
void calc(){
    cll n=readll(),q=readll();
    ll t=0;
    rep(i,1,n){
        p[i]=readll();
        ll x=0;
        while(t&&p[st[t]]<p[i])rs[st[t]]=x,x=st[t--];
        ls[st[++t]=i]=x;
    }
    ll x=0;
    while(t)rs[st[t]]=x,x=st[t--];
    ll m=0;
    rep(i,1,n)(a[i]=readll())||++m;
    rep(i,1,m-1)s[i]=readll();
    std::sort(s+1,s+m);
    lm[0]=-mod,rm[0]=mod,dfs(x,0);
    ll l=-mod,r=mod,tp=0;
    //rep(i,1,n)printf("[ %lld , %lld ]\n",lm[i],rm[i]);
    rep(i,1,n)if(lm[i]>rm[i]){
        l=mod;
        break;
    }else if(a[i]==0)p[++tp]=i;
    if(l!=mod){
        std::sort(p+1,p+tp+1,cmp);
        //rep(i,1,m-1)printf("s = %lld\n",s[i]);
        //rep(i,1,tp)printf("[ %lld , %lld ]\n",lm[p[i]],rm[p[i]]);
        ll j=1;
        rep(i,1,tp){
            while(j<m&&s[j]<=rm[p[i]])dt.update(1,s[j++],1);
            if(lm[p[i]]!=-mod)dt.update(1,lm[p[i]],-1);
            cll t=i>j?mod:dt.getans();
            //printf("%lld %lld\n",rm[p[i]],t);
            if(i>=j)r=std::min(r,rm[p[i]]);
            if(t!=-mod)l=std::max(l,t),r=std::min(r,rm[p[i]]);
            if(t==mod||i==tp){
                rep(j,1,i)if(lm[p[j]]!=-mod)dt.update(1,lm[p[j]],1);
                break;
            }
        }
        while(j!=1)dt.update(1,s[--j],-1);
    }
    //printf("[ %lld , %lld ] \n",l,r);
    rep(i,1,q){
        cll x=readll();
        myputs(l<=x&&x<=r?"YES":"NO");
    }
}
int main(){
    dt.set(1e6);
    rep(i,1,T)calc();
    return 0;
}
/*
1
4 1
3 1 4 2
3 0 4 0
7
2
4
4 3
1 4 3 2
5 0 7 0
6
9
1
4
5 3
1 2 5 4 3
0 5 10 0 0
3 9
1
8
11
5 2
1 4 3 2 5
0 0 0 0 0
7 9 1 5
6
100
4 2
4 1 3 2
0 5 3 0
2
4
6
*/