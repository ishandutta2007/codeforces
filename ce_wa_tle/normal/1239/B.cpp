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
const ll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<21;
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
int readchar(int l=33,int r=12){
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
char s[N];
aN h;
int qm(ll&a,ll b){
    return a<b?a=b,1:0;
}
int main(){
    IO();
    const ll n=readll();
    mygets(s+1),memcpy(s+n+1,s+1,n);
    ll m=0;
    rep(i,1,2*n)if(h[m]>(h[i]=h[i-1]+(s[i]==')'?-1:1)))m=i;
    if(h[n])return!myputs("0\n1 1");
    const ll d=h[m],l=m+1,r=m+n;
    ll s0=0,m1=0,m2=0,s1=0,s2=0,g0=l-1,g1=0,l1=0,r1=0,l2=1,r2=1;
    rep(i,l,r)switch(h[i]-d){
        case 0:s0++,qm(m1,s1)&&(l1=g0+1,r1=i),s1=0,g0=i;break;
        case 1:s1++,qm(m2,s2)&&(l2=g1+1,r2=i),s2=0,g1=i;break;
        case 2:s2++;
    }
    if(m1<m2+s0)writell(m2+s0,10),writell((l2-1)%n+1),writell((r2-1)%n+1);
    else writell(m1,10),writell((l1-1)%n+1),writell((r1-1)%n+1);
    return 0;
}