#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define N 5000
#define M 5000
double p[N+1],dp[N+1][M+1],sum[N+2];
int t[N+1];
double power(double x,int y){
	double res=1.0;
	while(y){
		if(y&1)res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}
int main(){
//	freopen("C:\\Users\\chenx\\OneDrive\\\\txt.txt","r",stdin);
	int n,m,i,j;scanf("%d%d",&n,&m);
	double ans=0.0;
	for(i=1;i<=n;i++)scanf("%lf%d",p+i,t+i),p[i]*=0.01;
	dp[0][0]=1.0;
	for(i=1;i<=n;i++){
		for(j=1;j<t[i];j++)
			dp[i][j]=
				dp[i][j-1]*(1.0-p[i])+
				dp[i-1][j-1]*p[i];
		double po=power(1.0-p[i],t[i]);
		dp[i][t[i]]=
			dp[i][t[i]-1]*(1.0-p[i])+
			dp[i-1][t[i]-1]*p[i]+
			po*dp[i-1][0];
		for(j=t[i]+1;j<=m;j++)
			dp[i][j]=
				dp[i][j-1]*(1.0-p[i])+
				dp[i-1][j-1]*p[i]+
				po*dp[i-1][j-t[i]]-
				po*dp[i-1][j-t[i]-1];
		for(j=1;j<=m;j++)sum[i]+=dp[i][j];
	}
	for(i=1;i<=n;i++)ans+=(sum[i]-sum[i+1])*i;
	printf("%.100lf",ans);
	return 0;
}
/*1
2 2
50 2
10 1
*/
/*2
2 2
0 2
100 2
*/
/*3
3 3
50 3
50 2
25 2
*/
/*4
2 2
0 2
0 2
*/