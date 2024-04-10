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
cll N=1e6+7,mod=1e18+7,iz=1<<21,oz=1<<22;
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
aN a,b,c,pre1,pre2,pre3,pre4;
aN L,R;
void calc(){
    cll n=readll();
    rep(i,1,n)a[i]=readchar()&1;
    rep(i,1,n)b[i]=readchar()&1;
    rep(i,1,n)c[i]=readchar()&1;
    rep(i,1,n)pre1[i]=pre1[i-1]+a[i]+b[i]+c[i];
    rep(i,1,n)pre2[i]=pre2[i-1]+(a[i]&&b[i])+(b[i]&&c[i]);
    rep(i,2,n)pre3[i]=pre3[i-1]+(a[i]&&a[i-1])+(b[i]&&b[i-1])+(c[i]&&c[i-1]);
    rep(i,2,n)pre4[i]=pre4[i-1]+(a[i]&&b[i]&&a[i-1]&&b[i-1])+(c[i]&&b[i]&&c[i-1]&&b[i-1]);
    ll t=0;
    rep(i,2,n)if(pre1[i-1]-pre1[i-2]==3&&!b[i]&&a[i]&&c[i]){
        ll j=i;
        while(!b[j]&&a[j]&&c[j])j++;
        //printf("%lld\n",i);
        if(pre1[j]-pre1[j-1]==3)L[++t]=i-1,R[t]=j;//,printf("i=%lld,j=%lld\n",i-1,j);
    }
    cll m=readll();
    rep(i,1,m){
        cll l=readll(),r=readll();
        writell(
            pre1[r]-pre1[l-1]
            -pre2[r]+pre2[l-1]
            -pre3[r]+pre3[l]
            +pre4[r]-pre4[l]
            +std::max(0ll,(std::upper_bound(R+1,R+t+1,r)-R-1)
            -(std::lower_bound(L+1,L+t+1,l)-L)+1ll)
        ,10);
    }
}
int main(){
    rep(i,1,T)calc();
    return 0;
}