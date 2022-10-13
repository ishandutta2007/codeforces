#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x": "<<x<<"\n"
#define arr_dump(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define ok_dump cerr<<"OK!\n"


#define int long long

int32_t main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	#endif

	int min_rating = -1e18, max_rating = 1e18;

	int n;
	cin >> n;

	int delta = 0;
	for(int i = 0; i < n; ++i) {
		int d;
		cin >> d;

		int div;
		cin >> div;

		if(div == 1) min_rating = max(min_rating, 1900LL - delta);
		else max_rating = min(max_rating, 1899LL - delta);


		delta += d;
	}

	if(min_rating > max_rating) {
		cout << "Impossible\n";
		return 0;
	}
	if(max_rating > 1e16) {
		cout << "Infinity\n";
		return 0;
	}
	//cerr << min_rating << " " << max_rating << endl;
	cout << max_rating + delta << endl;
	return 0;
}