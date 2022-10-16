#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	while(t--){
		long long sum,a,n,mip,mii=1e9,ans=1e15;
		scanf("%lld",&n);
		scanf("%lld",&mip);
		sum=mip;
		for(long long i=1;i<n;i++){
			scanf("%lld", &a);
			sum+=a;
			if(i&1) mii=min(a,mii);
			else mip=min(a,mip);
			ans=min(ans,sum+(n-i/2-1)*mip+(n-(i-1)/2-1)*mii);
		}
		printf("%lld\n", ans);
	}	
	return 0;
}