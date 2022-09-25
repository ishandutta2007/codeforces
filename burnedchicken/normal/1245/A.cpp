#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(ll i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll t,a,b;
	cin >> t;
	loop(t){
		cin >> a >> b;
		if(__gcd(a,b)>1) cout << "Infinite" << endl;
		else cout << "Finite" << endl;
	}
	return 0;
}