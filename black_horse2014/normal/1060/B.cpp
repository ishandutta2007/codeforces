#include <bits/stdc++.h>
using namespace std;

int get(long long x) {
	if (!x) return 0;
	int ret = 0;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

long long lower(long long x) {
	long long ret = 0;
	long long pw = 1;
	while (1) {
		long long cur = pw * 9;
		if (x >= cur) x -= cur, ret += cur;
		else {
			long long dd = x / pw;
			ret += pw * dd;
			break;
		}
		pw *= 10;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	long long n; cin >> n;
	long long m = lower(n);
	cout << get(m) + get(n - m) << endl;
	return 0;
}