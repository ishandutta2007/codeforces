/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;

void solve() {
	string s;
	cin >> s;
	stack <char> st;
	for (int i = 0; i < s.size(); i++) {
		if (st.empty()) {
			st.push(s[i]);
		} else if (s[i] == 'B' && st.top() == 'A') {
			st.pop();
		} else {
			st.push(s[i]);
		}
	}
	string t;
	while (!st.empty()) {
		t += st.top();
		st.pop();
	}
	reverse(t.begin(), t.end());
	int a = 0, b = 0;
	for (int i = 0; i < t.size(); i++)
		if (t[i] == 'A')
			a++;
		else
			b++;
	cout << a + b % 2 << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}