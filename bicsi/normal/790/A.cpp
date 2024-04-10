// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

string GetNextName() {
	static int cur = 0;

	int x = cur % 25, y = cur / 25;
	++cur;
	return string() + char(x + 'A') + char(y + 'a');
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<string> ans(n);
	vector<string> have(n - k + 1);

	int start = -1;
	for(int i = 0; i < n - k + 1; ++i) {
		cin >> have[i];
		if(have[i] == "YES") {
			start = i;
		}
	}

	if(start == -1) {
		// All NOs
		for(int i = 0; i < n; ++i) {
			cout << "A ";
		}
		cout << endl;
	} else {
		vector<string> ans(n);
		for(int i = start; i < start + k; ++i)
			ans[i] = GetNextName();
		for(int i = start - 1; i >= 0; --i) {
			if(have[i] == "NO") ans[i] = ans[i + k - 1];
			else ans[i] = GetNextName();
		}
		for(int i = start + 1; i < n - k + 1; ++i) {
			if(have[i] == "NO") ans[i + k - 1] = ans[i];
			else ans[i + k - 1] = GetNextName();
		}

		for(auto x : ans) cout << x << " ";
			cout << endl;
	}
}