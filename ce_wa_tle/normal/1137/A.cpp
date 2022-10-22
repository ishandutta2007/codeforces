#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=414514,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(){char c=getchar();for(;c<'A'||c>'z';c=getchar());return c;}
ll s[114514];
ll lm[1145],rm[1145],l[1145][1145],r[1145][1145],a[1145][1145];
int main(){
//    IO(5);
    ll n=readll(),m=readll();
    rep(i,1,n)rep(j,1,m)a[i][j]=readll();
    rep(i,1,n){
        rep(j,1,m)s[j]=a[i][j];
        std::sort(s+1,s+m+1),lm[i]=std::unique(s+1,s+m+1)-s-1;
        rep(j,1,m)l[i][j]=std::lower_bound(s+1,s+lm[i]+1,a[i][j])-s;
    }
    rep(j,1,m){
        rep(i,1,n)s[i]=a[i][j];
        std::sort(s+1,s+n+1),rm[j]=std::unique(s+1,s+n+1)-s-1;
        rep(i,1,n)r[i][j]=std::lower_bound(s+1,s+rm[j]+1,a[i][j])-s;
    }
//    rep(i,1,n){rep(j,1,m)printf("%lld ",l[i][j]);puts("");}
//    rep(i,1,n){rep(j,1,m)printf("%lld ",r[i][j]);puts("");}
    rep(i,1,n){rep(j,1,m)printf("%lld ",std::max(l[i][j],r[i][j])+std::max(rm[j]-r[i][j],lm[i]-l[i][j]));puts("");}
	return 0;
}