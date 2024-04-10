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
const ll N=1e6+7,mod=1e9+7,m2=5e8+4,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc() {
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout() {
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c) {
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126) {
    if(l>r)std::swap(l,r);
    int c=gc();
    for(; c<l||c>r; c=gc());
    return c;
}
ll readll() {
    ll x=0,w=1;
    int c=gc();
    for(; c<48||c>57; c=gc())c-45||(w=-w);
    for(; c>47&&c<58; c=gc())x=x*10+c-48;
    return x*w;
}
void writell(ll u,int c=32) {
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u; n; n/=10)wt[++t]=n%10^48;
    for(t||pc(48); t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0) {
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10) {
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
struct node{
    ll t,u,s,p;
}p[N];
aN k;
struct cmp_t{
    int operator()(ll x,ll y)const{
        return p[x].u<p[y].u;
    }
};
std::set<ll,cmp_t>h,z;
int main() {
    IO();
    ll n=readll(),cnt=2,m=readll();
    static_cast<void>(m);
    p[1]=(node){0,0,0,0},
    p[2]=(node){1,0,0,0};
    h.insert(1),z.insert(2);
//    const ll s=k[0];
//    for(std::set<ll,cmp_t>::iterator i=z.begin();i!=z.end();i++)printf("(%lld,%lld),",s,p[*i].u);pc(10);
//    for(std::set<ll,cmp_t>::iterator i=h.begin();i!=h.end();i++)printf("(%lld,%lld),",p[*i].u,s);pc(10);
    rep(i,1,n){
        k[i]=readll();
        ll lx=readll(),rx=readll(),ly=readll(),ry=readll();
        ll sh=i==1?0:h.empty()?0:*h.begin(),sz=z.empty()?0:*z.begin();
        if(k[i]<lx||rx<k[i])z.clear();
        else{
            while(!z.empty()&&p[*z.begin()].u<ly)z.erase(z.begin());
            while(!z.empty()&&p[*--z.end()].u>ry)z.erase(--z.end());
            if(sh&&ly<=k[i-1]&&k[i-1]<=ry)p[++cnt]=(node){1,k[i-1],i,sh},z.insert(cnt);
        }
        if(k[i]<ly||ry<k[i])h.clear();
        else{
            while(!h.empty()&&p[*h.begin()].u<lx)h.erase(h.begin());
            while(!h.empty()&&p[*--h.end()].u>rx)h.erase(--h.end());
            if(sz&&lx<=k[i-1]&&k[i-1]<=rx)p[++cnt]=(node){0,k[i-1],i,sz},h.insert(cnt);
        }
//        const ll s=k[i];
//        for(std::set<ll,cmp_t>::iterator i=z.begin();i!=z.end();i++)printf("(%lld,%lld),",s,p[*i].u);pc(10);
//        for(std::set<ll,cmp_t>::iterator i=h.begin();i!=h.end();i++)printf("(%lld,%lld),",p[*i].u,s);pc(10);
    }
    ll id=z.empty()?h.empty()?0:*h.begin():*z.begin();
    static ll ans[N];
    if(!id)return!myputs("No");
    per(i,n,1){
        if(i<p[id].s)id=p[id].p;
        ans[i]=!p[id].t;
    }
    myputs("Yes");
    rep(i,1,n)writell(ans[i]);
    return 0;
}
// y k
//z^ o
// |
//z|oo  o o k
//z| o
// +------->x
//  hh  h h