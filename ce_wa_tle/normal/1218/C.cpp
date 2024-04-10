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
const ll N=1e6+7,mod=1e18+7,iz=1<<21,oz=1<<22;
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
    c&&pc(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
const ll M=505;
ll f[M][2][M],g[M][M],c[2][M];
struct node{
    ll w,e;
};
std::vector<node>h[M][M][2];
static inline ll check(ll t,ll w){
    return w>=t&&!((t^w)&3);
}
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
int main(){
    IO();
    const ll n=readll(),m=readll(),k=readll();
    rep(i,1,k){
        const ll x=readll(),y=readll(),d=readll(),t=readll(),e=readll();
        const ll z=x+y,w=x+y+d,p0=check(t,z),p1=check(t+1,z),p2=check(t+2,w),p3=check(t+3,w);
        if(p0)g[x][y]+=e;
        if(p1)g[x+d][y-d]+=e;
        if(p2)g[x+d][y]+=e;
        if(p3)g[x][y+d]+=e;
        if(p0&&p2)h[x+d][y][1].push_back((node){x,e});
        if(p0&&p3)h[x][y+d][0].push_back((node){y,e});
        if(p1&&p2)h[x+d][y][0].push_back((node){y-d,e});
    }
    //ref(i,0,n)ref(j,0,m)printf("%lld%c",g[i][j],j==m-1?10:32);
    ref(i,0,n)ref(j,0,m){
        if(!i&&!j){
            f[j][0][0]=f[j][1][0]=g[0][0];
            continue;
        }
        rep(t,0,1){
            const std::vector<node>&now=h[i][j][t];
            const ll up=now.size();
            ref(k,0,up)c[t][now[k].w]+=now[k].e;
        }
        f[j][0][j]=f[j][1][i]=mod;
        if(i){
            ll now=g[i][j];
            per(k,i-1,0)qm(f[j][0][j],f[j][1][k]+=now-=c[1][k]);
        }
        if(j){
            ll now=g[i][j];
            per(k,j-1,0)qm(f[j][1][i],f[j][0][k]=f[j-1][0][k]+(now-=c[0][k]));
        }
        //rep(k,0,i)printf("f[%lld][%lld][0][%lld]=%lld\n",i,j,k,f[j][0][k]);
        //rep(k,1,j)printf("f[%lld][%lld][1][%lld]=%lld\n",i,j,k,f[j][1][k]);
        rep(t,0,1){
            const std::vector<node>&now=h[i][j][t];
            const ll up=now.size();
            ref(k,0,up)c[t][now[k].w]-=now[k].e;
        }
    }
    ll ans=mod;
    ref(k,n-1,n)qm(ans,f[m-1][1][k]);
    ref(k,m-1,m)qm(ans,f[m-1][0][k]);
    writell(ans);
    return 0;
}