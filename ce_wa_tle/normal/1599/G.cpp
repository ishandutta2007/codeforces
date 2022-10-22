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
const ll N=2e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
typedef long double ld;
struct pt{
    ll x,y,id;
    operator ll()const{
        return x*mod+y;
    }
    friend ld dis(const pt&a,const pt&b){
        return sqrtl((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
    void read(ll i){
        id=i,x=readll(),y=readll();
    }
}p[N];
ld dis(ll a,ll b){
    return a==b?0:dis(p[a],p[b]);
}
aN d;
ll check(ll a,ll b,ll c){
    return(p[a].x-p[b].x)*(p[b].y-p[c].y)==(p[a].y-p[b].y)*(p[b].x-p[c].x);
}
int main(){
    IO();
    ll n=readll(),s=readll();
    ld ans;
    rep(i,1,n)p[i].read(i);
    std::sort(p+1,p+n+1);
    rep(i,2,n-2)if(!check(i-1,i,i+1)){
        if(i==2&&n>3){
            if(check(1,3,4))i=1;
            else if(check(2,3,4))i=0;
        }
        pt now=p[i+1];
        rep(j,i+1,n-1)p[j]=p[j+1];
        p[n]=now;
        break;
    }
    //rep(i,2,n-2)assert(check(i-1,i,i+1));
    rep(i,1,n)if(p[i].id==s){
        s=i;
        break;
    }
    //printf("%lld\n",s);
    if(s==n)ans=std::min(dis(n,1),dis(n,n-1))+dis(1,n-1);
    else{
        ans=std::min(dis(1,s)+dis(n-1,n),dis(1,n)+dis(n-1,s))+dis(1,n-1);
        rep(i,s,n-2)ans=std::min(ans,std::min(dis(s,i)+dis(1,n),dis(s,1)+dis(i,n))+dis(1,i)+dis(n,i+1)+dis(i+1,n-1));
        rep(i,2,s)ans=std::min(ans,std::min(dis(s,i)+dis(n-1,n),dis(s,n-1)+dis(i,n))+dis(n-1,i)+dis(n,i-1)+dis(i-1,1));
    }
    printf("%.10Lf\n",ans);
    return 0;
}