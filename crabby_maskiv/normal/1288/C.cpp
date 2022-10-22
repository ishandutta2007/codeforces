#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+5;
const int mod=1e9+7;
int n,m;
int C[N][N];
int main(){
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			if(j==0||j==i) C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	cin>>n>>m;
	int ans=0;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			ans=(ans+1ll*C[i+m-2][m-1]*C[n-j+m-1][m-1])%mod;
		}
	}
	cout<<ans;
	return 0;
}