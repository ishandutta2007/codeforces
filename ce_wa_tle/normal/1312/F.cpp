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
cll N=2.1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
ll f[6][6][6][37][3],len[6][6][6];
aN a,b;
ll mex(cll a,cll b,cll c=3){
    ll t[4]={};
    t[a]=1,t[b]=1,t[c]=1;
    rep(i,0,3)if(!t[i])return i;
    __builtin_unreachable();
}
ll getans(cll x,cll y,cll z,ll a,cll r=0){
    if(a<=0)return 0;
    if(a>36)a=36-len[x][y][z]+(a-36)%len[x][y][z];
    return f[x][y][z][a][r];
}
void init(){
    ll SG_[78][3]={},(*SG)[3]=SG_+5;
    rep(x,1,5)rep(y,1,5)rep(z,1,5){
        ll fflag=0;
        rep(i,1,72){
            SG[i][0]=mex(SG[i-x][0],SG[i-y][1],SG[i-z][2]);
            SG[i][1]=mex(SG[i-x][0],SG[i-z][2]);
            SG[i][2]=mex(SG[i-x][0],SG[i-y][1]);
            if(!fflag)per(j,i-1,0){
                ll flag=1;
                rep(a,0,5)ref(b,0,3)if(SG[i-a][b]!=SG[j-a][b])flag=0;
                if(flag==1){fflag=i-j;/*printf("x=%lld y=%lld z=%lld i=%lld j=%lld\n",x,y,z,i,i-j);*/break;}
            }
        }
        memcpy(f[x][y][z],SG,sizeof f[x][y][z]),len[x][y][z]=fflag;
        //rep(i,-5,72)ref(j,0,3)assert(SG[i][j]==getans(x,y,z,i,j));
    }
}
void calc(){
    cll n=readll(),x=readll(),y=readll(),z=readll();
    ll sum=0,ans=0;
    rep(i,1,n)sum^=b[i]=getans(x,y,z,a[i]=readll());
    if(!sum)return writell(0,10);
    rep(i,1,n){
        //printf("%lld %lld\n",sum,b[i]^getans(x,y,z,a[i]-y,1));
        ans+=sum==(b[i]^getans(x,y,z,a[i]-x,0));
        ans+=sum==(b[i]^getans(x,y,z,a[i]-y,1));
        ans+=sum==(b[i]^getans(x,y,z,a[i]-z,2));
    }
    writell(ans,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}
/*
1
3 1 5 3
9 8 7
*/