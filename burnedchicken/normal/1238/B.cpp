#include <bits/stdc++.h>
 
#define ll long long int
#define loop(a) for(long long int i=0; i<a; i++)
 
using namespace std;

int main(){
	ll q,n,r,x,ans;
	cin >> q;
	loop(q){
		cin >> n >> r;
		vector<ll> vec;
		for(ll j=0; j<n; j++){
			cin >> x;
			vec.push_back(x);
		}
		sort(vec.begin(),vec.end());
		ans=0;
		while(vec.back()>ans*r){
			x=vec.back();
			vec.pop_back();
			while(vec.back()==x) vec.pop_back();
			ans++;
			if(vec.empty()) break;
		}
		cout << ans << endl;
	}
	return 0;
}