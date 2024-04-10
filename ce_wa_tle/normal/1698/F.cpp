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
cll IO_res=IO(),T=readll();
void init(){
}
aN a,b,l,r,lst;
ll t[501][501];
void calc(){
    cll n=readll();
    rep(i,1,n)a[i]=readll();
    rep(i,1,n)b[i]=readll();
    /*
    cll n=500;
    writell(n,10);
    rep(i,1,n)a[i]=b[i]=rand()%n+1;
    rep(i,1,n){
        ll l=0,r=0;
        do{
            l=rand()%n+1,r=rand()%n+1;
        }while(b[l]!=b[r]);
        rep(k,l,(l+r-1)/2)std::swap(b[k],b[l+r-k]);
    }
    rep(i,1,n)writell(a[i],i==n?10:32);
    rep(i,1,n)writell(b[i],i==n?10:32);
    */
    if(a[1]!=b[1])return static_cast<void>(myputs("NO"));
    rep(i,1,n)rep(j,1,n)t[i][j]=0;
    rep(i,1,n-1)t[a[i]][a[i+1]]++,t[a[i+1]][a[i]]++;
    rep(i,1,n-1)if(!t[b[i]][b[i+1]]--)return static_cast<void>(myputs("NO"));
    rep(i,1,n-1)if(!t[b[i+1]][b[i]]--)return static_cast<void>(myputs("NO"));
    myputs("YES");
    ll tans=0;
    rep(i,2,n)if(a[i]!=b[i]){
        rep(j,i,n-1){
            if(a[i-1]==a[j+1]&&b[i]==a[j]){
                l[++tans]=i-1,r[tans]=j+1;
                rep(k,i,(i+j-1)/2)std::swap(a[k],a[i+j-k]);
                break;
            }
            if(a[i-1]==a[j]&&b[i]==a[j+1]){
                //printf("??? %lld j=%lld\n",i,j);
                rep(k,i,j)lst[a[k]]=k;
                ll sl=0,sr=0;
                rep(k,j+1,n)if(lst[a[k]]){
                    sl=lst[a[k]],sr=k;
                    break;
                }
                rep(k,i,j)lst[a[k]]=0;
                l[++tans]=sl,r[tans]=sr;
                rep(k,sl+1,(sl+sr-1)/2)std::swap(a[k],a[sl+sr-k]);
                cll u=sl+sr-j-1;
                l[++tans]=i-1,r[tans]=sl+sr-j;
                rep(k,i,(i+u-1)/2)std::swap(a[k],a[i+u-k]);
                break;
            }
        }
    }
    writell(tans,10);
    rep(i,1,tans)writell(l[i]),writell(r[i],10);
    //rep(i,1,n)assert(a[i]==b[i]);//writell(a[i],i==n?10:32);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}