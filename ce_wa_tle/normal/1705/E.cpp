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
cll N=2.2e5+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
aN a;
struct bit{
    aN f1,f2;
    ll n,sum;
    void set(cll n_,cll*t){
        n=n_;
        ll now=0,lst=0;
        rep(i,1,n){
            now+=t[i];
            cll z=now&1,d=i+(i&-i);
            sum+=z;
            if(z!=lst){
                if(z)f1[i]++,f2[i]+=i;
                else f1[i]--,f2[i]-=i;
                lst=now&1;
            }
            if(d<=n)f1[d]+=f1[i],f2[d]+=f2[i];
            now/=2;
        }
    }
    void add(cll x){
        ll res1=0,res2=0;
        rfor(ll u=x-1;u;u&=~-u)res1+=f1[u],res2+=f2[u];
        ll r=0,k=x-1-(res1*x-res2),now1=0,now2=0;
        red(i,1<<21)if(r+i<=n&&r+i-((now1+f1[r+i])*(r+i+1)-(now2+f2[r+i]))<=k)now1+=f1[r+i],now2+=f2[r+=i];
        ll u=x,v=r+1,w=r+2;
        for(;u<w;u+=u&-u)f1[u]--,f2[u]-=x;
        u=std::min(u,n+1);
        for(;v<u;v+=v&-v)f1[v]+=2,f2[v]+=2*r+2;
        for(;w<u;w+=w&-w)f1[w]--,f2[w]-=r+2;
        for(;w<=n;w+=w&-w)f2[w]-=x-r;
        sum-=r-x;
    }
    void del(cll x){
        ll res1=0,res2=0;
        rfor(ll u=x-1;u;u&=~-u)res1+=f1[u],res2+=f2[u];
        ll r=0,k=res1*x-res2,now1=0,now2=0;
        red(i,1<<21)if(r+i<=n&&(now1+f1[r+i])*(r+i+1)-(now2+f2[r+i])<=k)now1+=f1[r+i],now2+=f2[r+=i];
        ll u=x,v=r+1,w=r+2;
        for(;u<w;u+=u&-u)f1[u]++,f2[u]+=x;
        u=std::min(u,n+1);
        for(;v<u;v+=v&-v)f1[v]-=2,f2[v]-=2*r+2;
        for(;w<u;w+=w&-w)f1[w]++,f2[w]+=r+2;
        for(;w<=n;w+=w&-w)f2[w]+=x-r;
        sum+=r-x;
    }
    ll getans()const{
        ll r=0,now1=0,now2=0;
        red(i,1<<21)if(r+i<=n&&(now1+f1[r+i])*(r+i+1)-(now2+f2[r+i])<sum)now1+=f1[r+i],now2+=f2[r+=i];
        return r+1;
    }
    void print()const{
        rep(i,1,10){
            ll sum=0;
            {
                ll res1=0,res2=0;
                rfor(ll u=i;u;u&=~-u)res1+=f1[u],res2+=f2[u];
                sum+=res1*(i+1)-res2;
            }
            {
                ll res1=0,res2=0;
                rfor(ll u=i-1;u;u&=~-u)res1+=f1[u],res2+=f2[u];
                sum-=res1*i-res2;
            }
            pc(sum+48);
        }
        pc(10);
    }
}dt;
aN t;
void calc(){
    cll n=readll(),m=readll();
    //cll n=200000,m=200000;
    //#define readll() rand()%200000+1
    rep(i,1,n)++t[a[i]=readll()];
    dt.set(2.1e5,t);
    //dt.print();
    //exit(0);
    rep(i,1,m){
        cll x=readll();
        //cll x=rand()%n+1;
        dt.del(a[x]),dt.add(a[x]=readll());
        writell(dt.getans(),10);
        //dt.print();
    }
}
int main(){
    rep(i,1,T)calc();
    return 0;
}