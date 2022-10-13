#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x": "<<x<<"\n"
#define arr_dump(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define ok_dump cerr<<"OK!\n"


int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	#endif

	int rem = 4 * 60;
	int n, k;
	cin >> n >> k;

	rem -= k;
	for(int i = 0; i < n; ++i) {
		rem -= 5 * (i + 1);
		if(rem < 0) {
			cout << i << endl;
			return 0;
		}
	}

	cout << n << endl;

	return 0;
}