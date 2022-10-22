#include<bits/stdc++.h>
using namespace std;
#define NPM 2000000
#define mod 1000000007
char s[NPM+10];
int dp[NPM+1],las[26];
int main(){
	int n,m,lim,i;scanf("%d%d%s",&m,&lim,s+1);n=strlen(s+1);
	dp[0]=1;
	for(i=1;i<=n;i++){
		dp[i]=(2ll*dp[i-1]-(las[s[i]-'a']?dp[las[s[i]-'a']-1]:0))%mod;if(dp[i]<0)dp[i]+=mod;
		las[s[i]-'a']=i;
	}
	for(i=n+1;i<=n+m;i++){
		int mn=0x3f3f3f3f;
		for(int j=0;j<lim;j++)if(las[j]<mn)mn=las[j],s[i]='a'+j;
		dp[i]=(2ll*dp[i-1]-(las[s[i]-'a']?dp[las[s[i]-'a']-1]:0))%mod;if(dp[i]<0)dp[i]+=mod;
		las[s[i]-'a']=i;
	}
	printf("%d",dp[n+m]);
	return 0;
}
/*1
1 3
ac
*/
/*2
0 2
aaba
*/