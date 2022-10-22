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
cll N=1e6+7,mod=1e9+7,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
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
#define $1(x...)x
#define $2(x...)x
cll IO_res=IO(),T=1;
void init(){
}
aN u,d,st,a,l;
ll n;
ll min2(cll u,cll v){
    return v==n+1||a[u]<a[v]?u:v;
}
ll max2(cll u,cll v){
    return v==n+1||a[u]>a[v]?u:v;
}
void calc(){
    cll n=::n=readll();
    rep(i,1,n)a[i]=readll();
    ll t=0;
    rep(i,1,n){
        while(t&&a[st[t]]<a[i])t--;
        d[i]=st[t],st[++t]=i;
    }
    t=0;
    rep(i,1,n){
        while(t&&a[st[t]]>a[i])t--;
        u[i]=st[t],st[++t]=i;
    }
    ll mx=n+1,mn=n+1,r=n;
    per(l,n,1){
        while(r&&max2(l,mx)!=l&&min2(l,mn)!=l)r==mx&&--mx,r==mn&&--mn,::l[r--]=l+1;
        mx=max2(l,mx),mn=min2(l,mn);
    }
    while(r)::l[r--]=1;
    /*rep(i,1,n)printf("%lld\n",u[i]);
    rep(i,1,n)printf("%lld\n",d[i]);
    rep(i,1,n)printf("%lld\n",l[i]);*/
    ll sum=0,l=1;
    rep(r,1,n){
        cll z=std::min(u[r],d[r]);
        if(z>l){
            cll h=z==u[r]?d[z]:u[z];
            if((a[z]>a[r])==(a[h]>a[r]))l=std::max(l,h+1);
            if(::l[z]>l)l=::l[z];
        }
        sum+=r-l+1;
        //printf("z=%lld l=%lld r=%lld\n",z,l,r);
    }
    writell(sum,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}
/*
20
2 1 13 10 12 18 15 19 5 14 16 9 3 8 17 11 7 20 6 4
*/