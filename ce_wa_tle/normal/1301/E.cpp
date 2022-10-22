#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout);
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
const ll M=512;
char a[M][M],dy[126];
ll st[9][9][M][M],(&z)[M][M]=st[0][0],lg[M];
static inline ll max(ll a,ll b){
    return a<b?b:a;
}
static inline ll min(ll a,ll b){
    return a>b?b:a;
}
static inline ll calc(ll r1,ll r2,ll c1,ll c2){
    //printf("%lld %lld %lld %lld\n",r1,r2,c1,c2);
    const ll rg=lg[r2-r1+1],cg=lg[c2-c1+1],(&z)[M][M]=st[rg][cg];
    r2-=(1<<rg)-1,c2-=(1<<cg)-1;
    return max(max(z[r1][c1],z[r1][c2]),max(z[r2][c1],z[r2][c2]));
}
int main(){
    IO();
    ref(i,2,M)lg[i]=lg[i>>1]+1;
    const ll n=readll(),m=readll(),q=readll();
    dy['R']=0,dy['G']=1,dy['Y']=2,dy['B']=3;
    rep(i,1,n)rep(j,1,m)a[i][j]=dy[readchar()];
    per(i,n,1)per(j,m,1)if(a[i][j]==a[i+1][j]&&a[i][j]==a[i][j+1]&&a[i][j]==a[i+1][j+1])
    z[i][j]=min(z[i+1][j],min(z[i][j+1],z[i+1][j+1]))+1;else z[i][j]=1;
    rep(i,1,n)rep(j,1,m)if(a[i][j]&1||a[i][j+z[i][j]]!=(a[i][j]|1)||z[i][j+z[i][j]]<z[i][j])z[i][j]=0;
    rep(i,1,n)rep(j,1,m)if(a[i][j]&2||a[i+z[i][j]][j]!=(a[i][j]|2)||z[i+z[i][j]][j]<z[i][j])z[i][j]=0;
    per(i,n,1)per(j,m,1)if(const ll v=z[i][j])z[i][j]=0,z[i+v-1][j+v-1]=v;
    //rep(i,1,n)rep(j,1,m)writell(z[i][j],j==m?10:32);
    rep(j,0,7)rep(u,1,n)rep(v,1,m-(1<<j)+1)st[0][j+1][u][v]=max(st[0][j][u][v],st[0][j][u][v+(1<<j)]);
    rep(i,0,7)rep(j,0,8)rep(u,1,n-(1<<i)+1)rep(v,1,m-(1<<j)+1)st[i+1][j][u][v]=max(st[i][j][u][v],st[i][j][u+(1<<i)][v]);
    rep(i,1,q){
        const ll r1=readll(),c1=readll(),r2=readll(),c2=readll();
        ll l=0,r=std::min(r2-r1+1,c2-c1+1)/2;
        while(l<=r){
            const ll mid=(l+r)>>1;
            if(calc(r1+mid-1,r2-mid,c1+mid-1,c2-mid)>=mid)l=mid+1;
            else r=mid-1;
        }
        writell(4*(l-1)*(l-1),10);
    }
    return 0;
}