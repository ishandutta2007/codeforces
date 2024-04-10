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
cll N=4.2e5+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
void init(){
}
aN a,l,r,s;
ll n,m;
int check(cll i,cll j){
    cll x=(i-1)*m+j;
    if(a[x]==1)return 1;
    if(i!=1&&a[x-m]<a[x])return 1;
    if(j!=1&&a[x-1]<a[x])return 1;
    if(i!=n&&a[x+m]<a[x])return 1;
    if(j!=m&&a[x+1]<a[x])return 1;
    return 0;
}
int check_plus(cll i,cll j){
    if(!check(i,j))return 0;
    if(i!=1&&!check(i-1,j))return 0;
    if(j!=1&&!check(i,j-1))return 0;
    if(i!=n&&!check(i+1,j))return 0;
    if(j!=m&&!check(i,j+1))return 0;
    return 1;
}
void qmin(ll&a,ll&b,cll c){
    if(c<a)b=a,a=c;else if(c<b)b=c;
}
ll diff(cll a,cll b){
    return a>b?a-b:b-a;
}
void calc(){
    cll n=::n=readll(),m=::m=readll();
    rep(i,1,n*m)a[i]=readll(),l[i]=0,r[i]=n*m+1,s[i]=0;
    /*cll n=::n=20,m=::m=20;
    //writell(n),writell(m,10);
    rep(i,1,n*m)l[i]=0,r[i]=n*m+1,s[i]=0;
    {
        static aN q,vis;
        memset(vis,0,(n*m+1)<<3);
        ll t=1;
        q[1]=rand()%(n*m)+1,vis[q[1]]=1;
        rep(h,1,t){
            std::random_shuffle(q+h,q+t+1);
            cll u=q[h],i=(u-1)/m+1,j=(u-1)%m+1;
            a[u]=h;
            if(i!=1&&!vis[u-m])vis[q[++t]=u-m]=1;
            if(j!=1&&!vis[u-1])vis[q[++t]=u-1]=1;
            if(i!=n&&!vis[u+m])vis[q[++t]=u+m]=1;
            if(j!=m&&!vis[u+1])vis[q[++t]=u+1]=1;
        }
    }
    std::swap(a[rand()%(n*m)+1],a[rand()%(n*m)+1]);
    //rep(i,1,n*m)a[i]<100&&pc(32),writell(a[i],i%m==0?10:32);pc(10);
    */
    ll q[122],tq=0,t=0;
    rep(i,1,n)rep(j,1,m){
        cll x=(i-1)*m+j;
        ll min=n*m+1,cmin=n*m+1;
        if(i!=1)qmin(min,cmin,a[x-m]);
        if(j!=1)qmin(min,cmin,a[x-1]);
        if(i!=n)qmin(min,cmin,a[x+m]);
        if(j!=m)qmin(min,cmin,a[x+1]);
        l[x]=std::max(l[x],min);
        if(a[x]==1)continue;
        //if(i==16&&j==3)printf("min=%lld cmin=%lld %lld %lld %lld %lld\n",min,cmin,a[x-m],a[x-1],a[x+m],a[x+1]);
        if(min>a[x]){
            if(t<=10){
                cll c=1<<t++;
                q[tq++]=x,s[x]|=c;
                if(i!=1)r[x-m]=std::min(r[x-m],a[x]),s[x-m]||(q[tq++]=x-m),s[x-m]|=c;
                if(j!=1)r[x-1]=std::min(r[x-1],a[x]),s[x-1]||(q[tq++]=x-1),s[x-1]|=c;
                if(i!=n)r[x+m]=std::min(r[x+m],a[x]),s[x+m]||(q[tq++]=x+m),s[x+m]|=c;
                if(j!=m)r[x+1]=std::min(r[x+1],a[x]),s[x+1]||(q[tq++]=x+1),s[x+1]|=c;
            }
        }else if(cmin>a[x]){
            if(i!=1&&a[x-m]==min)r[x-m]=std::min(r[x-m],a[x]);
            else if(j!=1&&a[x-1]==min)r[x-1]=std::min(r[x-1],a[x]);
            else if(i!=n&&a[x+m]==min)r[x+m]=std::min(r[x+m],a[x]);
            else if(j!=m&&a[x+1]==min)r[x+1]=std::min(r[x+1],a[x]);
        }
    }
    //rep(i,1,n*m)writell(l[i],i%m==0?10:32);pc(10);
    //rep(i,1,n*m)writell(r[i],i%m==0?10:32);pc(10);
    if(t==0)return writell(0,10);
    if(t>10)return writell(2,10);
    ll cnt=0;
    ref(h,0,tq){
        cll x=q[h],i=(x-1)/m+1,j=(x-1)%m+1;
        cll now=((1<<t)-1)^s[x];
        ref(z,h+1,tq)if(!(now&~s[q[z]])){
            cll y=q[z],k=(y-1)/m+1,l=(y-1)%m+1;
            std::swap(a[x],a[y]);
            if(check_plus(i,j)&&check_plus(k,l))cnt++;
            std::swap(a[x],a[y]);
        }
        if(!now){
            ll y=0;
            rep(k,1,n)rep(l,1,m)if(!s[y=(k-1)*m+l]){
                if(diff(i,k)+diff(j,l)>2){
                    if((a[x]==1||(::l[y]<=a[x]&&a[x]<=r[y]))
                     &&(a[y]==1||(::l[x]<=a[y]&&a[y]<=r[x])))cnt++;
                    /*{
                        std::swap(a[x],a[y]);
                        if(!(check_plus(i,j)&&check_plus(k,l)))printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",i,j,k,l,::l[x],::r[x],::l[y],r[y]),assert(0);
                        std::swap(a[x],a[y]);
                            cnt++;
                    }*/
                }else{
                    std::swap(a[x],a[y]);
                    if(check_plus(i,j)&&check_plus(k,l))cnt++;
                    std::swap(a[x],a[y]);
                }
            }
        }
    }
    /*rep(i,1,n)rep(j,1,m){
        cll x=(i-1)*m+j;
        ll y;
        rep(k,1,n)rep(l,1,m)if((s[y=(k-1)*m+l]|s[x])==((1<<t)-1)&&x<y){
            std::swap(a[x],a[y]);
            if(check_plus(i,j)&&check_plus(k,l))cnt++;
            std::swap(a[x],a[y]);
        }
    }*/
    if(cnt)writell(1),writell(cnt,10);
    else writell(2,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}