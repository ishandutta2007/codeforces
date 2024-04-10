#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int
#define pb push_back

const int MOD = 998244353;
const int N = 500005;

int add(int x, int y)
{
	return (x + y) % MOD;
}

int sub(int x, int y)
{
	return add(x, MOD - y);
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

int inv(int x)
{
	return binpow(x, MOD - 2);
}

int fact[N];

int C(int n, int k)
{
	return mul(fact[n], inv(mul(fact[k], fact[n - k])));
}

main() {
	int n, k;
	cin>>n>>k;
	fact[0]=1;
	for(int i=1; i<=500000; i++){
		fact[i]=mul(fact[i-1], i);
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		int num=(n/i)-1;
		if(k-1>num){
			continue;
		}
		ans=add(ans, C(num, k-1));
		
	}
	cout<<ans;
	return 0;
}