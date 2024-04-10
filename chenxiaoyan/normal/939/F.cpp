#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=100000,M=100;
int n,m;
int l[M+1],r[M+1];
int dp[2][2*N+1];
int q[2*N],head,tail;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",l+i,r+i);
	l[m+1]=2*n;
	memset(dp[0],0x3f,sizeof(dp[0]));
	dp[0][l[1]]=0;
	for(int i=1;i<=m;i++){
		int now=i&1,prv=!now;
		memset(dp[now],0x3f,sizeof(dp[now]));
		for(int j=0;j<=2*n;j++)dp[now][j]=min(dp[now][j],j-l[i+1]+l[i]<0?inf:dp[prv][j-l[i+1]+l[i]]);
		head=tail=0;
		for(int j=max(0,l[i]-2*n+l[i+1]-r[i]);j<-2*n+l[i+1];j++){
			while(head<tail&&dp[prv][q[tail-1]]>=dp[prv][j])tail--;
			q[tail++]=j;
		}
		for(int j=2*n;~j;j--){
//			cout<<j<<":\t+1=\t"<<l[i]-j+l[i+1]-r[i]<<"~"<<-j+l[i+1]<<"\n";
			while(head<tail&&q[head]<l[i]-j+l[i+1]-r[i])head++;
			if(-j+l[i+1]>=0){
				while(head<tail&&dp[prv][q[tail-1]]>=dp[prv][-j+l[i+1]])tail--;
				q[tail++]=-j+l[i+1];
			}
			dp[now][j]=min(dp[now][j],head==tail?inf:dp[prv][q[head]]+1);
		}
		head=tail=0;
		for(int j=max(0,-l[i+1]+l[i]);j<-l[i+1]+r[i];j++){
			while(head<tail&&dp[prv][q[tail-1]]>=dp[prv][j])tail--;
			q[tail++]=j;
		}
		for(int j=0;j<=2*n;j++){
//			cout<<j<<":\t+2=\t"<<j-l[i+1]+l[i]<<"~"<<j-l[i+1]+r[i]<<"\n";
			while(head<tail&&q[head]<j-l[i+1]+l[i])head++;
			if(j-l[i+1]+r[i]>=0){
				while(head<tail&&dp[prv][q[tail-1]]>=dp[prv][j-l[i+1]+r[i]])tail--;
				q[tail++]=j-l[i+1]+r[i];
			}
			dp[now][j]=min(dp[now][j],head==tail?inf:dp[prv][q[head]]+2);
		}
//		for(int j=0;j<=2*n;j++)printf("dp[%d][%d]=%d\n",i,j,dp[now][j]);
	}
	printf(dp[m&1][n]<inf?"Full\n%d\n":"Hungry",dp[m&1][n]);
	return 0;
}
/*1
10 2
3 5
11 13
*/
/*2
10 3
3 5
9 10
11 13
*/
/*3
20 1
3 19
*/
/*4
100000 2
60000 81999
120000 140000
*/