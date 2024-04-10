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
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);

	// Start code here

	long long n;
	cin >> n;

	long long Fib[50000];

	Fib[0] = Fib[1] = 1LL;
	for(int i = 2; ; ++i) {
		Fib[i] = Fib[i - 1] + Fib[i - 2];
		if(Fib[i] > n) {
			cout << i - 2 << endl;
			return 0;
		}
	}

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/