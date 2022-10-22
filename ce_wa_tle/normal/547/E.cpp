bool p1;
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
cll N=12e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
char cun[N];
ll son[26][N/5];
aN fail,qu,pos,head,to,next,dfn,ans,end;
ll cnt,top;
void add(cll u,cll v){
    //printf("%lld --> %lld\n",u,v);
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
struct bit{
    aN f;
    ll n;
    void set(ll n_){
        n=n_;
    }
    void update(ll u,cll c){
        //printf("dt[%lld]+=%lld\n",u,c);
        for(;u<=n;u+=u&-u)f[u]+=c;
    }
    ll query(ll u)const{
        //printf("\\sigma dt[%lld]=",u);
        ll res=0;
        for(;u;u&=~-u)res+=f[u];
        //printf("%lld\n",res);
        return res;
    }
}dt;
void dfs(ll u){
    dfn[u]=++top;
    rev(i,u,v)dfs(v);
    end[u]=top;
}
struct que{
    ll w,x,id;
    operator ll()const{
        return w;
    }
}q[N];
int main(){
    //extern bool p2;
    //printf("%fMiB\n",(&p2-&p1)/1048576.0);
    IO();
    //gc=getchar;
    cll n=readll(),m=readll();
    ll cnt=1;
    char*s=cun;
    rep(i,1,n){
        cll m=mygets(s+1);
        ll now=1;
        rep(j,1,m)now=son[s[j]-97][now]?:son[s[j]-97][now]=++cnt;
        s+=m+1,pos[i]=now;
    }
    ll t=qu[1]=1;
    rep(c,0,25)son[c][0]=1;
    rep(h,1,t){
        cll i=qu[h];
        rep(c,0,25)if(son[c][i])fail[qu[++t]=son[c][i]]=son[c][fail[i]];
        else son[c][i]=son[c][fail[i]];
    }
    rep(i,1,cnt)add(fail[i],i);
    dfs(1),dt.set(top),t=0;
    rep(i,1,m){
        cll l=readll(),r=readll(),k=readll();
        q[++t]=(que){r,pos[k],i};
        if(l>1)q[++t]=(que){l-1,pos[k],i+m};
    }
    std::sort(q+1,q+t+1),s=cun;
    ll p=1;
    rep(i,1,n){
        ll now=1;
        //printf("%lld %c\n",i,*(s+1));
        while(cll c=*++s)dt.update(dfn[now=son[c-97][now]],1);
        while(p<=t&&q[p].w==i)ans[q[p].id]=dt.query(end[q[p].x])-dt.query(dfn[q[p].x]-1),p++;
    }
    rep(i,1,m)writell(ans[i]-ans[i+m],10);
    return 0;
}
/*
5 5
a
ab
abab
ababab
b
1 5 1
3 5 1
1 5 2
1 5 3
1 4 5
*/
bool p2;