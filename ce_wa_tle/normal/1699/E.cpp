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
cll N=5.2e6+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),T=readll();
void init(){
}
aN t,s;
void calc(){
    cll n=readll(),m=readll();
    static_cast<void>(m);
    ll z=0,x,f=0,r=1,ans=mod,y=mod;
    rep(i,1,n)x=readll(),!t[x]&&(++t[x],++f),z=std::max(z,x),y=std::min(y,x);
    //rep(i,1,n)x=5e6,!t[x]&&(++t[x],++f),z=std::max(z,x),y=std::min(y,x);
    s[1]=1,t[1]&&--f,y==1&&++y;
    rep(l,2,y){
        while(r<z&&f)rfor(ll i=++r,j=1;i<=z;i+=r,j++)if(s[j])t[i]&&!s[i]&&--f,s[i]+=s[j];
        if(t[1]){
            ans=r-1;
            break;
        }
        ans=std::min(ans,r-l);
        if(l==y)break;
        rfor(ll i=z/l*l,j=z/l;i;i-=l,j--)if(s[j])t[i]&&s[i]==s[j]&&++f,s[i]-=s[j];
    }
    memset(s,0,(z+1)<<3);
    memset(t,0,(z+1)<<3);
    writell(ans,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}