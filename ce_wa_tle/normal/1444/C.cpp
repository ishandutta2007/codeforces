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
const ll N=2e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
aN a,f,c,can,t,u,v,head,to,next,fz;
ll cnt;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void clear(ll n){
    memset(head+1,cnt=0,n<<3);
}
int dfs(ll u){
    rev(i,u,v)if(!f[v]?f[v]=f[u]^1,!dfs(v):!(f[u]^f[v]))return 0;
    return 1;
}
int main(){
    IO();
    ll n=readll(),m=readll(),k=readll();
    rep(i,1,n)a[i]=readll();
    rep(i,1,m)if(a[u[i]=readll()]==a[v[i]=readll()])add(u[i],v[i]),add(v[i],u[i]);
    ll ct=n*2,sum=k;
    rep(i,1,n)if(!f[i])f[i]=ct+=2,can[a[i]]|=!dfs(i);
    clear(n);
    rep(i,1,k)if(can[i])sum--;
    sum=sum*(sum-1)/2;
    rep(i,1,m)if(a[u[i]]>a[v[i]])std::swap(u[i],v[i]);
    rep(i,1,m)t[a[v[i]]]++;
    rep(i,1,k)t[i]+=t[i-1];
    rep(i,1,m)c[++t[a[v[i]]-1]]=i;
    memcpy(fz+1,u+1,m<<3);
    rep(i,1,m)u[i]=fz[c[i]];
    memcpy(fz+1,v+1,m<<3);
    rep(i,1,m)v[i]=fz[c[i]];
    ll lst=1;
    memset(t,0,(k+1)<<3);
    rep(i,1,m)t[a[u[i]]]++;
    rep(i,1,k)t[i]+=t[i-1];
    rep(i,1,m)c[++t[a[u[i]]-1]]=i;
    memcpy(fz+1,u+1,m<<3);
    rep(i,1,m)u[i]=fz[c[i]];
    memcpy(fz+1,v+1,m<<3);
    rep(i,1,m)v[i]=fz[c[i]];
    //if(n==100&&m==1000&&k==50)exit(0);
    rep(i,1,m)if(a[u[i]]!=a[u[i+1]]||a[v[i]]!=a[v[i+1]]){
        if(a[u[i]]!=a[v[i]]&&!can[a[u[i]]]&&!can[a[v[i]]]){
            ll now=ct/2,u;
            rep(j,lst,i){
                const ll u=f[::u[j]],v=f[::v[j]];
                if((u^v)&1)add(u/2,++now),add(now,u/2),add(v/2,now),add(now,v/2);
                else add(u/2,v/2),add(v/2,u/2);
            }
            rep(j,lst,i)if(!f[u=f[::u[j]]/2]&&(f[u]=2,!dfs(u))){
                sum--;
                break;
            }
            cnt=0;
            rep(j,lst,i){
                const ll u=f[::u[j]],v=f[::v[j]];
                if((u^v)&1)f[now]=0,head[now--]=0;
                head[u/2]=head[v/2]=0,f[u/2]=f[v/2]=0;
            }
        }
        lst=i+1;
    }
    writell(sum);
    return 0;
}