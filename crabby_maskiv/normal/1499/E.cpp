#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5;
const int mod=998244353;
int n,m;
char a[N],b[N];
int wa[N],wb[N];
int dp[N][N][2];
int main(){
	int i,j;
	cin>>(a+1)>>(b+1);
	n=strlen(a+1);m=strlen(b+1);
	int ans=0;
	for(i=1;i<=n;i++){
		if(a[i]!=a[i-1]) wa[i]=wa[i-1]+1;
		else wa[i]=1;
	}
	for(i=1;i<=m;i++){
		if(b[i]!=b[i-1]) wb[i]=wb[i-1]+1;
		else wb[i]=1;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i]!=b[j]){
				dp[i][j][0]=wb[j];
				dp[i][j][1]=wa[i];
			}
			if(a[i]!=a[i-1]) dp[i][j][0]=(dp[i][j][0]+dp[i-1][j][0])%mod;
			if(a[i]!=b[j]) dp[i][j][0]=(dp[i][j][0]+dp[i-1][j][1])%mod;
			if(b[j]!=b[j-1]) dp[i][j][1]=(dp[i][j][1]+dp[i][j-1][1])%mod;
			if(b[j]!=a[i]) dp[i][j][1]=(dp[i][j][1]+dp[i][j-1][0])%mod;
			ans=(ans+dp[i][j][0])%mod;
			ans=(ans+dp[i][j][1])%mod;
		}
	}
	cout<<ans;
	return 0;
}