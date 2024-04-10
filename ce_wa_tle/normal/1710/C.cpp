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
cll N=2e5+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
char s[N];
ll f[N][8];
cll d[]={0,1,3,4,6,7};
void calc(){
    cll n=mygets(s+1);
    //cll n=200000;
    //rep(i,1,n)s[i]='1';
    ll len=0;
    f[0][7]=1;
    rep(i,1,n){
        cll lim=s[i]-48;
        ref(j,0,8)if(cll c=f[i-1][j]){
            if(lim)ref(k,0,6)f[i][j&d[k]]=(f[i][j&d[k]]+c)%mod;
            else ref(k,0,6)if(!(d[k]&j))f[i][j]=(f[i][j]+c)%mod;
            //printf("%lld %lld %lld\n",i-1,j,f[i-1][j]);
        }
        len=(len*2+lim)%mod;
    }
    ll sum=0;
    ref(i,0,8)sum=(sum+f[n][i])%mod;
    len=(len+1)%mod;
    //writell(len),writell(sum,10);
    writell((len*len%mod*len+3*len*len-len-3*sum+4*mod)%mod,10);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}
/*
sum=card({(a,b,c)|(a^b)+(b^c)=(a^c)})
sum2=card({a,a,b})=n*(n-1)
sum3=card({a,a,a})=n
sum=2sum2+sum3+2{a!=b!=c!=a}
n^3-sum*3+sum2*3+sum3*2=n^3-sum*3+3*n*(n-1)+2*n=n^3+3n^2-n-3sum
*/
    //ll len=0;
    //rep(i,1,n)len=len*2+s[i]-48;
    //len++;
    //ll sum=0;
    /*,sumz=0;
    ref(i,0,len)ref(j,0,len)ref(k,0,len){
        cll a=i^j,b=j^k,c=i^k;
        if(a+b==c||b+c==a||a+c==b)sumz++;
    }*/
    //ref(i,0,len)ref(j,0,len)ref(k,0,len)if((i^j)+(j^k)==(i^k))sum++;//,i!=j&&j!=k&&k!=i&&printf("%lld %lld %lld\n",i,j,k);
    //writell(len),writell(sum),writell(len*len*len-3*len*(len-1)-len),writell(3*(sum-2*len*(len-1)-len),10);
    //writell(sumz);