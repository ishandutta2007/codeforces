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
cll N=12222,mod=998244353,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),T=1;
aN f,z,res,head,to,next;
ll find(cll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
ll cnt;
void add(cll u,cll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
int dfs(cll u,cll fa){
    rev(i,u,v)if(v^fa&&dfs(v,u))res[v]^=1,res[u]^=1;
    return res[u];
}
void calc(){
    cll n=readll(),m=readll();
    switch((n&1)<<1|(m&1)){
        case 0:{
            ll c=1;
            rep(i,1,n)rep(j,1,m)readchar()=='?'&&(c=c*2%mod);
            writell(c,10);return;
        }
        case 1:{
            ll c=1,t0=1,t1=1;
            rep(i,1,n){
                ll f=0,z=0;
                rep(j,1,m){
                    cll x=readchar();
                    x=='?'?f?c=c*2%mod:++f:z^=x&1;
                }
                if(!f)z?t0=0:t1=0;
            }
            writell(c*(t0+t1)%mod,10);return;
        }
        case 2:{
            ll c=1,t0=1,t1=1;
            rep(i,1,n)rep(j,1,m){
                cll x=readchar();
                x=='?'?f[j]?c=c*2%mod:++f[j]:z[j]^=x&1;
            }
            rep(i,1,m)if(!f[i])z[i]?t0=0:t1=0;
            writell(c*(t0+t1)%mod,10);return;
        }
        case 3:{
            ll c=1;
            rep(i,1,n+m)f[i]=i;
            rep(i,1,n){
                rep(j,n+1,n+m){
                    cll x=readchar();
                    x=='?'?find(i)!=find(j)?(add(i,j),add(j,i),f[find(i)]=find(j)):c=c*2%mod:x&1&&(res[i]^=1,res[j]^=1);
                }
            }
            ll t0=1,t1=1;
            rep(i,1,n+m)if(f[i]==i&&dfs(i,0)){t0=0;break;}
            rep(i,1,n+m)res[i]^=1;
            rep(i,1,n+m)if(f[i]==i&&dfs(i,0)){t1=0;break;}
            writell(c*(t0+t1)%mod,10);return;
        }
    }
}
int main(){
    rep(i,1,T)calc();
    return 0;
}
/*
3 3
000
0??
0??
*/