#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int N=150000,M=300;
int n,m,s;
int q[N],head,tail;
int dp[2][N+1];
signed main(){
	cin>>n>>m>>s;
	int lastim=0;
	for(int i=1;i<=m;i++){
		int pos,cst,tim;
		cin>>pos>>cst>>tim;
		head=tail=0;
		for(int j=1;j<=(tim-lastim)*s&&j<=n;j++){
			while(head<tail&&dp[i-1&1][q[tail-1]]<=dp[i-1&1][j])tail--;
			q[tail++]=j;
		}
		for(int j=1;j<=n;j++){
			while(head<tail&&q[head]<j-(tim-lastim)*s)head++;
			if(j+(tim-lastim)*s<=n){
				while(head<tail&&dp[i-1&1][q[tail-1]]<=dp[i-1&1][j+(tim-lastim)*s])tail--;
				q[tail++]=j+(tim-lastim)*s;
			}
			dp[i&1][j]=head<tail?dp[i-1&1][q[head]]+cst-abs(pos-j):-inf;
		}
		lastim=tim;
//		for(int j=1;j<=n;j++)printf("dp[%lld][%lld]=%lld\n",i,j,dp[i][j]);
	}
	cout<<*max_element(dp[m&1]+1,dp[m&1]+n+1);
	return 0;
}
/*1
50 3 1
49 1 1
26 1 4
6 1 10
*/
/*2
10 2 1
1 1000 4
9 1000 4
*/
/*3
30 8 2
15 97 3
18 64 10
20 14 20
16 18 36
10 23 45
12 60 53
17 93 71
11 49 85
*/