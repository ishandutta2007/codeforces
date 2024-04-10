#include <bits/stdc++.h>
using namespace std;

int main() {
// 	freopen("in.txt", "r", stdin);	
	ios::sync_with_stdio(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n, k; cin >> n >> k;
		int f = n / k;
		string s;
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= f; j++) s.push_back(i + 'a' - 1);
		int dap = f;
		int r = n % k;
		if (r) {
			dap++;
			for (int i = 0; i < r; i++) s.push_back(i + 'a');
		}
		cout << s << endl;
	}
	return 0;
}