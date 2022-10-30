#include <bits/stdc++.h>
using namespace std;

inline int dis(char a, char b) {
	return min(abs(a - b), 26 - abs(a - b));
}

int main() {
	int n, p; string ss;
	cin >> n >> p >> ss;
	p--;

	int l, r;
	if(p < n / 2) {
		l = 0, r = n / 2 - 1;
	}
	else {
		l = n / 2, r = n - 1;
	}
	
	int ans = INT_MAX;
	int t = p;
	int lp = t;
	int ta = 0;
	string s = ss;
	while(t <= r) {
		if(s[t] != s[n - t - 1]) {
			ta += abs(lp - t) + dis(s[t], s[n - t - 1]);
			s[t] = s[n - t - 1];
			lp = t;
		}
		t++;
	}
	t--;
	while(t >= l) {
		if(s[t] != s[n - t - 1]) {
			ta += abs(lp - t) + dis(s[t], s[n - t - 1]);
			s[t] = s[n - t - 1];
			lp = t;
		}
		t--;
	}
	ans = min(ans, ta);
	t = p;
	s = ss;
	lp = t;
	ta = 0;
	while(t >= l) {
		if(s[t] != s[n - t - 1]) {
			ta += abs(lp - t) + dis(s[t], s[n - t - 1]);
			s[t] = s[n - t - 1];
			lp = t;
		}
		t--;
	}
	t++;
	while(t <= r) {
		if(s[t] != s[n - t - 1]) {
			ta += abs(lp - t) + dis(s[t], s[n - t - 1]);
			s[t] = s[n - t - 1];
			lp = t;
		}
		t++;
	}
	ans = min(ans, ta);
	cout << ans << endl;

	return 0;
}