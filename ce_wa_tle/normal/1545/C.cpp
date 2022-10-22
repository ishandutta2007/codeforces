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
ll a[1001][501],t[501][501],n;
aN flag;
ll find(){
    rep(j,1,n)rep(k,1,n)if(t[j][k]==1){
        //printf("??? %lld %lld\n",j,k);
        rep(i,1,2*n)if(!flag[i]&&a[i][j]==k)return i;
    }
    return-1;
}
int check(ll x,ll y){
    rep(i,1,n)if(a[x][i]==a[y][i])return 0;
    return 1;
}
void del(ll u){
    //printf("del %lld\n",u);
    rep(i,1,n)t[i][a[u][i]]--;
}
void calc(){
    n=readll();
    ll ans=1;
    memset(flag+1,0,n<<4);
    rep(i,1,2*n)rep(j,1,n)t[j][a[i][j]=readll()]++;
    //rep(j,1,n)rep(k,1,n)printf("t[%lld][%lld]=%lld\n",j,k,t[j][k]);
    rep(s,1,n){
        ll g=find();
        //printf("g=%lld\n",g);
        if(g==-1){
            rep(i,1,2*n)if(!flag[i]){
                g=i;
                ans=ans*2%mod;
                break;
            }
            if(g==-1)break;
        }
        flag[g]=1,del(g);
        rep(i,1,2*n)if(!flag[i]&&!check(i,g))flag[i]=-1,del(i);
    }
    writell(ans,10);
    rep(i,1,2*n)if(flag[i]==1)writell(i);
    pc(10);
}
int main(){
    IO();
    ll T=readll();
    while(T--)calc();
    return 0;
}