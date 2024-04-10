#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,k,n,a[200004];ll s[200004];
void sol(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	if(k<=n){
		ll mx=0;
		for(int i=0;i+k<=n;i++)
			mx=max(mx,s[i+k]-s[i]);
		printf("%lld\n",mx+(ll)k*(k-1)/2);
		return;
	}
	ll ans=s[n];
	for(int i=k-n+1;i<=k;i++)ans+=i-1;
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}