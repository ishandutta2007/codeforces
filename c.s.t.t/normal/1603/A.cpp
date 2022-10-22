#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[100100],fac[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		fac[0]=1;for(int i=1;i<=n+1;i++){
			ll tmp=1ll*fac[i-1]*i/__gcd(fac[i-1],i);
			if(tmp>1e9){for(int j=i;j<=n+1;j++)fac[j]=-1;break;}
			fac[i]=tmp;
		}
		bool ok=true;
		for(int i=1;i<=n;i++)if(fac[i+1]!=-1&&!(a[i]%fac[i+1]))ok=false;
		puts(ok?"YES":"NO");
	}
	return 0;
}