#include<bits/stdc++.h>
using namespace std;
long long ans;
int d[100005];
int main(){
	int t; cin>>t; while(t--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&d[i]);
		sort(d+1,d+1+n); ans=d[n];
		for(int i=1;i<=n;++i)ans+=d[i]*(n+1ll-i-i);
		printf("%lld\n",ans);
	}
}