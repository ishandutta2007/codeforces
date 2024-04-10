#include<bits/stdc++.h>
using namespace std;
double dp[5001][5001];
int p[5001],t[5001];
double mypow(double x,int y){
	double res=1;
	while(y){
		if(y&1)res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}
int main(){
	int n,T;
	cin>>n>>T;
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		cin>>p[i]>>t[i];
	double ans=0;
	for(int i=0;i<n;i++){
		double pp=p[i]*0.01;
		double now=0;
		double r2=mypow(1-pp,t[i]-1);
		double r=r2*pp;
		for(int j=0;j<T;j++){
			now*=(1-pp);
			now+=dp[i][j]*pp;
			if(j+1>=t[i]){
				now-=dp[i][j+1-t[i]]*r;
				dp[i+1][j+1]=now+dp[i][j+1-t[i]]*r2;
			}else{
				dp[i+1][j+1]=now;
			}
		}
		for(int j=0;j<=T;j++)ans+=dp[i+1][j];
	}
	printf("%.12f\n",ans);
}