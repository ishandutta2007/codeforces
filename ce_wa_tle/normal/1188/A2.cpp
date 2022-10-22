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
const ll N=1e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
aN head,to,next,w,d,z,a;
struct ans_t{
    ll x,y,c;
    void print()const{
        writell(x),writell(y),writell(c,10);
    }
}p[N];
ll cnt,t,rt;
void add(ll u,ll v,ll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
void dfs(ll u,ll fa){
    ll v1=0,v2=0;
    rev(i,u,v)if(v^fa)a[v]=w[i],dfs(v,u),a[u]-=w[i],v1?v2=v:z[u]=z[v1=v];
    if(!v1)z[u]=u,p[++t]=(ans_t){u,rt,a[u]};
    else if(v2&&a[u]){
        v1=z[v1],v2=z[v2];
        p[++t]=(ans_t){v1,rt,a[u]/2},p[++t]=(ans_t){v2,rt,a[u]/2},p[++t]=(ans_t){v1,v2,-a[u]/2};
    }
}
int main(){
    IO();
    const ll n=readll();
    ll u,v,c;
    rep(i,2,n)u=readll(),v=readll(),c=readll(),add(u,v,c),add(v,u,c),d[u]++,d[v]++;
    rep(i,1,n)if(d[i]==2&&w[head[i]]!=w[next[head[i]]])return!myputs("NO");
    rep(i,1,n)if(d[i]==1){
        rt=i;
        dfs(i,0);
        break;
    }
    myputs("YES"),writell(t,10);
    rep(i,1,t)p[i].print();
    return 0;
}