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
aN next,to,head,p,a,c,id,u,v,w;
ll cnt=1;
void add(ll u,ll v,ll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,id[cnt]=c;
}
ll x,y,z;
void dfs0(ll u){
    rev(i,u,v)if(!~c[v]?c[v]=c[u]^1,p[v]=i^1,dfs0(v),z:c[v]==c[u]&&(y=u,x=v,z=id[i]))return;
}
ll dfs2(ll u){
    ll res=a[u];
    c[u]=-2;
    rev(i,u,v)if(c[v]!=-2)res-=w[id[i]]=dfs2(v);
    return res;
}
static inline ll m3(ll u){
    const ll res=u%3;
    return res<0?res+3:res;
}
int main(){
    IO();
    const ll n=readll(),m=readll();
    ref(i,0,n)a[i]=readchar()^88;
    rep(i,1,m)u[i]=readll(),v[i]=readll(),add(u[i],v[i],i),add(v[i],u[i],i);
    memset(c,-1,n<<3),c[0]=0,dfs0(0);
    if(!z){
        memcpy(a,c,n<<3);
        if(m3(dfs2(0))==2&&next[head[0]])w[id[head[0]]]++,w[id[next[head[0]]]]++;
    }else if(ll r=m3(dfs2(x)))for(w[z]-=r;y!=x;y=to[p[y]])w[id[p[y]]]+=r,r=-r;
    rep(i,1,m)writell(u[i]),writell(v[i]),writell(3-m3(3-w[i]),10);
    return 0;
}