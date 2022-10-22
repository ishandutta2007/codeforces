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
const ll N=4e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
ld readld(){
    ld x=0,z=1;
    int c=gc(),w=1;
    for(;c<48||c>57;c=gc())c-45||(w=-w);
    for(;c>47&&c<58;c=gc())x=x*10+c-48;
    if(c==46)for(c=gc();c>47&&c<58;c=gc())x+=(z*=0.1)*(c-48);
    return x*w;
}
ld sum;
ld can[N],x[N];
aN c;
ll t,tc;
int cmp(ll a,ll b){
    return x[a]<x[b];
}
const ld eps=1e-9;
void add(ll l,ld v){
    if(!l)return;
    ld now=l/(v+1);
    sum+=now;
    can[++t]=now+(v!=1?l/(v-1):0),x[c[++tc]=t]=v,std::push_heap(c+1,c+tc+1,cmp);
    while(t){
        const ld v=x[c[1]],g=can[c[1]];
        if(now>=g)now-=g,sum+=g/v,std::pop_heap(c+1,c+tc+1,cmp),tc--;
        else sum+=now/v,can[c[1]]-=now,now=0;
        if(now<=eps)break;
    }
}
int main(){
    IO();
    const ll n=readll(),L=readll();
    ll lst=0;
    rep(i,1,n){
        const ll x=readll(),y=readll();
        add(x-lst,1),add((lst=y)-x,readld()+1);
    }
    add(L-lst,1);
    printf("%.12Lf\n",sum);
    return 0;
}