#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int mod;
int n,i,j,f[4000005];
int main(){
	cin>>n>>mod;
	f[1]=1;f[2]=mod-1;
	rep(i,n){
		f[i]=(f[i]+f[i-1])%mod;
		f[i+1]=(f[i]+f[i+1])%mod;
		for(j=2;i*j<=n;j++){
			f[i*j]=(f[i*j]+f[i])%mod;
			if((i+1)*j<=n){
				f[(i+1)*j]=(f[(i+1)*j]-f[i]+mod)%mod;
			}
		}
	}
	printf("%d\n",f[n]);
	return 0;
}