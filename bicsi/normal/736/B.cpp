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

const int kMaxN = 500000;

bool Prime(int n) {
	for(int d = 2; d * d <= n; ++d)
		if(n % d == 0)
			return false;
	return true;
}
int DP[50000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Comment these lines before submitting
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);

	// Start code here

	int n;
	cin >> n;

	if(Prime(n)) {
		cout << 1 << endl;
	} else if(n % 2 == 0 || Prime(n - 2)) {
		cout << 2 << endl;
	} else {
		cout << 3 << endl;
	}



	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/