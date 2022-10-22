#include<bits/stdc++.h>
using namespace std;

int main() {
	int T,n,m; scanf("%d",&T);
	while(T--) {
		scanf("%d",&n),m=n/2;
		int64_t ans=1ll<<n;
		for(int i=1;i<m;++i) ans+=1ll<<i;
		for(int i=m;i<n;++i) ans-=1ll<<i;
		printf("%lld\n",ans);
	}
}