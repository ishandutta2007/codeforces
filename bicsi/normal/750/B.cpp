#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x": "<<x<<"\n"
#define arr_dump(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define ok_dump cerr<<"OK!\n"


int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	#endif

	int n;
	cin >> n;
	int x = 0;
	for(int i = 0; i < n; ++i) {
		int y; string dir;
		cin >> y >> dir;
		if(dir == "North") x -= y;
		else if(dir == "South") x += y;
		else if(x == 0 || x == 20000) {
			cout << "NO" << endl;
			return 0;
		}

		if(x < 0 || x > 20000) {
			cout << "NO" << endl;
			return 0;
		}

	}

	if(x == 0) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}