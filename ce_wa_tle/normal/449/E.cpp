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
typedef const ull cull;
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
cll IO_res=IO(),n=readll(),up=1e6;
aN f,g,h,&p=f,&m=g,&s=h;
void qm(ll&a,cll b=mod){
    a>=b&&(a-=b);
}
int main(){
    ll*t=p;
    m[1]=1,s[1]=1;
    rep(i,2,up){
        if(!p[i])rfor(ll now=1,lst=1,j=*t++=i;j<=up;lst=j,j=j*i,now++)m[j]=1,s[j]=(j-lst)*now+j;
        rfor(ll*j=p,k;(k=i**j)<=up;j++){
            p[k]=1;
            if(i%*j==0){
                cll t=m[k]=m[i];
                s[k]=s[t]*s[k/t];
                break;
            }
            m[k]=i,s[k]=s[i]*s[*j];
        }
    }
    ll s0=0,s1=0,s2=0,s3=0;
    rep(i,1,up){
        cll sq=i*i%mod,now=(2*(s[i]+s0)+mod-sq)%mod;
        qm(s0+=sq),qm(s1+=now),s2=(s2+now*i)%mod,s3=(s3+now*sq)%mod,f[i]=s1,g[i]=s2,h[i]=s3;
    }
    rep(i,1,n){
        cll a=readll()+1,b=readll()+1,c=std::min(a,b)-1;
        writell((a*b%mod*f[c]+(mod-a-b)*g[c]+h[c])%mod,10);
    }
    return 0;
}