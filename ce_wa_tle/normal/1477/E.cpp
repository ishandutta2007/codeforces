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
int fgc() {
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout() {
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c) {
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126) {
    if(l>r)std::swap(l,r);
    int c=gc();
    for(; c<l||c>r; c=gc());
    return c;
}
ll readll() {
    ll x=0,w=1;
    int c=gc();
    for(; c<48||c>57; c=gc())c-45||(w=-w);
    for(; c>47&&c<58; c=gc())x=x*10+c-48;
    return x*w;
}
void writell(ll u,int c=32) {
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u; n; n/=10)wt[++t]=n%10+48;
    for(t||pc(48); t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0) {
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10) {
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
struct ss{
    ll sum,m;
    aN f,g,a; 
    static const ll n=1e6+1;
    ll kth(ll k)const{
        ll u=0;
        k=k?k==m+1?m:k:1;
        red(i,1<<21)if(u+i<=n&&f[u+i]<k)k-=f[u+=i]; 
        return u+1;
    }
    ll query(ll u)const{
        ll res=0;
        if(u>n)return m;
        for(;u;u&=~-u)res+=f[u];
        return res;
    }
    ll pre(ll u)const{
        return kth(query(u));
    }
    ll nxt(ll u)const{
        return kth(query(u)+1);
    }
    ll delsum(ll u)const{
        ll sumf=0,sumg=0,k=u;
        for(u=u<0?0:u;u;u&=~-u)sumf+=f[u],sumg+=g[u];
//        printf("%lld %lld\n",k,sum-sumg-k*(m-sumf));
        return sum-sumg-k*(m-sumf);
    }
    void update(ll u,ll c){
        sum+=u*c;
        rfor(const ll lc=u*c;u<=n;u+=u&-u)f[u]+=c,g[u]+=lc;
    }
    void insert(ll u,ll c){
        update(a[u]=c,1);
    }
    void change(ll u,ll c){
        update(a[u],-1),update(a[u]=c,1);
    }
    void set(ll n){
        m=n;
    }
}a,b;
int main() {
    IO();
    ll n=readll(),m=readll(),q=readll(),x;
    a.set(n),b.set(m);
    rep(i,1,n)a.insert(i,readll()+1);
    rep(i,1,m)b.insert(i,readll()+1);//exit(0);
    rep(i,1,q)switch(readll()) {
        case 1:
            x=readll(),a.change(x,readll()+1);
            break;
        case 2:
            x=readll(),b.change(x,readll()+1);
            break;
        case 3:{
            ll k=readll(),mina=a.kth(1),minb=b.kth(1),min=std::min(mina,minb),maxb=b.kth(m),ansa,ansb;
            struct func1{ll operator()(ll x){return-b.delsum(x-k)+a.sum-n*min+n*std::max(0ll,k+min-x);}
            const ss&a,&b;const ll&n,&k,&min;}f1{a,b,n,k,min};
            ansb=std::max(f1(minb),f1(maxb));
            struct func2{ll operator()(ll x){return-b.delsum(x-k)+a.sum-n*min+(n-1)*std::max(0ll,k+min-x)+(k+min-x);}
            const ss&a,&b;const ll&n,&k,&min;}f2{a,b,n,k,min};
            ansa=std::max(f2(mina),std::max(f2(a.pre(maxb+k)),f2(a.nxt(maxb+k))));
            writell(std::max(ansa,ansb),10);
        }
    }
    return 0;
}
/*
4 4 1
15110 711868 621748 899182
680432 341843 512406 89464
3 509096
*/