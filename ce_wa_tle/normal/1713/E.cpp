#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    //return 0;
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
aN f,p;
ll s[1001][1001];
ll find(cll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
void calc(){
    //pc(10);
    cll n=readll();
    rep(i,1,n)rep(j,1,n)s[i][j]=readll();
    rep(i,1,2*n)f[i]=i,p[i]=-1;
    rep(i,1,n)rep(j,1,n){
        if(s[j][i]<s[i][j]){
            if(find(i)==find(j))continue;
            f[find(i)]=find(j+n);
            f[find(j)]=find(i+n);
        }
        if(s[j][i]>s[i][j]){
            if(find(i)==find(j+n))continue;
            f[find(i)]=find(j);
            f[find(j+n)]=find(i+n);
        }
    }
    //rep(i,1,n)rep(j,1,n)writell(p[i]^p[j]?s[j][i]:s[i][j],j==n?10:32);
    //rep(i,1,n)printf("%lld %lld\n",find(i),find(i+n));
    rep(i,1,n)p[i]=p[find(i)]!=-1?p[find(i)]:0,p[find(i+n)]=p[i+n]=p[i]^1;
    //rep(i,1,n)printf("%lld %lld\n",p[i],p[i+n]);
    /*rep(i,2,n){
        ll x=1;
        while(x<=n&&s[i][x]==s[x][i])x++;
        a[i]=x,b[i]=i,p[i]=0;
    }
    std::sort(b+1,b+n+1,cmp);
    rep(i,1,n)if(a[b[i]]!=n+1){
        cll u=b[i],v=a[b[i]];
        p[u]=(s[u][v]<s[v][u])^p[v];
    }*/
    rep(i,1,n)rep(j,1,n)writell(p[i]^p[j]?s[j][i]:s[i][j],j==n?10:32);
    /*ref(S,0,1<<n){
        //rep(i,1,n)rep(j,1,n)writell((S>>(i-1)&1)^(S>>(j-1)&1)?s[j][i]:s[i][j],j==n?10:32);
        rep(i,1,n)rep(j,1,n){
            cll a=p[i]^p[j]?s[j][i]:s[i][j],b=(S>>(i-1)&1)^(S>>(j-1)&1)?s[j][i]:s[i][j];
            if(a!=b){
                assert(a<b);
                goto s;
            }
        }
        s:;
    }*/
}
int main(){
    rep(i,1,T)calc();
    return 0;
}
/*
8 9 1 6 6 4
9 5 7 1 8 7
2 0 2 7 9 1
6 4 0 6 0 1
9 4 2 1 9 1
7 7 2 5 5 9

8 9 1 6 6 4
9 5 0 1 4 7
2 7 2 0 9 1
6 4 7 6 1 5
9 8 2 0 9 1
7 7 2 1 5 9

*/