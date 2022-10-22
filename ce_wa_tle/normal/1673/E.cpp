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
aN a,ans;
ll C(cll n,cll m){
    if(n==0&&m<=0)return 1;
    //printf("check %lld %lld\n",n,m);
    return m<0||m>n?0:!((n-m)&(m-1));
}
void check(cll u,ll l,ll r){
    //printf("%lld %lld %lld\n",u,l,r);
    cll kd=2-(l==1)-(r==n);
    if(C(n-1-(r-l)-kd,k-kd))ans[u]^=1;//,printf("u=%lld\n",u);
}
void calc(){
    rep(i,1,n)a[i]=readll();
    rep(i,1,n){
        ll now=a[i];
        check(now,i,i);
        rep(len,1,21){
            if(i+len>n||a[i+len]>20)break;
            now<<=a[i+len];
            if(now>(1<<20))break;
            check(now,i,i+len);
        }
    }
    ll now=(1<<20)-1;
    while(now&&!ans[now])now--;
    while(now)pc(ans[now--]^48);
    pc(48);
}
int main(){
    //rep(i,0,10){
    //rep(j,-10,i)pc(C(i,j)^48);pc(10);}
    rep(i,1,T)calc();
    return 0;
}