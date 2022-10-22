#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3005;
const int mod=998244353;
int n,m;
int dp[N][N];
char a[N],b[N];
int main(){
	int i,j,k;
	cin>>(a+1)>>(b+1);
	while(a[n+1]) n++;
	while(b[m+1]) m++;
	for(i=0;i<=n;i++) dp[i+1][i]=1;
	for(i=1;i<=n;i++){
		for(j=1;j+i-1<=n;j++){
			int r=j+i-1;
			if(a[i]==b[j]||j>m)
				dp[j][r]=(dp[j][r]+dp[j+1][r])%mod;
			if(a[i]==b[r]||r>m)
				dp[j][r]=(dp[j][r]+dp[j][r-1])%mod;
		}
	}
	ll ans=0;
	for(i=m;i<=n;i++)
		ans=(ans+dp[1][i])%mod;
	cout<<ans;
	return 0;
}