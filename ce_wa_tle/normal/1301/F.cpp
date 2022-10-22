#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout);
typedef long long ll;
typedef unsigned long long ull;
const ll N=1.1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
struct node{
    short x,y;
    node(){}
    template<typename T>
    node(T a,T b):x(a),y(b){}
    void read(){
        x=readll(),y=readll();
    }
    ll dis(const node&b)const{
        return llabs(b.x-x)+llabs(b.y-y);
    }
    ll check(ll n,ll m){
        return 1<=x&&x<=n&&1<=y&&y<=m;
    }
}q[N],st[N];
aN t,l,r,v;
struct aNN{
    short v[1024][1024];
    const short*operator[](ll b)const{
        return v[b];
    }
    short*operator[](ll b){
        return v[b];
    }
    const short&operator[](const node&b)const{
        return v[b.x][b.y];
    }
    short&operator[](const node&b){
        return v[b.x][b.y];
    }
}f[41],a;
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
const short dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main(){
    IO();
    const ll n=readll(),m=readll(),k=readll();
    rep(i,1,n)rep(j,1,m)t[a[i][j]=readll()]++;
    rep(i,1,k)l[i]=t[i-1]+1,r[i]=t[i]+=t[i-1];
    rep(i,1,n)rep(j,1,m)st[++t[a[i][j]-1]]=node(i,j);
    memset(f,-1,sizeof f);
    rep(c,1,k){
        aNN&f=::f[c];
        ll h=1,t=0;
        rep(i,l[c],r[c])f[q[++t]=st[i]]=0;
        v[c]=c;
        while(h<=t){
            const node&u=q[h++];
            const ll dis=f[u];
            if(v[a[u]]!=c){
                rep(i,l[a[u]],r[a[u]])if(!~f[st[i]])f[q[++t]=st[i]]=dis+1;
                v[a[u]]=c;
            }
            ref(i,0,4){
                node v(u.x+dx[i],u.y+dy[i]);
                if(v.check(n,m)&&!~f[v])f[q[++t]=v]=dis+1;
            }
        }
    }
    const ll q=readll();
    rep(i,1,q){
        node a,b;
        a.read(),b.read();
        ll ans=a.dis(b);
        rep(i,1,k)qm(ans,(unsigned short)f[i][a]+(unsigned short)f[i][b]+1);
        writell(ans,10);
    }
    return 0;
}