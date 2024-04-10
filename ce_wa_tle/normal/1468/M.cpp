#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef long double ld;const ld eps=1e-6,inf=1e9;const ll N=2e5+5,mod=1e9+7;typedef ll aN[N],aN16[N*16];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll s[N],size[N],*a[N],w[N];
struct hash{
    static const int mod=19260817,k=31;ll key[mod];int val[mod],fx[mod],cnt;hash():cnt(0){}
    void clear(){while(cnt)val[fx[cnt]]=key[fx[cnt]]=0,cnt--;}
    #define cl ll x=b%mod;while(key[x]&&key[x]!=b)x=x+k,x>=mod&&(x-=mod)
    int count(ll b)const{cl;return!!key[x];}int operator[](ll b)const{cl;return key[x]?val[x]:0;}
    int&operator[](ll b){cl;return!key[x]?key[x]=b,val[fx[++cnt]=x]:val[x];}
}hs;
int calc(int cases){
    ll n=readll(),m=0,x,cnt=0;rfor(ll i=1;i<=n&&(m+=size[i]=readll());a[i+1]=a[i]+size[i],i++)
    rep(j,1,size[i])x=readll(),a[i][j]=hs.count(x)?hs[x]:hs[x]=++cnt;
    ll d=std::min(50ll,(ll)sqrt(m));(void)cases;
    rep(i,1,n)if(size[i]>=d){
        rep(j,1,size[i])w[a[i][j]]=1;
        rep(j,1,n)if(j!=i){
            ll flag=0;rep(k,1,size[j])flag+=w[a[j][k]];
            if(flag>=2){rep(j,1,size[i])w[a[i][j]]=0;return printf("%lld %lld\n",i,j),1;}
        }rep(j,1,size[i])w[a[i][j]]=0;
    }else{
        rep(j,1,size[i])rep(k,1,size[i])if(j!=k){if(hs.count(x=a[i][j]*1e9+a[i][k]))
        return printf("%lld %lld\n",i,(ll)hs[x]),1;else hs[x]=i;}
    }puts("-1");return 0;
}
int main(){ll T=readll(),cnt=0;a[1]=s;while(T --> 0)calc(++cnt),hs.clear();return 0;}