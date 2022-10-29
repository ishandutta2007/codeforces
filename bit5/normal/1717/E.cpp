#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1e5+7, mod=1e9+7;
ll gcd(ll a, ll b) {return b?gcd(b, a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, a=(ll)a*a%mod)
		if (b&1) res=(ll)res*a%mod;
	return res;
}
int n, s_p, pr[N], mu[N], v[N], f[N];
vector<int>fac[N];
inline void init() {
	mu[1]=1;
	for (int i=2; i<=n; i++) {
		if (!v[i]) v[i]=i, mu[i]=-1, pr[++s_p]=i;
		for (int j=1; j<=s_p && i*pr[j]<=n; j++) {
			v[i*pr[j]]=pr[j];
			if (i%pr[j]==0) break;
			mu[i*pr[j]]=-mu[i];
		}
	}
	for (int i=1; i<=n; i++)
		for (int j=i+i; j<=n; j+=i) fac[j].push_back(i);
}
signed main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	n=read(), init();
	for (int i=1; i<=n; i++) {
		ll res=0;
		for (int x:fac[i]) res+=(i/x-1)*mu[x];
		f[i]=(res%mod+mod)%mod;
	}
	ll ans=0;
	for (int a=1; a<n; a++) {
		int b=n-a;
		for (int x:fac[b]) {
			ll tmp=lcm(a, x)%mod*f[b/x]%mod;
			ans+=tmp, ans%=mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}