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
std::bitset<2001>f[65536];
aN a,d;
struct node{
    ll d,a;
    operator ll()const{
        return d;
    }
};
std::priority_queue<node>q;
int main(){
    IO();
    const ll n=readll(),k=readll();
    ref(i,0,n)a[i]=readll();
    f[0].set(0);
    ref(i,1,1<<n){
        ref(j,0,n)if(i>>j&1)f[i]|=f[i^1<<j]<<a[j];
        per(j,2000,1)if(f[i][j*k])f[i][j]=1;
    }
    if(f[(1<<n)-1][1]==0)return!myputs("NO");
    myputs("YES");
    ll S=(1<<n)-1,x=1;
    while(S)rep(t,0,100){
        int p=0;
        ref(j,0,n)if(S>>j&1)if(x>=a[j]&&f[S^1<<j][x-a[j]]){
            ref(j,0,n)if(S>>j&1)d[j]+=t;
            S^=1<<j,x-=a[j],p=1;
            break;
        }
        if(p)break;
        x*=k;
    }
    ref(i,0,n)q.push((node){d[i],a[i]});
    ref(i,1,n){
        const ll u=q.top().a;q.pop();
        ll a=u+q.top().a,d=q.top().d;q.pop();
        writell(u),writell(a-u,10);
        while(a%k==0)a/=k,d--;
        q.push((node){d,a});
    }
    return 0;
}