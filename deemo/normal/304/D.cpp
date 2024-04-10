#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

ll n, m, x, y, a, b;

long double cal(pair<long double, long double>	z){
	long double dif = (z.first - x) * (z.first - x);
	long double dif2 = (z.second - y) * (z.second - y);
	return	sqrt(dif + dif2);
}

long double dis(long double x1, long double y_1, long double x2, long double y2){
	long double f = x2 - x1;
	long double g = y2 - y_1;
	return	cal({x1 + f/2, y_1 + g/2});
}

int main(){
	cin >> n >> m >> x >> y >> a >> b;
	
	ll g = __gcd(a, b);
	a/=g,	b /= g;
	
	ll beg = 1, end = 1e9, mid, ret = -1;
	while (beg <= end){
		mid = (beg + end)/ 2;
		ll f = mid * a, g = mid * b;
		if (f <= n && g <= m){
			ret = mid;
			beg = mid + 1;
		}
		else	end = mid - 1;
	}
	ll f = ret * a;
	g = ret * b;

	ll xx = 0, yy = 0;

	long double bg = 0, ed = n - f;
	for (ll i = 0; i < 100; i++){
		long double m1 = (bg * 2.0 + ed) / 3.0;
		long double m2 = (ed * 2.0 + bg) / 3.0;
		if (dis(m1, 0, m1 + f, g) > dis(m2, 0, m2 + f, g))	bg = m1;
		else	ed = m2;
	}
	if (dis(floor(bg), 0, floor(bg) + f, g) > dis(ceil(bg), 0, ceil(bg) + f, g))	xx = ceil(bg);
	else	xx = floor(bg);

	bg = 0, ed = m - g;
	for (ll i = 0; i < 100; i++){
		long double m1 = (2.0 * bg + ed) / 3.0;
		long double m2 = (2.0 * ed + bg) / 3.0;
		if (dis(xx, m1, xx + f, m1 + g) > dis(xx, m2, xx + f, m2 + g))	bg = m1;
		else	ed = m2;
	}
	if (dis(xx, floor(bg), xx + f, floor(bg) + g) > dis(xx, ceil(bg), xx + f, ceil(bg) + g))	yy = ceil(bg);
	else	yy = floor(bg);

	cout << xx << " " << yy << " " << xx + f << " " << yy + g << endl;
	return 0;
}