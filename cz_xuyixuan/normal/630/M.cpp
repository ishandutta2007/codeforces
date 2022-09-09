#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int func(int x) {
	return min(x, 360 - x);
}
int main() {
	ios::sync_with_stdio(false);
	long long n; cin >> n;
	n = (n % 360 + 360) % 360;
	int now = func(n), ans = 0;
	for (int i = 1; i <= 4; i++) {
		n = (n - 90 + 360) % 360;
		if (func(n) < now) {
			now = func(n);
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}