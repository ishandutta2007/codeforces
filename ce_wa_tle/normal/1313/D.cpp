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
const ll N=1.1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
struct node{
    ll x,id;
    operator ll()const{
        return x*2+(id>0);
    }
}a[N];
static inline ll max(ll a,ll b){
    return a>b?a:b;
}
ll parity[256],f[2][256],st[8];
int main(){
    IO();
    const ll n=readll(),m=readll(),k=readll();
    ref(i,0,1<<k)parity[i]=parity[i>>1]^(i&1);
    rep(i,1,n)a[(i<<1)-1]=(node){readll(),i},a[i<<1]=(node){readll()+1,-i};
    std::sort(a+1,a+n*2+1);
    static_cast<void>(m);
    ll t=0;
    rep(i,1,n*2){
        const ll val=a[i].x-a[i-1].x,*const lst=f[~i&1],id=a[i].id;
        ll*const now=f[i&1];
        if(id>0){
            ref(j,0,1<<t)now[j]=now[j|1<<t]=lst[j]+(val&-parity[j]);
            st[t++]=id;
        }else{
            ll p=--t;
            while(st[p]!=-id)p--;
            const ll w=p;
            memmove(st+w,st+w+1,(t-w)<<3);
            ref(j,0,1<<t)now[j]=max(lst[j+(j>>w<<w)]+(val&-parity[j]),lst[(j+(j>>w<<w))|1<<w]+(val&~-parity[j]));
        }
    }
    writell(f[0][0]);
    return 0;
}