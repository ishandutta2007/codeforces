#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e3+5;
const int mod=1e9+7;
int n,m,k;
int dp[N][N];
double pd[N][N];
inline int po(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m>>k;
		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++)
				dp[i][j]=pd[i][j]=0;
		for(i=1;i<=n;i++){
			for(j=0;j<=i&&j<=m;j++){
				if(j==0){
					pd[i][j]=pd[i-1][j];
					dp[i][j]=dp[i-1][j];
				}
				else if(j==i){
					pd[i][j]=pd[i-1][j-1]+k;
					dp[i][j]=(dp[i-1][j-1]+k)%mod;
				}
				else{
					if(pd[i-1][j-1]+k+k>=pd[i-1][j]){
						dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*ll(mod+1>>1)%mod;
						pd[i][j]=(pd[i-1][j-1]+pd[i-1][j])/2;
					}
					else{
						pd[i][j]=pd[i-1][j-1]+k;
						dp[i][j]=(dp[i-1][j-1]+k)%mod;
					}
				}
			}
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}