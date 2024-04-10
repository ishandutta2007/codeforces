#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
int n,m;
int h[N][N];
bool f[N][N];
int a[N];
int dp[N];
int main(){
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) f[i][i]=1,h[i][i]=a[i];
	for(i=2;i<=n;i++){
		for(j=1;j+i-1<=n;j++){
			int r=j+i-1;
			for(k=j;k<r;k++){
				if(f[j][k]&&f[k+1][r]&&(h[j][k]==h[k+1][r]))
					f[j][r]=1,h[j][r]=h[j][k]+1;
			}
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			if(f[j][i])
				dp[i]=min(dp[i],dp[j-1]+1);
		}
	}
	cout<<dp[n];
	return 0;
}