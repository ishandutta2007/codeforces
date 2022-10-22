#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=2e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10+48;
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
ll f[101][5051];
void init(cll n=100,cll m=5050){
    f[1][1]=1;
    rep(i,1,n)rep(j,1,m)if(f[i][j]){
        rfor(ll k=4;i+k-1<=n&&j+k<=m;k++)f[i+k-1][j+k]=k<<1;
        rfor(ll k=2;i+k-1<=n&&j+k*(k+1)/2-1<=m;k++)f[i+k-1][j+k*(k+1)/2-1]=k<<1|1;
    }
}
void calc(){
    ll n=readll(),m=readll(),l=0,h=0;
    if(!f[n][m]){myputs("NO");return;}
    myputs("YES");
    rfor(ll k;k=f[n][m]>>1,k;)if(f[n][m]&1){
        if(h==0){
            rep(i,1,k-1)writell(l+i);
            l+=k-1,m-=k*(k+1)/2-1,n-=k-1,h=1;
        }else{
            per(i,k,2)writell(l+i+n-k);
            m-=k*(k+1)/2-1,n-=k-1,h=0;
        }
    }
    else{
        cll s=l+n-k;
        writell(l+2);
        rep(i,2,k/2)writell(i*2+s);
        writell(l+1);
        per(i,(k-1)/2,2)writell(i*2+1+s);
        l+=2,n-=k-1,m-=k;
    }
    writell(l+1,10);
}
int main(){
    IO();
    init();
    cll T=readll();
    rep(i,1,T)calc();
    return 0;
}
/*
type=0:
24681753
2461753
24153
type=1:
1234...n
*/