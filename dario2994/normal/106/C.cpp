#include <iostream>
using namespace std;

int n,m;
int a[20],b[20],c[20],d[20];
int dp[1010][12];

int main(){
	cin >> n >> m >> c[0] >> d[0];
	for(int i=1;i<=m;i++)cin >> a[i] >> b[i] >> c[i] >> d[i];
	for(int i=0;i<=n;i++)dp[i][0]=int(i/c[0])*d[0];
	for(int i=1;i<=m;i++)for(int p=0;p<=n;p++)for(int k=0;k*c[i]<=p and k*b[i]<=a[i];k++)dp[p][i]=max(dp[p][i],k*d[i]+dp[p-k*c[i]][i-1]);
	cout << dp[n][m];
}