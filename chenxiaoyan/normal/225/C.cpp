#include<bits/stdc++.h>
using namespace std;
#define ppf pop_front()
#define ppb pop_back()
#define pb push_back
const int inf=0x3f3f3f3f;
const int N=1000,M=1000;
int n,m,l,r;
char a[N+1][M+5];
int Sum[M+1];
deque<int> q0,q1;
int dp[M+1][2];
int dp0_eq(int j){return dp[j][1]-n*j+Sum[j];}
int dp1_eq(int j){return dp[j][0]-Sum[j];}
int main(){
	scanf("%d%d%d%d",&n,&m,&l,&r);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int j=1;j<=m;j++){
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=a[i][j]=='.';
		Sum[j]=Sum[j-1]+cnt;
	}
	for(int i=1;i<=m;i++){
		while(q0.size()&&q0[0]<i-r)q0.ppf;
		if(i-l>=0){
			while(q0.size()&&dp0_eq(q0.back())>=dp0_eq(i-l))q0.ppb;
			q0.pb(i-l);
		}
		dp[i][0]=q0.size()?n*i-Sum[i]+dp0_eq(q0[0]):inf;
		while(q1.size()&&q1[0]<i-r)q1.ppf;
		if(i-l>=0){
			while(q1.size()&&dp1_eq(q1.back())>=dp1_eq(i-l))q1.ppb;
			q1.pb(i-l);
		}
		dp[i][1]=q1.size()?Sum[i]+dp1_eq(q1[0]):inf;
	}
	printf("%d",min(dp[m][0],dp[m][1]));
	return 0;
}
/*1
6 5 1 2
##.#.
.###.
###..
#...#
.##.#
###..
*/
/*2
2 5 1 1
#####
.....
*/