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
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*const o2=os+oz;
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
aN a,ans;
static inline void qmn(ll&a,cll b){
    a>b&&(a=b);
}
static inline ll mn(cll a,cll b){
    return a<b?a:b;
}
int cmp(ll x,ll y){
    return a[x]<a[y];
}
#define abs aaa
static inline int abs(cll u){
    return u<0?-u:u;
}
struct sgt{
    typedef cll*const cpcll;
    aN f[23],min;
    ll n;
    void set(ll n_){
        n=n_,build(1,1,n,1),memset(min,0x3f,sizeof min);
    }
    void build(cll u,cll l,cll r,cll c){
        if(l==r){
            f[c][l]=l;
            return;
        }
        cll mid=(l+r)>>1;
        build(u<<1,l,mid,c+1),build(u<<1|1,mid+1,r,c+1);
        cll*a=f[c+1]+l,*b=f[c+1]+mid+1;
        cpcll ea=b,eb=f[c+1]+r+1;
        ll*d=f[c]+l;while(a<ea&&b<eb)*d++=*(cmp(*a,*b)?a:b)++;
        memcpy(d,a,(ea-a)<<3),memcpy(d,b,(eb-b)<<3);
        /*printf("%lld %lld %lld %lld:\n",u,l,r,c);
        rep(i,l,r)printf("%lld ",f[c][i]);
        puts("");*/
    }
    ll query(cll q)const{
        struct{const sgt&now;cll q;ll min;
            void query(cll u,cll l,cll r){
                if(q<=l)return qmn(min,now.min[u]);
                cll mid=(l+r)>>1;
                if(q<=mid)query(u<<1,l,mid);
                query(u<<1|1,mid+1,r);
            }
        }res={*this,q,mod};
        return res.query(1,1,n),res.min;
    }
    void update(cll q,cll c=0){
        (struct{sgt&now;cll q,val;ll min;
            void update(cll u,cll l,cll r,cll c,ll x){
                if(l==r)return qmn(now.min[u],abs(a[now.f[c][l]]-val)),qmn(min,now.min[u]);
                if(r<=q&&(x<l||x>r)){
                    cpcll tl=now.f[c]+l,tr=now.f[c]+r+1,i=std::lower_bound(tl,tr,q+1,cmp);
                    //printf("%lld %lld %lld %lld %lld %zd %lld %d\n",u,l,r,c,val,i-tl,a[*(i-1)]-val,i==tr);
                    if(min<=abs(a[x=(i==tr||(i!=tl&&a[*i]+a[*(i-1)]>=2*val))?*(i-1):*i]-val))
                        return qmn(min,now.min[u]);
                    //printf("x=%lld %lld %lld\n",x,a[x]-val,min);
                }
                cll mid=(l+r)>>1;
                if(q>mid)update(u<<1|1,mid+1,r,c+1,x);
                if(x<=mid)update(u<<1,l,mid,c+1,x);
                now.min[u]=mn(now.min[u<<1],now.min[u<<1|1]);
                //printf("min=%lld %lld\n",min,now.min[u]);
            }
        }){*this,q-1,c?:a[q],mod}.update(1,1,n,1,0);
    }
}t;
struct que{
    ll l,r,id;
    void read(cll i){
        l=readll(),r=readll(),id=i;
    }
    operator ll()const{
        return r;
    }
    void calc()const{
        ans[id]=t.query(l);
    }
}q[N];
int main(){
    IO();
    cll n=readll();
    rep(i,1,n)a[i]=readll();
    cll m=readll();
    rep(i,1,m)q[i].read(i);
    std::sort(q+1,q+m+1);
    t.set(n);
    ll p=1;
    rep(i,1,n){
        if(i!=1)t.update(i);
        while(p<=m&&q[p].r<=i)q[p++].calc();
    }
    rep(i,1,m)writell(ans[i],10);
    return 0;
}
/*struct bit{
    aN f;
    ll n;
    void set(ll n_){
        memset(f,0x3f,((n=n_)+1)<<3);
    }
    void update(ll u,ll c){
        for(;u;u&=~-u)qmin(f[u],c);
    }
    ll query(ll u){
        ll res=0;
        for(;u<n;u+=u&-u)qmin(res,f[u]);
        return res;
    }
}*/