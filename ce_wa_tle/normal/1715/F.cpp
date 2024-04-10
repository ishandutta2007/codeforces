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
typedef long double ld;
ld readld(){
    ll x=0,w=1;
    int c=gc();
    for(;c<48||c>57;c=gc())c-45||(w=-w);
    for(;c>47&&c<58;c=gc())x=x*10+c-48;
    ld y=0,z=0.1L;
    if(c=='.'){
        c=gc();
        for(;c>47&&c<58;c=gc())y=y+z*(c-48),z=z*0.1L;
    }
    return x*w+y;
}
cll IO_res=(IO(),gc=getchar,0),T=1;
void writeld(ld u,cll len,int c=32){
    int t=0;
    rfor(ull n=u<0?pc(45),u=-u:u;n;n/=10)wt[++t]=n%10^48;
    for(t||pc(48);t;)pc(wt[t--]);
    if(!len)return c&&pc(c),void();
    pc('.');
    u=u-(ll)u;
    rep(i,1,len)u*=10,pc((ll)u^48),u-=(ll)u;
    c&&pc(c);
}
const ld del=1.L/128;
ld wz(ld y){
    ld d=y*128,a=(ll)(d+1e-9L),b=a+(d-(ll)d>1e-9L);
    //printf("%.19Lf %.19Lf %.19Lf %.19Lf\n",y,d,a,b);
    return a+b*del;
}
ld getz(ld s){
    ld res=0;
    rep(i,1,100)res+=std::max(0.L,std::min(i+del*i,s+1)-std::max((ld)i,s));
    return res;
}
std::mt19937 rd;
void calc(){
    cll n=readll(),m=readll();
    ld x,y;
    //ld s=readld(),r=readld();
    //cll n=rd()%99+2,m=rd()%99+2;
    //ld s=rd()%((n-1)*1000000)/1000000.L,r=rd()%((m-1)*1000000)/1000000.L;
    if(n!=1){
        pc('?'),pc(32),writell(4*(n-1)+1,10);
        writeld(0,15),writeld(m+1,15,10);
        rep(i,1,n-1){
            writeld(i,15),writeld(m,15,10);
            writeld(i,15),writeld(0,15,10);
            writeld(i+del*i,15),writeld(0,15,10);
            writeld(i+del*i,15),writeld(m,15,10);
        }
        fout(),fflush(stdout);
        //x=/*wz(readld())*/wz(getz(s));
        x=wz(readld());
    }else x=1;
    pc('?'),pc(32),writell(4);
    writeld(0,15),writeld(m,15,10);
    writeld(0,15),writeld(0,15,10);
    writeld(x,15),writeld(0,15,10);
    writeld(x,15),writeld(m,15,10);
    fout(),fflush(stdout);
    //const ld ansx=/*x-readld();*/x-std::max(0.L,std::min(x,s+1)-std::max(0.L,s));
    const ld ansx=x-readld();
    
    if(m!=1){
        pc('?'),pc(32),writell(4*(m-1)+1,10);
        writeld(n+1,15),writeld(0,15,10);
        per(i,m-1,1){
            writeld(n,15),writeld(i+del*i,15,10);
            writeld(0,15),writeld(i+del*i,15,10);
            writeld(0,15),writeld(i,15,10);
            writeld(n,15),writeld(i,15,10);
        }
        fout(),fflush(stdout);
        //y=/*wz(readld());*/wz(getz(r));
        y=wz(readld());
    }else y=1;
    pc('?'),pc(32),writell(4);
    writeld(n,15),writeld(y,15,10);
    writeld(0,15),writeld(y,15,10);
    writeld(0,15),writeld(0,15,10);
    writeld(n,15),writeld(0,15,10);
    fout(),fflush(stdout);
    //const ld ansy=/*y-readld();*/y-std::max(0.L,std::min(y,r+1)-std::max(0.L,r));
    const ld ansy=y-readld();
    pc('!'),pc(32),writeld(ansx,15),writeld(ansy,15,10);
    fout(),fflush(stdout);
    //printf("%lld %lld %Lf %Lf %Lf %Lf\n",n,m,s,r,ansx,ansy);
    //assert(fabsl(ansx-s)<=1e-9);
    //assert(fabsl(ansy-r)<=1e-9);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}