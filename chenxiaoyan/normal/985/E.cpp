#include<bits/stdc++.h>
using namespace std;
const int N=500000;
int n,m,lim;
int a[N+1];
int q[N],head,tail;
bool dp[N+1];
int main(){
	cin>>n>>m>>lim;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	dp[0]=true;
	for(int i=1;i<=n;i++){
		if(i-m>=0){
			while(head<tail&&dp[q[tail-1]]<=dp[i-m])tail--;
			q[tail++]=i-m;
		}
		while(head<tail&&a[i]-a[q[head]+1]>lim)head++;
		dp[i]=head<tail&&dp[q[head]];
//		printf("dp[%d]=%d\n",i,dp[i]);
	}
	puts(dp[n]?"YES":"NO");
	return 0;
}
/*1
6 3 10
7 2 7 7 4 2
*/
/*2
6 2 3
4 5 3 13 4 10
*/
/*3
3 2 5
10 16 22
*/