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
ll k;
aN next,to,head,w,l,s,a,ft,col;
ll cnt;
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
ll qmax(ll&a,ll b){
    return a<b?a=b,1:0;
}
ll qv(ll a,ll b=mod){
    return a>=b?a-b:a;
}
struct node{
    ll s,c;
    node operator+(const node&b)const{
        return(node){qv(s+b.s),qv(c+b.c)};
    }
    node operator-(const node&b)const{
        return(node){qv(mod+s-b.s),qv(mod+c-b.c)};
    }
    node&operator+=(const node&b){
        qm(s+=b.s),qm(c+=b.c);
        return*this;
    }
    node&operator-=(const node&b){
        qm(s+=mod-b.s),qm(c+=mod-b.c);
        return*this;
    }
    friend ll getans(const node&a,const node&b,ll add){
        qm(add=add%mod+mod);
        //a.print(),b.print(),writell(add-mod,'<'),writell((a.c*b.s+(a.s+a.c*add)%mod*b.c)%mod);
        return(a.c*b.s+(a.s+a.c*add)%mod*b.c)%mod;
    }
    void print()const{
        writell(s,','),writell(c,10);
    }
};
void add(ll u,ll v,ll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
node f_[2][N];
ll now=1;
struct ss{
    node*f[2],sumk[2];
    ll sum,u,len,clen,flag;
    void set(ll u_,ll l,ll r){
        //printf("%lld.set(%lld,%lld)\n",u_,l,r);
        u=u_,f[0]=f_[0]+now-l,f[1]=f_[1]+now-l,now+=r-l+2,len=r;
    }
    void set(ll u_,const ss&b){
        //printf("%lld.set(%lld)\n",u_,b.u);
        const ll del=col[b.u]^col[u=u_];
        f[0]=b.f[0]+del,f[1]=b.f[1]+del,len=b.len-del;
    }
    void get(const ss&b){
        //printf("%lld.get(%lld)\n",u,b.u);
        qm(sum+=b.sum);
        const ll del=col[b.u]^col[u];
        if(del)flag=1,std::swap(f[0],f[1]),std::swap(sumk[0],sumk[1]),f[1]++;
        //rep(i,0,len)rep(j,0,1)printf("sum[%lld][%lld][%lld]=%lld %lld\n",u,j^col[u],i,f[j][i].s,f[j][i].c);
        sumk[del]+=b.sumk[0];
    }
    void merge(const ss&b){
        //printf("%lld+=%lld\n",u,b.u);
        qm(sum+=b.sum);
        const ll del=col[b.u]^col[u];
        
        //rep(i,0,len)rep(j,0,b.len)if(i+j<=k)qm(sum+=getans(f[del][i],b.f[0][j],-a[u]-a[ft[u]]));
        //rep(i,0,len)rep(j,0,b.len)if(i+j+1<=k)qm(sum+=getans(f[del^1][i],b.f[0][j],-a[u]-a[ft[u]]));
        
        //node now={0,0};
        //rep(i,0,std::min(len,k))now+=f[del][i];
        
        node now=sumk[del];
        rep(i,0,std::min(b.len,k))qm(sum+=getans(now,b.f[0][i],-a[u]-a[ft[u]])),(k-i<=len)&&(now-=f[del][k-i],0);
        now=sumk[del^1];
        rep(i,0,std::min(b.len,k))(k-i<=len)&&(now-=f[del^1][k-i],0),qm(sum+=getans(now,b.f[0][i],-a[u]-a[ft[u]]));
        
        rep(i,0,b.len)f[del][i]+=b.f[0][i];
        sumk[del]+=b.sumk[0];
        if(del^flag)qmax(clen,b.len);
        //rep(i,0,len)rep(j,0,1)printf("sum[%lld][%lld][%lld]=%lld %lld\n",u,j^col[u],i,f[j][i].s,f[j][i].c);
    }
    void calc(){
        f[1]--;
        clen++;
        //sumk[1].print();
        //printf("%lld.ans=%lld\n",u,sum);
        sumk[0]+=(node){a[u],1},f[0][0]+=(node){a[u],1};
        qm(sum+=getans(sumk[0]+sumk[1],(node){a[u],1},-a[u]-a[ft[u]]));
        if(k<=len)sumk[1]-=f[1][k+1];
        if(flag)std::swap(f[0],f[1]),std::swap(sumk[0],sumk[1]);
        //printf("%lld\n",clen);
        rep(i,0,clen)f[0][i]+=f[1][i],f[1][i]=(node){0,0};
        sumk[0]+=sumk[1];
        //rep(i,0,len)rep(j,0,1)printf("sum[%lld][%lld][%lld]=%lld %lld\n",u,j^col[u],i,f[j][i].s,f[j][i].c);
        //rep(i,0,len)printf("sum[%lld][%lld]=%lld %lld\n",u,i,f[0][i].s,f[0][i].c);
    }
}f[N];
void dfs0(ll u,ll fa,ll c){
    col[u]=c,qm(a[u]+=a[ft[u]=fa]),l[u]=0,s[u]=0;
    rev(i,u,v)if(v^fa)dfs0(v,u,w[i]),qmax(l[u],l[v]+(col[v]!=col[u]))&&(s[u]=v);
    //printf("%lld %lld %lld %lld %lld\n",u,col[u],a[u],l[u],s[u]);
}
void dfs1(ll u,ll fa){
    //printf("%lld %lld\n",u,fa);
    //s[u]=0;
    if(s[ft[u]]!=u)f[u].set(u,0,l[u]);
    else f[u].set(u,f[fa]);
    if(s[u])dfs1(s[u],u),f[u].get(f[s[u]]);
    rev(i,u,v)if(v^fa&&v^s[u])dfs1(v,u),f[u].merge(f[v]);
    f[u].calc();
}
int main(){
    IO();
    ll n=readll(),k=::k=readll(),u,v,c;
    static_cast<void>(k);
    rep(i,1,n)a[i]=readll();
    rep(i,2,n)u=readll(),v=readll(),c=readll(),add(u,v,c),add(v,u,c);
    //exit(0);
    dfs0(1,0,0),dfs1(1,0);
    writell(f[1].sum);
    return 0;
}
/*
4 2
2 0 2 1 
2 1 1 
3 1 0 
4 1 1
*/
/*
9 1
1 0 0 0 0 0 0 0 0
2 1 1 
3 2 0 
4 1 1 
5 1 0 
6 2 1 
7 3 0 
8 6 0 
9 4 1 
*/