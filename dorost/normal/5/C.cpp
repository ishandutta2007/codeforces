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
	string s;
	cin >> s;
	int n = s.size();
	stack <int> st;
	st.push(-1);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		if (c == '(')
			st.push(i);
		else {
			st.pop();
			if (!st.empty()) {
				mx = max(mx, i - st.top());
			} else
				st.push(i);
		}
	}
	st = {};
	st.push(-1);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		if (c == '(')
			st.push(i);
		else 
			st.pop();
			if (!st.empty()) {
				if ((i - st.top()) == mx)
					cnt++;
			} else
				st.push(i);
	}
	if (mx == 0) 
		cnt = 1;
	cout << mx << ' ' << cnt;
}