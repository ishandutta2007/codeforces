#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout),0))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=2e5+7,B=107,mod=1e9+7,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),n=readll(),k=readll(),s=31^__builtin_clz(k);
void qm(ll&a,cll b=mod){
    a>=b&&(a-=b);
}
struct matrix{
    ll val[32][32];
    matrix(cll x=0){
        memset(val,0,1<<13);
        if(x==1||x==2)rep(i,0,k)val[i][i]=1;
        if(x==2)rep(i,0,k)val[i][1]=1;
    }
    void merge(const matrix&a,const matrix&b){
        static cll m2=mod*mod;
        ll c[32][32];
        rep(i,0,k)rep(j,0,k)c[i][j]=0;
        rep(i,0,k)rep(l,0,k)rep(j,0,k)qm(c[i][j]+=a.val[i][l]*b.val[l][j],m2);
        rep(i,0,k)rep(j,0,k)val[i][j]=c[i][j]%mod;
    }
    void ushift(cll s){
        ll c[32][32];
        memcpy(c+1,val+k-s+1,s<<8);
        memmove(val+s+1,val+1,(k-s)<<8);
        memcpy(val+1,c+1,s<<8);
    }
    void print()const{
        rep(i,0,k)rep(j,0,k)printf("%lld%c",val[i][j],j==k?10:32);
    }
}A(2),pA[32];
struct vector{
    ll val[32];
    void merge(const vector&a,const matrix&b){
        static cll m2=mod*mod;
        ll c[32];
        rep(j,0,k)c[j]=0;
        rep(l,0,k)rep(j,0,k)qm(c[j]+=a.val[l]*b.val[l][j],m2);
        rep(j,0,k)val[j]=c[j]%mod;
    }
    void print()const{
        rep(j,0,k)printf("%lld%c",val[j],j==k?10:32);
    }
}v={1};
int main(){
    ll u=n;
    while(u){
        A.ushift(1);
        pA[0]=A;
        rep(i,1,s)A.merge(A,A),pA[i]=A;
        rep(i,0,s)if((u%k)>>i&1)v.merge(v,pA[i]);
        A=1;
        rep(i,0,s)if(k>>i&1)A.merge(A,pA[i]);
        u/=k;
    }
    ll sum=0;
    rep(i,0,k)sum+=v.val[i];
    writell(sum%mod,10);
    return 0;
}