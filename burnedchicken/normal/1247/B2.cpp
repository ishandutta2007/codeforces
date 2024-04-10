#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) for(long long i=0; i<a; i++)
#define IOS ios_base::sync_with_stdio(0),cin.tie(0)
 
using namespace std;
 
int main(){
	IOS;
	multiset<ll> s;
	set<ll> s0;
	ll t,n,k,d,ans,x;
	cin >> t;
	loop(t){
		cin >> n >> k >> d;
		ll a[n];
		for(ll j=0; j<n; j++) cin >> a[j];
		s.clear();
		s0.clear();
		ans=0;
		for(ll j=0; j<d; j++){
			s.insert(a[j]);
			s0.insert(a[j]);
		}
		ans=s0.size();
		for(ll j=0; j<n-d; j++){
			s.insert(a[j+d]);
			s0.insert(a[j+d]);
			s.erase(s.find(a[j]));
			if(s.find(a[j])==s.end()) s0.erase(a[j]);
			x=s0.size();
			ans=min(ans,x);
		}
		cout << ans << endl;
	}
	return 0;
}