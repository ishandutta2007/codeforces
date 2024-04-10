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
template<int dft=-1>
struct hash{
    static const ll m=9260817;
    typedef ll aN[m];
    aN k,v; 
    mutable ll l;
    ll g(ll b)const{
        if(k[l]==b)return l;
        ll n=b%m,x=0;
        while(k[n]&&k[n]!=b)n=(n+2*x+++1)%m;
        return l=n;
    }
    int count(ll b)const{
        return!!k[g(b)];
    }
    ll operator[](ll b)const{
        ll n=g(b);
        return k[n]?v[n]:dft;
    }
    ll&operator[](ll b){
        ll n=g(b);
        return!k[n]?k[n]=b,v[n]=dft:v[n];
    }
};
hash<-1>t;
ll add(ll&u,ll c){
    return c==0?0:c==1?!u++:-!--u;
}
aN p2;
template<int size>
struct ss{
    ll n0,n2,v0[size],v1[size];
    void set(ll n){
        n2=n;
    }
    void update(ll u,ll c,ll c0){
        if(!v0[u]==!v1[u])(v0[u]?n0:n2)--;
        (c?v1[u]:v0[u])+=c0;
        if(!v0[u]==!v1[u])(v0[u]?n0:n2)++;
        //printf("%lld %lld\n",n0,n2);
    }
    void ins(ll u,ll c){
        update(u,c,1);
    }
    void del(ll u,ll c){
        update(u,c,-1);
    }
    ll getans()const{
        return n0?0:p2[n2];
    }
};
ss<N>a,b;
ss<1>c;
int main(){
    IO();
    ll n=readll(),m=readll(),q=readll();
    ref(i,p2[0]=1,N)p2[i]=p2[i-1]*2%mod;
    a.set(n),b.set(m),c.set(1);
    //writell(a.getans()+b.getans()-c.getans(),10);
    rep(i,1,q){
        ll x=readll(),y=readll(),s=readll();
        ll&now=t[x*n+y];
        //printf("%lld %lld %lld->%lld\n",x,y,now,s);
        if(~now)a.del(x,(now^y)&1),b.del(y,(now^x)&1),c.del(0,(now^y^x)&1);
        if(~(now=s))a.ins(x,(now^y)&1),b.ins(y,(now^x)&1),c.ins(0,(now^y^x)&1);
        writell((mod+a.getans()+b.getans()-c.getans())%mod,10);
    }
    return 0;
}
/*
1000 1000 3

578 815 -1

31 458 0

887 997 -1

570 376 -1

980 959 -1

936 580 -1

157 817 -1

724 162 1

513 469 -1

*/