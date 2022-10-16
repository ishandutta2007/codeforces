#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
using namespace std;
inline void upd(register int &x,register int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
inline int Qpow(register int a,register int p){
	if (p==0)return 1;
	register int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline int inv(register int a){
	return Qpow(a,mod-2);
}
int f[4005][2005][2];
int n,k,l;
signed main(){
	cin>>n>>k>>l;
	f[0][0][0]=1;
	for (register int i=0;i<=2*n;i++)
		for (register int j=0;j<=n;j++){
			if (f[i][j][0]==0&&f[i][j][1]==0)continue;
			if (j<n)upd(f[i+1][j+1][0],f[i][j][0]);
			if (j<n)upd(f[i+1][j+1][1],f[i][j][1]);
			if (j>0)upd(f[i+1][j-1][0],j*f[i][j][0]%mod);
			if (j>0)upd(f[i+1][j-1][1],j*f[i][j][1]%mod);
			if (j>=k)upd(f[i+1][j][1],f[i][j][0]);
		}
	cout<<l*f[2*n+1][0][1]%mod*inv((2*n+1)%mod*f[2*n][0][0]%mod)%mod<<endl;
	return 0;
}