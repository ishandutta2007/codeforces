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
const ll N=2e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
int myputs(const char*s=0,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
ll f[1<<14],to[1<<14],c1[4782969],c2[4782969],c3[1<<14],g[4782969],a[14];
ll inv(ll a,ll b=mod){
    ll x=1,y=0,m=b;
    while(b){
        ll t=a/b;
        std::swap(a,b),
        std::swap(x,y),
        b-=t*a,
        y-=t*x;
    }
    return(x+m)%m;
}
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
/*void writeby(ll u,ll k,ll t){
    rep(i,1,t)wt[i]=u%k^48,u/=k;
    per(i,t,1)pc(wt[i]);
}*/
int main(){
    IO();
    ll n=readll(),sum=0;
    ref(i,0,n)a[i]=readll();
    ref(i,0,(1<<n))c3[i]=c3[i>>1]*3+(i&1);//,printf("c3["),writeby(i,2,n),printf("]="),writeby(c3[i],3,n),printf("\n");
    const ll lim=c3[1<<(n-1)]*3;
    ref(i,0,lim)c1[i]=c1[i/3]<<1|(i%3==1),c2[i]=c2[i/3]<<1|(i%3==2);//,printf("c["),writeby(i,3,n),printf("]="),writeby(c1[i],2,n),writeby(c2[i],2,n),printf("\n");
    ref(i,0,n){
        to[0]=1;
        ref(j,0,n)to[1<<j]=a[i]*inv(a[i]+a[j])%mod;//,printf("f[%lld][%lld]=%lld\n",i,j,to[i][1<<j]);
        ref(j,0,1<<n)if(~j>>i&1)g[c3[1<<i]+c3[j]*2]=to[j]=to[j&-j]*to[j&~-j]%mod;
    }
    ll s1,s2;
    ref(i,0,lim)g[i]=(s1=c1[i])?s2=c3[s1&~-s1],s1=c3[s1&-s1],g[i-s1]*g[i-s2]%mod:1;//,printf("g[%lld]=%lld\n",i,g[i]);
    //exit(0);
    ref(i,0,n){
        f[1<<i]=1;
        ref(S,1,1<<n)if(S>>i&1){
            f[S]=1;
            rej(T,S)if(T>>i&1&&T!=S)f[S]=(f[S]+(mod-f[T])*g[c3[S^T]+c3[T]*2])%mod;//,printf("%lld %lld\n",mod-f[T],g[c3[S^T]+c3[T]*2]);
        }
        qm(sum+=f[(1<<n)-1]);
    }
    writell(sum);
    return 0;
}