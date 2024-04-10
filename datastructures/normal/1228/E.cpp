#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std; 
int n,m,f[305][305],sum[305][305],pw[2][100005];
int c[305][305];
inline int Qpow(int a,int p){
	if (a==m)return pw[0][p];
	return pw[1][p];
} 
signed main(){
	cin>>n>>m;
	pw[0][0]=pw[1][0]=1;
	for (register int i=1;i<=100000;i++)
		pw[0][i]=pw[0][i-1]*m%mod,pw[1][i]=pw[1][i-1]*(m-1)%mod;
	c[0][0]=1;
	for (int i=1;i<=n;i++){
		c[i][0]=1;
		for (int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			f[i][j]=Qpow(m,i*j);
			for (register int k=0;k<i;k++)
				f[i][j]=(f[i][j]-c[i][k]*sum[i-k][j]%mod*Qpow(m-1,k*j)%mod+mod)%mod;
			f[i][j]=(f[i][j]-Qpow(m-1,i*j)%mod+mod)%mod;
			for (register int k=j;k<=n;k++)
				sum[i][k]+=f[i][j]*Qpow(m-1,(k-j)*i)%mod*c[k][j]%mod,sum[i][k]%=mod;
		}
	cout<<f[n][n]<<endl;
	return 0;
}