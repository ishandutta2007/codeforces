#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

const ld eps = 1e-13;

int n, l, k, v0, v1, nd;

bool ok(ld mid){
	ld b = 0, e = mid;
	for (int i = 0; i < 85; i++){
		ld m = (b + e)/ 2.;
		ld sm = m * v1 + (mid - m) * v0;
		if (sm >= l)
			e = m;
		else
			b = m;
	}

	if (e * v1 + (mid - e) * v0 + eps < l)	return false;
	ld temp = e * (v1 - v0);
	ld z = e + temp/ (v1 + v0);
	return nd * z - temp/ (v1 + v0) <= mid;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	cin >> n >> l >> v0 >> v1 >> k;
	nd = n/k + bool(n % k);
	v1 = max(v1, v0);

	ld b = 0, e = 1e9;
	for (int i = 0; i < 85; i++){
		ld mid = (b+e)/2.;
		if (ok(mid))
			e = mid;
		else
			b = mid;
	}
	cout << e << endl;
	return 0;
}