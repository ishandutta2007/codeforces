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
ll f[88][3222][88];
aN p,q,ans;
int qm(ll&a,ll b){
    return a>b?a=b,1:0;
}
int main(){
    IO();
    ll n=readll(),t=0;
    rep(i,1,n)if(readll())p[++t]=i;
    memset(f,0x3f,sizeof f);
    f[0][0][0]=0;
    rep(x,1,t){
        rep(s,0,(n-x)*x){
            const ll*lst=f[x-1][s];
            struct y_t{
                ll operator()(ll x)const{
                    return lst[x]+x*x+3*x;
                }
                const ll*lst;
            }y={lst};
            struct{
                ll operator()(ll j,ll i)const{
                    return y(j)-2*i*j+i*i-3*i+2;
                }
                const y_t&y;
            }w={y};
            ll h=1,t=0;
            rep(i,1,n){
                #define check(a,b,c)y(b)*(c-a)>=y(a)*(c-b)+y(c)*(b-a)
                if(lst[i-1]<f[0][0][1]){
                    while(h<t&&check(q[t-1],q[t],(i-1)))t--;
                    q[++t]=i-1;
                }
                while(h<t&&w(q[h],i)>=w(q[h+1],i))h++;
                //ref(j,0,i)qm(f[x][s+llabs(p[x]-i)][i],w(j,i));
                if(h<=t)qm(f[x][s+llabs(p[x]-i)][i],w(q[h],i));
            }
        }
    }
    //rep(x,0,t)rep(s,0,(n-x)*x)rep(i,0,n)printf("f[%lld][%lld][%lld]=%lld\n",x,s,i,f[x][s][i]);
    rep(y,0,(n-t)*t)rep(i,1,n)ans[y]=std::max(ans[y],(n-t)*(n-t-1)/2-f[t][y][i]/2-(n-i)*(n-i-1)/2);
    rep(i,0,n*(n-1)/2)writell(ans[i]=std::max(ans[i],i?ans[i-1]:0));
    return 0;
}