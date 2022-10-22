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
struct bit{
    ll n,sum;aN f;void set(ll x){memset(f,sum=0,sizeof(ll)*((n=x)+1));}
    void update(ll u,ll c){sum+=c;while(u<=n)f[u]+=c,u+=u&-u;}
    ll query(ll u)const{ll res=0;while(u)res+=f[u],u&=u-1;return res;}
    ll find(ll k)const{ll u=0;rfor(ll i=1<<20;i;i>>=1)if(u+i<=n&&k>f[u+i])k-=f[u+=i];return u+1;}
}t1,t2;aN a;
int main(){
    const ll n=readll();ll sum=0;rep(i,1,n)a[readll()]=i;t1.set(n),t2.set(n);
    rep(i,1,n){
        t1.update(a[i],1),t2.update(a[i],a[i]);ll m=t1.find(-~i>>1),j=i>>1;
        printf("%lld ",(sum+=i-t1.query(a[i]))+t2.sum-t2.query(m)*2+(i&1?m:j)-j*-~j);
    }return 0;
}
/*
    ....o...o...o.o..o....
                ^
                m j=2
res=0000011102220201100000
res=0000011112222221100000
ans=0000011102220            
   =0000011112222
   -0000000010002
   =0000011111111
   +0000000001111
   -0000000010002
   =m*j-t2.query(m-1)-(1+...+j)
    ....o...o...o.o..o....o..
                ^
                m j=2\
   =    0   1   2 3  2    1
res=0000011102220302201111000
res=0000011112222332221111100
*/