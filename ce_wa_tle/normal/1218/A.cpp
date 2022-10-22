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
    c&&pc(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
aN q,d,next,to,head,st,id,sz,a,f,s;
ll cnt,top,sum;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs_c(ll u){
    st[id[u]=++top]=u;
    rev(i,u,v)if(d[v]&&!id[v])dfs_c(v);
}
void dfs_t(ll u,ll fa){
    sz[u]=1;
    rev(i,u,v)if(v^fa&&!d[v])dfs_t(v,u),sz[u]+=sz[v];
}
ll n;
ll dfs_t2(ll u,ll fa,ll now){
    if(fa)sum+=sz[u],now+=n-2*sz[u];
    ll flag=now;
    rev(i,u,v)if(v^fa&&!d[v])flag=std::max(flag,dfs_t2(v,u,now));
    return flag;
}
int main(){
    IO();
    const ll n=::n=readll();
    ll u,v;
    rep(i,1,n)u=readll()+1,v=readll()+1,add(u,v),add(v,u),d[u]++,d[v]++;
    ll h=1,t=0;
    rep(i,1,n)if(d[i]==1)q[++t]=i;
    while(h<=t){
        const ll u=q[h++];
        rev(i,u,v)if(--d[v]==1)q[++t]=v;
    }
    ll z=0;
    rep(i,1,n)if(d[i]==1)d[i]=0;
    rep(i,1,n)if(d[i]==2)dfs_t(i,0),a[i]=dfs_t2(i,0,0),z=i;
    dfs_c(z);
    rep(i,1,top)s[i]=sz[st[i]];
    memcpy(s+top+1,s+1,top<<3);
    rep(i,1,2*top)s[i]+=s[i-1];
    ref(len,1,top){
        f[top+1]=f[1];
        rep(j,1,top)f[j]=std::max(f[j],f[j+1])+s[j+len-1]-s[j-1];
    }
    ll max=0;
    f[top+1]=f[1];
    rep(i,1,top)max=std::max(max,f[i+1]+a[st[i]]);
    writell(sum+max+n);
    return 0;
}