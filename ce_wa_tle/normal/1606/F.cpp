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
aN f,next,to,head,lf,rt,ans,ft;
struct ln{
    ll k,b;
    ll y(ll x)const{
        return k*x+b;
    }
    operator ll()const{
        return b/-k;
    }
    ln&operator+=(const ln&m){
        k+=m.k,b+=m.b;
        return*this;
    }
    ln operator-()const{
        return(ln){-k,-b};
    }
    ln&operator-=(const ln&m){
        k-=m.k,b-=m.b;
        return*this;
    }
    void print(int c=0)const{
        printf("y=%lldx%+lld\n",k,b);
        c&&putchar(c);
    }
}a[N];
struct node{
    ll u,v;
    operator ll()const{
        return v;
    }
};
std::priority_queue<node>qu;
ll cnt,top;
struct bit{
    ln f[N];
    ll n;
    void set(ll n_){
        n=n_;
    }
    void update(ll u,const ln&c){
        for(;u<=n;u+=u&-u)f[u]+=c;
    }
    ln query(ll u){
        ln res={0,0};
        for(;u;u&=~-u)res+=f[u];
        return res;
    }
    ln query(ll l,ll r){
        ln res=query(r);
        res-=query(l-1);
        //myputs("res:",0),res.print();
        return res;
    }
}t;
struct ss{
    ll id,u,k;
    void read(ll i){
        id=i,u=readll(),k=readll();
    }
    operator ll()const{
        return-k;
    }
}s[N];
ll find(ll u){
    return f[u]^u?f[u]=find(f[u]):u;
}
void add(ll u,ll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs(ll u,ll fa){
    ft[u]=fa,lf[u]=++top,a[u].k=a[u].b=-1;
    rev(i,u,v)if(v^fa)dfs(v,u),a[u].b++;
    if(a[u].b!=-1)qu.push((node){u,(ll)a[u]});
    t.update(lf[u],a[u]);
    if(u!=1)t.update(lf[ft[u]],-a[u]);
    rt[u]=top;
}
int main(){
    IO();
    ll n=readll(),u,v;
    t.set(n);
    rep(i,1,n)f[i]=i;
    rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);
    dfs(1,0);
    ll q=readll();
    rep(i,1,q)s[i].read(i);
    //rep(i,1,n)a[i].print();
    std::sort(s+1,s+q+1);
    ll p=1;
    per(i,n,0){
        while(!qu.empty()&&i<=qu.top().v){
            ll u=qu.top().u,g=qu.top().v;
            qu.pop();
            //puts("???");
            if(f[u]!=u||(ll)a[u]!=g)continue;
            while(u!=1&&i<=(ll)a[u]){
                ll v=find(ft[u]);
                //printf("%lld %lld %lld\n",u,v,i);
                a[f[u]=v]+=a[u],
                t.update(lf[ft[u]],a[u]);
                //a[v].print();
                if(ft[v])t.update(lf[ft[v]],-a[u]);
                //printf("%lld %lld\n",u,v);
                u=v;
            }
            if(u!=1)qu.push((node){u,(ll)a[u]});
        //exit(0);
        }
        while(p<=q&&s[p].k>=i)ans[s[p].id]=t.query(lf[s[p].u],rt[s[p].u]).y(s[p].k)+s[p].k+1,p++;
    }
    rep(i,1,q)writell(ans[i],10);
    return 0;
}