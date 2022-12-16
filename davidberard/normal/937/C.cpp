#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	ull k, d, t;
	cin >> k >> d >> t;
	t *= 2;
	if( d > k ) {
		d -= k;
	} else if( d == k ) {
		d = 0;
	} else if( k%d == 0) {
		d = 0;
	} else {
		d = (2*d-k%d)%d;
	}
	ull iter = (t/(k*2 + d));
	ull total = iter * (k + d);
	t -= iter*(k*2+d);
	//cerr << "REMAINING t " << t << " k=" << k << " d=" << d << " iter=" << iter << " total=" << total << endl;
	bool half = false;
	if(t > k*2) {
		//cerr << " + k !!" << endl;
		total += k;
		t -= k*2;
		total += t;
	} else if( t > 0 ){
		ull xtra = min(k, t/2);
		//cerr << "+ xtra " << xtra << " ( or + time " << xtra*2 << endl;
		t -= xtra*2;
		total += xtra;
		if(t > 0) half = true;
	}
	cout << total;
	if(half)
		cout << ".5";
	cout << endl;

	

	return 0;
}
// David Berard