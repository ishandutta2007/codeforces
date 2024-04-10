#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
map<pair<int,int> ,int> mp;
ll a[N];
ll rw[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	ll ans=0;
	for(i=1;i<=n;i++) {
		cin>>a[i];
		ans+=a[i];
	}
	cin>>m;
	while(m--){
		int s,t,u;cin>>s>>t>>u;
		if(mp[{s,t}]){
			int v=mp[{s,t}];
			ans-=max(a[v]-rw[v],0ll);
			rw[v]--;
			ans+=max(a[v]-rw[v],0ll);
		}
		if(u){
			ans-=max(a[u]-rw[u],0ll);
			rw[u]++;
			ans+=max(a[u]-rw[u],0ll);
		}
		mp[{s,t}]=u;
		cout<<ans<<endl;
	}
	return 0;
}