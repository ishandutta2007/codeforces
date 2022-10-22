/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2000,H=2000;
int dp[N+1][H];
int n,h,l,r;
int a[N+1];
bool in(int x){return l<=x&&x<=r;}
int main(){
	cin>>n>>h>>l>>r;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<h;i++)dp[0][i]=-inf;
	for(int i=1;i<=n;i++)for(int j=0;j<h;j++)
		dp[i][j]=max(dp[i-1][(j-a[i]+h)%h]+in(j),dp[i-1][(j-a[i]+1+h)%h]+in(j));
	cout<<*max_element(dp[n],dp[n]+h);
	return 0;
}