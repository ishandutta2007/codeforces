#include<bits/stdc++.h>
using namespace std;
#define N 100
#define LET 26
#define mp make_pair
#define X first
#define Y second
#define inf 0x3f3f3f3f
char s[N+1];
int dp[N+1][N+1][LET],val[LET][LET];
int main(){
	int n,m,t,i,j,k;scanf("%s%d%d",s+1,&m,&t);n=strlen(s+1);
	while(t--){
		char a[3],b[3];int c;scanf("%s%s%d",a,b,&c);
		val[a[0]-'a'][b[0]-'a']=c;
	}
	fill(dp[1][0],dp[n][m]+LET,-inf);
	for(i=0;i<LET;i++)for(j=s[1]!='a'+i;j<=m;j++)dp[1][j][i]=0;
	for(i=2;i<=n;i++)dp[i][0][s[i]-'a']=dp[i-1][0][s[i-1]-'a']+val[s[i-1]-'a'][s[i]-'a'];
	for(i=2;i<=n;i++)for(j=1;j<=m;j++)for(k=0;k<LET;k++)for(int o=0;o<LET;o++)
		dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-(s[i]!='a'+k)][o]+val[o][k]);
//	for(i=1;i<=n;i++)for(j=1;j<=m;j++)for(k=0;k<LET;k++)
//		printf("dp[%d][%d][%c]=%d\n",i,j,'a'+k,dp[i][j][k]);
	printf("%d",*max_element(dp[n][0],dp[n][m]+LET));
	return 0;
}
/*1
winner 4
4
s e 7
o s 8
l o 13
o o 8
*/
/*2
abcdef 1
5
a b -10
b c 5
c d 5
d e 5
e f 5
*/