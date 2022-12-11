#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,mod=998244353;
int n,x,y,d[N],J[N],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		d[x]++;d[y]++;
	}
	J[0]=1;
	for(int i=1;i<=n;i++)J[i]=1ll*J[i-1]*i%mod;
	ans=n;
	for(int i=1;i<=n;i++)ans=1ll*ans*J[d[i]]%mod;
	printf("%d",ans);
	return 0;
}