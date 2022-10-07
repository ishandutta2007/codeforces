#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,E=524288,N=300005;
int t,n,a[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		long long s=1;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			while(a[i]%2==0){
				a[i]/=2;
				s*=2;
			}
		}
		sort(a+1,a+1+n);
		long long ans=0;
		for(int i=1;i<=n;++i)
			ans+=(i==n?s:1)*a[i];
		printf("%lld\n",ans);
	}
}