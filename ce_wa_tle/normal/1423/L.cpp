#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef unsigned long long ull;const ll N=216333,e7=1e7+7,inf=1e17,mod=1e9+7;typedef ll aN[N];
ll iabs(ll a){return a<0?-a:a;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct bitset{
    const static ll N=18,k=137,mod=1e9+7,m=1e9+9;
    ull val[N];void reset(){memset(val,0,sizeof val);}void set(ll u){val[u>>6]|=1llu<<(u&63);}
    bitset operator^(const bitset&b)const{bitset f;f=*this;ref(i,0,N)f.val[i]^=b.val[i];return f;}
    void print(ll n,int ch='\n')const{ref(i,0,n)printf("%lld",val[i>>6]>>(i&63)&1);ch&&putchar(ch);}
    ull gethash()const{ull res=0;ref(i,0,N)res=res*m+val[i]+7;res%=inf;return res;}
}f[3][1027],res;
struct hash{
    const static ll mod=19260817;
    #define hss ll now=b%mod,k=0;while(key[now]&&key[now]!=b)now=(now+2*k+++1)%mod
    ll val[mod];ull key[mod];int count(ull b)const{hss;return!!key[now];}
    ll operator[](ull b)const{hss;return key[now]?val[now]:0;}
    ll&operator[](ull b){hss;return!key[now]?key[now]=b,val[now]:val[now];}
}hs;void qmin(ll&a,ll b){if(a>b)a=b;}ll p[1027];
int main(){
    ll n=readll(),s=readll(),d=readll();ll h[]{[0]=s/3,[1]=(s+1)/3,[2]=(s+2)/3};ref(S,1,(1<<h[2]))p[S]=p[S>>1]+(S&1);
    ref(j,0,3)ref(i,0,h[j]){f[j][1<<i].reset();ll k=readll();rep(s,1,k)f[j][1<<i].set(readll()-1);}
    ull nowhs;ref(j,0,3)ref(S,1,(1<<h[j]))if(S&~-S)f[j][S]=f[j][S&-S]^f[j][S&~-S];
//    ref(j,0,3)ref(S,0,(1<<h[j]))printf("f[%lld][%lld]=",j,S),f[j][S].print(n);
    ref(S,0,(1<<h[0]))ref(T,0,(1<<h[1]))nowhs=(f[0][S]^f[1][T]).gethash(),
    hs.count(nowhs)?qmin(hs[nowhs],p[S]+p[T]),0:hs[nowhs]=p[S]+p[T];//,printf("hs["),((f[0][S]^f[1][T])).print(4,0),printf("]=%lld\n",hs[nowhs]);
    
    rep(i,1,d){(void)n;
        res.reset();ll k=readll();rep(s,1,k)res.set(readll()-1);//res.print(4);
        ll ans=inf,nowhs;ref(S,0,(1<<h[2]))nowhs=(res^f[2][S]).gethash(),hs.count(nowhs)?qmin(ans,hs[nowhs]+p[S]):void(0);
        printf("%lld\n",ans<inf?ans:-1);
    }return 0;
}
//    ll gethash()const{printf("hs["),print(4,0),printf("]=");ll res=0;ref(i,0,N)res=(res*k+val[i]%m+1)%mod;printf("%lld\n",res);return res;}