#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll F[1010101], FI[1010101];
ll n, ans = 1;

ll pow(ll a, ll b)
{
	ll ret = 1;
	
	for(; b; b>>=1){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
	}
	
	return ret;
}

int main()
{
	ll i;
	
	scanf("%lld", &n);
	
	F[0] = 1;
	
	for(i=1; i<=n; i++){
		F[i] = F[i - 1] * i % mod;
	}
	
	FI[n] = pow(F[n], mod - 2);
	
	for(i=n-1; i>=1; i--){
		FI[i] = FI[i + 1] * (i + 1) % mod;
	}
	
	for(i=2; i<=n; i++){
		ans = (ans + (((n - i + 1) * (F[n] * FI[i] % mod) % mod) * (i - 1)) % mod) % mod;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}