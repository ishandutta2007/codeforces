#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double


const int MOD=1e9+7;
int cons; 
 
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
	return (x * y) % MOD;
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

const int N=2005;

bool che[N][N];
int dp[N][N];

int fu(int n, int m){
	m=min(n, m);
	if(n==m){
		return n;
	}
	if(m==0){
		return 0;
	}
	if(che[n][m]){
		return dp[n][m];
	}
	che[n][m]=1;
	dp[n][m]=mul(cons, add(fu(n-1, m), fu(n-1, m-1)));
	return dp[n][m];
}



 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	cons=inv(2);
	while(t--){
		int n, m, k;
		cin>>n>>m>>k;
		cout<<mul(k, fu(n, m))<<endl;
	}
	
	return 0;
}