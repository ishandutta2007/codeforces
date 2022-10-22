#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
typedef long long ll;
ll s[N],d[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%lld",&s[i]),d[i]=0;
		ll ans=0;
		for(int i=1;i<=n;++i){
			ll k=max(0ll,s[i]-1-d[i]);
			ans+=k;
			d[i]+=k;
			for(int j=i+2;j<=min(i+s[i],(ll)n);++j)
				d[j]++;
			d[i+1]+=d[i]-s[i]+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}