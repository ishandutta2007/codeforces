#include <bits/stdc++.h>
using namespace std;

const int L = 1e9;

char s[44], t[44];

int main() {
	int n; cin >> n;
	cout << 0 << ' ' << 1 << endl;
	cin >> t;
	int st = 0, en = L;
	for (int i = 0; i < n - 1; i++) {
		int md = (st + en) / 2;
		cout << md << ' ' << 1 << endl;
		cin >> s;
		if (s[0] == t[0]) st = md;
		else en = md;
	}
	cout << st << ' ' << 0 << ' ' << en << ' ' << 2 << endl;
}