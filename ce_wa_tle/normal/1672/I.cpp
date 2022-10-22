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
cll N=2.1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),T=1;//readll();
struct bit{
    aN f;
    ll n;
    void set(ll n_){
        memset(f,0,((n=n_)+1)<<3);
    }
    void update(ll u,cll c){
        for(;u<=n;u+=u&-u)f[u]+=c;
    }
    void update(ll l,ll r,cll c){
        r++;
        for(;l<r;l+=l&-l)f[l]+=c;
        for(;r<l;r+=r&-r)f[r]-=c;
    }
    ll query(ll u)const{
        ll res=0;
        for(;u;u&=~-u)res+=f[u];
        return res;
    }
    ll kth(ll k)const{
        ll u=0;
        red(i,1<<22)if(u+i<=n&&k>f[u+i])k-=f[u+=i];
        return u+1;
    }
    ll lower_bound(cll u)const{
        return kth(query(u)+1);
    }
}r,c;
aN p;
static inline ll iabs(cll u){
    return u<0?-u:u;
}
struct sgt{
    aN f,w,mn,lf,rt;
    bit s;
    ll n,z,m;
    cll*a;
    ll getfake(cll u)const{
        return z?m-a[m-u+1]+1:a[u];
    }
    void pushup(ll u){
        cll t=std::min(f[u<<1],f[u<<1|1]);
        f[u<<1]-=t,f[u<<1|1]-=t,f[u]+=t,w[u]=f[u<<1]?w[u<<1|1]:w[u<<1];
    }
    void pushup_mn(ll u){
        mn[u]=std::min(mn[u<<1],mn[u<<1|1]);
    }
    void set(ll n_,cll*a_,cll z_){
        n=2<<(31^__builtin_clz((m=n_)+2)),a=a_,z=z_,s.set(n),s.update(1,m+1);
        rep(i,0,n)mn[i+n]=mod,w[i+n]=i,f[i+n]=mod;
        memset(f,0,(n+1)<<3),f[n]=mod,mn[n]=w[n]=0;
        rep(i,1,n_)if(z?getfake(i)>=i:a[i]>i)mn[i+n]=getfake(i);//,printf("z=%lld i=%lld\n",z,i);
        per(i,n-1,1)pushup(i),pushup_mn(i);
        qr=n_+1,ql=0,min=mod,insert(1,0,n-1);
        /*rep(i,1,n)printf("s[%lld]=%lld\n",i,s.query(i));
        exit(0);*/
    }
    void update(ll l,ll r,cll c){
        if(l>r)return;
        //if(z==1)printf("z=%lld l=%lld r=%lld c=%lld\n",z,l,r,c);
        for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1,pushup(l),pushup(r))
        ~l&1&&(f[l^1]+=c),r&1&&(f[r^1]+=c);
        red(i,l>>1)pushup(i);
        /*if(z==1)rep(i,1,m){
            ll res=0;
            rfor(ll u=n+i;u;u>>=1)res+=f[u];
            writell(res);
        }pc(10);*/
        //printf("w=%lld %lld\n",w[1],f[1]);
    }
    ll getansr()const{
        return f[1];
    }
    ll getansw()const{
        return z?m-w[1]+1:w[1];
    }
    ll ql,qr,min;
    void erase(ll u){
        if(z)u=m-u+1;
        ql=lf[u],qr=rt[u],s.update(getfake(ql)+1,getfake(u),qr-u),update(u,u,mod),min=getfake(qr),insert(1,0,n-1),rt[ql]=qr,lf[qr]=ql;
        //printf("z=%lld u=%lld\n",z,u);rfor(ll u=rt[0];u!=m+1;u=rt[u])writell(u);
        //rep(i,1,m)printf("s[%lld]=%lld\n",i,s.query(i));
        //pc(10);
    }
    void erase_other(ll x){
        if(z)update(s.query(m-a[x]+1),m-x+1,-1);
        else update(s.query(a[x]),x,-1);
    }
    void insert(cll u,cll l,cll r,ll sum=0){
        sum+=f[u];
        //printf("z=%lld l=%lld r=%lld mn[u]=%lld min=%lld ql=%lld qr=%lld\n",z,l,r,mn[u],min,ql,qr);
        if(min<=mn[u])return;
        if(l==r){
            //printf("z=%lld l=%lld\n",z,l);
            lf[qr]=l,rt[l]=qr,min=mn[u],mn[u]=mod;
            if(l==ql)return;
            s.update(getfake(ql)+1,getfake(l),l-qr),qr=l;
            cll t=z?m-l+1:l;
            f[u]+=iabs((a[t]-c.query(a[t]))-(t-::r.query(t)))-sum;
            //printf("sum=%lld %lld %lld\n",sum,c.query(a[t]),::r.query(t));
            return;
        }
        cll mid=(l+r)>>1;
        if(qr>mid)insert(u<<1|1,mid+1,r,sum);
        if(ql<=mid)insert(u<<1,l,mid,sum);
        pushup(u),pushup_mn(u);
    }
}dt1,dt2;
void calc(cll u){
    r.update(u,1),c.update(p[u],1);
}
void calc(){
    //static ll cnt;
    cll n=readll();
    //if(0)
    rep(i,1,n)p[i]=readll();
    //else{rep(i,1,n)p[i]=i;std::random_shuffle(p+1,p+n+1);}
    //rep(i,1,n)printf("%lld ",p[i]);
    r.set(n),c.set(n),p[0]=0,p[n+1]=n+1,dt1.set(n,p,0),dt2.set(n,p,1);
    ll ans=0,w;
    rep(i,1,n)if(dt1.getansr()<dt2.getansr())
         ans=std::max(ans,dt1.getansr()),calc(w=dt1.getansw()),/*printf("%lld %lld\n",w,ans),*/dt2.erase_other(w),dt1.erase(w);
    else ans=std::max(ans,dt2.getansr()),calc(w=dt2.getansw()),/*printf("%lld %lld\n",w,ans),*/dt1.erase_other(w),dt2.erase(w);
    /*ll ans2=0;
    rep(i,1,n){
        ll mini=1;
        rep(j,2,n-i+1)if(iabs(mini-p[mini])>iabs(j-p[j]))mini=j;
        ans2=std::max(ans2,iabs(mini-p[mini]));
        rep(j,1,n-i+1)if(p[j]>p[mini])p[j]--;
        rep(j,mini,n-i+1)p[j]=p[j+1];
    }
    assert(ans==ans2);*/
    writell(ans);//,writell(ans2,10);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}
/*
1
7
7 2 5 4 7 4 2 
*/