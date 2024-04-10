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
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
ll g[1<<20],f[1<<20];
struct ar{
    static ll s[N],st,z;
    ll g,l,r;
    void set(ll l_,ll r_){
        l=l_,r=r_;
        g=st-l,st+=(r-l+1);
    }
    ll operator[](ll b)const{
        return b<l||b>r?0:s[g+b];
    }
    ll&operator[](ll b){
        return b<l||b>r?z:s[g+b];
    }
}c[N];
ll ar::st,ar::z,ar::s[N];
char s[N];
int main(){
    IO();
    ll n=readll(),max=0;
    ref(i,0,n){
        ll k=mygets(s),h=0,m=0;
        c[i].set(-k,0);
        //rep(j,-k,0)printf("%lld\n",c[i][j]);
        ref(j,0,k)s[j]==')'?qm(m,--h):++h,h==m&&++c[i][h];
        //printf("h=%lld\n",c[i][-1]);
        g[1<<i]=h;
    }
    ref(i,0,1<<n)g[i]=g[i&-i]+g[i&~-i];//,printf("%lld\n",g[i]);
    memset(f,-1,sizeof f);
    f[0]=0;
    ref(i,0,1<<n)if(~f[i]){
        ref(j,0,n)if(~i>>j&1){
            //printf("%lld %lld %lld\n",i,j,c[j][-1]);
            max=std::max(max,f[i]+c[j][-g[i]]);
            if(!c[j][~g[i]])f[i|1<<j]=std::max(f[i|1<<j],f[i]+c[j][-g[i]]);
        }
    }
    writell(max);
    return 0;
}
/*
10

()()

(())

()()

()()

(())

(((())))

()

(())

()()

()


*/