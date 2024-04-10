#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fast ios::sync_with_stdio(false), cout.tie(), cin.tie();
#define sz(s) int(s.size())

int main(){
	ll n;
	cin >> n;
	for (ll i = sqrt(n); i > 0; i--){
		if (__gcd(i, n / i) == 1 && n % i == 0){
			cout << i << ' ' << n / i;
			return 0;
		}
	}
	cout << 1 << ' ' << n;
}