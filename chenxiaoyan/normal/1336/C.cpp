/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=3000;
int n,m;
char a[N+5],b[N+5];
int dp[N+1][N+1];
bool eq(char x,char y){return x==y||y=='?';}
int main(){
	cin>>a+1>>b+1;
	n=strlen(a+1);m=strlen(b+1);
	int old_m=m;
	while(m<n)b[++m]='?';
	for(int i=m;i;i--)for(int j=i;j<=m;j++){
		if(i==j){dp[i][j]=eq(a[1],b[i]);continue;}
		if(eq(a[j-i+1],b[i]))dp[i][j]=dp[i+1][j];
		if(eq(a[j-i+1],b[j]))(dp[i][j]+=dp[i][j-1])%=mod;
//		printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	}
	int ans=0;
	for(int i=old_m;i<=m;i++)(ans+=dp[1][i])%=mod;
	cout<<2*ans%mod;
	return 0;
}