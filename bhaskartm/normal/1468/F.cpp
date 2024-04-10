#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<long double,long double>
#define fi first
#define se second
#define endl '\n'
map<pair<int,int>,int> mp;
int mod(int x){
	if(x<0){
		return -1*x;
	}
	return x;
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll ans=0;
		mp.clear();
		for(int i=0;i<n;i++){
			int x,y,u,v;
			cin>>x>>y>>u>>v;
			int x1=u-x;
			int y1=v-y;
			int g=__gcd(mod(x1),mod(y1));
			x1=x1/g;
			y1=y1/g;
			ans=ans+(mp[{-1*x1,-1*y1}]);
			mp[{x1,y1}]++;
		}
		cout<<ans<<endl;
	}
}