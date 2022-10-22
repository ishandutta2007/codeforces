#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		ll n = stoi(s), h = s.size();
		ll ans = 0;
		while (n > 0){
			ll x = s.size();
			ll a = pow (10, x - 1);
			ll f = a;
			a = a - a / 10;
			ll z = 1;
			n -= a;
			ans += f;
			s = to_string(n);
			//cerr << s << endl;
		}
		cout << ans << endl;
	}
}