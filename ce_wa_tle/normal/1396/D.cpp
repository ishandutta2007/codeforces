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
aN x,y,c,p,ry,r;
struct bit{
    aN f;
    ll n,sum,l;
    void build(ll*w,ll n_,ll l_){
        n=n_,l=l_,sum=(ry[n]+1)*l;
        rep(i,1,n)f[i]=w[i]-w[i&~-i],sum-=w[i]*(ry[i]-ry[i-1]);
    }
    void add(ll u,ll c){
        //printf("->%lld %lld\n",u,c);
        sum+=(ry[u-1]-ry[n])*c;
        for(;u<=n;u+=u&-u)f[u]+=c;
    }
    ll find(ll v)const{
        ll u=0;
        red(i,1<<20)if(u+i<=n&&v>=f[u+i])v-=f[u+=i];
        return u+1;
    }
    void update(ll u,ll c){
    //printf("%lld %lld\n",u,c);
        static aN cu,cc;
        const ll res=query(u);
        if(res>=c)return;
        ll t=1;
        cu[1]=u,cc[1]=c-res;
        rfor(ll lst=res,u=find(res),now=query(u);;lst=now,u=find(now),now=query(u)){
            if(now>=c){
                cu[++t]=u,cc[t]=lst-c;
                break;
            }
            cu[++t]=u,cc[t]=lst-now;
        }
        while(t)add(cu[t],cc[t]),t--;
    }
    ll query(ll u)const{
        if(u>n)return mod;
        ll res=0;
        for(;u;u&=~-u)res+=f[u];
        return res;
    }
}ds;
template<ll*z>int cmp(ll x,ll y){
    return z[x]<z[y];
}
int qmax(ll&a,ll b){
    return a<b?a=b,1:0;
}
struct list{
    ll l[2102],r[2102];
    void del(ll u){
        r[l[r[u]]=l[u]]=r[u];
    }
}q1,q2;
aN lst,col;
int main(){
    IO();
    //gc=getchar;
    const ll n=readll(),k=readll(),l=readll();
    ll sum=0;
    //exit(0);
    rep(i,1,n)x[i]=readll(),y[i]=readll(),c[i]=readll(),p[i]=i;
    x[0]=ry[0]=-1,x[n+1]=ry[y[n+1]=n+1]=l,p[0]=0,p[n+1]=n+1;
    std::sort(p+1,p+n+1,cmp<y>);
    rep(i,1,n){
        ll&x=lst[c[p[i]]];
        const ll y=p[i];
        q1.l[y]=x,x=q1.r[x]=y;
    }
    rep(i,1,k)if(ll&x=lst[i])q1.r[x]=n+1,x=0;
    rep(i,1,n)ry[i]=y[p[i]],col[y[p[i]]=i]=c[p[i]];
    std::sort(p+1,p+n+1,cmp<x>);
    lst[0]=1,p[n+1]=n+1;
    per(i,n+1,1)x[p[i]]-=x[p[i-1]];
    rep(i,1,n){
        if(const ll mul=x[p[i]]){
            q2=q1;
            ll now=0,cnt=0;
            rep(l,1,n){
                while(cnt<k&&now<=n)lst[col[++now]]++||++cnt;
                r[l]=ry[now],--lst[col[l]]||--cnt;
            }
            /*rep(i,1,n)printf("%lld ",ry[i]);puts("");
            rep(i,1,n)printf("%lld ",col[i]);puts("");
            rep(i,1,n)printf("%lld ",r[i]);puts("");*/
            ds.build(r,n,l);
            //printf("%lld\n",ds.sum);
            //exit(0);
            ll ans=0;
            per(j,n,i){
                const ll add=ds.sum;
                if(__builtin_expect(!add,0))break;
                if(ll mul=x[p[j+1]])ans=(ans+add%mod*mul)%mod;
                //printf("%lld\n",q2.r[p[j]]);
                ds.update(y[q2.l[p[j]]]+1,ry[y[q2.r[p[j]]]]),q2.del(p[j]);
            }
            sum=(sum+mul*ans)%mod;
        }
        col[y[p[i]]]=0,q1.del(p[i]);
        //break;
        //fprintf(stderr,"%lld\n",i);
    }
    writell(sum);
    return 0;
}