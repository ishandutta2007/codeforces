#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
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
cll IO_res=(IO(),gc=getchar,0),T=1;
ll n,pop,flag;
typedef ll aNN[256][2025];
aNN x,y,z;
char s[1025];
ll b[2025],res[2025];
void cpy(aNN&a,const aNN&b,cll n,cll m,cll x,cll y){
    ref(i,0,n)memcpy(a[x+i]+y,b[i],m<<3);
}
ll query(cll*a){
    ref(i,0,n)pc(a[i]?'T':'F');
    pc(10),fout(),fflush(stdout);
    cll res=readll();
    /*ll res=0;
    ref(i,0,n)res+=(a[i]?'T':'F')==s[i];
    //writell(res,10);*/
    if(res==n)flag=1;
    return res;
}
ll getans(cll*a){
    ll p=0;
    ref(i,0,n)p+=a[i];
    p=(p-n+query(a)+pop)/2;
    //writell(p,10);
    return p;
}
void solve(ll*res,ll*b,ll l,ll q){
    //printf("l=%lld q=%lld\n",l,q);
    //ref(i,0,q)printf("%lld ",b[i]);puts("");
    if(q==1){
        *res=*b;
        return;
    }
    q/=2,l=(l-q)/2;
    rfor(ll*x=b,*y=b+q,*z=res+2*l;x!=b+q;){
        cll a=*x,b=*y,c=*z++=(a^b)&1;
        *x++=(a-c+b)/2,*y++=(a-c-b)/2;
    }
    //printf("l=%lld q=%lld\n",l,q);
    //ref(i,0,2*q)printf("%lld ",b[i]);puts("");
    solve(res,b,l,q),solve(res+l,b+q,l,q);
}
void solve(ll*res,ll*b,ll m,ll l,ll q){
    //printf("%lld %lld %lld\n",m,l,q);
    if(q==1){
        *res=*b;
        return;
    }
    q/=2,l=(l-q)/2,m-=l;
    //ref(i,0,m+l)printf("%lld %lld\n",i,b[i]);
    rfor(ll*x=b,*y=b+q;x!=b+q;){
        cll a=*x,b=*y;
        *x++=a+b,*y++=a-b;
    }
    solve(res+m,b+q,l,q);
    //ref(i,0,m+l)printf("%lld r=%lld\n",i,res[i]);
    //ref(i,0,2*q)printf("%lld %lld\n",i,b[i]);
    //printf("%lld %lld %lld\n",m,l,q);
    rfor(ll*x=b;x!=b+q;){
        rfor(ll*y=res+m,*z=::z[x-b]+m,*w=::z[x-b+q]+m;y!=res+m+l;)*x-=*y++*(*z+++*w++);
        *x++/=2;
    }
    //ref(i,0,m+l)printf("%lld r=%lld\n",i,res[i]);
    //ref(i,0,2*q)printf("%lld %lld\n",i,b[i]);
    solve(res,b,m,l,q);
}
void calc(){
    //cll n=::n=rand()%1000+1;
    cll n=::n=readll();
    //mygets(s);
    //ref(i,0,n)s[i]=rand()&1?'F':'T';
    s[n]=0,flag=0;
    //writell(n,10),myputs(s);
    memset(x[0],0,n<<3),pop=n-query(x[0]);
    if(pop==0)return;
    ll m=1,q=1,l=1;
    x[0][0]=z[0][0]=1;
    //           /[X X I][Y Y 0][Z X]\ _
    // (X,Y,Z)-> \[X Y 0][X Y 0][Z Y]/ 
    while(m<n){
        if(m+l<n){
            ref(i,0,q)x[i][i+2*l]=1;
            cpy(x,x,q,l,0,l);
            cpy(x,x,q,l,q,0);
            cpy(x,y,q,l,q,l);
            cpy(y,y,q,l,0,l);
            cpy(y,y,q,l,q,0);
            cpy(y,x,q,l,q,l);
        }
        cpy(z,x,q,l,0,m);
        cpy(z,z,q,l,q,0);
        cpy(z,y,q,l,q,m);
        m+=l,l=l*2+q,q*=2;
        //printf("%lld %lld %lld\n",m,l,q);
    }
    ref(i,0,q)if(b[i]=getans(z[i]),flag)return;
    memset(res,0,m<<3);
    solve(res,b,m,l,q),assert(query(res)==n);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}