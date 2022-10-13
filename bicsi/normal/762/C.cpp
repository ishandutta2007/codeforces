#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	swap(a, b);
	int at, n = b.size();
	vector<int> pref(n + 1), suff(n + 1);

	at = 0;
	pref[0] = at;
	for(int i = 1; i <= n; ++i) {
		if(at < a.size() && b[i - 1] == a[at])
			++at;
		pref[i] = at;
	}

	if(at == a.size()) {
		cout << a << endl;
		return 0;
	}


	at = a.size();
	suff[n] = at;
	for(int i = n - 1; i >= 0; --i) {
		if(at > 0 && b[i] == a[at - 1])
			--at;
		suff[i] = at;
	}

	int best = -10000000, p = -1, s = -1;
	for(int i = 0; i <= n; ++i) {
		int now = pref[i] - suff[i];
		if(best < now) { 
			best = now;
			p = pref[i];
			s = suff[i];
		}
	}

	string ans = string(a.begin(), a.begin() + p) + 
				 string(a.begin() + s, a.end());

	if(ans == "") ans = "-";

	cout << ans << endl;
}