#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
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
aN a,l,r,s;
static inline void qm(ll&a,cll b){
    a>b&&(a=b);
}
struct sgt{
    ll n;
    aN f,t;
    void set(ll n_){
        /*n=n_;
        rep(i,0,n)f[i]=i;
        return;*/
        n=2<<(31^__builtin_clz(n_+2));
        memset(t,0,(n+1)<<4);
        rep(i,0,n_)f[n+i]=i;
        rep(i,n_+1,n)f[n+i]=mod;
        per(i,n-1,1)f[i]=std::min(f[i<<1],f[i<<1|1]);
    }
    void update(ll l,ll c){
        /*rep(i,l,n)f[i]+=c;
        return;*/
        if(l==0){
            t[1]+=c;
            return;
        }
        ll x=f[l+n-1];
        red(i,l+n-1)~i&1&&(t[i^1]+=c),f[i]=x,qm(x+=t[i],f[i^1]+t[i^1]);
    }
    ll query()const{
        /*ll res=mod;
        rep(i,0,n)qm(res,f[i]);
        return res;*/
        return f[1]+t[1];
    }
}t;
void calc(){
    cll n=readll();
    ll c=0,x;
    rep(i,1,n)a[i]=readll(),c+=!a[i];
    c/=2;
    memset(l,0,(n+1)<<3),memset(r,0,(n+1)<<3),memset(s,0,(n+1)<<3);
    x=0;rep(i,1,n){
        if((x+!a[i])==c+1)break;
        l[a[i]]=x+=!a[i],s[a[i]]=i;
    }
    x=0;per(i,n,1){
        if((x+!a[i])==c+1)break;
        r[a[i]]=x+=!a[i];
    }
    l[0]=r[0]=s[0]=-1;
    ll min=c;
    t.set(c);
    ll p=0,k=0;
    rep(i,1,n)if(l[i]==0)t.update(r[i],-1),k++,s[i]=-1;
    while(++p<=n&&s[a[p]]!=p);
    qm(min,t.query()+n);
    rep(i,1,c){
        while(p<n&&l[a[p]]==i){
            t.update(r[a[p]],-1),k++;
            while(++p<=n&&s[a[p]]!=p);
        }
        //printf("%lld %lld %lld %lld\n",i,t.query(),n,i+t.query()+n);
        qm(min,i+t.query()+n);
    }
    //assert(k==n);
    writell(min,10);
}
int main(){
    IO();
    //gc=getchar;
    cll T=readll();
    rep(i,1,T)calc();
    return 0;
}
/*
6
30
0 5 30 15 0 17 0 0 0 30 0 0 0 0 0 0 11 0 15 23 26 0 15 2 0 23 4 0 7 12
30
2 11 15 28 0 4 23 4 0 2 0 25 27 3 16 0 0 26 0 15 25 0 0 16 0 0 29 19 10 15
30
11 0 15 3 5 5 21 0 0 6 11 26 0 13 4 16 0 30 0 0 12 26 0 0 0 0 6 12 0 0
30
14 0 0 9 19 28 16 0 0 0 0 0 26 0 4 0 0 12 0 20 0 0 18 0 20 22 16 2 0 0
30
0 20 14 8 3 0 14 29 0 13 0 29 28 0 14 0 0 0 6 11 0 0 23 0 0 16 0 23 0 0
30
0 0 24 0 0 3 12 0 0 0 0 0 17 0 0 16 0 0 11 21 2 0 0 11 10 6 0 0 3 0



1
6
0 5 0 3 0 0

8
1
1
2
0 0
3
0 1 0
6
0 0 1 2 0 0
6
0 1 0 0 1 0
6
0 1 3 2 0 0
6
0 0 0 0 5 0
12
0 1 0 2 2 2 0 0 3 3 4 0

*/