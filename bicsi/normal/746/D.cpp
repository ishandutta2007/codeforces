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

	int n, k, a, b;
	cin >> n >> k >> a >> b;

	string ans = "";

	char last = 'G';
	int cnt = 0;

	while(a > 0 || b > 0) {
		if(cnt == k) {
			if(last == 'G') {
				if(b == 0) {
					cerr << a << " " << b << endl;
					cerr << ans << endl;
					cout << "NO"<< endl;
					return 0;
				} else {
					--b;
					cnt = 0; ans += "B";
				}
			} else {
				if(a == 0) {
					cerr << a << " " << b << endl;
					cerr << ans << endl;
					cout << "NO" << endl;
					return 0;
				} else {
					--a;
					cnt = 0; ans += "G";
				}
			}
		} else {
			if(a > b) {
				ans += "G"; --a;
				if(last != 'G') cnt = 0;
			} else {
				ans += "B"; --b;
				if(last != 'B') cnt = 0;
			}
		}
		last = ans.back();
		++cnt;
	}

	cout << ans << endl;


	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/