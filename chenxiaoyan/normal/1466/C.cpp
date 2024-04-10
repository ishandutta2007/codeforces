/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=100000;
int n;
char a[N+5];
int dp[2][27][27];
void mian(){
	cin>>a+1;
	n=strlen(a+1);
	for(int i=1;i<=1;i++)for(int j=0;j<=26;j++)for(int k=0;k<=26;k++)dp[i][j][k]=inf;
	dp[1][0][a[1]-'a'+1]=0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=26;j++)for(int k=0;k<=26;k++)dp[i&1][j][k]=inf;
		for(int j=0;j<=26;j++){
			vector<int> Mn(28,inf),mN(28,inf);
			Mn[0]=dp[i-1&1][0][j];
			for(int o=1;o<=26;o++)Mn[o]=min(Mn[o-1],dp[i-1&1][o][j]);
			for(int o=26;~o;o--)mN[o]=min(mN[o+1],dp[i-1&1][o][j]);
			for(int k=1;k<=26;k++)dp[i&1][j][k]=min(Mn[k-1],mN[k+1])+(a[i]-'a'+1!=k);
			dp[i&1][j][j]=inf;
		}
	}
	int ans=inf;
	for(int j=0;j<=26;j++)for(int k=0;k<=26;k++)ans=min(ans,dp[n&1][j][k]);
	cout<<ans<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}