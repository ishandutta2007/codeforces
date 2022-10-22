#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef int ll __attribute__((mode(TI)));
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
ll n;
ll gcd(ll a,ll b){
    while(b)std::swap(a%=b,b);
    if(a<0)a=-a;
    return a;
}
struct pt{
    ll x,y;
    void read(){
        x=readll()*n,y=readll()*n;
    }
    pt operator~()const{
        return(pt){y,-x};
    }
    pt operator-()const{
        return(pt){-x,-y};
    }
    pt operator+()const{
        const ll t=(x==0?y:x)<0?-1:1;
        const ll c=t*gcd(x,y);
        return(pt){x/c,y/c};
    }
    pt operator+(const pt&m)const{
        return(pt){x+m.x,y+m.y};
    }
    pt operator-(const pt&m)const{
        return(pt){x-m.x,y-m.y};
    }
    ll operator*(const pt&m)const{
        return x*m.x+y*m.y;
    }
    operator ll()const{
        return x*mod*mod+y;
    }
    void print(int c=10)const{
        pc('('),writell(x,','),writell(y,')'),c&&pc(c);
    }
}p[N];
aN f,ans;
ll t;
void check(pt a){
    a=+~a;
    //a.print();
    rep(i,1,n)f[i]=p[i]*a;
    std::sort(f+1,f+n+1);
    //rep(i,1,n)writell(f[i]);
    rep(i,2,(n+1)/2)if(f[i]-f[i-1]!=f[n-i+2]-f[n-i+1])return;
    //printf("???");
    ans[++t]=a;
}
int main(){
    IO();
    const ll n=::n=readll();
    pt w={0,0};
    rep(i,1,n)p[i].read(),w=w+p[i];
    std::sort(p+1,p+n+1);
    ll flag=0;
    w.x*=2,w.y*=2;
    w.x/=n,w.y/=n;
    //rep(i,1,n)p[i].print();
    //w.print();
    const ll g=w;
    rep(i,1,(n+1)/2)if(p[i]+p[n-i+1]!=g){
        if(g-p[i]>p[n-i+1])flag=i;
        else flag=n-i+1;
        break;
    }
    //writell(flag);
    if(!flag)return!myputs("-1");
    rep(i,1,n)check((p[flag]+p[i])-w);
    if(!t)return!myputs("0");
    std::sort(ans+1,ans+t+1);
    writell(std::unique(ans+1,ans+t+1)-ans-1);
    return 0;
}
/*
4
0 0
0 1
1 0
2 2

4
0 0
0 1
1 1
2 0
*/