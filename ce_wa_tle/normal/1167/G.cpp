#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef unsigned long long ull;const ll N=1e6+7,mod=1e9+7,inf=1e18;typedef ll aN[N];aN a;
const double p2=3.1415926535897932384626/2;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
#define log safdsafdsa
struct hash{
    #define hs ull now=b%mod,x=0;if(!b)now=0;else while(now&&key[now]&&key[now]!=b)now=(now+2*x+++1)%mod
    static const ull mod=1e6+7;ull val[mod],key[mod];int count(ull b)const{hs;return key[now]==b;}
    ull operator[](ull b)const{hs;return key[now]==b?val[now]:0;}
    ull&operator[](ull b){hs;return key[now]!=b?key[now]=b,val[now]=0:val[now];}
}log,t;void print(ull x,ll w){rep(i,1,w)putchar((x&1)^48),x>>=1;}
struct bitset{
    ll h,d,n,w,lst;ull val[222];void set(ll d_,ll n_,ll w_){d=d_,n=n_,w=w_,lst=-d,h=0;}
    void set(ll x){if(x>d||x<0)return;val[x>>6]|=1ull<<(x&63);}
    void left(ll x){
        ll di=-x>>6|63ull<<58,w=-x&63;per(i,d>>6,0)
        val[i]=(i+di>=0?val[i+di]>>w:0)|(i+di+1>=0&&w?val[i+di+1]<<(64-w):0);val[d>>6]&=((1ull<<(d&63))-1)<<1|1;
    }void right(ll x){
        ll di=x>>6,w=x&63,up=d>>6;rep(i,0,up)val[i]=(i+di<=up?val[i+di]>>w:0)|(i+di+1<=up&&w?val[i+di+1]<<(64-w):0);
    }void update(ll x){
        if(w==-1)for(left(x-lst),lst=x;h<n&&a[h+1]<=x;set(x-a[++h]));
        else for(right(x-lst),lst=x;h<n&&a[h+1]-x<=d;set(a[++h]-x));
    }void print()const{rep(i,0,(d>>6)-1)::print(val[i],64);::print(val[d>>6],d&63);}
}t1,t2;//,cs;
ll lowbitofor(const bitset&a,const bitset&b){
    ull x;rep(i,0,(a.d>>6))if((x=a.val[i]|b.val[i]))return i<<6|log[x&-x];return inf;
}ll lowbitofand(const bitset&a,const bitset&b){
    ull x;rep(i,0,(a.d>>6))if((x=a.val[i]&b.val[i]))return i<<6|log[x&-x];return inf;
}int main(){
    rep(i,0,63)log[1ull<<i]=i;//cs.set(128,0,0);cs.set(0),cs.set(64),cs.print(),puts(""),cs.left(63),cs.print(),puts("");
    const ll n=readll(),d=readll();ll top=0,x;rep(i,1,n)x=readll(),t[a[++top]=x]++,t[a[++top]=x+1]++;
    std::sort(a+1,a+top+1);top=std::unique(a+1,a+top+1)-a-1;t1.set(d,top,-1),t2.set(d,top,1);const ll m=readll();
    rep(s,1,m)x=readll(),t1.update(x),t2.update(x),//t1.print(),putchar(' '),t2.print(),putchar(' '),
    printf("%.15lf\n",t[x]?t[x]*p2:double(std::max(atan2(1,lowbitofor(t1,t2)),2*atan2(1,lowbitofand(t1,t2)))));return 0; 
}