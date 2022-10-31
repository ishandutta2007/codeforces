#include<bits/stdc++.h>
#define int long long
const int N=150,M=10050,mod=998244353;
using namespace std;

double f[N]; 
int c[N];
double dp[N][M];
int n,x,s;

void solve(){
	cin>>n>>x;
	for(int i=1;i<=n;i++)cin>>c[i],s+=c[i];
	for(int i=1;i<=n;i++)
		f[i]=(1.*n/i+1)/2*x;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j;j--)
			for(int k=s;k>=c[i];k--)
				dp[j][k]+=dp[j-1][k-c[i]]*j/(n-j+1);
	double ans=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=s;j++)
			if(dp[i][j])
				ans+=dp[i][j]*min(f[i],1.*j/i);
	printf("%.12lf",ans)
;}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}