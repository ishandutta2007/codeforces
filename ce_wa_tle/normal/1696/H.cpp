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
cll N=1e6+7,inf=1e18L+7,mod=1e9+7,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
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
#define $1(x...)x
ll cmp(cll a,cll b){
    return(a+b)*(a-b)>0;
}
ll a[666],ap[666],an[666],wp[666],wn[666],f[666],g[2][666],z[666][2],p2[666];
void init(){
    cll n=600;
    ll x=1;
    rep(i,0,n)p2[i]=x,x=x*i%mod;
}
struct bit{
    ll f[666];
    ll n;
    void set(cll n_){
        memset(f,0,((n=n_)+1)<<3);
    }
    void update(ll u,cll c){
        for(;u<=n;u+=u&-u)f[u]=(f[u]+c)%mod;
    }
    ll query(ll u)const{
        ll res=0;
        for(;u;u&=~-u)res=(res+f[u])%mod;
        return res;
    }
}dt1,dt2;
struct node{
    ll x,y,z,w;
    int operator<(const node&m)const{
        cll a=x==inf||m.y==inf?inf:x*m.y,b=y==inf||m.x==inf?inf:y*m.x;
        return a>b;
    }
    ll calc1()const{
        //printf("n-z=%lld %lld\n",dt2.n-z+1,z-1);
        dt2.update(dt2.n-z+1,x==inf?w:x*w%mod);
        return dt1.query(z-1)*(y==inf?w:y*w%mod)%mod;
    }
    ll calc2(){
        //printf("z=%lld %lld\n",z,dt2.n-z);
        dt1.update(z,x==inf?w:x*w%mod);
        return dt2.query(dt2.n-z)*(y==inf?w:y*w%mod)%mod;
    }
}l[666*666],r[666*666];
void calc(){
    cll n=readll(),m=readll();
    ll sum=0,x=1,tp=0,tn=0;
    rep(i,0,n)p2[i]=x,x=x*2%mod;
    rep(i,1,n)a[i]=readll();
    dt1.set(n+1),dt2.set(n+1);
    std::sort(a+1,a+n+1,cmp);
    memset(f,0,(m+1)<<3),f[0]=1;
    rep(i,1,n){
        a[i]<0?wn[++tn]=i:wp[++tp]=i;
        cll up=i>m?f[m]=f[m]*2%mod,m:i+0;
        per(j,up-1,0)f[j+1]=(f[j+1]+f[j]*a[i])%mod;
    }
    sum=f[m];
   // writell(sum,10);
    rep(i,1,tn)an[i]=a[wn[i]];
    rep(i,1,tp)ap[i]=a[wp[i]];
    an[0]=-inf,ap[0]=inf,an[tn+1]=ap[tp+1]=0,wn[tn+1]=wp[tp+1]=n+1;
    if(m&1){
        memset(f,0,(m+1)<<3),f[0]=1;
        per(i,tn,1){
            cll up=tn-i+1>m?f[m]=f[m]*2%mod,m:tn-i+1;
            per(j,up-1,0)f[j+1]=(f[j+1]+f[j]*an[i])%mod;
        }
        sum=(sum+f[m])%mod;
        //printf("f[m]=%lld\n",(f[m]+mod)%mod);
    }
    //writell(sum,10);
    memset(g[0],0,(m+1)<<3),memset(g[1],0,(m+1)<<3),g[0][0]=1;
    ll tl=0,tr=0,z=0;
    rep(i,1,tn){
        memcpy(f,g[0],(m+1)<<3);
        if(m&1)sum=(sum-f[m-1]*an[i]%mod*p2[tn-i])%mod;
        while(z<tp&&wp[z+1]<wn[i])z++;
        if(f[m-1])l[++tl]=(node){-an[i],ap[0],wn[i],f[m-1]},sum=(sum+-an[i]*f[m-1]%mod*(p2[tn-i+(tp-z)]-p2[tn-i]))%mod;
        rep(j,1,tp){
            //fprintf(stderr,"j=%lld %lld",j,ap[j]);
            if(m>=2&&f[m-2])l[++tl]=(node){-an[i],ap[j],std::max(wn[i],wp[j]),f[m-2]},sum=(sum+ap[j]*-an[i]%mod*f[m-2]%mod*(p2[n-std::max(wn[i],wp[j])]-1))%mod;
            if(j)per(k,m-1,0)f[k+1]=(f[k+1]+f[k]*ap[j])%mod;
        }
        cll up=i>m?m:i+0;
        per(j,up-1,0)g[0][j+1]=(g[0][j+1]+g[1][j]*an[i])%mod,g[1][j+1]=(g[1][j+1]+g[0][j]*an[i])%mod;
    }
    //writell(sum,10);
    std::sort(l+1,l+tl+1);
    rep(i,1,tn+1)rep(j,1,tp+1)if(ap[j]||an[i])r[++tr]=(node){ap[j],-an[i],std::min(wp[j],wn[i]),p2[tn-i+tp-j+(i>tn)+(j>tp)]};
    std::sort(r+1,r+tr+1);
    /*rep(i,1,n)writell(a[i],i==n?10:32);
    rep(i,1,tl)writell(l[i].x),writell(l[i].y),writell(l[i].z),writell(l[i].w,10);
    pc(10);
    rep(i,1,tr)writell(r[i].x),writell(r[i].y),writell(r[i].z),writell(r[i].w,10);
    pc(10);*/
    //exit(0);
    ll j=1;
    rep(i,1,tl+1){
        while(j<=tr&&(i==tl+1||r[j]<l[i]))sum=(sum+r[j++].calc1())%mod;
        if(i!=tl+1)sum=(sum+l[i].calc2())%mod;
    }
    writell((sum+mod)%mod,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}
/*
10
3
-1 0 -3 0 -2 0 -9 0 -13 0
*/