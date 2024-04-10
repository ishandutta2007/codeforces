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
    for(;c<48||c>57;c=gc());
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
aN a,z,f;
ll rev,n;
void update(ll x,ll c){
    c-=a[x=((x-1)^rev)+1],a[x]+=c;
    rfor(ll u=x;u<=n;u+=u&-u)z[u]+=c;
    rfor(ll u=n-x+1;u<=n;u+=u&-u)f[u]+=c;
}
ll query(ll u){
    ll res=0;
    for(;u;u&=~-u){
        const ll len=u&-u,r=rev&-len;
        res+=((u-1)^r)&len?f[n-(((u-1)^r)+1)+len]:z[((u-1)^r)+1];
    }
    return res;
}
int main(){
    IO();
    const ll n=::n=1<<readll(),q=readll();
    rep(i,1,n)a[i]=readll();
    rep(i,1,n)z[i+(i&-i)]+=z[i]+=a[i];
    rep(i,1,n)f[i+(i&-i)]+=f[i]+=a[n-i+1];
    ll x,c,l,r;
    rep(i,1,q)switch(readll()){
        case 1:x=readll(),c=readll(),update(x,c);break;
        case 2:rev^=(1<<readll())-1;break;
        case 3:rev^=1<<readll();break;
        case 4:l=readll(),r=readll(),writell(query(r)-query(l-1),10);
    }
    return 0;
}