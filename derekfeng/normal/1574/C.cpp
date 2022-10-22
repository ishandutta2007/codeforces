#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
ll sum,X,Y;
multiset<ll>mst;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ll x;scanf("%I64d",&x);
		mst.insert(x),sum+=x;
	}
	scanf("%d",&q);
	while(q--){
		scanf("%lld%lld",&X,&Y);
		ll ans=2e18;
		ll L=X,R=sum-Y;
		{
			auto it=mst.lower_bound(L);
			if(it!=mst.end()&&*it<=R)ans=0;
		}
		{
			auto it=mst.lower_bound(max(L,R));
			if(it!=mst.end())ans=min(ans,(*it)-R);
		}
		{
			auto it=mst.upper_bound(min(L,R));
			if(it!=mst.begin())ans=min(ans,L-(*--it));
		}
		{
			auto it=mst.lower_bound(R);
			if(it!=mst.end()&&*it<=L)ans=min(ans,L-R);
		}
		printf("%lld\n",ans);
	}
}