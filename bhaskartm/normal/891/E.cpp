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
const int N=5005;
int arr[N];

int n, k;

 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>k;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	
	vector<int>vec;
	
	vec.pb(arr[1]);
	vec.pb(-1);
	
	for(int i=2; i<=n; i++){
		vector<int>ne;
		ne.pb((-vec.back()+MOD)%MOD);
		for(int j=vec.size()-1; j>=1; j--){
			ne.pb((vec[j]*arr[i]-vec[j-1]+MOD)%MOD);
		}
		ne.pb((arr[i]*vec[0])%MOD);
		reverse(ne.begin(), ne.end());
		vec=ne;
	}
	
	int ans=0;
	int cons=inv(n);
	for(int j=0; j<=n; j++){
		int val=vec[j];
		for(int i=0; i<j; i++){
			val=(val*cons)%MOD;
		}
		for(int i=0; i<j; i++){
			val=(val*(k-i))%MOD;
		}
		ans=(ans+val)%MOD;
	}
	int val1=1;
	for(int i=1; i<=n; i++){
		val1=(val1*arr[i])%MOD;
	}
	ans=(val1-ans+MOD)%MOD;
	cout<<ans<<endl;
	
	return 0;
}