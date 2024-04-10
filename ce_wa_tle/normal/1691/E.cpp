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
cll N=1e6+7,mod=1e9+7,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
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
#define $1(x...)x
#define $2(x...)x
cll IO_res=IO(),T=readll();
void init(){
}
aN o,l,r;
struct node{
    ll id,w;
    operator ll()const{
        return w*2+(w==l[id]);
    }
}p[N];
void calc(){
    cll n=readll();
    ll t=0;
    rep(i,1,n)o[i]=readll(),l[i]=readll(),r[i]=readll()+1,p[++t]=(node){i,l[i]},p[++t]=(node){i,r[i]};
    std::sort(p+1,p+t+1);
    ll sum=0,lst=-1,lr=-1,a=0,b=0,g=-1;
    rep(i,1,t){
        cll u=p[i].id,c=o[u],y=p[i].w,z=l[u]^r[u]^p[i].w;
        //pc(y==r[u]?'-':'+'),pc(c?'r':'b'),writell(u);
        if(p[i].w==l[u]){
            c?a++:b++;
            g=std::max(g,z);
            if(a&&b)y>=lr&&++sum,lst=y,lr=std::max(g,lr),g=-1;
        }else{
            if(z>lst)sum++;
            c?a--:b--;
        }
        //writell(sum,10);
        //printf("%lld ",sum);
    }
    writell(sum,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}
/*
2
4
0 1 6
1 1 2
0 2 3
1 6 7
4
0 1 1
1 1 3
1 3 5
0 5 5
*/