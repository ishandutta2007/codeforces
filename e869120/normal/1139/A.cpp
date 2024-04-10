#include <bits/stdc++.h>
using namespace std;

string s; int n; long long cnt = 0;

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if ((int)(s[i] - '0') % 2 == 0) cnt += 1LL * (i + 1LL);
	}
	cout << cnt << endl;
	return 0;
}