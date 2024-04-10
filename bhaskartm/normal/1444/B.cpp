#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int MOD=998244353;


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
	fact[0]=1;
	ifact[0]=1;
	for(int i=1; i<500000; i++){
		fact[i]=mul(i, fact[i-1]);
		ifact[i]=inv(fact[i]);
	}
	
	int n;
	cin>>n;
	int arr[2*n];
	for(int i=0; i<2*n; i++){
		cin>>arr[i];
	}
	sort(arr, arr+2*n);
	int sum=0;
	for(int i=n; i<2*n; i++){
		sum+=arr[i];
	}
	for(int i=0; i<n; i++){
		sum-=arr[i];
	}
	sum=sum%MOD;
	cout<<mul(sum, C(2*n, n))<<endl;
	
	
	return 0;
}