#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=2e6+9;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN d,l,x,y,q,m;ll p[N][4];
void solve(ll cases){
    ll n=readll(),t=0;rep(i,1,n)d[i]=l[i]=x[i]=y[i]=0;
    rep(i,1,n-2)rep(j,1,3)d[p[i][j]=readll()]++,x[i]^=p[i][j],y[p[i][j]]^=i;
    rep(i,1,n-2)rep(j,1,3);rep(i,1,n-2)rep(j,1,3)l[p[i][j]]^=p[i][j]^x[i];rep(i,1,n)if(d[i]==1)q[++t]=i;
    rfor(ll i=1,w,z;i<=n-2&&(w=m[i]=y[q[i]]);i++)rep(j,1,3)if(y[z=p[w][j]]^=w,1==--d[z])q[++t]=z;(void)cases;
    ll s1=q[1],s2=p[m[1]][1]==s1?p[m[1]][2]:p[m[1]][1];rep(i,1,n)printf("%lld ",s2),s1^=l[s2],std::swap(s1,s2);
    puts("");rep(i,1,n-2)printf("%lld ",m[i]);puts("");
}int main(){ll T=readll(),cnt=0;while(T --> 0)solve(++cnt);return 0;}