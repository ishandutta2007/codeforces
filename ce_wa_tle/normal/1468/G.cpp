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
typedef long double ld;
struct pt{
    ll x,y;
    void read(){
        x=readll(),y=readll();
    }
    ll operator*(const pt&b)const{
        return x*b.y-y*b.x;
    }
    pt operator-(const pt&b)const{
        return(pt){x-b.x,y-b.y};
    }
    ld dis()const{
        return sqrtl(x*x+y*y);
    }
    void print()const{
        writell(x),writell(y,10);
    }
}p[N],H;
ld get(const pt&p1,const pt&p2,const pt&p3,const pt&p4){
    pt s1=p2-p1,s2=p4-p3;
    if((p1-p3)*s2<0)return 0;
    if(s1*s2==0)return s2*(p2-p3)==0?s1.dis():0;
    //printf("%lld %.7Lf %lld\n",(p1-p3)*s2,s1.dis(),(s1*s2));
    return std::max(0.0L,(p1-p3)*s2*-s1.dis()/(s1*s2));
}
int main(){
    IO();
    ll n=readll(),h=readll();
    rep(i,1,n)p[i].read();
    H=(pt){p[n].x,p[n].y+h};
    ll now=n;
    ld ans=0;
    per(i,n-1,1){
        ld res=get(p[i],p[i+1],H,p[now]);
        ans+=res;
        if((p[i]-H)*(p[now]-H)>0)now=i;
        //printf("%lld %.2Lf\n",now,res);
    }
    printf("%.10Lf\n",ans);
    return 0;
}