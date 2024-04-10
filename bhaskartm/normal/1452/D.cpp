#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=998244353;
int dp[200005];
int ev[200005];
int od[200005];


int add(int x, int y)
{
	return (x + y) % N;
}
 
int sub(int x, int y)
{
	return add(x, N - y);
}
 
int mul(int x, int y)
{
	return (x * 1ll * y) % N;
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
	return binpow(x, N - 2);
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[1]=1;
	dp[2]=1;
	ev[2]=1;
	od[1]=1;
	for(int i=3; i<=200000; i++){
		if(i%2==1){
			dp[i]=(1+ev[i-1])%N;
			od[i]=(od[i-2]+dp[i])%N;
		}
		else{
			dp[i]=od[i-1];
			ev[i]=(dp[i]+ev[i-2])%N;
		}
	}
	int n;
	cin>>n;
	cout<<mul(dp[n], inv(binpow(2, n)));
	return 0;
}