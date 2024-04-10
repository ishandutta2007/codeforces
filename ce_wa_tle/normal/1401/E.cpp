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
const ll sz=1e6;
struct bit{
    aN f;
    void update(ll u,ll c){
        for(;u<=sz;u+=u&-u)f[u]+=c;
    }
    ll query(ll u){
        if(u<1)return 0;
        ll res=0;
        for(;u;u&=~-u)res+=f[u];
        return res;
    }
}t;
struct node{
    ll w,l,r;
    operator ll()const{
        return w;
    }
}q[N],p[N];
int main(){
    IO();
    const ll n=readll(),m=readll();
    ll sum=1;
    rep(i,1,n){
        const ll w=readll(),l=readll(),r=readll();
        q[i]=(node){w,l,r};
        sum+=l==0&&r==sz;
    }
    std::sort(q+1,q+n+1);
    rep(i,1,m){
        const ll w=readll(),l=readll(),r=readll();
        p[i*2-1]=(node){l,w,1},p[i*2]=(node){r+1,w,-1};
        sum+=l==0&&r==sz;
    }
    std::sort(p+1,p+2*m+1);
    ll now=1;
    rep(i,1,n){
        while(now<=2*m&&p[now].w<=q[i].w)t.update(p[now].l,p[now].r),now++;
        sum+=t.query(q[i].r)-t.query(q[i].l-1);
    }
    writell(sum);
    return 0;
}