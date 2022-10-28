#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int MOD=1e9+7;
 
 
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
 
int fact[500000];
int ifact[500000];
int C(int n, int k)
{
	return mul(fact[n], mul(ifact[k],  ifact[n - k]));
}
 
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	int ans=1;
	for(int i=1; i<=m; i++){
		ans=(ans*(2*(n+1)))%MOD;
	}
	ans=(ans*(n+1-m))%MOD;
	ans=(ans*(inv(n+1)))%MOD;
	cout<<ans<<endl;
	return 0;
}