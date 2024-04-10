#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=422222,inf=1e18,mod=998244353;typedef ll aN[N];aN a,v,r,c,tr,tc;
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct nd{ll x1,y1,x2,y2;void print()const{printf("%lld %lld %lld %lld\n",x1,y1,x2,y2);}}ans[N];ll top=0;
int main(){
    ll n=readll();rep(i,1,n)tr[r[i]=readll()]=i;rep(i,1,n)tc[c[i]=readll()]=i;
    rep(i,1,n)(c[i]!=i||r[i]!=i)&&(ans[++top]=(nd){i,tc[i],tr[i],i},0),tr[r[tr[i]]=r[i]]=tr[i],tc[c[tc[i]]=c[i]]=tc[i];
    printf("%lld\n",top);rep(i,1,top)ans[i].print();return 0;
}