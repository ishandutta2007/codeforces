#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5,P=1e9+7;
int n,res,dp[N][3][4],s[N][3][4],pw[N],ans;char str[N];
int main(){
	scanf("%d",&n);scanf("%s",str+1);
	pw[0]=1;for(int i=1;i<=n;i++)pw[i]=3LL*pw[i-1]%P;
	for(int i=1;i<=n;i++)if(str[i]=='?')res++;
	for(int i=1,now=0;i<=n;i++){
		if(str[i]=='a')dp[i][0][0]=1;
		else if(str[i]=='b')dp[i][1][0]=s[i-1][0][0],dp[i][1][1]=s[i-1][0][1];
		else if(str[i]=='c')dp[i][2][0]=s[i-1][1][0],dp[i][2][1]=s[i-1][1][1],dp[i][2][2]=s[i-1][1][2];
		else{
			dp[i][0][1]=1;
			dp[i][1][1]=s[i-1][0][0];dp[i][1][2]=s[i-1][0][1];
			dp[i][2][1]=s[i-1][1][0];dp[i][2][2]=s[i-1][1][1];dp[i][2][3]=s[i-1][1][2];
			now++;res--;
		}
		for(int j=0;j<=min(3,now);j++)ans=(ans+(LL)dp[i][2][j]*pw[now-j+res]%P)%P;
		for(int j=0;j<3;j++)for(int k=0;k<4;k++)s[i][j][k]=(s[i-1][j][k]+dp[i][j][k])%P;
	} 
	printf("%d\n",ans);
	return 0;
}