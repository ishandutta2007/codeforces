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
cll N=1e6+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
aN p,m,s,e[7];
std::multiset<ll>se[7];
ll d[7];
void calc(){
    cll n=readll(),q=readll();
    ll t=0,ls=-1;
    rfor(ll x=n;x!=1;x/=m[x])if(n/m[x]!=ls)ls=d[t++]=n/m[x];
    ref(i,0,t)se[i].clear(),memset(e[i],0,d[i]<<3);//,printf("d=%lld\n",d[i]);
    rep(i,1,n){
        cll x=s[i]=readll();
        ref(j,0,t)e[j][i%d[j]]+=x;
    }
    ref(i,0,t)ref(j,0,d[i])se[i].insert(e[i][j]);
    ll max=0;
    ref(j,0,t)max=std::max(max,d[j]**--se[j].end());
    writell(max,10);
    rep(i,1,q){
        cll x=readll(),y=readll(),del=y-s[x];
        s[x]=y;
        ll max=0;
        ref(j,0,t)se[j].erase(se[j].find(e[j][x%d[j]])),se[j].insert(e[j][x%d[j]]+=del),max=std::max(max,d[j]**--se[j].end());
        writell(max,10);
    }
}
void init(){
    cll n=1e6;
    ll*t=p,k;
    rep(i,2,n){
        if(!p[i])*t++=m[i]=i;
        rfor(ll*j=p;j!=t&&(k=i**j)<=n;j++){
            p[k]=1,m[k]=*j;
            if(i%*j==0)break;
        }
    }
}       
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}