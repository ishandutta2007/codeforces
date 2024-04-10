#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=21;
int n;
int arr[N][N];
int p[N][N];
int ip[N][N];



const int MOD=31607;
 
 
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

vector<vector<bool>>che;
vector<vector<int>>dp;


int hor[N];
int num[N][N];


int fu(int i, int ms, int ind){
	if(che[i][ms]){
		return dp[i][ms];
	}
	che[i][ms]=1;
	
	if(ind!=-1){
		if(ind==0){
			for(int j=0; j<n; j++){
				num[j][j]++;
				if(num[j][j]==1){
					hor[j]=(hor[j]*ip[j][j])%MOD;
				}
			}
		}
		else if(ind==1){
			for(int j=0; j<n; j++){
				num[j][n-j-1]++;
				if(num[j][n-j-1]==1){
					hor[j]=(hor[j]*ip[j][n-j-1])%MOD;
				}
			}
		}
		else{
			for(int j=0; j<n; j++){
				num[j][ind-2]++;
				if(num[j][ind-2]==1){
					hor[j]=(hor[j]*ip[j][ind-2])%MOD;
				}
			}
		}
	}
	if(i==(n+2)){
		dp[i][ms]=1;
		for(int j=0; j<n; j++){
			dp[i][ms]=(dp[i][ms]*(1-hor[j]+MOD))%MOD;
		}
		if(ind!=-1){
		if(ind==0){
			for(int j=0; j<n; j++){
				num[j][j]--;
				if(num[j][j]==0){
					hor[j]=(hor[j]*p[j][j])%MOD;
				}
			}
		}
		else if(ind==1){
			for(int j=0; j<n; j++){
				num[j][n-j-1]--;
				if(num[j][n-j-1]==0){
					hor[j]=(hor[j]*p[j][n-j-1])%MOD;
				}
			}
		}
		else{
			for(int j=0; j<n; j++){
				num[j][ind-2]--;
				if(num[j][ind-2]==0){
					hor[j]=(hor[j]*p[j][ind-2])%MOD;
				}
			}
		}
	}
		return dp[i][ms];	
	}
	int pr=1;
	if(i==0){
		for(int j=0; j<n; j++){
			if(num[j][j]==0){
				pr=(pr*p[j][j])%MOD;
			}
		}
	}
	else if(i==1){
		for(int j=0; j<n; j++){
			if(num[j][n-j-1]==0){
				pr=(pr*p[j][n-j-1])%MOD;
			}
		}
	}
	else{
		for(int j=0; j<n; j++){
			if(num[j][i-2]==0){
				pr=(pr*p[j][i-2])%MOD;
			}
		}
	}
	dp[i][ms]=(((fu(i+1, ms, -1)-(fu(i+1, ms|(1<<i), i)*pr))%MOD)+MOD)%MOD;
	if(ind!=-1){
		if(ind==0){
			for(int j=0; j<n; j++){
				num[j][j]--;
				if(num[j][j]==0){
					hor[j]=(hor[j]*p[j][j])%MOD;
				}
			}
		}
		else if(ind==1){
			for(int j=0; j<n; j++){
				num[j][n-j-1]--;
				if(num[j][n-j-1]==0){
					hor[j]=(hor[j]*p[j][n-j-1])%MOD;
				}
			}
		}
		else{
			for(int j=0; j<n; j++){
				num[j][ind-2]--;
				if(num[j][ind-2]==0){
					hor[j]=(hor[j]*p[j][ind-2])%MOD;
				}
			}
		}
	}
	return dp[i][ms];
}
 
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	
	dp.resize(n+3);
	che.resize(n+3);
	
	for(int i=0; i<=n+2; i++){
		dp[i].resize((1<<i));
		che[i].resize((1<<i));
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
			
			p[i][j]=mul(arr[i][j], inv(10000));
			
			ip[i][j]=inv(p[i][j]);
		}
	}
	
	for(int i=0; i<n; i++){
		hor[i]=1;
		for(int j=0; j<n; j++){
			hor[i]=(hor[i]*p[i][j])%MOD;
		}
	}
	
	cout<<(1-fu(0, 0, -1)+MOD)%MOD<<endl;
	
	return 0;
}