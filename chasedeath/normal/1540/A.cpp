#include<bits/stdc++.h>
using namespace std;

int d[100010];

int main(){ 
	int T; scanf("%d",&T);
	while(T--) {
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",d+i);
		sort(d+1,d+n+1);
		int64_t s=0,ans=0;
		for(int i=1;i<=n;++i) ans+=s-1ll*d[i]*(i-1),s+=d[i];
		ans+=d[n];
		printf("%lld\n",ans);
	}
}