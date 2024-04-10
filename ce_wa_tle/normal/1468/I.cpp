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
struct pt{
    ll x,y;
    void read(){
        x=readll(),y=readll();
    }
    ll operator*(const pt&b)const{
        return x*b.y-y*b.x;
    }
    void print()const{
        writell(x),writell(y,10);
    }
    pt operator-()const{
        return(pt){-x,-y};
    }
    ll y_d(ll x_d)const{
        static ll py=1e12;
        return x==0?x_d<x?-py:x_d>x?py:0:(x_d*y+py*x+x-1)/x-py;
    }
}p[N],s1,s2;
int main(){
    IO();
    ll n=readll(),t=0;
    s1.read(),s2.read();
    if(s1.x<0)s1=-s1;
    if(s2.x<0)s2=-s2;
    if(s1*s2==0)return!myputs("NO");
    if(s1*s2>0)std::swap(s1,s2);
    //s1.print(),s2.print();
    rep(i,0,2e6){
        ll l=std::max(s2.y_d(i),s1.y_d(i-s2.x)+s2.y),r=std::min(s1.y_d(i),s2.y_d(i-s1.x)+s1.y)-1;
        rep(j,l,r)if(p[++t]=(pt){i,j},t>n)break;
    }
    if(t!=n)return!myputs("NO");
    myputs("YES");
    rep(i,1,n)p[i].print();
    return 0;
}