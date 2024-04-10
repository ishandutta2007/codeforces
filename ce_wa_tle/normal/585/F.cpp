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
char s[N],l[N],r[N];
aN son[26],fail,end,f,g,q;
void qm(ll&a,cll b=mod){
    a>=b&&(a-=b);
}
ll getans(const char*s,cll n,cll m){
    //rep(i,1,n)pc(s[i]+48);pc(10);
    memset(f+1,0,m<<3);
    ll now=1;
    rep(i,1,n){
        cll t=s[i];
        memset(g+1,0,m<<3);
        per(j,m,1)rep(c,0,9)qm(g[son[c][j]]+=f[j]);
        ref(c,0,t)qm(++g[son[c][now]]);
        now=son[t][now];
        memcpy(f+1,g+1,m<<3);
    }
    ll res=0;
    f[now]+=1;
    rep(i,1,m)if(end[i])res+=f[i];
    //printf("res=%lld\n",res);
    return res%mod;
}
int main(){
    IO();
    //gc=getchar;
    cll n=mygets(s+1),d=mygets(l+1),c=mygets(r+1),m=d/2;
    ll cnt=1;
    rep(i,1,n)s[i]&=15;
    rep(i,1,d)l[i]&=15,r[i]&=15;
    per(i,d,1)if(l[i]!=0){l[i]--;break;}else l[i]=9;
    rep(i,1,n-m+1){
        ll now=1;
        rep(j,i,i+m-1)now=son[s[j]][now]?:son[s[j]][now]=++cnt;
        end[now]=1;
    }
    rep(c,0,9)son[c][0]=1;
    ll t=q[1]=1;
    rep(h,1,t){
        cll i=q[h];
        rep(c,0,9)if(son[c][i])fail[q[++t]=son[c][i]]=son[c][fail[i]];
        else son[c][i]=son[c][fail[i]];
        //rep(c,0,9)printf("%lld %lld %lld\n",i,c,son[c][i]);
    }
    rep(i,1,cnt)if(end[i])rep(c,0,9)son[c][i]=i;
    writell((getans(r,c,cnt)+mod-getans(l,d,cnt))%mod);
    return 0;
}