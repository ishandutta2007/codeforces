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
aN next,to,head,vis;
ll cnt=0;
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
ll dfs(ll u){
    vis[u]=1;
    ll res=1;
    rev(i,u,v)if(!vis[v])res+=dfs(v);
    return res;
}
aN fst,f[2][2],g[2],a,b;
ll qm(ll&a,ll b=mod){
    return a>=2*b?a-=2*b,2:a>=b?a-=b,1:0;
}
int main(){
    IO();
    ll n=readll(),m=readll(),u,v,t=0,sum=0;
    const ll y=n+1;
    rep(i,1,m)u=readll(),v=readll(),add(u,v),add(v,u);
    vis[1]=1;
    aN*now=f[0],*lst=f[1];
    now[1][y]=1;
    rep(i,1,n)if(!vis[i]){
        const ll s=dfs(i)+1;
        //printf("%lld\n",s);
        if(ll&k=fst[s]){
            b[k]++;
            const ll w=s;
            std::swap(now,lst);
            rep(o,0,1)rep(j,0,2*y)qm(now[o][j]=(j+w<=2*y?lst[o][j+w]:0)+(j-w>=0?lst[o][j-w]:0)),qm(now[0][j]+=lst[o][j]);
        }else{
            a[k=++t]=s,b[t]=1;
        }
    }
    //rep(j,0,1)rep(k,0,2*y)printf("now[%lld][%lld]=%lld\n",j,k-y,now[j][k]);
    memcpy(g,now,sizeof g);
    rep(i,0,t){
        memcpy(now,g,sizeof g);
        rep(j,1,t)if(j!=i){
            const ll w=a[j];
            //printf("%lld\n",w);
            std::swap(now,lst);
            rep(o,0,1)rep(j,0,2*y)qm(now[o][j]=(j+w<=2*y?lst[o][j+w]:0)+(j-w>=0?lst[o][j-w]:0)),qm(now[0][j]+=lst[o][j]);
        }
        //rep(j,0,1)rep(k,0,2*y)printf("now[%lld][%lld]=%lld\n",j,k-y,now[j][k]);
        if(i){
            const ll w=a[i];
            ll res=0;
            rep(j,y-w+2,y+w-2)qm(res+=now[0][j]+now[1][j]);
            qm(res+=now[1][y-w+1]+now[1][y+w-1]);
            sum=(sum+res*b[i]*2)%mod;
        }
        else qm(sum+=now[1][y]);
    }
    writell(sum);
    return 0;
}
/*
6 8
4 1
3 5
5 1
4 1
1 6
6 3
1 2
2 1
*/