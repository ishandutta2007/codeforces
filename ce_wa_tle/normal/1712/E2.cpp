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
cll N=2e5+7,mod=998244853,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),T=1;
aN ans,head,to,next,t;
ll cnt;
void add(cll u,cll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
struct bit{
    aN f;
    ll n;
    void set(cll n_){
        memset(f,0,((n=n_)+1)<<3);
    }
    void update(ll u,cll c){
        //f[u]+=c;return;
        for(;u<=n;u+=u&-u)f[u]+=c;
    }
    ll query(ll u)const{
        ll res=0;
        //rep(i,1,u)res+=f[u];
        //return res;
        for(;u;u&=~-u)res+=f[u];
        return res;
    }
}dt;
ll fw(cll u){
    return u<0?0:u;
}
aN lst;
void calc(){
    cll n=readll();
    //cll n=100000;
    memset(head,cnt=0,(200001)<<3);
    memset(t,0,(200001)<<3);
    memset(lst,0,(200001)<<3);
    dt.set(2e5);
    rep(i,1,n){
        cll l=readll(),r=readll();
        //cll a=rand()%n+1,b=rand()%n+1,l=std::min(a,b),r=a+b-l;
        cll n=r-l+1;
        add(l,r),ans[i]=n*(n-1)*(n-2)/6-fw(r/6-(l-1)/3)-fw(r/15-(l-1)/6);
    }
    per(l,2e5,1){
        /*rfor(ll r=l*2;r<=2e5;r+=l){
            ll c=t[r]++,u=r;
            for(;u<l+r&&u<=2e5;u+=u&-u)dt.f[u]+=c+=lst[u],lst[u]=0;
            if(u<=2e5)lst[u]+=c;
        }*/
        rfor(ll r=l*2;r<=2e5;r+=l)dt.update(r,t[r]++);
        rev(i,l,r)ans[i]-=dt.query(r);
    }
    rep(i,1,n)writell(ans[i],10);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}