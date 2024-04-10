/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=5000;
int n,m;
char a[N+5];
int dp[N+1][N+1];
int main(){
//	freopen("a.in","r",stdin);
	cin>>a+1;
	n=strlen(a+1);
	m=log2(n);
	for(int i=0;i<1<<m;i++)dp[i][i]=true;
	for(int i=1;i<=n-(1<<m)+1;i++){
		int mn=inf;
		for(int j=i;j<i+(1<<m);j++)if(dp[j-1][j-i])mn=min(mn,int(a[j]));
		for(int j=i;j<i+(1<<m);j++)dp[j][j-i]=dp[j-1][j-i]&&a[j]==mn;
		for(int j=i;j<i+(1<<m);j++)
			for(int k=0;k<m;k++)if(j-i&1<<k)
				dp[j][j-i]|=dp[j-(1<<k)][j-i^1<<k];
		putchar(mn);
	}
	return 0;
}