#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, x, y;

int main(){
	cin >> a >> b >> x >> y;
	ll g = __gcd(x, y);
	x /= g;
	y /= g;
	ll lo = 0, hi = 2e9+1;
	while (hi-lo>1){
		ll mid = hi+lo>>1;
		if (mid * x <= a && mid * y <= b)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo * x << " " << lo * y << endl;
	return 0;
}