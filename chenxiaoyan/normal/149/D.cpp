#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int N=700,COLOR=3;
int n;
char s[N+1];
int mch[N+1];
int dp[N+2][N+1][COLOR][COLOR];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	stack<int> stk;
	for(int i=1;i<=n;i++)
		if(s[i]=='(')stk.push(i);
		else mch[stk.top()]=i,stk.pop();
//	for(int i=1;i<=n;i++)cout<<mch[i]<<" ";puts("");
	for(int i=n-1;i;i--)for(int j=i+1;j<=n;j++)for(int k=0;k<=2;k++)for(int o=0;o<=2;o++)
		if(mch[i]==j){
//			cout<<i<<" "<<j<<" dping\n";
			if(!!k+!!o!=1)continue;
			if(i+1==j){dp[i][j][k][o]=1;continue;}
			for(int p=0;p<=2;p++)for(int q=0;q<=2;q++)
				if(!(k&&k==p||o&&o==q))(dp[i][j][k][o]+=dp[i+1][j-1][p][q])%=mod;
		}
		else{
//			cout<<i<<" "<<j<<" dping\n";
			if(!mch[i]||mch[i]>j)continue;
			if(k)dp[i][j][k][o]=dp[i][mch[i]][k][0]*
			(1ll*dp[mch[i]+1][j][0][o]+dp[mch[i]+1][j][1][o]+dp[mch[i]+1][j][2][o])%mod;
			else dp[i][j][k][o]=(1ll*dp[i][mch[i]][k][1]*
			(dp[mch[i]+1][j][0][o]+dp[mch[i]+1][j][2][o])%mod+
			1ll*dp[i][mch[i]][k][2]*
			(dp[mch[i]+1][j][0][o]+dp[mch[i]+1][j][1][o])%mod)%mod;
		}
	int ans=0;
	for(int i=0;i<=2;i++)for(int j=0;j<=2;j++)(ans+=dp[1][n][i][j])%=mod;
	printf("%d",ans);
	return 0;
}
/*1
(())
*/
/*2
(()())
*/
/*3
()
*/