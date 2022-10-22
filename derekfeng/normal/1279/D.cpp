#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int MOD=998244353;
int n;
int have[1000004];
vector<int>v[1000004];
ll mypow(ll x,int t){
	ll res=1,ans=x;
	while (t){
		if (t%2==1){
			res=res*ans%MOD;
			t--;
			continue;
		}
		ans=ans*ans%MOD;
		t/=2;
	}
	return res;
}
ll inv(int x){
	return mypow(x,MOD-2);
}
int main(){
	cin>>n;
	ll ans=0;
	for (int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		while (x--){
			int k;scanf("%d",&k);
			v[i].push_back(k);
			have[k]++;
		}
	} 
	ll ha=inv(n);
	for (int i=1;i<=n;i++){
		for (int j=0;j<v[i].size();j++){
			ans+=ha*inv((int)v[i].size())%MOD*have[v[i][j]]%MOD*ha%MOD;
		}
	}
	cout<<ans%MOD;
}