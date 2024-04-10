#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
typedef long long ll;
ll dp[2003][4005],ans=1e15;
int MAXN=2000;
int main(){
	for (int i=0;i<2003;i++)for(int j=0;j<4005;j++)dp[i][j]=1e15;
	int n;read(n);
	dp[0][MAXN]=0;
	for (int i=1;i<=n;i++){
		int t,c;read(t),read(c);
		for (int j=0;j<4005;j++){
			if (j>0) dp[i][j-1]=min(dp[i][j-1],dp[i-1][j]);
			dp[i][min(4004,j+t)]=min(dp[i-1][j]+c,dp[i][min(4004,j+t)]);
		}
	}
	for (int i=MAXN;i<4005;i++) ans=min(ans,dp[n][i]);
	cout<<ans;
}