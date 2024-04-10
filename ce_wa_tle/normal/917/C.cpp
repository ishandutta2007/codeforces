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
const ll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
struct matrix{
    static const ll n=70;
    ll v[n][n];
    const ll*operator[](ll b)const{
        return v[b];
    }
    ll*operator[](ll b){
        return v[b];
    }
    void merge(const matrix b){
        memset(this,0x3f,sizeof*this);
        ref(i,0,n)ref(k,0,n)ref(j,0,n)qm(v[i][j],b[i][k]+b[k][j]);
    }
}f[32];
ll id[256],st[77],ans[256],res[256],l[9],zr[8],c[8];
struct lim{
    ll p,w;
    void read(){
        p=readll(),w=readll();
    }
    operator ll()const{
        return p;
    }
}lim[N];
int main(){
    IO();
    const ll x=readll(),k=readll(),n=readll(),q=readll();
    ref(i,0,k)c[i]=readll();
    ll t=0;
    ref(i,0,1<<k)if(__builtin_popcount(i)==x)id[i]=t,st[t++]=i;
    memset(f[0].v,0x3f,sizeof f[0]);
    ref(i,0,1<<k)if(st[id[i]]==i){
        if(~i&1)f[0][id[i]][id[i>>1]]=0;
        else ref(j,0,k)if(!(i>>1&1<<j))f[0][id[i]][id[i>>1|1<<j]]=c[j];
    }
    //ref(i,0,t)ref(j,0,t)printf("f[%lld][%lld]=%lld\n",st[i],st[j],f[0][i][j]);
    rep(i,1,31)f[i].merge(f[i-1]);
    rep(i,1,q)lim[i].read();
    std::sort(lim+1,lim+q+1);
    ll i=1,p=1;
    memset(ans,0x3f,sizeof ans);
    ans[st[0]]=0;
    while(i!=n-x+1){
        //printf("%lld\n",i);
        memmove(l,l+1,64);
        while(p<=q&&lim[p].p-i-1<k)l[lim[p].p-i-1]=lim[p].w,p++;
        //ref(i,0,k)printf("%lld ",l[i]);puts("");
        if(memcmp(l,zr,sizeof zr)){
            memset(res,0x3f,sizeof res);
            ref(i,0,1<<k)if(st[id[i]]==i){
                if(~i&1)qm(res[i>>1],ans[i]);
                else ref(j,0,k)if(!(i>>1&1<<j))qm(res[i>>1|1<<j],ans[i]+c[j]+l[j]);
            }
            memcpy(ans,res,sizeof ans);
            //ref(d,0,t)printf("ans[%lld][%lld]=%lld\n",i+1,st[d],ans[st[d]]);
            i++;
        }
        else{
            const ll move=(p>q?n+1-x-i:lim[p].p-k-i)*1+0;
            //printf("%lld\n",i);
            rep(i,0,31)if(move>>i&1){
                const __typeof__(::f[0])&f=::f[i];
                memset(res,0x3f,sizeof res);
                ref(k,0,t)ref(j,0,t)qm(res[st[j]],ans[st[k]]+f[k][j]);
                memcpy(ans,res,sizeof ans);
            }
            i+=move;
        }
    }
    //ref(d,0,t)printf("ans[%lld][%lld]=%lld\n",i+1,st[d],ans[st[d]]);
    writell(ans[st[0]]);
    return 0;
}