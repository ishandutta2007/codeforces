#include <bits/stdc++.h>

using namespace std;

string n, ans;

int get_sum(string s) {
	int res = 0;
	for (int i = 0; i < s.length(); ++i) {
		res += s[i] - '0';
	}
	return res;
}

void update(string s) {
	if (get_sum(ans) <= get_sum(s)) {
		ans = s;
	}
}

int main()  {
	cin >> n;
	if (n.length() > 1) {
		string q = "";
		for (int i = 1; i < n.length(); ++i) {
			q += '9';
		}
		update(q);
	}
	for (int i = 0; i < n.length(); ++i) {
		int st = '0';
		if (i == 0) {
			st = '1';
		}
		for (int j = st; j < n[i]; ++j) {
			string q = n.substr(0, i);
			q += j;
			for (int k = i + 1; k < n.length(); ++k) {
				q += '9';
			}
			update(q);
		}
	}
	update(n);
	cout << ans << endl;
	return 0;
}