//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define inv(x) ksm(x,mod - 2)

const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;

int n,k,ans;
int y[MAXN];
int a[MAXN],b[MAXN],cnt;

inline int ksm(int x,int b) {
	int res = 1;
	while(b) {
		if(b & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		b >>= 1;
	}
	return res;
}

signed main () {
	scanf("%lld%lld",&n,&k);
	for(register int i = 1;i <= min(n,k + 2); ++i)
		(y[i] = y[i - 1] + ksm(i,k)) %= mod;
	if(n <= k + 2) {printf("%lld\n",y[n]); return 0;}
	cnt = a[0] = b[0] = 1;
	for(register int i = 1;i <= k + 2; ++i) {
		(cnt *= (n - i) % mod) %= mod;
		(a[i] = a[i - 1] * i) %= mod;
		(b[i] = -b[i - 1] * i) %= mod;
	}
	for(register int i = 1;i <= k + 2; ++i) 
		(ans += y[i] * cnt % mod * inv(n - i) % mod * inv(a[i - 1] * b[k - i + 2] % mod) % mod + mod) %= mod;
	printf("%lld\n",(ans + mod) % mod);
	return 0;
}