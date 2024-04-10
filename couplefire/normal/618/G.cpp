#include<bits/stdc++.h>
using namespace std;
const int N=102;
double f[N][N],g[N][N],dp[N][N],sum[N]; int n,k,q; double p;
struct matrix{
	double f[N][N];
}gt,f1,f2;
inline matrix operator * (matrix a,matrix b){
	matrix c=gt;
	for(int i=1;i<=q+1;i++)
		for(int j=1;j<=q+1;j++)
			for(int k=1;k<=q+1;k++) c.f[i][k]=c.f[i][k]+a.f[i][j]*b.f[j][k];
	return c;
}
int main(){
	cin>>n>>k,q=100,p=k/1000000000.0;
	for(int i=1;i<=q;i++) f[i][1]=p; f[1][2]=1-p,f[2][2]=1-p+p*p;
	for(int i=2;i<=q;i++) f[i][2]=f[2][2],g[i][2]=1-p;
	for(int i=1;i<=q;i++)
		for(int j=3;j<=q;j++) f[i][j]=f[i][j-1]*f[i-1][j-1];
	g[1][2]=1-p;
	for(int i=2;i<=q;i++)
		for(int j=3;j<=q;j++) g[i][j]=g[i][j-1]*f[i-1][j-1];
	for(int i=q;i>=1;i--)
		for(int j=1;j<=q;j++) f[i][j]=f[i][j]*(1-f[i-1][j]),g[i][j]=g[i][j]*(1-f[i-1][j]);
	for(int i=1;i<=q;i++){
		for(int j=2;j<=i+1;j++){
			double zt=0; 
			for(int k=1;k<j;k++){
				zt+=f[i-1][k];
			}
			if(zt==0){
				dp[i][j]=j; continue;
			}
			for(int k=1;k<j;k++){
				dp[i][j]=dp[i][j]+dp[i-1][k]*f[i-1][k]/zt;
			}
			dp[i][j]+=j;
		}
		double zt=0;
		for(int k=2;k<=q;k++) zt+=g[i-1][k];
		if(zt==0){
			dp[i][1]=1; continue;
		}
		for(int k=2;k<=q;k++) dp[i][1]=dp[i][1]+dp[i-1][k]*g[i-1][k]/zt;
		dp[i][1]+=1;
	}
	double ans=0;
	if(n<=q){
		for(int i=1;i<=q;i++) ans=ans+dp[n][i]*f[n][i];
		printf("%.15lf\n",ans); 
	}
	else{
		
		for(int j=2;j<=q;j++){
			double zt=0;
			for(int k=1;k<j;k++) zt+=f[q][k];
			for(int k=1;k<j;k++)
				f1.f[k][j]=f[q][k]/zt;
			f1.f[q+1][j]=j;
		}
		double zt=0;
		for(int i=2;i<=q;i++) zt+=g[q][i];
		for(int k=2;k<=q;k++) f1.f[k][1]=g[q][k]/zt;
		f1.f[q+1][1]=1,f1.f[q+1][q+1]=1;
		bool fg=0; n-=q;
		while(n>0){
			if(n&1){
				if(!fg) fg=1,f2=f1;
				else f2=f1*f2;
			}
			f1=f1*f1,n=n>>1;
		}
		dp[q][q+1]=1; double ans=0;
		for(int i=1;i<=q+1;i++)
			for(int j=1;j<=q;j++) sum[j]=sum[j]+dp[q][i]*f2.f[i][j];
		for(int i=1;i<=q;i++) ans=ans+sum[i]*f[q][i];
		printf("%.15lf\n",ans); 
	}
}