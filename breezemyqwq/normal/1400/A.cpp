#include <bits/stdc++.h>

using namespace std;

bool ok[55];
int th[55];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n;
		cin >> s;
		s = ' ' + s;
		for(int i = 1; i <= ((2 * n) >> 1); i++) cout << s[i * 2 - 1];
		puts("");
	}
	return 0;
}