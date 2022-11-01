#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 1e6;

int n, a[N];

string fuck(int n, int a[]) {
	string ret = "";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			ret += ('a' + i);
		}
	}
	return ret;
}

string get_palindrom(int n, int a[]) {
	string forward = "", backward = "";
	for (int i = 0; i < n; i++) {
		char c = 'a' + i;
		for (int j = 0; j < a[i]; j += 2) {
			forward += c;
			backward += c;
		}
	}
	reverse(backward.begin(), backward.end());
	return forward + backward;
}

void solve_odd(int x) {
	int t = a[x];
	a[x] = 0;
	for (int unit = 1; unit <= t; unit++) {
		if (t % unit == 0) {
			bool flag = true;
			for (int j = 0; j < n; j++) {
				if (a[j] % (2 * t / unit) != 0) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				a[j] /= (t / unit);
			}
			string period = get_palindrom(n, a);
			string ret = "";
			for (int j = 1; j <= t / unit; j++) {
				for (int k = 0; k < unit; k++) {
					ret += ('a' + x);
				}
				ret += period;
			}
			printf("%d\n", t / unit);
			cout << ret << endl;
			return ;
		}
	}
}

void solve_even() {
	int m = 0;
	for (int i = 0; i < n; i++) {
		m += a[i];
	}
	for (int unit = 1; unit <= m; unit++) {
		if (m % unit != 0) {
			continue;
		}
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (a[j] % (2 * m / unit) != 0) {
				flag = false;
			}
		}
		if (!flag) {
			continue;
		}
		for (int j = 0; j < n; j++) {
			a[j] /= m / unit;
		}
		string period = get_palindrom(n, a);
		string ret = "";
		for (int j = 1; j <= m / unit; j++) {
			ret += period;
		}
		cout << m / unit * 2 << endl;
		cout << ret << endl;
		return ;
	}
}

int main() {
	scanf("%d", &n);
	int odd = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		odd += a[i] & 1;
	}
	if (odd > 1) {
		cout << 0 << endl;
		cout << fuck(n, a) << endl;
		return 0;
	}

	if (odd == 0) {
		solve_even();
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] & 1) {
			solve_odd(i);
			return 0;
		}
	}
	return 0;
}