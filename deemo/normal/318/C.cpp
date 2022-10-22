#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

int main(){
	ll x, y, m;	cin >> x >> y >> m;
	if (x >= m || y >= m){
		cout << 0 << endl;
		return 0;
	}
	if (x > y)	swap(x, y);
	if (x <= 0 && y <= 0){
		cout << -1 << endl;
		return 0;
	}

	ll ans = 0;
	if (x < 0){
		ans += (-x)/ y;
		if ((-x) % y != 0)	ans++;
		x += ((-x) / y) * y;
		if (x < 0)	x += y;
	}

	while (x < m && y < m){
		if (x > y)	swap(x, y);
		ans++;
		x = x + y;
	}
	cout << ans << endl;
	return 0;
}