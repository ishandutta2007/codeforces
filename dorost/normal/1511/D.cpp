/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	set <string> st;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			string s;
			s += (i + 'a');
			s += (j + 'a');
			if (s != "aa") {
				st.insert(s);
			}
		}
	}
	string a = "aa";
	if (k == 1)
		a = "a";
	while (st.size()) {
		string t;
		t += (a[a.size() - 1] + 1);
		t += 'a';
		auto in = st.lower_bound(t);
		in--;
		string s = *in;
		assert(s[0] == a[a.size() - 1]);
		st.erase(s);
		a += s[1];
	}
	k = (int)(a.size());
	for (int i = 0; i < n; i++) {
		if (i == 0 || k == 1)
			cout << 'a';
		else
			cout << a[(i - 1) % (k - 1) + 1]; 
	}
}