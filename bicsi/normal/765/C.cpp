#include <bits/stdc++.h>

using namespace std;

int main() {
	long long k, a, b;
	cin >> k >> a >> b;
	long long t = a / k, u = b / k;

	if(a <= t * k + u * (k - 1)
	&& b <= u * k + t * (k - 1)) {
		cout << u + t << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}