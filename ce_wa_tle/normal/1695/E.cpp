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
cll N=1e6+7,mod=1e9+7,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
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
#define $1(x...)x
#define $2(x...)x
cll IO_res=IO(),T=1;
aN G;
void init(){
    rep(i,0,1e6)G[i]=i&1?'R':'L';
}
aN next,to,head,st,res[2],A[2],B[2],vis,ves;
ll cnt=1;
void add(cll u,cll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
ll dfs(cll u,ll t){
    if(vis[u])return st[t+1]=u,1;
    cll s=t;
    st[++t]=u;
    vis[u]=1;
    rev(i,u,v)if(!ves[i>>1])ves[i>>1]=1,t+=dfs(v,t),st[++t]=u;
    return t-s;
}
void calc(){
    cll n=readll();
    rep(i,1,n){
        cll u=readll(),v=readll();
        add(u,v),add(v,u);
    }
    ll now=0;
    rep(i,1,2*n)if(!vis[i]){
        cll t=dfs(i,0)-1;
        //writell(t,10);
        if(!t)continue;
        if(t==2)return static_cast<void>(myputs("-1"));
        cll n=t/2;
        memcpy(res[0]+now+1,st+1,n<<3);
        rep(i,1,n)res[1][now+i]=st[t-i+1];
        if(n&1){
            memcpy(A[0]+now+1,G,(n-1)<<3);
            memcpy(A[1]+now+1,G,(n-1)<<3);
            memcpy(B[0]+now+2,G,(n-1)<<3);
            memcpy(B[1]+now+2,G,(n-1)<<3);
            A[0][now+n]=B[0][now+1]='U';
            A[1][now+n]=B[1][now+1]='D';
        }else{
            memcpy(A[0]+now+1,G,n<<3);
            memcpy(A[1]+now+1,G,n<<3);
            memcpy(B[0]+now+2,G,(n-2)<<3);
            memcpy(B[1]+now+2,G,(n-2)<<3);
            B[0][now+n]=B[0][now+1]='U';
            B[1][now+n]=B[1][now+1]='D';
        }
        now+=n;
    }
    writell(2),writell(now,10),pc(10);
    rep(i,0,1)rep(j,1,now)writell(res[i][j],j==now?10:32);
    pc(10);
    rep(i,0,1)rep(j,1,now)pc(A[i][j]),j==now&&pc(10);
    pc(10);
    rep(i,0,1)rep(j,1,now)pc(B[i][j]),j==now&&pc(10);
    pc(10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}