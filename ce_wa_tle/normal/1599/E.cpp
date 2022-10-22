#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=5e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10+48;
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
static inline ll qm(cll a,cll b=mod){
    return a>=b?a-b:a;
}
struct matrix{
    ll a,b;
    friend matrix operator+(const matrix&a,const matrix&b){
        return(matrix){qm(a.a+b.a),qm(a.b+b.b)};
    }
    friend matrix operator*(const matrix&a,const matrix&b){
        return(matrix){(a.a*b.a+a.b*b.b)%mod,(a.b*b.a+(a.a+mod-a.b)*b.b)%mod};
    }
}f_[2000006],*F=f_+1000003,fe6_[200006],*Fe6=fe6_+100003;
const matrix I={1,1},epsilon={1,0},mu={0,1};
struct node;
template<ll i>struct ss{
    ll mx,cmx,mn,cmn,tag[3];
    //mx,mn,re
    // 0, 1, 2
    matrix(&sum)[3][3];
    ss(matrix(&s)[3][3]):sum(s){}
    template<ll>void mul(cll);
    ll level(ll x)const{
        return x==mx?0:x==mn?1:2;
    }
    void merge(const ss&l,const ss&r){
        //assert(!tag[0]),assert(!tag[1]),assert(!tag[2]);
        if(l.mx>r.mx)mx=l.mx,cmx=r.mx;
        if(l.mx<r.mx)mx=r.mx,cmx=l.mx;
        if(l.mx==r.mx)mx=l.mx,cmx=-mod;
        cmx=std::max(cmx,std::max(l.cmx,r.cmx));
        if(l.mn<r.mn)mn=l.mn,cmn=r.mn;
        if(l.mn>r.mn)mn=r.mn,cmn=l.mn;
        if(l.mn==r.mn)mn=l.mn,cmn=mod;
        cmn=std::min(cmn,std::min(l.cmn,r.cmn));
    }
    void calc(){
        if(mx==mn){
            //if(i==2)printf("== %lld\n",tag[0]);
            if(tag[0])mul<0>(tag[0]),mx+=tag[0],mn=mx,tag[0]=0;
            tag[1]=tag[2]=0;
            return;
        }
        if(cmx==mn){
            //printf("%lld %lld %lld %lld ===%lld,%lld==>",mn,cmn,cmx,mx,tag[0],tag[1]);
            if(tag[0])mul<0>(tag[0]),mx+=tag[0],cmn=mx,tag[0]=0;
            if(tag[1])mul<1>(tag[1]),mn+=tag[1],cmx=mn,tag[1]=0;
            //printf("%lld %lld %lld %lld\n",mn,cmn,cmx,mx);
            tag[2]=0;
            return;
        }
        if(tag[0])mul<0>(tag[0]),mx+=tag[0],tag[0]=0;
        if(tag[1])mul<1>(tag[1]),mn+=tag[1],tag[1]=0;
        if(tag[2])mul<2>(tag[2]),cmx+=tag[2],cmn+=tag[2],tag[2]=0;
    }
    void gettag(const ss&f){
        tag[0]+=f.tag[f.level(mx+tag[0])];
        tag[1]+=f.tag[f.level(mn+tag[1])];
        tag[2]+=f.tag[f.level(cmx+tag[2])];
    }
    void set(cll a){
        mx=mn=a,cmx=-mod,cmn=mod;
    }
    template<ll type>int can_tag(ll x){
        //assert(!tag[0]),assert(!tag[1]),assert(!tag[2]);
        if(mx==mn&&type==1)return tag[0]=std::max(mx,x)-mx,1;
        switch(type){
            case 0:
            if(x>=mx)return 1;
            if(x>cmx)return tag[0]=x-mx,1;
            return 0;
            case 1:
            if(x<=mn)return 1;
            if(x<cmn)return tag[1]=x-mn,1;
            return 0;
            case 2:
            tag[0]+=x,tag[1]+=x,tag[2]+=x;
            return 1;
        }
    }
};
template<>template<ll i>void ss<1>::mul(cll v){
    matrix m=Fe6[v/1000000]*F[v%1000000];
    sum[i][0]=sum[i][0]*m,sum[i][1]=sum[i][1]*m,sum[i][2]=sum[i][2]*m;
}
template<>template<ll i>void ss<2>::mul(cll v){
    matrix m=Fe6[v/1000000]*F[v%1000000];
    sum[0][i]=sum[0][i]*m,sum[1][i]=sum[1][i]*m,sum[2][i]=sum[2][i]*m;
}
struct node{
    matrix sum[3][3];
    ss<1>v1;
    ss<2>v2;
    node():v1(sum),v2(sum){}
    void merge_addsum(const node&l){
        typedef cll pl[];
        pl px={v1.level(l.v1.mx),v1.level(l.v1.mn),v1.level(l.v1.cmx)},
           py={v2.level(l.v2.mx),v2.level(l.v2.mn),v2.level(l.v2.cmx)};
        ref(i,0,3)ref(j,0,3)sum[px[i]][py[j]]=sum[px[i]][py[j]]+l.sum[i][j];
    }
    void merge(const node&l,const node&r){
        v1.merge(l.v1,r.v1),v2.merge(l.v2,r.v2);
        memset(sum,0,sizeof sum),merge_addsum(l),merge_addsum(r);
    }
    void calc(){
        v1.calc(),v2.calc();
    }
    void gettag(const node&f){
        v1.gettag(f.v1),v2.gettag(f.v2);
    }
    template<ll i>ll getans()const{
        return sum[i][0].b+sum[i][1].b+sum[i][2].b;
    }
    ll getans()const{
        return getans<0>()+getans<1>()+getans<2>();
    }
    void set(cll a1,cll a2){
        v1.set(a1),v2.set(a2),sum[0][0]=F[a1]*F[a2];
    }
    template<ll i>int can_tag(ll x){
        switch(i&1){
            case 0:return v1.can_tag<i/2>(x);
            case 1:return v2.can_tag<i/2>(x);
        }
    }
};
aN a1,a2;
struct sgt{
    node v[N];
    ll n,ql,qr,x;
    void pushup(cll u,cll l,cll r){
        if(l!=r)v[u].merge(v[u<<1],v[u<<1|1]);
    }
    void pushdown(cll u,cll l,cll r){
        if(l!=r)v[u<<1].gettag(v[u]),v[u<<1|1].gettag(v[u]);
        v[u].calc();
    }
    void build(cll u,cll l,cll r){
        if(l==r)return v[u].set(a1[l],a2[l]);
        cll mid=(l+r)>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r),pushup(u,l,r);
    }
    void set(ll n_){
        n=n_,build(1,1,n);
    }
    template<ll t>void update_(cll u,cll l,cll r){
        pushdown(u,l,r);
        //printf("%lld %lld %lld\n",u,l,r);
        if(ql<=l&&r<=qr&&v[u].can_tag<t>(x))return pushdown(u,l,r);
        cll mid=(l+r)>>1;
        if(ql<=mid)update_<t>(u<<1,l,mid);else pushdown(u<<1,l,mid);
        if(qr>mid)update_<t>(u<<1|1,mid+1,r);else pushdown(u<<1|1,mid+1,r);
        pushup(u,l,r);
        //printf("[%lld,%lld]:(%lld,%lld,%lld,%lld)\n",l,r,v[u].v1.mn,v[u].v1.cmn,v[u].v1.cmx,v[u].v1.mx);
    }
    template<ll t>void update(cll l,cll r,cll s){
        //printf("update(type=%lld,[%lld,%lld],%lld)\n",t,l,r,s);
        ql=l,qr=r,x=s;
        update_<t>(1,1,n);
    }
    ll query(cll u,cll l,cll r){
        //printf("%lld %lld %lld\n",u,l,r);
        pushdown(u,l,r);
        if(ql<=l&&r<=qr)return v[u].getans();
        cll mid=(l+r)>>1;
        ll res=0;
        if(ql<=mid)res+=query(u<<1,l,mid);
        if(qr>mid)res+=query(u<<1|1,mid+1,r);
        return res;
    }
    ll query(cll l,cll r){
        //printf("query(%lld,%lld)\n",l,r);
        ql=l,qr=r;
        return query(1,1,n);
    }
}t;
int main(){
    IO();
    //gc=getchar;
    cll n=readll(),q=readll();
    F[0]=epsilon;
    rep(i,1,1e6)F[i]=F[i-1]*I;//,i<=10&&printf("%lld:(%lld,%lld)\n",i,F[i].a,F[i].b);
    rep(i,1,1e6)F[-i]=F[-i+1]*mu;//,i<=10&&printf("%lld:(%lld,%lld)\n",-i,F[-i].a,F[-i].b);
    matrix Ie6=F[1000000],mue6=F[-1000000];
    Fe6[0]=epsilon;
    rep(i,1,1e5)Fe6[i]=Fe6[i-1]*Ie6;
    rep(i,1,1e5)Fe6[-i]=Fe6[-i+1]*mue6;
    rep(i,1,n)a1[i]=readll();
    rep(i,1,n)a2[i]=readll();
    t.set(n);
    rep(i,1,q){
        cll f=readll();
        if(f==4){
            cll l=readll(),r=readll();
            writell(t.query(l,r)%mod,10);
            continue;
        }
        cll k=readll(),l=readll(),r=readll(),x=readll();
        switch(f*2+k-3){
            #define code(z)case z:t.update<z>(l,r,x);break;
            code(0)code(1)code(2)code(3)code(4)code(5)
        }
    }
    return 0;
}
/*
2 3
1 1
0 5
3 2 1 2 5 
1 2 1 2 8 
4 2 2
*/