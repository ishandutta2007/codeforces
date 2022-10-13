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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	vector<int> Prime(101, 1), Primes;
	for(int i = 2; i <= 100; ++i) {
		if(Prime[i]) {
			Primes.push_back(i);
			for(int j = i + i; j <= 100; j += i) {
				Prime[j] = 0;
			}
		}
	}

	string ans;
	for(auto p : Primes) {
		if(p * p > 100) {
			cout << "prime" << endl;
			return 0;
		}

		cout << p << endl;
		cin >> ans;

		if(ans == "yes") {
			for(auto q : Primes) {
				if(q < p) continue;

				if(p * q > 100) {
					cout << "prime" << endl;
					return 0;
				}

				cout << p * q << endl;
				cin >> ans;

				if(ans == "yes") {
					cout << "composite" << endl;
					return 0;
				}
			}
		}
	}
	
	
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/