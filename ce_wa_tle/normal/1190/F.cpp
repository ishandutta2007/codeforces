#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef long double ld;const ll N=422222;typedef ll aN[N];aN a;ll n,k;int v[11111111];
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
typedef unsigned long long ull;typedef unsigned short us;const ll pr[]={2,3,5,7,11,13,17,19,37};
inline ll mul(ull a,ull b,ll p){a%=p,b%=p;ll c=a*b-(ull)((long double)a/p*b)*p;c%=p;return c<0?c+p:c;}
inline ll pow(ll a,ll b,ll p){ll res=1;while(b){if(b&1)res=mul(res,a,p);a=mul(a,a,p),b>>=1;}return res;}
inline int MR(ll n){
    if(n==1||!(n&1))return n==2;ll u=n-1,c=0;while((u&1)==0)u>>=1,++c;
    rep(p,0,8){
        ll a=pow(pr[p],u,n),b=0;if(a==1||a==n-1||a==0)continue;
        rep(i,1,c-1)if((a=mul(a,a,n))==n-1){b=1;break;}else if(a==1)return 0;if(!b)return 0;
    }/*printf("%lld is prime\n",n);*/return 1;
}inline ll f(ll x,ll c,ll p){return(c+mul(x,x,p))%p;}inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
#define ur (us)rand()
inline ll random(){const us p[]={ur,ur,ur,ur};ull res=0;memcpy(&res,p,sizeof res);return res>>1;}
#define rand() random()
inline ll PR(ll n,ll check=-1){
	if(~check?MR(n):check)return n;if(n==4)return 2;
    while(1)rfor(ll c=rand()%(n-3)+3,x=f(0,c,n),y=f(x,c,n),lim=1,g,cnt;cnt=1,x!=y;lim<128&&(lim<<=1)){
        rep(i,1,lim){ll nxt=mul(cnt,(x+n-y)%n,n);if(!nxt)break;cnt=nxt,x=f(x,c,n),y=f(f(y,c,n),c,n);if(x==y)break;}
        if((g=gcd(cnt,n))!=1)return g;
    }
}inline ll fj(ll*res,ll n,ll t=0){ll fs=0;if(MR(n))res[++t]=n;else fs=PR(n,0),t=fj(res,fs,fj(res,n/fs,t));return t;}
inline void getyz(ll n,ll*p,ll&top){n!=1?top=fj(p,n),std::sort(p+1,p+top+1),top=std::unique(p+1,p+top+1)-p-1:top=0;}
inline void multi_getyz(ll n,ll*p,ll&top){if(n==1){top=0;return;}top=fj(p,n);std::sort(p+1,p+top+1);}
inline ll getphi(ll n,const ll*p=0,ll top=0){
    static ll sp[70];if(!p)getyz(n,sp,top),p=sp;ll now=n;rep(i,1,top)now=now/p[i]*(p[i]-1);return now;
}inline ll getroot(ll n,ll phi=0,const ll*p=0,ll top=0){
    if(!phi)phi=getphi(n);static ll sp[70];if(!p)getyz(phi,sp,top),p=sp;//printf("%lld %lld\n",phi,top);exit(0);
    rep(i,2,n){ll flag=1;rep(j,1,top)if(pow(i,phi/p[j],n)==1){flag=0;break;}if(flag)return i;}return -1;
}inline ll getord(ll n,ll a,ll phi=0,const ll*p=0,ll top=0){
    if(!phi)phi=getphi(n);static ll sp[70];if(!p)multi_getyz(phi,sp,top),p=sp;//printf("n=%lld\n",n);
    ll now=phi,ans=phi;rep(i,1,top){now=p[i]==p[i-1]?now/p[i]:phi/p[i];if(pow(a,now,n)==1)ans/=p[i];}return ans;
}int main(){
    ll n=readll(),m=readll(),k=readll(),yz[70],top;getyz(m,yz,top);ll p=yz[1],phi=getphi(m,yz,top),ord;//printf("%lld %lld\n",p,phi);
    if(k%p==0){if(n+1>phi)return puts("-1"),0;rep(i,2,m)if(i%p){printf("%lld ",i);if(!--n)break;}return 0;}
    if((ord=getord(m,k,phi))+n>phi)return puts("-1"),0;if(m<=1e7){ll now=1;rep(i,1,phi){v[now]=1;
    if((now=mul(now,k,m))==1)break;}rep(i,1,m)if(i%p&&!v[i]){printf("%lld ",i);if(!--n)break;}return 0;}//exit(0); 
    if(!(m&1)&&(k&3)==1){rep(i,1,n)printf("%lld ",4*i+3);return 0;}ll g=m&1?getroot(m,phi):5;//if(~m&1)ord/=2;printf("%lld %lld %lld %lld\n",g,ord,getord(m,mul(k,k,m)),mul(k,k,m)%4);exit(0);
    ll now=1,v=phi/ord;rep(i,1,phi){now=mul(now,g,m);if(i%v==0)continue;printf("%lld ",now);if(!--n)break;}return 0; 
}//if m=2^x k=4f+3 |{ans}|=phi/2 ord_k2=ordk/2 v=phi/ord_k