/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const ll inf = 1LL << 32LL;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	string nn = "";
	getline(cin, nn);
	n = stoi(nn);
	ll x = 0;
	stack <ll> st;
	st.push(1);
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		if (s[0] == 'a') {
			x += st.top();
			if (x >= inf) {
				cout << "OVERFLOW!!!";
				return 0;
			}
		} else if (s[0] == 'e') {
			st.pop();
		} else {
			string t;
			for (int i = 4; i < s.size(); i++) {
				t += s[i];
			}
			int a = stoi(t);
			st.push(min((ll)inf, st.top() * a));
		}
	}
	cout << x << endl;
}