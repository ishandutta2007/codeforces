#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
const int mod=1e9+7;
int qp(int x,int y){
	int z=1;
	while(y){if(y&1)z=1ll*z*x%mod;x=1ll*x*x%mod;y/=2;}
	return z;
}
int n,a[14],p[14][14],f[1<<14],ans;
int i,j,k,l;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			p[i][j]=1ll*a[i]*qp((a[i]+a[j])%mod,mod-2)%mod;
		}
	}
	for(i=1;i<(1<<n);i++){
		f[i]=1;
		for(j=((i-1)&i);j;j=((j-1)&i)){
			int pro=f[j];
			for(k=0;k<n;k++)if((j>>k)&1){
				for(l=0;l<n;l++)if(((i>>l)&1)&&!((j>>l)&1)){
					pro=1ll*pro*p[k][l]%mod;
				}
			}
			f[i]=(f[i]-pro+mod)%mod;
		}
	}
	for(i=1;i<(1<<n);i++){
		int t=__builtin_popcount(i);
		t=1ll*f[i]*t%mod;
		for(k=0;k<n;k++)if((i>>k)&1){
			for(l=0;l<n;l++)if(!((i>>l)&1)){
				t=1ll*t*p[k][l]%mod;
			}
		}
		ans=(ans+t)%mod;
	}
	cout<<ans<<endl;
	return 0;
}