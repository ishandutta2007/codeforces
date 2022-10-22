#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=555555,inf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(){char c=getchar();for(;c<'A'||c>'z';c=getchar());return c;}
ll getans(ll x,ll y,ll k){
//    printf("f(%lld,%lld,%lld)=",x,y,k);
    ll lx=(x&-x)<(y&-y)?std::swap(x,y),x&(x-1):x&(x-1);
//    printf("%lld %lld\n",x,lx);
    ll ans=(lx=((lx^(y-1))&-(x&-x))+1)<=k?x=std::min(k,lx+(x&-x)-1),(lx+x)*(x-lx+1)/2%mod*(y&-y)%mod:0;
//    printf("%lld %lld %lld\n",ans,x,lx);
    return ans;
}
    /*
      1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
      2  1  4  3  6  5  8  7 10  9 12 11 14 13 16 15 18 17 20 19
      3  4  1  2  7  8  5  6 11 12  9 10 15 16 13 14 19 20 17 18
      4  3  2  1  8  7  6  5 12 11 10  9 16 15 14 13 20 19 18 17
      5  6  7  8  1  2  3  4 13 14 15 16  9 10 11 12 21 22 23 24
      6  5  8  7  2  1  4  3 14 13 16 15 10  9 12 11 22 21 24 23
      7  8  5  6  3  4  1  2 15 16 13 14 11 12  9 10 23 24 21 22
      8  7  6  5  4  3  2  1 16 15 14 13 12 11 10  9 24 23 22 21
      9 10 11 12 13 14 15 16  1  2  3  4  5  6  7  8 25 26 27 28
     10  9 12 11 14 13 16 15  2  1  4  3  6  5  8  7 26 25 28 27
     11 12  9 10 15 16 13 14  3  4  1  2  7  8  5  6 27 28 25 26
     12 11 10  9 16 15 14 13  4  3  2  1  8  7  6  5 28 27 26 25
     13 14 15 16  9 10 11 12  5  6  7  8  1  2  3  4 29 30 31 32
     14 13 16 15 10  9 12 11  6  5  8  7  2  1  4  3 30 29 32 31
     15 16 13 14 11 12  9 10  7  8  5  6  3  4  1  2 31 32 29 30
     16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1 32 31 30 29
     17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32  1  2  3  4
     18 17 20 19 22 21 24 23 26 25 28 27 30 29 32 31  2  1  4  3
     19 20 17 18 23 24 21 22 27 28 25 26 31 32 29 30  3  4  1  2
     20 19 18 17 24 23 22 21 28 27 26 25 32 31 30 29  4  3  2  1
    */
ll solve(ll x,ll y,ll k){ll ans=0;rfor(ll i=x;i;i&=i-1)rfor(ll j=y;j;j&=j-1)ans=(ans+getans(i,j,k))%mod;return ans;}
int main(){
//    IO(!);
//    rep(i,1,20){rep(j,1,20)printf("%3lld",-~(~-i^~-j));puts("");}
    rfor(ll T=readll();T;T--){
        ll x1=readll()-1,y1=readll()-1,x2=readll(),y2=readll(),k=readll();
        printf("%lld\n",(solve(x1,y1,k)+solve(x2,y2,k)-solve(x1,y2,k)-solve(x2,y1,k)+mod+mod)%mod);
    }
    return 0;
}
//110000
//1~100000
//100001~110000