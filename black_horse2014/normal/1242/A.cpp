#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	int cnt = 0;
	long long cur = -1;
	for (int i = 2; i * 1LL * i <= n; i++) {
		if (n % i == 0) {
			cur = i;
			while (n % i == 0) n /= i;
			cnt++;
		}
	}
	if (n != 1) cnt++, cur = n;
	if (cnt == 1) {
		cout << cur << "\n";
	} else {
		cout << 1 << "\n";
	}
	return 0;
}