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
ll to[126];
aN f;
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
struct sgt{
    ll cnt,n,rt;
    struct {
        ll ls,rs,v[6];
    }val[N];
    void pushup(ll u,ll cs){
        ref(i,0,6)if(~val[u].v[i]){
            if(cs==1){
                val[u].v[i]=1;
                continue;
            }
            ll ls=0;
            if(ll x=val[u].ls)ref(j,0,6)(j^i)>>1&&~val[x].v[j]&&qm(ls+=val[x].v[j]);
            else ls=4*f[cs-1]%mod;
            ll rs=0;
            if(ll x=val[u].rs)ref(j,0,6)(j^i)>>1&&~val[x].v[j]&&qm(rs+=val[x].v[j]);
            else rs=4*f[cs-1]%mod;
            //printf("%lld %lld %lld\n",u,ls,rs);
            val[u].v[i]=ls*rs%mod;
        }
        //ref(i,0,6)printf("%lld ",val[u].v[i]);puts("");
    }
    void lim(ll u,ll cs,ll l){
        pushup(u,cs);
        ref(i,0,6)if(i!=l)val[u].v[i]=-1;
    }
    void update(ll&u,ll cs,ll q,ll g,ll c){
        u=u?:++cnt;
        //printf("%lld %lld %lld %lld %lld\n",u,cs,q,g,c);
        if(g==-1)return lim(u,cs,c);
        update(q>>g&1?val[u].rs:val[u].ls,cs-1,q,g-1,c);
        pushup(u,cs);
    }
    void set(ll n_){
        n=n_,rt=cnt=1;
    }
    void update(ll x){
        update(rt,n,x,(__builtin_clzll(x)^63)-1,to[readchar()]);
    }
}t;
int main(){
    IO();
    to['w']=0,to['u']=1,
    to['g']=2,to['b']=3,
    to['r']=4,to['o']=5;
    ll k=readll(),n=readll();
    t.set(k);
    f[1]=1;
    rep(i,2,k)f[i]=16ll*f[i-1]%mod*f[i-1]%mod;
    rep(i,1,n)t.update(readll());
    ll sum=0;
    ref(i,0,6)if(~t.val[1].v[i])qm(sum+=t.val[1].v[i]);
    writell(sum);
    return 0;
}