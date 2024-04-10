#include<bits/stdc++.h>

using namespace std;

const int maxn=505;
const long long mdn=998244353;

long long dp[maxn][maxn];
int n,k;
long long cst[maxn];

int main(){
	cin>>n>>k;
	for(int i=0;i<=n;i++)dp[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j>=i)dp[i][j]=1;
			for(int k=0;k<=j;k++){
				if(i-k-1>=0)dp[i][j]+=dp[i-k-1][j];
				dp[i][j]%=mdn; 
			}
			//cerr<<i<<j<<dp[i][j]<<endl;
		}
	} 
	cst[0]=dp[n-1][0];
	for(int i=1;i<=n;i++){
		cst[i]=(dp[n-1][i]-dp[n-1][i-1]+mdn)%mdn;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i*j<k)ans=(ans+cst[i-1]*cst[j-1]*2)%mdn; 
		}
	}
	cout<<ans;
	return 0;
}