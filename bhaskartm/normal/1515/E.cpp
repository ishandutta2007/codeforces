#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=405;
int dp[N][N];
int po[N];
int n, M;

int add(int x, int y)
{
	return (x + y) % M;
}
 
int sub(int x, int y)
{
	return add(x, M - y);
}
 
int mul(int x, int y)
{
	return (x * y) % M;
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
	return binpow(x, M - 2);
}
 
int fact[N];
int ifact[N];

int C(int n, int k){
	if(k>n || k<0){
		return 0;
	}
	return mul(fact[n], mul(ifact[k],  ifact[n - k]));
}

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>M;
	
	po[0]=1;
	
	for(int i=1; i<N; i++){
		po[i]=(po[i-1]*2)%M;
	}
	
	fact[0]=1;
	for(int i=1; i<N; i++){
		fact[i]=mul(i, fact[i-1]);
	}
	for(int i=0; i<N; i++){
		ifact[i]=inv(fact[i]);
	}
	
	for(int i=0; i<N; i++){
		for(int gap=0; gap<=i; gap++){
			if(i==0){
				dp[i][gap]=1;
				continue;
			}
			for(int j=1; j<=i+1; j++){
				if(j==(i+1)){
					if(gap!=0){
						continue;
					}
					else{
						dp[i][0]=po[i];
						continue;
					}
				}
				if(j==i){
					continue;
				}
				if(gap==0 && j!=(i+1)){
					continue;
				}
				if(i-j-1>=0){
					dp[i][gap]=(dp[i][gap]+((dp[i-j-1][gap-1]*po[j-1])%M)*C(i+1-gap, j))%M;
				}
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<=n; i++){
		ans=(ans+dp[n-1][i])%M;
	}
	cout<<ans<<endl;
	
	return 0;
}