#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=2.5e5+7,mod=998244353,iz=1<<21,oz=1<<22;
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
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10+48;
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
aN f,p;
ll find(ll u){
    return f[u]==u?u:f[u]=find(f[u]);
}
std::priority_queue<ll,std::vector<ll>,std::greater<ll>>se[N];
void merge(ll a,ll b){
    if(se[p[a]].size()>se[p[b]].size())std::swap(p[a],p[b]);
    std::priority_queue<ll,std::vector<ll>,std::greater<ll>>&x=se[p[a]],&y=se[p[b]];
    while(x.size())y.push(x.top()),x.pop();
    while(y.size()&&y.top()<b)y.pop();
}
struct lb{
    aN l,r;
    void set(cll n){
        rep(i,0,n)l[r[i]=i+1]=i,f[i]=i,p[i]=i;
        p[n+1]=n+1,f[n+1]=n+1;
    }
    int has(cll u)const{
        return r[l[u]]==u;
    }
    void del(cll u){
        r[l[u]]=r[u],l[r[u]]=l[u];
        merge(u,r[u]),f[u]=r[u];
    }
}t;
int main(){
    IO();
    //gc=getchar;
    cll n=readll(),m=readll();
    t.set(n);
    rep(i,1,m)if(readll()==1){
        cll x=readll();
        if(!t.has(x))myputs("NO");
        else{
            myputs(!se[p[x]].size()||se[p[x]].top()>=t.r[x]?"N/A":"YES");
        }
    }else{
        cll l=readll(),r=readll();
        if(readll()==0)rfor(ll i=find(l);i<=r;i=t.r[i])t.del(i);
        else se[p[find(l)]].push(r);
    }
    return 0;
}