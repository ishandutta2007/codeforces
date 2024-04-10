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
cll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is+iz,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i2++;
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
cll IO_res=IO(/),T=readll();
ll inv(ll a,ll b=mod){
    ll x=1,y=0;
    cll m=b;
    while(b){
        cll t=a/b,lb=b,ly=y;
        b=a-t*b,a=lb,y=x-t*y,x=ly;
    }
    return(x+m)%m;
}
ll pow(ll a,cll b,cll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
aN a,l,r,q,f,d;
std::vector<ll>se[N];
ll find(cll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
void calc(){
    cll n=readll(),m=readll();
    rep(i,0,n+2)f[i]=i,se[i].clear();
    ll s=0,t=0;
    rep(i,1,n)a[i]=s+=readll();
    s=0;
    rep(i,1,n)a[i]+=s-=readll();
    rep(i,1,m){
        cll l=::l[i]=readll(),r=::r[i]=readll();
        cll s1=a[l-1]==0,s2=a[r]==0;
        if(s1&&s2)q[++t]=i,d[i]=0;
        else if(s1)se[r].push_back((ll)i),d[i]=1;
        else if(s2)se[l-1].push_back((ll)i),d[i]=1;
        else se[l-1].push_back((ll)i),se[r].push_back((ll)i),d[i]=2;
    }
    rep(h,1,t){
        cll l=::l[q[h]],r=::r[q[h]];
        rfor(ll i=find(l);i<=r;i=f[i]=find(i+1)){
            //printf("%lld\n",i);
            if(a[i]){
                cll up=se[i].size();
                a[i]=0;
                ref(j,0,up)if(!--d[se[i][j]])q[++t]=se[i][j];
            }
        }
    }
    ll flag=1;
    rep(i,1,n)if(a[i])flag=0;
    myputs(flag?"YES":"NO");
}
int main(){
    rep(i,1,T)calc(); 
    return 0;
}