#include <bits/stdc++.h>
using namespace std;
map<int,vector<int> > mp;
typedef long long ll;
int main(){
	int n;cin>>n;
	for (int i=0;i<n;i++){
		int x;cin>>x;
		mp[i-x].push_back(x);
	}
	ll ans=0;
	for (map<int,vector<int> >::iterator it=mp.begin();it!=mp.end();it++){
		ll res=0;
		vector<int>v=it->second;
		for (int j=0;j<v.size();j++) res+=v[j];
		ans=max(ans,res);
	}
	cout<<ans;
}