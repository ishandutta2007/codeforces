/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000;
int n,m;
char a[N+5];
int q[N],head,tail;
int dp[N+1];
signed main(){
	cin>>n>>m>>a+1;
	for(int i=1;i<1+m;i++)
		if(a[i]=='1'){
			while(head<tail&&q[tail-1]>=i)tail--;
			q[tail++]=i;
		}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+i;
		while(head<tail&&q[head]<i-m)head++;
		if(i+m<=n&&a[i+m]=='1'){
			while(head<tail&&dp[max(0ll,q[tail-1]-m-1)]+q[tail-1]>=dp[max(0ll,i-1)]+i+m)tail--;
			q[tail++]=i+m;
		}
		if(head<tail)dp[i]=min(dp[i],dp[max(0ll,q[head]-m-1)]+q[head]);
//		printf("dp[%lld]=%lld\n",i,dp[i]);
	}
	cout<<dp[n];
	return 0;
}
/*1
5 2
00100
*/ 
/*2
6 1
000000
*/ 
/*3
4 1
0011
*/
/*4
12 6
000010000100
*/
/*5
14 2
00001101011000
*/