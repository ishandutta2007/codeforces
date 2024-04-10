#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
void writell(ll u,int c=32){
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
const ll M=2222;
char s[M][M];
short h[M][M];
ll q[M];
template<typename T,typename T2>
int qm(T&a,T2 b){
    return a>b?a=b,1:0;
}
int main(){
    IO();
    ll n=readll()+1,m=readll()+1;
    rep(j,1,m)h[0][j]=h[n+1][j]=16384;
    rep(i,1,n){
        mygets(s[i]+1);
        rep(j,1,m)h[i][j]=s[i][j]=='1'?0:h[i-1][j]+1;
    }
    per(i,n,1)rep(j,1,m)qm(h[i][j],h[i+1][j]+1);
    //rep(i,1,n){rep(j,1,m)printf("%d ",h[i][j]);puts("");}
    ll sum=0;
    rep(s,1,n){
        struct{
            ll operator()(ll j,ll i){
                return(i-j)*(i-j)+h[s][j]*h[s][j];
            }
            const ll s;
        }f={s};
        struct{
            ll operator()(ll j){
                return j*j+h[s][j]*h[s][j];
            }
            const ll s;
        }y={s};
        ll h=1,t=0;
        rep(i,1,m){
            while(h<t&&(i-q[t-1])*y(q[t])>=(q[t]-q[t-1])*y(i)+(i-q[t])*y(q[t-1]))t--;
            q[++t]=i;
        }
        rep(i,1,m){
            while(h<t&&f(q[h],i)>=f(q[h+1],i))h++;
            sum+=f(q[h],i);
            //printf("%lld %lld\n",q[h],i);
        }
    }
    writell(sum);
    return 0;
}