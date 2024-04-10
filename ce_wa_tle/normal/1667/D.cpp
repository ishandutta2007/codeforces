#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
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
cll IO_res=IO(),T=readll();
ll cnt,flag;
aN head,next,to;
void add(cll u,cll v){
    //printf("%lld->%lld\n",u,v);
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
aN s,l;
int dfs0(cll u,cll fa){
    ll d=1,s0=0,s1=0;
    rev(i,u,v)if(v^fa){
        d++;
        if(dfs0(v,u))s1++;
        else s0++;
        if(flag)return-1;
    }
    if(s0>d/2)flag=1;
    if(s1>(d+1)/2)flag=1;
    s[u]=d;
    return l[u]=s1<(d+1)/2;
}
void dfs2(cll u,cll fa){
    cll d=s[u];
    ll s0[d/2+1],s1[(d+1)/2+1],t0=0,t1=0;
    rev(i,u,v)if(v!=fa)(l[v]?s1[t1++]:s0[t0++])=v;
    (t1!=(d+1)/2?s1[t1++]:s0[t0++])=fa;
    per(i,d,1){
        cll now=i&1?s1[--t1]:s0[--t0];
        if(now==fa){
            if(fa)writell(u),writell(fa,10);
        }else dfs2(now,u);
    }
}
void calc(){
    cll n=readll();
    memset(head,cnt=0,(n+1)<<3);
    rep(i,2,n){
        cll u=readll(),v=readll();
        add(u,v),add(v,u);
    }
    dfs0(1,flag=0);
    if(flag||(s[1]&1)!=l[1]){
        myputs("NO");
        return;
    }
    myputs("YES");
    dfs2(1,0),pc(10);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}
/*
1
8
7 3
1 8
3 1
6 8
5 6
8 4
2 3
*/