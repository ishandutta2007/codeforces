#include <iostream>
#include <cstring>
#define mod 31607
using namespace std;
int n,a[25][25],_a[25][25],c[25],f[25],ans;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
int inv(int x){
	return Qpow(x,mod-2);
}
int dfs(int now,int fg){
	if (now>n){
		f[0]=mod-1;
		for (int i=1;i<=n;i++)f[i]=(f[i-1]-c[i]*f[i-1]%mod+mod)%mod;
		if (fg==1)return f[n];
		return (mod-f[n])%mod;
	}
	int _c[25];
	for (int i=1;i<=n;i++)_c[i]=c[i];
	int ans=0,v1=1,v2=1;
	
	for (int i=1;i<=n;i++)v1=v1*a[now][i]%mod;
	ans=(ans+v1*dfs(now+1,-fg))%mod;
	
	for (int i=1;i<=n;i++)c[i]=c[i]*a[now][i]%mod;
	ans=(ans+v2*dfs(now+1,fg))%mod;
	
	for (int i=1;i<=n;i++)c[i]=_c[i];
	return ans;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
			a[i][j]=a[i][j]*inv(10000)%mod;
			_a[i][j]=a[i][j];
		}
	for (int i=1;i<=n;i++)c[i]=1;
	int v1=1,v2=1,v3=1,v4=1;
	ans=(ans+v1*(1+dfs(1,1)))%mod;

	for (int i=1;i<=n;i++)v2=v2*a[i][i]%mod,a[i][i]=1;
	ans=(ans+v2*dfs(1,-1))%mod;
	for (int i=1;i<=n;i++)a[i][i]=_a[i][i];
	
	for (int i=1;i<=n;i++)v3=v3*a[i][n-i+1]%mod,a[i][n-i+1]=1;
	ans=(ans+v3*dfs(1,-1))%mod;
	for (int i=1;i<=n;i++)a[i][n-i+1]=_a[i][n-i+1];

	for (int i=1;i<=n;i++){
		v4=v4*a[i][i]%mod;
		if (i!=n-i+1)v4=v4*a[i][n-i+1]%mod;
		a[i][i]=a[i][n-i+1]=1;
	}
	ans=(ans+v4*dfs(1,1))%mod;
	for (int i=1;i<=n;i++)a[i][i]=_a[i][i],a[i][n-i+1]=_a[i][n-i+1];
		
	cout<<ans<<endl;
	return 0;
}