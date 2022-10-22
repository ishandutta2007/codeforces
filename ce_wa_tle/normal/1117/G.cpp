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
aN a,st[20],l,r,s,g,ql;
typedef ll twins __attribute__((vector_size(16)));
typedef twins a2[N];
a2 fl,fr;
ll max2(ll x,ll y){
    return a[x]>a[y]?x:y;
}
int main(){
    IO();
    const ll n=readll(),q=readll();
    ll t=0;
    rep(i,1,n){
        st[0][i]=i,a[i]=readll();
        while(t&&a[i]>a[g[t]])r[g[t--]]=i-1;
        l[i]=g[t]+1,g[++t]=i;
    }
    while(t)r[g[t--]]=n;
    rep(i,1,n)s[i]=s[i-1]+r[i]-l[i],fr[i]=fr[l[i]-1]+(twins){1,r[i]};
    per(i,n,1)fl[i]=fl[r[i]+1]+(twins){1,l[i]};
    ref(i,0,19)rep(u,1,n)st[i+1][u]=max2(st[i][u],st[i][u+(1<<i)]);
    rep(i,1,q)ql[i]=readll();
    rep(i,1,q){
        const ll l=ql[i],r=readll(),lg=__builtin_clzll(r-l+1)^63,t=max2(st[lg][l],st[lg][r-(1<<lg)+1]);
        twins tr=fr[r]-fr[::l[t]-1],tl=fl[l]-fl[::r[t]+1];
        writell(s[r]-s[l-1]-tr[1]+tr[0]*r+tl[1]-tl[0]*l+r-l+1);
    }
    return 0;
}