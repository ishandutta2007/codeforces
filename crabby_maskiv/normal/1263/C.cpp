#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
ll k;
vector<ll> v;
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>k;
		v.push_back(0);
		ll l=1,r;
		while(l<=k){
			ll t=k/l;
			v.push_back(t);
			r=k/t;
			l=r+1;
		}
		sort(v.begin(),v.end());
		cout<<v.size()<<endl;
		for(i=0;i<v.size();i++) cout<<v[i]<<" ";
		cout<<endl;
		v.clear();
	}
	return 0;
}