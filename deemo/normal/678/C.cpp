#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

int main(){
	ll n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	ll ans = n/a * p + n/b * q;
	ll g = __gcd(a, b);
	g = a/g * b;
	ans -= n/g * min(p, q);
	cout << ans << endl;
	return 0;
}