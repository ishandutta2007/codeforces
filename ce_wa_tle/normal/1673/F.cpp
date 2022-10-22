#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],v;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i=i>>1)
#define IO(x...)((*#x!='/'&&#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=3e6+7,mod=2,iz=1<<21,oz=1<<22;
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
void writell(cll u,int c=32){
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
cll IO_res=IO(),T=1,n=readll(),k=readll();
ll f[33][33],x[3024],y[3024];
ll g[32];
ll zhz(ll i,ll j){
    ll x=0,s=0;
    rep(z,1,5){
        x|=(i&1)<<s++,
        x|=(j&1)<<s++,
        i>>=1,j>>=1;
    }
    //printf("%lld %lld-> %lld\n",i,j,x); 
    return x;
}
int main(){
    f[1][1]=0;
    ll cnt=0;
    {
        ll x=0;
        ref(i,0,32)g[x]=i,x^=(1<<__builtin_ctz(i+1));//,printf("%lld\n",g[i]);
    }
    rep(i,1,32)rep(j,1,32)f[g[i-1]+1][g[j-1]+1]=zhz(cnt>>5,cnt&31),cnt++;//zhz(i-1,j-1);
    rep(i,1,n)rep(j,1,n)x[f[i][j]]=i,y[f[i][j]]=j;
    ll sum=0;
    rep(i,1,n){rep(j,2,n)writell(f[i][j]^f[i][j-1]),sum+=f[i][j]^f[i][j-1];pc(10);}
    rep(i,2,n){rep(j,1,n)writell(f[i][j]^f[i-1][j]),sum+=f[i][j]^f[i-1][j];pc(10);}
    //writell(sum);
    fout(),fflush(stdout);
    ll s=0;
    rep(i,1,k){
        s^=readll();
        writell(x[s]),writell(y[s]),fout(),fflush(stdout);
    }
    return 0;
}