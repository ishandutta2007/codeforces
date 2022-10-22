#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=2e5+9,mod=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
char ss[N];aN s;
struct hash{
    int val[N*120],jl[N];ll cnt;hash():cnt(0){}
    int&operator[](ll b){return val[jl[++cnt]=b];}
    void clear(){while(cnt)val[jl[cnt--]]=0;}
//    const static ll mod=19260817;ll val[mod],key[mod],jl[mod];ll cnt;hash():cnt(0){}
//    void clear(){while(cnt)key[jl[cnt--]]=0;}
//    #define fd ll now=(b?b%mod+mod:b=192608167)%mod,k=0;while(key[now]&&key[now]!=b)now=(now+2*k+++1)%mod
//    int count(ll b)const{fd;return!!key[now];}ll operator[](ll b)const{fd;return key[now]?val[now]:0;}
//    ll&operator[](ll b){fd;return!key[now]?key[now]=b,val[jl[++cnt]=now]=0:val[now];}
}hs;
int main(){//IO(1270F);
    scanf("%s",ss+1);const ll n=strlen(ss+1),t=std::max(1ll,(ll)sqrt(n)/4);ll sum=0;rep(i,1,n)s[i]=s[i-1]+(ss[i]^48);//fprintf(stderr,"%lld %lld\n",sum,t);
    rep(d,1,t){hs.clear();rep(i,0,n)sum+=hs[d*s[i]+n-i]++/*,printf("%lld %lld ",sum,i-d*s[i]);puts("")*/;}fprintf(stderr,"%ld\n",clock());//exit(0);
    rep(g,1,n/t){ll r=1,l=0;rep(i,0,n){if(s[n]-s[i]<g||n-i<g*t)break;while(r<n&&s[r+1]-s[i]<=g)r++;
    while(l<n&&s[l+1]-s[i]<g)l++;if(r-i>=g*t)sum+=(r-i)/g-std::max((l-i)/g,t);}}fprintf(stderr,"%ld\n",clock());printf("%lld\n",sum);
    return 0;
}