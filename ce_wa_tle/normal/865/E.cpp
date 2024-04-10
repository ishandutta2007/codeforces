#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),T=1;
char s[126];
int chartoint(int u){
    return u>96?u-87:u-48;
}
int inttochar(int u){
    return u>9?u+87:u+48;
}
void qmin(ll&a,cll b){
    a>b&&(a=b);
}
ll z[1<<13],f[1<<13];
void calc(){
    cll n=mygets(s);
    ll sum=0;
    char ans[15]={'N','O'};
    ref(i,0,n)sum+=s[i]=chartoint(s[i]);
    if(sum%15==0){
        cll p=sum/15,mod=1e18+7;
        ll min=mod;
        ref(S,0,1<<(n-1))if(__builtin_popcount(S)==p){
            z[0]=s[0]+((S<<1)>>(n-1)&1);
            if(z[0]<0||15<z[0])continue;
            ll p2j=1,j=0;
            memset(f,0x3f,8<<(n-1));
            ref(j,0,n-1)f[1<<j]=z[0]<<(j<<2);
            ref(i,1,1<<(n-1)){
                if(i==p2j)z[i]=z[0]+s[n-1-j]-((S>>j&1)<<4)+((S<<1)>>j&1),p2j<<=1,j++;
                else z[i]=z[i&~-i]+z[i&-i]-z[0];
                //printf("z[%lld]=%lld %lld\n",i,z[i],f[i]);
                if(0<=z[i]&&z[i]<=15)ref(j,0,n-1)if(~(i>>j)&1)qmin(f[i^1<<j],f[i]^z[i]<<(j<<2));//,printf("%lld %lld %lld %lld\n",i,j,f[i]^z[i]<<(j<<2),i^1<<j);
            }
            //printf("S=%lld %lld\n",S,f[(1<<(n-1))-1]);
            min=std::min(min,f[(1<<(n-1))-1]);
        }
        if(min!=mod)rfor(ll u=min,j=n;j;u/=16)ans[--j]=inttochar(u%16);
    }
    myputs(ans);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}
//fd11