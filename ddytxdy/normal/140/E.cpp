#include<bits/stdc++.h>
using namespace std;
const int N=5050,M=1e6+50;
int n,m,mod,a[M],mx,f[N][N],g[N],A[N],J[N];long long sum=1;
int read(){
	int x=0,c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
int main(){
	scanf("%d%d%d",&n,&m,&mod);f[0][0]=A[0]=J[0]=sum=1;
	for(int i=1;i<=n;i++)mx=max(mx,a[i]=read());
	for(int i=1;i<=mx;i++)A[i]=1ll*A[i-1]*(m-i+1)%mod,J[i]=1ll*J[i-1]*i%mod;
	for(int i=1;i<=mx;i++)for(int j=1;j<=i;j++)
		f[i][j]=(f[i-1][j-1]+1ll*(j-1)*f[i-1][j])%mod;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(m,a[i]);j++)
			g[j]=(sum*A[j]-1ll*g[j]*J[j])%mod*f[a[i]][j]%mod;
		for(int j=a[i]+1;j<=a[i-1];j++)g[j]=0;
		sum=0;for(int j=1;j<=a[i];j++)sum+=g[j];sum%=mod;
	}
	cout<<(sum+mod)%mod;
	return 0;
}