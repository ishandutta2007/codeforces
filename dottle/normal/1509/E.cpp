#include<bits/stdc++.h>
#define int long long
const int N=100050,INF=1e18;
using namespace std;

int n,k,t,a[N];

main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		if(n<=62&&(1ll<<n-1)<k){
			printf("-1\n");continue;
		}--k;
		for(int i=1;i<n-62;i++)printf("%lld ",i);
		for(int i=max(1ll,n-62),cnt;i<=n;i+=cnt){
			cnt=1;
			while(k>=1ll<<n-i-cnt&&n-i-cnt+1)
				k-=1ll<<n-i-cnt,++cnt;
			for(int j=i+cnt-1;j>=i;j--)
				printf("%lld ",j);
		}
		putchar('\n');
	} 
}