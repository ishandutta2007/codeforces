/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200000;
char a[N+5],b[N+5];
bool dp[N+1][2];
void mian(){
	int n;
	cin>>n>>a+1>>b+1;
	for(int i=0;i<=n;i++)dp[i][0]=dp[i][1]=false;
	dp[0][0]=true;
	for(int i=1;i<=n;i++){
		if(a[i]<='2')dp[i][0]|=dp[i-1][0];
		if(b[i]>'2'&&a[i]>'2')dp[i][0]|=dp[i-1][1];
		if(b[i]<='2')dp[i][1]|=dp[i-1][1];
		if(a[i]>'2'&&b[i]>'2')dp[i][1]|=dp[i-1][0];
	}
	puts(dp[n][1]?"YES":"NO");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}