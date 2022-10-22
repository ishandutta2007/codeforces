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
const ll N=1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
struct hash{
    static const ll m=9260817;
    ll v[m],k[m];
    mutable ll l;
    ll g(ll b)const{
        if(k[l]==b)return l;
        ll n=b%m,x=0;
        while(k[n]&&k[n]!=b)n=(n+2*x+++1)%m;
        return l=n;
    }
    int count(ll b)const{
        return!!k[g(b)];
    }
    ll operator[](ll b)const{
        ll n=g(b);
        return k[n]?v[n]:0;
    }
    ll&operator[](ll b){
        ll n=g(b);
        return!k[n]?k[n]=b,v[n]=0:v[n];
    }
}hs[2];
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
aN p,g,d,q,s;
int main(){
    //IO();
    ll n=readll(),m=1<<(n-1),len=m<<1,a=readll(),H=readll(),del=0;
    rep(i,p[0]=1,100)p[i]=p[i-1]*a%mod;
    per(i,m-1,0){
        static ll s=1;
        if(s*2-(s!=1)<=m-i)s=s*2-(s!=1);
        g[i]=s*2-(s!=1),qm(del+=p[g[i]]);
    }
    //printf("m=%lld\n",m);
    //ref(i,0,m)printf("%lld ",g[i]);puts("");
    del=(H+(mod-del)*m)%mod;
    //printf("%lld\n",del);
    ref(i,0,1<<m){
        ll h=0,t=-1,sum=0;
        ref(i,0,m)q[++t]=i+1;
        while(h<t)sum=(sum+q[h+(~i>>(h>>1)&1)]*p[g[h>>1]])%mod,q[++t]=q[h+(i>>(h>>1)&1)],h++,h++;
        sum=(sum+q[h]*p[i>>(h>>1)&1?2:1])%mod,hs[i>>(h>>1)&1][d[i]=sum]=i;
        //printf("%lld %lld\n",i,sum);
    }
    const ll ddel=m*(p[2]+mod-p[1])%mod;
    ll ss;
    //printf("%lld\n",ddel);
    ref(i,0,1<<m)if(hs[~i>>(m-1)&1].count(ss=(del+mod-d[i]+(~i>>(m-1)&1?ddel:0))%mod)){
        const ll r=hs[~i>>(m-1)&1][ss];
    //printf("%lld %lld\n",i,r);
        ll h=0,t=-1;
        ref(i,0,m)q[++t]=i;
        while(h<t)s[q[h+(~r>>(h>>1)&1)]]=g[h>>1],q[++t]=q[h+(r>>(h>>1)&1)],h++,h++;
        s[q[h]]=r>>(h>>1)&1?2:1;
        h=0,t=-1;
        ref(i,0,m)q[++t]=i+m;
        while(h<t)s[q[h+(~i>>(h>>1)&1)]]=g[h>>1],q[++t]=q[h+(i>>(h>>1)&1)],h++,h++;
        s[q[h]]=i>>(h>>1)&1?2:1;
        ref(i,0,len)writell(s[i]);
        pc(10);
        return 0;
    }//else printf("%lld %lld %lld\n",i,d[i],(del+mod-d[i]+(~i>>(m-1)&1?ddel:0))%mod);
    myputs("-1");
    return 0;
}