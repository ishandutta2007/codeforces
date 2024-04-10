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
int fgc() {
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout() {
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c) {
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126) {
    if(l>r)std::swap(l,r);
    int c=gc();
    for(; c<l||c>r; c=gc());
    return c;
}
ll readll() {
    ll x=0,w=1;
    int c=gc();
    for(; c<48||c>57; c=gc())c-45||(w=-w);
    for(; c>47&&c<58; c=gc())x=x*10+c-48;
    return x*w;
}
void writell(ll u,int c=32) {
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u; n; n/=10)wt[++t]=n%10^48;
    for(t||pc(48); t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0) {
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10) {
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
char s[N],t[N];
ll c[22];
int qm(char&a,ll b) {
    return a>=b?a-=b,1:0;
}
ll qa(ll a,ll b) {
    return a<0?a+b:a;
}
static inline int check(int c) {
    return c==4||c==7;
}
#define debug {\
ll f=n,n=f;\
while(n&&!s[n])n--;\
while(n)pc(s[n--]^48);\
pc(10);\
}
void calc(const char*s_,ll n,ll t,ll*c) {
    static char s[N];
    memcpy(s+1,s_+1,n);
    ll cnt=0;
    rep(i,1,n)cnt+=check(s[i]);
    rep(i,1,t) {
        c[i]=cnt;
        ll t=1;
        while(s[t]==9)s[t++]=0;
        cnt-=check(s[t]),cnt+=check(++s[t]);
    }
}
static inline void cover(char*s,ll l,ll r,int a){
    if(l<=r)memset(s+l,a,r-l+1);
}
void getans(char*s,ll n,ll k) {
    assert(k<=6);
//    debug;
//    printf("%lld\n",k);
    calc(s,n,15,c);
    ll min=mod;
    rep(i,1,k)min=std::min(min,c[i]);//,printf("%lld\n",c[i]);
    rep(i,2,15-k+1) {
        ll flag=1;
        rep(j,1,k)if(c[i+j-1]!=c[j]) {
            flag=0;
            break;
        }
        if(flag) {
            rep(e,1,i-1) {
                ll t=1;
                while(s[t]==9)s[t++]=0;
                ++s[t];
            }
            return;
        }
    }
    if(k==1){
        ll now=c[1],lst_9=1;
        rep(i,1,n){
            now-=check(s[i]);
            while(lst_9<=i||s[lst_9]==9)lst_9++;
            rep(j,s[i]+1,9){
                ll num_4=min-now-check(j);
                if(num_4>=0&&num_4<=i-1){
                    cover(s,1,1+num_4-1,4),cover(s,1+num_4,i-1,0),s[i]=j;
                    return;
                }
            }
        }
    }
    ll f1=-1,f2=-1,m2=-1;
    rep(i,0,10-k) {
        ll flag=1,checki=check(i);
        rep(j,2,k)if(c[j]-c[1]!=check(j+i-1)-checki) {
//            printf("%lld %lld\n",i,j);
            flag=0;
            break;
        }
        if(flag){
            f1=i;
            break;
        }
    }
    rep(u,0,2){
        rep(i,11-k,9){ 
            ll flag=1,checki=check(i)+(u&1);
            rep(j,2,k)if(c[j]-c[1]!=check(j+i-1)+(u>>(j+i-1>=10)&1)-checki) {
                flag=0;
                break;
            }
            if(flag){
                f2=i,m2=u;
                break;
            }
        }
        if(~f2)break;
    }
//    printf("%lld %lld %lld %lld\n",k,f1,f2,m2);
//    puts("??");
    ll now=c[1]-check(s[2])-check(s[1]),lst_9=1;
    rep(j,s[2]+1,9){
        while(lst_9<=2||s[lst_9]==9)lst_9++;
        if(~f1&&check(j)+now==min){
            s[1]=f1,s[2]=j;
            return;
        }
        if(~f2&&check(j)+now==min+(m2&1)&&(j!=9?check(j+1):check(s[lst_9]+1)-check(s[lst_9]))+now==min+(m2>>1)){
            s[1]=f2,s[2]=j;
            return;
        }
    }
    rep(i,3,n){
        now-=check(s[i]);
        while(lst_9<=i||s[lst_9]==9)lst_9++;
        rep(j,s[i]+1,9){
//            printf("i=%lld j=%lld\n",i,j);
            ll num_4=min-now-check(j);
            if(~f1&&num_4>=0&&num_4<=i-2){
                s[1]=f1,cover(s,2,2+num_4-1,4),cover(s,2+num_4,i-1,0),s[i]=j;
                return;
            }
//            printf("i=%lld j=%lld\n",i,j);
            if(~f2&&num_4>=0&&num_4<=i-3){
                s[1]=f2,s[2]=m2==0?0:m2==1?4:3,cover(s,3,3+num_4-1,4),cover(s,3+num_4,i-1,0),s[i]=j;
                return;
            }
//            printf("i=%lld j=%lld\n",i,j);
            if(~f2&&check(j)+now==min+(m2&1)&&(j==9?check(s[lst_9]+1)-check(s[lst_9]):check(j+1))+now==min+(m2>>1)){
                s[1]=f2,cover(s,2,i,9),s[i]=j;
                return;
            }
        }
    }
}
void calc() {
    ll n=mygets(s+1),m=mygets(t+1);
    rep(i,1,n/2)std::swap(s[i],s[n-i+1]);
    rep(i,1,m/2)std::swap(t[i],t[m-i+1]);
    rep(i,1,n)s[i]-=48;
    rep(i,1,m)t[i]-=48;
    rep(i,n+1,m+1)s[i]=0;
    rep(i,m+1,n+1)t[i]=0;
    t[1]--;
    rep(i,1,n)qm(t[i]+=s[i],10)&&t[i+1]++,t[i]==-1&&(t[i]=9,t[i+1]--);
    t[n+1]&&++n,n=std::max(n,m)+1,s[n]=t[n]=0;
//    rep(i,1,n)printf("%d ",t[i]);puts("");
//    debug;
    if(qa((t[m+1]-s[m+1])*10+t[m]-s[m]+1,100)>6)m++;
    getans(s+m-1,n-m+1,qa((t[m+1]-s[m+1])*10+t[m]-s[m]+1,100));
    while(!s[n])n--;
    while(n)pc(s[n--]^48);
    pc(10);
}
int main() {
    IO();
    ll T=1;
    while(T--)calc();
    return 0;
}