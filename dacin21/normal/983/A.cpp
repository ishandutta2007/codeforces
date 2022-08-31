#include <bits/stdc++.h>
using namespace std;
using ll = long long;


signed main(){
	cin.tie(0); ios_base::sync_with_stdio(false);
	int T; cin >> T;
	while(T--){
		ll p, q, b;
		cin >> p >> q >> b;
		q/=__gcd(p, q);
		while(b>1){
			b = __gcd(b, q);
			q/=b;
		}
		if(q==1){
			cout << "Finite\n";
		} else {
			cout << "Infinite\n";
		}
	}	
}