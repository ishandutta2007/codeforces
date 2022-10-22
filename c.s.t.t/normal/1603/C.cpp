#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int T,n,a[100100],res,f[2][100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),res=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=n;i>=2;i--){
			f[i&1][a[i]]++;
			for(int j=1;j<=a[i];j=a[i]/(a[i]/j)+1){
				int lim=a[i]/j;
//				printf("%d,%d:%d\n",i,lim,f[i&1][lim]);
				int num=(a[i-1]-1)/lim+1;res=(1ll*(num-1)*(i-1)%mod*f[i&1][lim]+res)%mod;
				int k=a[i-1]/num;
				(f[!(i&1)][k]+=f[i&1][lim])%=mod,f[i&1][lim]=0;
			}
		}
		for(int j=1;j<=a[1];j=a[1]/(a[1]/j)+1)f[1][a[1]/j]=0;
		printf("%d\n",res);
	}
	return 0;
}