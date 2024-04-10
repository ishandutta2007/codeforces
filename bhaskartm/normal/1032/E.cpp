#include <bits/stdc++.h>
using namespace std;
long long int dp[10005][105];
long long int dp2[10005][105];
const int N=1000000007;
int coun;
int cnt[105];


long long int binpow(long long int x, long long int y)
{
	long long int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = (z*x)%N;
		x = (x*x)%N;
		y /= 2;
	}
	return z;
}

long long int inv(long long int x)
{
	return binpow(x, N - 2);
}

long long int fact[102];

long long int C(long long int n, long long int k)
{
	return (fact[n]*inv((fact[k]*fact[n - k])%N))%N;
}


int main() {
	
	fact[0]=1;
	for(int i=1; i<102; i++){
		fact[i]=(fact[i-1]*i)%N;
	}
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(cnt[arr[i]]==0){
			coun++;
		}
		cnt[arr[i]]++;
		
	}
	if(coun<=2){
		cout<<n<<endl;
		return 0;
	}
	dp[arr[0]][1]=1;
	dp[0][0]=1;
	
	for(int i=1; i<n; i++){
		
		for(int w=1; w<=10000; w++){
			for(int count=1; count<=i+1; count++){
				
				if(w-arr[i]>=0){
					dp2[w][count]=dp[w-arr[i]][count-1];
				}
				
			}
		}
		for(int w=1; w<=10000; w++){
			for(int count=1; count<=i+1; count++){
				dp[w][count]=(dp[w][count]+dp2[w][count])%N;
				dp2[w][count]=0;
			}
		}
		
	}
	
	int ans=0;
	for(int i=1; i<=100; i++){
		for(int j=1; j<=cnt[i]; j++){
			if(dp[i*j][j]==C(cnt[i], j)){
				ans=max(ans, j);
			}
		}
	}
	cout<<ans;
	return 0;
}