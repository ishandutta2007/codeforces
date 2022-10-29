#include <bits/stdc++.h>
using namespace std;
long long int dp[205][205][205];
long long  int MOD = 1000000007;
const  int N = 205;

long long int add(long long int x, long long int y)
{
	return (x + y) % MOD;
}

long long int sub(long long int x, long long int y)
{
	return add(x, MOD - y);
}

long long int mul(long long int x, long long int y)
{
	return (x * 1ll * y) % MOD;
}

long long int binpow(long long int x, long long int y)
{
	long long int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}

long long int inv(int x)
{
	return binpow(x, MOD - 2);
}

long long int fact[205];

long long int C(long long int n, long long int k)
{
	return mul(fact[n], inv(mul(fact[k], fact[n - k])));
}


int main() {
	long long 	int n;
	fact[0] = 1;
	for(int i = 1; i <= N; i++)
		fact[i] = mul(i, fact[i - 1]);
	cin>>n;
	string s;
	cin>>s;
	long long int val2=mul(inv(n+1), C(2*n, n));
	if(s.size()==1){
		cout<<val2<<endl;
		return 0;
	}
	long long int val[s.size()];
	for(int i=0; i<s.size(); i++){
		val[i]=0;
	}
	for(int i=0; i<s.size()-1; i++){
		string t;
		for(int j=0; j<=i; j++){
			t=t+s[j];
		}
		if(s[i+1]=='('){
			t=t+')';
		}
		else{
			t=t+'(';
		}
		
		for(int l=1; l<=i+1; l++){
			if(s.substr(0, l)==t.substr(i-l+2, l)){
				
				val[i]=l;
			}
		}
	}
	
	int l=s.size();
	if(s[0]=='('){
		dp[0][1][1]=1;
	}
	else{
		dp[0][1][0]=1;
	}
	

	for(int i=0; i<(2*n); i++){
		for(int j=0; j<(2*n+1); j++){
			for(int k=0; k<s.size(); k++){
				
				if(j==0){
					if(k==l-1 && s[l-1]=='('){
						continue;
					}
					if(k==l-1 && s[l-1]==')'){
						dp[i+1][j+1][val[l-2]]+=dp[i][j][k];
						dp[i+1][j+1][val[l-2]]=(dp[i+1][j+1][val[l-2]])%MOD;
						continue;
					}
					if(s[k]=='('){
						dp[i+1][j+1][k+1]+=dp[i][j][k];
						dp[i+1][j+1][k+1]=(dp[i+1][j+1][k+1])%MOD;
						continue;
					}
					if(s[k]==')' && k==0){
						dp[i+1][j+1][0]+=dp[i][j][k];
						dp[i+1][j+1][0]=(dp[i+1][j+1][0])%MOD;
						continue;
					}
					if(s[k]==')'){
						dp[i+1][j+1][val[k-1]]+=dp[i][j][k];
						dp[i+1][j+1][val[k-1]]=(dp[i+1][j+1][val[k-1]])%MOD;
						continue;
					}
				}
				else{
					if(k==l-1 && s[k]=='('){
						dp[i+1][j-1][val[k-1]]+=dp[i][j][k];
						dp[i+1][j-1][val[k-1]]=(dp[i+1][j-1][val[k-1]])%MOD;
						continue;
					}
					if(k==l-1 && s[k]==')'){
						
						dp[i+1][j+1][val[k-1]]+=dp[i][j][k];
						dp[i+1][j+1][val[k-1]]=(dp[i+1][j+1][val[k-1]])%MOD;
						continue;
					}
					if(s[k]=='('){
						dp[i+1][j+1][k+1]+=dp[i][j][k];
						dp[i+1][j+1][k+1]=(dp[i+1][j+1][k+1])%MOD;
						if(k!=0){
						dp[i+1][j-1][val[k-1]]+=dp[i][j][k];
						dp[i+1][j-1][val[k-1]]=(dp[i+1][j-1][val[k-1]])%MOD;
						}
						if(k==0){
							dp[i+1][j-1][0]+=dp[i][j][k];
							dp[i+1][j-1][0]=(dp[i+1][j-1][0])%MOD;
						}
						continue;
					}
					if(s[k]==')'){
						if(k!=0){
						dp[i+1][j+1][val[k-1]]+=dp[i][j][k];
						dp[i+1][j+1][val[k-1]]=(dp[i+1][j+1][val[k-1]])%MOD;
						}
						if(k==0){
							dp[i+1][j+1][0]+=dp[i][j][k];
							dp[i+1][j+1][0]=(dp[i+1][j+1][0])%MOD;
						}
						dp[i+1][j-1][k+1]+=dp[i][j][k];
						dp[i+1][j-1][k+1]=(dp[i+1][j-1][k+1])%MOD;
						continue;
					}
				}
			}
		}
	}
	
	long long int ans=0;
	for(int i=0; i<l; i++){
		ans=add(ans, dp[2*n-1][0][i]);
	}
	cout<<sub(val2,ans);
	return 0;
}