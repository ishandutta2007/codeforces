#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define nxt y=(y+k[x]%2520+2520)%2520,x=to[x][y%m[x]]
typedef long long ll;const ll N=1e6+7,inf=0x3f3f3f3f3f3f3f3f,mod=998244353;typedef ll aN[N];
ll f[55][55][55][55];
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
	ll n=readll();rep(i,1,n)rep(j,1,n)f[i][i][j][j]=readchar('#','.')=='#';
	rep(h,1,n)rep(w,1,n)rep(li,1,n-h+1)rep(lj,1,n-w+1){
		ll ri=li+h-1,rj=lj+w-1;if(h!=1||w!=1)f[li][ri][lj][rj]=std::max(ri-li+1,rj-lj+1);
		rep(ki,li,ri-1)f[li][ri][lj][rj]=std::min(f[li][ri][lj][rj],f[li][ki][lj][rj]+f[ki+1][ri][lj][rj]);
		rep(kj,lj,rj-1)f[li][ri][lj][rj]=std::min(f[li][ri][lj][rj],f[li][ri][lj][kj]+f[li][ri][kj+1][rj]);
//		printf("f[%lld][%lld][%lld][%lld]=%lld\n",li,ri,lj,rj,f[li][ri][lj][rj]);
	}printf("%lld\n",f[1][n][1][n]);return 0; 
}