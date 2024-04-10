#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long sqr(long long x) {
	return x * x;
}

int x[8][3];

long long dist(int i, int j) {
	return sqr(x[i][0] - x[j][0]) + sqr(x[i][1] - x[j][1]) + sqr(x[i][2] - x[j][2]);
}

bool check() {
	long long d = 111111111111111111;
	for (int i = 0; i < 8; ++i) {
		for (int j = i + 1; j < 8; ++j) {
			//cout << i << " " << j << "   " << dist(i, j) << endl;
			d = min(d, dist(i, j));
		}
	}
	if (d == 0) {
		return false;
	}
	for (int i = 0; i < 8; ++i) {
		int cnt = 0;
		for (int j = 0; j < 8; ++j) {
			if (dist(i, j) == d) {
				++cnt;
			}
		}
		//cout << cnt << " " << d << endl;
		if (cnt != 3) {
			return false;
		}
	}
	return true;
}

void rec(int num) {
	if (num == 8) {
		if (check()) {
			cout << "YES" << endl;
			for (int i = 0; i < 8; ++i) {
				cout << x[i][0] << " " << x[i][1] << " " << x[i][2] << endl;
			}
			exit(0);
		}
		return;
	}
	sort(x[num], x[num] + 3);
	do {
		rec(num + 1);
	} while (next_permutation(x[num], x[num] + 3));
}

int main() {
	for (int i = 0; i < 8; ++i) {
		cin >> x[i][0] >> x[i][1] >> x[i][2];
	}
	rec(0);
	cout << "NO" << endl;
	return 0;
}