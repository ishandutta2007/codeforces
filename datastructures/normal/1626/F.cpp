#include <iostream>
#include <cstdio>
#define mod 998244353
#define maxn 12252240
using namespace std;
int pow_n[105],f[maxn+5];
int n,a[10000005],x,y,k,M;
int ans;
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
void dp(){
	pow_n[0]=1;
	for (int i=1;i<=k;i++)pow_n[i]=1ll*pow_n[i-1]*n%mod;
	for (int i=k;i>=1;i--)
		for (int j=maxn;j>=0;j--){
			int qwq=f[j-j%i];
			f[j]=1ll*f[j]*(n-1)%mod;
			upd(f[j],1ll*j*pow_n[k-i]%mod);
			upd(f[j],qwq);
		}
	return;
}
int main(){
	cin>>n>>a[0]>>x>>y>>k>>M;
	dp();
	for (int i=1;i<n;i++)a[i]=(1ll*a[i-1]*x%M+y)%M;
	for (int i=0;i<n;i++){
		int d1=a[i]%maxn;
		int d2=a[i]-d1;
		upd(ans,f[d1]);
		upd(ans,1ll*d2*k%mod*pow_n[k-1]%mod);
	}
	cout<<ans<<endl;
	return 0;
}