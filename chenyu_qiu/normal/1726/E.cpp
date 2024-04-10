#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
using namespace std;
const int N=1e6,inf=1e18,mod=998244353,inv2=(mod+1)/2;
int n,f[N],fac[N],Pw[N],inv[N],invfac[N];
int C(int x,int y) {
	return fac[x]*invfac[y]%mod*invfac[x-y]%mod;
}
void Clear(){
}
void solve(){
	cin >> n;
	f[0]=1;
	for(int i=1;i<=n;i++) {
		f[i]=(f[i-1]+f[i-2]*(i-1))%mod;
	}
	int ans=0,pw=1;
	for(int i=0;i*4<=n;i++) {
		int x=f[n-i*4];
		x=x*C(n-2*i,i*2)%mod;
		x=x*pw%mod;
		ans=(ans+x*fac[i*2]%mod*Pw[i]%mod*invfac[i])%mod;
		pw=pw*2%mod;
	}
	cout << ans << "\n";
}
signed main()
{
	fac[0]=inv[1]=fac[1]=invfac[0]=invfac[1]=1;
	Pw[0]=1,Pw[1]=inv2;
	for(int i=2;i<=N-1;i++) {
		Pw[i]=Pw[i-1]*inv2%mod;
		fac[i]=fac[i-1]*(i)%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		invfac[i]=invfac[i-1]*inv[i]%mod;
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	cin >> T;
	while(T--){
		solve();
		Clear();
	}
	return 0;
}