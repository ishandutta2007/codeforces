#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,mod,a[1000005];
int g[5005][5005],h[5005][5005];
int f[2][5005],sum;
int main(){
	cin>>n>>m>>mod;
	for (int i=1;i<=n;i++)a[i]=read();
	g[0][0]=h[0][0]=1;
	for (int i=1;i<=5000;i++)
		for (int j=1;j<=i&&j<=m;j++)
			g[i][j]=(1ll*g[i-1][j]*(j-1)%mod+1ll*g[i-1][j-1]*(m-j+1)%mod)%mod;
	for (int i=1;i<=5000;i++)
		for (int j=1;j<=i&&j<=m;j++)
			h[i][j]=(1ll*h[i-1][j]*(j-1)%mod+1ll*h[i-1][j-1]*j%mod)%mod;
	f[0][0]=sum=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++){
			f[i&1][j]=1ll*(sum-f[(i-1)&1][j]+mod)*g[a[i]][j]%mod;
			f[i&1][j]=(f[i&1][j]+1ll*f[(i-1)&1][j]*(g[a[i]][j]-h[a[i]][j]+mod)%mod)%mod;
		}
		sum=0;
		for (int j=1;j<=a[i];j++)sum=(sum+f[i&1][j])%mod;
		for (int j=0;j<=a[i-1];j++)f[(i-1)&1][j]=0;
	}
	cout<<sum<<endl;
	return 0;
}