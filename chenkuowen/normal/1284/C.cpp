#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
int fac[MAX_N];
int main(){
	int n,m; scanf("%d%d",&n,&m);
	fac[0]=1; for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%m;
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=(ans+1ll*(n-i+1)*(n-i+1)%m*fac[n-i]%m*fac[i])%m;
	printf("%d\n",ans);
	return 0;
}