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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Comment these lines before submitting
	//freopen("input", "r", stdin);
	// /freopen("output", "w", stdout);

	// Start code here
	int n;
	cin >> n;

	vector<bool> Prime(n * 10005);
	for(int i = 2; i < Prime.size(); ++i) {
		if(Prime[i]) continue;
		for(int j = 2 * i; j < Prime.size(); j += i)
			Prime[j] = 1;
	}

	for(int m = 1; m <= 10000; ++m) {
		if(!Prime[n * m + 1]) continue;
		cout << m << endl;
		return 0;
	}

	assert(false);
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/