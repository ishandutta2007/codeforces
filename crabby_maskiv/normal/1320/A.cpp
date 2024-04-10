#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const int inf=0x3f3f3f3f;
int n,m;
map<int,ll> mp;
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		int x;cin>>x;
		mp[x-i]+=x;
	}
	ll ans=0;
	for(auto x:mp) ans=max(ans,x.second);
	cout<<ans;
	return 0;
}