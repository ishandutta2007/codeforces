/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

#define int long long

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long x;
	cin >> x;

	x *= x;
	if(x == 1) {
		cout << -1;
		return 0;
	}

	if(x == 4) {
		cout << -1;
		return 0;
	}

	if(x % 2 == 1) {
		// b - a = 1
		// b + a = x
		cout << x / 2 << " " << x / 2 + 1 << endl;
		return 0;
	}

	if(x % 4 == 0) {
		// b - a = 2
		// b + a = x / 2
		
		
		int half = x / 2;
		cout << half / 2 - 1 << " " << half / 2 + 1 << endl;
		return 0;
	}

	assert(false);
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/