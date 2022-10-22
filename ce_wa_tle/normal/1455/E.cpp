#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x"in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=4e5+7,mod=1e9+7,iz=1<<21,oz=1<<22,inf=0x3f3f3f3f3f3f3f3f;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1!=o2)fout();
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
struct pt{
    ll x,y;
    void read(){
        x=readll(),y=readll();
    }
}p[4];
ll c[4];
ll m0(ll u){
    return u&-(u>=0);
}
void calc(){
    ll ans=mod*8;
    ref(i,0,4)p[c[i]=i].read();
    do{
        #define cl(s)const ll x##s=p[c[s]].x,y##s=p[c[s]].y
        #define mx std::max
        #define mn std::min
        cl(0);cl(1);cl(2);cl(3);
        //ref(i,0,4)printf("c[%lld]=%lld\n",i,c[i]);
        ans=mn(ans,llabs(x0-x1)+llabs(x2-x3)+llabs(y0-y3)+llabs(y1-y2)+
        2*m0(mx(mn(x2,x3)-mx(x0,x1),mn(y1,y2)-mx(y0,y3))-mn(mx(x2,x3)-mn(x0,x1),mx(y1,y2)-mn(y0,y3))));
    }while(std::next_permutation(c,c+4));
    writell(ans,10);
}
int main(){
    IO();
    ll T=readll();
    while(T--)calc();
    return 0;
}