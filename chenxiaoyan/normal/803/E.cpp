/*








*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000,M=1000,ASCII=150;
int n,m;
char a[N+5];
bool dp[N+1][2*M+1];
char pa[N+1][2*M+1];
int Delta[150],let[3]={'L','D','W'};
int main(){
	Delta['W']=1;Delta['L']=-1;
	cin>>n>>m>>a+1;
	dp[0][0+m]=true;
	for(int i=1;i<=n;i++)for(int j=-m+(i<n);j<=m-(i<n);j++)
		if(a[i]!='?')dp[i][j+m]=dp[i-1][max(-m,min(m,j-Delta[a[i]]))+m],pa[i][j+m]=a[i];
		else
			for(int k=-1;k<=1;k++)
				if(dp[i-1][max(-m,min(m,j-k))+m])
					dp[i][j+m]=true,pa[i][j+m]=let[k+1];
	if(!dp[n][-m+m]&&!dp[n][m+m])return puts("NO"),0;
	int nowj=-m+m;
	if(!dp[n][-m+m])nowj=m+m;
	string ans;
	for(int i=n;i;i--){
//		printf("\npa[%d][%d]=%c\n",i,nowj,pa[i][nowj]);
		ans+=pa[i][nowj];
		nowj-=Delta[pa[i][nowj]];
	}
	reverse(ans.begin(),ans.end());cout<<ans;
	return 0;
}