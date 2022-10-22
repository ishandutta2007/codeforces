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
ll f[1<<12],h[1<<12],g[2000][12],l[2000],c[2000];
int cmp(ll a,ll b){
    return g[a][l[a]]>g[b][l[b]];
}
void calc(){
    const ll n=readll(),m=readll();
    ref(i,0,n)ref(j,0,m)g[j][i]=readll();
    memset(l,0,m<<3);
    ref(j,0,m){
        ref(i,1,n)if(g[j][i]>g[j][l[j]])l[j]=i;
        c[j]=j;
    }
    const ll s=std::min(n,m);
    std::nth_element(c,c+s-1,c+m,cmp);
    memset(f,0,8<<n);
    ref(j,0,s){
        ref(i,0,n)h[1<<i]=g[c[j]][i];
        ref(i,0,1<<n)h[i]=h[i&-i]+h[i&~-i];
        ref(t,0,n)ref(i,0,1<<n)h[i]=std::max(h[i],h[i>>1|(1<<(n-1)&-(i&1))]);
        per(i,(1<<n)-1,0)rej(t,i)f[i]=std::max(f[i],h[t]+f[i^t]);
    }
    writell(f[(1<<n)-1],10);
}
int main(){
    IO();
    ll T=readll();
    while(T--)calc();
    return 0;
}
/*
24

2 2

5 2

1 5

1 1

3

1 2

1 1

1 2

1 1

1 2

2 3

2 1

1

1

1 1

1

2 1

1

1

1 2

2 3

2 2

1 3

3 3

1 1

1

2 1

3

4

1 1

2

2 2

1 1

1 1

2 2

1 1

1 1

1 1

1

2 1

1

1

2 1

5

3

1 1

2

1 2

2 2

2 1

1

1

2 2

3 2

2 4

1 1

5

1 2

2 1

1 2

1 1

1 2

1 1

1 2

1 1




*/