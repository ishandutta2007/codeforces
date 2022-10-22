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
cll N=5e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
char s[N];
ll r[N][10],l[N][10],g[10];
aN vis,tim;
//extern struct list nd,nl;
//if(this==&nd)printf("nd.del(%lld)\n",u);
struct list{
    aN l,r;
    void set(ll m){rep(i,0,m)l[r[i]=i+1]=i;}
    void del(cll u){r[l[r[u]]=l[u]]=r[u];}
    ll getnxt(cll u,cll x)const{return u[x?l:r];}
}nd,nl;
aN f;
ll find(cll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
int main(){
    IO();
    //gc=getchar;
    cll n=readll(),q=readll();
    mygets(s+1),s[0]='>';
    nd.set(n),nl.set(n);
    rep(i,1,n+1)f[i]=i;
    ll now=1,w=0,lst=0,cnt=0;
    while(++cnt){
        if(!vis[now])memcpy(r[now],g,sizeof g),vis[now]=cnt;
        if(lst>now)rfor(ll i=find(now);i<lst;i=nl.getnxt(i,0))memcpy(l[i],g,sizeof g),tim[i]=cnt,f[i]=find(i+1),nl.del(i);
        lst=now;
        if(now>n)break;
        if(now<1)now=nd.getnxt(now,w=1);
        if(s[now]<58)g[s[now]---48]++,s[now]==47&&(nd.del(now),0),now=nd.getnxt(now,w);
        else w=(s[now]=='<')?1:0,now=nd.getnxt(now,w),s[now]>57&&(nd.del(lst),0);
    }
    rep(i,1,q){
        cll ql=readll(),qr=readll(),*const g=!tim[ql-1]||vis[qr+1]<tim[ql-1]?r[qr+1]:l[ql-1];
        rep(i,0,9)writell(g[i]-r[ql][i]);pc(10);
    }
    return 0;
}