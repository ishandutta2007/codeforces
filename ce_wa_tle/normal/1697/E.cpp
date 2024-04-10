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
    return i1==i2&&is==(i2=is+fread(is,1,iz,stdin))?-1:*i1++;
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
cll IO_res=IO(),T=1;
void init(){
}
ll diff(cll a,cll b){
    return a>b?a-b:b-a;
}
ll res[111][111];
aN f,s,e,x,y,l,c;
ll find(cll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
void calc(){
    cll n=readll();
    rep(i,1,n)x[i]=readll(),y[i]=readll(),f[i]=i,s[i]=1,e[i]=0;
    rep(i,1,n){
        ll min=mod;
        rep(j,1,n)if(j!=i){
            cll d=diff(x[i],x[j])+diff(y[i],y[j]);
            if(d<min)min=d,c[i]=0;
            if(d==min)c[i]++;
        }
        l[i]=min;
        rep(j,1,i-1)if((diff(x[i],x[j])+diff(y[i],y[j]))==min&&min==l[j]){
            cll x=find(i),y=find(j);
            if(x!=y)f[x]=y,c[y]=std::max(c[y],c[x]),s[y]+=s[x],e[y]+=e[x]+1;
            else e[x]++;
        }
    }
    //rep(i,1,n)rep(j,1,n)diff(x[i],x[j])+diff(y[i],y[j])<10&&pc(32),writell(diff(x[i],x[j])+diff(y[i],y[j]),j==n?10:32);
    res[0][0]=1;
    ll t=0;
    rep(i,1,n)if(f[i]==i){
        //printf("%lld %lld %lld\n",i,s[i],e[i]);
        rep(j,t,t+s[i]-1)rep(k,0,j)
        res[j+1][k+1]=(res[j+1][k+1]+res[j][k])%mod;
        if(s[i]*(s[i]-1)==e[i]*2&&s[i]==c[i]+1)rep(k,0,t)
        res[t+s[i]][k+1]=(res[t+s[i]][k+1]+res[t][k])%mod;
        t+=s[i];
    }
    ll sum=0,x=1;
    rep(i,0,n)sum=(sum+x*res[n][i])%mod,x=x*(n-i)%mod;
    writell(sum,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}