/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	set <int> st;
	for (auto c : s) {
		st.insert(c);
	}
	if (n < k) {
		cout << s;
		for (int i = 0; i < k - n; i++) {
			cout << *min_element(s.begin(), s.end());
		}
		return 0;
	}
	char mx = *max_element(s.begin(), s.end());
	char mn = *min_element(s.begin(), s.end());
	for (int i = k - 1; i >= 0; i--) {
		if (s[i] != mx) {
			s[i] = *st.upper_bound(s[i]);
			for (int j = i + 1; j < k; j++) {
				s[j] = mn;
			}
			break;
		}
	}
	for (int i = 0; i < k; i++)
		cout << s[i];
}