#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout),0))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=2e5+7,B=107,mod=1e9+7,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),n=readll(),b=std::max(n/100+1,(ll)sqrt(n));
std::map<ll,ll>ma;
aN val,f[B],g[B];
ll get_cnt(cll u){
    static ll cnt=0;
    return!ma.count(u)?val[++cnt]=u,ma[u]=cnt:ma[u];
}
aN a;
int main(){
    ll j=1;
    rep(i,1,n)i>=j*b&&(++j,memcpy(g[j],g[j-1],(n+1)<<3),memcpy(f[j],f[j-1],(n+1)<<3),0),++g[j][++f[j][a[i]=get_cnt(readll())]];//,printf("%lld %lld\n",i,j);
    cll m=readll();
    rep(i,1,m)if(readll()==1){
        cll x=get_cnt(readll()),u=readll(),c=u/b;
        rep(i,c+1,n/b)g[i][f[i][a[u]]--]--;
        a[u]=x;
        rep(i,c+1,n/b)++g[i][++f[i][a[u]]];
    }else{
        cll x=readll(),y=readll(),c=y/b,l=std::max(1ll,c*b);
        if(x==1)writell(val[a[y]],10);
        else if(~x&1){
            ll sum=f[c][a[y]];
            rep(k,l,y)a[k]==a[y]&&sum++;
            writell(sum,10);
        }else{
            static aN t;
            ll cnt=f[c][a[y]];
            rep(k,l,y)a[k]==a[y]&&cnt++,t[a[k]]=f[c][a[k]];
            ll sum=g[c][cnt];
            rep(k,l,y)++t[a[k]]==cnt&&sum++;
            writell(sum,10);
        }
    }
    return 0;
}