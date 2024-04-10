#include <bits/stdc++.h>
using namespace std;

int d[21000000];

int main() {
	int n; cin >> n;
	int cnt = 0;
	for (int i = 1; i <= 20000000; i++) {
		d[i] = d[i / 10] + i % 10;
		if (d[i] == 10) {
			cnt++;
			if (cnt == n) {
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}