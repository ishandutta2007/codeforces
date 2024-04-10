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
cll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),n=readll();
ll check(cll u){
    ll res=0;
    rfor(ll n=u;n;n/=10)if(n%10!=4&&n%10!=7)return 0;
    else res=res*3+(n%10==7)+1;
    return res;
}
ll C2(cll n){
    return n*(n-1)/2;
}
ll C3(cll n){
    return n*(n-1)*(n-2)/6;
}
ll C4(cll n){
    return n*(n-1)/2ull*(n-2)/3*(n-3)/4;
}
struct link{
    aN l,r;
    ll del(cll u){
        l[r[u]]=l[u],r[l[u]]=r[u];
        return l[u]?(r[u]-u)*(u-l[u]):-C2(r[u]-u);
    }
}dt;
aN a,b,nxt,lst,st,vis;
int main(){
    ll t=0;
    rep(i,1,n)if((b[i]=check(a[i]=readll())))
        st[++t]=lst[b[i]]=nxt[lst[b[i]]]=i;
    st[t+1]=n+1,vis[0]=1;
    ull res=0;
    rep(i,0,t)res+=C4(st[i+1]-st[i]+1);
    rep(r,1,t){
        res+=C3(st[r]-st[r-1]+1)*(n-st[r]+1)+C2(st[r]-st[r-1])*C2(n-st[r]+1);
        ll now=0,ls=0;
        rep(i,1,r)vis[b[st[i]]]=1;
        rep(i,r+1,t+1)if(vis[b[st[i]]])dt.l[st[i]]=ls,ls&&(now+=C2(st[i]-ls)),ls=dt.r[ls]=st[i];//,printf("i=%lld %lld\n",st[i],i);
        //printf("r=%lld now=%lld\n",r,now);
        rep(i,1,r){
        //printf("r=%lld %lld\n",res,now);
            vis[b[st[i]]]=0;
            if(!dt.r[0])continue;
            res+=(C3(st[r+1]-st[r]+1)+C2(st[r+1]-st[r]+1)*(dt.r[0]-st[r+1])+(st[r+1]-st[r])*(C2(dt.r[0]-st[r+1])+now))*(st[i]-st[i-1]);
        //printf("h=%lld\n",res);
            //printf("%lld %lld\n",dt.r[0],st[r]);
            if(nxt[st[i]]>st[r])rfor(ll u=nxt[st[i]];u;u=nxt[u])now+=dt.del(u);//,printf("ii=%lld\n",u);
        }
    }
    writell(res);
    return 0;
}