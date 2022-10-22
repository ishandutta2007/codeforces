#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x"in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=4e5+7,mod=1e9+7,iz=1<<21,oz=1<<22,inf=0x3f3f3f3f3f3f3f3f;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1!=o2)fout();
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
aN next,to,head,tot,now,tag1,tag2,c;
ll cnt,tot2;
struct hash{
    static const ll m=9260817;
    ll v[m],k[m];
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
        return k[n]?v[n]:0;
    }
    ll&operator[](ll b){
        ll n=g(b);
        return!k[n]?k[n]=b,v[n]=0:v[n];
    }
}t;
ll get(ll u){
    static ll cnt=0;
    return t.count(u)?t[u]:t[u]=++cnt;
}
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs0(ll u,ll fa){
    ll lstf=now[c[fa]],lstu=now[c[u]];
    now[c[u]]++;
    rev(i,u,v)if(v^fa)dfs0(v,u);
    if(now[c[u]]-lstu!=tot[c[u]])tag1[u]=1;
    if(lstf!=now[c[fa]])tot2++,tag2[u]=1;
}
ll dfs2(ll u,ll fa){
    tag1[u]+=tag1[fa],tag2[u]+=tag2[fa];
    if(tag1[u])return 0;
    ll sum=tag2[u]==tot2;
    rev(i,u,v)if(v^fa)sum+=dfs2(v,u);
    return sum;
}
int main(){
    IO();
    ll n=readll(),u,v;
    rep(i,1,n)tot[c[i]=get(readll())]++;
    rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    dfs0(1,0);
    writell(dfs2(1,0));
    return 0;
}