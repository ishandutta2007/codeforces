//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int f[100005][20];
long long o[100053],a[100009],n,c,dp[100005],h,hh;

int main()
{
	n=read(); c=read();
	for(int i=1; i<=n; ++i)f[i][0]=a[i]=read();
	
	for(int i=1; i<=n; ++i)o[i]=o[i-1]+a[i];
		
	for(int i=1; i<=18; ++i)
	for(int j=1; j<=n; ++j)if(j+(1<<(i-1))<=n){
		f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);  //N  oNlogn/diaoduilie
	}
	
	dp[0]=0;
	for(int i=1; i<=n; ++i){
		dp[i]=dp[i-1]+a[i];
		if(i>=c){
			h=log2(c+0.01); //n+0.01 //dou= int + 0.40.50.6
			hh=f[i-c+1][h];
			hh=min(hh,(long long)f[i-(1<<h)+1][h]);
			dp[i]=min(dp[i],dp[i-c]+o[i]-o[i-c]-hh);
		}
	}
	cout<<dp[n]<<endl;//()
}