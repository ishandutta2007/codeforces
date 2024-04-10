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
const ll N=4e5+7,mod=998244353,iz=1<<21,oz=1<<22;
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
ll d[18],g[18],q[18],a[18];
ll f[19][1<<18],l[19][1<<18];
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
int main(){
    IO();
    ll n=readll(),m=readll(),u,v,w;
    rep(i,1,m)u=readll()-1,v=readll()-1,w=readll(),a[u]+=w,a[v]-=w,g[u]|=1<<v,d[v]|=1<<u;
    ll h=0,t=-1;
    ref(i,0,n)if(!d[i])d[q[++t]=i]=-1;
    while(h<=t){
        const ll u=q[h++];
        ref(i,0,n)if(g[u]>>i&1&&!(d[i]&=~(1<<u)))d[q[++t]=i]=-1;
    }
    //ref(i,0,n)printf("%lld\n",q[i]);
    memset(f[0],0x3f,sizeof f[0]),f[0][0]=0,memset(l,0,sizeof l);
    rep(i,1,n){
        memcpy(f[i],f[i-1],sizeof f[i]);
        ref(j,0,n)ref(S,0,1<<n)if(~S>>q[j]&1&&!(g[q[j]]&~S))
        if(qm(f[i][S|1<<q[j]],f[i][S]+a[q[j]]*i))l[i][S|1<<q[j]]=l[i][S]|1<<q[j];
    }
    ll S=(1<<n)-1;
    //printf("%lld\n",f[n][S]);
    per(i,n,1){
        const ll s=l[i][S];
        ref(j,0,n)if(s>>j&1)d[j]=i;
        S^=s;
    }
    ref(i,0,n)writell(d[i]);
    return 0;
}
/*
18 13
6 16 62481
17 13 92131
4 1 4944
14 5 75492
3 17 88091
15 5 40590
9 12 55008
6 7 75413
17 14 55677
6 10 73493
17 11 27405
2 7 75361
1 8 43576
*/